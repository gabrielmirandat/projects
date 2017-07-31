#ifndef _CENTER_H_
#define _CENTER_H_

#include "StaticInFieldEntity.h"
#include "namespace/image.h"
#include "namespace/lines.h"
#include "namespace/contours.h"

class Center : public StaticInFieldEntity
{
private:
	std::vector<std::vector<cv::Point> > contours_; 
	void init();
public:
	explicit Center();
	virtual ~Center();

    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
};

#endif //_CENTER_H_
