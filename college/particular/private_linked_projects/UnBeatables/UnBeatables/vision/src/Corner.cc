#include "Corner.h"

Corner::Corner()
: StaticInFieldEntity(), line1_(-1,-1), line2_(-1,-1), line_width_(-1)
{

	#ifdef OBJECT
        std::cout<<"Corner object created." << std::endl;
    #endif
}

Corner::~Corner()
{
    #ifdef OBJECT
        std::cout<<"Corner object destroyed." << std::endl;
    #endif
}

void Corner::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{
   init();
   size_t size;
   size_t idx=0;
   float m1,m2,n1,n2;
   float x = -1;
   float y = -1;
   cv::Mat img_debug;

   // #ifdef REMOTE
   //    image.copyTo(img_debug);
   // #endif

   // image::convert(image, img_debug, CV_BGR2GRAY);
   image::canny(image, img_debug, 320, 480);
   lines::applyHough(img_debug, this->lines_, IMG_HEIGHT/5);
   //image::debug(image,"Dentro!");

   // std::vector<cv::Vec2f> lines = this->lines_container_->getLines();
   size = this->lines_.size();
   if(size>1)
   {
      this->line1_ = this->lines_[0];

      idx = lines::getFilteredLine(this->lines_,
                                   this->line2_,
                                   1,
                                   0,
                                   0,
                                   -IMG_WIDTH,
                                   IMG_WIDTH,
                                   this->line1_[1]*180/CV_PI-10,
                                   this->line1_[1]*180/CV_PI-140,
                                   this->line1_[1]*180/CV_PI+10,
                                   this->line1_[1]*180/CV_PI+140);
   }
  
   if(idx!=-1)
   {
      n1 = this->line1_[0]/sin(this->line1_[1]);
      n2 = this->line2_[0]/sin(this->line2_[1]);

      m1 = -cos(this->line1_[1])/sin(this->line1_[1]);
      m2 = -cos(this->line2_[1])/sin(this->line2_[1]);

      x = (n2-n1)/(m1-m2);
      y = m1*x + n1;

      x = (x > 0 && x < IMG_WIDTH) ? x : -1;
      y = (y > 0 && x < IMG_HEIGHT) ? y : -1;

      if(x != -1 && y != -1)
      {
          this->is_detected_ = true;
          this->position_ = cv::Point(x,y);

          #ifdef REMOTE
            //std::cout << "Corner1: " << this->line1_;
            //std::cout << " Corner2: " << this->line2_ << std::endl;
            std::cout << "X: " << x;
            std::cout << "Y: " << y;
            image::convert(img_debug, img_debug, CV_GRAY2BGR);
            lines::show(img_debug,  this->line1_, cv::Scalar(255,0,0));
            lines::show(img_debug,  this->line2_, cv::Scalar(255,0,0));
            lines::drawCross(img_debug, cv::Point2f(x,y), cv::Scalar(0,0,255));
          #endif

          //this->detectDistance(CORNER);
      }
   }

   #ifdef REMOTE
       image::debug(img_debug,"Corner");
   #endif

}

void Corner::init()
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
  line_width_ = -1;

}
