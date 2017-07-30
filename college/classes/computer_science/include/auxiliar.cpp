#include "auxiliar.hpp"

/* Remove noise by blurring with a Gaussian filter
    blur( src, src, Size(3,3));
    GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    cvtColor( src, gray, CV_RGB2GRAY );
 
    /// Apply Laplace function
    Laplacian( gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( dst, abs_dst );
    imshow( "result", abs_dst );*/



void equalizeHistogram(Mat& src, Mat& equalizada){
  if(src.channels() == 3){
    Mat planes[3], im_b, im_g, im_r;
    vector<Mat> channels;
    split(src,planes); 
    equalizeHist( planes[0], im_b);
    equalizeHist( planes[1], im_g);
    equalizeHist( planes[2], im_r);

    channels.push_back(im_b);
    channels.push_back(im_g);
    channels.push_back(im_r);

    merge(channels, equalizada);
    return;
  }

	//cvtColor(src, src, CV_BGR2GRAY);
	/// Apply Histogram Equalization
  	equalizeHist( src, equalizada);
}

void blurImage(Mat& src, Mat& dest, int size, int type){
    if(type == BLUR)
      blur( src, dest, Size(size, size));  
    else if(type == GAUSSIAN_BLUR)
      GaussianBlur(src, dest, Size(size,size), 0, 0, BORDER_DEFAULT);
    else if(type == MEDIAN_BLUR){
      if(size%2==0)  size++;
      medianBlur( src, dest, size );
    }
}

Mat getHSV(Mat& src){
    Mat imagemHSV,binaria;
    //encounterrar bola
    //int H_MIN = 0;
    //int H_MAX = 256;
    //int S_MIN = 185;
    //int S_MAX = 256;
    //int V_MIN = 190;
    //int V_MAX = 256;

    //encounterrar ponta
    int H_MIN = 0;
    int H_MAX = 180;
    int S_MIN = 0;
    int S_MAX = 255;
    int V_MIN = 0;
    int V_MAX = 30;

    cvtColor(src,imagemHSV,  CV_BGR2HSV);
    inRange(imagemHSV,Scalar(H_MIN,S_MIN,V_MIN),Scalar(H_MAX,S_MAX,V_MAX),binaria);

    return binaria;
}

void drawLine(Mat& ori ,float& rho, float& theta, Point& p1, Point& p2, vector<Vec2f> lines, size_t counter){
    double a,b,x0,y0;

    rho = lines[counter][0]; 
    theta = lines[counter][1];
    a = cos(theta), b = sin(theta);
    x0 = a*rho, y0 = b*rho;
    p1.x = cvRound(x0 + 1000*(-b));
    p1.y = cvRound(y0 + 1000*(a));
    p2.x = cvRound(x0 - 1000*(-b));
    p2.y = cvRound(y0 - 1000*(a));
    line( ori, p1, p2, Scalar(0,0,255), 3, CV_AA);
}

void drawLines(Mat& ori, vector<Vec2f> lines, int thick){
    double a,b,x0,y0;
    float rho,theta;
    Point p1,p2;

    for(int i=0;i < lines.size();i++){
      rho = lines[i][0]; 
      theta = lines[i][1];
      a = cos(theta), b = sin(theta);
      x0 = a*rho, y0 = b*rho;
      p1.x = cvRound(x0 + 1000*(-b));
      p1.y = cvRound(y0 + 1000*(a));
      p2.x = cvRound(x0 - 1000*(-b));
      p2.y = cvRound(y0 - 1000*(a));
      line( ori, p1, p2, Scalar(0,0,255), thick, CV_AA);
    }
}

Mat getRed(Mat& src){
	Mat planes[3];
	split(src,planes);  // planes[2] is the red channel

	return planes[2];
}

Mat getGreen(Mat& src){
  Mat planes[3];
  split(src,planes);  // planes[2] is the red channel

  return planes[1];
}

Mat getBlue(Mat& src){
  Mat planes[3];
  split(src,planes);  // planes[2] is the red channel

  return planes[0];
}

Mat thresBinary(Mat& src, int value){
	Mat limiarizada;
	cvtColor(src, src, CV_BGR2GRAY);

	//threshold( src, dest, limiar, limite_max, tipo);
	threshold( src, limiarizada, value, 255, 0 );

	return limiarizada;
}

