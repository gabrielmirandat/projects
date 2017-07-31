// classes example
//#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

#include <iostream>

#define BAIXO 0
#define CIMA 1
#define INFINITO 9999

#ifndef VS_H
#define VS_H

using namespace std;
using namespace cv;

class VS {
  private:
    //-- passar variaveis de classe pra ca e fazer métodos get.

  public:
    bool detect_trave(Mat& im);			
    bool detect_base(Mat& im);			
    bool detect_bola(Mat& im, int camera);
    bool detect_gol(Mat& im);			
    
    //-- auxiliares
    float posY2DistanceBottom (int posY);
    float posY2DistanceTop (int posY);
    void remove_bordas(Mat& im);
    void desenha_linha(Mat& ori ,float& rho, float& theta);
	  
    //-- construtor
    VS();
	//-- destrutor
    virtual ~VS();

    //-- detectar base
    float rho_base, theta_base; 

    //-- detectar traves
    float dif_traves;     //esquerda - direita

    //-- detectar bola
    float lado_bola;
    float dist_bola_nao;  //cm INFINITO

    //-- detectar gol
    int tamanho_gol;
    int trave1x, trave2x;
    
};

#endif