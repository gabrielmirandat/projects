/*
* turnToBall inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class turnToBall : public BehaviorBase
{
private:
    turnToBall();
    static turnToBall *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
