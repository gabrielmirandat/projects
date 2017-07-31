#include <stdio.h>
#include <iostream>
#include <sstream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"

using namespace cv;

void help()
{
 std::cout << "\nhow to use = ./exec <video.avi> <video_name> n_of_framas.\n";
 std::cout << "\ndirectory video_name must be present in same path as execu.\n";
 
}

int main(int argc, char* argv[])
{
    if(argc < 4){	
      help();
      exit(-1);
    }
  
    VideoCapture cap(argv[1]);
    if (!cap.isOpened())
    {
        std::cout << "!!! Failed to open file: " << argv[1] << std::endl;
        return -1;
    }
    
    Mat frame;
    int frames_counter = 0;
    int frame_number = 0;
    double nof = cap.get(CV_CAP_PROP_FRAME_COUNT);
    int it = nof/atof(argv[3]);
    
    for(;;)
    {

        if (!cap.read(frame))             
            break;

        imshow("video", frame);
	
	if(frames_counter%it==0){
	    frame_number++;
	    std::stringstream ss;
	    ss << argv[2] << '/' << argv[2] << '_' << frame_number << ".png";
	    std::string file = ss.str();
	    cvtColor(frame, frame, CV_BGR2GRAY);
	    cvtColor(frame, frame, CV_GRAY2BGR);
	    resize(frame, frame, Size(512,512));
	    imwrite(file, frame);
	    std::cout << file << std::endl;
	}
	frames_counter++;
	
	//ESC
        char key = waitKey(1);
        if (key == 27)
            break;
    }

    return 0;
}
