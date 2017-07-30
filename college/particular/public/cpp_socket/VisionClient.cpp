// c++ client socket

#include "VisionClient.hpp"

VisionClient::VisionClient()
{
    socket_ = -1;
    port_ = 0;
    address_ = "";

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        std::cout<<"[COMM] VisionClient object created." << std::endl;
#endif
}

VisionClient::~VisionClient()
{
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        std::cout<<"[COMM] VisionClient object deleted." << std::endl;
#endif
}

/**
    Connect to a host on a certain port number
*/
bool VisionClient::conn(string address , int port)
{
    // create socket if it is not already created
    if(socket_ == -1)
	{
        // create socket
        socket_ = socket(AF_INET , SOCK_STREAM , 0);
        if (socket_ == -1)
		{
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
            perror("[COMM] Could not create socket");
#endif
		}

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        cout<<"[COMM] Socket created\n";
#endif
	}
	else	{	/* OK , nothing */	}

    // setup address structure
    if(inet_addr(address.c_str()) != 0)
	{
		struct hostent *he;
		struct in_addr **addr_list;

        // resolve the hostname, its not an ip address
		if ( (he = gethostbyname( address.c_str() ) ) == NULL)
		{
            // gethostbyname failed
            herror("[COMM] gethostbyname");
			
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
            cout<<"[COMM] Failed to resolve hostname\n";
#endif

			return false;
		}

        // cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
		addr_list = (struct in_addr **) he->h_addr_list;

		for(int i = 0; addr_list[i] != NULL; i++)
		{
            // strcpy(ip , inet_ntoa(*addr_list[i]) );
            str_server_.sin_addr = *addr_list[i];

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
            cout<< "[COMM] " << address <<" resolved to "<<inet_ntoa(*addr_list[i])<<endl;
#endif

			break;
		}
	}

    // plain ip address
	else
	{
        str_server_.sin_addr.s_addr = inet_addr( address.c_str() );
	}

    str_server_.sin_family = AF_INET;
    str_server_.sin_port = htons( port );

    // connect to remote server
    if (connect(socket_ , (struct sockaddr *)&str_server_ , sizeof(str_server_)) < 0)
	{
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        perror("[COMM] connect failed. Error");
#endif

		return 1;
	}

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
    cout<<"[COMM] Connected\n";
#endif
	
	return true;
}

/**
	Send data to the connected host
*/
bool VisionClient::send_data(string data)
{
    // send some data
    if( send(socket_ , data.c_str() , strlen( data.c_str() ) , 0) < 0)
	{
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        perror("[COMM] Send failed : ");
#endif

		return false;
	}
	return true;
}

/**
	Send Mat to the connected host
*/
bool VisionClient::send_data_Mat(cv::Mat &cameraFeed, int img_size)
{
    // send some data
    if( send(socket_ , cameraFeed.data , img_size, 0) < 0)
	{
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        perror("[COMM] Send failed : ");
#endif
			
		return false;
	}
	return true;
}

/**
	Receive data from the connected host
*/
string VisionClient::receive(int size)
{
    char buffer[size];
	string reply;

    // receive a reply from the server
    if( recv(socket_ , buffer , sizeof(buffer) , 0) < 0)
	{
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        puts("[COMM] recv failed");
#endif
	}

	reply = buffer;
	return reply;
}
