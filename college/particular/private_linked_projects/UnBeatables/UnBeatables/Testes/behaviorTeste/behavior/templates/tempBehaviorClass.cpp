#include <includeMapBehavior.hpp>

tempBehaviorClass* tempBehaviorClass::instance = NULL;

BehaviorBase* tempBehaviorClass::Behavior()
{
    if(! instance)
    {
        instance = new tempBehaviorClass();
    }
    return instance;
}

void tempBehaviorClass::action()
{
    //Do something
    std::cout << "Fuciona!" << std::endl;
}

BehaviorBase* tempBehaviorClass::transition()
{
    return this;
}
    