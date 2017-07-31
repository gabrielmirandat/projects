/*
* ClasseMaior inherited from BehaviorBase.
*/
#include <includeMapBehavior.hpp>

class ClasseMaior : public BehaviorBase
{
private:
    static ClasseMaior *instance;

public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
    