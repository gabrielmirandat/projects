#include <Sonar.hpp>


#define THRESHOLD_CLOSE 0.34


SonarClass::SonarClass(std::string naoIP)
{
	memory = new AL::ALMemoryProxy(naoIP);
    sonar = new AL::ALSonarProxy(naoIP);
}

SonarClass::~SonarClass()
{
	  sonar->unsubscribe("myApplication");
}

int SonarClass::getSonar()
{
	AL::ALValue ALleft, ALright;
    float left, right;

	ALleft = memory->getData("Device/SubDeviceList/US/Left/Sensor/Value");
    ALright = memory->getData("Device/SubDeviceList/US/Right/Sensor/Value");

    left = (float)ALleft;
    right = (float)ALright;

    
    if(right < THRESHOLD_CLOSE && left < THRESHOLD_CLOSE)
    {
    	std::cout << "Perto a centro" << std::endl;
    	return SonarData::MIDDLE;
    }
    else if(left < THRESHOLD_CLOSE)
    {
    	std::cout << "Perto a esquerda" << std::endl;
    	return SonarData::LEFT;
    }
    else if(right < THRESHOLD_CLOSE)
    {
    	std::cout << "Perto a direita" << std::endl;
    	return SonarData::RIGHT;
    }
    return SonarData::NONE;
}