#include "include/headers.hpp"
#include "include/track.hpp"

/* Global Variables */
const string windowOriginal 	= "Original Image";
const string windowHSV 			= "HSV Image";
const string windowThresh 		= "Thresholded Image";
const string windowMorph 		= "After Morphological Operations";
const string trackbarWindowName = "Trackbars";
bool running 		= true;
bool paused 		= false;
bool preprocess 	= true;
bool useMorphOps 	= true;
bool trackObjects 	= false;
int IM_HEIGHT, IM_WIDTH;
int ITER = 0;

bool userInput( char );

void help()
{
	cout <<
				"\n This program is designed to peform a webcam color tracking based on trackbars \n"
				"it`s basic usage is:\n"
				"					./segmentColor\n\t"
				"Hot keys:\n"
				"\t press 'm' to turn on/off morphological operations\n"
				"\t press 'p' to turn on/off preprocessing operations\n"
				"\t press 's' to pause or unpuause the video capture\n"
				"\t press 't' to turn on/off tracking\n"
				"\t press 'esc' key to exit\n\n"
				"Parameters and struct refereces are placed at ''include/core.hpp''\n\n"
	<< endl;
}

int main( int argc, char* argv[] )
{
	help();

	/* Initialize structure for tracking object colors */
	ColorsToTrack objectColors;
	initColors( &objectColors );

	Mat cameraFeed;
	/* matrix storage for HSV image */
	Mat HSV;
	/* matrix storage for binary threshold image */
	Mat threshold;
	/*/ x and y values for the location of the object */
	int x = 0, y = 0;

	createTrackbars( trackbarWindowName, &objectColors );

	VideoCapture capture;

	/* open capture object at location zero (default location for webcam) */
	//-- webcam
	  //capture.open(0);
	//-- video
	  capture.open(argv[1]);
	//--imagem
	  //cameraFeed = imread(argv[1]);
	  //resize(cameraFeed, cameraFeed, Size(FRAME_WIDTH, FRAME_HEIGHT)); // to half size or even smaller

	while( running )
	{
		ITER += ITER;
		if( !paused )
		{
			/* store image to matrix && test frame */
			if(!capture.read(cameraFeed))
			{
				std::cout << "Video Ended" << std::endl;
				break;
			}

			//int height = cameraFeed.rows;
    		//int width = cameraFeed.cols;

			//cv::Mat cropped = cv::Mat(cameraFeed, cv::Rect(width/2 - width/7,
                                                		   //height/2 - height/9,
                                                		   //2*width/7, 2*height/7));
        
        	//cameraFeed = cropped;

        	//IM_HEIGHT = 4*height/7;
        	//IM_WIDTH = 4*width/7;

        	//cv::resize(cameraFeed, cameraFeed, cv::Size(/*1.5*width*/4*width/7, /*1.4*height*/4*height/7));  

			/* convert frame from BGR to HSV colorspace */
			cvtColor( cameraFeed, HSV, COLOR_BGR2HSV );

			if( preprocess )
				preprocessing( HSV );
		}

		filterHSV( HSV, &objectColors, threshold );

		if( useMorphOps )
			morphOps( threshold );

		if( trackObjects )
		{
			trackFilteredObject( x, y, threshold, cameraFeed );
			
			if(ITER%100==0)
			{
				cout << "clara! " << x << " " << y << endl;
				//se distância tiver em width/10 ou height/10 faz nada
				char d_x = 'z'; 
				char d_y = 'z';

				if (abs(x - IM_WIDTH/2) > IM_WIDTH/10)
					d_x = x - IM_WIDTH/2 > 0 ? 'd' : 'e';

				if (abs(y - IM_HEIGHT/2) > IM_HEIGHT/10)
					d_y = y - IM_HEIGHT/2 > 0 ? 'b' : 'c';

				cout << "clara! " << x << " " << y << endl;
				cout << "go to! " << d_x << " " << d_y << "\n" << endl;
			}
 		}

		/* show frames */
		imshow( windowThresh, threshold );
		imshow( windowOriginal, cameraFeed );
		imshow( windowHSV, HSV );

		char key = waitKey(1000000);
		running = userInput( key );
	}
	return 0;
}



bool userInput( char key )
{
	bool goOn = true;
	switch( key )
	{
		case 'm':
			useMorphOps = !useMorphOps;
			cout << "MorphOps have been turned ";
			if( useMorphOps )
				cout << "on" << endl;
			else
				cout << "off" << endl;
			break;
		case 'p':
			preprocess = !preprocess;
			cout << "Preprocessing has been turned ";
			if( useMorphOps )
				cout << "on" << endl;
			else
				cout << "off" << endl;
			break;
		case 's':
			paused = !paused;
			cout << "Video ";
			if( paused )
				cout << "paused" << endl;
			else
				cout << "resumed" << endl;
			break;
		case 't':
			trackObjects = ! trackObjects;
			cout << "Track Objects have been turned ";
			if( trackObjects )
				cout << "on" << endl;
			else
				cout << "off" << endl;
			break;
		case 27:	// 'esc'
			cout << "\nExiting program." << endl;
			goOn = false;
			break;
	}
	return goOn;
}
