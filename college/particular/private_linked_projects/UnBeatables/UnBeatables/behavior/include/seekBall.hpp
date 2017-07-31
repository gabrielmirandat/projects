/*
* seekBall inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class seekBall : public BehaviorBase
{
private:
    seekBall();
    static seekBall *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
