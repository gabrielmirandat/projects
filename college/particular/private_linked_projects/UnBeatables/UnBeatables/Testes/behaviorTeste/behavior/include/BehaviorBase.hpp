/*
* Base Class to All Behavior
* All Behavior Should Inherite From this class and override this methods!
*/
#include <includeMapBehavior.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <motionData.hpp>

class BehaviorBase
{
protected:
    boost::interprocess::managed_shared_memory managed_shm;
    motionData *dadosMotion;

    BehaviorBase():managed_shm(boost::interprocess::open_or_create, "unBoard", 1024)
    {
      dadosMotion = managed_shm.find_or_construct<motionData>(typeid(motionData).name())();
    }

public:
    static BehaviorBase* Behavior();
    virtual BehaviorBase* transition(){ return NULL;};
    virtual void action(){};
};
