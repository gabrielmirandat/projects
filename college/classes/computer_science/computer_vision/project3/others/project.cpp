#include <stdio.h>
#include <opencv2/opencv.hpp>  
#include <iostream> 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"


const int EIXOY = 480;	//metade do tamanho da imagem

using namespace cv;
using namespace std;

int main(){
  Mat imagem_1 = imread("imagens/mantle1.jpg");
  Mat imagem_2 = imread("imagens/mantle2.jpg");
  int thickness = 2;
  int lineType = 8;
  int largura = imagem_1.cols;
  int altura = imagem_1.rows;
  
  vector<Point2f> pt1;	//8 pontos para o algoritmo 8-points normalizado de Hartley da imagem 1
  vector<Point2f> pt2;	//8 pontos para o algoritmo 8-points normalizado de Hartley da imagem 2
  vector<Point2f> pontos_correspondecia;	//15 pontos para 15 retas epipolares
  vector<Point3f> linhas;	//(a,b,c) da equação ax + by + c = 0 das equações das retas epipolares
  
  Mat Img_1_aux, Img_2_aux;	//imagens auxiliares
  imagem_1.copyTo(Img_1_aux);
  imagem_2.copyTo(Img_2_aux);
  
  //pontos correspondentes na primeira imagem
  pt1.push_back(Point2f(330,620));
  pt1.push_back(Point2f(304,414));
  pt1.push_back(Point2f(760,526));
  pt1.push_back(Point2f(506,568));
  pt1.push_back(Point2f(706,512));
  pt1.push_back(Point2f(36,298));
  pt1.push_back(Point2f(868,188));
  pt1.push_back(Point2f(916,410));
  
  //pontos correspondente na segunda imagem
  pt2.push_back(Point2f(204,558));
  pt2.push_back(Point2f(168,384));
  pt2.push_back(Point2f(642,574));
  pt2.push_back(Point2f(378,552));
  pt2.push_back(Point2f(612,548));
  pt2.push_back(Point2f(160,248));
  pt2.push_back(Point2f(900,232));
  pt2.push_back(Point2f(870,492));

  //Cria matriz A a partir dos pontos
  Mat A =
  (Mat_<float>(8,9) << pt2[0].x*pt1[0].x,pt2[0].x*pt1[0].y, pt2[0].x, pt2[0].y*pt1[0].x, pt2[0].y*pt1[0].y, pt2[0].y, pt1[0].x, pt1[0].y, 1,
		       pt2[1].x*pt1[1].x,pt2[1].x*pt1[1].y, pt2[1].x, pt2[1].y*pt1[1].x, pt2[1].y*pt1[1].y, pt2[1].y, pt1[1].x, pt1[1].y, 1,
		       pt2[2].x*pt1[2].x,pt2[2].x*pt1[2].y, pt2[2].x, pt2[2].y*pt1[2].x, pt2[2].y*pt1[2].y, pt2[2].y, pt1[2].x, pt1[2].y, 1,
		       pt2[3].x*pt1[3].x,pt2[3].x*pt1[3].y, pt2[3].x, pt2[3].y*pt1[3].x, pt2[3].y*pt1[3].y, pt2[3].y, pt1[3].x, pt1[3].y, 1,
                       pt2[4].x*pt1[4].x,pt2[4].x*pt1[4].y, pt2[4].x, pt2[4].y*pt1[4].x, pt2[4].y*pt1[4].y, pt2[4].y, pt1[4].x, pt1[4].y, 1,
		       pt2[5].x*pt1[5].x,pt2[5].x*pt1[5].y, pt2[5].x, pt2[5].y*pt1[5].x, pt2[5].y*pt1[5].y, pt2[5].y, pt1[5].x, pt1[5].y, 1,
		       pt2[6].x*pt1[6].x,pt2[6].x*pt1[6].y, pt2[6].x, pt2[6].y*pt1[6].x, pt2[6].y*pt1[6].y, pt2[6].y, pt1[6].x, pt1[6].y, 1,
		       pt2[7].x*pt1[7].x,pt2[7].x*pt1[7].y, pt2[7].x, pt2[7].y*pt1[7].x, pt2[7].y*pt1[7].y, pt2[7].y, pt1[7].x, pt1[7].y, 1);

  //Computa SVD. 
  Mat w, u, vt;
  SVD::compute(A, w, u, vt);
  
  //Da matriz vt (right singular transposta), encontramos a primeira estimativa de F
  Mat F1 = (Mat_<float>(3,3) <<	vt.at<float>(7,0),vt.at<float>(7,1),vt.at<float>(7,2),
				vt.at<float>(7,3),vt.at<float>(7,4),vt.at<float>(7,5),
				vt.at<float>(7,6),vt.at<float>(7,7),vt.at<float>(7,8));

  //escolhe 15 pontos na imagem da esquerda para ser usada na estimativa das retas epipolares da segunda imagem
  for(int i=115;i<1165;i=i+70)
    pontos_correspondecia.push_back(Point2f(i,EIXOY));
  
  //computa as retas epipolares na segunda imagem dos pontos de pontos_correspondencia
  computeCorrespondEpilines(pontos_correspondecia,1,F1,linhas);	//retorna (a,b,c) da equação ax + by + c = 0 no vetor linhas

  //ponto1 = escolho x=-1 e encontro y
  //ponto2 = escolho x= imagem.cols + 1 e encontro y
  for(int i=0;i<15;i++){
    	line(	   Img_2_aux,	//imagem onde a linha será desenhada
		   Point(-1,((linhas.at(i).x - linhas.at(i).z)/linhas.at(i).y)),	//ponto de início
		   Point(largura+1,(((-linhas.at(i).x)*(largura-1) - linhas.at(i).z)/linhas.at(i).y)),	//ponto de fim
		   Scalar( 255, 255, 255 ),	//Cor da linha em BGR (preto)
		   thickness,	//espessura da linha
		   lineType );	//tipo da linha - 8 conectada
  }

  //Computa SVD em F1 - segunda estimativa - considerando rank 2. 
  Mat w2, u2, vt2;
  SVD::compute(F1, w2, u2, vt2);
  
  Mat W2 = Mat::zeros(3,3,CV_32F);
  W2.at<float>(0,0) = w2.at<float>(0,0);
  W2.at<float>(1,1) = w2.at<float>(1,0);
  
  //Segunda estimativa de F, restrição de que det(F1)=0, rank 2.
  Mat F2 = u2 * W2 * vt2;

  //computa as retas epipolares na segunda imagem dos pontos de pontos_correspondencia
  computeCorrespondEpilines(pontos_correspondecia,1,F2,linhas);	//retorna (a,b,c) da equação ax + by + c = 0 no vetor linhas
  
  //ponto1 = escolho x=-1 e encontro y
  //ponto2 = escolho x= imagem.cols + 1 e encontro y
  for(int i=0;i<15;i++){
    	line(	   imagem_2,	//imagem onde a linha será desenhada
		   Point(-1,((linhas.at(i).x - linhas.at(i).z)/linhas.at(i).y)),	//ponto de início
		   Point(largura+1,(((-linhas.at(i).x)*(largura-1) - linhas.at(i).z)/linhas.at(i).y)),	//ponto de fim
		   Scalar( 255, 255, 255 ),	//Cor da linha em BGR (preto)
		   thickness,	//espessura da linha
		   lineType );	//tipo da linha - 8 conectada
  }
  
    

  resize(Img_2_aux,Img_2_aux,Size(0,0),0.5,0.5);
  imwrite("img2epiF1.jpg", Img_2_aux);
  
  resize(imagem_2,imagem_2,Size(0,0),0.5,0.5);
  imwrite("img2epiF2.jpg", imagem_2);
  
  imshow("Retas epipolares em 2 - sem rank2",Img_2_aux);
  imshow("Retas epipolares em 2 - com rank2",imagem_2);
  waitKey(0);
  return 1;
}