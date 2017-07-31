#include "Ball.h"

Ball::Ball()
    : DynamicInFieldEntity(), middle_xaxis_side_(-1), frames_lost(7), flag(false),
    roi_seed_x(0), roi_seed_y(0), roi_width(50), roi_height(50), flag_rect_(0)
{
    try 
    {
        #ifdef REMOTE
            if (!this->cascade_.load("content/ball_cascade.xml"))
                throw 1;
        #else
            if(!this->cascade_.load("/home/nao/naoqi/content/ball_cascade.xml"))
                throw 1;
        #endif
        for(size_t i=0; i<4; i++)
        {
            this->apparent_focus_.push_back((DEFAULT_OBJ_CAMERA_PX[BALL][i] * DEFAULT_OBJ_CAMERA_MM[BALL][i])/WIDTH_WORLD_COORD[BALL]);
        }

    }
    catch (int e) {
        std::cout << "BALL_CASCADE.XML NOT FOUND! ERROR " << e << std::endl;
    }

    #ifdef OBJECT
        std::cout<<"Ball object created." << std::endl;
    #endif
}

Ball::~Ball()
{
    delete lclz_;

    #ifdef OBJECT
        std::cout<<"Ball object destroyed." << std::endl;
    #endif
}

void Ball::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{
    cv::Mat image_roi;
    image.copyTo(image_roi);
    int img_width, img_height;

    if (!cam_flag) {
        img_width = IMG_WIDTH*2;
        img_height = IMG_HEIGHT*2;
    }
    else
    {
        img_width = IMG_WIDTH;
        img_height = IMG_HEIGHT;
    }

    if(this->frames_lost < 6 && flag && !cam_flag)
    {
        int width = this->objects_[0].width;
        this->roi_seed_x = (this->roi_seed_x - width*this->frames_lost/10 ) > 0 ? (this->roi_seed_x - width*this->frames_lost/10) : 0;
        this->roi_seed_y = (this->roi_seed_y - width*this->frames_lost/10 ) > 0 ? (this->roi_seed_y - width*this->frames_lost/10) : 0;
        this->roi_width = (this->roi_width + width*this->frames_lost/5 + this->roi_seed_x) < img_width ? this->roi_width + width*this->frames_lost/5 : img_width - this->roi_seed_x -1;
        this->roi_height = (this->roi_height + width*this->frames_lost/5 +this->roi_seed_y) < img_height ? this->roi_height + width*this->frames_lost/5 : img_height - this->roi_seed_y -1;
    }else if (!cam_flag)
    {
        int tolerance = 60;
        roi_seed_y = img_height/3;
        roi_width = (img_width + tolerance)/3;
        roi_height = 2*img_height/3;
        if(this->flag_rect_ == 0)
        {
          roi_seed_x = 0;
        }else if(this->flag_rect_ == 1)
        {
          roi_seed_x = (img_width + tolerance)/3 - tolerance/2;
        }else if(this->flag_rect_ == 2)
        {
          roi_seed_x = 2*(img_width + tolerance)/3 - tolerance;
        }
        if(++this->flag_rect_==3) this->flag_rect_=0;
    }
    if (!cam_flag)
    {
    std::cout << "A 4 " << roi_seed_x<<" "<< roi_seed_y <<" "<< roi_width <<" "<< roi_height << std::endl;
    cv::Rect region_of_interest = cv::Rect(roi_seed_x,
                                           roi_seed_y,
                                           roi_width,
                                           roi_height);
    image_roi = image(region_of_interest);
    }
    else {
        this->roi_seed_x = 0;
        this->roi_seed_y = 0;
        image.copyTo(image_roi);
    }
    init();
    cv::Mat img_debug;

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
        std::cout << "BOLA BOLA BOLA BOLA" << std::endl;
        flag = true;
        this->frames_lost = 0;
        this->is_detected_ = true;
        this->position_ = cv::Point(this->objects_[0].x+roi_seed_x,this->objects_[0].y+roi_seed_y);
        this->width_image_coord_ =  this->objects_[0].width;
        middle_xaxis_side_ = this->objects_[0].x - img_width/2;

        this->roi_seed_x = (this->getPosition().x - 1.5*this->width_image_coord_) > 0 ? (this->getPosition().x - 1.5*this->width_image_coord_) : 0;
        this->roi_seed_y = (this->getPosition().y - 1.5*this->width_image_coord_) > 0 ? (this->getPosition().y - 1.5*this->width_image_coord_) : 0;
        this->roi_width = (this->objects_[0].x + 1.5*this->width_image_coord_) < img_width ? (3*this->width_image_coord_) : img_width - this->objects_[0].x;
        this->roi_height = (this->objects_[0].y + 1.5*this->width_image_coord_) < img_height ? (3*this->width_image_coord_) : img_height - this->objects_[0].y;

        //this->detectDistance(BALL,cam_flag,angle);
        /*#ifdef REMOTE
            cv::ellipse( img_debug,
                         cv::Point2f(this->objects_[0].x + this->objects_[0].width*0.5,
                         this->objects_[0].y + this->objects_[0].height*0.5 ), 
                         cv::Size( this->objects_[0].width*0.5, this->objects_[0].height*0.5), 
                         0, 0, 360, 
                         cv::Scalar( 0, 255, 0), 1, 8, 0 
                        );
                 
             std::cout << "ball: " << this->position_;
             for (size_t i = 0; i < VIEWS_SIZE; i++)
                std::cout << " distance: " << this->dist_to_camera_view_[i] << std::endl;
        #endif*/
    }
    else {
        std::cout << "B 2" << std::endl;
        this->frames_lost++;
    }

    #ifdef REMOTE
      cv::rectangle(image,region_of_interest,cv::Scalar(0,0,255));
      image::debug(img_debug,"Ball");
      image::debug(image, "roi");
      //cv::imwrite("/home/nao/ball_img.jpg",img_debug);
    #endif
}

void Ball::init()
{
  //parents
  this->is_detected_ = false;
  this->position_ = cv::Point(-1,-1);
  this->distance_to_camera_ = -1;
  this->width_image_coord_ = -1;
  //own
  middle_xaxis_side_ = -1000;

}
