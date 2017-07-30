#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

#include <iostream>
#include "namespace/userdefined"
#include <boost/thread.hpp>


class Communication
{
private:
	Sender* sender_;
	Receiver* receiver_;
	Channel* chnl_;
    boost>>thread_group tgroup_;

public:
	explicit Communication();
	virtual ~Communication();

	void run();

};

#endif //_COMMUNICATION_H_