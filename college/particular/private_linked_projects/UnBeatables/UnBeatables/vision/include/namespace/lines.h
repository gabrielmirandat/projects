#ifndef _LINES_H_
#define _LINES_H_

#include "common.h"
using namespace common;

namespace lines
{
	void applyHough(const cv::Mat& img, 
					std::vector<cv::Vec2f>& lines,
					int threshold=80,
                    double rho_resol=1,
                    double theta_resol=CV_PI/180);
					
	size_t getFilteredLine(std::vector<cv::Vec2f>& lines,
					 	   cv::Vec2f& line,
					 	   size_t index,
					 	   double min_rho_next,
					 	   double min_rho_far,
					 	   double max_rho_next,
					 	   double max_rho_far,
					 	   double min_theta_next,
					 	   double min_theta_far,
					 	   double max_theta_next,
					 	   double max_theta_far);

	void removeInRangeAngles(std::vector<cv::Vec2f>& lines,
							 double min_theta,
							 double max_theta);

	void drawCross(cv::Mat& img,
				   cv::Point2f point,
				   cv::Scalar color);

	void show(cv::Mat& img,
			  cv::Vec2f& line,
			  cv::Scalar color,
              int thickness=1);

    void truncateLines(std::vector<cv::Vec2f>& lines);
    void normalizeAngles(std::vector<cv::Vec2f>& lines);
}

#endif //_LINES_H_
