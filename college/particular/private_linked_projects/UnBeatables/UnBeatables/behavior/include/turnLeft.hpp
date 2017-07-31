/*
* turnLeft inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class turnLeft : public BehaviorBase
{
private:
    static turnLeft *instance;
    int contadorBall;
    float lastBallX;
    float lastBallY; 
    float ballX;
    float ballY;
    float center;
    bool camera;
    bool flag;

public:
    turnLeft();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
