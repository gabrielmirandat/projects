#include "vision_implementation.hpp"

//constructor
VS::VS()
{
    this->rhoBase = this->thetaBase = 0.0;
    this->diffPosts = 0.0;
    this->ballSide = 0.0; 
    this->goalSize = this->post1x = this->post2x = 0;
    this->ballDist = INFINITE;
}

//destructor
VS::~VS()
{
}

//-- set functions
void VS::setRhoBase(float value)
{
    this->rhoBase = value;
}

void VS::setThetaBase(float value)
{
    this->thetaBase = value;
}

void VS::setDiffPosts(float value)
{
    this->diffPosts = value;
}

void VS::setBallSide(float value)
{
    this->ballSide = value;
}

void VS::setBallDist(float value)
{
    this->ballDist = value;
}

void VS::setGoalSize(int value)
{
    this->goalSize = value;
}
    
void VS::setPost1x(int value)
{
    this->post1x = value;
}

void VS::setPost2x(int value)
{
    this->post2x = value;
}

//-- get functions
float VS::getRhoBase()
{
    return this->rhoBase;
}

float VS::getThetaBase()
{
    return this->thetaBase;
}

float VS::getDiffPosts()
{
    return this->diffPosts;
}

float VS::getBallSide()
{
    return this->ballSide;
}

float VS::getBallDist()
{
    return this->ballDist;
}

int VS::getGoalSize()
{
    return this->goalSize;
}

int VS::getPost1x()
{
    return this->post1x;
}

int VS::getPost2x()
{
    return this->post2x;
}

//-- main functions
bool VS::detectPost(Mat& im)
{
    //-- declarations, 
    // as the flag if post was found, the lines for the hough lines algorithm, the images passed
    // in OpenCV functions, the unsigned integers representing the indexes of the chosen lines
    // and the rho and theta that represent those lines.
    int find_flag;
    vector<Vec2f> lines;
    Mat src,dst,cdst;
    size_t i,j;
    float rho1, rho2, theta1, theta2;
    
    //-- initializations
    src = im; //only header copy
    setDiffPosts(0.0);
    find_flag = 0;
    rho1 = rho2 = theta1 = theta2 = 0.0;

    // image beeing used cannot be empty.
    if(src.empty())
    {
      return false;
    }

    // get borders with Canny and remove outside borders for better results.
    Canny(src, dst, 270, 600, 3);
    removeBordes(dst);

    // transform the Canny response from gray to bgr scale. This is only used when in remote mode
    // with the intent to see the colored lines found by the algorithm.
    #ifdef REMOTE 
      cvtColor(dst, cdst, CV_GRAY2BGR); 
    #endif

    // apply the hough lines algorithm with the specified parameters. The function returns the lines 
    // that we will filter.
    HoughLines(/*image*/dst,/*lines*/lines,/*rho resol*/1,/*theta resol*/CV_PI/180,/*thres hough*/80); //60

    //--filtering lines
    // loop to get the firt line corresponding to the post .
    // As hough returns strongest lines in descending order, we start from the beginning
    // and get the first line whose angle is lower than ?? degrees and greater than ?? degrees.
    // Remembering that OpenCV angles are between 0 and 180, it means we are getting only lines
    // like verticals. We store the choosen line's index on the i variable.
    for(i = 0; i < lines.size(); i++ )
    { 
      if( (lines[i][1]>CV_PI/180*15 && lines[i][1]<CV_PI/180*165))
      {
        continue;
      }
      find_flag = 1;
      rho1 = lines[i][0]; 
      theta1 = lines[i][1];
      #ifdef REMOTE
        drawLine(cdst, rho1, theta1);
      #endif
      break;
    }
    i++;    
    
    // loop to get the second line corresponding to the post.
    // It is just executed if the first line was obtained, corresponding to find_flag==1.
    // Here the count begins from the first line's index plus 1.
    // In addition of constraining only vertical lines, we also restrict not so close lines
    // (whose distance is lesser than ? pixels) and not so different angles 
    // (with more than ? degrees distance).
    if(find_flag == 1)
    {
      for(j = i; j < lines.size(); j++ )
      {
        if((lines[j][1]>CV_PI/180*15 && lines[j][1]<CV_PI/180*165))
        {
          continue;
        }

        if(abs(lines[j][0] - rho1) > 5.0  && abs(lines[j][1] - theta1) < CV_PI*5/180)
        {
          find_flag = 2;
          rho2 = lines[j][0]; 
          theta2 = lines[j][1];
                
          setDiffPosts(abs(rho1  - rho2));

          #ifdef REMOTE
            drawLine(cdst, rho2, theta2);
            imshow("result",cdst);
          #endif
          return true;
	      }
      }
    }
    
    // if the code cames to here, It means that at least some of the lines was not found.
    // The function returns false.
    #ifdef REMOTE
      cout << "Post was not found." << endl;
    #endif
    return false;
}

