#ifndef _GOAL_H_
#define _GOAL_H_

#include "StaticInFieldEntity.h"
#include "namespace/image.h"
#include "namespace/lines.h"

#define  MIN_GOAL_SIZE 100

class Goal : public StaticInFieldEntity
{
private:
   cv::Vec2f post_left_;
   cv::Vec2f post_right_;
   cv::Vec2f second_left_;
   cv::Vec2f second_right_;
   double width_;
   void init();
public:
	explicit Goal();
	virtual ~Goal();

    void detectPosition(cv::Mat& image,bool cam_flag=false,float angle=0);
    inline cv::Vec2f getPostLeft() const {return this->post_left_;};
    inline cv::Vec2f getPostRight() const {return this->post_right_;};
    inline cv::Vec2f getSecondLineLeft() const {return this->second_left_;};
	inline cv::Vec2f getSecondLineRight() const {return this->second_right_;};
};

#endif //_GOAL_H_
