DEBUG= -g
OBJECT= -D OBJECT
REMOTE= -D REMOTE 
OPENCV= -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lopencv_objdetect
BOOST= -lboost_timer -lboost_system

roi_detection: clean
	g++ -o roi_detection roi_detection.cc $(OPENCV) $(BOOST)

clean: 
	clear

	
