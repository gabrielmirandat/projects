#include "Goal.h"

Goal::Goal()
: StaticInFieldEntity(), width_(-1.0), post_left_(-1.0,-1.0), post_right_(-1.0,-1.0), second_left_(-1.0,-1.0), second_right_(-1.0,-1.0)
{

  #ifdef OBJECT
        std::cout<<"Goal object created." << std::endl;
    #endif
}

Goal::~Goal()
{
    #ifdef OBJECT
        std::cout<<"Goal object destroyed." << std::endl;
    #endif
}

void Goal::detectPosition(cv::Mat& image, bool cam_flag, float angle)
{

    init();
    size_t idx=0;
    double x, y;
    cv::Mat img_debug, image_roi;

    image.copyTo(image_roi);

    cv::Rect region_of_interest = cv::Rect(0,
                                         IMG_HEIGHT/3 - 20,
                                         IMG_WIDTH,
                                         IMG_HEIGHT/3 + 40);
    image_roi = image(region_of_interest);

    // get lines from image
    image::canny(image_roi, img_debug, 240, 480);
    lines::applyHough(img_debug, this->lines_, IMG_HEIGHT/7);
    // remove non-vertical lines
    lines::removeInRangeAngles(this->lines_, 20*CV_PI/180, 160*CV_PI/180);
    lines::normalizeAngles(this->lines_);
    // group lines by rho
    lines::truncateLines(this->lines_);


    for (std::vector<cv::Vec2f>::iterator it1 = this->lines_.begin(), it2 = it1 + 1;
         it1 != this->lines_.end();
         it2++)
    {
        if (it2 == this->lines_.end())
            it2 = ++it1;
        else
        {
            if (abs(it1[0][0] - it2[0][0]) > MIN_GOAL_SIZE)
            {
                this->post_left_= it1[0][0] < it2[0][0] ? it1[0] : it2[0];
                this->post_right_ = it1[0][0] > it2[0][0] ? it1[0] : it2[0];
                is_detected_ = true;
                this->position_ = cv::Point(((((this->post_left_[0] + this->post_right_[0])/2) -
                        IMG_WIDTH/2)/IMG_WIDTH/2)
                        , 0);
            }
        }
    }

    #ifdef REMOTE
    image::convert(img_debug, img_debug, CV_GRAY2BGR);
    if (this->is_detected_)
        lines::drawCross(img_debug,this->position_,cv::Scalar(0,0,255));
    cv::rectangle(image,region_of_interest,cv::Scalar(0,0,255));
    image::debug(img_debug,"Goal");
    image::debug(image, "roi");
    #endif
}

void Goal::init()
{
    //parents
    this->is_detected_ = false;
    this->position_ = cv::Point(-1,-1);
    this->distance_to_camera_ = -1;
    this->width_image_coord_ = -1;
    //lines_ not needed

    //own
    this->post_left_ = cv::Vec2f(-1,-1);
    this->post_right_ = cv::Vec2f(-1,-1);
    this->second_left_ = cv::Vec2f(-1,-1);
    this->second_right_ = cv::Vec2f(-1,-1);
    width_ = -1;

}
