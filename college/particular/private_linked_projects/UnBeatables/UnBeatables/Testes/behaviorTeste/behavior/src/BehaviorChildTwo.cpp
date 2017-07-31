#include <includeMapBehavior.hpp>

BehaviorChildTwo* BehaviorChildTwo::singleOne = NULL;

void BehaviorChildTwo::action()
{
    //Do something
    std::cout << "Fuciona BehaviorChildTwo!" << std::endl;
}

BehaviorBase* BehaviorChildTwo::Behavior()
{
    if(! singleOne)
    {
        singleOne = new BehaviorChildTwo();
    }
    return singleOne;
}

BehaviorBase* BehaviorChildTwo::transition()
{
    return BehaviorChildOne::Behavior();
}
