#include <communication.hpp>
#include <unBoard.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/ref.hpp>
#include <boost/thread.hpp>

#include <alproxies/almotionproxy.h>
#include <alerror/alerror.h>
#include <qi/log.hpp>

#include <cstring>		//Needed for memset
#include <sys/socket.h>	//Needed for the socket functions
#include <netdb.h>		//Needed for the socket functions
#include <string>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <UdpInterface.hpp>
#include <RoboCupGameControlData.h>
#include <SPLStandardMessage.h>
#include <commData.h>
#include <fstream>
#include <cmath>

#define FREQUENCY 3
struct Communication::Impl
{
    Communication &module;

    boost::thread *ptr_t;                           //Thread
    boost::posix_time::time_duration samplingPeriod;
    bool stopThread;                                //flag to stop the thread, and predicate against spurious unblocks
    boost::mutex stopThreadLock;                    //lock
    boost::condition_variable condVar;              //mechanism to control the thread's execution
    boost::mutex communication_lock;                //Lock da locomoção

    struct sockaddr_in targetReceive;
    UdpInterface udpSend;
    UdpInterface udpGmCtrl;
    RoboCupGameControlReturnData gmCtrl;
    RoboCupGameControlData gmCtrlData, gmCtrlOld;
    SPLStandardMessage SPLsend;
    unBoard<RoboCupGameControlData> gmCtrlSaver;
//    unBoard<SPLStandardMessage> SPLBoard;
    unBoard<CommData> commBoard;

    Impl(Communication &mod) :  module(mod), samplingPeriod(boost::posix_time::milliseconds(1000/FREQUENCY)), stopThread(false), ptr_t(NULL), udpGmCtrl(GAMECONTROLLER_DATA_PORT), udpSend(TEAM_PORT)
    {
        qiLogInfo("Communication") << "Creating Impl Struct" << std::endl;

        gmCtrl.version = GAMECONTROLLER_RETURN_STRUCT_VERSION;
        gmCtrl.team = TEAM_NUM;
        gmCtrl.player = PLAYER_NUM;
        gmCtrl.message = GAMECONTROLLER_RETURN_MSG_ALIVE;

        SPLsend.playerNum = PLAYER_NUM;
        SPLsend.teamNum = TEAM_NUM;
        SPLsend.fallen = 0;
        SPLsend.ballAge = 0;
        SPLsend.intention = 0;
        SPLsend.averageWalkSpeed = 0;
        SPLsend.maxKickDistance = 0;
        SPLsend.currentPositionConfidence = 0;
        SPLsend.currentSideConfidence = 0;

        memset((char *)&targetReceive, 0, sizeof(targetReceive));
        targetReceive.sin_family = AF_INET;
        targetReceive.sin_addr.s_addr = inet_addr("10.0.255.255");
        targetReceive.sin_port = htons(TEAM_PORT);
        qiLogInfo("Communication") << "Finish Creating" << std::endl;
    }

    ~Impl()
    {
        communication_lock.unlock();
        stopThreadLock.lock();
        stopThread = true;
        stopThreadLock.unlock();
        if (ptr_t)
        {
            ptr_t->join();
        }
    }

