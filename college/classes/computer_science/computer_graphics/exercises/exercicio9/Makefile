INCDIR = -I ../include/
LDFLAGS = $(INCDIR) -lGL -lGLEW -lglut -lm

InitShader.cpp :
	g++ -c $(INCDIR) ../common/InitShader.cpp

.cpp: InitShader.cpp
	g++ $(LDFLAGS) -o$@   $^ ../common/InitShader.o
