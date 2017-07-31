#ifndef _ENEMIE_H_
#define _ENEMIE_H_

#include "DynamicInFieldEntity.h"

class Enemie : public DynamicInFieldEntity
{
private:
public:
	explicit Enemie();
	virtual ~Enemie();

	void init();
    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
};

#endif //_ENEMIE_H_
