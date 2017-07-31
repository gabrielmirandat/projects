#include <includeMapBehavior.hpp>

GmCtrlSet* GmCtrlSet::instance = NULL;

GmCtrlSet::GmCtrlSet()
{
	penalized = 0;
}

BehaviorBase* GmCtrlSet::Behavior()
{
    if(! instance)
    {
        instance = new GmCtrlSet();
    }
    return instance;
}

void GmCtrlSet::action()
{   
    qiLogInfo("Communication/Behavior") << "State: Set" << std::endl;
    gmCtrlData=loadGmCtrlData.load();

    commandStatic.leds = LEDAux::changeColor(4, 0, 0);
    commandStatic.body = MotionAux::Penalize();
    MotionAux::SendCommand(commandStatic);
    
    if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
        penalized=1;
    }
    else {
        penalized=0;
    }
}

BehaviorBase* GmCtrlSet::transition()
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
                return this;
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
