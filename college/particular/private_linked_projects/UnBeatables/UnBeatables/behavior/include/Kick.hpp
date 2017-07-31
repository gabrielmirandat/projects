/*
 *
* Kick inherited from BehaviorBase.
*/

#pragma once

#include <BehaviorBase.hpp>
#include <kickFlag.hpp>
#include <unBoard.hpp>

class Kick : public BehaviorBase
{
private:
//	Ball ball;
    Kick();
    static Kick *instance;
    unBoard<kickFlag> kickFlagBoard;
    kickFlag kickIsFinished;  

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
