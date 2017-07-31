#include <iostream>
#include <opencv2/core/core.hpp>
#include <boost/timer/timer.hpp>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/bind.hpp>


class Motion
{
private:
	//void
public:
	Motion(){};
	~Motion(){};

	void walk(int x,int y,int z) const {
		std::cout << "Motion::walk" << std::endl;};

	void head(float angle_x, float angle_y) const {
		std::cout << "Motion::head" << std::endl;};

	void kick() const {
		std::cout << "Motion::kick" << std::endl;};

	void run();

};

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

class Behavior
{
private:
	
public:
	Behavior(){};
	~Behavior(){};

	void searchBall() const {
		std::cout << "		Behavior::searchBall" << std::endl;};

	void alignGoal() const {
		std::cout << "		Behavior::alignGoal" << std::endl;};

	void checkBondaries() const {
		std::cout << "		Behavior::checkBondaries" << std::endl;};

	void run();
};

class Communication
{
private:
	int comm_counter;
public:
	Communication(){};
	~Communication(){};

	void listen() const {
		std::cout << "			Communication::listen" << std::endl;};

	void receive() const {
		std::cout << "			Communication::receive" << std::endl;};

	void send() const {
		std::cout << "			Communication::send" << std::endl;};

	
	void run(boost::posix_time::time_duration interval){
		for(comm_counter=0;comm_counter<100;comm_counter++)
		{
			listen();
			if(comm_counter%5==0) receive();
			if(comm_counter%7==0) send();
			boost::this_thread::sleep(interval);
		}};
};

int main()
{
	// Wallclock and cpu time
	boost::timer::cpu_timer timer;

	boost::posix_time::time_duration interval(boost::posix_time::milliseconds(250));
	boost::posix_time::time_duration delay(boost::posix_time::milliseconds(60));
	boost::thread_group tgroup;

	Motion* motion = new Motion();
	Vision* vision = new Vision();
	Behavior* behavior = new Behavior();
	Communication* comm = new Communication();

	// --vision->run(interval);
	tgroup.create_thread(boost::bind(&Vision::run, vision, interval));
	boost::this_thread::sleep(delay);
	tgroup.create_thread(boost::bind(&Communication::run, comm, interval));

	tgroup.join_all();

	delete motion;
	delete vision;
	delete behavior;
	delete comm;

	boost::timer::cpu_times elapsed = timer.elapsed();
	std::cout << " cpu_time: " << (elapsed.user + elapsed.system)/1e9 << " seconds." << std::endl;
	std::cout << " wallclock_time: " << elapsed.wall/1e9 << " seconds." << std::endl;

	return 0;
}