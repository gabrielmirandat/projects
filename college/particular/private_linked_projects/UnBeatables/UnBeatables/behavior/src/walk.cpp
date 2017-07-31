#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>
#include <cmath>

#define THRESHOLD_THETA_ONLY 50
#define THRESHOLD_THETA_ALIGN 0.0873
#define THRESHOLD_BALL 225
#define THRESHOLD_HEAD 120
#define NUMBER_LOST 300
#define CENTER_X_TOP 320
#define CENTER_X_BOT 170
#define OFFSET 110
#define MAX_TURN_ANGLE 0.4


walk* walk::instance = NULL;

walk::walk()
{
    contadorBall = 0;
    lastBallX = -1;
    lastBallY = -1;
    camera = 0;
    center = 0;
}

//Class Methods
BehaviorBase* walk::Behavior()
{
    
    if(! instance)
    {
        instance = new walk();
    }
    return instance;
}

void walk::action()
{
    //Do something

    //qiLogInfo("Behavior") << "I'm walking!" << std::endl;
    //commandStatic.body = MotionAux::Walk(300.0, 0.0, 0.0);
    //MotionAux::SendCommand(commandStatic);
    //std::cout << "Walking" << std::endl;

    //contadorWalk++;

   /* commandStatic.body = MotionAux::Kick(160.0, 45.0, 0.0);
    MotionAux::SendCommand(commandStatic);*/

    
    /*kickIsFinished = kickFlagBoard.load();
    std::cout << "kick is:" << kickIsFinished.kickFinished << std::endl; 

    if(kickIsFinished.kickFinished == 1)
    {
        commandStatic.body = MotionAux::Stand();
        MotionAux::SendCommand(commandStatic);   
    }*/
    visionData visionBall = VisionBoard.load();
    std::cout << "X BOLA: " << visionBall.ball_distance_x << "Y BOLA: " << visionBall.ball_distance_y << std::endl;
    std::cout << "WALK " << std::endl;
    ballX = visionBall.ball_distance_x;
    ballY = visionBall.ball_distance_y;
    camera = visionBall.cam_flag;

    if(ballX == -1 || ballX == 0)
    {
        std::cout << "Ball not found" << std::endl;
        //FLAG DE ERRO

        commandStatic.leds = LEDAux::changeColor(0, 1, 0);


        ballX = lastBallX;
        ballY = lastBallY;


        float angulo = (center - ballX)*MAX_TURN_ANGLE/OFFSET;
        commandStatic.body = MotionAux::Walk(300, 0.0, angulo);
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
         std::cout << "Ball found" << std::endl;

        if(camera == 0)
        {
            center = CENTER_X_BOT;
        }
        if (camera == 1)
        {
            center = CENTER_X_TOP;
        }
        float angulo = (center - ballX)*MAX_TURN_ANGLE/OFFSET;
        commandStatic.body = MotionAux::Walk(300, 0.0, angulo);



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


BehaviorBase* walk::transition()
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
         return Start::Behavior();

     }

    if((center - ballX) < -OFFSET)
        return turnRight::Behavior();
    else if(center - ballX > OFFSET)
        return turnLeft::Behavior();
    else if(ballY > THRESHOLD_BALL && camera)
    { 
        //contadorWalk = 0;
        return Kick::Behavior();
    }
    else
    {
            return this;
    }
}
