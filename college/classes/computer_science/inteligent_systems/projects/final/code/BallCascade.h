#ifndef _BALLCASCADE_H_
#define _BALLCASCADE_H_

#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/objdetect/objdetect.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BallCascade
{
private:
   cv::CascadeClassifier cascade_;
   vector<cv::Rect> objects_;
   bool is_running_;

   void loadCascadeXml();
   
public:
	explicit BallCascade();
	virtual ~BallCascade();
   bool isRunning();

	void run(cv::Mat& frame);
};

#endif //_BALLCASCADE_H_