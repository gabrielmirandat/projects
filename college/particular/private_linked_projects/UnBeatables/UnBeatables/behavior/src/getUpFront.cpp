#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>

getUpFront* getUpFront::instance = NULL;

getUpFront::getUpFront()
{

}

BehaviorBase* getUpFront::Behavior()
{
    if(! instance)
    {
        instance = new getUpFront();
    }
    return instance;
}

void getUpFront::action()
{

	std::cout << "Get Up Front" << std::endl;
    commandStatic.body = MotionAux::GetUpFront();
    MotionAux::SendCommand(commandStatic); 
    boost::this_thread::sleep(boost::posix_time::milliseconds(6500));

}

BehaviorBase* getUpFront::transition()
{
    return Start::Behavior();

}
