#ifndef VISION_H_
#define VISION_H_

#include <iostream>
#include <opencv2/core/core.hpp>

class Vision
{
private:
	int vision_counter;
	cv::Point ball_position, goal_position, center_position;
	int bi, gi, ci;
public:
	Vision():ball_position(-1,-1), goal_position(-1,-1), center_position(-1,-1){};
	~Vision(){};

	void ball() {
		bi = (++bi%4 == 0) ? bi : -1;
		ball_position = cv::Point(bi,bi);
		std::cout << "	Vision::ball" << std::endl;};

	void goal() {
		gi = (++gi%7 == 0) ? gi : -1;
		goal_position = cv::Point(gi,gi);
		std::cout << "	Vision::goal" << std::endl;};

	void center() {
		ci = (++ci%5 == 0) ? ci : -1;
		center_position = cv::Point(ci,ci);
		std::cout << "	Vision::center" << std::endl;};

	void run(boost::posix_time::time_duration interval){
		for(vision_counter=0;vision_counter<100;vision_counter++)
		{
			ball();
			if(vision_counter%4==0) goal();
			if(vision_counter%11==0) center();
			boost::this_thread::sleep(interval);
		}};
};

#endif //VISION_H_