bool VS::detectBase(Mat& im)
{
    //-- declarations, 
    // as the flag if base was found, the lines for the hough lines algorithm, the images passed
    // in OpenCV functions and the rho and theta that represents the best line, here the base line.
    int find_flag;
    vector<Vec2f> lines;
    Mat src, dst, cdst;
    float rho_best, theta_best;
    
    //-- initializations
    src = im; //only header copy
    setRhoBase(0.0);
    setThetaBase(0.0);
    rho_best = 0.0;
    find_flag = 0;
  
    // image beeing used cannot be empty.
    if(src.empty())
    {
        return false;
    }

    // get borders with Canny and remove outside borders for better results.
    Canny(src, dst, 89, 272, 3);
    removeBordes(dst);

    // transform the Canny response from gray to bgr scale. This is only used when in remote mode
    // with the intent to see the colored lines found by the algorithm.    
    #ifdef REMOTE 
      cvtColor(dst, cdst, CV_GRAY2BGR);
    #endif

    // apply the hough lines algorithm with the specified parameters. The function returns the lines 
    // that we will filter.
    HoughLines(/*image*/dst,/*lines*/lines,/*rho resol*/1,/*theta resol*/CV_PI/180,/*thres hough*/100);

    //--filtering lines
    // loop to get the best line corresponding to the base.
    // We start from the beginning and get all the lines whose angle is between ?? and ?? degrees.
    // Remembering that OpenCV angles are between 0 and 180, it means we are obtaining only
    // inclined or horizontal lines.
    // From those lines we choose the one that has the highest rho. This makes sense when the goalkeeper 
    // looks with the down camera.
    for( size_t i = 0; i < lines.size(); i++ )
    {
      if( (lines[i][1]>CV_PI/180*45 && lines[i][1]<CV_PI/180*135))
      {
        float rho = lines[i][0], theta = lines[i][1];
        if(rho > rho_best)
        {
          rho_best = rho;
          theta_best = theta;
          find_flag = 1;
        }
      }
    }
 
    // if ball was found, class variables are assigned and the function returns true. 
    if(find_flag == 1)
    {
      setRhoBase(rho_best);
      setThetaBase(theta_best - CV_PI/2);
      #ifdef REMOTE
        drawLine(cdst, rho_best, theta_best); 
        imshow("result",cdst);
      #endif
      return true;
    }

    // if the code cames to here, It means that base was not found.
    // The function returns false.
    #ifdef REMOTE
      cout << "Base was not found." << endl;
    #endif
    return false;
}

