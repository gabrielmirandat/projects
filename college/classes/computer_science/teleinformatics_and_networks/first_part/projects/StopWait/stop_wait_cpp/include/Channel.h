#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#include <iostream>
#include "Frame.h"
#include "Receiver.h"
#include "Sender.h"
#include "namespace/userdefined"

//precisa constructor de copia

class Channel
{
private:
     float frame_loss_prob;
     float delay_prob;
public:
	explicit Channel(int lenght);
	virtual ~Channel();

	void sendTo(Receiver& receiver, Frame& frame);
	void sendTo(Sender& sender, int ack);
};

#endif //_CHANNEL_H_