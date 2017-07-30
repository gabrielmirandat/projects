#include "ServerSocket.hpp"
#include "SocketException.hpp"
#include <string>

int main ( int argc, int argv[] )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	    	while ( true )
			{
			  char data1;
			  std::string data2;
			  // Read from socket
			  new_sock >> data1;
			  // Write to socket
			  new_sock << data1;

			  // Read from socket
			  new_sock >> data2;
			  // Write to socket
			  new_sock << data2;

			  std::cout << "Recebi: " << data1 << std::endl;
			  std::cout << "Recebi: " << data2 << std::endl;
			}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
