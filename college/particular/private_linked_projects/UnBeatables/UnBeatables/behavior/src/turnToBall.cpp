#include <includeMapBehavior.hpp>

turnToBall* turnToBall::instance = NULL;

turnToBall::turnToBall()
{

}

BehaviorBase* turnToBall::Behavior()
{
    if(! instance)
    {
        instance = new turnToBall();
    }
    return instance;
}

void turnToBall::action()
{
   /* motion.TurnHead(-current);
    motion.turn(current);*/
}

BehaviorBase* turnToBall::transition()
{
    //	return walkToBall::Behavior();
}
