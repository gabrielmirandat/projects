/** 
 *  @file vision_implementation.h 
 *  @version 1.0
 *  @date 01/16/2016
 *  @author Gabriel Martins de Miranda (UnBeatables Team)
 *  @brief functions relative to the robot's vision
 *  @code 
        #include "vision_implementation.hpp"

        int main(int argc, char** argv)
        {
            VS vs;
            
            VideoCapture cap(argv[1]);

            if (!cap.isOpened())
            {
              std::cout << "!!! Failed to open file: " << argv[1] << std::endl;
              return -1;
            }

            for(;;)
            {
              Mat frame;
              if (!cap.read(frame))             
                   break;
            
                imshow("frame",frame);
                //imwrite("frame.jpg", frame);
                
                //-- post detection test
                bool ok = vs.detectPost(frame);
                if(ok)
                {
                  cout << "diffPosts: " << vs.getDiffPosts() << endl;   
                }

                //-- goal detection test
              bool ok = vs.detectGoal(frame);
              if(ok)
                {
                  cout << "goalSize: " << vs.getGoalSize() << endl; 
                    cout << "post1x: " << vs.getPost1x() << endl;   
                    cout << "post2x: " << vs.getPost2x() << endl;   
                }

                //-- base detection test
                bool ok = vs.detectBase(frame);
              if(ok)
                cout << "thetaBase: " << vs.getThetaBase() << " degrees: " << vs.getThetaBase()*180/CV_PI << endl;  

              //-- ball detection test
              bool ok = vs.detectBall(frame, DOWN);
                if(ok)
                {
                  cout << "ballSide: " << vs.getBallSide() << endl;
                  cout << "ballDist: " << vs.getBallDist() << "\n" << endl;
              }

                waitKey(0);
            }
            return 0;
        }
 * @endcode
 */

//-- includes
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

#ifndef VS_H
#define VS_H

//-- constants 
#define DOWN 0
#define UP 1
#define INFINITE 9999

//-- namespaces
using namespace std;
using namespace cv;

/**
 * @brief VS: vision class. Contains all vision functions and methods.
 */
class VS 
{
  private:
    //-- set functions --//
    
    /**
     * @brief setRhoBase: used to set rhoBase variable. Called in detectBase.
     * @param value: float number corresponding to rhoBase's value.
     * @return void.
     * @sa function detectBase, variable rhoBase.
     *
     * input and output assertives\n
     *   - value must be lesser than image's diagonal.\n
     *   - class variable rhoBase has its value changed.
     */
    void setRhoBase(float value);

    /**
     * @brief setThetaBase: used to set thetaBase variable. Called in detectBase.
     * @param value: float number corresponding to thetaBase's value.
     * @return void.
     * @sa function detectBase, variable thetaBase.
     *
     * input and output assertives\n
     *   - value must be lesser than CV_PI*90/180 and greater than -CV_PI*90/180.
     *   - class variable thetaBase has its value changed.
     */
    void setThetaBase(float value);

    /**
     * @brief setDiffPosts: used to set diffPosts variable. Called in detectPost.
     * @param value: float number corresponding to diffPosts's value.
     * @return void
     * @sa function detectPost, variable diffPosts.
     *
     * input and output assertives\n
     *   - value must be lesser than image's diagonal.
     *   - class variable diffPosts has its value changed.
     */
    void setDiffPosts(float value);

    /**
     * @brief setBallSide: used to set ballSide variable. Called in detectBall.
     * @param value: float number corresponding to ballSide's value.
     * @return void
     * @sa function detectBall, variable ballSide.
     *
     * input and output assertives\n
     *   - value must be lesser than half image's width and greater than this same negative value.
     *   - class variable ballSide has its value changed.
     */
    void setBallSide(float value);

    /**
     * @brief setBallDist: used to set ballDist variable. Called in detectBall.
     * @param value: float number corresponding to ballDist's value.
     * @return void
     * @sa function detectBall, variable ballDist.
     *
     * input and output assertives\n
     *   - value must be positive.
     *   - class variable ballDist has its value changed.
     */
    void setBallDist(float value);

