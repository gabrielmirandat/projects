/*
* refPickup inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class refPickup : public BehaviorBase
{
private:
    refPickup();
    static refPickup *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
