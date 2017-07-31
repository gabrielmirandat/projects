#include "Post.h"

Post::Post()
: StaticInFieldEntity(), width_(-1.0), first_line_(-1.0,-1.0), second_line_(-1.0,-1.0)
{

	#ifdef OBJECT
        std::cout<<"Post object created." << std::endl;
    #endif
}

Post::~Post()
{
    #ifdef OBJECT
        std::cout<<"Post object destroyed." << std::endl;
    #endif
}

void Post::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{
   init();
   size_t idx;
   double x, y;
   cv::Mat img_debug;

   // #ifdef REMOTE
   //    image.copyTo(img_debug);
   // #endif

   // std::vector<cv::Vec2f> lines = this->lines_container_->getLines();

   this->first_line_ = this->second_line_ = cv::Vec2f(-1.0,-1.0);
   // image::convert(image, img_debug, CV_BGR2GRAY);
   image::canny(image, img_debug, 120, 240);
   lines::applyHough(img_debug, this->lines_, 2*IMG_HEIGHT/5);

   idx = lines::getFilteredLine(this->lines_, this->first_line_, 0,
                                IMG_DIAGONAL, -IMG_DIAGONAL,
                                0, 0,
                                15.0*CV_PI/180, 0.0*CV_PI/180,
                                165.0*CV_PI/180, 180.0*CV_PI/180);

   if (this->first_line_[0] != -1)
  		lines::getFilteredLine(this->lines_, this->second_line_, idx+1,
  					 	  	           this->first_line_[0] - 10, -IMG_DIAGONAL,
                             this->first_line_[0] + 10, IMG_DIAGONAL,
                             this->first_line_[1] , this->first_line_[1] - 3*CV_PI/180,
                             this->first_line_[1] , this->first_line_[1] + 3*CV_PI/180);
                             
   if(this->second_line_[0] != -1)
   {
   		this->is_detected_ = true;
   		this->width_ = std::abs(this->second_line_[0] - this->first_line_[0]);
   		x = (this->second_line_[0] + this->first_line_[0])/2.0;
   		y = IMG_HEIGHT/2;
   		this->position_ = cv::Point(x,y);

   		#ifdef REMOTE
        std::cout << "post: " << this->position_ << std::endl;
        image::convert(img_debug, img_debug, CV_GRAY2BGR);
        lines::show(img_debug, this->first_line_, cv::Scalar(255,0,0));
   			lines::show(img_debug, this->second_line_, cv::Scalar(0,255,0));
   			lines::drawCross(img_debug, cv::Point2f(x,y), cv::Scalar(0,0,255));
   		#endif
   }

   #ifdef REMOTE
       image::debug(img_debug,"Post");
   #endif

}

void Post::init()
{
  //parents
  this->is_detected_ = false; 
  this->position_ = cv::Point(-1,-1);
  this->distance_to_camera_ = -1;
  this->width_image_coord_ = -1;
  //lines_ not needed

  //own
   this->first_line_ = cv::Vec2f(-1,-1);
   this->second_line_ = cv::Vec2f(-1,-1);
   width_ = -1;
}
