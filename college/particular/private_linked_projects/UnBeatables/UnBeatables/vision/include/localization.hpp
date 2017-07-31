#ifndef _LOCALIZATION_HPP_
#define _LOCALIZATION_HPP_

#include <vector>
#include <stdio.h>

#include "namespace/common.h"
//#include "line.hpp"
class Localization
{	

	public:
		Localization();
		virtual ~Localization();

        float projection3d2d(int px, int py,float dist, float apparent_focus);
};



#endif //_LOCALIZATION_HPP_
