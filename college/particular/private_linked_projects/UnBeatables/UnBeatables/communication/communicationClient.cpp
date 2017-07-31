/*#include <string>
#include<sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <UdpInterface.hpp>
#include <RoboCupGameControlData.h>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/thread/thread.hpp>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  UdpInterface udpSend(GAMECONTROLLER_RETURN_PORT);
  UdpInterface udpGmCtrl (GAMECONTROLLER_DATA_PORT);
  RoboCupGameControlReturnData gmCtrl;
  RoboCupGameControlData gmCtrlData;

  struct sockaddr_in targetReceive;
  fd_set socks;
  FD_ZERO(&socks);
  FD_SET(udpGmCtrl.fd, &socks);
  int recvlen;
  socklen_t addrlen = sizeof(targetReceive);
  int nsocks = max(udpSend.fd, udpGmCtrl.fd) + 1;

  // Lendo arquivo de preferencias
  ifstream settings("settings.txt");
  string line;
  if(settings.is_open())
  {
    // Header
    getline(settings,line);
    // Version
    getline(settings,line);
    gmCtrl.version = atoi(line.c_str());
    // Team
    getline(settings,line);
    gmCtrl.team = atoi(line.c_str());
    // Player
    getline(settings,line);
    gmCtrl.player = atoi(line.c_str());
  }
  settings.close();
  cout << (int)gmCtrl.version << (int)gmCtrl.team << (int)gmCtrl.player << endl;
  while(true)
  {
    if (select(nsocks, &socks, NULL, NULL, NULL) >= 0) {
      if (FD_ISSET(udpGmCtrl.fd, &socks))
      {
        recvlen = udpGmCtrl.receive((char *)&gmCtrlData, sizeof(RoboCupGameControlData), (struct sockaddr *)&targetReceive, &addrlen);
        if(recvlen > 0)
        {
          printf("received %d bytes\n", recvlen);
          udpGmCtrl.send((char *)&gmCtrl, sizeof(gmCtrl), &targetReceive,GAMECONTROLLER_RETURN_PORT);
        }
      }
    }
  }

  return 0;
}
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <boost/program_options.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <alcommon/albroker.h>
#include <alcommon/albrokermanager.h>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>

#include <alproxies/almemoryproxy.h>
#include <alvalue/alvalue.h>

#include <unBoard.hpp>
#include <proxyData.hpp>
#include <RoboCupGameControlData.h>
//#include <types/SensorValues.hpp>

void parseOpt(std::string *naoBrokerIP, int *naoBrokerPort, int argc, char* argv[])
{
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "Print help mesages.")
        ("pip", po::value<std::string>(naoBrokerIP)->default_value("127.0.0.1"), "IP of the parent broker. Default: 127.0.0.1")
        ("pport", po::value<int>(naoBrokerPort)->default_value(9559),"Port of the parent broker. Default: 9559");
    po::positional_options_description positionalOptions;
    po::variables_map vm; // Map containing all the options with their values
    try
    {
        po::store(po::command_line_parser(argc, argv).options(desc).positional(positionalOptions).run(), vm);

        if (vm.count("help"))
        {
            std::cout << "Behavior client module."                                   << std::endl;
            std::cout << "Can be executed locally or remotelly."                   << std::endl;
            std::cout                                                              << std::endl;
            std::cout << "Usage:"                                                  << std::endl;
            std::cout << "  " << argv[0] << " [options] [input] "                  << std::endl;
            std::cout                                                              << std::endl;
            std::cout << desc                                                      << std::endl;

            exit(0);
        }

        po::notify(vm);
    }
    catch(po::error &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << desc << std::endl;
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    std::string parentBrokerIP; //robot IP
    int parentBrokerPort;		//robot port

    setlocale(LC_NUMERIC, "C"); // Need this to for SOAP serialization of floats to work

    parseOpt(&(parentBrokerIP), &(parentBrokerPort), argc, argv);

    std::cout << "parse created..." << std::endl;

    // A broker needs a name, an IP and a port:
    const std::string brokerName = "mybroker";
    // FIXME: would be a good idea to look for a free port first
    int brokerPort = 0;
    // listen port of the broker (here an anything)
    const std::string brokerIp = "";

    RoboCupGameControlData gmCtrlData;
    unBoard<RoboCupGameControlData> gmCtrlSaver;
    memset(&gmCtrlData, 0, sizeof(RoboCupGameControlData));
    gmCtrlSaver.save(gmCtrlData);
    // Create your own broker
    boost::shared_ptr<AL::ALBroker> broker;
    try
    {
        broker = AL::ALBroker::createBroker(
            brokerName,
            brokerIp,
            brokerPort,
            parentBrokerIP,
            parentBrokerPort,
            0    // you can pass various options for the broker creation,
                 // but default is fine
        );
    }
    catch(const AL::ALError& e)
    {
        std::cerr << "Fail to connect broker to: "
                  << parentBrokerIP
                  << ":"
                  << parentBrokerPort
                  << std::endl
                  << e.what()
                  << std::endl;

        AL::ALBrokerManager::getInstance()->killAllBroker();
        AL::ALBrokerManager::kill();

        return 1;
    }

//    // Create the proxy to access the motion module
//    boost::shared_ptr<AL::ALProxy> Motion;
//    try
//    {
//        Motion = boost::shared_ptr<AL::ALProxy>(new AL::ALProxy(broker,"Motion"));
//        std::cout << "proxy created..." << std::endl;
//        Motion->callVoid("StartLoop");
//    }
//    catch (const AL::ALError& e)
//    {
//        std::cerr << "Could not create proxy: " << e.what() << std::endl;
//        return 1;
//    }

    // Create the proxy to access the Communication module
    boost::shared_ptr<AL::ALProxy> Communication;
    try
    {
        Communication = boost::shared_ptr<AL::ALProxy>(new AL::ALProxy(broker,"Communication"));
        std::cout << "proxy created..." << std::endl;
        Communication->callVoid("StartLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Could not create proxy: " << e.what() << std::endl;
        return 1;
    }

    // Create the proxy to access the Vision module
   /*boost::shared_ptr<AL::ALProxy> Vision;

    try
    {
        Vision = boost::shared_ptr<AL::ALProxy>(new AL::ALProxy(broker,"Vision"));
        std::cout << "proxy created..." << std::endl;
        Vision->callVoid("StartLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Could not create proxy: " << e.what() << std::endl;
        return 1;
    }
    */
