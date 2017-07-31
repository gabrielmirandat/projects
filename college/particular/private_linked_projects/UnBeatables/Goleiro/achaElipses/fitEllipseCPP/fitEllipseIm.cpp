/********************************************************************************
*
*
*  This program is demonstration for ellipse fitting. Program finds
*  contours and approximate it by ellipses.
*
*  Trackbar specify threshold parametr.
*
*  White lines is contours. Red lines is fitting ellipses.
*
*
*  Autor:  Denis Burenkov.
*
*
*
********************************************************************************/
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <auxiliar.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// static void help()
// {
//     cout <<
//             "\nThis program is demonstration for ellipse fitting. The program finds\n"
//             "contours and approximate it by ellipses.\n"
//             "Call:\n"
//             "./fitellipse [image_name -- Default stuff.jpg]\n" << endl;
// }

int sliderPos = 70;

Mat image;

void processImage(int, void*);

int main( int argc, char** argv )
{
    const char* filename = argc == 2 ? argv[1] : (char*)"stuff.jpg";
    image = imread(filename, 0);
    if( image.empty() )
    {
        cout << "Couldn't open image " << filename << "\nUsage: fitellipse <image_name>\n";
        return 0;
    }

    imshow("source", image);
    namedWindow("result", 1);

    // Create toolbars. HighGUI use.
    createTrackbar( "threshold", "result", &sliderPos, 255, processImage );
    processImage(0, 0);

    // Wait for a key stroke; the same function arranges events processing
    waitKey();
    return 0;
}

// Define trackbar callback functon. This function find contours,
// draw it and approximate it by ellipses.
void processImage(int /*h*/, void*)
{
    vector<vector<Point> > contours;
    
    Mat bimage = image >= 240/*sliderPos*/;

    Mat cnnyimage, dilatimage;  
    //erode_dilate(bimage,dilatimage,DILATING,ELLIPSE,3);
    Canny(image,cnnyimage,80,160,3);

    //remove lines
    int thres = (image.cols + image.rows)/6;
    vector<Vec2f> lines;
    HoughLines(/*image*/cnnyimage,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 100, 0, 0 );
    drawLines(cnnyimage, lines);    //como é nível de cinza, 
                                    //já pinta de preto, que é o que quero.
    //images without lines
    
    imshow("imagemb", cnnyimage);
    findContours(cnnyimage, contours,CV_RETR_LIST,CV_CHAIN_APPROX_TC89_L1);
    
    Mat cimage = Mat::zeros(cnnyimage.size(), CV_8UC3);

    for(size_t i = 0; i < contours.size(); i++)                                     //fazendo um loop em todos os contornos
    {
        size_t count = contours[i].size();                                          //apenas se o contorno atual tem no mínimo 6 pontos
        if( count < 36 ) //necessário: 6
            continue;

        Mat pointsf;
        Mat(contours[i]).convertTo(pointsf, CV_32F);
        RotatedRect box = fitEllipse(pointsf);//se tem tenta fitar uma ellipse e 
                                              //coloca dentro de uma caixa
        drawContours(cimage, contours, i, Scalar::all(255), 1, 8); //mostra o contorno (tipo um canny)
        if(box.size.width * box.size.height < 240 * 24)
            continue;
        ellipse(cimage, box, Scalar(0,0,255), 1, CV_AA);                            //desenha a ellipse
        ellipse(cimage, box.center, box.size*0.5f, box.angle, 0, 360, Scalar(0,255,255), 1, CV_AA);
        Point2f vtx[4];
        box.points(vtx);
        for( int j = 0; j < 4; j++ )
            line(cimage, vtx[j], vtx[(j+1)%4], Scalar(0,255,0), 1, CV_AA);          //mostra o retângulo
    }
    
    imshow("result", cimage);
}
