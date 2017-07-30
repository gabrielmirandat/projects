#include "../include/Sender.h"

Sender::Sender(Channel* chnl)
{
	this->chnl_ = chnl;

	#ifdef OBJECT
        std::cout<<"Sender object created." << std::endl;
    #endif
}

Sender::~Sender()
{
    delete this->chnl;

    #ifdef OBJECT
        std::cout<<"Sender object destroyed." << std::endl;
    #endif
}

void Sender::bind(Receiver& receiver)
{
	this->receiver_ = receiver;
}

void Sender::ready()
{
	while(!top_layer_->getPermission());
	frame_buffer_ = top_layer_->popFrame();
	frame_buffer_-> setSlast(0);
	chnl_->sendTo(receiver_, frame_buffer_);
}

void Sender::wait()
{
	top_layer_->setPermission(false);
	
}

void Sender::run() 
{
	ready();
	wait();
}