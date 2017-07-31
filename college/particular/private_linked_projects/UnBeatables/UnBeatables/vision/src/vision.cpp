#include <vision.hpp>
#include <InFieldDetection.h>
#include <unBoard.hpp>

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

//Include motion sensors
#include "../../motion_integracao/runswift/types/SensorValues.hpp"

#define FREQUENCY 5

using namespace AL;

struct Vision::Impl
{
    Vision &module;

    ALVideoDeviceProxy *camProxy;
    std::string clientName;
    cv::Mat imgTop, imgBot, imgTop640;

    boost::thread *ptr_t;                           //Thread
    boost::posix_time::time_duration samplingPeriod;
    bool stopThread;                                //flag to stop the thread, and predicate against spurious unblocks
    boost::mutex stopThreadLock;                    //lock
    boost::condition_variable condVar;              //mechanism to control the thread's execution
    boost::mutex vision_lock;                       //Lock da visao

    SensorValues sensorValues;
    unBoard<SensorValues> sensorBoard;
    unBoard<visionData> dataSaver;
    visionData dataReader;

    bool cam_flag;
    float angle;

    bool copy_lock_p;
    boost::mutex copy_lock;

    boost::mutex update_lock;


    InFieldDetection *ifd;


    Impl(Vision &mod) :  module(mod), samplingPeriod(boost::posix_time::milliseconds(1000/FREQUENCY)), stopThread(false), ptr_t(NULL), copy_lock_p(false)
    {
        qiLogInfo("Vision") << "contructed impl" << std::endl;
        camProxy = new ALVideoDeviceProxy(mod.getParentBroker());

        AL::ALValue cameras, camerasColor, camerasRes;
        cameras.arraySetSize(2);
        camerasColor.arraySetSize(2);
        camerasRes.arraySetSize(2);

        cameras[0] = 0;
        cameras[1] = 1;

        camerasColor[0] = kBGRColorSpace;
        camerasColor[1] = kBGRColorSpace;

        camerasRes[0] = kVGA;
        camerasRes[1] = kQVGA;

        clientName = camProxy->subscribeCameras("test", cameras, camerasRes, camerasColor, 30);

        imgTop = cv::Mat(cv::Size(320, 240), CV_8UC3);
        imgBot = cv::Mat(cv::Size(320, 240), CV_8UC3);
        imgTop640 = cv::Mat(cv::Size(640,480), CV_8UC3);

        AL::ALValue images = camProxy->getImagesRemote(clientName);

        imgTop640.data = (uchar*) images[0][6].GetBinary();
        imgBot.data = (uchar*) images[1][6].GetBinary();

        camProxy->releaseImages(clientName);

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
        bool timeFlag = false;
        int loopCounter = 0;
        cam_flag = false;
        
        while (!stopThreadCopy)
        {

            boost::system_time tickTime = boost::get_system_time();
            // note the time in nanoseconds since Jan 1 1970
            //boost::posix_time::time_duration duration = boost::get_system_time() - time_t_epoch;
            //long long timestampNanos = duration.total_nanoseconds();
            

            //qiLogInfo("Vision") << "DEBUG1" << std::endl;
            ALValue img = camProxy->getImagesRemote(clientName);

            imgTop640.data = (uchar*) img[0][6].GetBinary();
            imgBot.data = (uchar*) img[1][6].GetBinary();

            image::resize(imgTop640, imgTop, cv::Size(320,240));

            camProxy->releaseImages(clientName);
            //qiLogInfo("Vision") << "DEBUG2" << std::endl;

            //sensorValues = sensorBoard.load();
            //angle = sensorValues.joints.angles[Joints::HeadPitch];
            //std::cout << "EI: " << std::endl;
            //std::cout << "vision "<< angle << std::endl;

            ifd = InFieldDetection::getInstance();

            ifd->run(imgTop640);
            //qiLogInfo("Vision") << "DEBUG4" << std::endl;

            if (cam_flag)
            {
                ifd->run(imgBot);
                cam_flag = ifd->detectBall(cam_flag);
            }else
            {
                ifd->run(imgTop640);
                cam_flag = !ifd->detectBall(cam_flag);
            }

            /*if (!ifd->detectBall(!cam_flag))
            {
                std::cout << "B 1" << std::endl;
                ifd->run(imgBot);
                cam_flag = true;
                cam_flag = ifd->detectBall(cam_flag);
            }*/

            /*if (!timeFlag) {
                ifd->detectAll(cam_flag,angle);
                timeFlag = true;
            }
            else {
                ifd->detectBall(cam_flag, angle);
                if (loopCounter%5 == 0)
                    ifd->detectInline();
                if (loopCounter%7 == 0) {
                    ifd->detectGoal();
                }
                if (loopCounter%9 == 0) {
                    ifd->detectEnemy();
                }
                if (loopCounter%10 == 0)
                    ifd->detectCenter();

            }*/

            ifd->updatePersistence(cam_flag);
            dataSaver.save(ifd->getPersistence());
            dataReader = dataSaver.load();

            qiLogInfo("Vision shr memo") << dataReader.ball_distance_x << std::endl;
            qiLogInfo("Vision shr memo") << dataReader.ball_distance_y << std::endl;

            // calculate next tick time
            tickTime += samplingPeriod;
            loopCounter++;
            qiLogInfo("Vision") << loopCounter << std::endl;

            // wait for timeout, unlock sockLock while waiting, and control for spurious wakes
            // by checking stopThread.
            condVar.timed_wait(vision_unique_lock, tickTime, boost::lambda::var(stopThread));
            stopThreadLock.lock();
            //qiLogInfo("Vision") << "DEBUG14" << std::endl;
            stopThreadCopy = stopThread;
            stopThreadLock.unlock();
        }
    }
};


Vision::Vision(boost::shared_ptr<AL::ALBroker> pBroker, const std::string &pName) : AL::ALModule(pBroker, pName)
{
    //Bind the methods so they can be called by other modules
    setModuleDescription("Get and process the camera frames.");
    functionName("StartLoop", getName(), "Start the Vision Thread.");
    BIND_METHOD(Vision::StartLoop);

    functionName("StopLoop", getName(), "Stop the Vision Thread.");
    BIND_METHOD(Vision::StopLoop);


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

//Exception Class

VisionError::VisionError(const char* message)
  : msg(message) {}

VisionError::VisionError(const std::string message)
  : msg(message.c_str()) {}

const char* VisionError::what() { return msg; }
