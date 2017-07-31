#include <includeMapBehavior.hpp>

GmCtrlPlaying* GmCtrlPlaying::instance = NULL;

GmCtrlPlaying::GmCtrlPlaying()
{
	penalized = 0;
}

BehaviorBase* GmCtrlPlaying::Behavior()
{
    if(! instance)
    {
        instance = new GmCtrlPlaying();
    }
    return instance;
}

void GmCtrlPlaying::action()
{
    BehaviorBase* current;
    gmCtrlData=loadGmCtrlData.load();
    if ((int)gmCtrlData.teams[TEAM_NUM_VECTOR].players[PLAYER_NUM-1].penalty != 0) {
        penalized=1;
    }
    else {
        penalized=0;
    }
    commandStatic.leds = LEDAux::changeColor(2,0,0);
    current = Start::Behavior();
    qiLogInfo("Behavior") << "Estou preso antes do loop do playing " << penalized << std::endl;
    while((gmCtrlData.state==STATE_PLAYING)&&(penalized==0))
    {
        boost::system_time tickTime = boost::get_system_time();
        qiLogInfo("Behavior") << "Playing" << std::endl;
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

BehaviorBase* GmCtrlPlaying::transition()
{
    if (penalized==1){
        qiLogInfo("Behavior") << "Retorna Penalized " << std::endl;
    	return GmCtrlPenalized::Behavior();
    }
    
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
                qiLogInfo("Behavior") << "Retorna Playing " << penalized << std::endl;
                return this;
                break;
            case STATE_FINISHED:
                return GmCtrlFinished::Behavior();
                break;
        }
    }
}

