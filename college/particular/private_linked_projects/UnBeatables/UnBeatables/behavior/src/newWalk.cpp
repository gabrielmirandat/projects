#include <includeMapBehavior.hpp>

newWalk* newWalk::instance = NULL;

newWalk::newWalk()
{
    contadorBall = 0;
}

BehaviorBase* newWalk::Behavior()
{
    if(! instance)
    {
        instance = new newWalk();
    }
    return instance;
}

void newWalk::action()
{

    //Do something

    qiLogInfo("Behavior") << "I'm walking!" << std::endl;
    commandStatic.body = MotionAux::Walk(300.0, 0.0, 0.0);
    MotionAux::SendCommand(commandStatic);
    std::cout << "Walking" << std::endl;

    contadorWalk++;

   commandStatic.body = MotionAux::Kick(160.0, 45.0, 0.0);
   MotionAux::SendCommand(commandStatic);


    kickIsFinished = kickFlagBoard.load();
    std::cout << "kick is:" << kickIsFinished.kickFinished << std::endl;

    if(kickIsFinished.kickFinished == 1)
    {
        commandStatic.body = MotionAux::Stand();
        MotionAux::SendCommand(commandStatic);
    }
    visionData visionBall = VisionBoard.load();
    std::cout << "X BOLA: " << visionBall.ball_distance_x << "Y BOLA: " << visionBall.ball_distance_y << std::endl;

    lastBallX = visionBall.ball_distance_x;


    if(visionBall.ball_distance_x == -1 || visionBall.ball_distance_x == 0)
    {
        //FLAG DE ERRO
        std::cout << "ERRO" << std::endl;
        if(visionBall.ball_distance_x == -1)
        {
            contadorBall++;
        }
    }
    else
    {
        contadorBall = 0;
    }

    float angulo = atan2(visionBall.ball_distance_y, visionBall.ball_distance_x);

    if(angulo > THRESHOLD_THETA_ONLY)
    {
        commandStatic.body = MotionAux::Walk(0.0, 0.0, angulo);
    }


    commandStatic.body = MotionAux::Walk(visionBall.ball_distance_x, 0.0, angulo);
    MotionAux::SendCommand(commandStatic);

}

BehaviorBase* newWalk::transition()
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

    if(contadorWalk < 5000)
    {
        return this;
    }
    else
    {
        contadorWalk = 0;
        return Kick::Behavior();
    }
}
