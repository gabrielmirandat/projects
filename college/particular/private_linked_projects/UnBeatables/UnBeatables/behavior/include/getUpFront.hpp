/*
* getUpFront inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>


class getUpFront : public BehaviorBase
{
private:
    getUpFront();
    static getUpFront *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
