#include "../include/image.h"

namespace image
{

	void negate(cv::Mat& img_in, cv::Mat& img_out)
	{
		cv::threshold(img_in, img_out, 127, 255, cv::THRESH_BINARY_INV);
	}

    void threshold(cv::Mat& img_in, cv::Mat& img_out, double min, double max, int type)
    {
        cv::threshold(img_in, img_out, min, max, type); //cv::THRESH_TOZERO
    }

	void convert(cv::Mat& img_in, cv::Mat& img_out, int type )
	{
		cv::cvtColor(img_in, img_out, type);
	}

	void hsv(cv::Mat& img_in, cv::Mat& img_out, int_tuple min_hsv, int_tuple max_hsv)
	{
		assert(img_in.channels() == 3); //assert that image is in HSV!
		
		cv::inRange(img_in,
    				cv::Scalar(boost::get<0>(min_hsv),boost::get<1>(min_hsv),boost::get<2>(min_hsv)),
    				cv::Scalar(boost::get<0>(max_hsv),boost::get<1>(max_hsv),boost::get<2>(max_hsv)),
    				img_out);
    }
	
	void canny(cv::Mat& img_in, cv::Mat& img_out, double bottom, double top, int sobel_size, bool grad_flag)
	{
        assert(img_in.channels() == 1 && img_out.channels() == 1);
		cv::Canny(img_in, img_out, bottom, top, sobel_size, grad_flag);
        //removeBorders(img_out);
	}
	
	void intersection(cv::Mat& img_in1, cv::Mat& img_in2, cv::Mat& img_out)
	{
		assert(img_in1.channels() == 1 && img_in1.type() == img_in2.type());
	
		bitwise_and(img_in1,img_in2,img_out);
	}
	
	void removeBorders(cv::Mat& img)
	{
	    for(int i=0; i< IMG_WIDTH;i++){
	      img.at<uchar>(0,i) = 0;
          img.at<uchar>(IMG_HEIGHT-1,i) = 0;
        }

	    for(int i=0; i< IMG_HEIGHT;i++){
	      img.at<uchar>(i,0) = 0;
          img.at<uchar>(i,IMG_WIDTH-1) = 0;
        }
	}

	void blur(cv::Mat& img_in, cv::Mat& img_out, int kernel_size)
	{
		assert(img_in.channels() == 1 && img_out.channels() == 1);
		blur(img_in,img_out,cv::Size(kernel_size,kernel_size));
	}

	void morphClosing(cv::Mat& img, int shape, int shape_size)
	{
		assert(img.channels() == 1);

		morphologyEx(img,
					 img, 
					 cv::MORPH_CLOSE,
					 getStructuringElement(shape, 
						 				   cv::Size(shape_size,shape_size)),
						 				   cv::Point(-1,-1),
						 				   1);
	}

	void morphOpening(cv::Mat& img, int shape, int shape_size)
	{
		assert(img.channels() == 1);

		morphologyEx(img,
					 img, 
					 cv::MORPH_OPEN,
					 getStructuringElement(shape, 
						 				   cv::Size(shape_size,shape_size)),
						                   cv::Point(-1,-1),
						                   1);
	}

	int getHeight(const cv::Mat& img)
  	{
   	return img.rows;
  	}	

	int getWidth(const cv::Mat& img)
	{
		return img.cols;
	}

	int getDiagonal(const cv::Mat& img)
	{
		return std::sqrt(img.rows*img.rows + img.cols*img.cols);
	}

	void debug(const cv::Mat& img, const char* window)
    {
		#ifdef REMOTE
			cv::imshow(window, img);
		#endif
    }

    void resize(cv::Mat img_in, cv::Mat img_out, cv::Size dsize)
    {
        std::cout << "ENTROU" << std::endl;
        cv::resize(img_in, img_out, dsize);
        std::cout << "SAIU" << std::endl;
    }

}
