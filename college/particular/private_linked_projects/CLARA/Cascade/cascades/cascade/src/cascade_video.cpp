#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 
#include <iostream>
#include <stdio.h>
 
using namespace std;
using namespace cv;
 

void help(){
    cout << "To use: ./executable cascade.xml <video.avi>\n" << endl;
}

int main(int argc, char** argv )
{
    help();
    if(argc <3){
	cout << "Too few arguments.." << endl;
	return -1;
    }
    VideoCapture cap(argv[2]);
    int width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    Mat image;
    int scale = height/(width/200);
    
    // Load Face cascade (.xml file)
    CascadeClassifier myCascade;
    myCascade.load(argv[1]);
    
    for(;;)
    {
        //read a image from video
        if (!cap.read(image))             
                break;

		std::vector<Rect> objects;
		//imwrite("ori.jpg", image);
		
		cvtColor(image, image, CV_BGR2GRAY);
		resize(image,image,Size(200,scale));
		// Detect objects
		myCascade.detectMultiScale( image, objects, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, Size(20, 20) );
		cvtColor(image, image, CV_GRAY2BGR);
	 
		// Draw circles on the detected objects
		double x=0; double y=0;
		for( int i = 0; i < objects.size(); i++ )
		{
		    ellipse( image, Point(objects[i].x, objects[i].y), Size(2,2), 0, 0, 360, Scalar( 0, 0, 255 ));
		    //Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		    //ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );


		    x = (double) x + objects[i].x;
		    y = (double) y + objects[i].y;
		}
		
		x = (double) x/objects.size();
		y = (double) y/objects.size();
		ellipse( image, Point(x,y), Size(2,2), 0, 0, 360, Scalar( 0, 255, 0));
		
		resize(image,image,Size(width,height));
		imshow( "Detected", image );
		//imwrite("end.jpg", image);
		
		char key = waitKey(33);
	        if (key == 27) // ESC
	                break;
    }
                     
    return 0;
}
