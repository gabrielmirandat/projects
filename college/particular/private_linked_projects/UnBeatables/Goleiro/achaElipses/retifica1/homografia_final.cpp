#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <iostream>
#include <limits>
#include <numeric>
using namespace cv;
using namespace std;

// We need 4 corresponding 2D points(x,y) to calculate homography.
vector<Point2f> image_points_1;      // Stores 4 points(x,y) of the logo image. Here the four points are 4 corners of image.
vector<Point2f> image_points_2;
// Image containers for main and logo image
Mat imageMain;

// Here we get four points from the user with left mouse clicks.
// On 5th click we output the overlayed image.
void on_mouse( int e, int x, int y, int d, void *ptr )
{
    if (e == EVENT_LBUTTONDOWN )
    {
        if(image_points_1.size() < 4 )
        {

            image_points_1.push_back(Point2f(float(x),float(y)));
            cout << x << " "<< y <<endl;
        }
        else if(image_points_2.size() < 3 ) 
        {
	    if(image_points_2.size() == 0){
	      image_points_2.push_back(Point2f(float(x),float(y)));
	    }else if(image_points_2.size() == 1){
	      image_points_2.push_back(Point2f(image_points_2.at(0).x,float(y)));
	    }else if(image_points_2.size() == 2){
	      image_points_2.push_back(Point2f(float(x), image_points_2.at(1).y));
	    }
            //cout << x << " "<< y <<endl;
        }
        else{ 
	    image_points_2.push_back(Point2f(image_points_2.at(2).x,image_points_2.at(0).y));
	  
	    cout << " Calculating Homography " <<endl;
            // Deactivate callback
            cv::setMouseCallback("Display window", NULL, NULL);
            // once we get 4 corresponding points in both images calculate homography matrix
            Mat H = findHomography( image_points_1,image_points_2,0 );
            
	    cout<< H << endl;
	    
	    Mat ImageMainFinal;
            // Warp the logo image to change its perspective
            warpPerspective(imageMain,ImageMainFinal,H,imageMain.size() );
            
	    namedWindow( "output", WINDOW_AUTOSIZE );
	    imshow("output",ImageMainFinal);
	    imwrite("saida.JPG", ImageMainFinal);
	    cvWaitKey(0);
	}
    }
}


int main( int argc, char** argv )
{
//  We need tow argumemts. "Main image" and "logo image"
    if( argc != 2)
    {
        cout <<" Usage: error" << endl;
        return -1;
    }


// Load images from arguments passed.
    imageMain = imread(argv[1], CV_LOAD_IMAGE_COLOR);
// Push the 4 corners of the logo image as the 4 points for correspondence to calculate homography.

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", imageMain );


    setMouseCallback("Display window",on_mouse, NULL );

//  Press "Escape button" to exit
    while(1)
    {
        int key=cvWaitKey(10);
        if(key==27) break;
    }


    return 0;
}


    