INC= -I ''
SRC= code/
DEBUG= -g
OPENCV= -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lopencv_objdetect -lopencv_contrib 
BOOST= -lboost_timer -lboost_system

ball_cascade: clean
	g++ -o  ball_cascade $(SRC)*.cc $(DEBUG) $(OPENCV) $(BOOST)

clean: 
	clear