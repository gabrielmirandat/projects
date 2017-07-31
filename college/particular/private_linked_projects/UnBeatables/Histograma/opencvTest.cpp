/**
 * @file compareHist_Demo.cpp
 * @brief Sample code to use the function compareHist
 * @author OpenCV team
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
using namespace cv;

/**
 * @function main
 */
int main( int argc, char** argv )
{
    Mat src_base, hsv_base;
    Mat src_test1, hsv_test1;
    Mat src_test2, hsv_test2;
    Mat hsv_half_down;
    string var;

    int h_bins = 50; int s_bins = 60;
    int histSize[] = { h_bins, s_bins };
    // hue varies from 0 to 179, saturation from 0 to 255
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };
    // Use the o-th and 1-st channels
    int channels[] = { 0, 1 };

    const float* ranges[] = { h_ranges, s_ranges };

    /// Histograms
    MatND hist_base;
    MatND hist_half_down;
    MatND hist_test1;
    MatND hist_test2;


    ifstream bons(argv[2]);
    ifstream ruins(argv[3]);

    /// Load three images with different environment settings
    if( argc < 4 )
    {
        printf("** Error. Usage: ./compareHist_Demo <image_settings0> <image_setting1> <image_settings2>\n");
        return -1;
    }

    src_base = imread( argv[1], 1 );
    // imshow("oioioi", src_base);
    // waitKey(0);
    cv::Rect region_of_interest1 = cv::Rect(1, 1, src_base.cols-1, (src_base.rows-1)/2);
    src_base = src_base(region_of_interest1);

    cvtColor( src_base, hsv_base, COLOR_BGR2HSV );
    /// Calculate the histograms for the HSV images
    calcHist( &hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false );
    normalize( hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat() );

    cout << "BONS" << endl;
    while(!bons.eof())
    {
        getline(bons, var);
        src_test1 = imread( var, 1 );
        imshow("sudh",src_test1);
        waitKey(0);
        cvtColor( src_test1, hsv_test1, COLOR_BGR2HSV );
        cv::Rect region_of_interest2 = cv::Rect(1, 1, src_test1.cols-1, (src_test1.rows-1)/2);
        src_test1 = src_test1(region_of_interest2);

        calcHist( &hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false );
        normalize( hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat() );

        double base_test1 = compareHist( hist_base, hist_test1, CV_COMP_CORREL );

        cout << base_test1 << endl;
    }

    cout << "RUINS" << endl;
     while(!ruins.eof())
    {
        getline(ruins, var);
        src_test2 = imread( var, 1 );
        cvtColor( src_test2, hsv_test2, COLOR_BGR2HSV );
        cv::Rect region_of_interest3 = cv::Rect(1, 1, src_test2.cols-1, (src_test2.rows-1)/2);
        src_test2 = src_test2(region_of_interest3);

        calcHist( &hsv_test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false );
        normalize( hist_test2, hist_test2, 0, 1, NORM_MINMAX, -1, Mat() );

        double base_test2 = compareHist( hist_base, hist_test2, CV_COMP_CORREL );

        cout << base_test2 << endl;
    }

    printf( "Done \n" );

    return 0;
}