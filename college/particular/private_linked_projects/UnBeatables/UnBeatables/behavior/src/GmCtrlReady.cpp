#include <includeMapBehavior.hpp>

GmCtrlReady* GmCtrlReady::instance = NULL;

GmCtrlReady::GmCtrlReady()
{
	penalized = 0;
	vbOnce = true;
}

BehaviorBase* GmCtrlReady::Behavior()
{
    if(! instance)
    {
        instance = new GmCtrlReady();
    }
    return instance;
}

void GmCtrlReady::action()
{
	BehaviorBase* current;
    current = ReadyMachine::Behavior();
	gmCtrlData=loadGmCtrlData.load();
    commandStatic.leds = LEDAux::changeColor(3,0,0);
    while((gmCtrlData.state==STATE_READY) && (penalized == 0))
    {
        boost::system_time tickTime = boost::get_system_time();
        qiLogInfo("Behavior") << "State: Ready" << std::endl;
        gmCtrlData=loadGmCtrlData.load();
        if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
            penalized=1;
        }
        else{
            penalized=0;
            current->action();
            current = current->transition();
        }


        boost::posix_time::time_duration duration = boost::get_system_time() - tickTime;
        long long timestampNanos = duration.total_milliseconds();
        if(int diff = (BEHAVIOR_FREQ_MS - timestampNanos) > 0)
            boost::this_thread::sleep(boost::posix_time::milliseconds(diff));
    }
}

BehaviorBase* GmCtrlReady::transition()
{
	if (penalized==1){
		return GmCtrlPenalized::Behavior();
	}
	else {
		switch(gmCtrlData.state) {
	        case STATE_INITIAL:
        		return GmCtrlInitial::Behavior();
	            break;
	        case STATE_READY:
	            return this;
	            break;
	        case STATE_SET:
	            return GmCtrlSet::Behavior();
	            break;
	        case STATE_PLAYING:
	            return GmCtrlPlaying::Behavior();
	            break;
	        case STATE_FINISHED:
	            return GmCtrlFinished::Behavior();
	            break;
	    }
	}
}
