#include <includeMapBehavior.hpp>

GmCtrlInitial* GmCtrlInitial::instance = NULL;

GmCtrlInitial::GmCtrlInitial()
{
    penalized = 0;
    vbOnce = true;
}

BehaviorBase* GmCtrlInitial::Behavior()
{
    if(! instance)
    {
        instance = new GmCtrlInitial();
    }
    return instance;
}

void GmCtrlInitial::action()
{
    gmCtrlData.state=STATE_INITIAL;
    if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
        penalized=1;
    }
    else {
        penalized=0;
    }
    commandStatic.leds = LEDAux::changeColor(0, 2, 0);
    MotionAux::SendCommand(commandStatic);
    while(gmCtrlData.state==STATE_INITIAL) {
        boost::system_time tickTime = boost::get_system_time();
        qiLogInfo("Communication/Behavior") << "State: Initial - " << (int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM].penalty <<  std::endl;
        gmCtrlData=loadGmCtrlData.load();
        if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
            penalized=1;
        }
        else {
            penalized=0;
        }
        if(vbOnce)
        {
            commandStatic.body = MotionAux::Penalize();
            MotionAux::SendCommand(commandStatic);
            vbOnce = false;
        }
        boost::posix_time::time_duration duration = boost::get_system_time() - tickTime;
        long long timestampNanos = duration.total_milliseconds();
        if(int diff = (BEHAVIOR_FREQ_MS - timestampNanos) > 0)
        boost::this_thread::sleep(boost::posix_time::milliseconds(diff));
    }
}

BehaviorBase* GmCtrlInitial::transition()
{
    vbOnce = true;
	if (penalized==1)
        return GmCtrlPenalized::Behavior();
    else {
        switch(gmCtrlData.state) {
            case STATE_INITIAL:
                vbOnce = false;
                return this;
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
