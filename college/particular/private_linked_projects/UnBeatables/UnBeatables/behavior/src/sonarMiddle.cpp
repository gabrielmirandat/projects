#include <includeMapBehavior.hpp>

sonarMiddle* sonarMiddle::instance = NULL;

sonarMiddle::sonarMiddle()
{

}

BehaviorBase* sonarMiddle::Behavior()
{
    if(! instance)
    {
        instance = new sonarMiddle();
    }
    return instance;
}

void sonarMiddle::action()
{
    //Do something
    std::cout << "Fuciona!" << std::endl;
}

BehaviorBase* sonarMiddle::transition()
{
    return this;
}
