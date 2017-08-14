#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include <iostream>
#include "Channel.h"

class Receiver
{
private:
   Channel* chnl_;
   Frame* frame_buffer_;
   TopLayer* top_layer_;
   Sender* sender_;

public:
	explicit Receiver(Channel* chnl);
	virtual ~Receiver();

	void run();

};

#endif //_RECEIVER_H_