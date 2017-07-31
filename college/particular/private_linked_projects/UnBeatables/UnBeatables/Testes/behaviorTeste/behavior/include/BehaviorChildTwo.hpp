/*
* BehaviorChildTwo inherited from BehaviorBase.
*/
#include <includeMapBehavior.hpp>

class BehaviorChildTwo : public BehaviorBase
{
private:
    static BehaviorChildTwo *singleOne;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
