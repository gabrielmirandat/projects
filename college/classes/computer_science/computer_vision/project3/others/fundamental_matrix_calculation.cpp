// Example Program for calculating Fundamental Matrix using OpenCV with 8-point algorithm
// Visual Studio 2005
//
#include "stdafx.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
	struct mousedata
	{
		int cntr ;
		CvPoint p1[8];
		CvPoint p2[8];
		
	} pp ={0,{},{}};
	  IplImage* image ;
  IplImage* image2 ;

void on_mouse(int event, int x, int y, int flags, void* param)
{
	switch(event)
	{
	case CV_EVENT_LBUTTONDOWN:
		{
			
			int cntr = pp.cntr;
			char cntr_s[5];
			
			CvFont font;
			cvInitFont(&font,CV_FONT_HERSHEY_PLAIN|CV_FONT_ITALIC,1,1,0,1);

			CvPoint ptr = cvPoint(x,y);
			printf("(%d,%d)",ptr.x,ptr.y);
			if (cntr <8)
			{
				itoa(cntr,cntr_s,10);
				pp.p1[cntr] = ptr;
				cvCircle(image,pp.p1[cntr],1,cvScalar(0,0,255),3);
				  
				cvPutText(image,cntr_s,pp.p1[cntr],&font,cvScalar(0,0,255));
				cvShowImage("mywindow", image);
				cvSaveImage("c:\\img1.jpg",image);

				
			}
			else if (cntr <16)
			{	pp.p2[cntr-8] = ptr;
				cvCircle(image2,pp.p2[cntr-8],1,cvScalar(0,0,255),3);
				_itoa(cntr-8,cntr_s,10);
				cvPutText(image2,cntr_s,pp.p2[cntr-8],&font,cvScalar(0,0,255));
				cvShowImage("mywindow2", image2);
				cvSaveImage("c:\\img2.jpg",image2);
			}
			
			
			pp.cntr = cntr + 1;
		}
		break;

	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	


//	mousedada *pp;
	pp.cntr = 0;

	
  // load 8-bit, 1 channel grayscale PGM image
  image = cvLoadImage("C:\\Documents and Settings\\Ramin\\Desktop\\images\\apt1.jpg");
  image2 = cvLoadImage("C:\\Documents and Settings\\Ramin\\Desktop\\images\\apt2.jpg");
  
  // Create a window in which the captured images will be presented
  cvNamedWindow("mywindow", CV_WINDOW_AUTOSIZE);

  // set the mouse call back
  cvSetMouseCallback("mywindow",on_mouse,0);

  // display results
  cvShowImage("mywindow", image);

 // Create a window in which the captured images will be presented
  cvNamedWindow("mywindow2", CV_WINDOW_AUTOSIZE);

  // set the mouse call back
  cvSetMouseCallback("mywindow2",on_mouse,0 );

  cvShowImage("mywindow2", image2);


  // wait for a keypress
  cvWaitKey(0);

  //transfer the vector of points to the appropriate opencv matrix structures
	int i1,i2;
	i2 =0;
	int numPoints =8;
	CvMat* points1;
	CvMat* points2;
	CvMat* status;
	CvMat* fundMatr;
	points1 = cvCreateMat(2,numPoints,CV_32F);
	points2 = cvCreateMat(2,numPoints,CV_32F);
	status = cvCreateMat(1,numPoints,CV_32F);
	
	for ( i1 = 0; i1 < numPoints; i1++) {
		

		cvSetReal2D(points1,0,i1,pp.p1[i1].x/1); 
		cvSetReal2D(points1,1,i1,pp.p1[i1].y/1); 
		
		cvSetReal2D(points2,0,i1,pp.p2[i1].x/1); 
		cvSetReal2D(points2,1,i1,pp.p2[i1].y/1); 
	}
	
	//create the output fundamental matrix
	fundMatr = cvCreateMat(3,3,CV_32F);
	
	//see opencv manual for other options in computing the fundamental matrix	
	int num = cvFindFundamentalMat(points1,points2,fundMatr,CV_FM_8POINT,1.0,0.9999,status);
	
	if( num == 1 )
	{
		printf("Fundamental matrix was found\n");
		
		
	}
	else
	{
		printf("Fundamental matrix was not found\n");
		return -1;
		
	}
	
	//now visualize the fundamental matrix
	int numOutputPoints;
	
	CvMat* corrLines;
	corrLines= cvCreateMat(3,numPoints,CV_32F);
	
	
	//specify which direction to compute epipolar lines
	int startImage = 2;
	cvComputeCorrespondEpilines( points2,
		startImage,//means points are in image 1
		fundMatr,
		corrLines);
	
	CvMat* a = cvCreateMat(3,1,CV_32F);
	CvMat* b = cvCreateMat(3,1,CV_32F);
	CvMat* c = cvCreateMat(3,1,CV_32F);
	CvMat* d = cvCreateMat(3,1,CV_32F);
	
	//create output window
	char windowName[100];
	strcpy_s(windowName,"Output Window");
	cvNamedWindow(windowName,CV_WINDOW_AUTOSIZE);
	
	//for all the points set the point and corresponding epipolar line
	//and determine where the epipolar line intersects the image plane
	//then display all this info
	CvMat* epiLine = cvCreateMat(1,3,CV_32F);
	for (  i1 = 0; i1 < numPoints; i1++) {
		
		for (i2 = 0; i2 < 3; i2++) {
			cvmSet(epiLine,0,i2,cvmGet(corrLines,i2,i1));
		}
		
		
		CvPoint epipolarLinePoint1, epipolarLinePoint2;
		
		int  i4;
		
		CvMat* a = cvCreateMat(3,1,CV_32F);
		CvMat* b = cvCreateMat(3,1,CV_32F);
		CvMat* c = cvCreateMat(3,1,CV_32F);
		CvMat* d = cvCreateMat(3,1,CV_32F);
		
		
		for ( i4 = 0; i4 < 3; i4++) {
			
			cvSetReal2D(a,i4,0,cvGetReal2D(epiLine,0,i4)/cvGetReal2D(epiLine,0,2));		
		}
		
		
		if (abs(cvGetReal2D(epiLine,0,0)) > abs(cvGetReal2D(epiLine,0,1)) ){
			
			double ylim = image->height;
			
			
			cvSetReal2D(b,0,0,0);
			cvSetReal2D(b,1,0,1);
			cvSetReal2D(b,2,0,0);
			
			
			cvCrossProduct(a,b,c);
			for ( i4 = 0; i4 < 3; i4++) {
				cvSetReal2D(c,i4,0,cvGetReal2D(c,i4,0)/cvGetReal2D(c,2,0));		
			}
			
			cvSetReal2D(b,0,0,0);
			cvSetReal2D(b,1,0,-1.0/ylim);			
			cvSetReal2D(b,2,0,1);
			cvCrossProduct(a,b,d);
			for ( i4 = 0; i4 < 3; i4++) {
				cvSetReal2D(d,i4,0,cvGetReal2D(d,i4,0)/cvGetReal2D(d,2,0));		
			}
			
		}
		else  { 
			double xlim = image->width;
			cvSetReal2D(b,0,0,1);
			cvSetReal2D(b,1,0,0);
			cvSetReal2D(b,2,0,0);
			
			cvCrossProduct(a,b,c);
			for ( i4 = 0; i4 < 3; i4++) {
				cvSetReal2D(c,i4,0,cvGetReal2D(c,i4,0)/cvGetReal2D(c,2,0));		
			}
			
			cvSetReal2D(b,0,0,-1.0/xlim);
			cvSetReal2D(b,1,0,0);
			cvSetReal2D(b,2,0,1);
			cvCrossProduct(a,b,d);
			for ( i4 = 0; i4 < 3; i4++) {
				cvSetReal2D(d,i4,0,cvGetReal2D(d,i4,0)/cvGetReal2D(d,2,0));		
			}
			
		}
		
		
		epipolarLinePoint1.x = cvmGet(c,0,0);
		epipolarLinePoint1.y = cvmGet(c,1,0);
		
		epipolarLinePoint2.x = cvmGet(d,0,0);
		epipolarLinePoint2.y = cvmGet(d,1,0);
		
		//cvCircle(image2,cvPoint(cvmGet(points2,0,i1),cvmGet(points2,1,i1)),5,CV_RGB(255,255,0),1);
		
		cvShowImage(windowName,image2);
		//cvWaitKey(0);
		
		
		cvLine(image,epipolarLinePoint1,epipolarLinePoint2,CV_RGB(0,255,0));

		cvShowImage(windowName,image);
		//	cvWaitKey(0);
	}
	cvWaitKey(0);
	cvSaveImage("c:\\epipolars.jpg",image);
	return 0;

}
