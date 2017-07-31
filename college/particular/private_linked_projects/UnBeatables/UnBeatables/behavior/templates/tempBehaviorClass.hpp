/*
* tempBehaviorClass inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class tempBehaviorClass : public BehaviorBase
{
private:
    static tempBehaviorClass *instance;

public:
    tempBehaviorClass();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
