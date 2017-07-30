#include "BallCascade.h"

int main(int argc, char* argv[])
{
	cv::VideoCapture cap(argv[1]);
	cv::Mat frame;
	double computation_time =0.0;
	int frame_number = 0;
	
	BallCascade* bc = new BallCascade();
	try
	{
    	while(cap.read(frame))
	 	{
			if(!bc->isRunning())
			{
				break;
			}
			
			double timer = (double)cv::getTickCount();
			bc->run(frame);
			timer = ((double)cv::getTickCount() - timer)/cv::getTickFrequency();
			//std::cout << "wallclock_time: " << timer << std::endl;
	        computation_time += timer;
			frame_number+=1;
		}
	}
	catch( cv::Exception& e )
	{
    	std::cout << "opencv exception caught: " << e.what() << std::endl;
	}
	
	
	//cv::waitKey(0);
	delete bc;

	std::cout << "VIDEO_FPS: " << cap.get(CV_CAP_PROP_FPS) << std::endl;
	std::cout << "COMP_TIME: " << computation_time << std::endl;
	std::cout << "MEAN_TIME_PER_FRAME: " << computation_time/ (double) frame_number << std::endl;
	std::cout << "MEAN_FPS: " << 1/(computation_time/ (double) frame_number) << std::endl;
    
	return 1;
}