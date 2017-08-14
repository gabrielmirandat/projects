#include "BallCascade.h"

BallCascade::BallCascade()
: is_running_(true)
{
    loadCascadeXml();
}

BallCascade::~BallCascade()
{
  
}

void BallCascade::loadCascadeXml()
{
   cout << "Loading Cascade.." << endl;
   if (!this->cascade_.load("code/content/ball_cascade.xml"))
   {
          string error_message = "No valid ball_cascade.xml given.";
          CV_Error(CV_StsBadArg, error_message);
   }
}

bool BallCascade::isRunning()
{
    char key = cv::waitKey(1);
    if(key==27) this->is_running_=false;
    return this->is_running_;
}

void BallCascade::run(cv::Mat& frame)
{
    cv::Mat frame_gray;
    cv::cvtColor(frame, frame_gray,CV_BGR2GRAY);
    this->objects_.clear();
    this->cascade_.detectMultiScale(frame_gray, 
                                    this->objects_,
                                    /*scaleFactor*/1.1, 
                                    /*minNeighbors*/ 2, 
                                    /*flags*/ 0|CV_HAAR_SCALE_IMAGE, 
                                    /*minSize*/ cv::Size(20, 20) );

    size_t size = this->objects_.size();
      
    for(size_t i=0; i < size; i++)
    {
        cv::Point pt1 = cvPoint(this->objects_[i].x, this->objects_[i].y);
        cv::Point pt2 = cvPoint(this->objects_[i].x + this->objects_[i].width,
                                this->objects_[i].y + this->objects_[i].height);

        cv::rectangle(frame, pt1, pt2, cv::Scalar(0,0,255), 1);
    }

    cv::imshow("tracking",frame);

    // char key = cv::waitKey(1);
    // if(key=='p')
    // {
    //       char key = cv::waitKey(0);
    //       if(key=='p') cv::imwrite("code/content/saved.jpg", frame);
    // }
}
