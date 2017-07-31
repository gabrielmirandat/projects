#include "operations.h"

Phasor divide(Phasor f1, Phasor f2)
{
    double mag = f1.getMagnitude()/f2.getMagnitude();
    double ang = f1.getAngle() - f2.getAngle();
    return Phasor(mag, ang);
}

Phasor multiply(Phasor f1, Phasor f2)
{
    double mag = f1.getMagnitude() * f2.getMagnitude();
    double ang = f1.getAngle() + f2.getAngle();
    return Phasor(mag, ang);
}

Phasor minus(Phasor f1, Phasor f2)
{
    double real1, real2, real;
    double imag1, imag2, imag;
    
    real1 = f1.getMagnitude()*cos(f1.getAngle()*M_PI/180.0);
    real2 = f2.getMagnitude()*cos(f2.getAngle()*M_PI/180.0);
    
    imag1 = f1.getMagnitude()*sin(f1.getAngle()*M_PI/180.0);
    imag2 = f2.getMagnitude()*sin(f2.getAngle()*M_PI/180.0);
    
    real = real1 - real2;
    imag = imag1 - imag2;
    
    double mag = sqrt(real*real + imag*imag);
    double ang = atan2(imag*M_PI/180.0, real*M_PI/180.0);
    
    return Phasor(mag, ang*180.0/M_PI);
}

Phasor plus(Phasor f1, Phasor f2)
{
    double real1, real2, real;
    double imag1, imag2, imag;
    
    real1 = f1.getMagnitude()*cos(f1.getAngle()*M_PI/180.0);
    real2 = f2.getMagnitude()*cos(f2.getAngle()*M_PI/180.0);
    
    imag1 = f1.getMagnitude()*sin(f1.getAngle()*M_PI/180.0);
    imag2 = f2.getMagnitude()*sin(f2.getAngle()*M_PI/180.0);
    
    real = real1 + real2;
    imag = imag1 + imag2;
    
    double mag = sqrt(real*real + imag*imag);
    double ang = atan2(imag*M_PI/180.0, real*M_PI/180.0);
    
    return Phasor(mag, ang*180.0/M_PI);
}
