/*
* GmCtrlReady inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>

class GmCtrlReady : public BehaviorBase
{
private:
    GmCtrlReady();
    static GmCtrlReady *instance;
    int penalized;
    int vbOnce;
    RoboCupGameControlData gmCtrlData;
    unBoard<RoboCupGameControlData> loadGmCtrlData;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
