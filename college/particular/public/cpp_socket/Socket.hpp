// http://tldp.org/LDP/LG/issue74/tougher.html
// Definition of the Socket class

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>
#include "tlayer.hpp"       //general


const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
// data for recv methods (need a defined size)
const int MAXSTRRECV = 500;

class Socket
{
private:
    int m_sock;
    sockaddr_in m_addr;

public:
    Socket();
    virtual ~Socket();

    // Server initialization
    bool create();
    bool bind ( const int port );
    bool listen() const;
    bool accept ( Socket& ) const;

    // Client initialization
    bool connect ( const std::string host, const int port );

    // Data Transimission
    bool sendStr ( const std::string s) const;
    int recvStr ( std::string& s) const;

    bool sendMat (const cv::Mat image, int image_size) const;

    bool sendChar ( char c) const;
    int recvChar ( char& c) const;

    void set_non_blocking ( const bool );

    bool is_valid() const { return m_sock != -1; }
};

#endif //_SOCKET_H_
