#include "auxiliar.hpp"

using namespace cv;

/** @function main */
int main(int argc, char** argv)
{
  Mat src, src_gray; double thre;

  /// Read the image
  src = imread( argv[1], 1 );

  if( !src.data )
    { return -1; }

  /// Convert it to gray
  src_gray = thresBinary(src, 200);

  /// Reduce the noise so we avoid false circle detection
  //GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );

  vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
  HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 0.1, src_gray.rows/5, 200, 10, 80, 100 );

  /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }

  /// Show your results
  imshow( "ori", src );
  imshow( "gray", src_gray );

  waitKey(0);
  return 0;
}