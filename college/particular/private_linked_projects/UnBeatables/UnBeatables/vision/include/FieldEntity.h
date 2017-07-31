//! @file FieldEntity.h
//! @version 1.0
//! @date 02/20/2016 (mm/dd/yy)
//! @author Gabriel Martins de Miranda (UnBeatables Team)
//! @brief abstract class relative to the entities in field.
//! @code
//! @endcode

#ifndef _FIELDENTITY_H_
#define _FIELDENTITY_H_

#include "namespace/common.h"
#include "localization.hpp"


using namespace common;

//! @brief FieldEntity class.

class FieldEntity
{
protected:
   cv::Point2f position_;
   bool is_detected_;
   double distance_to_camera_;//DEPRECATED
   float dist_x, dist_y;
   double width_image_coord_;
   std::vector<cv::Point2f> dist_to_camera_view_;
   std::vector<float> apparent_focus_;
   Localization* lclz_;

public:
    explicit FieldEntity();
	virtual ~FieldEntity();
	
  virtual void detectPosition(cv::Mat& image, bool cam_flag=false,float angle=0) = 0;
  virtual void init(void) = 0;
  inline float getDistX() const {return this->dist_x;}
  inline float getDistY() const {return this->dist_y;}
  inline cv::Point2f getPosition() const {return this->position_;}
  inline cv::Point2f getDistance() const {return this->dist_to_camera_view_[0];}
  inline void setPosition(cv::Point2f& position){this->position_ = position;}
 // void detectDistance(int entity, bool cam_flag=false, float angle=0);
};

#endif //_FIELDENTITY_H_
