#include "../include/localization.hpp"
//#include <qi/log.hpp>
/*
#include "field.hpp"



#include "../C++/DQ.h"
#include "../C++/DQ_kinematics.h"
#include "../C++/DQ_controller.h"
*/
//#include <Eigen/Dense>
#include <stdio.h>
#include <math.h>


using namespace std;
// using namespace Eigen;
#define PI 3.14159265


Localization::Localization()
{
	//Contruindo o campo
	//Field field();

	//Executar Predição(Odometria)
		//Baseado em X,Y e teta fornecidos pela odometria, faz-se uma projeção 3D -> 2D para verificar onde uma 
		//determinada Feature se encontraria no sistemas de coordenadas da câmera.

		//Distância dos pontos
		//Projeção3D->2D 

	//Executar Correção(Visão)

	//Filtro de Kalman Extendido

}

float Localization::projection3d2d(int px, int py,float dist, float apparent_focus)
{
    std::cout << "A 1" << std::endl;
	int xi, yi;
	float hc,xc,yc;
	float resh, resv, ppx, ppy;
	float fovh, fovv;
    std::cout << "A 2" << std::endl;


	xc = yc = 0.0;
	hc =56.85;

	resh = 320.0;		resv = 240.0;
	ppx = 160.0;		ppy = 120.0;
	fovh = (60.97*PI)/180.0;	fovv = (47.64*PI)/180.0;

	float u = px;
	float v = py;
	float fx = 275.84193859;
	float fy = 275.4397455;
	float cx = 164.17096837;
	float cy = 122.34095676;


    float x_img = (dist*(u - ppx)/apparent_focus)/1.25;//y do robo

    std::cout << "A 4" << std::endl;
    //std::cout << "Localization" << "Y relação robô: " << x_img << std::endl;
    //std::cout << "Localization" << "Y relação robô: " << x_img/1.5 << std::endl;
    //std::cout << "Localization" << "Y relação robô: " << x_img/1.25 << std::endl;
	// qiLogInfo("Localization") << "Y relação robô: " << x_img << std::endl;
	// qiLogInfo("Localization") << "Y relação robô: " << x_img/1.5 << std::endl;
	// qiLogInfo("Localization") << "Y relação robô: " << x_img/1.25 << std::endl;
	//qiLogInfo("Localization") << "Y relação robô: " << x_img/((240-v)*1.25) << std::endl;
	//qiLogInfo("Localization") << "Y relação robô: " << x_img*((240-v)*1.25) << std::endl;
	

	// Matrix<int,4,4> HRz180;
	// Matrix<int,4,4> HRz90;
	// Matrix<int,4,4> HRz_90;
	//xp = px global de um ponto da feature
	//xy = py global de um ponto da feature
	//int tx = xp - px;
	//int ty = xy - py;
	//Matrizes Homogênias coordenada mundo p/ Câmera:
	/*HRz180(0,0) = -1;	HRz180(0,1) =  0;	HRz180(0,2) = 0;	HRz180(0,3) = tx;
	HRz180(1,0) =  0;	HRz180(1,1) = -1;	HRz180(1,2) = 0;	HRz180(1,3) = ty;
	HRz180(2,0) =  0;	HRz180(2,1) =  0;	HRz180(2,2) = 1;	HRz180(2,3) = 0;
	HRz180(3,0) =  0;	HRz180(3,1) =  0;	HRz180(3,2) = 0;	HRz180(3,3) = 1;

	HRz90(0,0) =  0;	HRz90(0,1) = -1;	HRz90(0,2) = 0;		HRz90(0,3) = tx;
	HRz90(1,0) =  1;	HRz90(1,1) =  0;	HRz90(1,2) = 0;		HRz90(1,3) = ty;
	HRz90(2,0) =  0;	HRz90(2,1) =  0;	HRz90(2,2) = 1;		HRz90(2,3) = 0;
	HRz90(3,0) =  0;	HRz90(3,1) =  0;	HRz90(3,2) = 0;		HRz90(3,3) = 1;

	HRz_90(0,0) =  0;	HRz_90(0,1) =  1;	HRz_90(0,2) = 0;	HRz_90(0,3) = tx;
	HRz_90(1,0) = -1;	HRz_90(1,1) =  0;	HRz_90(1,2) = 0;	HRz_90(1,3) = ty;
	HRz_90(2,0) =  0;	HRz_90(2,1) =  0;	HRz_90(2,2) = 1;	HRz_90(2,3) = 0;
	HRz_90(3,0) =  0;	HRz_90(3,1) =  0;	HRz_90(3,2) = 0;	HRz_90(3,3) = 1;
	*/

	//-----------------------------------------------------

	// Matrix<float,3,3>RCI;//Matriz de rotação Câmera para Imagem
	// RCI(0,0) = 0.0; RCI(0,1) = 0.0; RCI(0,2) = 1.0;
	// RCI(1,0) = 1.0; RCI(1,1) = 0.0; RCI(1,2) = 0.0;
	// RCI(2,0) = 0.0; RCI(2,1) = 1.0; RCI(2,2) = 0.0;

	// //Matriz de parâmetros intrinsicos K
	// Matrix<float,3,3> K_mat;
	// K_mat(0,0) = resh/(2*tan(0.5*fovh));	K_mat(0,1) = 0.0;							K_mat(0,2) = ppx;
	// K_mat(1,0) = 0.0;						K_mat(1,1) = resv/(2*tan(0.5*fovv));		K_mat(1,2) = ppy;
	// K_mat(2,0) = 0.0;						K_mat(2,1) = 0.0;							K_mat(2,2) = 1.0;


	// Matrix<float,3,3> K2_mat;
	// K2_mat(0,0) = 275.84193859;				K2_mat(0,1) = 0.0;							K2_mat(0,2) = 164.17096837;
	// K2_mat(1,0) = 0.0;						K2_mat(1,1) = 275.4397455;					K2_mat(1,2) = 122.34095676;
	// K2_mat(2,0) = 0.0;						K2_mat(2,1) = 0.0;							K2_mat(2,2) = 1.0;
	// //Matriz de translação do ĉamera robo
	// Matrix<float,3,4> T;
	// T(0,0) = 1.0;	T(0,1) = 0.0;	T(0,2) = 0.0; T(0,3) = xc;
	// T(1,0) = 0.0;	T(1,1) = 1.0;	T(1,2) = 0.0; T(1,3) = yc; 
	// T(2,0) = 0.0;	T(2,1) = 0.0;	T(2,2) = 1.0; T(2,3) = hc;

	// //Matriz de transformação P
	// Matrix<float,3,4> P;
	// P = K_mat*RCI*T;

	// Matrix<float,3,4> P2;
	// P2 = K2_mat*RCI*T;

	// //Simplificando a Matriz P, retira-se a coluna relativa a Z;

	// Matrix<float,3,3>P_linha;
	// P_linha(0,0) = P(0,0); P_linha(0,1) = P(0,1); P_linha(0,2) = P(0,3);
	// P_linha(1,0) = P(1,0); P_linha(1,1) = P(1,1); P_linha(1,2) = P(1,3);
	// P_linha(2,0) = P(2,0); P_linha(2,1) = P(2,1); P_linha(2,2) = P(2,3);

	// Matrix<float,3,3>P2_linha;
	// P2_linha(0,0) = P2(0,0); P2_linha(0,1) = P2(0,1); P2_linha(0,2) = P2(0,3);
	// P2_linha(1,0) = P2(1,0); P2_linha(1,1) = P2(1,1); P2_linha(1,2) = P2(1,3);
	// P2_linha(2,0) = P2(2,0); P2_linha(2,1) = P2(2,1); P2_linha(2,2) = P2(2,3);

	// //Matrix que calcula coordenada global
	// Matrix<float,3,1>camera2robo;
	// Matrix<float,3,1>camera2robo2;
	// Matrix<float,3,1>image;
	// image(0,0) = float(xi);
	// image(1,0) = float(yi);
	// image(2,0) = 1.0;
	// camera2robo = P_linha.inverse()*image;
	// camera2robo2 = P2_linha.inverse()*image;
	// qiLogInfo("Localization") << "K X:" << camera2robo(0,0) << "Y:" << camera2robo(1,0) << std::endl;
	// qiLogInfo("Localization") << "K2 X:" << camera2robo2(0,0) << "Y:" << camera2robo2(1,0) << std::endl;
    return x_img;
}

Localization::~Localization()
{ 

}
