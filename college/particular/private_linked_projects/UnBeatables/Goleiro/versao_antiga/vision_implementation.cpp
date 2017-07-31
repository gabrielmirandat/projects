#include "vision_implementation.hpp"

//constructor
VS::VS()
{
    rho_base = theta_base = 0.0; 
    dif_traves = 0.0;
    lado_bola = 0.0;
    dist_bola_nao = INFINITO;
}

//destructor
VS::~VS()
{
}

bool VS::detect_trave(Mat& im)
{
    dif_traves = 0.0;
    int achou = 0;
    vector<Vec2f> lines;
    Mat src,dst,cdst;
    size_t i,j;   //escolha das duas linhas
    float rho1, rho2, theta1, theta2;
    rho1 = rho2 = theta1 = theta2 = 0.0;

    src = im;
    
    if(src.empty())
    {
      return false;
    }

    //Canny(src, dst, 89, 272, 3);	goleiro
    Canny(src, dst, 270, 600, 3);
    remove_bordas(dst);
    cvtColor(dst, cdst, CV_GRAY2BGR);

    //HoughLines(/*image*/dst,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 60, 0, 0 );	goleiro
    HoughLines(/*image*/dst,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 80, 0, 0 );	//60

    
    achou = 0;
    for(i = 0; i < lines.size(); i++ )
    { 
      if( (lines[i][1]>CV_PI/180*15 && lines[i][1]<CV_PI/180*165))
      {
        continue;
      }
      //armazena rho1 e theta1 e mostra a linha na tela 
      achou = 1;
      rho1 = lines[i][0]; 
      theta1 = lines[i][1];
      #ifdef REMOTE
        desenha_linha(cdst, rho1, theta1);
      #endif
      break;
    }
    
    i++;
    j=i;
    if(achou == 1)
    {
      for(i = j; i < lines.size(); i++ )
      {
        if((lines[i][1]>CV_PI/180*15 && lines[i][1]<CV_PI/180*165))
        {
          continue;
        }

        if(abs(lines[i][0] - rho1) > 5.0/*linhas próximas*/ && abs(lines[i][1] - theta1) < 0.087 /*~5graus*/)
        {
          //armazena rho2 e theta2
          achou = 2;
          rho2 = lines[i][0]; 
          theta2 = lines[i][1];
                
          dif_traves = abs(rho1  - rho2);

          #ifdef REMOTE
            desenha_linha(cdst, rho2, theta2);
            imshow("resultado",cdst);
          #endif
          return true;
	      }
      }
    }
    
    #ifdef REMOTE
      cout << "trave não encontrada." << endl;
    #endif
    return false;
}



bool VS::detect_base(Mat& im)
{
    rho_base = theta_base = 0.0; 
    float rho_escolhido, theta_escolhido;
    rho_escolhido = 0.0;
    int achou = 0;
    Mat dst, cdst;
    vector<Vec2f> lines;

    Mat src = im;
  
    if(src.empty())
    {
        return false;
    }

    Canny(src, dst, 89, 272, 3);
    remove_bordas(dst);
    cvtColor(dst, cdst, CV_GRAY2BGR);

    HoughLines(/*image*/dst,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 100, 0, 0 );

    for( size_t i = 0; i < lines.size(); i++ )
    {
      if( (lines[i][1]>CV_PI/180*45 && lines[i][1]<CV_PI/180*135))
      {
        float rho = lines[i][0], theta = lines[i][1];
        if(rho > rho_escolhido)
        {
          rho_escolhido = rho;
          theta_escolhido = theta;
          achou = 1;
        }
      }
    }
 
    if(achou == 1)
    {
      rho_base = rho_escolhido;
      theta_base = (theta_escolhido - CV_PI/2) /**180/CV_PI*/;
      #ifdef REMOTE
        desenha_linha(cdst, rho_escolhido, theta_escolhido); 
        imshow("result",cdst);
      #endif
      return true;
    }
    #ifdef REMOTE
      cout << "base não encontrada." << endl;
    #endif
    return false;
}

