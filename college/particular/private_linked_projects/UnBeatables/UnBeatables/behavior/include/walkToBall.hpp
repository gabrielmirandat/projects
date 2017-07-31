/*
* walkToBall inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class walkToBall : public BehaviorBase
{
private:
    walkToBall();
    static walkToBall *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
