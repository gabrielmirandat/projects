#include "headers.hpp"

/* Image Parameters */
//default capture width and height (putText purposes)
#define FRAME_WIDTH         640
#define FRAME_HEIGHT        480
//max number of objects to be detected in frame
#define MAX_NUM_CLUSTERS    50
//minimum and maximum object area
#define MIN_OBJECT_AREA     20*20
#define MAX_OBJECT_AREA     FRAME_HEIGHT*FRAME_WIDTH/1.5

typedef struct HSV_ranges
{
	int H_MIN;
	int H_MAX;
	int S_MIN;
	int S_MAX;
	int V_MIN;
	int V_MAX;
} ColorsToTrack;

void initColors( ColorsToTrack *object );

/* String */
string intToString( int );

/* Trackbars */
void on_trackbar( int, void* );
void createTrackbars( string, ColorsToTrack* );

/* Drawing */
void drawCross( int, int, Mat& );
void drawObject( int, int, Mat& );
