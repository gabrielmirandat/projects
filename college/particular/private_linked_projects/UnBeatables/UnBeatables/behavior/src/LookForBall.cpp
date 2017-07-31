#include <includeMapBehavior.hpp>
#include <motionAuxiliarFunctions.hpp>

#define HEAD_YAW_MAX 2.0857
#define HEAD_YAW_MIN -2.0857

LookForBall* LookForBall::instance = NULL;

LookForBall::LookForBall()
{
    bit = true;
    ball_lost = 0;
    wandering_ticks = 0;
}

BehaviorBase* LookForBall::Behavior()
{
    if(! instance)
    {
        instance = new LookForBall();
    }
    return instance;
}

void LookForBall::action()
{
    visionData visionBall = VisionBoard.load();
    std::cout << "LookForBall" << std::endl;

    ballX = visionBall.ball_distance_x;
    ballY = visionBall.ball_distance_y;

    std::cout << "SEM BOLA" << std::endl;

    if (bit == true) {
        commandStatic.head = MotionAux::MoveHead(0,(0.5*HEAD_YAW_MAX),0.5,0.5);
        bit == false;
    }else {
        commandStatic.head = MotionAux::MoveHead(0,(0.5*HEAD_YAW_MIN),0.5,0.5);
        bit == true;
    }
    MotionAux::SendCommand(commandStatic);
}

BehaviorBase* LookForBall::transition()
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
    visionData visionBall = VisionBoard.load();
    if(visionBall.ball_distance_x == -1 && ball_lost < 100) {
        ball_lost++;
        return this;
    }
    else
    {
        if (visionBall.ball_distance_x != -1)
            return walk::Behavior();
        //SHOULD BE ALLIGNING THE BODY! UNDER CONSTRUCTION
        if (ball_lost >= 100)
        {
            commandStatic.body = MotionAux::Walk(30,0,0);
            if (wandering_ticks++ >= 60)
            {
                MotionAux::Stand();
                wandering_ticks = 0;
                ball_lost = 0;
            }
            return this;
        }
    }
}
