/// @file
/// @brief Class representing the client for communication
/// @attention Laboratório de Automação e Robótica (LARA)\n
/// Research laboratory from the University of Brasilia.
/// @attention CLARA project

#ifndef _VISION_CLIENT_H
#define _VISION_CLIENT_H

#include <iostream>         //cout
#include <stdio.h>          //printf
#include <string.h>         //strlen
#include <string>           //string
#include <sys/socket.h>     //socket
#include <arpa/inet.h>      //inet_addr
#include <netdb.h>          //hostent
#include "tlayer.hpp"       //general

///
/// \brief TCP Vision Client class
///
class VisionClient
{
private:
    int socket_;                    ///< integer representing socket
    std::string address_;           ///< name of adress
    int port_;                      ///< port for communication
    struct sockaddr_in str_server_;     ///< server adress

public:
    VisionClient();
    virtual ~VisionClient();

    ///
    /// \brief Connect to a host on a certain port number
    /// \param address Adress of the host, used in gethostbyname for obtaining its IP
    /// \param port The port for connection
    /// \return Operation successful or not
    ///
    bool conn(string address , int port);

    ///
    /// \brief Send data to the connected host
    /// \param data Data to be sent
    /// \return Operation successful or not
    ///
	bool send_data(string data);

    ///
    /// \brief Send Mat to the connected host
    /// \param cameraFeed Image to be sent
    /// \param img_size Size of the image
    /// \return Operation successful or not
    ///
    bool send_data_Mat(cv::Mat &cameraFeed, int img_size);

    ///
    /// \brief Receive data from the connected host
    /// \param size Buffer size for receiving
    /// \return The data received
    ///
    string receive(int size=512);
};

#endif
