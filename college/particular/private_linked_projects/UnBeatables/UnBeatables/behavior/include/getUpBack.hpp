/*
* getUpBack inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class getUpBack : public BehaviorBase
{
private:
    getUpBack();
    static getUpBack *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
