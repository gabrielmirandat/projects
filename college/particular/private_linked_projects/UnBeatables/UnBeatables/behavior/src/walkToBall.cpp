#include <includeMapBehavior.hpp>

walkToBall* walkToBall::instance = NULL;

walkToBall::walkToBall()
{
    // ball = findBall();
}

BehaviorBase* walkToBall::Behavior()
{
    if(! instance)
    {
        instance = new walkToBall();
    }
    return instance;
}

void walkToBall::action()
{
 	//motion.Walk(ball.x, ball.theta);

}

BehaviorBase* walkToBall::transition()
{
	/*if (!ball.isBall)
		return searchForBall::Behavior();
    else if(ball.x > threshold)
    	return this;
    else
    	return Align::Behavior();*/
}
