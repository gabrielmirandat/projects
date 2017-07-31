#include "FieldEntity.h"

FieldEntity::FieldEntity()
: position_(-1,-1), is_detected_(false), distance_to_camera_(-1), width_image_coord_(-1)
{

    lclz_ = new Localization();
}

FieldEntity::~FieldEntity()
{
	
}

/*void FieldEntity::detectDistance(int entity,bool cam_flag, float angle)
{
    float x,y;
    std::cout << "angle: " << angle << std::endl;
    size_t i;
    if ((angle <=0.5 && angle >= -0.5)&&(!cam_flag))
        i = 0;
    else if ((angle == 0.0)&&(cam_flag))
        i = 1;
    else if ((angle <= 0.40 && angle >= 0.30)&&(!cam_flag))
        i = 2;
    else if ((angle <= 0.40 && angle >= 0.30)&&(cam_flag))
         i = 3;
    else
    {
        this->dist_x = -2;
        return;
    }

    x = (WIDTH_WORLD_COORD[entity] * this->apparent_focus_[i])/this->width_image_coord_;
    y = lclz_->projection3d2d(int (this->position_.x), int (this->position_.y), x, this->apparent_focus_[i]);

    if (!cam_flag) {
        x = 2*x;
        y = 2*y;
    }

    this->dist_x = x;
    this->dist_y = y;
 }*/


