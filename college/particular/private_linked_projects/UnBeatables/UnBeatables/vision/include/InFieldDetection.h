#ifndef _INFIELDDETECTION_H_
#define _INFIELDDETECTION_H_

#include "namespace/common.h"
#include "namespace/image.h"
#include "namespace/lines.h"
// #include "container/LinesContainer.h"
// #include <boost/shared_ptr.hpp>
#include "Post.h"
#include "Goal.h"
#include "Enemie.h"
#include "Center.h"
#include "Ball.h"
#include "Corner.h"
#include "InLine.h"
#include "FieldEntity.h"


//GAMBIARRA! ARRUMAR!
#include "../../common/visionData.hpp"

using namespace common;


class InFieldDetection
{
private:
	std::vector<FieldEntity*> fe_;
	bool is_running_;
	
	//useful variables
	cv::Mat img_gray_, img_blur_, img_hsv_, img_original_/*img_canny_*/;
    cv::Mat img_hsv_field_in_, img_hsv_field_out_, img_lines_;
    cv::Mat img_infield_, img_outfield_;
    int_tuple tpl_min_hsv_field_, tpl_max_hsv_field_;
    visionData persistence;
    std::vector<cv::Vec2f> lines_;
    // cv::MatND histogram_base_H_, histogram_base_S_, histogram_base_V_;
    /*boost::shared_ptr<LinesContainer> lines_container_;*/
    // LinesContainer* lines_container_;

    //useful methods
    void tupleSetter();
    void imagesSetter(cv::Mat image);

    //singletone constructor
	explicit InFieldDetection();
	static InFieldDetection* instance;

public:	
	virtual ~InFieldDetection();
    static InFieldDetection* getInstance();

    void run(cv::Mat image);
    bool isRunning();
    FieldEntity* getEntity(size_t num){return this->fe_[num];}
    cv::Mat& getInfieldImage(){return this->img_infield_;}
    cv::Mat& getOutfieldImage(){return this->img_outfield_;}
    cv::Mat& getGrayImage(){return this->img_gray_;}
    cv::Mat& getOriginalImage(){return this->img_original_;}
    cv::Mat& getLinesImage(){return this->img_lines_;}
    
    visionData getPersistence(){return this->persistence;}
    void updatePersistence(bool cam_flag);

    void detectAll(bool cam_flag=false, float angle=0);
    
    inline void detectPost() 
    {
        this->fe_[POST]->detectPosition(this->img_lines_);
        std::cout << "post:" << this->fe_[POST]->getPosition() << std::endl;
    }

    inline void detectGoal() 
    {
        this->fe_[GOAL]->detectPosition(this->img_lines_);
        std::cout << "goal:" << this->fe_[GOAL]->getPosition() << std::endl;
    }

    inline void detectEnemy() 
    {
        this->fe_[ENEMIE]->detectPosition(this->img_gray_);
        std::cout << "goal:" << this->fe_[ENEMIE]->getPosition() << std::endl;
    }

    inline void detectCenter() 
    {
        this->fe_[CENTER]->detectPosition(this->img_infield_);
        std::cout << "center:" << this->fe_[CENTER]->getPosition() << std::endl;
    }

    inline bool detectBall(bool cam_flag=false,float angle=0)
    {
        this->fe_[BALL]->detectPosition(this->img_gray_,cam_flag);
        std::cout << "Vision ball:" << this->fe_[BALL]->getPosition() << std::endl;
        if (this->fe_[BALL]->getPosition().x == -1)
             return false;
        else
             return true;
    }

    inline void detectCorner() 
    {
        this->fe_[CORNER]->detectPosition(this->img_infield_);
        std::cout << "corner:" << this->fe_[CORNER]->getPosition() << std::endl;
    }
    
    inline void detectInline() 
    {
        this->fe_[INLINE]->detectPosition(this->img_infield_);
        std::cout << "inline:" << this->fe_[INLINE]->getPosition() << std::endl;
    }
};

#endif //_INFIELDDETECTION_H_
