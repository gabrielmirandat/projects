// Implementation of the ClientSocket class

#include "ClientSocket.hpp"
#include "SocketException.hpp"


ClientSocket::ClientSocket ( std::string host, int port )
{
    if ( ! Socket::create() )
    {
        throw SocketException ( "Could not create client socket." );
    }

    if ( ! Socket::connect ( host, port ) )
    {
        throw SocketException ( "Could not bind to port." );
    }

}


const ClientSocket& ClientSocket::operator << ( const std::string& s ) const
{
    if ( ! Socket::sendStr ( s ) )
    {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;

}


const ClientSocket& ClientSocket::operator >> ( std::string& s ) const
{
    if ( ! Socket::recvStr ( s ) )
    {
        throw SocketException ( "Could not read from socket." );
    }

    return *this;
}

const ClientSocket& ClientSocket::operator << (  const cv::Mat& image ) const
{
    int image_size = image.total()*image.elemSize();


    if ( ! Socket::sendMat ( image, image_size ) )
    {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;

}

const ClientSocket& ClientSocket::operator << ( const char& c ) const
{
    if ( ! Socket::sendChar ( c ) )
    {
        throw SocketException ( "Could not write to socket." );
    }

    return *this;

}


const ClientSocket& ClientSocket::operator >> ( char& c ) const
{
    if ( ! Socket::recvChar ( c ) )
    {
        throw SocketException ( "Could not read from socket." );
    }

    return *this;
}
