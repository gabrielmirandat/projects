#include "namespace/lines.h"

namespace lines
{
	void applyHough(const cv::Mat& img, 
					std::vector<cv::Vec2f>& lines,	
					int threshold,
                    double rho_resol,
                    double theta_resol)
	{
		cv::HoughLines(img,
					   lines,
					   rho_resol,
					   theta_resol,
					   threshold);
	}

	//angle in degress
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
					 	   double max_theta_far)
	{
		size_t size;
		size = lines.size();
		line = cv::Vec2f(-1,-1);
		for(size_t i=index;i < size; i++)
		{
			if
			  (	 
			  (lines[i][1]*180/CV_PI <= min_theta_next && lines[i][1]*180/CV_PI >= min_theta_far || lines[i][1]*180/CV_PI >= max_theta_next && lines[i][1]*180/CV_PI <= max_theta_far)
			  && 
			  (lines[i][0] <= min_rho_next && lines[i][0] >= min_rho_far || lines[i][0] >= max_rho_next && lines[i][0] <= max_rho_far)
			  )
			{
				line = lines[i];
				return i;
			}
		}
		return -1;
	}

	void removeInRangeAngles(std::vector<cv::Vec2f>& lines,
							 double min_theta,
							 double max_theta)
	{
		size_t size = lines.size();

		for(size_t i=0;i < size; i++)
		{
			if(lines[i][1]>min_theta && lines[i][1]<max_theta)
			{
				lines.erase(lines.begin()+i);
				i-=1; //Updates lines.size()
				size-=1;
			}
		}
	}

	void drawCross(cv::Mat& img,
				   cv::Point2f point,
				   cv::Scalar color)
	{
		cv::line( img,
				  cv::Point( point.x - 5, point.y - 5 ),
				  cv::Point( point.x + 5, point.y + 5 ),
				  color, 2, CV_AA, 0);
		cv::line( img,
				  cv::Point( point.x + 5, point.y - 5 ),
				  cv::Point( point.x - 5, point.y + 5 ),
				  color, 2, CV_AA, 0);
		cv::circle( img,
					point,
					10,
					color,
					2);
	 }

	void show(cv::Mat& img,
			  cv::Vec2f& line,
			  cv::Scalar color,
			  int thickness)
	{
		cv::Point pt1, pt2;
    	double a = cos(line[1]), b = sin(line[1]);
    	double x0 = a*line[0], y0 = b*line[0];
    	pt1.x = cvRound(x0 + 1000*(-b));
    	pt1.y = cvRound(y0 + 1000*(a));
    	pt2.x = cvRound(x0 - 1000*(-b));
    	pt2.y = cvRound(y0 - 1000*(a));
    	cv::line( img, pt1, pt2, color, thickness, CV_AA);
	}

    void truncateLines(std::vector<cv::Vec2f>& lines)
    {
        if (lines.size() < 2)
            return;
        float rho=0;
        for (std::vector<cv::Vec2f>::iterator it1 = lines.begin(), it2 = it1 + 1;
             it1 != lines.end();
             it2++)
        {
            rho = it1[0][0];
            if (it2 == lines.end())
               it2 = ++it1;
            else
            {
                if (abs(it1[0][0] - it2[0][0]) < 15)
                {
                    rho += it2[0][0];
                    it1[0][0] = rho/2;
                    it1[0][1] = 0;
                    lines.erase(it2--);
                }
            }
        }
    }

    void normalizeAngles(std::vector<cv::Vec2f>& lines)
    {
        for (size_t i = 0; i < lines.size(); i++)
        {
            if (lines[i][0] < 0)
                lines[i][0] = abs(lines[i][0]);
            lines[i][1] = 0;
        }
    }
}
