#include "../include/Frame.h"

Frame::Frame()
: info_std_(userdefined::frame_size)
{
	gen_random();

	#ifdef OBJECT
        std::cout<<"Frame object created." << std::endl;
    #endif
}

Frame::~Frame()
{
    #ifdef OBJECT
        std::cout<<"Frame object destroyed." << std::endl;
    #endif
}

void Frame::gen_random() {
    static const char hex_str[] =
        "0123456789"
        "ABCDEF";

    for (int i = 0; i < userdefined::frame_size; ++i) {
        info_std_[i] = hex_str[rand() % (sizeof(hex_str) - 1)];
    }

    s[userdefined::frame_size] = 0;
}