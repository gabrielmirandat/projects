#include "../include/core.hpp"

/* ColorsToTrack */
void initColors( ColorsToTrack *object )
{
	object -> H_MIN = 0;
	object -> H_MAX = 255;
	object -> S_MIN = 0;
	object -> S_MAX = 255;
	object -> V_MIN = 0;
	object -> V_MAX = 255;
}

/* Strings */
string intToString( int number )
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

/* Trackbars */
void on_trackbar( int, void* )
{
	//This function gets called whenever a
	// trackbar position is changed
}


void createTrackbars( string trackbarWindowName, ColorsToTrack *object )
{
	//create window for trackbars
    namedWindow(trackbarWindowName,0);
	//create memory to store trackbar name on window
	char TrackbarName[50];
	sprintf( TrackbarName, "H_MIN %d", object -> H_MIN );
	sprintf( TrackbarName, "H_MAX %d", object -> H_MAX );
	sprintf( TrackbarName, "S_MIN %d", object -> S_MIN );
	sprintf( TrackbarName, "S_MAX %d", object -> S_MAX );
	sprintf( TrackbarName, "V_MIN %d", object -> V_MIN );
	sprintf( TrackbarName, "V_MAX %d", object -> V_MAX );
	//create trackbars and insert them into window
	//3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
	//the max value the trackbar can move (eg. H_HIGH),
	//and the function that is called whenever the trackbar is moved(eg. on_trackbar)
	//                                  ---->    ---->     ---->
    createTrackbar( "H_MIN", trackbarWindowName, &(object -> H_MIN), object -> H_MAX, on_trackbar );
    createTrackbar( "H_MAX", trackbarWindowName, &(object -> H_MAX), object -> H_MAX, on_trackbar );
    createTrackbar( "S_MIN", trackbarWindowName, &(object -> S_MIN), object -> S_MAX, on_trackbar );
    createTrackbar( "S_MAX", trackbarWindowName, &(object -> S_MAX), object -> S_MAX, on_trackbar );
    createTrackbar( "V_MIN", trackbarWindowName, &(object -> V_MIN), object -> V_MAX, on_trackbar );
    createTrackbar( "V_MAX", trackbarWindowName, &(object -> V_MAX), object -> V_MAX, on_trackbar );
}
/* Drawing */
void drawCross( int x, int y, Mat &frame )
{
	/* if / else statements to prevent drawing out of window */
	if( (y - 25) > 0 )
    	line( frame, Point(x,y), Point(x,y-25), Scalar(0,255,0), 2 );
    else
    	line( frame, Point(x,y), Point(x,0), Scalar(0,255,0),2 );

    if(y+25<FRAME_HEIGHT)
		line( frame, Point(x,y), Point(x,y+25), Scalar(0,255,0), 2 );
    else
    	line( frame, Point(x,y), Point(x,FRAME_HEIGHT), Scalar(0,255,0), 2 );

    if(x-25>0)
    	line( frame, Point(x,y), Point(x-25,y), Scalar(0,255,0), 2 );
    else
    	line( frame, Point(x,y), Point(0,y), Scalar(0,255,0), 2 );

    if(x+25<FRAME_WIDTH)
    	line( frame, Point(x,y), Point(x+25,y), Scalar(0,255,0), 2 );
    else
    	line( frame, Point(x,y), Point(FRAME_WIDTH,y), Scalar(0,255,0), 2 );
}

void drawObject( int x, int y, Mat &frame )
{
	circle( frame,Point(x,y), 20, Scalar(0,255,0), 2 );

    drawCross( x, y, frame );

	putText( frame, intToString(x) + "," + intToString(y) , Point(x,y+30), 1, 1, Scalar( 0, 255, 0 ), 2 );
}
