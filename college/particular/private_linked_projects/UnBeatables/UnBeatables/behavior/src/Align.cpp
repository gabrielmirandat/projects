//TO DO!!!!!!!
//Se alinhar com gol
//Checar lado correto

#include <includeMapBehavior.hpp>

Align* Align::instance = NULL;

Align::Align()
{
    
}

BehaviorBase* Align::Behavior()
{
    if(! instance)
    {
        instance = new Align();
    }
    return instance;
}

void Align::action()
{
    //Do something
    std::cout << "Fuciona!" << std::endl;
}

BehaviorBase* Align::transition()
{
    return Kick::Behavior();;
}
