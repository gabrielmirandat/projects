#ifndef _BALL_H_
#define _BALL_H_

#include "DynamicInFieldEntity.h"
#include "localization.hpp"

class Ball : public DynamicInFieldEntity
{
private:
   int middle_xaxis_side_;
   int flag_rect_;
   bool flag;
   int frames_lost;
   int roi_seed_x, roi_seed_y, roi_width, roi_height;

public:
	explicit Ball();
	virtual ~Ball();

    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
	void init();
	inline int getMiddleXAxisSide() const {return this->middle_xaxis_side_;};
    inline void setMiddleXAxisSide(int middle_xaxis_side){this->middle_xaxis_side_ = middle_xaxis_side;};
//	inline void setDistance(double distance){this->distance_to_camera_ = distance;};
};

#endif //_BALL_H_
