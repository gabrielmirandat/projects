// Implementation of the ServerSocket class

#include "ServerSocket.hpp"
#include "SocketException.hpp"


ServerSocket::ServerSocket ( int port )
{
    if ( ! Socket::create() )
    {
        throw SocketException ( "Could not create server socket." );
    }

    if ( ! Socket::bind ( port ) )
    {
        throw SocketException ( "Could not bind to port." );
    }

    if ( ! Socket::listen() )
    {
        throw SocketException ( "Could not listen to socket." );
    }

}

ServerSocket::~ServerSocket()
{
}


const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
    if ( ! Socket::sendStr ( s ) )
    {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;
}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
    if ( ! Socket::recvStr ( s ) )
    {
        throw SocketException ( "Could not read from socket." );
    }

    return *this;
}

const ServerSocket& ServerSocket::operator << ( const cv::Mat& image ) const
{
    int image_size = image.total()*image.elemSize();


    if ( ! Socket::sendMat ( image, image_size ) )
    {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;
}


const ServerSocket& ServerSocket::operator << ( const char& c ) const
{
    if ( ! Socket::sendChar ( c ) )
    {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;
}


const ServerSocket& ServerSocket::operator >> ( char& c ) const
{
    if ( ! Socket::recvChar ( c ) )
    {
        throw SocketException ( "Could not read from socket." );
    }

    return *this;
}

void ServerSocket::accept ( ServerSocket& sock )
{
    if ( ! Socket::accept ( sock ) )
    {
        throw SocketException ( "Could not accept socket." );
    }
}
