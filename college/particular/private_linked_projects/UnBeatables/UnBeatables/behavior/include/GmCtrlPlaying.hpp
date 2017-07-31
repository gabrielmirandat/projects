/*
* GmCtrlPlaying inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>

class GmCtrlPlaying : public BehaviorBase
{
private:
    GmCtrlPlaying();
    static GmCtrlPlaying *instance;
    int penalized;
    unBoard<RoboCupGameControlData> loadGmCtrlData;
	RoboCupGameControlData gmCtrlData;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
