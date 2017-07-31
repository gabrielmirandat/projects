#include <includeMapBehavior.hpp>

ClasseMenor* ClasseMenor::instance = NULL;

BehaviorBase* ClasseMenor::Behavior()
{
    if(! instance)
    {
        instance = new ClasseMenor();
    }
    return instance;
}

void ClasseMenor::action()
{
    //Do something
    std::cout << "Classe Menor!" << dadosMotion->x_vel << std::endl;
}

BehaviorBase* ClasseMenor::transition()
{
  if(dadosMotion->x_vel > 10){
      return ClasseMaior::Behavior();
  }
  else {
    return this;
  }
}