Mat thresOtsu(Mat& src, double& thre){
	Mat limiarizada;
	if(src.channels() == 3)
    cvtColor(src, src, CV_BGR2GRAY);

	//threshold( src, dest, limiar, limite_max, tipo);
	thre = threshold( src, limiarizada, 0, 255, 
		             CV_THRESH_BINARY | CV_THRESH_OTSU);

	return limiarizada;
}

void erode_dilate(Mat& src, Mat& morf, int operation, int elem, int size){
	int type;
	if( elem == 10 ){ type = MORPH_RECT; }
  	else if( elem == 11 ){ type = MORPH_CROSS; }
  	else if( elem == 12) { type = MORPH_ELLIPSE;}

  	Mat elem_estru = getStructuringElement( type,Size( size,size));

  	//erode_dilate(src, dst, elem_estru, ponto_ancora, 
  	//nro_vezes, tipo_borda, valor_borda)
  	if(operation == ERODING){
  		erode(src, morf, elem_estru);
  	}else if(operation == DILATING){
  		dilate(src, morf, elem_estru);
  	}
}

Mat otherMorph(Mat& src, int operation, int size){
	Mat morf;
	int elem = 2;

  // Já que MORPH_X : 2,3,4,5 e 6
  //MORPH_OPEN - an opening operation
  //MORPH_CLOSE - a closing operation
  //MORPH_GRADIENT - a morphological gradient
  //MORPH_TOPHAT - “top hat”
  //MORPH_BLACKHAT - “black hat”

  int type;
	if( elem == 0 ){ type = MORPH_RECT; }
  	else if( elem == 1 ){ type = MORPH_CROSS; }
  	else if( elem == 2) { type = MORPH_ELLIPSE;}

  	Mat elem_estru = getStructuringElement( type, 
  		          Size( 2*size + 1, 2*size+1 ));

  	//morphologyEx(src, dst, operation, elem_estru, ponto_ancora, 
  	//nro_vezes, tipo_borda, valor_borda)
  	morphologyEx( src, morf, operation, elem_estru);

  	return morf;
}

//linear (negative and identity transformations), 
//logarithmic ( log and inverse log transformations ),
//power law (nth power and nth root transformation).

//insira src BGR e um valor de correção gamma
Mat correctGamma(Mat& src) {
 	Mat corrigida;
  double gamma= 2.2;
 	double inverse_gamma = 1.0 / gamma;
 
	Mat lut_matrix(1, 256, CV_8UC1 );
 	uchar* ptr = lut_matrix.ptr();
 	for( int i = 0; i < 256; i++ )
   		ptr[i] = (int)( pow( (double) i / 255.0, inverse_gamma ) * 255.0 );
 
 	LUT( src, lut_matrix, corrigida);
 
 	return corrigida;
}

Mat contoursImage(Mat& bordas){
  vector<vector<Point> > counterours;
  vector<Vec4i> hierarchy;

  /// Find contours
  findContours( bordas, counterours, hierarchy, 
                CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, 
                Point(0, 0));

  /// Draw counterours
  Mat resultado = Mat::zeros( bordas.size(), CV_8UC3 );
  for( int i = 0; i< counterours.size(); i++ )
     {
       //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       Scalar color = Scalar(255,255,255);
       drawContours( resultado, counterours, i, color, 1.2, 8, hierarchy, 0, Point() );
     }

  return resultado;
}

void tipXY(Mat& src, Mat& otsu_image, Point& p1, Point& p2, float& rho1, float& rho2){
  int maior_valor = 0;
  int counterador = 0;
  int blue,green,red,metade,otsu;
  //int dist = (int) abs(rho1 - rho2);
  
  //fazer esta operação só na linha!
  Mat hsv_image = getHSV(src);
  blur( hsv_image, hsv_image, Size(15, 15));
  imshow("hsv", hsv_image);

  LineIterator it(src, p1, p2, 8);

  vector<Vec3b> buf;   
  vector<Point> points;  

  for(int i=0; i<it.count; i++)
  {
      buf.push_back(Vec3b(*it));
      points.push_back(it.pos());

      it++;
      //cout << points[i] << endl;
  }

  //metade = points.size()/2;

  for(int i=30; i < points.size()-30; i=i+5)
  { 
    blue = src.at<Vec3b>(points[i])[0];
    green = src.at<Vec3b>(points[i])[1];
    red = src.at<Vec3b>(points[i])[2];
    otsu = otsu_image.at<uchar>(points[i]);

    if(blue>100 && blue<200 && green>100 && green<200 && red>100 && red<200 && otsu == 255){
          circle( src, points[i], 3, Scalar(0,0,255), 3, 8, 0 );
          circle( src, points[i], 15, Scalar(0,0,255), 3, 8, 0 );
          break;
    }
  }
}

