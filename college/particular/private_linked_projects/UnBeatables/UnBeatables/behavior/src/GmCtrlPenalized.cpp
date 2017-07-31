#include <includeMapBehavior.hpp>

GmCtrlPenalized* GmCtrlPenalized::instance = NULL;

GmCtrlPenalized::GmCtrlPenalized()
{
	penalized = 1;
	vbOnce = true;
}

BehaviorBase* GmCtrlPenalized::Behavior()
{
    if(! instance)
    {
        instance = new GmCtrlPenalized();
    }
    return instance;
}

void GmCtrlPenalized::action()
{
    gmCtrlData=loadGmCtrlData.load();
    if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
        penalized=1;
    }
    else {
        penalized=0;
    }

    qiLogInfo("Behavior") << "Estou preso antes do loop do penalized " << penalized << std::endl;
    while(penalized==1)
    {
        boost::system_time tickTime = boost::get_system_time();
        qiLogInfo("Behavior") << "State: Penalized" << std::endl;
    	gmCtrlData=loadGmCtrlData.load();
        commandStatic.leds = LEDAux::changeColor(1,0,0);
    	if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty == 0) {
        	penalized= 0;
    	}
    	else {
    		penalized = 1;
			if(vbOnce){
				commandStatic.body = MotionAux::Penalize();
				MotionAux::SendCommand(commandStatic);
				vbOnce = false;
			}
        }

        boost::posix_time::time_duration duration = boost::get_system_time() - tickTime;
        long long timestampNanos = duration.total_milliseconds();
        if(int diff = (BEHAVIOR_FREQ_MS - timestampNanos) > 0)
            boost::this_thread::sleep(boost::posix_time::milliseconds(diff));
    }

}

BehaviorBase* GmCtrlPenalized::transition()
{
	if (penalized == 1) {
    	return this;
	}
	else
	{
		vbOnce = true;
		switch(gmCtrlData.state) {
            case STATE_INITIAL:
                return GmCtrlInitial::Behavior();
                break;
			case STATE_READY:
				return GmCtrlReady::Behavior();
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
