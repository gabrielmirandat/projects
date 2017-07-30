INC= -I '/home/gabriel/ode-0.13.1/include'
#this is optional if you didn't specify in the source file
SINGLE= -DdSINGLE 
DOUBLE= -DdDOUBLE
SRC= src/
DEBUG= -g
OBJECT= -D OBJECT
REMOTE= -D REMOTE 
DRAWSTUFF= -ldrawstuff
ODE= -lode
OPENGL= -lGL -lGLU
X11= -lX11 

bouncing_sphere: clean
	g++ bouncing_sphere.cpp -o bouncing_sphere $(INC) $(ODE) $(DRAWSTUFF) $(OPENGL) $(X11)

bouncing_sphere_2: clean
	g++ `ode-config --cflags` bouncing_sphere.cpp `ode-config --libs` $(INC) \
	$(DRAWSTUFF) $(OPENGL) $(X11) -o bouncing_sphere

clean: 
	clear

	
