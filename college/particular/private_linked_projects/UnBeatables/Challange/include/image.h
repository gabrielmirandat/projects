#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "common.h"
using namespace common;

namespace image
{
	enum StructuringElement 
	{
	  RECT = cv::MORPH_RECT,
	  CROSS = cv::MORPH_CROSS, 
  	  ELLIPSE = cv::MORPH_ELLIPSE
  	};

	//images always passed by reference
	//never return image
	void negate(cv::Mat& img_in, cv::Mat& img_out);
	void convert(cv::Mat& img_in, cv::Mat& img_out, int type );
    void threshold(cv::Mat& img_in, cv::Mat& img_out, double min = 200, double max = 255, int type = cv::THRESH_TOZERO);
	void hsv(cv::Mat& img_in, cv::Mat& img_out, int_tuple min_hsv, int_tuple max_hsv);
	void canny(cv::Mat& img_in, cv::Mat& img_out, double bottom, double top, int sobel_size=3, bool grad_flag=false);
	void intersection(cv::Mat& img_in1, cv::Mat& img_in2, cv::Mat& img_out);
	void removeBorders(cv::Mat& img);
	void blur(cv::Mat& img_in, cv::Mat& img_out, int kernel_size=3);
	void morphClosing(cv::Mat& img, int shape=ELLIPSE, int shape_size=3);
	void morphOpening(cv::Mat& img, int shape=ELLIPSE, int shape_size=3);
    void resize(cv::Mat img_in, cv::Mat img_out, cv::Size dsize);
	void debug(const cv::Mat& img, const char* window);

}

#endif //_IMAGE_H_

