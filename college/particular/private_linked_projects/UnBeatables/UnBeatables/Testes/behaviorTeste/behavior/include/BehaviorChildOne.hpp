/*
* BehaviorChildOne inherited from BehaviorBase.
*/
#include <includeMapBehavior.hpp>

class BehaviorChildOne : public BehaviorBase
{
private:
    static BehaviorChildOne *singleOne;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
