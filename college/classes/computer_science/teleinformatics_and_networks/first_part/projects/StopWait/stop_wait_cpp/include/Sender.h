#ifndef _SENDER_H_
#define _SENDER_H_

#include <iostream>

class Sender
{
private:
   Channel* chnl_;
   Frame* frame_buffer_;
   TopLayer* top_layer_;
   Receiver* receiver_;
   int ack_buffer_;

public:
	explicit Sender(Channel& chnl;);
	virtual ~Sender();

	void ready();
	void wait();

	void run();
};

#endif //_SENDER_H_