#To make a project qtable, just add a .pro file with the following tags
#run with  qmake -o Makefile vision.pro to generate the makefile
#run make

OBJECTS_DIR= generated_files 		#Intermediate object files directory
DESTDIR=     bin          		#Target file directory
INCLUDEPATH= include		        #Paths to be included
			

CONFIG  += qt

TARGET   = main_shm

HEADERS += include/*.h \

SOURCES += src/*.cc \
           main_shm.cc

QT += core

LIBS += -lboost_system
