#ifndef LOOKFORBALL_H
#define LOOKFORBALL_H

#include <BehaviorBase.hpp>

class LookForBall : public BehaviorBase {
private:
    static LookForBall *instance;
    bool bit;
    int ball_lost, wandering_ticks;
    float ballX, ballY;
public:
    LookForBall();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();

};

#endif // LOOKFORBALL_H
