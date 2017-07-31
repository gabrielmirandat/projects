#include "../include/infield.hpp"

// class statics must be defined outside the class;
// initialization is to 0 by default
size_t InField::numInfield;


InField::InField(const unsigned int& hmin, const unsigned int& smin, const unsigned int& vmin,
      const unsigned int& hmax, const unsigned int& smax, const unsigned int& vmax)
      : infield_lines_(NULL), infieldp_lines_(NULL), instanceFlag(false), single(NULL)
{
    boost::get<0>(this->min_hsv_) = hmin;
    boost::get<1>(this->min_hsv_) = smin;
    boost::get<2>(this->min_hsv_) = vmin;
    boost::get<0>(this->max_hsv_) = hmax;
    boost::get<1>(this->max_hsv_) = smax;
    boost::get<2>(this->max_hsv_) = vmax;

    #ifdef REMOTE
        std::cout<<"InField object created." << std::endl;
    #endif
}

InField* InField::getInstance(const unsigned int& hmin, const unsigned int& smin, const unsigned int& vmin,
                              const unsigned int& hmax, const unsigned int& smax, const unsigned int& vmax)
{
    if(!instanceFlag)
    {
        single = new InField(hmin, smin, vmin, hmax, smax, vmax);
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

InField::~InField()
{
    this->instanceFlag = false;

    #ifdef REMOTE
        std::cout<<"InField object destroyed." << std::endl;
    #endif    
}

void InField::processLines(const cv::Mat& src, const double& rho_resol, const double& theta_resol,const int& threshold)
{
    cv::HoughLines(src, infield_lines_, rho_resol, theta_resol, threshold);

}

void InField::processPLines(const cv::Mat& src, const double& rho_resol, const double& theta_resol,const int& threshold,
                     const double& min_line_length, double max_line_gap)
{
    cv::HoughLinesP(src, infieldp_lines_, rho_resol, theta_resol, threshold, min_line_length, max_line_gap);

}

void InField::drawLines(cv::Mat& src, const cv::Scalar& color) const
{
  for( std::size_t i = 0; i < infield_lines_.size(); i++ )
  {
     float rho = infield_lines_[i][0], theta = infield_lines_[i][1];
     cv::Point pt1, pt2;
     double a = cos(theta), b = sin(theta);
     double x0 = a*rho, y0 = b*rho;
     pt1.x = cvRound(x0 + 1000*(-b));
     pt1.y = cvRound(y0 + 1000*(a));
     pt2.x = cvRound(x0 - 1000*(-b));
     pt2.y = cvRound(y0 - 1000*(a));
     cv::line( src, pt1, pt2, color, 3, CV_AA);
  }
}

void InField::drawPLines(cv::Mat& src, const cv::Scalar& color) const
{
  for( std::size_t i = 0; i < houghP_lines_.size(); i++ )
  {
    cv::Vec4i l = houghP_lines_[i];
    cv::line( src, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), color, 3, CV_AA);
  }
    
}

void InField::filterLines(std::vector<cv::Vec2f> filtered_lines, const double& min_rho, const double& max_rho,
                        const double& min_theta, const double& max_theta)
{
    for(size_t i = 0; i < this->infield_lines_.size(); i++)
    {
        if (this->infield_lines_[i][0] > min_rho && this->infield_lines_[i][0] < max_rho &&
            this->infield_lines_[i][1] > min_theta && this->infield_lines_[i][1] < max_theta)
            filtered_lines.push_back(infield_lines_[i]);
            //this->infield_lines_.erase(this->infield_lines_.begin() + i);
    }
}

void InField::filterPLines(std::vector<cv::Vec4i> filteredp_lines, const double& min_rho, const double& max_rho,
                  const double& min_theta, const double& max_theta)
{
    for(size_t i = 0; i < this->infieldp_lines_.size(); i++)
    {
        if (this->infieldp_lines_[i][0] > min_rho && this->infieldp_lines_[i][0] < max_rho &&
            this->infieldp_lines_[i][1] > min_theta && this->infieldp_lines_[i][1] < max_theta)
            filteredp_lines.push_back(infieldp_lines_[i]);
            //this->infieldp_lines_.erase(this->infieldp_lines_.begin() + i);
    }
}

void InField::setInfieldMinHsv(boost::tuple<int,int,int> mint)
{
    boost::get<0>(this->min_hsv_) = boost::get<0>(mint);
    boost::get<1>(this->min_hsv_) = boost::get<1>(mint);
    boost::get<2>(this->min_hsv_) = boost::get<2>(mint);

}

void InField::setInfieldMaxHsv(boost::tuple<int,int,int> maxt)
{
    boost::get<0>(this->max_hsv_) = boost::get<0>(maxt);
    boost::get<1>(this->max_hsv_) = boost::get<1>(maxt);
    boost::get<2>(this->max_hsv_) = boost::get<2>(maxt);
}

void InField::applyInfieldHsv(const cv::Mat& src, cv::Mat& field) const
{
    cv::cvtColor(src,field,CV_BGR2HSV);
    inRange(field,cv::Scalar(boost::get<0>(this->min_hsv_),
                             boost::get<1>(this->min_hsv_),
                             boost::get<2>(this->min_hsv_)),
                  cv::Scalar(boost::get<0>(this->max_hsv_),
                             boost::get<1>(this->max_hsv_),
                             boost::get<2>(this->max_hsv_)),
            field);
            
}

void InField::processInFieldCavitys(const cv::Mat& src, cv::Mat& field,const cv::Size& size, const unsigned int& iter) const
{
    cv::morphologyEx(src,field, cv::MORPH_CLOSE, 
    cv::getStructuringElement(cv::MORPH_ELLIPSE, size), cv::Point(-1,-1),iter);
    cv::morphologyEx(src,field, cv::MORPH_OPEN, 
    cv::getStructuringElement(cv::MORPH_ELLIPSE, size), cv::Point(-1,-1),iter);
}
