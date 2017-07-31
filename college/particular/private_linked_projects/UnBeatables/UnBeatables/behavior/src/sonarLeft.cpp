#include <includeMapBehavior.hpp>

sonarLeft* sonarLeft::instance = NULL;

sonarLeft::sonarLeft()
{

}

BehaviorBase* sonarLeft::Behavior()
{
    if(! instance)
    {
        instance = new sonarLeft();
    }
    return instance;
}

void sonarLeft::action()
{
    //Do something
    std::cout << "Fuciona!" << std::endl;
}

BehaviorBase* sonarLeft::transition()
{
    return this;
}
