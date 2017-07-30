#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"

using namespace cv;
using namespace std;

enum morfo {//lembrem que so sao considerados os 6 primeiros bits dessas constantes
  ERODING = 0,
  DILATING = 1,
  OPENING = 2,
  CLOSING = 3,
  GRADIENT = 4,
  TOPHAT = 5,
  BLACKHAT = 6,
  BLUR = 7,
  GAUSSIAN_BLUR = 8,
  MEDIAN_BLUR = 9,
  RECT = 10,
  CROSS = 11, 
  ELLIPSE = 12
};

void equalizeHistogram(Mat& src, Mat& equalizada);
void blurImage(Mat& src, Mat& dest, int size = 20, int type = BLUR);
Mat getHSV(Mat& src);
void drawLine(Mat& ori ,float& rho, float& theta, Point& p1, Point& p2, vector<Vec2f> lines, size_t counter);
void drawLines(Mat& ori, vector<Vec2f> lines, int thick = 3);
Mat getRed(Mat& src);
Mat getGreen(Mat& src);
Mat getBlue(Mat& src);
Mat thresBinary(Mat& src, int value);
Mat thresOtsu(Mat& src, double& thre);
Mat erode_dilate(Mat& src, int operation, int elem = RECT, int size = 10);
void erode_dilate(Mat& src, Mat& morf, int operation, int elem, int size = 3);
Mat correctGamma(Mat& src);
Mat contoursImage(Mat& bordas);
void tipXY(Mat& src, Mat& dest, Point& p1, Point& p2, float& rho1, float& rho2);
void tipXY2(Mat& src, Mat& dest, Point& p1, Point& p2);
void tipXY3(Mat& src, Mat& gray_image, Point& p1, Point& p2, Point& p3, Point& p4);
Mat GTransform(Mat& src, int value = 10);
Mat filterEqualizedBest(Mat& src, int value = 50);
double standartDevRed(Mat& src);
Mat RedBorder(Mat& src, int low_der = 3, int high_red = 60);
Mat RedBorderOpt(Mat& src, int low_der, int high_red);
Mat RedBorderOptAuto(Mat& src, int high_red);
Mat RedBorderOptAuto2(Mat& src, int high_pixel);
void std2HighRed(double formal_stdDev,int& formal_redMax);
void showHistogram(Mat& img);

//IDEIAS:
//1) verm - azul com dif maxima de 10
//2) estudar otsu
//3) obter valor comparação de histograma e decidir se faz ou não
//4) equaliza, se verm menor que 50 (para histogramas
//ja uniformes poderia ser 30) e menor que verde