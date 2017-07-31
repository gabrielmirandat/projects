#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>

#define THRESHOLD_THETA_ONLY 50
#define THRESHOLD_THETA_ALIGN 0.0873
#define THRESHOLD_BALL 50
#define NUMBER_LOST 50
#define CENTER_X_TOP 320
#define CENTER_X_BOT 170
#define OFFSET 100
#define MAX_TURN_ANGLE 0.4

turnLeft* turnLeft::instance = NULL;

turnLeft::turnLeft()
{
    flag = false;
}

BehaviorBase* turnLeft::Behavior()
{
    if(! instance)
    {
        instance = new turnLeft();
    }
    return instance;
}

void turnLeft::action()
{
 	visionData visionBall = VisionBoard.load();
    std::cout << "X BOLA: " << visionBall.ball_distance_x << "Y BOLA: " << visionBall.ball_distance_y << std::endl;
    std::cout << "Turn Left" << std::endl;

    ballX = visionBall.ball_distance_x;
    ballY = visionBall.ball_distance_y;



    if(visionBall.ball_distance_x == -1 || visionBall.ball_distance_x == 0)
    {
        std::cout << "ERRO" << std::endl;
        flag = true;
        commandStatic.leds = LEDAux::changeColor(0, 1, 0);
        commandStatic.body = MotionAux::Walk(0.0, 0.0, 0.4);

        ballX = lastBallX;
        ballY = lastBallY;

        if(visionBall.ball_distance_x == -1)
        {
            contadorBall++;
        }
    }
    else
    {
        commandStatic.leds = LEDAux::changeColor(0, 2, 0);
        lastBallX = visionBall.ball_distance_x;
        lastBallY = visionBall.ball_distance_y;
        contadorBall = 0;
        //float angulo = atan2(visionBall.ball_distance_y, visionBall.ball_distance_x);

        //std::cout << "Ang: " << angulo << std::endl;


        if(camera == 0)
        {
            center = CENTER_X_BOT;
        }
        if (camera == 1)
        {
            center = CENTER_X_TOP;
        }
        commandStatic.body = MotionAux::Walk(0.0, 0.0, 0.4);


       /* if(visionBall.ball_distance_y > THRESHOLD_THETA_ONLY)
        {
            commandStatic.body = MotionAux::Walk(0.0, 0.0, -angulo);
        }
        else
        {
            commandStatic.body = MotionAux::Walk(visionBall.ball_distance_x, 0.0, -angulo);
        }*/

    }

    MotionAux::SendCommand(commandStatic);

}

BehaviorBase* turnLeft::transition()
{
	SensorValues sensorValues = SensorBoard.load();
    if(sensorValues.sensors[0] != NAN)
    {
        BehaviorBase* returnBehavior= MotionAux::getUpIfFalling(sensorValues);
        if(returnBehavior != NULL)
        {
            return returnBehavior;
        }
    }

     if(contadorBall == NUMBER_LOST)
     {
         contadorBall = 0;
         //find ball
         return Start::Behavior();


     }

    if(center - ballX < -OFFSET)
        return turnRight::Behavior();

    else if((center - ballX) < OFFSET)
        return walk::Behavior();
    else if(flag)
    {
        return walk::Behavior();
    }
  	else
    {
            return this;
    }
}
