#pragma once


#include <alproxies/almemoryproxy.h>
#include <alproxies/alsonarproxy.h>
#include <string>

namespace SonarData
{
	enum{
		NONE = 0,
		LEFT,
		MIDDLE,
		RIGHT
	};
}

class SonarClass
{

private: 
	AL::ALMemoryProxy *memory;
    AL::ALSonarProxy *sonar;
public:
	SonarClass(std::string naoIP);
	~SonarClass();
	int getSonar();

};