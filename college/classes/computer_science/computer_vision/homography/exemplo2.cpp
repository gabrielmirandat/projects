//
//  
//  Created by Prof. Dr. Flavio Vidal on 26/02/13.
//  Copyright (c) 2013 Prof. Dr. Flavio Vidal. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "opencv2/calib3d/calib3d.hpp"

using namespace std;
using namespace cv;

         
    int main( int argc, char** argv )
    {
        
        Mat imr = imread("im.008.png",1);
        Mat iml = imread("im.009.png",1);
        
        char* imlabel1 = "Imagem da Direita";
        char* imlabel2 = "Imagem da Esquerda";
        char* imlabel3 = "Imagem Deslocada Direita em Relacao a Esquerda";
        
        // Mostrando as imagens utilizadas
        namedWindow( imlabel1 , CV_WINDOW_AUTOSIZE );
        namedWindow( imlabel2, CV_WINDOW_AUTOSIZE );
        imshow( imlabel1, imr );
        imshow( imlabel2, iml);
        
        // Estimando a Transformação Rigida
        Mat Trans = estimateRigidTransform(imr, iml, 1);
        Mat warp_dst;
        
        // Aplicando a Transformação
        warp_dst = Mat::zeros( iml.rows, iml.cols, iml.type() );
        warpAffine( iml, warp_dst, Trans, warp_dst.size() );
        
        // Mostrando Imagem com a Homografia
        namedWindow( imlabel3, CV_WINDOW_AUTOSIZE );
        imshow( imlabel3, warp_dst);
        
        // Mostrando a Matriz de Transformação Rigida
        for(int row = 0; row < Trans.rows; ++row)
        {
            for (int col = 0; col < Trans.cols; ++col)
            {
                cout << Trans.at<double>(row, col) << endl;
            }
        }
        
        waitKey(0);
        
        return 0;
        
    }
