/*
* deadStiffness inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class deadStiffness : public BehaviorBase
{
private:
    deadStiffness();
    static deadStiffness *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
