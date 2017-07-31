#ifndef _CONTOURS_H_
#define _CONTOURS_H_

#include "common.h"
using namespace common;

namespace contours
{
	void find(cv::Mat& img,
			  std::vector<std::vector<cv::Point> >& contours,
			  int mode=CV_RETR_LIST,
			  int method=CV_CHAIN_APPROX_SIMPLE);

	bool InliersCompare(std::vector<cv::Point>  a,
						std::vector<cv::Point>  b);

	void filter(std::vector<std::vector<cv::Point> >& contours,
				int min_inliers, 
				int min_area,
				int max_area,
				int min_side_size,
				int min_ratio, 
				int max_ratio);

}

#endif //_CONTOURS_H_