bool VS::detectBall(Mat& im, int camera)
{
    //-- declarations, 
    // as the flag if ball was found, the circles for the hough circles algorithm, the images passed
    // in OpenCV functions, the center and radius that represents the ball circle and the HSV values 
    // for down and top cameras.
    int find_flag;
    vector<Vec3f> circles;
    Mat src, hsv_image, hsv_gray, hsv_comparator, detec_final;
    Point center_best;
    int radius_best;
    int H_MIN_D, H_MAX_D, S_MIN_D, S_MAX_D, V_MIN_D, V_MAX_D;
    int H_MIN_U, H_MAX_U, S_MIN_U, S_MAX_U, V_MIN_U, V_MAX_U;

    //-- initializations
    src = im; //only header copy
    setBallSide(0.0);
    setBallDist(INFINITE);
    find_flag= 0;
    H_MIN_D = 5; H_MAX_D = 31; S_MIN_D = 182; S_MAX_D = 230; V_MIN_D = 0; V_MAX_D = 255;
    H_MIN_U = 0; H_MAX_U = 26; S_MIN_U = 151; S_MAX_U = 228; V_MIN_U =12; V_MAX_U = 255;

    // image beeing used cannot be empty.
    if(src.empty())
    {
      return false;
    }
  
    // transform source to its HSV correspondent. 
    // Apply the HSV filter depending on the camera beeing used.
    // Make morphological transformations to segment the ball and blur it.
    cvtColor(src,hsv_image,CV_BGR2HSV);

    if(camera == DOWN)
      inRange(hsv_image,Scalar(H_MIN_D,S_MIN_D,V_MIN_D),Scalar(H_MAX_D,S_MAX_D,V_MAX_D),hsv_gray);
    else if(camera == UP)
      inRange(hsv_image,Scalar(H_MIN_U,S_MIN_U,V_MIN_U),Scalar(H_MAX_U,S_MAX_U,V_MAX_U),hsv_gray);

    erode(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    dilate(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    dilate(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    erode(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    blur( hsv_gray, hsv_comparator, Size(7, 7));

    // transform the response from gray to bgr scale. This is only used when in remote mode
    // with the intent to see the colored circles found by the algorithm.    
    #ifdef REMOTE
      cvtColor(hsv_comparator,detec_final, CV_GRAY2BGR);
    #endif

    // apply the hough circles algorithm with the specified parameters. The function returns the circles 
    // that we will filter.
    HoughCircles(/*image*/hsv_gray,/*circles*/circles,/*method*/CV_HOUGH_GRADIENT,/*inv ratio resol*/2,
     /*min dist centers*/src.rows/4,/*upper canny thres*/160,/*thres hough*/ 10, /*min radius*/3,/*max radius*/200);
	
    //--filtering circles
    // loop to get the best circle corresponding to the ball.
    // We start from the beginning and loop until we find a circle that fits in some restrictions.
    // Those comparisons are made with the center's pixel value in source image and binary image
    // got from morphological operations.
    // If the image corresponds to the top camera, we also do not consider centers that are above src.rows*0.3.
    for( size_t i = 0; i < circles.size(); i++ )
    {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);

      if(center.x > 0 && center.y > 0 && center.x < src.cols && center.y < src.rows)
      {
	      if(camera == UP && center.y < src.rows*0.3 )
	        continue;
	
	      int center_value = hsv_comparator.at<uchar>(center);
        float red_src = src.at<Vec3b>(center)[2];    //red_srcelho
        float blue_src = src.at<Vec3b>(center)[0];    //blue_src

        if(center_value >= 100 &&  red_src/blue_src > 5.0 && red_src/blue_src < 9.0)
        {
          #ifdef REMOTE
            cout << "center_value   .:" << center_value << endl;
            cout << "red_src/blue_src.:" << red_src/blue_src << endl;
          #endif
          radius_best = radius;
	        center_best = center;
	        find_flag = 1;
	        break;
	      }
      }
  }
      
  // In case we found the ball, we set some class variables and return true.
  // If the choosen circle has it's center in the left image size, ballSize is negative. 
  // Otherwise is positive.
  if(find_flag == 1)
  {
    #ifdef REMOTE
      cout << "found circles.: " << circles.size()  << "\n" << endl;
      circle(detec_final, center_best, radius_best, Scalar(0,0,255), 1, 8, 0 );	
      imshow("result",detec_final);
    #endif

    setBallSide(center_best.x - src.cols/2);
   
    if(camera == UP)
      setBallDist(posY2DistanceTop(center_best.y));
    else if (camera == DOWN)
      setBallDist(posY2DistanceBottom(center_best.y));
    
    return true;
  }

  // if the code cames to here, It means that ball was not found.
  // The function returns false.
  #ifdef REMOTE
    cout << "Ball was not found." << endl;
  #endif
    return false;
}

bool VS::detectGoal(Mat& im)
{
    //-- declarations, 
    // as the flag if post was found, the lines for the hough lines algorithm, the images passed
    // in OpenCV functions, the unsigned integers representing the indexes of the chosen lines
    // and the rho and theta that represent those lines.
    int find_flag;
    vector<Vec2f> lines;
    Mat src,dst,cdst;
    size_t i,j;
    float rho1, rho2, theta1, theta2;
    

    //-- initializations
    src = im; //only header copy
    find_flag = 0;
    rho1 = rho2 = theta1 = theta2 = 0.0;
    int min_goal = src.cols/6;
    setGoalSize(0);
    setPost1x(0);
    setPost2x(0);
    
    // image beeing used cannot be empty.
    if(src.empty())
    {
        return false;
    }

    // get borders with Canny and remove outside borders for better results.
    Canny(src, dst, 212, 420, 3); //212
    removeBordes(dst);

    // transform the Canny response from gray to bgr scale. This is only used when in remote mode
    // with the intent to see the colored lines found by the algorithm.    
    #ifdef REMOTE 
      cvtColor(dst, cdst, CV_GRAY2BGR);
    #endif
    
    // apply the hough lines algorithm with the specified parameters. The function returns the lines 
    // that we will filter.
    HoughLines(/*image*/dst,/*lines*/lines,/*rho resol*/1,/*theta resol*/CV_PI/180,/*thres hough*/60);

    //--filtering lines
    // loop to get the firt line corresponding to the a goal post .
    // As hough returns strongest lines in descending order, we start from the beginning
    // and get the first line whose angle is lower than ?? degrees and greater than ?? degrees.
    // Remembering that OpenCV angles are between 0 and 180, it means we are getting only lines
    // like verticals. We store the choosen line's index on the i variable.
    for(i = 0; i < lines.size(); i++ )
    { 
      if( (lines[i][1]>CV_PI/180*5 && lines[i][1]<CV_PI/180*175))
      {
        continue;
      }

      find_flag = 1;
      rho1 = lines[i][0]; 
      theta1 = lines[i][1];
      #ifdef REMOTE
        drawLine(cdst ,rho1, theta1);
      #endif
      break;
    }
    i++;
    
    // loop to get the second line corresponding to the second's goal post.
    // It is just executed if the first line was obtained, corresponding to find_flag==1.
    // Here the count begins from the first line's index plus 1.
    // In addition of constraining only vertical lines, we also restrict not so close lines
    // (whose distance is lesser than ? pixels).
    if (find_flag == 1)
    {
      for(j = i; j < lines.size(); j++ )
      {
        if( lines[j][1]>CV_PI/180*5 && lines[j][1]<CV_PI/180*175)
	        continue;
	
	      if(abs(lines[j][0] - rho1) > min_goal)
        {
	        find_flag = 2;
	        rho2 = lines[j][0];
	        theta2 = lines[j][1];

	        #ifdef REMOTE
	          drawLine(cdst ,rho2, theta2);
            imshow("result",cdst);
	        #endif
	  
	        setPost1x(rho1);
          setPost2x(rho2);
          setGoalSize(abs(rho1 - rho2));
          
          return true;
        }
      }
    }

    // if the code cames to here, It means that at least some of the lines was not found.
    // The function returns false.
    #ifdef REMOTE
      cout << "Goal was not found." << endl;
    #endif
    return false;
}

//-- auxiliary functions
float VS::posY2DistanceBottom (int posY)
{
    float result = -0.0000049753*posY*posY*posY + 0.0029*posY*posY - 0.7576*posY + 94.3995;
    return result;
}

float VS::posY2DistanceTop (int posY)
{
    float result = -0.000237*posY*posY*posY + 0.1418*posY*posY - 28.9862*posY + 2122.2;
    return result;
}

void VS::removeBordes(Mat& im)
{
    for(int i=0; i< im.cols;i++){
      im.at<uchar>(0,i) = 0;
      im.at<uchar>(im.rows-1,i) = 0;
    }

    for(int i=0; i< im.rows;i++){
      im.at<uchar>(i,0) = 0;
      im.at<uchar>(i,im.cols-1) = 0;
    }
}

void VS::drawLine(Mat& im ,float& rho, float& theta)
{
    Point p1,p2;
    double a,b,x0,y0;
    a = cos(theta), b = sin(theta);
    x0 = a*rho, y0 = b*rho;
    p1.x = cvRound(x0 + 1000*(-b));
    p1.y = cvRound(y0 + 1000*(a));
    p2.x = cvRound(x0 - 1000*(-b));
    p2.y = cvRound(y0 - 1000*(a));
    line( im, p1, p2, Scalar(0,0,255), 3, CV_AA);
}