void tipXY2(Mat& src, Mat& dest, Point& p1, Point& p2){

  LineIterator it(src, p1, p2, 8);

  vector<Vec3b> buf;   
  vector<Point> points;  

  for(int i=0; i<it.count; i++)
  {
      buf.push_back(Vec3b(*it));
      points.push_back(it.pos());

      it++;
      //cout << points[i] << endl;
  }

  for(int i=1; i<points.size() - 1; i++)
  {
    if((src.at<uchar>(points[i-1]) - src.at<uchar>(points[i+1])) > 30){
      //src.at<Vec3b>(buf[i])[0] = 0;
      //src.at<Vec3b>(buf[i])[1] = 0;
      //src.at<Vec3b>(buf[i])[2] = 255;
      ellipse( dest,
           points[i],
           Size( 5, 3),
           0,
           0,
           360,
           Scalar( 255, 0, 0 ),
           1,
           8);
      break;

    }
  }
}

void tipXY3(Mat& src, Mat& gray_image, Point& p1, Point& p2, Point& p3, Point& p4){
  int vl1,vl2;
  Point ptm;

  LineIterator it1(src, p1, p2, 8);
  LineIterator it2(src, p3, p4, 8);

  vector<Point> points1;  
  vector<Point> points2;  

  for(int i=0; i<it1.count; i++)
  {
      points1.push_back(it1.pos());
      it1++;
  }

  for(int i=0; i<it2.count; i++)
  {
      points2.push_back(it2.pos());
      it2++;
  }

  //metade = points.size()/2;

  for(int i=0; i < points1.size(); i++)
  { vl1 = gray_image.at<uchar>(points1[i]);
    vl2 = gray_image.at<Vec3b>(points2[i])[1];
  
    if(vl1 == 255 && vl2 == 255){
          ptm.x = (points1[i].x + points2[i].x)/2;
          ptm.y = (points1[i].y + points2[i].y)/2;

          circle( src, ptm, 3, Scalar(0,0,255), 3, 8, 0 );
          circle( src, ptm, 15, Scalar(0,0,255), 3, 8, 0 );
          break;
    }
  }
}

//diferença maxima entre as componentes de cor menor que value
//recebia video3 normal
Mat GTransform(Mat& src, int value){
  Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
  
  for(int i=0; i<src.cols; i++){
    for(int j=0; j<src.rows; j++){
      int b = src.at<Vec3b>(j,i)[0];
      int g = src.at<Vec3b>(j,i)[1];
      int r = src.at<Vec3b>(j,i)[2];

      int v1 = abs(b - g);
      int v2 = abs(g - r); 
      //int v3 = (b+g+r)/3;

      if( v1 <= value && v2 <= value && r < 100)
        dst.at<uchar>(j,i) = 0;
      else
        dst.at<uchar>(j,i) = 255;
    }
  }
  return dst;
}

//se r é menor que value e r é menor que as outras componentes
//recebe a original equalizada
Mat filterEqualizedBest(Mat& src, int value){
  Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
  
  for(int i=0; i<src.cols; i++){
    for(int j=0; j<src.rows; j++){
      int b = src.at<Vec3b>(j,i)[0];
      int g = src.at<Vec3b>(j,i)[1];
      int r = src.at<Vec3b>(j,i)[2];

      if(r < value && r <= g && r <= b)
        dst.at<uchar>(j,i) = 0;
      else
        dst.at<uchar>(j,i) = 255;
    }
  }
  return dst;
}

//calcula desvio padrão
//usada na original
double standartDevRed(Mat& src){
   Scalar mean, stddev;
   meanStdDev(src, mean, stddev);
   return (double) stddev.val[2];;
}

