#include <includeMapBehavior.hpp>

searchForBall* searchForBall::instance = NULL;

searchForBall::searchForBall()
{
     // Ball ball; //ball is ball.x, ball.y ball.isBall
	 //int headCounter=0;
}

BehaviorBase* searchForBall::Behavior()
{
    if(! instance)
    {
        instance = new searchForBall();
    }
    return instance;
}

void searchForBall::action()
{
    /*
    ball = findBall();
    headCounter = headCounter%5;

    if (ball.isBall == 0 && headCounter<2)
    {
		motion.TurnHead(current+0.78) //turn 45deg
		headCounter++;
    }
    if(ball.isBall == 0 && headCounter == 2 )
    {	
    	motion.TurnHead(0) // look forward
    	headCounter++
    }
	if (ball.isBall == 0 && headCounter>2)
	{
		motion.TurnHead(current-0.78) //turn 45deg
		headCounter++;
	}
	if (ball.isBall == 0 && headCounter == 5)
	{
		motion.turn(3.14) //turn body 180 deg
	}
	
	*/


}

BehaviorBase* searchForBall::transition()
{
   /* if (ball.isBall == 0)
    	return this;
    else 
    	return turnToBall::Behavior();
    */
}
