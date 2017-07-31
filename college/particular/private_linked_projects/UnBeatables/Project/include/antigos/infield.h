//! @file infield.h
//! @version 1.0
//! @date 02/13/2016 (mm/dd/yy)
//! @author Gabriel Martins de Miranda (UnBeatables Team)
//! @brief functions relative to the elements in field.
//! @code
//! @endcode

#ifndef _INFIELD_H_
#define _INFIELD_H_

#include <iostream>
#include <vector>
#include <boost/tuple/tuple.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


//! @brief Infield class.


class InField
{
    private:
        //variables
        std::vector<cv::Vec2f> infield_lines_;
        std::vector<cv::Vec4i> infieldp_lines_;
        boost::tuple<int,int,int> min_hsv_, max_hsv_;
        static size_t numInfield;

        //singleton
        static bool instanceFlag=false;
        static InField* single=null;
        //private constructor
        explicit InField(const unsigned int& hmin=37, const unsigned int& smin=92, const unsigned int& vmin=0,
                         const unsigned int& hmax=86, const unsigned int& smax=224, const unsigned int& vmax=255);
        
    public:
        //singleton
        static InField* getInstance(const unsigned int& hmin=37, const unsigned int& smin=92, const unsigned int& vmin=0,
                                    const unsigned int& hmax=86, const unsigned int& smax=224, const unsigned int& vmax=255);
        
        //destructor
        virtual ~InField();

        //get and set functions
        inline std::vector<cv::Vec2f> getInfieldLines() const {return this->infield_lines_;};
        inline std::vector<cv::Vec4i> getInfieldPLines() const {return this->infieldp_lines_;};
        inline boost::tuple<int,int,int> getInFieldMinHsv() const {return this->min_hsv_;};
        inline boost::tuple<int,int,int> getInFieldMaxHsv() const {return this->max_hsv_;};
        inline void setInfieldMinHsv(boost::tuple<int,int,int> mint);
        inline void setInfieldMaxHsv(boost::tuple<int,int,int> maxt);

        //processing functions
        void processLines(const cv::Mat& src, const double& rho_resol=1,const double& theta_resol=CV_PI/180,
                        const int& threshold=100);
        void processPLines(const cv::Mat& src, const double& rho_resol=1, const double& theta_resol=CV_PI/180,
                         const int& threshold=50, const double& min_line_length=0, double max_line_gap=0 );
        void filterLines(std::vector<cv::Vec2f> filtered_lines, const double& min_rho, const double& max_rho,
                         const double& min_theta, const double& max_theta);
        void filterPLines(std::vector<cv::Vec4i> filteredp_lines, const double& min_rho, const double& max_rho,
                          const double& min_theta, const double& max_theta);
        void drawLines(cv::Mat& src, const cv::Scalar& color=cv::Scalar(255,0,0)) const;
        void drawPLines(cv::Mat& src, const cv::Scalar& color=cv::Scalar(255,0,0)) const;
        void applyInFieldHsv(const cv::Mat& src, cv::Mat& field) const;
        void processInFieldCavities(const cv::Mat& src, cv::Mat& field,const cv::Size& size, const unsigned int& iter) const;
};

#endif //_INFIELD_H_
