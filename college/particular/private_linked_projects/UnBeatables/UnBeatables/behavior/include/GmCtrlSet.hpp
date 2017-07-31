/*
* GmCtrlSet inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>
#include <ledAuxiliarFunctions.hpp>
#include <GmCtrlPlaying.hpp>
#include <GmCtrlPenalized.hpp>

class GmCtrlSet : public BehaviorBase
{
private:
    GmCtrlSet();
    static GmCtrlSet *instance;
    int penalized;
    RoboCupGameControlData gmCtrlData;
    unBoard<RoboCupGameControlData> loadGmCtrlData;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
