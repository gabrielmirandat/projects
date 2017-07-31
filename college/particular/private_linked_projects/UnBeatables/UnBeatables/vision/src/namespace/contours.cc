#include "../../include/namespace/contours.h"

namespace contours
{
	void find(cv::Mat& img,
			  std::vector<std::vector<cv::Point> >& contours,
			  int mode,
			  int method)
	{
		cv::findContours(img, contours,mode,method);
	}

	bool InliersCompare(std::vector<cv::Point>  a,
						std::vector<cv::Point>  b) 
	{ 
		return a.size() > b.size(); 
	}


	void filter(std::vector<std::vector<cv::Point> >& contours,
				int min_inliers, 
				int min_area,
				int max_area,
				int min_side_size,
				int min_ratio, 
				int max_ratio)
		{

			size_t size = contours.size();
			for(size_t i = 0; i < size; i++)
    		{
    			size_t inliers = contours[i].size();
				
    			if(inliers < min_inliers)
    			{
					contours.erase(contours.begin()+i);
					i-=1; //Updates contours.size()
					size-=1;
				}else{
					cv::Mat pointsf;
		        	cv::Mat(contours[i]).convertTo(pointsf, CV_32F);
		        	cv::RotatedRect box = fitEllipse(pointsf);
		        	int box_area = box.size.width * box.size.height;
		        	float box_ratio = box.size.width/box.size.height;

					if(
					   	(box_area < min_area || std::min(box.size.width,box.size.height) < min_side_size || box_area > max_area) ||
					   	(box_ratio > max_ratio || box_ratio < min_ratio) ||
					   	(box.center.x > IMG_WIDTH || box.center.y > IMG_HEIGHT || box.center.x < 0 || box.center.y < 0)
					  )
					  {
							contours.erase(contours.begin()+i);
							i-=1; //Updates contours.size()
							size-=1;
					  }
				}
			}
			
			if(contours.size() > 1)
	    		std::sort(contours.begin(), contours.end(), InliersCompare);

		}
}
