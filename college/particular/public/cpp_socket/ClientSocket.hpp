// Definition of the ClientSocket class

#ifndef _CLIENT_SOCKET_H_
#define _CLIENT_SOCKET_H_

#include "Socket.hpp"


class ClientSocket : private Socket
{
public:

	ClientSocket ( std::string host, int port );
	virtual ~ClientSocket(){};

	const ClientSocket& operator << ( const std::string& s) const;
	const ClientSocket& operator >> ( std::string& s) const;
	const ClientSocket& operator << ( const cv::Mat& image) const;
	const ClientSocket& operator << ( const char& c) const;
	const ClientSocket& operator >> ( char& c) const;
};

#endif  //_CLIENT_SOCKET_H_
