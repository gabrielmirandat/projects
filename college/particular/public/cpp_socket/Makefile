# Makefile for the socket programming example
#

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o


all : simple_server simple_client

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects) -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lboost_timer -lboost_system


simple_client: $(simple_client_objects)
	g++ -o simple_client $(simple_client_objects) -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lboost_timer -lboost_system


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp


clean:
	rm -f *.o simple_server simple_client
