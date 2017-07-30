#include "../include/TopLayer.h"

TopLayer::TopLayer(size_t number_bits)
: permission_(true)
{
    for (i=0; i < (number_bits/userdefined::frame_size); i++)
    {
        frame_list_[i] = new Frame();
    }

    #ifdef OBJECT
        std::cout<<"TopLayer object created." << std::endl;
    #endif
}

TopLayer::~TopLayer()
{
    size_t size = frame_list_.size();
    for(i=0;i < size;i++)
    {
        delete frame_list_[i];
    }
    frame_list_.clear();

    #ifdef OBJECT
        std::cout<<"TopLayer object destroyed." << std::endl;
    #endif
}

Frame* TopLayer::popFrame()
{
    //remove frame da lista e retorna ele
}

void TopLayer::insertFrame(Frame& frame)
{
    //insere frame na ultima posição
}