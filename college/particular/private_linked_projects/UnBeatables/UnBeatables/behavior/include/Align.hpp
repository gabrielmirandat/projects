/*
* Align inherited from BehaviorBase.
*/

#include <BehaviorBase.hpp>
class Align : public BehaviorBase
{
private:
    Align();
    static Align *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
