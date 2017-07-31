/*
* ReadyMachine inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class ReadyMachine : public BehaviorBase
{
private:
    static ReadyMachine *instance;
    int contadorWalk;
    int vbOnce;

public:
    ReadyMachine();
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
