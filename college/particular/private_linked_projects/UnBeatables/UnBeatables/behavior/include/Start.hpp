/*
* Start inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class Start : public BehaviorBase
{
private:
   
    static Start *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
