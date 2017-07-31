/*
* searchForBall inherited from BehaviorBase.
*/
#include <BehaviorBase.hpp>

class searchForBall : public BehaviorBase
{
private:
	//Ball ball;
	//int headCounter; 
    searchForBall();
    static searchForBall *instance;
    
public:
    static BehaviorBase* Behavior();
    BehaviorBase* transition();
    void action();
};
