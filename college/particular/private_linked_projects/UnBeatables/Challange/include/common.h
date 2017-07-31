#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/objdetect/objdetect.hpp"

namespace common
{

	enum Entities
	{
		POST,
	    GOAL,
	    ENEMIE,
	    CENTER,
	    BALL,
	    CORNER,
	    INLINE
	};

    const int ENTITIES_SIZE = 7;
    const int VIEWS_SIZE = 4;
    typedef boost::tuple<int,int,int> int_tuple;

    //mudar aqui de acordo com tamanho frame
    const int IMG_HEIGHT = 480;
    const int IMG_WIDTH = 640;
    const int IMG_DIAGONAL = 400;

    const int ROI_HEIGHT = 111;
    const int ROI_WIDTH = 153;



    //real object's sizes in millimeters (width)
    const float WIDTH_WORLD_COORD[] = {				/*POST*/105.0,
                                                    /*GOAL*/1520.0,
                                                    /*ENEMIE*/0.0,
                                                    /*CENTER*/1057.0,
                                                    /*BALL*/120.0,
                                                    /*CORNER*/0.0,
                                                    /*INLINE*/57.0};

    //CAMERA PARAMETERS METHOD (flag defined in makefile)
    const double F_X = 275.84193859; const double F_Y = 275.4397455;
    const double C_X = 164.17096837; const double C_Y = 122.34095676;
    const double M = ((F_X + F_Y)/2);

    //BALL_SIZE_SENSOR = 2*radius/M;
    //BALL_DISTANCE = BALL_SIZE_REAL/BALL_SIZE_SENSOR


    //TRIANGLE METHOD (DEFAULT - more precise)

    //we need default distance to the camera in mm and the correspondent size in pixels
    //rows are the entities and the cols are the camera-angle (top-front, top-bot, bot-front, bot-bot)
    //{POST, GOAL, ENEMIE, CENTER, BALL, CORNER, INLINE}
    const float DEFAULT_OBJ_CAMERA_MM[ENTITIES_SIZE][VIEWS_SIZE] = {
                                               {0,0,0,0},
                                               {0,0,0,0},
                                               {0,0,0,0},
                                               {0,0,0,0},
                                               {1000,1000,300,230},
                                               {0,0,0,0},
                                               {0,0,0,0}};

    const float DEFAULT_OBJ_CAMERA_PX[ENTITIES_SIZE][VIEWS_SIZE] = {
                                               {0,0,0,0},
                                               {0,0,0,0},
                                               {0,0,0,0},
                                               {0,0,0,0},
                                               {31,30,64,78},
                                               {0,0,0,0},
                                               {0,0,0,0}};

	// const float PER_OBJECT_FOCAL_LENGHT[] = {
	// 	/*POST*/	(DEFAULT_OBJ_CAMERA_PX[POST] * DEFAULT_OBJ_CAMERA_MM[POST])/WIDTH_WORLD_COORD[POST],
	// 	/*GOAL*/	(DEFAULT_OBJ_CAMERA_PX[GOAL] * DEFAULT_OBJ_CAMERA_MM[GOAL])/WIDTH_WORLD_COORD[GOAL],
	// 	/*ENEMIE*/	(DEFAULT_OBJ_CAMERA_PX[ENEMIE] * DEFAULT_OBJ_CAMERA_MM[ENEMIE])/WIDTH_WORLD_COORD[ENEMIE],
	// 	/*CENTER*/	(DEFAULT_OBJ_CAMERA_PX[CENTER] * DEFAULT_OBJ_CAMERA_MM[CENTER])/WIDTH_WORLD_COORD[CENTER],
	// 	/*BALL*/	(DEFAULT_OBJ_CAMERA_PX[BALL] * DEFAULT_OBJ_CAMERA_MM[BALL])/WIDTH_WORLD_COORD[BALL],
	// 	/*CORNER*/	(DEFAULT_OBJ_CAMERA_PX[CORNER] * DEFAULT_OBJ_CAMERA_MM[CORNER])/WIDTH_WORLD_COORD[CORNER],
	// 	/*INLINE*/	(DEFAULT_OBJ_CAMERA_PX[INLINE] * DEFAULT_OBJ_CAMERA_MM[INLINE])/WIDTH_WORLD_COORD[INLINE]
	// };


	//nao's camera parameters
	//http://doc.aldebaran.com/2-1/family/robots/video_robot.html
	//http://docs.opencv.org/2.4/doc/tutorials/calib3d/camera_calibration/camera_calibration.html
	//http://stackoverflow.com/questions/14038002/opencv-how-to-calculate-distance-between-camera-and-object-using-image

	//RMS: 0.197796576332
	//camera matrix:

	//320x240
	//RMS: 0.197796576332
	//camera matrix:
	//[[ 275.84193859    0.          164.17096837]
	// [   0.          275.4397455   122.34095676]
	// [   0.            0.            1.        ]]
	//distortion coefficients:  [-0.02209688 -0.22279051 -0.00175674  0.0011898   0.80226521]
	//As we are using same resolution in calibration and detection, we don't need focal lenght (320x240)

	//1. Camera calibration
	//|f_x=2803	0	 	  c_x|
	//|0		f_y=2805  c_y|
	//|0		0	 	  1  |
	//f_x, f_y = camera focal lengths (times scaling factor**)
	//c_x, c_y = optical centers expressed in pixels coordinates
	//you can find the Focal Length value=(4.15mm) of the photos in their JPEG EXIF headers
	//run jhead image.jpg to see the Focal Length value
	//run calibrate.py **

	//2. We need to know the pixels per millimeter (px/mm) on the image sensor
	//we know that f_x and f_y are focal-length times a scaling factor
	//f_x = f * m_x
	//f_y = f * m_y
	//solve for m_x and m_y
	//m = 2804px / 4.15mm = 676px/mm 

	//3. Size of the object on the image sensor
	//if the image is in other resolution, convertion is needed**
	//the object is 41px in a video shot
	//so given 41px/676px/mm we see that the size of the object on the image sensor is .060mm .

	//4. Distance formula
	//distance_mm = object_real_world_mm * focal-length_mm / object_image_sensor_mm
	//distance_mm = 70mm * 4.15mm / .308mm
	//distance_mm = 943mm

	//distâncias do centro, linha, gol (entre traves e posts)


}

#endif //_COMMON_H_
