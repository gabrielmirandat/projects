#include <includeMapBehavior.hpp>

ReadyMachine* ReadyMachine::instance = NULL;

ReadyMachine::ReadyMachine()
{
    contadorWalk = 0;
    vbOnce = true;
}

BehaviorBase* ReadyMachine::Behavior()
{
    if(! instance)
    {
        instance = new ReadyMachine();
    }
    return instance;
}

void ReadyMachine::action()
{
    qiLogInfo("ReadyMachine") << contadorWalk << std::endl;
    commandStatic.leds = LEDAux::changeColor(3,0,0);
    commandStatic.body = MotionAux::Walk(300.0, 0.0, 0.0);
    MotionAux::SendCommand(commandStatic);
    contadorWalk++;
}

BehaviorBase* ReadyMachine::transition()
{
    //  // SensorValues sensorValues = SensorBoard.load();
    // if(sensorValues.sensors[0] != NAN)
    // {
    //     BehaviorBase* returnBehavior= MotionAux::getUpIfFalling(sensorValues);
    //     if(returnBehavior != NULL)
    //     {
    //         return returnBehavior;
    //     }
    // }
    if(contadorWalk < 7000)    
        return this;
    else
    { 
        contadorWalk = 0;
        return stayStill::Behavior();
    }
}
