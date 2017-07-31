#include <motion.hpp>
#include <unBoard.hpp>
#include <motionData.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/ref.hpp>
#include <boost/thread.hpp>

#include <alproxies/almotionproxy.h>
#include <alerror/alerror.h>
#include <alproxies/almemoryproxy.h>
#include <alproxies/alrobotpostureproxy.h>

#include <cmath>

#define FREQUENCY 50

struct Motion::Impl
{
    Motion &module;

    boost::shared_ptr<AL::ALMotionProxy> motionProxy;
    boost::shared_ptr<AL::ALMemoryProxy> memoryProxy;
    boost::shared_ptr<AL::ALRobotPostureProxy> postureProxy;


    boost::thread *ptr_t;                           //Thread
    boost::posix_time::time_duration samplingPeriod;
    bool stopThread;                                //flag to stop the thread, and predicate against spurious unblocks
    boost::mutex stopThreadLock;                    //lock
    boost::condition_variable condVar;              //mechanism to control the thread's execution
    boost::mutex motion_lock;                       //Lock da locomoção

    bool speed_lock_p;
    boost::mutex speed_lock;                        //Lock to change x_vel, y_vel and theta

    float x_vel, y_vel, theta, turn_time;
    motionData persistence;
    unBoard<motionData> dataSaver;
    
    bool neck_lock_p;
    boost::mutex neck_lock;                        //Lock to change neck angles

    float neck_yaw, neck_pitch;

    AL::ALValue gyros_strings;
    bool standing;
    bool falling;

    AL::ALValue neck_strings;

    //Defense Variables
    std::vector<std::string> names_defend;
    AL::ALValue times_defend, keys_defend;

    std::vector<std::string> names_stand;
    AL::ALValue times_stand, keys_stand;

    //Gait Parameters
    AL::ALValue gait_parameters;

    Impl(Motion &mod) :  module(mod), samplingPeriod(boost::posix_time::milliseconds(1000/FREQUENCY)), stopThread(false), ptr_t(NULL), speed_lock_p(false), neck_lock_p(false), standing(true), falling(false)
    {
        motionProxy = boost::shared_ptr<AL::ALMotionProxy>(new AL::ALMotionProxy(mod.getParentBroker()));

        memoryProxy = boost::shared_ptr<AL::ALMemoryProxy>(new AL::ALMemoryProxy(mod.getParentBroker()));

        postureProxy = boost::shared_ptr<AL::ALRobotPostureProxy>(new AL::ALRobotPostureProxy(mod.getParentBroker()));

        motionProxy->stiffnessInterpolation("Body", 1.0f, 0.1f);

        postureProxy->goToPosture("StandInit", 0.5f);

        //Disable Fall Manager
        motionProxy->setFallManagerEnabled(false);

        //All speed start as 0
        x_vel = 0.0;
        y_vel = 0.0;
        theta = 0.0;

        //All neck angles start as 0
        neck_yaw = 0.0;
        neck_pitch = 0.0;
        turn_time = 1.0f;

        //Set Gyroscope keys
        gyros_strings.arraySetSize(2);
        gyros_strings[0] = AL::ALValue("Device/SubDeviceList/InertialSensor/AngleX/Sensor/Value");
        gyros_strings[1] = AL::ALValue("Device/SubDeviceList/InertialSensor/AngleY/Sensor/Value");

        //Set HeadAngle keys
        neck_strings.arraySetSize(2);
        neck_strings[0] = AL::ALValue("Device/SubDeviceList/HeadYaw/Position/Sensor/Value");
        neck_strings[1] = AL::ALValue("Device/SubDeviceList/HeadPitch/Position/Sensor/Value");

        SetParameters();

        //Gait Parameters
        gait_parameters.arraySetSize(7);
        for(int i = 0; i < 7; i++)
        {
            gait_parameters[i].arraySetSize(2);
        }
        gait_parameters[0][0] = AL::ALValue("MaxStepX");
        gait_parameters[0][1] = AL::ALValue(0.060);
        gait_parameters[1][0] = AL::ALValue("MaxStepY");
        gait_parameters[1][1] = AL::ALValue(0.160);
        gait_parameters[2][0] = AL::ALValue("MaxStepTheta");
        gait_parameters[2][1] = AL::ALValue(0.349);
        gait_parameters[3][0] = AL::ALValue("MaxStepFrequency");
        gait_parameters[3][1] = AL::ALValue(1.0);
        gait_parameters[4][0] = AL::ALValue("StepHeight");
        gait_parameters[4][1] = AL::ALValue(0.018);
        gait_parameters[5][0] = AL::ALValue("TorsoWx");
        gait_parameters[5][1] = AL::ALValue(0.0);
        gait_parameters[6][0] = AL::ALValue("TorsoWy");
        gait_parameters[6][1] = AL::ALValue(0.0);
    }

    ~Impl()
    {
        postureProxy->goToPosture("Crouch", 0.5f);
        motionProxy->setStiffnesses("Body", 0.0f);
        speed_lock.unlock();
        neck_lock.unlock();
        stopThreadLock.lock();
        stopThread = true;
        stopThreadLock.unlock();
        if (ptr_t)
        {
            ptr_t->join();
        }
    }

