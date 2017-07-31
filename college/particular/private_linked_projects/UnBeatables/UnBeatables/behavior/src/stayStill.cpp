#include <includeMapBehavior.hpp>

stayStill* stayStill::instance = NULL;

stayStill::stayStill()
{
	vbOnce = true;
	vbTwice = true;
	counter = 0;
}

BehaviorBase* stayStill::Behavior()
{
    if(! instance)
    {
        instance = new stayStill();
    }
    return instance;
}

void stayStill::action()
{	
	counter++;
    boost::system_time tickTime = boost::get_system_time();
    qiLogInfo("Communication/Behavior") << "State: stayStill - Counter:" << counter << " VbOnce: " << vbOnce << " vbTwice: " << vbTwice << std::endl;
    commandStatic.body = MotionAux::Penalize();
	MotionAux::SendCommand(commandStatic);
	boost::posix_time::time_duration duration = boost::get_system_time() - tickTime;
    long long timestampNanos = duration.total_milliseconds();
    if(int diff = (BEHAVIOR_FREQ_MS - timestampNanos) > 0)
        boost::this_thread::sleep(boost::posix_time::milliseconds(diff));

}

BehaviorBase* stayStill::transition()
{
	if (counter<10) {
    	return this;
	}
	else {
		if (vbOnce==true) {
			vbOnce=false;
			return vira90::Behavior();
		}
		else {
			return this;
		}
	}
}
