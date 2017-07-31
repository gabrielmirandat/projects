#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>


getUpBack* getUpBack::instance = NULL;

getUpBack::getUpBack()
{

}

BehaviorBase* getUpBack::Behavior()
{
    if(! instance)
    {
        instance = new getUpBack();
    }
    return instance;
}

void getUpBack::action()
{
    std::cout << "Get Up Back!" << std::endl;
    commandStatic.body = MotionAux::GetUpBack();
    MotionAux::SendCommand(commandStatic);
    boost::this_thread::sleep(boost::posix_time::milliseconds(6500));
}

BehaviorBase* getUpBack::transition()
{
    return Start::Behavior();
}
