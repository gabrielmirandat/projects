/*
* GmCtrlPenalized inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>
#include <GmCtrlReady.hpp>
#include <GmCtrlSet.hpp>
#include <GmCtrlPlaying.hpp>

class GmCtrlPenalized : public BehaviorBase
{
private:
    GmCtrlPenalized();
    static GmCtrlPenalized *instance;
    int penalized;
    bool vbOnce;
    RoboCupGameControlData gmCtrlData;
    unBoard<RoboCupGameControlData> loadGmCtrlData;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
