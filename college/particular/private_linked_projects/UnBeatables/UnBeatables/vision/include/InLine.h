#ifndef _INLINE_H
#define _INLINE_H

#include "StaticInFieldEntity.h"
#include "namespace/lines.h"
#include "namespace/image.h"
#include <math.h>

class InLine : public StaticInFieldEntity
{
private:
   cv::Vec2f line1_;
   cv::Vec2f line2_;

   void init();

public:
	explicit InLine();
	virtual ~InLine();

    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
	inline cv::Vec2f getLine1() const {return this->line1_;};
	inline void setLine1(cv::Vec2f line){this->line1_ = line;};
	inline cv::Vec2f getLine2() const {return this->line2_;};
	inline void setLine2(cv::Vec2f line){this->line2_ = line;};
};

#endif //_INLINE_H
