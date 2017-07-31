#include <vision.hpp>
#include <vision_implementation.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/ref.hpp>
#include <boost/thread.hpp>

// Aldebaran includes.
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>

// Opencv includes.
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#define FREQUENCY 30

using namespace AL;

struct Vision::Impl
{
    Vision &module;

    ALVideoDeviceProxy *camProxy;
    std::string clientName;
    cv::Mat imgTop, imgBot, imgTopSafe, imgBotSafe;

    boost::thread *ptr_t;                           //Thread
    boost::posix_time::time_duration samplingPeriod;
    bool stopThread;                                //flag to stop the thread, and predicate against spurious unblocks
    boost::mutex stopThreadLock;                    //lock
    boost::condition_variable condVar;              //mechanism to control the thread's execution
    boost::mutex vision_lock;                       //Lock da visao

    bool copy_lock_p;
    boost::mutex copy_lock;

    boost::mutex update_lock;

    bool isBallKnown, isLineKnown;
    float ballX, ballY, lineAngle;

    VS vs;

    Impl(Vision &mod) :  module(mod), samplingPeriod(boost::posix_time::milliseconds(1000/FREQUENCY)), stopThread(false), ptr_t(NULL), copy_lock_p(false), ballX(0.0), ballY(0.0), isBallKnown(false), isLineKnown(false), lineAngle(0.0)
    {
        camProxy = new ALVideoDeviceProxy(mod.getParentBroker());

        AL::ALValue cameras, camerasColor, camerasRes;
        cameras.arraySetSize(2);
        camerasColor.arraySetSize(2);
        camerasRes.arraySetSize(2);

        cameras[0] = 0;
        cameras[1] = 1;

        camerasColor[0] = kBGRColorSpace;
        camerasColor[1] = kBGRColorSpace;

        camerasRes[0] = kQVGA;
        camerasRes[1] = kQVGA;

        clientName = camProxy->subscribeCameras("test", cameras, camerasRes, camerasColor, 30);

        imgTop = cv::Mat(cv::Size(320, 240), CV_8UC3);
        imgBot = cv::Mat(cv::Size(320, 240), CV_8UC3);

        AL::ALValue images = camProxy->getImagesRemote(clientName);

        imgTop.data = (uchar*) images[0][6].GetBinary();
        imgBot.data = (uchar*) images[1][6].GetBinary();

        camProxy->releaseImages(clientName);

        imgTop.copyTo(imgTopSafe);
        imgBot.copyTo(imgBotSafe);

        copy_lock.unlock();
        update_lock.unlock();

    }

    ~Impl()
    {
        camProxy->unsubscribe(clientName);
        copy_lock.unlock();
        update_lock.unlock();
        stopThreadLock.lock();
        stopThread = true;
        stopThreadLock.unlock();
        if (ptr_t)
        {
            ptr_t->join();
        }
    }

    void operator()()
    {
        bool stopThreadCopy;
        boost::posix_time::ptime time_t_epoch(boost::gregorian::date(1970,1,1));
        stopThreadLock.lock();
        stopThreadCopy = stopThread;
        stopThreadLock.unlock();
        boost::system_time tickTime = boost::get_system_time();

        boost::unique_lock<boost::mutex> vision_unique_lock(vision_lock); // starts locked

        //thread loop
        while (!stopThreadCopy)
        {
            // note the time in nanoseconds since Jan 1 1970
            //boost::posix_time::time_duration duration = boost::get_system_time() - time_t_epoch;
            //long long timestampNanos = duration.total_nanoseconds();

            qiLogInfo("Vision") << "DEBUG1" << std::endl;
            ALValue img = camProxy->getImagesRemote(clientName);

            imgTop.data = (uchar*) img[0][6].GetBinary();
            imgBot.data = (uchar*) img[1][6].GetBinary();

            camProxy->releaseImages(clientName);
            qiLogInfo("Vision") << "DEBUG2" << std::endl;

            if(!copy_lock_p)
            {
                copy_lock.lock();
                imgTop.copyTo(imgTopSafe);
                imgBot.copyTo(imgBotSafe);
                copy_lock.unlock();
            }
            qiLogInfo("Vision") << "DEBUG3" << std::endl;

            update_lock.lock();
            isBallKnown = vs.detectBall(imgBot, DOWN);
            update_lock.unlock();
            qiLogInfo("Vision") << "DEBUG4" << std::endl;

            if(isBallKnown)
            {
                qiLogInfo("Vision") << "DEBUG5" << std::endl;
                update_lock.lock();
                ballX = vs.getBallSide();
                ballY = vs.getBallDist();
                update_lock.unlock();
                qiLogInfo("Vision") << "DEBUG6" << std::endl;
            }
            else
            {
                qiLogInfo("Vision") << "DEBUG7" << std::endl;
                update_lock.lock();
                isBallKnown = vs.detectBall(imgTop, UP);
                update_lock.unlock();

                if(isBallKnown)
                {
                    qiLogInfo("Vision") << "DEBUG8" << std::endl;
                    update_lock.lock();
                    ballX = vs.getBallSide();
                    ballY = vs.getBallDist();
                    update_lock.unlock();
                    qiLogInfo("Vision") << "DEBUG9" << std::endl;
                }
            }

            qiLogInfo("Vision") << "DEBUG10" << std::endl;
            update_lock.lock();
            isLineKnown = vs.detectBase(imgBot);
            update_lock.unlock();

            qiLogInfo("Vision") << "DEBUG11" << std::endl;
            if(isLineKnown)
            {
                qiLogInfo("Vision") << "DEBUG12" << std::endl;
                update_lock.lock();
                lineAngle = vs.getThetaBase();
                update_lock.unlock();
                qiLogInfo("Vision") << "DEBUG13" << std::endl;
            }

            //cv::imwrite("/home/nao/imgTop.jpg", imgTop);
            cv::imwrite("/home/nao/imgBot.jpg", imgBot);
            
            qiLogInfo("Vision") << "Teste de thread" << std::endl;


            // calculate next tick time
            tickTime += samplingPeriod;
            // wait for timeout, unlock sockLock while waiting, and control for spurious wakes
            // by checking stopThread.
            condVar.timed_wait(vision_unique_lock, tickTime, boost::lambda::var(stopThread));
            stopThreadLock.lock();
            qiLogInfo("Vision") << "DEBUG14" << std::endl;
            stopThreadCopy = stopThread;
            stopThreadLock.unlock();
        }
    }
};


