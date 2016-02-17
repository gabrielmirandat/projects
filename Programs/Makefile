#to use: make type prog='program_name'
INC= -I '/include'
SRC= include

c:
	clear
	gcc -o ${prog} ${prog}'.c' -g 
cpp:
	clear
	g++ -o ${prog} ${prog}.cc ${SRC}/*.cc $(INC) -g -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching
