#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    Mat frame;
    for(;;)
    {

        cap >> frame; // get a new frame from camera
        imshow("frame",frame);
        
        char key = (char)waitKey(50);
	if (key=='q'){
	  imwrite("im1.jpg",frame);
	  break;
	}
    }
    
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
