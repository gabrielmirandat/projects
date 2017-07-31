/*
* newWalk inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class newWalk : public BehaviorBase
{
private:
    static newWalk *instance;

public:
    newWalk();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
