#include "core.hpp"

void preprocessing( Mat& );

void filterHSV( const Mat&, const ColorsToTrack*, Mat& );

void morphOps( Mat& );

void trackFilteredObject( int&, int&, Mat, Mat& );
