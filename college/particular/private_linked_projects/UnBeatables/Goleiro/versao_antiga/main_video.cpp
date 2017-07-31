#include "vision_implementation.hpp"

int main(int argc, char** argv)
{
	VS vs;
	
	VideoCapture cap(argv[1]);
	
	if (!cap.isOpened())
	{
	  std::cout << "!!! Failed to open file: " << argv[1] << std::endl;
	  return -1;
	}

	for(;;)
	{
	    Mat frame;
	    if (!cap.read(frame))             
	      break;
	    
	    imshow("frame_atual",frame);
	    
	    //-- teste de detecção de trave
   	    bool ok = vs.detect_trave(frame);
   	    if(ok)
   	    {
      		cout << "dif_traves: " << vs.dif_traves << endl;	
		}
	
/*	
		//-- teste de detecção de gol	
  	    bool ok = vs.detect_gol(frame);
  	    if(ok)
     	{
     		cout << "dif_traves: " << vs.tamanho_gol << endl;	
	  		cout << "rhot1: " << vs.trave1x << endl;	
  			cout << "rhot2: " << vs.trave2x << endl;	
  		}

    	//-- teste de detecção de base
		bool ok = vs.detect_base(frame);
   	    if(ok)
        	cout << "ang_base: " << vs.theta_base << " grau: " << vs.theta_base*180/CV_PI << endl;	

        //-- teste de detecção de bola
   	    bool ok = vs.detect_bola(frame, BAIXO);
	    if(ok)
 	    {
   	      cout << "lado_bola: " << vs.lado_bola << endl;
   	      cout << "dist_bola_nao: " << vs.dist_bola_nao << "\n" << endl;
   	    }
*/	    
	    waitKey(0);
	}
	return 0;
}