    void SetParameters()
    {
        names_defend.reserve(26);
        times_defend.arraySetSize(26);
        keys_defend.arraySetSize(26);

        names_defend.push_back("HeadPitch");
        times_defend[0].arraySetSize(2);
        keys_defend[0].arraySetSize(2);

        times_defend[0][0] = 1.48;
        keys_defend[0][0] = AL::ALValue::array(-4.19617e-05, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[0][1] = 2.2;
        keys_defend[0][1] = AL::ALValue::array(0.024502, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("HeadYaw");
        times_defend[1].arraySetSize(2);
        keys_defend[1].arraySetSize(2);

        times_defend[1][0] = 1.48;
        keys_defend[1][0] = AL::ALValue::array(-0.00924586, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[1][1] = 2.2;
        keys_defend[1][1] = AL::ALValue::array(0.00149202, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LAnklePitch");
        times_defend[2].arraySetSize(2);
        keys_defend[2].arraySetSize(2);

        times_defend[2][0] = 1.48;
        keys_defend[2][0] = AL::ALValue::array(-1.18944, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[2][1] = 2.2;
        keys_defend[2][1] = AL::ALValue::array(-1.00941, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LAnkleRoll");
        times_defend[3].arraySetSize(2);
        keys_defend[3].arraySetSize(2);

        times_defend[3][0] = 1.48;
        keys_defend[3][0] = AL::ALValue::array(0.0690719, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[3][1] = 2.2;
        keys_defend[3][1] = AL::ALValue::array(-0.115273, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LElbowRoll");
        times_defend[4].arraySetSize(2);
        keys_defend[4].arraySetSize(2);

        times_defend[4][0] = 1.48;
        keys_defend[4][0] = AL::ALValue::array(-0.969447, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[4][1] = 2.2;
        keys_defend[4][1] = AL::ALValue::array(-0.957173, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LElbowYaw");
        times_defend[5].arraySetSize(2);
        keys_defend[5].arraySetSize(2);

        times_defend[5][0] = 1.48;
        keys_defend[5][0] = AL::ALValue::array(-1.39291, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[5][1] = 2.2;
        keys_defend[5][1] = AL::ALValue::array(-1.40672, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LHand");
        times_defend[6].arraySetSize(2);
        keys_defend[6].arraySetSize(2);

        times_defend[6][0] = 1.48;
        keys_defend[6][0] = AL::ALValue::array(0.2596, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[6][1] = 2.2;
        keys_defend[6][1] = AL::ALValue::array(0.2596, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LHipPitch");
        times_defend[7].arraySetSize(2);
        keys_defend[7].arraySetSize(2);

        times_defend[7][0] = 1.48;
        keys_defend[7][0] = AL::ALValue::array(-0.677985, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[7][1] = 2.2;
        keys_defend[7][1] = AL::ALValue::array(-0.320565, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LHipRoll");
        times_defend[8].arraySetSize(2);
        keys_defend[8].arraySetSize(2);

        times_defend[8][0] = 1.48;
        keys_defend[8][0] = AL::ALValue::array(-0.0444441, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[8][1] = 2.2;
        keys_defend[8][1] = AL::ALValue::array(0.782382, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LHipYawPitch");
        times_defend[9].arraySetSize(2);
        keys_defend[9].arraySetSize(2);

        times_defend[9][0] = 1.48;
        keys_defend[9][0] = AL::ALValue::array(-0.38806, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[9][1] = 2.2;
        keys_defend[9][1] = AL::ALValue::array(-1.10751, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LKneePitch");
        times_defend[10].arraySetSize(2);
        keys_defend[10].arraySetSize(2);

        times_defend[10][0] = 1.48;
        keys_defend[10][0] = AL::ALValue::array(2.1, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[10][1] = 2.2;
        keys_defend[10][1] = AL::ALValue::array(2.11255, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LShoulderPitch");
        times_defend[11].arraySetSize(2);
        keys_defend[11].arraySetSize(2);

        times_defend[11][0] = 1.48;
        keys_defend[11][0] = AL::ALValue::array(1.50021, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[11][1] = 2.2;
        keys_defend[11][1] = AL::ALValue::array(1.50788, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LShoulderRoll");
        times_defend[12].arraySetSize(2);
        keys_defend[12].arraySetSize(2);

        times_defend[12][0] = 1.48;
        keys_defend[12][0] = AL::ALValue::array(0.256136, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[12][1] = 2.2;
        keys_defend[12][1] = AL::ALValue::array(0.256136, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("LWristYaw");
        times_defend[13].arraySetSize(2);
        keys_defend[13].arraySetSize(2);

        times_defend[13][0] = 1.48;
        keys_defend[13][0] = AL::ALValue::array(-0.023052, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[13][1] = 2.2;
        keys_defend[13][1] = AL::ALValue::array(-0.023052, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RAnklePitch");
        times_defend[14].arraySetSize(2);
        keys_defend[14].arraySetSize(2);

        times_defend[14][0] = 1.48;
        keys_defend[14][0] = AL::ALValue::array(-1.1796, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[14][1] = 2.2;
        keys_defend[14][1] = AL::ALValue::array(-1.10751, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RAnkleRoll");
        times_defend[15].arraySetSize(2);
        keys_defend[15].arraySetSize(2);

        times_defend[15][0] = 1.48;
        keys_defend[15][0] = AL::ALValue::array(-0.0122299, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[15][1] = 2.2;
        keys_defend[15][1] = AL::ALValue::array(0.0799279, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RElbowRoll");
        times_defend[16].arraySetSize(2);
        keys_defend[16].arraySetSize(2);

        times_defend[16][0] = 1.48;
        keys_defend[16][0] = AL::ALValue::array(0.897433, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[16][1] = 2.2;
        keys_defend[16][1] = AL::ALValue::array(0.89283, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RElbowYaw");
        times_defend[17].arraySetSize(2);
        keys_defend[17].arraySetSize(2);

        times_defend[17][0] = 1.48;
        keys_defend[17][0] = AL::ALValue::array(1.41124, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[17][1] = 2.2;
        keys_defend[17][1] = AL::ALValue::array(1.43732, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RHand");
        times_defend[18].arraySetSize(2);
        keys_defend[18].arraySetSize(2);

        times_defend[18][0] = 1.48;
        keys_defend[18][0] = AL::ALValue::array(0.2616, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[18][1] = 2.2;
        keys_defend[18][1] = AL::ALValue::array(0.2616, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RHipPitch");
        times_defend[19].arraySetSize(2);
        keys_defend[19].arraySetSize(2);

        times_defend[19][0] = 1.48;
        keys_defend[19][0] = AL::ALValue::array(-0.679603, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[19][1] = 2.2;
        keys_defend[19][1] = AL::ALValue::array(-0.227074, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RHipRoll");
        times_defend[20].arraySetSize(2);
        keys_defend[20].arraySetSize(2);

        times_defend[20][0] = 1.48;
        keys_defend[20][0] = AL::ALValue::array(-0.00762796, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[20][1] = 2.2;
        keys_defend[20][1] = AL::ALValue::array(-0.753151, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RHipYawPitch");
        times_defend[21].arraySetSize(2);
        keys_defend[21].arraySetSize(2);

        times_defend[21][0] = 1.48;
        keys_defend[21][0] = AL::ALValue::array(-0.38806, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[21][1] = 2.2;
        keys_defend[21][1] = AL::ALValue::array(-1.10751, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RKneePitch");
        times_defend[22].arraySetSize(2);
        keys_defend[22].arraySetSize(2);

        times_defend[22][0] = 1.48;
        keys_defend[22][0] = AL::ALValue::array(2.11082, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[22][1] = 2.2;
        keys_defend[22][1] = AL::ALValue::array(2.10469, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RShoulderPitch");
        times_defend[23].arraySetSize(2);
        keys_defend[23].arraySetSize(2);

        times_defend[23][0] = 1.48;
        keys_defend[23][0] = AL::ALValue::array(1.45888, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[23][1] = 2.2;
        keys_defend[23][1] = AL::ALValue::array(1.46348, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RShoulderRoll");
        times_defend[24].arraySetSize(2);
        keys_defend[24].arraySetSize(2);

        times_defend[24][0] = 1.48;
        keys_defend[24][0] = AL::ALValue::array(-0.0521979, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[24][1] = 2.2;
        keys_defend[24][1] = AL::ALValue::array(-0.092082, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        names_defend.push_back("RWristYaw");
        times_defend[25].arraySetSize(2);
        keys_defend[25].arraySetSize(2);

        times_defend[25][0] = 1.48;
        keys_defend[25][0] = AL::ALValue::array(0.033706, AL::ALValue::array(3, -0.493333, 0), AL::ALValue::array(3, 0.24, 0));
        times_defend[25][1] = 2.2;
        keys_defend[25][1] = AL::ALValue::array(0.033706, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0, 0));

        //************************************************Stand************************************************

        names_stand.reserve(26);
        times_stand.arraySetSize(26);
        keys_stand.arraySetSize(26);

        names_stand.push_back("HeadPitch");
        times_stand[0].arraySetSize(5);
        keys_stand[0].arraySetSize(5);

        times_stand[0][0] = 1;
        keys_stand[0][0] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[0][1] = 2.16;
        keys_stand[0][1] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[0][2] = 2.36;
        keys_stand[0][2] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[0][3] = 3.2;
        keys_stand[0][3] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[0][4] = 5.16;
        keys_stand[0][4] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("HeadYaw");
        times_stand[1].arraySetSize(5);
        keys_stand[1].arraySetSize(5);

        times_stand[1][0] = 1;
        keys_stand[1][0] = AL::ALValue::array(0.0183661, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[1][1] = 2.16;
        keys_stand[1][1] = AL::ALValue::array(0.0183661, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[1][2] = 2.36;
        keys_stand[1][2] = AL::ALValue::array(0.0183661, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[1][3] = 3.2;
        keys_stand[1][3] = AL::ALValue::array(0.0183661, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[1][4] = 5.16;
        keys_stand[1][4] = AL::ALValue::array(0.0183661, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LAnklePitch");
        times_stand[2].arraySetSize(5);
        keys_stand[2].arraySetSize(5);

        times_stand[2][0] = 1;
        keys_stand[2][0] = AL::ALValue::array(-1.00788, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[2][1] = 2.16;
        keys_stand[2][1] = AL::ALValue::array(-1.18736, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[2][2] = 2.36;
        keys_stand[2][2] = AL::ALValue::array(-1.18582, AL::ALValue::array(3, -0.0666667, -0.000393328), AL::ALValue::array(3, 0.28, 0.00165198));
        times_stand[2][3] = 3.2;
        keys_stand[2][3] = AL::ALValue::array(-1.18122, AL::ALValue::array(3, -0.28, -0.00460194), AL::ALValue::array(3, 0.653333, 0.0107379));
        times_stand[2][4] = 5.16;
        keys_stand[2][4] = AL::ALValue::array(-0.354396, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LAnkleRoll");
        times_stand[3].arraySetSize(5);
        keys_stand[3].arraySetSize(5);

        times_stand[3][0] = 1;
        keys_stand[3][0] = AL::ALValue::array(-0.118076, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[3][1] = 2.16;
        keys_stand[3][1] = AL::ALValue::array(-0.0398421, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[3][2] = 2.36;
        keys_stand[3][2] = AL::ALValue::array(-0.0444441, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[3][3] = 3.2;
        keys_stand[3][3] = AL::ALValue::array(0.0537319, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[3][4] = 5.16;
        keys_stand[3][4] = AL::ALValue::array(-0.00302601, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LElbowRoll");
        times_stand[4].arraySetSize(5);
        keys_stand[4].arraySetSize(5);

        times_stand[4][0] = 1;
        keys_stand[4][0] = AL::ALValue::array(-0.951038, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[4][1] = 2.16;
        keys_stand[4][1] = AL::ALValue::array(-0.826784, AL::ALValue::array(3, -0.386667, -0.0355899), AL::ALValue::array(3, 0.0666667, 0.00613619));
        times_stand[4][2] = 2.36;
        keys_stand[4][2] = AL::ALValue::array(-0.820648, AL::ALValue::array(3, -0.0666667, -0.00613619), AL::ALValue::array(3, 0.28, 0.025772));
        times_stand[4][3] = 3.2;
        keys_stand[4][3] = AL::ALValue::array(-0.677986, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[4][4] = 5.16;
        keys_stand[4][4] = AL::ALValue::array(-0.977116, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LElbowYaw");
        times_stand[5].arraySetSize(5);
        keys_stand[5].arraySetSize(5);

        times_stand[5][0] = 1;
        keys_stand[5][0] = AL::ALValue::array(-1.40519, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[5][1] = 2.16;
        keys_stand[5][1] = AL::ALValue::array(-1.40519, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[5][2] = 2.36;
        keys_stand[5][2] = AL::ALValue::array(-1.42666, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[5][3] = 3.2;
        keys_stand[5][3] = AL::ALValue::array(-1.42666, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[5][4] = 5.16;
        keys_stand[5][4] = AL::ALValue::array(-1.41592, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LHand");
        times_stand[6].arraySetSize(5);
        keys_stand[6].arraySetSize(5);

        times_stand[6][0] = 1;
        keys_stand[6][0] = AL::ALValue::array(0.2684, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[6][1] = 2.16;
        keys_stand[6][1] = AL::ALValue::array(0.2684, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[6][2] = 2.36;
        keys_stand[6][2] = AL::ALValue::array(0.2684, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[6][3] = 3.2;
        keys_stand[6][3] = AL::ALValue::array(0.2684, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[6][4] = 5.16;
        keys_stand[6][4] = AL::ALValue::array(0.2684, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LHipPitch");
        times_stand[7].arraySetSize(5);
        keys_stand[7].arraySetSize(5);

        times_stand[7][0] = 1;
        keys_stand[7][0] = AL::ALValue::array(-0.31903, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[7][1] = 2.16;
        keys_stand[7][1] = AL::ALValue::array(-0.375788, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[7][2] = 2.36;
        keys_stand[7][2] = AL::ALValue::array(-0.375788, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[7][3] = 3.2;
        keys_stand[7][3] = AL::ALValue::array(-0.713268, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[7][4] = 5.16;
        keys_stand[7][4] = AL::ALValue::array(-0.44942, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LHipRoll");
        times_stand[8].arraySetSize(5);
        keys_stand[8].arraySetSize(5);

        times_stand[8][0] = 1;
        keys_stand[8][0] = AL::ALValue::array(0.79046, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[8][1] = 2.16;
        keys_stand[8][1] = AL::ALValue::array(0.219404, AL::ALValue::array(3, -0.386667, 0.0444855), AL::ALValue::array(3, 0.0666667, -0.00766992));
        times_stand[8][2] = 2.36;
        keys_stand[8][2] = AL::ALValue::array(0.211734, AL::ALValue::array(3, -0.0666667, 0.00766992), AL::ALValue::array(3, 0.28, -0.0322137));
        times_stand[8][3] = 3.2;
        keys_stand[8][3] = AL::ALValue::array(-0.0383081, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[8][4] = 5.16;
        keys_stand[8][4] = AL::ALValue::array(-0.00302601, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LHipYawPitch");
        times_stand[9].arraySetSize(5);
        keys_stand[9].arraySetSize(5);

        times_stand[9][0] = 1;
        keys_stand[9][0] = AL::ALValue::array(-1.10444, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[9][1] = 2.16;
        keys_stand[9][1] = AL::ALValue::array(-0.429478, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[9][2] = 2.36;
        keys_stand[9][2] = AL::ALValue::array(-0.435614, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[9][3] = 3.2;
        keys_stand[9][3] = AL::ALValue::array(-0.182504, AL::ALValue::array(3, -0.28, -0.0434122), AL::ALValue::array(3, 0.653333, 0.101295));
        times_stand[9][4] = 5.16;
        keys_stand[9][4] = AL::ALValue::array(-0.00149202, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LKneePitch");
        times_stand[10].arraySetSize(5);
        keys_stand[10].arraySetSize(5);

        times_stand[10][0] = 1;
        keys_stand[10][0] = AL::ALValue::array(2.10461, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[10][1] = 2.16;
        keys_stand[10][1] = AL::ALValue::array(2.0954, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[10][2] = 2.36;
        keys_stand[10][2] = AL::ALValue::array(2.11255, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[10][3] = 3.2;
        keys_stand[10][3] = AL::ALValue::array(2.10767, AL::ALValue::array(3, -0.28, 0.00487225), AL::ALValue::array(3, 0.653333, -0.0113686));
        times_stand[10][4] = 5.16;
        keys_stand[10][4] = AL::ALValue::array(0.700996, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LShoulderPitch");
        times_stand[11].arraySetSize(5);
        keys_stand[11].arraySetSize(5);

        times_stand[11][0] = 1;
        keys_stand[11][0] = AL::ALValue::array(1.51862, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[11][1] = 2.16;
        keys_stand[11][1] = AL::ALValue::array(1.36522, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[11][2] = 2.36;
        keys_stand[11][2] = AL::ALValue::array(1.42811, AL::ALValue::array(3, -0.0666667, -0.00747334), AL::ALValue::array(3, 0.28, 0.031388));
        times_stand[11][3] = 3.2;
        keys_stand[11][3] = AL::ALValue::array(1.4818, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[11][4] = 5.16;
        keys_stand[11][4] = AL::ALValue::array(1.45112, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LShoulderRoll");
        times_stand[12].arraySetSize(5);
        keys_stand[12].arraySetSize(5);

        times_stand[12][0] = 1;
        keys_stand[12][0] = AL::ALValue::array(0.26534, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[12][1] = 2.16;
        keys_stand[12][1] = AL::ALValue::array(0.130348, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[12][2] = 2.36;
        keys_stand[12][2] = AL::ALValue::array(0.14262, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[12][3] = 3.2;
        keys_stand[12][3] = AL::ALValue::array(0.12728, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[12][4] = 5.16;
        keys_stand[12][4] = AL::ALValue::array(0.260738, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("LWristYaw");
        times_stand[13].arraySetSize(5);
        keys_stand[13].arraySetSize(5);

        times_stand[13][0] = 1;
        keys_stand[13][0] = AL::ALValue::array(-0.019984, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[13][1] = 2.16;
        keys_stand[13][1] = AL::ALValue::array(-0.00924587, AL::ALValue::array(3, -0.386667, -0.00959506), AL::ALValue::array(3, 0.0666667, 0.00165432));
        times_stand[13][2] = 2.36;
        keys_stand[13][2] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[13][3] = 3.2;
        keys_stand[13][3] = AL::ALValue::array(-0.016916, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[13][4] = 5.16;
        keys_stand[13][4] = AL::ALValue::array(-0.016916, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RAnklePitch");
        times_stand[14].arraySetSize(5);
        keys_stand[14].arraySetSize(5);

        times_stand[14][0] = 1;
        keys_stand[14][0] = AL::ALValue::array(-1.10137, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[14][1] = 2.16;
        keys_stand[14][1] = AL::ALValue::array(-1.1863, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[14][2] = 2.36;
        keys_stand[14][2] = AL::ALValue::array(-1.18574, AL::ALValue::array(3, -0.0666667, -0.000560196), AL::ALValue::array(3, 0.28, 0.00235282));
        times_stand[14][3] = 3.2;
        keys_stand[14][3] = AL::ALValue::array(-1.17654, AL::ALValue::array(3, -0.28, -0.00920402), AL::ALValue::array(3, 0.653333, 0.021476));
        times_stand[14][4] = 5.16;
        keys_stand[14][4] = AL::ALValue::array(-0.35738, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RAnkleRoll");
        times_stand[15].arraySetSize(5);
        keys_stand[15].arraySetSize(5);

        times_stand[15][0] = 1;
        keys_stand[15][0] = AL::ALValue::array(0.07214, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[15][1] = 2.16;
        keys_stand[15][1] = AL::ALValue::array(0.0565338, AL::ALValue::array(3, -0.386667, 0.00589708), AL::ALValue::array(3, 0.0666667, -0.00101674));
        times_stand[15][2] = 2.36;
        keys_stand[15][2] = AL::ALValue::array(0.0513985, AL::ALValue::array(3, -0.0666667, 0.00480128), AL::ALValue::array(3, 0.28, -0.0201654));
        times_stand[15][3] = 3.2;
        keys_stand[15][3] = AL::ALValue::array(-0.0183661, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[15][4] = 5.16;
        keys_stand[15][4] = AL::ALValue::array(-0.00455999, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RElbowRoll");
        times_stand[16].arraySetSize(5);
        keys_stand[16].arraySetSize(5);

        times_stand[16][0] = 1;
        keys_stand[16][0] = AL::ALValue::array(0.889762, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[16][1] = 2.16;
        keys_stand[16][1] = AL::ALValue::array(0.889762, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[16][2] = 2.36;
        keys_stand[16][2] = AL::ALValue::array(0.882092, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[16][3] = 3.2;
        keys_stand[16][3] = AL::ALValue::array(0.882092, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[16][4] = 5.16;
        keys_stand[16][4] = AL::ALValue::array(0.981802, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RElbowYaw");
        times_stand[17].arraySetSize(5);
        keys_stand[17].arraySetSize(5);

        times_stand[17][0] = 1;
        keys_stand[17][0] = AL::ALValue::array(1.41431, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[17][1] = 2.16;
        keys_stand[17][1] = AL::ALValue::array(1.41431, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[17][2] = 2.36;
        keys_stand[17][2] = AL::ALValue::array(1.43885, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[17][3] = 3.2;
        keys_stand[17][3] = AL::ALValue::array(1.43885, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[17][4] = 5.16;
        keys_stand[17][4] = AL::ALValue::array(1.40357, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RHand");
        times_stand[18].arraySetSize(5);
        keys_stand[18].arraySetSize(5);

        times_stand[18][0] = 1;
        keys_stand[18][0] = AL::ALValue::array(0.2588, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[18][1] = 2.16;
        keys_stand[18][1] = AL::ALValue::array(0.2588, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[18][2] = 2.36;
        keys_stand[18][2] = AL::ALValue::array(0.2588, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[18][3] = 3.2;
        keys_stand[18][3] = AL::ALValue::array(0.2588, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[18][4] = 5.16;
        keys_stand[18][4] = AL::ALValue::array(0.2588, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RHipPitch");
        times_stand[19].arraySetSize(5);
        keys_stand[19].arraySetSize(5);

        times_stand[19][0] = 1;
        keys_stand[19][0] = AL::ALValue::array(-0.220938, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[19][1] = 2.16;
        keys_stand[19][1] = AL::ALValue::array(-0.236278, AL::ALValue::array(3, -0.386667, 0.0153401), AL::ALValue::array(3, 0.0666667, -0.00264484));
        times_stand[19][2] = 2.36;
        keys_stand[19][2] = AL::ALValue::array(-0.372804, AL::ALValue::array(3, -0.0666667, 0.0299917), AL::ALValue::array(3, 0.28, -0.125965));
        times_stand[19][3] = 3.2;
        keys_stand[19][3] = AL::ALValue::array(-0.704148, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[19][4] = 5.16;
        keys_stand[19][4] = AL::ALValue::array(-0.449504, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RHipRoll");
        times_stand[20].arraySetSize(5);
        keys_stand[20].arraySetSize(5);

        times_stand[20][0] = 1;
        keys_stand[20][0] = AL::ALValue::array(-0.751618, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[20][1] = 2.16;
        keys_stand[20][1] = AL::ALValue::array(-0.292952, AL::ALValue::array(3, -0.386667, -0.00889709), AL::ALValue::array(3, 0.0666667, 0.00153398));
        times_stand[20][2] = 2.36;
        keys_stand[20][2] = AL::ALValue::array(-0.291418, AL::ALValue::array(3, -0.0666667, -0.00153398), AL::ALValue::array(3, 0.28, 0.00644272));
        times_stand[20][3] = 3.2;
        keys_stand[20][3] = AL::ALValue::array(-0.0199001, AL::ALValue::array(3, -0.28, -0.0118337), AL::ALValue::array(3, 0.653333, 0.027612));
        times_stand[20][4] = 5.16;
        keys_stand[20][4] = AL::ALValue::array(0.00771189, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RHipYawPitch");
        times_stand[21].arraySetSize(5);
        keys_stand[21].arraySetSize(5);

        times_stand[21][0] = 1;
        keys_stand[21][0] = AL::ALValue::array(-1.10444, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[21][1] = 2.16;
        keys_stand[21][1] = AL::ALValue::array(-0.429478, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[21][2] = 2.36;
        keys_stand[21][2] = AL::ALValue::array(-0.435614, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[21][3] = 3.2;
        keys_stand[21][3] = AL::ALValue::array(-0.182504, AL::ALValue::array(3, -0.28, -0.0434122), AL::ALValue::array(3, 0.653333, 0.101295));
        times_stand[21][4] = 5.16;
        keys_stand[21][4] = AL::ALValue::array(-0.00149202, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RKneePitch");
        times_stand[22].arraySetSize(5);
        keys_stand[22].arraySetSize(5);

        times_stand[22][0] = 1;
        keys_stand[22][0] = AL::ALValue::array(2.11083, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[22][1] = 2.16;
        keys_stand[22][1] = AL::ALValue::array(2.02492, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[22][2] = 2.36;
        keys_stand[22][2] = AL::ALValue::array(2.11255, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[22][3] = 3.2;
        keys_stand[22][3] = AL::ALValue::array(2.10929, AL::ALValue::array(3, -0.28, 0.00325438), AL::ALValue::array(3, 0.653333, -0.00759356));
        times_stand[22][4] = 5.16;
        keys_stand[22][4] = AL::ALValue::array(0.694944, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RShoulderPitch");
        times_stand[23].arraySetSize(5);
        keys_stand[23].arraySetSize(5);

        times_stand[23][0] = 1;
        keys_stand[23][0] = AL::ALValue::array(1.44814, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[23][1] = 2.16;
        keys_stand[23][1] = AL::ALValue::array(1.40519, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[23][2] = 2.36;
        keys_stand[23][2] = AL::ALValue::array(1.45427, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[23][3] = 3.2;
        keys_stand[23][3] = AL::ALValue::array(1.4466, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[23][4] = 5.16;
        keys_stand[23][4] = AL::ALValue::array(1.46655, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RShoulderRoll");
        times_stand[24].arraySetSize(5);
        keys_stand[24].arraySetSize(5);

        times_stand[24][0] = 1;
        keys_stand[24][0] = AL::ALValue::array(-0.0997519, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[24][1] = 2.16;
        keys_stand[24][1] = AL::ALValue::array(-0.122762, AL::ALValue::array(3, -0.386667, 0.00741433), AL::ALValue::array(3, 0.0666667, -0.00127833));
        times_stand[24][2] = 2.36;
        keys_stand[24][2] = AL::ALValue::array(-0.12583, AL::ALValue::array(3, -0.0666667, 0.000885007), AL::ALValue::array(3, 0.28, -0.00371703));
        times_stand[24][3] = 3.2;
        keys_stand[24][3] = AL::ALValue::array(-0.136568, AL::ALValue::array(3, -0.28, 0.0107381), AL::ALValue::array(3, 0.653333, -0.0250557));
        times_stand[24][4] = 5.16;
        keys_stand[24][4] = AL::ALValue::array(-0.251618, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));

        names_stand.push_back("RWristYaw");
        times_stand[25].arraySetSize(5);
        keys_stand[25].arraySetSize(5);

        times_stand[25][0] = 1;
        keys_stand[25][0] = AL::ALValue::array(0.0352399, AL::ALValue::array(3, -0.333333, 0), AL::ALValue::array(3, 0.386667, 0));
        times_stand[25][1] = 2.16;
        keys_stand[25][1] = AL::ALValue::array(0.0352399, AL::ALValue::array(3, -0.386667, 0), AL::ALValue::array(3, 0.0666667, 0));
        times_stand[25][2] = 2.36;
        keys_stand[25][2] = AL::ALValue::array(0.0398421, AL::ALValue::array(3, -0.0666667, 0), AL::ALValue::array(3, 0.28, 0));
        times_stand[25][3] = 3.2;
        keys_stand[25][3] = AL::ALValue::array(0.0398421, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.653333, 0));
        times_stand[25][4] = 5.16;
        keys_stand[25][4] = AL::ALValue::array(0.0398421, AL::ALValue::array(3, -0.653333, 0), AL::ALValue::array(3, 0, 0));
    }

    void StandUp()
    {
        postureProxy->goToPosture("StandInit", 0.9f);

        float gyros_values[2];
        gyros_values[0] = memoryProxy->getData((std::string)gyros_strings[0]);
        gyros_values[1] = memoryProxy->getData((std::string)gyros_strings[1]);

        if((abs((float)gyros_values[0]) < M_PI_4 && abs((float)gyros_values[1]) < M_PI_4))
        {
            falling = false;
            standing = true;
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

        boost::unique_lock<boost::mutex> motion_unique_lock(motion_lock); // starts locked

        float i = 0;

        AL::ALValue head_joints, head_values;
        head_joints.arraySetSize(2);
        head_values.arraySetSize(2);
        head_joints[0] = AL::ALValue("HeadYaw");
        head_joints[1] = AL::ALValue("HeadPitch");

        float theta_correction = 0.1;

        //thread loop
        while (!stopThreadCopy)
        {
            // note the time in nanoseconds since Jan 1 1970
            //boost::posix_time::time_duration duration = boost::get_system_time() - time_t_epoch;
            //long long timestampNanos = duration.total_nanoseconds();

            float gyros_values[2];
            gyros_values[0] = memoryProxy->getData((std::string)gyros_strings[0]);
            gyros_values[1] = memoryProxy->getData((std::string)gyros_strings[1]);

            //qiLogInfo("Motion") << "Gyro X: " << gyros_values[0] << std::endl << "Gyro Y: " << gyros_values[1] << std::endl << std::endl;

            if((abs((float)gyros_values[0]) > M_PI_4 || abs((float)gyros_values[1] > M_PI_4)) && standing)
            {
                motionProxy->stiffnessInterpolation("Body", 0.0f, 0.1f);
                standing = false;
                falling = true;
            }

            if((abs((float)gyros_values[0]) > 1.2f || abs((float)gyros_values[1]) > 1.2f) && falling)
            {
                motionProxy->stiffnessInterpolation("Body", 1.0f, 0.1f);
                StandUp();
            }

            //Update robot speed
            if(!speed_lock_p)
            {
                float sign = 0.0;
                speed_lock.lock();
                if(y_vel > 0.0)
                {
                    sign = -0.55;
                }
                else if(y_vel < 0.0)
                {
                    sign = -1.0;
                }
                motionProxy->moveToward(x_vel, y_vel, theta + sign*theta_correction, gait_parameters);
                speed_lock.unlock();
            }

            //Update neck angles
            if(!neck_lock_p)
            {
                neck_lock.lock();
                head_values[0] = AL::ALValue(neck_yaw);
                head_values[1] = AL::ALValue(neck_pitch);
                motionProxy->setAngles(head_joints, head_values, turn_time);
                neck_lock.unlock();
            }

            persistence.x_vel = x_vel;
            persistence.y_vel = y_vel;
            persistence.theta = theta;
            persistence.turn_time = turn_time;

            dataSaver.save(persistence);

            // calculate next tick time
            tickTime += samplingPeriod;
            // wait for timeout, unlock sockLock while waiting, and control for spurious wakes
            // by checking stopThread.
            condVar.timed_wait(motion_unique_lock, tickTime, boost::lambda::var(stopThread));
            stopThreadLock.lock();
            stopThreadCopy = stopThread;
            stopThreadLock.unlock();
        }
    }
};


Motion::Motion(boost::shared_ptr<AL::ALBroker> pBroker, const std::string &pName) : AL::ALModule(pBroker, pName)
{
    //Bind the methods so they can be called by other modules
    setModuleDescription("Control Goalkeeper motions and motors.");

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

    functionName("StartLoop", getName(), "Start the Motion Thread.");
    BIND_METHOD(Motion::StartLoop);

    functionName("StopLoop", getName(), "Stop the Motion Thread.");
    BIND_METHOD(Motion::StopLoop);

    functionName("Move", getName(), "Update robot move speed");
    addParam("x_vel", "Speed on x axis. Positive speeds means move forward. Negative means move backwards");
    addParam("y_vel", "Speed on y axis. Positive speeds means move left. Negative means move right");
    addParam("theta", "Speed on x axis. Positive speeds means turn counterclockwise. Negative means turn clockwise");
    BIND_METHOD(Motion::Move);

    functionName("StopMove", getName(), "Sets all robot speeds to 0.0");
    BIND_METHOD(Motion::StopMove);

    functionName("MoveNeck", getName(), "Update robot neck angles");
    addParam("turn_time", "time to change angles");
    addParam("neck_yaw", "Neck Yaw angles.");
    addParam("neck_pitch", "Neck Pitch angles");
    BIND_METHOD(Motion::MoveNeck);

    functionName("Defend", getName(), "Runs the defense choreography");
    BIND_METHOD(Motion::Defend);

    functionName("StandUp", getName(), "Runs the stand up after defending choreography");
    BIND_METHOD(Motion::StandUp);

    functionName("GetHeadAngles", getName(), "Return head yaw and pitch");
    setReturn("AL::ALValue", "Returns a vector contaning head yaw and pitch angles.");
    BIND_METHOD(Motion::GetHeadAngles);
}

Motion::~Motion()
{
    //Continue
}

/**
 * Overrides ALModule::init(). This is called right after the module has been constructed.
 */
void Motion::init()
{
    try
    {
        isActive = false;
        AL::ALModule::init();
    }
    catch (std::exception& e)
    {
        qiLogError("Motion") << "Failed to initialize Motion Module" << e.what() << std::endl;
        exit();
    }
}

/**
 * Overides ALModule::exit(), called before unloading
 */
void Motion::exit()
{
    //Always call ALModule::exit() or the module won't be destroyed properly
    isActive = false;
    AL::ALModule::exit();
}

void Motion::StartLoop()
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
            qiLogError("Motion") << "Failed to start the thread." << e.what() << std::endl;
            throw MotionError("Failed to start the thread.");
            exit();
        }
        isActive = true;
    }
    else
    {
        throw MotionError("Module is already active.");
    }
}

void Motion::StopLoop()
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
            qiLogError("Motion") << "Failed to stop the thread." << e.what() << std::endl;
            throw MotionError("Failed to stop the thread.");
            exit();
        }
        isActive = false;
    }
    else
    {
        throw MotionError("Module is already inactive.");
    }
}

void Motion::Move(const float &x_vel, const float &y_vel, const float &theta)
{
    //Lock the speed variables to update it
    impl->speed_lock.lock();
    impl->speed_lock_p = true;
    impl->speed_lock.unlock();

    //Update variables
    impl->x_vel = x_vel;
    impl->y_vel = y_vel;
    impl->theta = theta;

    //Unlock the speed variables
    impl->speed_lock.lock();
    impl->speed_lock_p = false;
    impl->speed_lock.unlock();
}

void Motion::StopMove()
{
    //Lock the speed variables to update it
    impl->speed_lock.lock();
    impl->speed_lock_p = true;
    impl->speed_lock.unlock();

    //Update variables
    impl->x_vel = 0.0;
    impl->y_vel = 0.0;
    impl->theta = 0.0;

    //Unlock the speed variables
    impl->speed_lock.lock();
    impl->speed_lock_p = false;
    impl->speed_lock.unlock();
}

void Motion::MoveNeck(const float& turn_time, const float &neck_yaw, const float &neck_pitch)
{
    //Lock the speed variables to update it
    impl->neck_lock.lock();
    impl->neck_lock_p = true;
    impl->neck_lock.unlock();

    //Update variables
    impl->neck_yaw = neck_yaw;
    impl->neck_pitch = neck_pitch;
    impl->turn_time = turn_time;

    //Unlock the speed variables
    impl->neck_lock.lock();
    impl->neck_lock_p = false;
    impl->neck_lock.unlock();
}

void Motion::Defend()
{
    StopMove();
    try
    {
        impl->motionProxy->angleInterpolationBezier(impl->names_defend, impl->times_defend, impl->keys_defend);
    }
    catch(const std::exception& e)
    {
        throw MotionError(e.what());
    }

}

void Motion::StandUp()
{
    try
    {
        impl->motionProxy->angleInterpolationBezier(impl->names_stand, impl->times_stand, impl->keys_stand);
    }
    catch(const std::exception& e)
    {
        throw MotionError(e.what());
    }
}

void Motion::StandInit()
{
    impl->postureProxy->goToPosture("StandInit", 0.9f);
}

AL::ALValue Motion::GetHeadAngles()
{
    AL::ALValue neck_angles;
    neck_angles.arraySetSize(2);
    neck_angles[0] = impl->memoryProxy->getData((std::string)(impl->neck_strings[0]));
    neck_angles[1] = impl->memoryProxy->getData((std::string)(impl->neck_strings[1]));

    return neck_angles;
}


//Exception Class

MotionError::MotionError(const char* message)
  : msg(message) {}

MotionError::MotionError(const std::string message)
  : msg(message.c_str()) {}

const char* MotionError::what() { return msg; }
