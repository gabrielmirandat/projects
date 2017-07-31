
/* ANTIGO */
/*
bool VS::detect_bola_1(Mat& im, int camera){
  Mat src, red, red_color, hsv_image;
  Mat planes[3];
  int maior_valor = 0;
  int valor,valor_hsv, maior_valor_hsv;
  int raio_escolhido;
  Point centro_escolhido;
  
  //camera baixo
  int H_MIN = 0;
  int H_MAX = 26;
  int S_MIN = 155;
  int S_MAX = 228;
  int V_MIN = 12;
  int V_MAX = 255;
  
  //camera cima
  //int H_MIN = 0;
  //int H_MAX = 255;
  //int S_MIN = 178;
  //int S_MAX = 255;
  //int V_MIN = 61;
  //int V_MAX = 255;

  /// Read the image
  src = im;

  if( !src.data )
    { return -1; }

  split(src,planes);  // planes[1] is the red channel
  red = planes[2];

  cvtColor(red, red_color, CV_GRAY2BGR);

  imwrite("plano_vermelho.jpg",red_color);
  
  ///Pega a imagem HSV
  cvtColor(src,hsv_image,  CV_BGR2HSV);
  inRange(hsv_image,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),hsv_image);
  blur( hsv_image, hsv_image, Size(15, 15));
  
  imshow("hsv",hsv_image);
  
  /// Reduce the noise so we avoid false circle detection
  GaussianBlur( red, red, Size(3, 3), 2, 2 );

  vector<Vec3f> circles;

  /// Apply the Hough Transform to find the circles
  //HoughCircles( red, circles, CV_HOUGH_GRADIENT, 1, red.rows/8, 200, 100, 0, 0 );
  HoughCircles(  red, circles, CV_HOUGH_GRADIENT, 1, red.rows/4, 140, 30, red.rows/48, red.rows/6);
  
  /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);

      //if(center.x > 0 && center.y > 0 && center.x < red.cols && center.y < red.rows){

         valor = red.at<uchar>(center);
         valor_hsv = hsv_image.at<uchar>(center);
	 
	 circle( red_color, center, radius, Scalar(0,0,255), 3, 8, 0 );
	 imshow("parcial",red_color);
	 waitKey(0);
         
         if(((valor * valor_hsv)) > maior_valor){
             centro_escolhido = center;
             raio_escolhido = radius;
             maior_valor = (valor * valor_hsv);
             maior_valor_hsv = valor_hsv; 
         }
      //}
  }

  #ifdef REMOTE
    //cout << "qtd encont.: " << circles.size() << endl;
    //cout << "maior HSV.: " << maior_valor_hsv << endl;
  #endif

  if(maior_valor_hsv > 40){
    // circle outline
    circle( red_color, centro_escolhido, raio_escolhido, Scalar(0,0,255), 3, 8, 0 );
    //centro_bola = centro_escolhido;
    //raio_bola = raio_escolhido;
    //imshow("hsv",hsv_image);
    imshow("fim",red);
    return true;
  }
  
  return false;
}

*/

