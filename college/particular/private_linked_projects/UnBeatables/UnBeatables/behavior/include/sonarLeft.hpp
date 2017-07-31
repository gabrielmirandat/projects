/*
* sonarLeft inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class sonarLeft : public BehaviorBase
{
private:
    static sonarLeft *instance;

public:
    sonarLeft();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
