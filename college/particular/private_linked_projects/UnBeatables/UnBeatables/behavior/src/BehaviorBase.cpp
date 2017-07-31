#include <BehaviorBase.hpp>
#include <motionAuxiliarFunctions.hpp>

Command teste(){
    Command testando;
    memset(&testando, 0, sizeof(testando));
    return testando;
}
Command BehaviorBase::commandStatic = teste();