    /**
     * @brief setGoalSize: used to set goalSize variable. Called in detectGoal.
     * @param value: integer corresponding to goalSize's value.
     * @return void
     * @sa function detectGoal, variable goalSize.
     *
     * input and output assertives\n
     *   - value must be lesser than image's diagonal.
     *   - class variable goalSize has its value changed.
     */
    void setGoalSize(int value);

    /**
     * @brief setPost1x: used to set post1x variable. Called in detectGoal.
     * @param value: integer corresponding to post1x's value.
     * @return void
     * @sa function detectGoal, variable post1x.
     *
     * input and output assertives\n
     *   - value must be lesser than image's diagonal.
     *   - class variable post1x has its value changed.
     */
    void setPost1x(int value);

    /**
     * @brief setPost2x: used to set post2x variable. Called in detectGoal.
     * @param value: integer corresponding to post2x's value.
     * @return void
     * @sa function detectGoal, variable post2x.
     *
     * input and output assertives\n
     *   - value must be lesser than image's diagonal.
     *   - class variable post2x has its value changed.
     */
    void setPost2x(int value);

    //-- auxiliary functions

    /**
     * @brief posY2DistanceBottom: used to let goalkeeper know the distance from ball in centimeters.
     *                                      It is measured by a mathematical function that maps the y-value of
     *                                      the ball in image pixels in it's real world value in centimeters.
     *                                      This function is relative to the bottom's robot camera.
     *                                      Called in detectBall.
     * @param posY: integer corresponding to the y-value of the ball in the frame image.
     * @return float value corresponding to the ball's distance from goalkeeper in centimeters.
     * @sa function detectBall.
     *
     * input and output assertives\n
     *   - posY must be greater than zero and lesser than image's height.
     *   - output variable must be greater than zero.
     */
    float posY2DistanceBottom (int posY);

    /**
     * @brief posY2DistanceTop: used to let goalkeeper know the distance from ball in centimeters.
     *                                      It is measured by a mathematical function that maps the y-value of
     *                                      the ball in image pixels in it's real world value in centimeters.
     *                                      This function is relative to the top's robot camera.
     *                                      Called in detectBall.
     * @param posY: integer corresponding to the y-value of the ball in the frame image.
     * @return float value corresponding to the ball's distance from goalkeeper in centimeters.
     * @sa function detectBall.
     *
     * input and output assertives\n
     *   - posY must be greater than zero and lesser than image's height.
     *   - output variable must be greater than zero.
     */
    float posY2DistanceTop (int posY);
    
    /**
     * @brief removeBordes: used to remove the four image outside edges.
     *                               It is needed due to the differences between 
     *                               nao's edge detector and the not embedded environment's version.
     *                               Called in functions detectGoal, detectBase and detectPost. 
     * @param im: image obtained from nao's camera.
     * @return void
     * @sa functions detectBall, detectBase and detectPost.
     *
     * input and output assertives\n
     *   - im must not be empty or null.
     *   - im has it's outside edges removed. No image copy is made.
     */
    void removeBordes(Mat& im);

    /**
     * @brief drawLine: used to draw a line in an image. This function is only used for debugging 
     *                           when using the remote mode.
     * @param im: image where the line will be drawn.
     * @param rho: float number corresponding to the line's distance from source.
     * @param theta: float number corresponding to the line's angle with the image x-axis in radians.
     * @return void
     *
     * input and output assertives\n
     *   - im must not be empty or null.
     *   - rho must be greater than zero and lesser than im's diagonal.
     *   - theta must be between zero and CV_PI.
     *   - a line is drawn in the image im.
     */
    void drawLine(Mat& im ,float& rho, float& theta);

    //-- class variables
    
    //-- goalkeeper
    /** 
     * @brief perpendicular distance in pixels from image pixel (0,0) to goal base.
     */
    float rhoBase;      

    /** 
     * @brief angle in radians between top image x-axis and goal base minus 90 degrees.
     *         Meaning that base tilted to the right correspond to negative angles, 
     *         while base tilted to the left correspond to positive angles.
     */
    float thetaBase;    
    
