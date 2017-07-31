#ifndef _PHASOR_H_
#define _PHASOR_H_

#include <iostream>
#include <math.h>

class Phasor
{
    private:
        double magnitude, angle;
    
    public:
        Phasor(double magnitude, double angle)
		{
			this->magnitude = magnitude;
			this->angle = angle;
		}
		
		inline double getMagnitude() const {return this->magnitude;};
        inline double getAngle() const {return this->angle;};
        inline void setMagnitude(double mag) {this->magnitude = mag;};
        inline void setAngle(double ang) {this->angle = ang;};
        inline void show(const char* str){std::cout<< str << "("<<this->magnitude<<","<<this->angle<<")"<<std::endl;};        
};

#endif //_PHASOR_H_