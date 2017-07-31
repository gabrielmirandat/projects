#include <includeMapBehavior.hpp>

seekBall* seekBall::instance = NULL;

seekBall::seekBall()
{

}

BehaviorBase* seekBall::Behavior()
{
    if(! instance)
    {
        instance = new seekBall();
    }
    return instance;
}

void seekBall::action()
{
    //Do something
    std::cout << "Fuciona!" << std::endl;
}

BehaviorBase* seekBall::transition()
{
    return this;
}
