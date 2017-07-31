#ifndef _DYNAMICINFIELDENTITY_H_
#define _DYNAMICINFIELDENTITY_H_

#include "FieldEntity.h"
#include "namespace/image.h"

class DynamicInFieldEntity : public FieldEntity
{
protected:
   // cv::Mat pose_;
   // float velocity_;
   cv::CascadeClassifier cascade_;
   std::vector<cv::Rect> objects_;
public:
	explicit DynamicInFieldEntity();
	virtual ~DynamicInFieldEntity();
	
    void detectPose();
    void detectVelocity();
    // inline cv::Mat getPose() const {return this->pose_;}
    // inline float getVelocity() const {return this->velocity_;}
    // inline void setPose(cv::Mat pose){this->pose_ = pose;}
    // inline void setVelocity(float velocity){this->velocity_ = velocity;}
};

#endif //_DYNAMICINFIELDENTITY_H_
