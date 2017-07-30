#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 
#include <iostream>
#include <stdio.h>
 
using namespace std;
using namespace cv;
 
int main(int argc, char** argv )
{
    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);  
    imshow( "original", image );
 
    // Load Face cascade (.xml file)
    CascadeClassifier face_cascade;
    face_cascade.load( "/home/gabriel/Área de Trabalho/car_cascade/data/cascade.xml" );
 
    // Detect objects
    std::vector<Rect> objects;
    face_cascade.detectMultiScale( image, objects, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
 
    // Draw circles on the detected objects
    for( int i = 0; i < objects.size(); i++ )
    {
        Point center( objects[i].x + objects[i].width*0.5, objects[i].y + objects[i].height*0.5 );
        ellipse( image, center, Size( objects[i].width*0.5, objects[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    }
     
    imshow( "Detected", image );
     
    waitKey(0);                   
    return 0;
}