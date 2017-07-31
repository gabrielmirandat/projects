#include <includeMapBehavior.hpp>

sonarRight* sonarRight::instance = NULL;

sonarRight::sonarRight()
{

}

BehaviorBase* sonarRight::Behavior()
{
    if(! instance)
    {
        instance = new sonarRight();
    }
    return instance;
}

void sonarRight::action()
{
    //Do something
    std::cout << "Fuciona!" << std::endl;
}

BehaviorBase* sonarRight::transition()
{
    return this;
}
