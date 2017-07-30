1. Proxies (procurador)
-> ALMotion		(funções de movimento)
-> ALTextToSpeech 	(funções de voz)
-> ALVideoDevice	(funções com imagem/vídeo)

Uma vez criados, dão acesso direto a métodos já existentes.

#include <alproxies/altexttospeechproxy.h>
AL::ALTextToSpeechProxy fTtsProxy(argv[1], 9559); //argv[1] = robot IP
fTtsProxy.say("Hello world!");

2. Stiffness (rigidez)
-> Antes de usar/aplicar funções de movimento, deve-se setar a rigidez das articulações do robô.
-> proxy ALMotion

#include <alproxies/almotionproxy.h>
AL::ALMotionProxy motion(argv[1], 9559);
AL::ALValue jointNames 	= AL::ALValue::array("Body");
float stiffnessLists 	= 1.0f;
float timeLists		= 1.0f;
motion.stiffnessInterpolation(	jointNames, 	//nome da articulação ("Body"=todas as articulações)
			    stiffnessLists, 
				timeLists);

3. Joints Movement (Movimentar articulações)
-> função ALMotion::angleInterpolation
-> Interpola uma ou múltiplas articulações a um ângulo alvo ou ao longo de trajetórias temporizadas.
-> Escolhida entre outras pois pode ser interrompida antes de acabar (blocking call).

//Único alvo para uma articulação
AL::ALValue names 	= "HeadYaw";
AL::ALValue angleLists  = 1.0f;	//radianos
AL::ALValue timeLists   = 1.0f;
bool isAbsolute		= true;
std::cout << "Step 1: single target angle for one joint" << std::endl;
motion.angleInterpolation(names, angleLists, timeLists, isAbsolute);

//Vários ângulos múltiplas articulações
AL::ALValue	jointNames = AL::ALValue::array("LShoulderPitch","LShoulderRoll", "LElbowYaw", "LElbowRoll");
AL::ALValue 	angles = AL::ALValue::array(-40.0f * AL::Math::TO_RAD,  // "LShoulderPitch"
					    +25.0f * AL::Math::TO_RAD,  // "LShoulderRoll"
					    +00.0f * AL::Math::TO_RAD,  // "LElbowYaw"
					    -40.0f * AL::Math::TO_RAD); // "LelbowRoll"
motion.angleInterpolationWithSpeed(jointNames, angles, 0.6f);

4. Walking (andar)
-> função ALMotion::moveTo
-> NAO se move para a dada posição no plano da terra, relativo ao FRAME_ROBOT.
-> Pode ser interrompida (blocking call).

float x 	= 0.2f;			//frente/tras em metros
float y 	= 0.2f;			//esquerda/direita em metros
// pi/2 anti-clockwise (90 degrees)	
float theta 	= 1.5709f;		//rotação eixo Z em radianos
motion.moveTo(x, y, theta);

5. Opening and Closing Hands (Abrir e fechar de mãos)
-> função ALMotion::openHand(handName), porém após execução, seta stiffness pra 0.
-> função ALMotion::angleInterpolationWithSpeed

std::string handName	= "LHand";
float maxSpeedFraction 	= 0.5f;			// half of max speed
motion.angleInterpolationWithSpeed(	handName, 
					     1.0,
			       maxSpeedFraction);

6. Getting Image (Obter imagem)
-> proxies ALVideoDevice, ALImage e ALVisionDefinitions
-> Bibliotecas OpenCV

// Aldebaran includes.
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
#include <alvision/alvisiondefinitions.h>
#include <alerror/alerror.h>

// Opencv includes.
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

CvMemStorage* storage = cvCreateMemStorage(0);

/** Create a proxy to ALVideoDevice on the robot.*/
ALVideoDeviceProxy camProxy(robotIp, 9559);

/** Subscribe a client image requiring 320*240 and BGR colorspace.*/
const std::string  clientName = camProxy.subscribe("test", kQVGA,kBGRColorSpace, 30); //The lowest quality will be used for better performance

/** Create an cv::Mat header to wrap into an opencv image.*/
cv::Mat imgHeader = cv::Mat(cv::Size(320, 240), CV_8UC3);

/** Create a OpenCV window to display the images. */
cv::namedWindow("images");

