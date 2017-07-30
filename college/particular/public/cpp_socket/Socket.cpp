// Implementation of the Socket class.
#include "Socket.hpp"
#include "string.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>



Socket::Socket() 
: m_sock (-1)
{
    memset ( &m_addr, 0, sizeof ( m_addr ) );
}

Socket::~Socket()
{
    if (is_valid())
        ::close ( m_sock );
}

bool Socket::create()
{
    m_sock = socket ( AF_INET, SOCK_STREAM, 0);

    if ( ! is_valid() )
        return false;


    // TIME_WAIT - argh
    int on = 1;
    if ( setsockopt ( m_sock, SOL_SOCKET, SO_REUSEADDR, ( const char* ) &on, sizeof ( on ) ) == -1 )
        return false;


    return true;
}

bool Socket::bind ( const int port )
{

    if ( ! is_valid() )
        return false;

    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons ( port );

    int bind_return = ::bind ( m_sock, ( struct sockaddr * ) &m_addr, sizeof ( m_addr ) );


    if ( bind_return == -1 )
        return false;

    return true;
}

bool Socket::listen() const
{
    if ( ! is_valid() )
        return false;

    int listen_return = ::listen ( m_sock, MAXCONNECTIONS );


    if ( listen_return == -1 )
        return false;

    return true;
}

bool Socket::accept ( Socket& new_socket ) const
{
    int addr_length = sizeof ( m_addr );
    new_socket.m_sock = ::accept ( m_sock, ( sockaddr * ) &m_addr, ( socklen_t * ) &addr_length );

    if ( new_socket.m_sock <= 0 )
        return false;
    
    return true;
}

bool Socket::connect ( const std::string host, const int port )
{
    if ( ! is_valid() ) return false;

    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons ( port );

    int status = inet_pton ( AF_INET, host.c_str(), &m_addr.sin_addr );

    if ( errno == EAFNOSUPPORT ) return false;

    status = ::connect ( m_sock, ( sockaddr * ) &m_addr, sizeof ( m_addr ) );

    if ( status == 0 )
        return true;
    else
        return false;
}

bool Socket::sendStr ( const std::string s ) const
{
    int status = ::send( m_sock, s.c_str(), s.size(), MSG_NOSIGNAL );
    if ( status < 0 )
    {
        std::cout << "[COMM] error in sendStr" << std::endl;
        return false;
    }

    return true;
}

int Socket::recvStr ( std::string& s ) const
{
    char buf [ MAXSTRRECV + 1 ];

    s = "";

    memset ( buf, 0, MAXSTRRECV + 1 );

    int status = ::recv ( m_sock, buf, MAXSTRRECV, 0 );

    if ( status < 0 )
    {
        std::cout << "[COMM] error in recvStr" << std::endl;
        return 0;
    }
    
    s = buf;
    return status;
}

bool Socket::sendMat ( const cv::Mat image, int image_size) const
{
    int status = ::send( m_sock, image.data, image_size, MSG_NOSIGNAL );
    if ( status < 0 )
    {
        std::cout << "[COMM] error in sendMat" << std::endl;
        return false;
    }

    return true;
}

bool Socket::sendChar ( char c) const
{
    int status = ::send( m_sock, &c, sizeof(c), MSG_NOSIGNAL );
    if ( status < 0 )
    {
        std::cout << "[COMM] error in sendChar" << std::endl;
        return false;
    }

    return true;
}

int Socket::recvChar ( char& c) const
{
    char buf = '0';

    int status = ::recv ( m_sock, &buf, sizeof(char), 0 );

    if ( status < 0 )
    {
        std::cout << "[COMM] error in recvChar" << std::endl;
        return 0;
    }
    
    c = buf;
    return status;
}

void Socket::set_non_blocking ( const bool b )
{
    int opts;

    opts = fcntl ( m_sock, F_GETFL );

    if ( opts < 0 )
    {
        return;
    }

    if ( b )
        opts = ( opts | O_NONBLOCK );
    else
        opts = ( opts & ~O_NONBLOCK );

    fcntl ( m_sock, F_SETFL,opts );
}
