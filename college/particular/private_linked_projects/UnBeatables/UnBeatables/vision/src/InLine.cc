#include "InLine.h"

InLine::InLine()
: StaticInFieldEntity(), line1_(-1,-1), line2_(-1,-1)
{

	#ifdef OBJECT
        std::cout<<"InLine object created." << std::endl;
    #endif
}

InLine::~InLine()
{
    #ifdef OBJECT
        std::cout<<"InLine object destroyed." << std::endl;
    #endif
}

void InLine::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{
   init();
   size_t idx_sec_line, size;
   cv::Mat img_debug;
   idx_sec_line = -1; 

   // #ifdef REMOTE
   //    image.copyTo(img_debug);
   // #endif

   // image::convert(image, image, CV_BGR2GRAY);
   image::canny(image, img_debug, 320, 480);
   lines::applyHough(img_debug, this->lines_, 2*IMG_HEIGHT/5);

   // std::vector<cv::Vec2f> lines = this->lines_container_->getLines();
   size = this->lines_.size();
   if(size>1)
   {
      this->line1_ = this->lines_[0];
      idx_sec_line = lines::getFilteredLine(this->lines_,
                      this->line2_,
                      0,
                      this->line1_[0] - 1.0,
                      this->line1_[0] - 30.0,
                      this->line1_[0] + 1.0,
                      this->line1_[0] + 30.0,
                      this->line1_[1]*180/CV_PI,
                      this->line1_[1]*180/CV_PI-1,
                      this->line1_[1]*180/CV_PI,
                      this->line1_[1]*180/CV_PI+1);
   }


   if(idx_sec_line!=-1)
   {
   		this->is_detected_ = true;
   		//position is not interesting
      this->width_image_coord_ = abs(this->line1_[0] - this->line2_[0]);

      //this->detectDistance(INLINE);
   		
      #ifdef REMOTE
        std::cout << "Inline1_: " << this->line1_;
        std::cout << " InLine2: " << this->line2_ << std::endl;
        std::cout << " distance: " << this->distance_to_camera_/10 << "cm\n" << std::endl;                   
        image::convert(img_debug, img_debug, CV_GRAY2BGR);
      	lines::show(img_debug,  this->line1_, cv::Scalar(255,0,0));
        lines::show(img_debug,  this->line2_, cv::Scalar(255,0,0));
      #endif
   }

   #ifdef REMOTE
       image::debug(img_debug,"InLine");
   #endif

}

void InLine::init()
{
  //parents
  this->is_detected_ = false; 
  this->position_ = cv::Point(-1,-1);
  this->distance_to_camera_ = -1;
  this->width_image_coord_ = -1;
  //lines_ not needed

  //own
  this->line1_ = cv::Vec2f(-1,-1);
  this->line2_ = cv::Vec2f(-1,-1);

}
