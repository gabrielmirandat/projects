/*
* GmCtrlFinished inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>

class GmCtrlFinished : public BehaviorBase
{
private:
    GmCtrlFinished();
    static GmCtrlFinished *instance;
    int penalized;
    RoboCupGameControlData gmCtrlData;
    unBoard<RoboCupGameControlData> loadGmCtrlData;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
