#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/thread/thread.hpp>

#include <iostream>


int main()
{
	long now;
	long old;
	long dif;
	for(int i = 0;i<100;i++)
	{
	    boost::posix_time::ptime time = boost::posix_time::microsec_clock::local_time();
	    boost::posix_time::time_duration duration( time.time_of_day() );

	    now = duration.total_milliseconds();
	    dif = now - old;

	    std::cout <<"Tempo Atual: "<<now<<" Tempo anterior: "<<old<<" Diferença: "<<dif<<std::endl;
	    boost::this_thread::sleep(boost::posix_time::milliseconds(300 - dif));
	    old = now;
	}


    return 0;
}