    int ComparaGmCtrl (RoboCupGameControlData gmCtrl1, RoboCupGameControlData gmCtrl2) {
        int i;

        if ((gmCtrl1.state==gmCtrl2.state)&&
            (gmCtrl1.firstHalf==gmCtrl2.firstHalf)&&
            (gmCtrl1.kickOffTeam==gmCtrl2.kickOffTeam)&&
            (gmCtrl1.secondaryState==gmCtrl2.secondaryState)&&
            (gmCtrl1.dropInTeam==gmCtrl2.dropInTeam)&&
            (gmCtrl1.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty==gmCtrl2.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty)&&
            (gmCtrl1.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].secsTillUnpenalised==gmCtrl2.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].secsTillUnpenalised))
        {
            i = 1;
        }
        else{
            i = 0;
        }
        return(i);
    }

    void operator()()
    {
        bool stopThreadCopy;
        boost::posix_time::ptime time_t_epoch(boost::gregorian::date(1970,1,1));
        stopThreadLock.lock();
        stopThreadCopy = stopThread;
        stopThreadLock.unlock();
        boost::system_time tickTime = boost::get_system_time();

        boost::unique_lock<boost::mutex> communication_unique_lock(communication_lock); // starts locked


        struct sockaddr_in targetGmCtrl;
        socklen_t addrlen = sizeof(targetGmCtrl);
        fd_set socks;
        FD_ZERO(&socks);
        FD_SET(udpGmCtrl.fd, &socks);
        fd_set tmp = socks;
        int recvlen;
        struct timeval tv;
        int nsocks = std::max(udpGmCtrl.fd,0) + 1;
        int broadcastEnable = 1;
        int ret = setsockopt(udpSend.fd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));

        //thread loop
        while (!stopThreadCopy)
        {
            boost::system_time tickTime = boost::get_system_time();
            // note the time in nanoseconds since Jan 1 1970
//             boost::posix_time::time_duration duration = boost::get_system_time() - time_t_epoch;
//             long long timestampNanos = duration.total_nanoseconds();
            udpSend.send((char *)&SPLsend, sizeof(SPLStandardMessage), &targetReceive, TEAM_PORT);
            tv.tv_sec = 0;
            tv.tv_usec = 300000;
            if (select(nsocks, &socks, NULL, NULL, &tv) >= 0)
            {
                qiLogInfo("Communication") << "Entre Ifs 1 " << std::endl;
                if (FD_ISSET(udpGmCtrl.fd, &socks))
                {
                    qiLogInfo("Communication") << "Entre Ifs 2 " << std::endl;
                    recvlen = udpGmCtrl.receive((char *)&gmCtrlData, sizeof(RoboCupGameControlData), (struct sockaddr *)&targetGmCtrl, &addrlen);
                    if(recvlen > 0)
                    {
//                        qiLogInfo("Communication") << "Received Message - Team: " << (int)gmCtrl.team << " Player: "<< (int)gmCtrl.player << " Port: " << GAMECONTROLLER_RETURN_PORT << std::endl;
                        udpGmCtrl.send((char *)&gmCtrl, sizeof(gmCtrl), &targetGmCtrl,GAMECONTROLLER_RETURN_PORT);
                        if (!(ComparaGmCtrl(gmCtrlData, gmCtrlOld))) {
                            gmCtrlSaver.save(gmCtrlData);
                        }
                        gmCtrlOld = gmCtrlData;
                    }
                }
                socks = tmp;
            }
//            qiLogInfo("Communication") << "SPL - Team: " << (int)SPLsend.teamNum << " Player: "<< (int)SPLsend.playerNum << " Port: " << TEAM_PORT << std::endl;
            // calculate next tick time
            tickTime += samplingPeriod;
            // wait for timeout, unlock sockLock while waiting, and control for spurious wakes
            // by checking stopThread.
            condVar.timed_wait(communication_unique_lock, tickTime, boost::lambda::var(stopThread));
            stopThreadLock.lock();
            stopThreadCopy = stopThread;
            stopThreadLock.unlock();
        }
    }
};




