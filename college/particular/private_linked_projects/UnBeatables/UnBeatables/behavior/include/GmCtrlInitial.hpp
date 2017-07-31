/*
* GmCtrlInitial inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>
#include <GmCtrlPenalized.hpp>
#include <GmCtrlReady.hpp>

class GmCtrlInitial : public BehaviorBase
{
private:
    GmCtrlInitial();
    unBoard<RoboCupGameControlData> loadGmCtrlData;
    static GmCtrlInitial *instance;
    int penalized;
    bool vbOnce;
    RoboCupGameControlData gmCtrlData;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
