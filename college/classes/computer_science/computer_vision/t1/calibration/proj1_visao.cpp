#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <iostream>
#include <limits>
#include <numeric>

using namespace cv;
using namespace std;

int n_boards = 0;		//número de fotografias do tabuleiro
int frame_step;			//Frames a serem pulados na câmera
int board_w;			//cantos fechados horizontais do tabuleiro
int board_h;			//cantos fechados verticais do tabuleiro

int main( int argc, char** argv )
{
  CvCapture* capture;
  
  cout<< "Enter the numbers of spanspots = ";
  cin >> n_boards;
	
  cout<< "\rEnter the numbers of frames to skip = ";
  cin >> frame_step;
  
  board_w  = 8;
  board_h  = 6;  
  
  int board_total  = board_w * board_h;						//As bordas do tablado
  Size board_sz = Size( board_w, board_h );
  
  capture = cvCaptureFromCAM(-1);
  
  if(!capture) 
  { 
    cout<< "\nCouldn't open the camera\n";
    return -1;
  }
  
  cvNamedWindow( "Snapshot" );
  cvNamedWindow( "Raw Video");
  
  //Aloca espaço para os parâmetros de acordo com o número total de cantos e número de snapshots
  Mat image_points(n_boards*board_total,2,CV_32FC1);
  Mat object_points(n_boards*board_total,3,CV_32FC1);
  Mat point_counts(n_boards,1,CV_32SC1);
  Mat intrinsic_matrix(3,3,CV_32FC1);
  Mat distortion_coeffs(4,1,CV_32FC1);

  //Note:
	//Intrinsic Matrix - 3x3			   Lens Distorstion Matrix - 4x1
	//	[fx 0 cx]							[k1 k2 p1 p2   k3(optional)]
	//	[0 fy cy]
	//	[0  0  1]
  
  vector<Point2f> corners(board_total);

  int corner_count=0;
  int successes = 0;
  int step, frame = 0;
  
  Mat image = cvQueryFrame( capture );
  Mat gray_image(image.size,CV_8UC1)			//subpixel
  
  //Loop while successful captures equals total snapshots
  //Successful captures implies when all the enclosed corners are detected from a snapshot
  
  while(successes < n_boards)					
  {
    if((frame++ % frame_step) == 0)						//Skip frames
    {
    //Encontra cantos do tabuleiro:
      bool found = findChessboardCorners(image, board_sz, corners);
      if(found)	corner_count++;

      cvtColor( image, gray_image, CV_BGR2GRAY );				//Get Subpixel accuracy on those corners
      
      cornerSubPix( gray_image, corners, Size(11,11),
                        Size(-1,-1), TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

      drawChessboardCorners(image, board_sz, corners, found);			//Draw it
   
      // If we got a good board, add it to our data
      if( corner_count == board_total ) 
      {
	imshow( "Snapshot", image );					//show in color if we did collect the image
	step = successes*board_total;
	for( int i=step, j=0; j<board_total; ++i,++j ) 
	{
	  image_points.at<Vec2f>(i,0)[0] = corners[j].x;
	  image_points.at<Vec2f>(i,0)[1] = corners[j].y;
	  object_points.at<Vec2f>(i,0)[0] = (float) j/board_w;
	  object_points.at<Vec2f>(i,0)[1] = (float) (j%board_w);
	  object_points.at<Vec2f>(i,0)[2] = 0.0f;

	  //CV_MAT_ELEM(matrix, type, i, j*nchannels + channel_idx)
	}
	
	point_counts.at<int>(successes,0)[0] = board_total;    
	successes++;
	cout << successes << "successful Snapshots out of " << n_boards << "collected.";
      }else
	imshow( "Snapshot", gray_image );						//Show Gray if we didn't collect the image
    } 
    //Handle pause/unpause and ESC
    int c = WaitKey(15);
    if(c == 'p')
    {  
      c = 0;
      while(c != 'p' && c != 27)
      {
	c = WaitKey(250);
      }
    }
    if(c == 27)
      return 0;

    image = cvQueryFrame( capture );								//Get next image
    imshow("Raw Video", image);
  }
  
  //End WHILE loop with enough successful captures

  destroyWindow("Snapshot")

  cout << "\n\n *** Calbrating the camera now...\n";

  //Allocate matrices according to successful number of captures
  Mat object_points2(successes*board_total,3,CV_32FC1);
  Mat image_points2(successes*board_total,2,CV_32FC1);
  Mat point_counts2(successes,1,CV_32SC1);
  
  //Tranfer the points to matrices
  for(int i = 0; i<successes*board_total; ++i)
  {
    image_points2.at<Vec2f>(i,0)[0] = image_points.at<Vec2f>(i,0)[0];
    image_points2.at<Vec2f>(i,0)[1] = image_points.at<Vec2f>(i,0)[1]; 
    object_points2.at<Vec2f>(i,0)[0] = object_points.at<Vec2f>(i,0)[0];
    object_points2.at<Vec2f>(i,0)[1] = object_points.at<Vec2f>(i,0)[1];
    object_points2.at<Vec2f>(i,0)[2] = object_points.at<Vec2f>(i,0)[2];
  } 
	
  for(int i=0; i<successes; ++i)
  { 
    point_counts2.at<int>(i,0)[0] = point_counts.at<int>(i,0)[0]; 
    
  }

  // Initialize the intrinsic matrix with both the two focal lengths in a ratio of 1.0

  intrinsic_matrix.at<Vec2f>(0,0)[0] = 1.0f;
  intrinsic_matrix.at<Vec2f>(1,0)[1] = 1.0f;

  //Calibrate the camera
  //_____________________________________________________________________________________
 
  calibrateCamera();
  
  cvCalibrateCamera2(object_points2, image_points2, point_counts2,  cvGetSize( image ), intrinsic_matrix, distortion_coeffs, NULL, NULL,0 );
																																		//CV_CALIB_FIX_ASPECT_RATIO
	
	//_____________________________________________________________________________________

	//Save values to file
	printf(" *** Calibration Done!\n\n");
	printf("Storing Intrinsics.xml and Distortions.xml files...\n");
	cvSave("Intrinsics.xml",intrinsic_matrix);
	cvSave("Distortion.xml",distortion_coeffs);
	printf("Files saved.\n\n");

	printf("Starting corrected display....");

	//Sample: load the matrices from the file
	CvMat *intrinsic = (CvMat*)cvLoad("Intrinsics.xml");
	CvMat *distortion = (CvMat*)cvLoad("Distortion.xml");

	// Build the undistort map used for all subsequent frames.

	IplImage* mapx = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1 );
	IplImage* mapy = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1 );
	cvInitUndistortMap(intrinsic,distortion,mapx,mapy);

	// Run the camera to the screen, showing the raw and the undistorted image.

	cvNamedWindow( "Undistort" );
	while(image) 
	{
		IplImage *t = cvCloneImage(image);
		cvShowImage( "Raw Video", image );			// Show raw image
		cvRemap( t, image, mapx, mapy );			// Undistort image
		cvReleaseImage(&t);
		cvShowImage("Undistort", image);			// Show corrected image

		//Handle pause/unpause and ESC
		int c = cvWaitKey(15);
		if(c == 'p')
		{ 
			c = 0;
			while(c != 'p' && c != 27)
			{
				c = cvWaitKey(250);
			}
		}
		if(c == 27)
			break;

		image = cvQueryFrame( capture );
	} 
	
	return 0;
}

  
  