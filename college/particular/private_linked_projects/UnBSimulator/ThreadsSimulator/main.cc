//Usar tutoriais da boost 1_35_0
//Threads (of the same process) run in a shared memory space
//Processes run in separate memory spaces.
#include <iostream>
#include <boost/timer/timer.hpp>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/bind.hpp>

#include "motion/Motion.h"
#include "vision/Vision.h"
#include "behavior/Behavior.h"
#include "communication/Communication.h"

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