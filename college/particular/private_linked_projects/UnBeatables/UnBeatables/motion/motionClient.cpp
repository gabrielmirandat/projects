#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <boost/program_options.hpp>
#include <boost/shared_ptr.hpp>

#include <alcommon/albroker.h>
#include <alcommon/albrokermanager.h>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>
#include <alproxies/almemoryproxy.h>
#include <alvalue/alvalue.h>

void parseOpt(std::string *naoBrokerIP, int *naoBrokerPort, int argc, char* argv[])
{
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "Print help mesages.")
        ("pip", po::value<std::string>(naoBrokerIP)->default_value("NAOMAR.local"), "IP of the parent broker. Default: NAOMAR.local")
        ("pport", po::value<int>(naoBrokerPort)->default_value(9559),"Port of the parent broker. Default: 9559");
    po::positional_options_description positionalOptions;
    po::variables_map vm; // Map containing all the options with their values
    try
    {
        po::store(po::command_line_parser(argc, argv).options(desc).positional(positionalOptions).run(), vm);

        if (vm.count("help"))
        {
            std::cout << "Motion client module."                                   << std::endl;
            std::cout << "Can be executed locally or remotelly."                   << std::endl;
            std::cout                                                              << std::endl;
            std::cout << "Usage:"                                                  << std::endl;
            std::cout << "  " << argv[0] << " [options] [input] "                  << std::endl;
            std::cout                                                              << std::endl;
            std::cout << desc                                                      << std::endl;

            exit(0);
        }

        po::notify(vm);
    }
    catch(po::error &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << desc << std::endl;
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    std::string parentBrokerIP;
    int parentBrokerPort;
    
    setlocale(LC_NUMERIC, "C"); // Need this to for SOAP serialization of floats to work

    parseOpt(&parentBrokerIP, &parentBrokerPort, argc, argv);
    
    std::cout << "parse created..." << std::endl;

    // A broker needs a name, an IP and a port:
    const std::string brokerName = "mybroker";
    // FIXME: would be a good idea to look for a free port first
    int brokerPort = 0;
    // listen port of the broker (here an anything)
    const std::string brokerIp = "";


    // Create your own broker
    boost::shared_ptr<AL::ALBroker> broker;
    try
    {
        broker = AL::ALBroker::createBroker(
            brokerName,
            brokerIp,
            brokerPort,
            parentBrokerIP,
            parentBrokerPort,
            0    // you can pass various options for the broker creation,
                 // but default is fine
        );
    }
    catch(const AL::ALError& e)
    {
        std::cerr << "Fail to connect broker to: "
                  << parentBrokerIP
                  << ":"
                  << parentBrokerPort
                  << std::endl
                  << e.what()
                  << std::endl;

        AL::ALBrokerManager::getInstance()->killAllBroker();
        AL::ALBrokerManager::kill();

        return 1;
    }

    //Create the proxy to access the motion module
    boost::shared_ptr<AL::ALProxy> Motion;

    try
    {
        Motion = boost::shared_ptr<AL::ALProxy>(new AL::ALProxy(broker,"Motion"));
        std::cout << "proxy created..." << std::endl;
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Could not create proxy: " << e.what() << std::endl;
        return 1;
    }

    try
    {
        Motion->callVoid("StartLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << e.what() << std::endl;
    }

    float speed = 1.0f, neck = 0.0;
    int flag = 0;

    while(!flag)
    {
        Motion->callVoid("MoveNeck", 0.8f, (float)sin(neck), 0.0f);
        neck += 0.1f;

        Motion->callVoid("Move", 0.0f, speed, 0.0f);
        std::cout << neck << std::endl;
        if(neck >= 100.0f)
            speed = -1.0f;
        if(neck >= 200.0f)
            flag = 1;
    }

    sleep(5);

    Motion->callVoid("StopMove");

    sleep(2);
    try
    {
        Motion->callVoid("StopLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
