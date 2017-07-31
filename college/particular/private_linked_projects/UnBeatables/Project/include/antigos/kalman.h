/** 
 *  @file kalman.h
 *  @version 1.0
 *  @date 02/06/2016
 *  @author Gabriel Martins de Miranda (UnBeatables Team)
 *  @brief functions relative to kalman's filter.
 *  @code
 *      Kalman kalman;
 *      kalman.setFistMeasPos(cv::Point2f measure);
 *      for(;;){
 *          kalman.processMeasPos(measure);
 *          cv::Point2f state = kalman.getStatePos();
 *          measure.x+=0.1; measure.y+=0.15;
 *      }    
 * @endcode
 */
 
#ifndef _KALMAN_H_
#define _KALMAN_H_

#include <iostream>
#include <opencv2/video/tracking.hpp>

/**
 * @brief Kalman class.
 */
class Kalman
{
    private:
        cv::KalmanFilter KF;
        cv::Mat_<float> measurement;  
        cv::Mat_<float> state;    //(x, y, Vx, Vy)
        cv::Mat prediction, estimated;
        cv::Point2f meas_pt;
        cv::Point2f state_pt;

        void predict(void){KF.predict();};
        void correct()
        {
            this->measurement(0) = this->meas_pt.x; this->measurement(1) = this->meas_pt.y; 
            this->estimated = KF.correct(this->measurement);
            this->state_pt.x = this->estimated.at<float>(0); this->state_pt.y = this->estimated.at<float>(1);
        };
    public:
        /**
        * @brief constructor.
        */
        explicit Kalman(const unsigned int& dynam_params=4, const unsigned int& measure_params=2, const unsigned int& control_params=0,
               const float& process_noiseCov=.0025, const float& measurement_noiseCov=1e-1, const float& error_covPost=.1);

        /**
        * @brief copy constructor.
        * Kalman k2(k1);
        */
        Kalman(const Kalman& rhs);

        /**
        * @brief copy assignment operator.
        * w1 = w2;
        */
        Kalman& operator=(const Kalman& rhs);
        
        /**
        * @brief destructor.
        */
        virtual ~Kalman();
        /**
        * @brief setFistMeasPos: used to set the first measurement position for the Kalman filter.
        * @param position: cv::Point2f.
        * @return void.
        *
        * input and output assertives\n\n
        *   - void
        */
        void setFistMeasPos(cv::Point2f& position);
        /**
        * @brief processMeasPos: used to set the others measurement positions. It also predicts and corrects this value,
        *                        storing the next state in state_pt.
        * @param position: cv::Point2f.
        * @return void.
        *
        * input and output assertives\n\n
        *   - im must not be empty or null.
        *   - void
        */
        void processMeasPos(cv::Point2f& position);
        /**
        * @brief getMeasPos: used to get meas_pt's value.
        * @return cv::Point2f corresponding to meas_pt.
        *
        * input and output assertives\n
        *   - void
        *   - void
        */
        cv::Point2f getMeasPos(){return this->meas_pt;};
        /**
        * @brief getStatePos: used to get state_pt's value.
        * @return cv::Point2f corresponding to state_pt.
        *
        * input and output assertives\n
        *   - void
        *   - void
        */
        cv::Point2f getStatePos(){return this->state_pt;};
};

#endif //_KALMAN_H_
