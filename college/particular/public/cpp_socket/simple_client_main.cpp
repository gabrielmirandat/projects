#include "ClientSocket.hpp"
#include "SocketException.hpp"
#include <iostream>
#include <string>

int main ( int argc, char* argv[] )
{
  try
    {

      ClientSocket client_socket ( "localhost", 7800 );

      std::string reply;

      try
	    {
          while(1)
          {
          	  // Write to socket
          	  client_socket << '5';
          	  // Read from socket
          	  // client_socket >> reply;
              // std::cout << "We received this response from the server:\n\"" << reply << "\"\n";

              for(int i=0; i<30000; i++);
          }
    	}
      catch ( SocketException& ) {}

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}