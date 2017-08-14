#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int thresh = 60;

/** @function main */
int main( int argc, char** argv )
{
  VideoCapture cap(0);
  
  namedWindow("webcam",1);
  Mat frame_gray;
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  
  Point2f rect_points[4];
  
  //vector<Point2f> image(20);
  //vector<Point3f> vPoints(20);
  
  Point3f pt1,pt2,pt3;
  Point3f wl1,wl2,wl3;
  double dist1, dist2;
  
  int contador = 0;
  int dist[] = {350, 450, 550};
  float fator[] = {1.865, 1.654, 1.391, 1.391, 1.129, 1.092};
  Mat new_camera_matrix;
  
  string msg1, msg2, msg3, msg4;
  int ok;
  int rect_certo;
  char key;
  int i,j;
  
  Mat frame;
  cap >> frame;
  
  FileStorage fs("out_camera_data.xml", FileStorage::READ);
  Mat intrinsics, distortion , pose;
  fs["Camera_Matrix"] >> intrinsics;
  fs["Distortion_Coefficients"] >> distortion;
 
  new_camera_matrix = getOptimalNewCameraMatrix(intrinsics,distortion,frame.size(),1,frame.size(),0);	//nova CameraMatrix junto com distortion
  
  while(contador!=6)
    {
        ok=0;
	cap >> frame; // get a new frame from camera
	
	Point msg1Origin(3, frame.rows - 10);
	Point msg2Origin(frame.cols/2, frame.rows - 10);
	Point msg3Origin(3,10);
	Point msg4Origin(frame.cols/2, 10);
        
        /// Convert image to gray and blur it
	cvtColor( frame, frame_gray, CV_BGR2GRAY );
	blur( frame_gray, frame_gray, Size(3,3) );
	
	/// Detect edges using Threshold
	threshold( frame_gray, threshold_output, thresh, 255, THRESH_BINARY );
	/// Find contours
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	/// Find the rotated rectangles and ellipses for each contour
	vector<RotatedRect> minRect( contours.size() );
	
	for(i = 0; i < contours.size(); i++ ){
	  if(contourArea(contours[i])>5000 && contourArea(contours[i])<50000){
	      minRect[i] = minAreaRect( Mat(contours[i]) );
	      rect_certo = i;
	      ok=1;
	  }
	}
	/// Draw contours
	for(i = 0; i< contours.size(); i++ ){
	  Scalar color = Scalar(0,0,0);
	  minRect[i].points(rect_points);
	  for(j = 0; j < 4; j++ )
	    line( frame, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
	}
	
	 key = (char)waitKey(50);

	 if(key=='i'){
	    contador++;
	 }
	 
	 msg3 = format( "Objeto: %d",(contador%2 + 1));
	 msg4 = format( "Distancia: %d mm",dist[contador/2]);
	 putText( frame, msg3, msg3Origin, 1, 1, Scalar(0,0,255));
	 putText( frame, msg4, msg4Origin, 1, 1, Scalar(0,0,255));
	
	if(ok){
	  
	  minRect[rect_certo].points(rect_points);	//aqui tenho os 4 pontos em pixels
	  
	  //rect_points[0]; é o primeiro ponto
	  //rect_points[1]; é o segundo ponto
	  //rect_points[2]; é o terceiro ponto
	  //rect_points[3]; é o quarto ponto
	  	  
	 //pt1 = Point3f(rect_points[0].x,rect_points[0].y,1);
	 //pt2 = Point3f(rect_points[1].x,rect_points[1].y,1);
	 //pt3 = Point3f(rect_points[2].x,rect_points[2].y,1);
	  
	  
	  //cout << new_camera_matrix << "\n\n\n";


	  //wl1 = new_camera_matrix.inv()* pto;
	  //wl2 = new_camera_matrix.inv()* pt_2;
	  //wl3 = new_camera_matrix.inv()* pt_3;
	  
	  //wl1 *= dist[contador/2];
	  //wl2 *= dist[contador/2];
	  //wl3 *= dist[contador/2];
	  
	  //dist1 = norm(wl1 - wl2);
	  //dist2 = norm(wl2 - wl3);
	  
	  msg1 = format( "pixelDimensions %.2f x %.2f",minRect[rect_certo].size.height, minRect[rect_certo].size.width);
	  //msg2 = format( "realDimensions %.2f x %.2f (mm)",(minRect[rect_certo].size.height/fator[contador]), (minRect[rect_certo].size.width/fator[contador]));
	  msg2 = format( "realDimensions %.2f x %.2f (mm)",11.1,13.1);
	  putText( frame, msg1, msg1Origin, 1, 1, Scalar(0,255,0));
	  putText( frame, msg2, msg2Origin, 1, 1, Scalar(0,255,0));	 	  
	}
	  
	imshow("webcam",frame);
    }
    
    cout <<"\n" << float(1.0) * 33.44;
    return(0);
}