while (true){
  ALValue img = camProxy.getImageRemote(clientName);
  
  /** Access the image buffer (6th field) and assign it to the opencv image container. */
  imgHeader.data = (uchar*) img[6].GetBinary();

  /** Tells to ALVideoDevice that it can give back the image buffer to the driver. Optional after a getImageRemote but MANDATORY
   * after a getImageLocal.*/
  camProxy.releaseImage(clientName);

  /** Display the iplImage on screen.*/
  imshow("images", imgHeader);
}
/** Cleanup.*/
camProxy.unsubscribe(clientName);

7. Changing camera (Trocar câmera)
-> camProxy.setParam(	kCameraSelectID,	//valor fixo
				    ID);	//0 (câmera de cima) ou 1 (câmera de baixo)

8. Shape Detection (Detectar formas)
-> cvtColor (RGB2gray) - Canny() - findContours()

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>Mat img_rgb,img_gray,canny_output,drawing;

int thresh = 100;
int max_thresh = 255;

ALValue img = camProxy.getImageRemote(clientName);
imgHeader.data = (uchar*) img[6].GetBinary();
cvtColor(imgHeader,img_gray,CV_RGB2GRAY);

void drawStuff(){
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  Canny( img_gray, canny_output, thresh, thresh*2, 3 );
  imshow("Canny",canny_output);
  findContours(canny_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
  drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  imshow("Triangles",drawing);
}

-> Para desenhar as formas, defina o número de lados que sua forma tem com approxShape.size().

vector<Point> approxShape;

for(size_t i = 0; i < contours.size(); i++){
  approxPolyDP(contours[i],approxShape,arcLength(Mat(contours[i]),true)*0.05, true);

  if(approxShape.size() == 3){
    drawContours(img,contours, i, Scalar(0, 255, 255), CV_FILLED);
    vector<Point>::iterator vertex;
    
    for(vertex = approxShape.begin(); vertex != approxShape.end(); ++vertex){
      circle(img, *vertex, 3, Scalar(0, 0, 255), 1);}
    }
}

9. Color Detection (detectar cor)

static int posX, posY, lastX, lastY;  //To hold the X and Y position of tracking color object

Mat rgbCameraFrames; //Matrix to hold Raw frames from Camera in RGB color space
Mat colorTrackingFrames; //Matrix to hold color filtered Frames in GRAY color space
Mat resutantFrame; //Matrix to add RAW and user scribble Frames
CvMoments colorMoment; //Structure to hold moments information and their order
GaussianBlur(rgbCameraFrames, colorTrackingFrames, Size(11, 11), 0, 0); //Just a filter to reduce the noise
inRange(colorTrackingFrames,Scalar(0,0,115),Scalar(50,50,255),colorTrackingFrames);


colorMoment = moments(colorTrackingFrames);	//We give the binary converted frames for calculating the moments

double moment10 = cvGetSpatialMoment(&colorMoment, 1, 0);  //Sum of X coordinates of all white pixels 
double moment01 = cvGetSpatialMoment(&colorMoment, 0, 1);  //Sum of Y coordinates of all white pixels 
double area = cvGetCentralMoment(&colorMoment, 0, 0); //Sum of all white color pixels

lastX = posX;
lastY = posY;
posX = (moment10 / area);
posY = moment01 / area;

10. Color Range (range de cores
  
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
  Mat src = imread("3colors.png");
  int rh = 255, rl = 0, gh = 255, gl = 0, bh = 255, bl = 0;
  
  string windowName = "background";
  namedWindow(windowName);
  createTrackbar("rh", windowName, &rh, 255);
  createTrackbar("rl", windowName, &rl, 255);
  createTrackbar("gh", windowName, &gh, 255);
  createTrackbar("gl", windowName, &gl, 255);
  createTrackbar("bh", windowName, &bh, 255);
  createTrackbar("bl", windowName, &bl, 255);

  // for dilation
  Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));

  Mat bgIsolation;
  int key = 0;
  
  do
  {
    inRange(src, Scalar(bl, gl, rl), Scalar(bh, gh, rh), bgIsolation);
    imshow(windowName, bgIsolation);
    key = waitKey(33);
  } while((char)key != 27);
    
  waitKey();
  return 0;
}

-> P/ compilar: g++ -ggdb `pkg-config --cflags opencv` RangeFinder.cpp .cpp` RangeFinder.cpp `pkg-config --libs opencv`

11. Threads
-> Rodar blocos em paralelo com a main
-> Se for Thread Safe, pode fazer sem problemas

void *threadFunc(void *threadid){
    //do something
}

int main(int argc, char* argv[]){
  pthread_t threads;
  //...
  pthread_create(&threads, NULL, threadFunc, (void *)variable);
  //...
}

