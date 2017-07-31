#include <includeMapBehavior.hpp>

ClasseMaior* ClasseMaior::instance = NULL;

BehaviorBase* ClasseMaior::Behavior()
{
    if(! instance)
    {
        instance = new ClasseMaior();
    }
    return instance;
}

void ClasseMaior::action()
{
    //Do something
    std::cout << "Classe Maior!" << dadosMotion->x_vel << std::endl;
}

BehaviorBase* ClasseMaior::transition()
{
    if(dadosMotion->x_vel > 10){
        return this;
    }
    else {
      return ClasseMenor::Behavior();
    }
}
