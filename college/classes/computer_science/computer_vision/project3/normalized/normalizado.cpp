#include <stdio.h>
#include <iostream> 
#include <opencv2/opencv.hpp>    
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"

const int EIXOY = 480;	//metade do tamanho da imagem

using namespace cv;
using namespace std;

int main(){
  Mat imagem_1 = imread("../imagens/mantle1.jpg");
  Mat imagem_2 = imread("../imagens/mantle2.jpg");
  int thickness = 2;
  int lineType = 8;
  int largura = imagem_1.cols;
  int altura = imagem_1.rows;
  
  vector<Point2f> pontos_1;	//8 pontos para o algoritmo 8-points normalizado de Hartley da imagem 1
  vector<Point2f> pontos_2;	//8 pontos para o algoritmo 8-points normalizado de Hartley da imagem 2
  vector<Point2f> pontos_correspondecia;	//15 pontos para 15 retas epipolares
  vector<Point3f> linhas;	//(a,b,c) da equação ax + by + c = 0 das equações das retas epipolares
  
  Mat Img_1_aux, Img_2_aux;	//imagens auxiliares
  imagem_1.copyTo(Img_1_aux);
  imagem_2.copyTo(Img_2_aux);
  
  //pontos correspondentes na primeira imagem
  pontos_1.push_back(Point2f(330,620));
  pontos_1.push_back(Point2f(304,414));
  pontos_1.push_back(Point2f(760,526));
  pontos_1.push_back(Point2f(506,568));
  pontos_1.push_back(Point2f(706,512));
  pontos_1.push_back(Point2f(36,298));
  pontos_1.push_back(Point2f(868,188));
  pontos_1.push_back(Point2f(916,410));
  
  //pontos correspondente na segunda imagem
  pontos_2.push_back(Point2f(204,558));
  pontos_2.push_back(Point2f(168,384));
  pontos_2.push_back(Point2f(642,574));
  pontos_2.push_back(Point2f(378,552));
  pontos_2.push_back(Point2f(612,548));
  pontos_2.push_back(Point2f(160,248));
  pontos_2.push_back(Point2f(900,232));
  pontos_2.push_back(Point2f(870,492));
  
  //mostra nas duas imagens onde estão os pontos que se correlacionam
  for(int i=0;i<8;i++){
      	ellipse(	Img_1_aux,	//imagem onde elipse será desenhada
			pontos_1.at(i),	//ponto de centro da elipse
      Size( 16, 8 ),	//dimensões da bounding box que engloba a elipse
		          0,	//rotação da elipse em graus
			  0,	//se estende no arco que vai de 0 graus
			360,	//até 360 graus
	Scalar( 255, 0, 0 ),	//Cor da elipse em BGR (azul)
		  thickness,	//espessura do linha
		 lineType );	//tipo do linha - 8 conectada
	
	ellipse(	Img_2_aux,	//imagem onde elipse será desenhada
			pontos_2.at(i),	//ponto de centro da elipse
      Size( 16, 8 ),	//dimensões da bounding box que engloba a elipse
		          0,	//rotação da elipse em graus
			  0,	//se estende no arco que vai de 0 graus
			360,	//até 360 graus
	Scalar( 255, 0, 0 ),	//Cor da elipse em BGR (azul)
		  thickness,	//espessura do linha
		 lineType );	//tipo do linha - 8 conectada
  }
  
  
  //mostra imagens escaladas pela metade
  resize(Img_1_aux,Img_1_aux,Size(0,0),0.5,0.5);
  resize(Img_2_aux,Img_2_aux,Size(0,0),0.5,0.5);
  
  imshow("Pontos na imagem 1", Img_1_aux);
  imwrite("pontos_im1.jpg",Img_1_aux);
  imshow("Pontos na imagem 2", Img_2_aux);
  imwrite("pontos_im2.jpg",Img_2_aux);
  
  //calcula estimativa da matriz fundamental. Aqui é usado o 
  //algoritmo 8-pontos normalizado de Hartley
  Mat F = findFundamentalMat(pontos_1, pontos_2, CV_FM_8POINT);
  
  //escolhe 15 pontos na imagem da esquerda para ser usada na estimativa das retas epipolares da segunda imagem
  for(int i=115;i<1165;i=i+70)
    pontos_correspondecia.push_back(Point2f(i,EIXOY));
  
  //computa as retas epipolares na segunda imagem dos pontos de pontos_correspondencia
  computeCorrespondEpilines(pontos_correspondecia,1,F,linhas);	//retorna (a,b,c) da equação ax + by + c = 0 no vetor linhas
  
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
  

  resize(imagem_2,imagem_2,Size(0,0),0.5,0.5);
  imshow("Retas epipolares em 2",imagem_2);
  imwrite("img2epi.jpg", imagem_2);
  waitKey(0);
  
  return 1;
}