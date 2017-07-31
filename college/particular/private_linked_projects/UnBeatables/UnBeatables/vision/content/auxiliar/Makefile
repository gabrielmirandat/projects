INC= -I '/include'
SRC= src/
DEBUG= -g
OPENCV= -lopencv_core -lopencv_highgui -lopencv_imgproc

PKG_CONF_CFLAG= `pkg-config --cflags opencv2 --libs opencv2`
PKGCONF_LIBS= `pkg-config --libs opencv2`

gabriel:
	clear
	g++ -o trackColor trackColor.cpp $(SRC)*'.cpp' $(DEBUG) $(OPENCV)

pedro:
	clear
	g++ $(PKG_CONF_CFLAG) $(INC)  -o trackColor trackColor.cpp $(SRC)*'.cpp' $(PKGCONF_LIBS)
