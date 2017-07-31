#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>


Kick* Kick::instance = NULL;

Kick::Kick()
{
    /*Ball ball;
    ball = findBall();*/

}

BehaviorBase* Kick::Behavior()
{
    if(! instance)
    {
        instance = new Kick();
    }
    return instance;
}

void Kick::action()
{
    commandStatic.body = MotionAux::Kick(160.0, 45.0, 0.0);
    MotionAux::SendCommand(commandStatic);

    kickIsFinished = kickFlagBoard.load();
    std::cout << "Kicking" << std::endl;
    //std::cout << "kick is:" << kickIsFinished.kickFinished << std::endl;

    /*if(kickIsFinished.kickFinished == 1)
    {
        commandStatic.body = MotionAux::Stand();
        MotionAux::SendCommand(commandStatic);
    }*/
}

BehaviorBase* Kick::transition()
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
	if(kickIsFinished.kickFinished != 1)
        return this;
    if(kickIsFinished.kickFinished == 1)
        return Start::Behavior();
}
