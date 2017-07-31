#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

#include "include/kalman.h"

int main(){
    cv::Point2f measure, state;
    measure = cv::Point2f(2.0,3.0);
    Kalman kalman(4);
    kalman.setFistMeasPos(measure);

    double t = (double) cv::getTickCount(); //ticks_passados1

    for(std::size_t i=0; i<100;i++)
    {
        kalman.processMeasPos(measure);
        state = kalman.getStatePos();
        measure.x+=0.1; measure.y+=0.15;
        std::cout << "clara!" << state << std::endl;
    }

    t = ((double) cv::getTickCount() - t)/cv::getTickFrequency(); //(ticks_passados2 - ticks_passados1)/(ticks_emitidos/segundo)
    //= segundos passados no evento
    std::cout << "Times passed in seconds: " << t << std::endl;

    return 0;
}
