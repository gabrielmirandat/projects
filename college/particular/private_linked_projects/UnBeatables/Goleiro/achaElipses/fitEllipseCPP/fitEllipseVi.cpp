#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace cv;
using namespace std;

#define CAM_HEIGHT 240
#define CAM_WIDTH 320

//struct for final ellipse
struct Fellipse{
    RotatedRect rect;//a rect
    int inliers;     //number of points in contour. It would be better if it was the number of points
                     //used to fit the ellipse.
};
//HSV values used to find the field. With this we limit the search space.
int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;

void process(Mat& image);

bool InliersCompare(Fellipse* a, Fellipse* b) { return a->inliers > b->inliers; }

void help(){
    cout << "To use: ./executable <video.avi>" << endl;
    cout << "If ellipse was found the program will pause. Press a button to continue..\n" <<endl;
}

void drawLines(Mat& ori, vector<Vec2f> lines, int thick){
    double a,b,x0,y0;
    float rho,theta;
    Point p1,p2;

    for(int i=0;i < lines.size();i++){
      rho = lines[i][0]; 
      theta = lines[i][1];
      a = cos(theta), b = sin(theta);
      x0 = a*rho, y0 = b*rho;
      p1.x = cvRound(x0 + 1000*(-b));
      p1.y = cvRound(y0 + 1000*(a));
      p2.x = cvRound(x0 - 1000*(-b));
      p2.y = cvRound(y0 - 1000*(a));
      line( ori, p1, p2, Scalar(0,0,255), thick, CV_AA);
    }
}

int main( int argc, char** argv )
{
    help();
    //read a video from main argument
    VideoCapture cap(argv[1]);
    Mat frame;
    
    //The HSV values for search the field
    H_MIN = 37; H_MAX = 86; S_MIN = 92; S_MAX = 224; V_MIN = 0; V_MAX = 255;

    for(;;)
    {
        //read a frame from video
        if (!cap.read(frame))             
                break;

        imshow("1.normal", frame);
	
	    //imwrite("normal.jpg",frame );
        process(frame);
        char key = waitKey(33);
        if (key == 27) // ESC
                break;
    }
    return 0;
}

void process(Mat& image)
{
    //The vector and images used.
    vector<Fellipse*> best_ellipses;            //store the best ellipses.
    vector<vector<Point> > contours;            //returned from opencv's findContours.
    vector<Vec2f> lines;                        //returned from opencv's houghLines.
    Mat cnnyimage, hsv_image, hsv_gray, cimage; //images that we will use. 
    Fellipse* current_ellipse;                  //current ellipse

    //HSV.Here we restrict the search space for inside the field.
    cvtColor(image,hsv_image,CV_BGR2HSV);
    inRange(hsv_image,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),hsv_gray);
    imshow("2.hsv", hsv_gray);
    
    //Closing followed by opening.Is it interesting? After we blur the image in order to
    //facilitate Canny in finding edges.
    //erode(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    //dilate(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    //dilate(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    //erode(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    blur(hsv_gray, hsv_gray, Size(5,5));
    imshow("3.blur", hsv_gray);
    
    //Canny to find edges
    Canny(hsv_gray,cnnyimage,50,120,3);	//80, 160
    imshow("4.canny", cnnyimage);

    //With houghLines, we can remove strong lines that hinder finding ellipses. We can just draw
    //found lines in the grayscale canny result to remove the lines.
    HoughLines(/*image*/cnnyimage,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 80);
    drawLines(cnnyimage, lines, 2);
    imshow("5.hough", cnnyimage);
    
    //Here we find the contours for what we did
    findContours(cnnyimage, contours,CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE);
    
    //Image with countors that passed the filter step. 
    //The ellipses are also drawn here.
    cimage = Mat::zeros(cnnyimage.size(), CV_8UC3);

    //loop through all contours
    for(size_t i = 0; i < contours.size(); i++)
    {
        //To fit an ellipse we need at leat 6 points. 
        //We can choose here any value greater than that.
        size_t count = contours[i].size();
        if( count < 36)  //36
            continue;

        //We try to fit an ellipse given the current coutour.
        Mat pointsf;
        Mat(contours[i]).convertTo(pointsf, CV_32F);
        RotatedRect box = fitEllipse(pointsf);
        RotatedRect box2 = minAreaRect(pointsf);

        //If the countour passed count filter, we draw it.
        drawContours(cimage, contours, i, Scalar::all(255), 1, 8);
        
        //Trying to find good ellipses. We filter based on the box we found. Experimental values.
        if(box.size.width * box.size.height < (CAM_HEIGHT/4)*(CAM_WIDTH/3) 
           || min(box.size.width,box.size.height) < 40)
            continue;
	    float ratio = box.size.width/box.size.height;
	    if(ratio > 4.5 || ratio < 0.23/*1/4.5*/ || box.size.width * box.size.height > CAM_HEIGHT*CAM_WIDTH)
	       continue;
	    if(box.center.x > CAM_WIDTH || box.center.y > CAM_HEIGHT || box.center.x < 0 || box.center.y < 0)
	       continue;
	    
        //We draw the current ellipse
        ellipse(cimage, box, Scalar(0,255,0), 1, CV_AA);
        drawContours(cimage, contours, i, Scalar(255,0,0), 1, 8);

        //Show the rect
        //Point2f vtx[4];
        //box.points(vtx);
        //for( int j = 0; j < 4; j++ )
        //    line(cimage, vtx[j], vtx[(j+1)%4], Scalar(0,255,0), 1, CV_AA);
	   
       //Here we have a good ellipse.
       current_ellipse = new Fellipse;
	   current_ellipse-> rect = box;
	   current_ellipse-> inliers = contours[i].size();
	   best_ellipses.push_back(current_ellipse);
    }
    
    //Now we filter all the good ellipses to get the best one.
    //We choose that has more points associated.
    int size_best = best_ellipses.size();
    if(size_best >1)
    {
       sort(best_ellipses.begin(), best_ellipses.end(), InliersCompare);
    
       for (int i = 0; i < size_best;i++)
	       cout << best_ellipses[i]->inliers << "  ";
       cout << endl;
        
       //Ideally choose the contour with more points. 
       RotatedRect bbox = best_ellipses[size_best/2]->rect;
       ellipse(cimage, bbox , Scalar(0,0,255), 3, CV_AA);
       delete[] current_ellipse;
    }

    imshow("6.contours", cimage);
    //Pause if found best ellipse
    if(size_best>1)
        waitKey(0);
}