    /**
     * @brief  width in pixels of goal post.
     */
    float diffPosts;    

    /** 
     * @brief ball distance in pixels relative to the middle column of image.
     *  If the ball is in the right side, it is positive. Otherwise, negative.
     */
    float ballSide;     
    
    /** 
     * @brief distance in centimeters from ball to goalkeeper.
     * It is relative to the calibration phase.
     */
    float  ballDist;    
    
    //-- striker
    /** 
     * @brief distance in pixels between the two goal posts.
     */
    int goalSize;
    
    /** 
     * @brief distance in pixels between image pixel (0,0) and line correspondent to the left goal's post.
     */
    int post1x;         
    
    /** 
     * @brief distance in pixels between image pixel (0,0) and line correspondent to the left goal's post.
     */
    int post2x;         

  public:
    //-- main functions

    /**
     * @brief detectPost: used by the goalkeeper to discover the size in pixels of a goal post.
     *                                 This way, the robot can align itself to the goal center.
     *                                 It calls setDiffPosts.
     * @param im: goalkeeper's top camera image.
     * @return boolean value indicating if a post was found.
     *
     * input and output assertives\n\n
     *   - im must not be empty or null.
     *   - void
     */
    bool detectPost(Mat& im);			

    /**
     * @brief detectBase: used by the goalkeeper to find it's goal base.
     *                                 This way, the robot can align itself in relation to the base.
     *                                 It calls setRhoBase and setThetaBase.
     * @param im: goalkeeper's down camera image.
     * @return boolean value indicating if base was found.
     *
     * input and output assertives\n
     *   - im must not be empty or null.
     *   - void
     */
    bool detectBase(Mat& im);			
    
    /**
     * @brief detectBall: used by the goalkeeper to find the ball.
     *                                 It also defines the ball's distance to the robot.
     *                                 It calls setBallSide and setBallDist.
     * @param im: goalkeeper's up or down camera image.
     * @param camera: value that represents goalkeeper's up(1) or down(0) camera. 
     * @return boolean value indicating if ball was found.
     *
     * input and output assertives\n
     *   - im must not be empty or null.
     *   - camera must be 0 - DOWN or 1 - UP.
     *   - void
     */
    bool detectBall(Mat& im, int camera);
    
    /**
     * @brief detectGoal: used by the striker to find enemies goal.
     *                                 It calls setGoalSize, setPost1x and setPost2x.
     * @param im: goalkeeper's top camera image.
     * @return boolean value indicating if goal was found.
     *
     * input and output assertives\n
     *   - im must not be empty or null.
     *   - void
     */
    bool detectGoal(Mat& im);		

    //-- get functions

    /**
     * @brief getRhoBase: used to get rhoBase's value.
     * @return float number corresponding to rhoBase.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    float getRhoBase();

    /**
     * @brief getThetaBase: used to get thetaBase's value.
     * @return float number corresponding to thetaBase.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */    
    float getThetaBase();

    /**
     * @brief getDiffPosts: used to get diffPosts's value.
     * @return float number corresponding to diffPosts.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    float getDiffPosts();

    /**
     * @brief getBallSide: used to get ballSide's value.
     * @return float number corresponding to ballSide.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    float getBallSide();

    /**
     * @brief getBallDist: used to get ballDist's value.
     * @return float number corresponding to ballDist.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    float getBallDist();

    /**
     * @brief getGoalSize: used to get goalSize's value.
     * @return integer corresponding to goalSize.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    int getGoalSize();

    /**
     * @brief getPost1x: used to get post1x's value.
     * @return float number corresponding to post1x.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    int getPost1x();

    /**
     * @brief getPost2x: used to get post2x's value.
     * @return float number corresponding to post2x.
     *
     * input and output assertives\n
     *   - void
     *   - void
     */
    int getPost2x();	
    
    /**
     * @brief constructor.
     */
    VS();
    
    /**
     * @brief destructor.
     */
    virtual ~VS();    
};

#endif