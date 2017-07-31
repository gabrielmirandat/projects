#include <iostream>
#include <behavior.hpp>

struct Behavior::Impl
{
    Behavior &module;

    Impl(Behavior &mod) :  module(mod)
    {

    }

    ~Impl()
    {
    
    }
};


Behavior::Behavior()
{
}

Behavior::~Behavior()
{
    //Continue
}

void Behavior::StartLoop()
{
    if(!isActive)
    {
        try
        {
            impl = boost::shared_ptr<Impl>(new Impl(*this));
        }
        catch (std::exception& e)
        {
            std::cerr << "Failed to start the thread." << e.what() << std::endl;
            throw BehaviorError("Failed to start the thread.");
        }
        isActive = true;
    }
    else
    {
        throw BehaviorError("Module is already active.");
    }
}

void Behavior::StopLoop()
{
    if(isActive)
    {
        try
        {
            impl.reset();
        }
        catch (std::exception& e)
        {
            std::cerr << "Failed to stop the thread." << e.what() << std::endl;
            throw BehaviorError("Failed to stop the thread.");
        }
        isActive = false;
    }
    else
    {
        throw BehaviorError("Module is already inactive.");
    }
}


//Exception Class

BehaviorError::BehaviorError(const char* message)
  : msg(message) {}

BehaviorError::BehaviorError(const std::string message)
  : msg(message.c_str()) {}

const char* BehaviorError::what() { return msg; }




