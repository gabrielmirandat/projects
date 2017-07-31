/*
* ClasseMenor inherited from BehaviorBase.
*/
#include <includeMapBehavior.hpp>

class ClasseMenor : public BehaviorBase
{
private:
    static ClasseMenor *instance;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