bool VS::detect_bola(Mat& im, int camera)
{
    lado_bola = 0.0;
    dist_bola_nao = INFINITO;
    Mat src, hsv_image, hsv_gray, hsv_comparador, detec_final, teste;
    int raio_escolhido;
    int achou= 0;
    Point centro_escolhido;

    /// Read the image
    src = im;

    if(src.empty())
    {
      return false;
    }
    
    //-- camera BAIXO
    //int H_MIN = 5;
    //int H_MAX = 31;
    //int S_MIN = 182;
    //int S_MAX = 230;
    //int V_MIN = 0;
    //int V_MAX = 255;
  
    //-- camera CIMA
    //int H_MIN = 0;
    //int H_MAX = 26;
    //int S_MIN = 151;
    //int S_MAX = 228;
    //int V_MIN = 12;
    //int V_MAX = 255;
  
    cvtColor(src,hsv_image,  CV_BGR2HSV);

    if(camera == BAIXO)
      inRange(hsv_image,Scalar(5,182,0),Scalar(31,230,255),hsv_gray);		//-- camera de baixo
    else if(camera == CIMA)
      inRange(hsv_image,Scalar(0,151,12),Scalar(26,228,255),hsv_gray);	//-- camera de cima

    //morphological closing (removes small holes from the foreground)
    erode(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    dilate(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
  
    dilate(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));
    erode(hsv_gray, hsv_gray, getStructuringElement(MORPH_ELLIPSE, Size(3,3)));

    blur( hsv_gray, hsv_comparador, Size(7, 7));

    cvtColor(hsv_comparador,detec_final,  CV_GRAY2BGR);
  
    vector<Vec3f> circles;
  
    int dp = 2; 			          //The inverse ratio of resolution
    int min_dist = src.rows/4; 	//Minimum distance between detected centers
    int param_1 = 160; 		      //Upper threshold for the internal Canny edge detector
    int param_2 = 10; 		      //Threshold for center detection.
    int min_radius = 3; 		    //Minimum radius to be detected. If unknown, put zero as default.
    int max_radius = 200; 	    //Maximum radius to be detected. If unknown, put zero as default


    //apply the Hough Transform to detect circles
    HoughCircles(hsv_gray,circles,CV_HOUGH_GRADIENT,dp,min_dist,param_1,param_2,min_radius,max_radius);
	
    /// Escolhe melhor circulo
    for( size_t i = 0; i < circles.size(); i++ )
    {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);

      if(center.x > 0 && center.y > 0 && center.x < src.cols && center.y < src.rows)
      {
	      if(camera == CIMA && center.y < src.rows*0.3 )	//0.3
	        continue;
	
	        int centro = hsv_comparador.at<uchar>(center);
          float verm = src.at<Vec3b>(center)[2];    //vermelho
          float azul = src.at<Vec3b>(center)[0];    //azul

          if(centro >= 100 &&  verm/azul > 5.0 && verm/azul < 9.0)
          {
	          #ifdef REMOTE
              cout << "centro   .:" << centro << endl;
              cout << "verm/azul.:" << verm/azul << endl;
            #endif
            raio_escolhido = radius;
	          centro_escolhido = center;
	          achou = 1;
	          break;
	        }
        }
      }
      
    if(achou == 1)
    {
      #ifdef REMOTE
        cout << "qtd encont.: " << circles.size()  << "\n" << endl;
        circle(detec_final, centro_escolhido, raio_escolhido, Scalar(0,0,255), 1, 8, 0 );	
        imshow("resposta",detec_final);
      #endif
      
      //-- esquerda = negativo, direita = positivo
      lado_bola = centro_escolhido.x - src.cols/2;
    
      if(camera == CIMA)
        dist_bola_nao = posY2DistanceTop(centro_escolhido.y);
      else if (camera == BAIXO)
        dist_bola_nao = posY2DistanceBottom(centro_escolhido.y);
    
      return true;
    }
    #ifdef REMOTE
      cout << "bola não encontrada." << endl;
    #endif
    return false;
}

bool VS::detect_gol(Mat& im)
{
    int achou = 0;
    vector<Vec2f> lines;
    Mat src,dst,cdst;
    size_t i,j;   //escolha das duas linhas
    float rho1, rho2, theta1, theta2;
    rho1 = rho2 = theta1 = theta2 = 0.0;

    src = im;
    int tam_gol = src.cols/6;
    
    if(src.empty())
    {
        return false;
    }

    //Canny(src, dst, 89, 272, 3);	goleiro
    Canny(src, dst, 212, 420, 3);	//212
    remove_bordas(dst);
    cvtColor(dst, cdst, CV_GRAY2BGR);

    //HoughLines(/*image*/dst,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 60, 0, 0 );	goleiro
    HoughLines(/*image*/dst,/*lines*/lines,/*rho*/ 1, /*theta*/CV_PI/180,/*threshold*/ 60, 0, 0 );

    for(i = 0; i < lines.size(); i++ )
    { 
      if( (lines[i][1]>CV_PI/180*5 && lines[i][1]<CV_PI/180*175))
      {
        continue;
      }
      //armazena rho1 e theta1 e mostra a linha na tela 
      achou = 1;
      rho1 = lines[i][0]; 
      theta1 = lines[i][1];
      #ifdef REMOTE
        desenha_linha(cdst ,rho1, theta1);
      #endif
      break;
    }
    
    if (achou == 1)
    {
      for(j = i; j < lines.size(); j++ )
      {
        if( lines[j][1]>CV_PI/180*5 && lines[j][1]<CV_PI/180*175)
	        continue;
	
	      if(abs(lines[j][0] - rho1) > tam_gol)
        {
	        achou = 2;
	        rho2 = lines[j][0];
	        theta2 = lines[j][1];

	        #ifdef REMOTE
	          desenha_linha(cdst ,rho2, theta2);
            imshow("resultado",cdst);
	        #endif
	  
	        trave1x = rho1;
          trave2x = rho2;
          tamanho_gol = abs(rho1 - rho2);
          
          return true;
        }
      }
    }
    #ifdef REMOTE
      cout << "gol não encontrado." << endl;
    #endif
    return false;
}

float VS::posY2DistanceBottom (int posY)
{
    float result = -0.0000049753*posY*posY*posY + 0.0029*posY*posY - 0.7576*posY + 94.3995;
    return result;
}

float VS::posY2DistanceTop (int posY)
{
    float result = -0.000237*posY*posY*posY + 0.1418*posY*posY - 28.9862*posY + 2122.2;
    return result;
}

void VS::remove_bordas(Mat& im)
{
    for(int i=0; i< im.cols;i++){
      im.at<uchar>(0,i) = 0;
      im.at<uchar>(im.rows-1,i) = 0;
    }

    for(int i=0; i< im.rows;i++){
      im.at<uchar>(i,0) = 0;
      im.at<uchar>(i,im.cols-1) = 0;
    }
}

void VS::desenha_linha(Mat& ori ,float& rho, float& theta)
{
    Point p1,p2;
    double a,b,x0,y0;
    a = cos(theta), b = sin(theta);
    x0 = a*rho, y0 = b*rho;
    p1.x = cvRound(x0 + 1000*(-b));
    p1.y = cvRound(y0 + 1000*(a));
    p2.x = cvRound(x0 - 1000*(-b));
    p2.y = cvRound(y0 - 1000*(a));
    line( ori, p1, p2, Scalar(0,0,255), 3, CV_AA);
}