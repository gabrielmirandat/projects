#include "../include/Receiver.h"

Receiver::Receiver(Channel* chnl)
{
	this->chnl_ = chnl;
	#ifdef OBJECT
        std::cout<<"Receiver object created." << std::endl;
    #endif
}

Receiver::~Receiver()
{
	delete this->chnl;
	
    #ifdef OBJECT
        std::cout<<"Receiver object destroyed." << std::endl;
    #endif
}

void Receiver::bind(Sender& sender)
{
	this->sender_ = sender;
}

void Receiver::run() 
{
	
}