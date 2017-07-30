// Definition of the ServerSocket class

#ifndef _SERVER_SOCKET_H_
#define _SERVER_SOCKET_H_

#include "Socket.hpp"


class ServerSocket : private Socket
{
public:

	ServerSocket ( int port );
	ServerSocket (){};
	virtual ~ServerSocket();

	const ServerSocket& operator << ( const std::string& s) const;
	const ServerSocket& operator >> ( std::string& s) const;
	const ServerSocket& operator << ( const cv::Mat& image) const;
    const ServerSocket& operator << ( const char& c) const;
	const ServerSocket& operator >> ( char& c) const;

	void accept ( ServerSocket& );
};

#endif  //_SERVER_SOCKET_H_
