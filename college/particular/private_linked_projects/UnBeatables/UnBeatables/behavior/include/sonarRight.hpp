/*
* sonarRight inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class sonarRight : public BehaviorBase
{
private:
    static sonarRight *instance;

public:
    sonarRight();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
