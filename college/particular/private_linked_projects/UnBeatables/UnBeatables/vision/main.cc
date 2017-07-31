// bash build.sh
//-- terminal1 
// ./sendToNAO.sh 192.168.0.37
// ssh nao@192.168.0.37
// nao stop 
// naoqi
//-- terminal 2
// cd naoqi
// ./visionClient

//rho = x*cos(theta) + y*sin(theta)


#include "include/InFieldDetection.h"
#include <boost/timer/timer.hpp>

int main(int argc, char* argv[])
{
	cv::VideoCapture cap(argv[1]);
	cv::Mat frame;
	double computation_time =0.0;
	int frame_number = 0;

	// Wallclock and cpu time
	// boost::timer::cpu_timer timer;
	InFieldDetection* ifd = InFieldDetection::getInstance();
	try
	{
    	//bool test = true;
    	while(cap.read(frame))
		{
			if(!ifd->isRunning())
			{
				break;
			}
			
			ifd->run(frame);

			double timer = (double)cv::getTickCount();
			// ifd->getEntity(POST)->detectPosition(ifd->getLinesImage()); //ok - but not working
			//ifd->getEntity(GOAL)->detectPosition(ifd->getLinesImage()); //ok - but not working FAULT
			// ifd->getEntity(ENEMIE)->detectPosition(ifd->getGrayImage());
			//ifd->getEntity(CENTER)->detectPosition(ifd->getInfieldImage()); //ok - but not working
			ifd->getEntity(BALL)->detectPosition(ifd->getGrayImage());
			//ifd->getEntity(CORNER)->detectPosition(ifd->getInfieldImage()); //ok - but not implemented
			//ifd->getEntity(INLINE)->detectPosition(ifd->getInfieldImage()); //ok

			timer = ((double)cv::getTickCount() - timer)/cv::getTickFrequency();
			std::cout << "wallclock_time: " << timer << std::endl;
	        computation_time += timer;
			frame_number+=1;
		}
	}
	catch( cv::Exception& e )
	{
    	//const char* err_msg = e.what();
    	std::cout << "opencv exception caught: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& oor) 
	{
    	std::cerr << "out of range exception caught: " << oor.what() << std::endl;
  	}
  	catch (const std::exception& ex) 
  	{
  		std::cerr << "std exception caught: " << ex.what() << std::endl;
  	}
	
	delete ifd;

	std::cout << "VIDEO_FPS: " << cap.get(CV_CAP_PROP_FPS) << std::endl;
	std::cout << "COMP_TIME: " << computation_time << std::endl;
	std::cout << "MEAN_TIME_PER_FRAME: " << computation_time/ (double) frame_number << std::endl;
	std::cout << "MEAN_FPS: " << 1/(computation_time/ (double) frame_number) << std::endl;

	cv::waitKey(0);
	
	//boost::timer::cpu_times elapsed = timer.elapsed();
	//std::cout << " cpu_time: " << (elapsed.user + elapsed.system)/1e9 << " seconds." << std::endl;
	//std::cout << " wallclock_time: " << elapsed.wall/1e9 << " seconds." << std::endl;
    
	return 1;
}