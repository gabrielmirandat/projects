/*
* sonarMiddle inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class sonarMiddle : public BehaviorBase
{
private:
    static sonarMiddle *instance;

public:
    sonarMiddle();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
