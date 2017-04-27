#to use: make {c/cpp} prog='program_name/directory'
INC= -I '/include'
SRC= include

c:
	clear
	gcc -o ${prog} ${prog}'.c' -g -lm
c_dir:
	clear
	gcc -o ${prog}/main ${prog}/*.c -g -lm
cpp:
	clear
	g++ -o ${prog} ${prog}.cc ${SRC}/*.cc $(INC) -g -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching
