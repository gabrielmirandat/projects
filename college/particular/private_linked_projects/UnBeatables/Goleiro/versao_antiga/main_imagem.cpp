#include "vision_implementation.hpp"

int main(int argc, char** argv)
{
	//const char* im_esq = argv[1];
	//const char* im_dir = argv[2];
	//const char* im_base = argv[3];
	//const char* im_bola = argv[4];

	VS vs;
	
	Mat imageTest1 = imread(argv[1],1);
	//Mat imageTest2 = imread(argv[2],1);
  
	
// 	bool ok = vs.detect_trave(imageTest1);
// 	if(ok)
//    	    cout << "dif_traves: " << vs.dif_traves << endl;	
	
	
	
//  	bool ok = vs.detect_gol(imageTest1);

//  	if(ok)
//     	   cout << "dif_traves: " << vs.tamanho_gol << endl;	
//  	   cout << "rhot1: " << vs.trave1x << endl;	
//  	   cout << "rhot2: " << vs.trave2x << endl;	

// 	 bool ok = vs.detect_base(imageTest1);
// 	 if(ok)
//     	   cout << "ang_base: " << vs.theta_base << " grau: " << vs.theta_base*180/CV_PI << endl;	

	 imshow("frame_atual",imageTeste1);
	 bool ok = vs.detect_bola(imageTeste1, CIMA);
    	 if(ok)
	 {
	   cout << "lado_bola: " << vs.lado_bola << endl;
	   cout << "dist_bola_nao: " << vs.dist_bola_nao << "\n" << endl;
	 }
	 waitKey(0);
	
	return 0;
}