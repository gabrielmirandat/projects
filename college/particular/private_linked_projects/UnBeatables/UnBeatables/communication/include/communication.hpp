#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <Settings.hpp>

namespace AL {
    class ALBroker;
}

/**
 * This class inherits AL::ALModule to bind methods and be run as a plugin within NAOqi.
 */

class Communication : public AL::ALModule
{
public:
	Communication(boost::shared_ptr<AL::ALBroker> pBroker, const std::string& pName);
	~Communication();
	/**
    * Overrides ALModule::init() and ALModule::exit(). exit() is called before unloading.
    * init() is called right after the module has been loaded.
    */
    void init(), exit();

    //Start the module's thread
    void StartLoop();

    //Stop the module's thread
    void StopLoop();

private:
    struct Impl;
    boost::shared_ptr<Impl> impl;
    bool isActive;
};

class CommunicationError: public std::exception
{
public:
    CommunicationError(const char* message);
    CommunicationError(const std::string message);
    virtual const char* what();

private:
    const char* msg;
};






 #endif //_COMMUNICATION_H_
