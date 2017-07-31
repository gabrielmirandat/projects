/*
* turnRight inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class turnRight : public BehaviorBase
{
private:
    static turnRight *instance;
    int contadorBall;
    float lastBallX;
    float lastBallY; 
    float ballX;
    float ballY;
    int center;
    bool camera;
    bool flag;
public:
    turnRight();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
