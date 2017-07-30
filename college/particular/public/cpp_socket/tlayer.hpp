/// @file
/// @brief Header with global includes
/// @attention Laboratório de Automação e Robótica (LARA)\n
/// Research laboratory from the University of Brasilia.
/// @attention CLARA project

#ifndef _TRANSPORT_LAYER_H_
#define _TRANSPORT_LAYER_H_

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"

// Conection Parameters
#define LOCALHOST "127.0.0.1"       ///< local host
#define PORT_FRAME 7200             ///< port for sending frame
#define PORT_SERVO 7300             ///< port for sending servo
#define PORT_STATE 7800             ///< port for receiving states

using namespace std;
using namespace cv;

#endif //_TRANSPORTE_LAYER_H_
