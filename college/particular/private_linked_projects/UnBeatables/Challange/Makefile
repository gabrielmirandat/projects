INC= 'include/'
SRC= src/
CONTAINER= src/container/
NAMESPACE= src/namespace/
DEBUG= -g
OBJECT= -D OBJECT
REMOTE= -D REMOTE 
CAMERA_PARAMETERS = -D CAMERA_PARAMETERS
OPENCV= -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lopencv_objdetect
BOOST= -lboost_timer -lboost_system

segment_field_1: clean
	g++ -o fieldFoot1 segment_field_1.cpp $(SRC)*'.cpp' -I$(INC) $(OPENCV) $(BOOST)

segment_field_2: clean
	g++ -o fieldFoot2 segment_field_2.cpp $(SRC)*'.cpp' -I$(INC) $(OPENCV) $(BOOST)

clean: 
	clear

	
