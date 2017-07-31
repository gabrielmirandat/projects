#include <includeMapBehavior.hpp>

BehaviorChildOne* BehaviorChildOne::singleOne = NULL;

void BehaviorChildOne::action()
{
    //Do something
    std::cout << "Fuciona BehaviorChildOne! " << dadosMotion->x_vel << std::endl;
}

BehaviorBase* BehaviorChildOne::Behavior()
{
    if(! singleOne)
    {
        singleOne = new BehaviorChildOne();
    }
    return singleOne;
}

BehaviorBase* BehaviorChildOne::transition()
{
    return BehaviorChildTwo::Behavior();
}
