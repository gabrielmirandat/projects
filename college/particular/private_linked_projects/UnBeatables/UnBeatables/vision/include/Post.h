#ifndef _POST_H_
#define _POST_H_

#include "StaticInFieldEntity.h"
#include "namespace/lines.h"
#include "namespace/image.h"

class Post : public StaticInFieldEntity
{
private:
   double width_;
   cv::Vec2f first_line_;
   cv::Vec2f second_line_;

   void init();
public:
	explicit Post();
	virtual ~Post();

    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
	inline double getWidth() const {return this->width_;};
	inline cv::Vec2f getFirstLine() const {return this->first_line_;};
	inline cv::Vec2f getSecondLine() const {return this->second_line_;};
	inline void setWidth(double width){this->width_ = width;};
	inline void setFirstLine(cv::Point2f& first_line){this->first_line_ = first_line;};
	inline void setSecondLine(cv::Point2f& second_line){this->second_line_ = second_line;};
};

#endif //_POST_H_