Communication::Communication(boost::shared_ptr<AL::ALBroker> pBroker, const std::string &pName) : AL::ALModule(pBroker, pName)
{
    //Bind the methods so they can be called by other modules
    setModuleDescription("Control Goalkeeper network and communication.");

    /** How to bind a method:
      * functionName("NAME_OF_THE_METHOD" , getName(), "DESCRIPTION_OF_THE_METHOD");
      * addParam("NAME_OF_THE_PARAMETER_N", "DESCRIPTION_OF_THE_PARAMETER_N");
      * setReturn("TYPE_OF_RETURN", "DESCRIPTION_OF_THE_RETURN");
      * BIND_METHOD(CLASS::METHOD);
      * Exemple:
      * functionName("LeftHandInverseKinematics" , getName(), "Move the left hand to a desired position and orientation using Inverse Kinematics.");
      * addParam("frame", "Vector that contains 12 values: 9 to represent the rotation and 3 to represent the position.");
      * setReturn("boolean", "return true if there is a result to the inverse kinematics calculation.");
      * BIND_METHOD(KinematicsModule::LeftHandInverseKinematics);
    **/

    functionName("StartLoop", getName(), "Start the Communication Thread.");
    BIND_METHOD(Communication::StartLoop);

    functionName("StopLoop", getName(), "Stop the Communication Thread.");
    BIND_METHOD(Communication::StopLoop);
}

Communication::~Communication()
{
    //Continue
}

/**
 * Overrides ALModule::init(). This is called right after the module has been constructed.
 */
void Communication::init()
{
    try
    {
        isActive = false;
        AL::ALModule::init();
    }
    catch (std::exception& e)
    {
        qiLogError("Communication") << "Failed to initialize Communication Module" << e.what() << std::endl;
        exit();
    }
}

/**
 * Overides ALModule::exit(), called before unloading
 */
void Communication::exit()
{
    //Always call ALModule::exit() or the module won't be destroyed properly
    isActive = false;
    AL::ALModule::exit();
}

void Communication::StartLoop()
{
    if(!isActive)
    {
        try
        {
            qiLogInfo("Communication") << "Teste - Team: " << TEAM_NUM << " Player: "<< PLAYER_NUM << std::endl;
            impl = boost::shared_ptr<Impl>(new Impl(*this));
            impl->ptr_t = new boost::thread(boost::ref(*impl));

            /*pthread_t threadID = (pthread_t) impl->ptr_t->native_handle();

            struct sched_param param;

            int retcode, policy;

            if((retcode = pthread_getschedparam(threadID, &policy, &param)) != 0)
            {
                throw std::runtime_error(std::string("Failed to get thread param"));
            }
            qiLogInfo("Communication") << "policy: " << ((policy == SCHED_FIFO) ? "SCHED_FIFO" :
                                                  (policy == SCHED_RR) ? "SCHED_RR" :
                                                  (policy == SCHED_OTHER) ? "SCHED_OTHER" :
                                                                            "???")
                                << std::endl << "priority: " << param.sched_priority << std::endl;

            policy = SCHED_RR;
            param.sched_priority = 0;

            if((retcode = pthread_setschedparam(threadID, policy, &param)) != 0)
            {
                throw std::runtime_error(std::string("Failed to change priority"));
            }*/
        }
        catch (std::exception& e)
        {
            qiLogError("Communication") << "Failed to start the thread." << e.what() << std::endl;
            throw CommunicationError("Failed to start the thread.");
            exit();
        }
        isActive = true;
    }
    else
    {
        throw CommunicationError("Module is already active.");
    }
}

void Communication::StopLoop()
{
    if(isActive)
    {
        try
        {
            impl->stopThreadLock.lock();
            impl->stopThread = true;
            impl->stopThreadLock.unlock();
            impl->condVar.notify_one();
            if (impl->ptr_t)
            {
                impl->ptr_t->join();
            }
            impl.reset();
        }
        catch (std::exception& e)
        {
            qiLogError("Communication") << "Failed to stop the thread." << e.what() << std::endl;
            throw CommunicationError("Failed to stop the thread.");
            exit();
        }
        isActive = false;
    }
    else
    {
        throw CommunicationError("Module is already inactive.");
    }
}

//Exception Class

CommunicationError::CommunicationError(const char* message)
  : msg(message) {}

CommunicationError::CommunicationError(const std::string message)
  : msg(message.c_str()) {}

const char* CommunicationError::what() { return msg; }