//    unBoard<SensorValues> SensorBoard;

//    SensorValues tmp;

//    SensorBoard.save(tmp);

 /* unBoard<ProxyData> proxyBoard;
    ProxyData proxies;

    proxies.broker = broker;
    proxies.Communication = Communication;
    proxies.Motion = Motion;
    proxies.Vision = Vision;

    proxyBoard.save(proxies);*/

    struct sched_param param;

    int retcode, policy;

    if((policy = sched_getscheduler(getpid())) == -1)
    {
        std::cerr << "Failed to get main policy" << std::endl;
    }

    if((retcode = sched_getparam(getpid(), &param)) == -1)
    {
        std::cerr << "Failed to get main param" << std::endl;
    }
    std::cout << "policy: " << ((policy == SCHED_FIFO) ? "SCHED_FIFO" :
                                          (policy == SCHED_RR) ? "SCHED_RR" :
                                          (policy == SCHED_OTHER) ? "SCHED_OTHER" :
                                                                    "???")
                        << std::endl << "priority: " << param.sched_priority << std::endl;
    policy = SCHED_RR;
    param.sched_priority = 2;

    if((retcode = sched_setscheduler(getpid(), policy, &param)) == -1)
    {
        std::cerr << "Error no Scheduler" << std::endl;
    }

    getchar();

//    BehaviorBase* current;
//    // Initial Behavior
//    current = GmCtrlInitial::Behavior();
//    while(true)
//    {
//        boost::system_time tickTime = boost::get_system_time();
//        current->action();
//        current = current->transition();
//        boost::posix_time::time_duration duration = boost::get_system_time() - tickTime;
//        long long timestampNanos = duration.total_milliseconds();
//        if(int diff = (BEHAVIOR_FREQ_MS - timestampNanos) > 0)
//            boost::this_thread::sleep(boost::posix_time::milliseconds(diff));
//    }

    /*std::cout << "Stop Vision" << std::endl;
    try
    {
        Vision->callVoid("StopLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << e.what() << std::endl;
    }
    */
    std::cout << "Stop Communication" << std::endl;
    try
    {
        Communication->callVoid("StopLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << e.what() << std::endl;
    }

//    std::cout << "Stop Motion" << std::endl;
//    try
//    {
//        Motion->callVoid("StopLoop");
//    }
//    catch (const AL::ALError& e)
//    {
//        std::cerr << e.what() << std::endl;
//    }

    return 0;
}
