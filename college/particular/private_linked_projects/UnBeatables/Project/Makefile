INC= -I 'include/'
SRC= src/
FLAGS = -D REMOTE -std=c++11 -lboost_system -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video

all:
	clear
	g++ -o  executable $(SRC)'kalman.cc' main.cpp -g $(FLAGS) 

	
