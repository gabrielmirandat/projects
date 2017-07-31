#include "../include/kalman.h"

Kalman::Kalman(const unsigned int& dynam_params, const unsigned int& measure_params, const unsigned int& control_params,
               const float& process_noiseCov, const float& measurement_noiseCov, const float& error_covPost)
               : measurement(2,1),state(4, 1), KF(dynam_params,measure_params,control_params)
{
    this->measurement = cv::Mat_<float>::zeros(2,1);
    KF.statePre.setTo(0);
    KF.statePost.setTo(0);
    setIdentity(KF.transitionMatrix);
    setIdentity(KF.measurementMatrix);
    setIdentity(KF.processNoiseCov, cv::Scalar::all(process_noiseCov)); //adjust this for faster convergence - but higher noise
    setIdentity(KF.measurementNoiseCov, cv::Scalar::all(measurement_noiseCov));
    setIdentity(KF.errorCovPost, cv::Scalar::all(error_covPost));

    #ifdef REMOTE
        std::cout<<"Kalman object created." << std::endl;
    #endif
}

Kalman::~Kalman()
{
    #ifdef REMOTE
        std::cout<<"Kalman object destroyed." << std::endl;
    #endif
}

void Kalman::setFistMeasPos(cv::Point2f& position)
{
    this->meas_pt = position;
    this->measurement.at<float>(0, 0) = this->meas_pt.x;
    this->measurement.at<float>(1, 0) = this->meas_pt.y;

    KF.statePre.at<float>(0, 0) = this->meas_pt.x;
    KF.statePre.at<float>(1, 0) = this->meas_pt.y;

    KF.statePost.at<float>(0, 0) = this->meas_pt.x;
    KF.statePost.at<float>(1, 0) = this->meas_pt.y; 
}

void Kalman::processMeasPos(cv::Point2f& position)
{
    //Predict, to update the internal statePre variable.
    predict();
    //Correct.
    this->meas_pt.x = position.x; this->meas_pt.y = position.y; 
    correct();
}
