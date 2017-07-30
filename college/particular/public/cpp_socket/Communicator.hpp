/// @file
/// @brief Class representing the general communicator
/// @attention Laboratório de Automação e Robótica (LARA)\n
/// Research laboratory from the University of Brasilia.
/// @attention CLARA project

#ifndef _COMMUNICATOR_H_
#define _COMMUNICATOR_H_

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "tlayer.hpp"
#include "CommunicateServo.hpp"
#include "ClientSocket.hpp"
#include "ServerSocket.hpp"

class Communicator
{
private:
    CommunicateServo* servo_comm_;                  ///< servo communicator
    ClientSocket* client_socket_;                   ///< socket for sending frames
    ServerSocket* server_socket_;                   ///< socket for receiving states

public:
    explicit Communicator(int width, int height);
	virtual ~Communicator();

    ///
    /// \brief sendMatToGui For sending an image to the python gui
    /// \param image
    ///
    void sendMatToGui(cv::Mat image);

    ///
    /// \brief sendPosToServo For sending found position to servo
    /// \param x X parameter of position
    /// \param y Y parameter of position
    ///
    void sendPosToServo(int x, int y);

    char rcvStateFromGui();
};

#endif	//_COMMUNICATOR_H_
