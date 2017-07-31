#To make a project qtable, just add a .pro file with the following tags
#run with  qmake -o Makefile simulator.pro to generate the makefile
#run make

CONFIG += qt

TARGET = simulator

HEADERS += behavior/*.h \
		   communication/*.h \
		   motion/*.h \
		   vision/*.h


SOURCES += behavior/*.cc \
		   communication/*.cc \
		   motion/*.cc \
		   vision/*.cc \
		   main.cc

LIBS += -lopencv_core -lboost_system -lboost_thread -lboost_timer