#ifndef _BEHAVIOR_H_
#define _BEHAVIOR_H_

#include <iostream>
#include <boost/shared_ptr.hpp>


class Behavior
{
public:
	Behavior();
	~Behavior();
	
    //Start the module's thread
    void StartLoop();

    //Stop the module's thread
    void StopLoop();

private:
    struct Impl;
    boost::shared_ptr<Impl> impl;
    bool isActive;
};

class BehaviorError : public std::exception
{
public:
    BehaviorError(const char* message);
    BehaviorError(const std::string message);
    virtual const char* what();

private:
    const char* msg;
};






 #endif //_BEHAVIOR_H_
