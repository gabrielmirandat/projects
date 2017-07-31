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

infielddetection: clean
	g++ -o bin/InFieldDetection main.cc $(SRC)*'.cc' $(CONTAINER)*'.cc' $(NAMESPACE)*'.cc' -I$(INC) $(DEBUG) $(REMOTE) \
	$(OPENCV) $(BOOST)

clean: 
	clear

	
