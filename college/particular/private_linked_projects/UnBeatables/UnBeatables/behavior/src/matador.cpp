#include <alcommon/albroker.h>
#include <alcommon/albrokermanager.h>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>

#include <unBoard.hpp>
#include <proxyData.hpp>

int main()
{
    unBoard<ProxyData> proxyBoard;
    ProxyData proxies;
    proxies = proxyBoard.load();
    try
    {
        std::cout << "killing motion..." << std::endl;
        proxies.Motion->callVoid("StopLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Could not kill proxy: " << e.what() << std::endl;
        return 1;
    }

    try
    {
        std::cout << "killing communication..." << std::endl;
        proxies.Communication->callVoid("StopLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Could not kill proxy: " << e.what() << std::endl;
        return 1;
    }

    try
    {
        std::cout << "killing vision..." << std::endl;
        proxies.Vision->callVoid("StopLoop");
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Could not kill proxy: " << e.what() << std::endl;
        return 1;
    }
	return 0;
}