Vision::Vision(boost::shared_ptr<AL::ALBroker> pBroker, const std::string &pName) : AL::ALModule(pBroker, pName)
{
    //Bind the methods so they can be called by other modules
    setModuleDescription("Get and process the GoalKeeper camera frames.");

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

    functionName("StartLoop", getName(), "Start the Vision Thread.");
    BIND_METHOD(Vision::StartLoop);

    functionName("StopLoop", getName(), "Stop the Vision Thread.");
    BIND_METHOD(Vision::StopLoop);

    functionName("IsTherePost", getName(), "Checks if the robot can get the post thickness");
    setReturn("boolean", "return true if there is a post thickness.");
    BIND_METHOD(Vision::IsTherePost);

    functionName("GetPostThickness", getName(), "Returns the post thickness");
    setReturn("float", "Post thickness.");
    BIND_METHOD(Vision::GetPostThickness);

    functionName("CheckAngleLine", getName(), "Returns the angle of a line related to the robot.");
    setReturn("float", "Line angle.");
    BIND_METHOD(Vision::CheckAngleLine);

    functionName("IsBallSeen", getName(), "Checks if the robot knows the ball position.");
    setReturn("boolean", "Returns true if the ball position is known.");
    BIND_METHOD(Vision::IsBallSeen);

    functionName("GetBallPosition", getName(), "Returns the ball x and y.");
    setReturn("AL::ALValue", "Array containing ball x and ball y.");
    BIND_METHOD(Vision::GetBallPosition);
}

Vision::~Vision()
{
    //Continue
}

/**
 * Overrides ALModule::init(). This is called right after the module has been constructed.
 */
void Vision::init()
{
    try
    {
        isActive = false;
        AL::ALModule::init();
    }
    catch (std::exception& e)
    {
        qiLogError("Vision") << "Failed to initialize Vision Module" << e.what() << std::endl;
        exit();
    }
}

/**
 * Overides ALModule::exit(), called before unloading
 */
void Vision::exit()
{
    //Always call ALModule::exit() or the module won't be destroyed properly
    isActive = false;
    AL::ALModule::exit();
}

void Vision::StartLoop()
{
    if(!isActive)
    {
        try
        {
            impl = boost::shared_ptr<Impl>(new Impl(*this));
            impl->ptr_t = new boost::thread(boost::ref(*impl));
        }
        catch (std::exception& e)
        {
            qiLogError("Vision") << "Failed to start the thread." << e.what() << std::endl;
            throw VisionError("Failed to start the thread.");
            exit();
        }
        isActive = true;
    }
    else
    {
        throw VisionError("Module is already active.");
    }
}

void Vision::StopLoop()
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
            qiLogError("Vision") << "Failed to stop the thread." << e.what() << std::endl;
            throw VisionError("Failed to stop the thread.");
            exit();
        }
        isActive = false;
    }
    else
    {
        throw VisionError("Module is already inactive.");
    }
}

bool Vision::IsTherePost()
{
    //Call the function to get the thickness of the post
    impl->copy_lock.lock();
    impl->copy_lock_p = true;
    impl->copy_lock.unlock();

    bool ret_value = impl->vs.detectPost(impl->imgTopSafe);

    impl->copy_lock.lock();
    impl->copy_lock_p = false;
    impl->copy_lock.unlock();
    return ret_value;
}

float Vision::GetPostThickness()
{
    //return the thickness saved by the IsTherePost method
    return impl->vs.getDiffPosts();
}

float Vision::CheckAngleLine()
{
    //Return the angle of the line in front of the robot
    return impl->getThetaBase();
}

bool Vision::IsBallSeen()
{
    //Return if the ball position is known
    return impl->isBallKnown;
}

AL::ALValue Vision::GetBallPosition()
{
    //Returns the ball x and y position
    AL::ALValue ret_value;
    ret_value.arraySetSize(2);
    qiLogInfo("Vision") << "Array Set Size" << std::endl;
    ret_value[0] = impl->ballX;
    ret_value[1] = impl->ballY;
    qiLogInfo("Vision") << "BallY" << std::endl;
    return ret_value;
}


//Exception Class

VisionError::VisionError(const char* message)
  : msg(message) {}

VisionError::VisionError(const std::string message)
  : msg(message.c_str()) {}

const char* VisionError::what() { return msg; }
