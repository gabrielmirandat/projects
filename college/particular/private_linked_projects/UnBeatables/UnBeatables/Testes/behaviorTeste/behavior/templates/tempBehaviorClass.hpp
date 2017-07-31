/*
* tempBehaviorClass inherited from BehaviorBase.
*/
#include <includeMapBehavior.hpp>

class tempBehaviorClass : public BehaviorBase
{
private:
    static tempBehaviorClass *instance;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
    