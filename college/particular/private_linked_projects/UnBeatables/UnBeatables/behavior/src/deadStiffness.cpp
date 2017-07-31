#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>

deadStiffness* deadStiffness::instance = NULL;

deadStiffness::deadStiffness()
{

}

BehaviorBase* deadStiffness::Behavior()
{
    if(! instance)
    {
        instance = new deadStiffness();
    }
    return instance;
}

void deadStiffness::action()
{
    std::cout << "Dead!" << std::endl;
    std::cout << "Get Up Front" << std::endl;
    commandStatic.body = MotionAux::DeadStiffness();
    MotionAux::SendCommand(commandStatic);
}

BehaviorBase* deadStiffness::transition()
{
    SensorValues sensorValues = SensorBoard.load();
    if(sensorValues.sensors[0] != NAN)
    {
        BehaviorBase* returnBehavior= MotionAux::getUpIfFalling(sensorValues);
        if(returnBehavior != NULL)
        {
            return returnBehavior;
        }
    }
    return this;
}
