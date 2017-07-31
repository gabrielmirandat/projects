/*
* stayStill inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class stayStill : public BehaviorBase
{
private:
    static stayStill *instance;
    int vbOnce;
    int vbTwice;
    int counter;

public:
    stayStill();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
