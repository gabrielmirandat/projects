#include "../include/Communication.h"

Communication::Communication()
{
    chnl_ = new Channel(100);	
    sender_ = new Sender(chnl_);
    receiver_ = new Receiver(chnl_);

    sender_-> bind(receiver_);
    receiver_-> bind(sender_);

    #ifdef OBJECT
        std::cout<<"Communication object created." << std::endl;
    #endif
}

Communication::~Communication()
{
    delete sender_;
    delete receiver_;
    delete chnl_;


    #ifdef OBJECT
        std::cout<<"Communication object destroyed." << std::endl;
    #endif
}

void Communication::run() 
{
    this->tgroup_.create_thread(boost::bind(&Sender::run,this->sender_));
    this->tgroup_.create_thread(boost::bind(&Receiver::run,this->receiver_));
    this->tgroup_.join_all();
}