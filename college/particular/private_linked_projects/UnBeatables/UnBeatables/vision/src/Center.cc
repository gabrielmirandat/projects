#include "Center.h"

Center::Center()
: StaticInFieldEntity()
{

	#ifdef OBJECT
        std::cout<<"Center object created." << std::endl;
    #endif
}

Center::~Center()
{
    #ifdef OBJECT
        std::cout<<"Center object destroyed." << std::endl;
    #endif
}

void Center::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{
	  init();
    size_t idx;
   	double x, y;
   	cv::Mat img_debug;

    image.copyTo(img_debug);
    
    image::blur(image, img_debug, 3);
    image::canny(img_debug,img_debug,50,120); //80, 160
    lines::applyHough(img_debug,this->lines_, 80);

    // std::vector<cv::Vec2f> lines = this->lines_container_->getLines();
    
    size_t size = this->lines_.size();
    for(size_t i=0; i<size;i++)
    	lines::show(img_debug, this->lines_[i], cv::Scalar(0,0,0)); //it's not for remote
    
    contours::find(img_debug, this->contours_, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
    contours::filter(this->contours_,
					 /*min_inliers*//*36*/  36, 
					 /*min_area*/(IMG_HEIGHT/4)*(IMG_WIDTH/3),
					 /*max_area*/IMG_HEIGHT*IMG_WIDTH,
					 /*min_side_size*//*40*/60,
					 /*int min_ratio*//*0.23*/0.2857, 
					 /*int max_ratio*//*4.5*/3.5);

    size = this->contours_.size();
    if(size > 2)
    {
    	this->is_detected_ = true;

    	cv::Mat pointsf;
	    cv::Mat(this->contours_/*[size/2]*/[0]).convertTo(pointsf, CV_32F);
	    cv::RotatedRect box = fitEllipse(pointsf);
      this->position_ = cv::Point(box.center.x,box.center.y);
      width_image_coord_ = cv::max(box.size.width, box.size.height);

      //detectDistance(CENTER);

    	#ifdef REMOTE 
            std::cout << "center: " << this->position_;
            std::cout << " distance: " << this->distance_to_camera_/10 << "cm" << std::endl;
            image::convert(img_debug, img_debug, CV_GRAY2BGR);
	          cv::ellipse(img_debug, box , cv::Scalar(255,0,0), 2, CV_AA);
            lines::drawCross(img_debug, this->position_, cv::Scalar(0,0,255));
	    #endif
    }

   #ifdef REMOTE
       image::debug(img_debug,"Center");
   #endif

}

void Center::init()
{
  //parents
  this->is_detected_ = false; 
  this->position_ = cv::Point(-1,-1);
  this->distance_to_camera_ = -1;
  this->width_image_coord_ = -1;
  //lines_ not needed

  //own
  //contours_ not needed

}
