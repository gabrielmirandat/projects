#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>

refPickup* refPickup::instance = NULL;

refPickup::refPickup()
{

}

BehaviorBase* refPickup::Behavior()
{
    if(! instance)
    {
        instance = new refPickup();
    }
    return instance;
}

void refPickup::action()
{
    std::cout << "Ref Pickup" << std::endl;
    commandStatic.body = MotionAux::RefPickup();
    MotionAux::SendCommand(commandStatic);
}

BehaviorBase* refPickup::transition()
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
    return Start::Behavior();
}
