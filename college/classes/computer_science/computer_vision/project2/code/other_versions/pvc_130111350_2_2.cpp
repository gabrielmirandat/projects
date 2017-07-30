#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>    
#include <opencv2/stitching/stitcher.hpp>  
  
#ifdef _DEBUG    
#pragma comment(lib, "opencv_core246d.lib")     
#pragma comment(lib, "opencv_imgproc246d.lib")   //MAT processing    
#pragma comment(lib, "opencv_highgui246d.lib")    
#pragma comment(lib, "opencv_stitching246d.lib");  
  
#else    
#pragma comment(lib, "opencv_core246.lib")    
#pragma comment(lib, "opencv_imgproc246.lib")    
#pragma comment(lib, "opencv_highgui246.lib")    
#pragma comment(lib, "opencv_stitching246.lib");  
#endif    
  
using namespace cv;    
using namespace std;  
  
void help(){
  cout << "Para usar o programa, você deve chama-lo como ./pvc_130111350_2 image1 image2 ..." << endl;
  cout << "Especifique um minimo de duas imagens de entrada" << endl;
}  

int main(int argc, char** argv)    
{  
  if(argc<3){
    help();
    return 0;
  }
  
  vector< Mat > vImg;
  
  /*vector<vector<Point2f>> img_feat (argc-1);
  
  for(int i=1; i < argc; i++){
    vImg.push_back( imread(argv[i]));  
  }   
  //-- retificacao das imagens --//
  
  for(int i=0; i < argc-1; i++){
    goodFeaturesToTrack(vImg.at(i), img_feat[i], 30, 0.01, 10);
  }
  
  for(int i=0; i < argc-1; i++){
    cornerSubPix(vImg.at(i), img_feat[i], Size( 5, 5 ), Size( -1, -1 ), TermCriteria( CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 40, 0.001 ));
  }
  
  for(int i=0; i < argc-2; i++){
    calcOpticalFlowPyrLK(vImg.at(i),vImg.at(i+1), img_feat[i], img_feat[i+1], OutputArray status, OutputArray err;
  }*/
  
  
  
  
  
  
  
  
  
  //-- retificacao das imagens --//
  
  //-- panorama de imagens --//
  Mat rImg;  
  
  Stitcher stitcher = Stitcher::createDefault();  
  
  unsigned long AAtime=0, BBtime=0; //check processing time  
  AAtime = getTickCount(); //check processing time  
  
  Stitcher::Status status = stitcher.stitch(vImg, rImg);  
  
  BBtime = getTickCount(); //check processing time   
  printf("%.2lf sec \n",  (BBtime - AAtime)/getTickFrequency() ); //check processing time  
  
  if (Stitcher::OK == status)   
    imshow("Stitching Result",rImg);  
  else  
    printf("Stitching fail.");  
  
  //-- panorama de imagens --//
  
  imwrite("saida.jpg",rImg);
  waitKey(0);  
  return 0;
}