/*
 *
* Base Class to All Behavior
* All Behavior Should Inherite From this class and override this methods!
*/
#pragma once
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

#include <RoboCupGameControlData.h>
#include <unBoard.hpp>
#include <types/SensorValues.hpp>
#include <motionData.hpp>
#include <visionData.hpp>
#include <Settings.hpp>

#include <proxyData.hpp>

#define BEHAVIOR_FREQ_MS 200

class BehaviorBase
{
protected:
    boost::interprocess::managed_shared_memory managed_shm;
    unBoard<SensorValues> SensorBoard;
    unBoard<visionData> VisionBoard;

public:
    static Command commandStatic;
    static BehaviorBase* Behavior();
    virtual BehaviorBase* transition(){ return NULL;};
    virtual void action(){};
};
