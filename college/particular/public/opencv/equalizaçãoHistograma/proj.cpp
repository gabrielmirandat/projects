#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

/**  @function main */
int main( int argc, char** argv )
{
  Mat src, dst;
  /// Load image
  src = imread( argv[1], 1 );

  if( !src.data )
    { cout<<"Usage: ./Histogram_Demo <path_to_image>"<<endl;
      return -1;}

  Mat planes[3];
  split(src,planes);
  
  /// Apply Histogram Equalization
  equalizeHist( planes[0],planes[0] );
  equalizeHist( planes[1],planes[1]);
  equalizeHist( planes[2],planes[2]);
  
  merge(planes,3,dst);

  /// Display results
  namedWindow( "Source image", CV_WINDOW_AUTOSIZE );
  namedWindow( "Equalized Image", CV_WINDOW_AUTOSIZE );

  imshow("Source image", src );
  imshow( "Equalized Image", dst );

  imwrite( "saida.jpg", dst );
  /// Wait until user exits the program
  waitKey(0);

  return 0;
}