#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>

Start* Start::instance = NULL;


BehaviorBase* Start::Behavior()
{
    if(! instance)
    {
        instance = new Start();
    }
    return instance;
}

void Start::action()
{


    std::cout << "Starting Fred!" << std::endl;

    commandStatic.body = MotionAux::Stand();
    MotionAux::SendCommand(commandStatic); 
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));

}

BehaviorBase* Start::transition()
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
    
    //SonarClass sonarValues =
    
    
    return LookForBall::Behavior();
     //return this;
}
