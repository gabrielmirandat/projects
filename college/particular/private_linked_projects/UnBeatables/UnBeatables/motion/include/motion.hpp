#ifndef _MOTION_H_
#define _MOTION_H_

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>

namespace AL {
    class ALBroker;
}

/**
 * This class inherits AL::ALModule to bind methods and be run as a plugin within NAOqi.
 */

class Motion : public AL::ALModule
{
public:
	Motion(boost::shared_ptr<AL::ALBroker> pBroker, const std::string& pName);
	~Motion();
	/**
    * Overrides ALModule::init() and ALModule::exit(). exit() is called before unloading.
    * init() is called right after the module has been loaded.
    */
    void init(), exit();
    
    //Start the module's thread
    void StartLoop();

    //Stop the module's thread
    void StopLoop();

    //Move function
    void Move(const float& x_vel, const float& y_vel, const float& theta);

    //Stop the movement
    void StopMove();

    //Move the Neck
    void MoveNeck(const float& turn_time, const float& neck_yaw, const float& neck_pitch);

    //Defend
    void Defend();

    //Stand up after defending
    void StandUp();

    //Just call aldebaran stand
    void StandInit();

    //Returns a vector with head yaw and pitch angles
    AL::ALValue GetHeadAngles();

private:
    struct Impl;
    boost::shared_ptr<Impl> impl;
    bool isActive;
};

class MotionError: public std::exception
{
public:
    MotionError(const char* message);
    MotionError(const std::string message);
    virtual const char* what();

private:
    const char* msg;
};






 #endif //_MOTION_H_
