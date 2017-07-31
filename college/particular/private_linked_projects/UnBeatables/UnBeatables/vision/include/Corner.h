#ifndef _CORNER_H_
#define _CORNER_H_

#include "StaticInFieldEntity.h"
#include "namespace/lines.h"
#include "namespace/image.h"
#include <math.h>

class Corner : public StaticInFieldEntity
{
private:
   cv::Vec2f line1_;
   cv::Vec2f line2_;
   float line_width_;

   void init();

public:
	explicit Corner();
	virtual ~Corner();

    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
	cv::Vec2f getLine1() const {return this->line1_;};
	void setLine1(cv::Vec2f line){this->line1_ = line;};
	cv::Vec2f getLine2() const {return this->line2_;};
	void setLine2(cv::Vec2f line){this->line2_ = line;};
	float getLineWidth() const {return this->line_width_;};
};

#endif //_CORNER_H_
