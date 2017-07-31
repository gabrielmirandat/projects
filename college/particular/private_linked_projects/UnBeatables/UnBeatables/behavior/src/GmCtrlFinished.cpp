#include <includeMapBehavior.hpp>

GmCtrlFinished* GmCtrlFinished::instance = NULL;

GmCtrlFinished::GmCtrlFinished()
{
    
}

BehaviorBase* GmCtrlFinished::Behavior()
{
    if(! instance)
    {
        instance = new GmCtrlFinished();
    }
    return instance;
}

void GmCtrlFinished::action()
{	
	gmCtrlData=loadGmCtrlData.load();
    commandStatic.leds = LEDAux::changeColor(0, 0, 0);
    if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
        penalized=1;
    }
    else {
        penalized=0;
    }
    while(gmCtrlData.state==STATE_FINISHED) {
    	boost::system_time tickTime = boost::get_system_time();
    	qiLogInfo("Communication/Behavior") << "State: Finished" << std::endl;
        gmCtrlData=loadGmCtrlData.load();
        if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
            penalized=1;
        }
        else {
            penalized=0;
        }
        commandStatic.body = MotionAux::Penalize();
        MotionAux::SendCommand(commandStatic);
        boost::posix_time::time_duration duration = boost::get_system_time() - tickTime;
        long long timestampNanos = duration.total_milliseconds();
        if(int diff = (BEHAVIOR_FREQ_MS - timestampNanos) > 0)
        boost::this_thread::sleep(boost::posix_time::milliseconds(diff));
    }

}

BehaviorBase* GmCtrlFinished::transition()
{
    if (penalized==1)
    	return GmCtrlPenalized::Behavior();
    else {
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
                return this;
                break;
        }
    }
}
