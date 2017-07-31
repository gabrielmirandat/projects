#include "Enemie.h"

Enemie::Enemie()
: DynamicInFieldEntity()
{

	cascade_.load("content/enemie_cascade.xml");

	#ifdef OBJECT
        std::cout<<"Enemie object created." << std::endl;
    #endif
}

Enemie::~Enemie()
{
    #ifdef OBJECT
        std::cout<<"Enemie object destroyed." << std::endl;
    #endif
}

void Enemie::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{
  
  cv::Mat image_roi;
  image.copyTo(image_roi);

  if(this->position_ != cv::Point2f(-1,-1))
  {
    int width = this->objects_[0].width;

    int posx = (this->objects_[0].x - 1.5*width) > 0 ? (this->objects_[0].x - 1.5*width) : 0;
    int posy = (this->objects_[0].y - 1.5*width) > 0 ? (this->objects_[0].y - 1.5*width) : 0;
    int wx = (this->objects_[0].x + 1.5*width) < common::IMG_WIDTH ? (3*width) : IMG_WIDTH - this->objects_[0].x;
    int wy = (this->objects_[0].y + 1.5*width) < common::IMG_HEIGHT ? (3*width) : IMG_HEIGHT - this->objects_[0].y;

    cv::Rect region_of_interest = cv::Rect(posx, 
                                           posy,
                                           wx, 
                                           wy);
    image_roi = image(region_of_interest);
    
  }

  init();
  cv::Mat img_debug;
  bool img_change = false;

  #ifdef REMOTE
     image::convert(image_roi, img_debug, CV_GRAY2BGR);
  #endif

  //this->objects é um rect!
  this->objects_.clear();
  this->cascade_.detectMultiScale(image_roi, 
                                  this->objects_,
                                  /*scaleFactor*/1.1, 
                                  /*minNeighbors*/ 3, 
                                  /*flags*/ 0|CV_HAAR_SCALE_IMAGE, 
                                  /*minSize*/ cv::Size(20, 20) );

    size_t size = this->objects_.size();
    
    if(size>0)
    {
        this->is_detected_ = true;
        this->position_ = cv::Point(this->objects_[0].x,this->objects_[0].y);
        this->width_image_coord_ =  this->objects_[0].width;
        
        //this->detectDistance(ENEMIE);

        #ifdef REMOTE
            cv::ellipse( img_debug, 
                         cv::Point2f(this->objects_[0].x + this->objects_[0].width*0.5,
                         this->objects_[0].y + this->objects_[0].height*0.5 ), 
                         cv::Size( this->objects_[0].width*0.5, this->objects_[0].height*0.5), 
                         0, 0, 360, 
                         cv::Scalar( 0, 255, 0), 1, 8, 0 
                        );
                 
             std::cout << "enemie: " << this->position_;  
             std::cout << " distance: " << this->distance_to_camera_/10 << "cm" << std::endl;                   
        #endif
    }

    #ifdef REMOTE
      image::debug(img_debug,"Enemie");
    #endif
}

void Enemie::init()
{
  //parents
  this->is_detected_ = false; 
  this->position_ = cv::Point(-1,-1);
  this->distance_to_camera_ = -1;
  this->width_image_coord_ = -1;

  //own

}


