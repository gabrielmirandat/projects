/*
* walk inherited from BehaviorBase.
*/
#pragma once
#include <BehaviorBase.hpp>
#include <kickFlag.hpp>
#include <unBoard.hpp>

class walk : public BehaviorBase
{
private:
    static walk *instance;
   // unBoard<kickFlag> kickFlagBoard;
    //kickFlag kickIsFinished;   
    int contadorBall, center;
    float lastBallX, lastBallY, ballX, ballY;
    bool camera, align;

public:
	walk();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
    
