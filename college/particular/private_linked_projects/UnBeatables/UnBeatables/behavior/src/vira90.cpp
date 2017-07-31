#include <includeMapBehavior.hpp>

vira90* vira90::instance = NULL;

vira90::vira90()
{
	contadorVira=0;
}

BehaviorBase* vira90::Behavior()
{
    if(! instance)
    {
        instance = new vira90();
    }
    return instance;
}

void vira90::action()
{
    qiLogInfo("ReadyMachine") << "State: Vira90" << contadorVira << std::endl;
    commandStatic.leds = LEDAux::changeColor(3,0,0);
    commandStatic.body = MotionAux::Walk(0.0, 0.0, 10);
    MotionAux::SendCommand(commandStatic);
    contadorVira++;
}

BehaviorBase* vira90::transition()
{
    if(contadorVira < 3000)    
        return this;
    else
    { 
        contadorVira = 0;
        return stayStill::Behavior();
    }
}