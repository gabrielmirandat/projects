#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <iostream>

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

#endif //COMMUNICATION_H_