//derivada com restrições de thre minimo e intensidade máxima
//usada no plano vermelho equalizado
Mat RedBorder(Mat& src, int low_der, int high_red){
  if(src.channels() == 3){
    cout << "\nRedBorderError: not in GrayScale.." << endl;
    //exit();
  }

  Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
  
  for(int i=0; i<src.cols-1; i++){
    for(int j=0; j<src.rows-1; j++){
      int pass_red = src.at<uchar>(Point(i,j));
      int future_hori = src.at<uchar>(Point(i+1,j));
      int future_vert = src.at<uchar>(Point(i,j+1));

      if(pass_red < high_red && (abs(pass_red - future_hori) >= low_der || abs(pass_red - future_vert) >= low_der))
        dst.at<uchar>(j,i) = 255;
    }
  }

  return dst;
}

//derivada com restrições de thre minimo , intensidade máxima
//e vermelho menor que as outras componentes
//usada na original equalizada
Mat RedBorderOpt(Mat& src, int low_der, int high_red){
  if(src.channels() == 1){
    cout << "\nRedBorderOptError: not 3 channel image.." << endl;
    //exit();
  }

  Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
  
  for(int i=0; i<dst.cols-1; i++){
    for(int j=0; j<dst.rows-1; j++){
      int pass_red = src.at<Vec3b>(Point(i,j))[2];
      int pass_green = src.at<Vec3b>(Point(i,j))[1];
      int pass_blue = src.at<Vec3b>(Point(i,j))[0];
      int future_hori = src.at<Vec3b>(Point(i+1,j))[2];
      int future_vert = src.at<Vec3b>(Point(i,j+1))[2];

      if(pass_red < high_red && pass_red <= pass_green && 
        pass_red <= pass_blue && 
        (abs(pass_red - future_hori) >= low_der 
          || abs(pass_red - future_vert) >= low_der))
        dst.at<uchar>(j,i) = 255;
    }
  }

  return dst;
}

Mat RedBorderOptAuto(Mat& src, int high_red){
  high_red = 60;

  if(src.channels() == 1){
    cout << "\nRedBorderOptAutoError: not 3 channel image.." << endl;
    //exit();
  }

  Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
  int low_der = 6;

  for(int i=0; i<dst.cols-1; i++){
    for(int j=0; j<dst.rows-1; j++){
      int pass_red = src.at<Vec3b>(Point(i,j))[2];
      int pass_green = src.at<Vec3b>(Point(i,j))[1];
      int pass_blue = src.at<Vec3b>(Point(i,j))[0];
      int future_hori = src.at<Vec3b>(Point(i+1,j))[2];
      int future_vert = src.at<Vec3b>(Point(i,j+1))[2];

      if(pass_red < high_red && pass_red <= pass_green && 
        pass_red <= pass_blue && 
        (abs(pass_red - future_hori) >= low_der 
          || abs(pass_red - future_vert) >= low_der))
        dst.at<uchar>(j,i) = 255;
        //circle( dst, Point( i,j), 3.0, Scalar( 255, 255, 255 ), 3, 8 );
    }
  }

  return dst;
}

Mat RedBorderOptAuto2(Mat& src, int high_pixel){
  high_pixel = 200;
  Mat dst(src.size(), src.type());
  src.copyTo(dst);

  if(src.channels() == 1){
    cout << "\nRedBorderOptAutoError: not 3 channel image.." << endl;
    //exit();
  }

  for(int i=0; i<dst.cols-1; i++){
    for(int j=0; j<dst.rows-1; j++){
      int red = src.at<Vec3b>(Point(i,j))[2];
      int green = src.at<Vec3b>(Point(i,j))[1];
      int blue = src.at<Vec3b>(Point(i,j))[0];
      
      if(red+green+blue > high_pixel)
        dst.at<Vec3b>(Point(i,j))[2] = 255;
        dst.at<Vec3b>(Point(i,j))[1] = 255;
        dst.at<Vec3b>(Point(i,j))[0] = 255;
        //dst.at<Vec3b>(Point(i,j)) = Scalar(255,255,255);
    }
  }

  return dst;
}


void std2HighRed(double formal_stdDev,int& formal_redMax){
  formal_redMax = (int) (1760 - 6*formal_stdDev)/76;
}

void showHistogram(Mat& src)
{
  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  /// Establish the number of bins
  int histSize = 256;

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  /// Compute the histograms:
  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

  // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /// Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize; i++ )
  {
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                       Scalar( 255, 0, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                       Scalar( 0, 255, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                       Scalar( 0, 0, 255), 2, 8, 0  );
  }

  /// Display
  namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
  imshow("calcHist Demo", histImage );
}