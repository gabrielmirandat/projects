/*
* vira90 inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class vira90 : public BehaviorBase
{
private:
    static vira90 *instance;
    int contadorVira;

public:
    vira90();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
