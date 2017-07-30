#To make a project qtable, just add a .pro file with the following tags
#run with  qmake -o Makefile simulator.pro to generate the makefile
#run make

OBJECTS_DIR= generated_files #Intermediate object files directory
MOC_DIR=     generated_files #Intermediate moc files directory
DESTDIR=     bin             #Target file directory

CONFIG += qt link_pkgconfig

PKGCONFIG += orocos-bfl

TARGET = bfl

SOURCES +=  bfl.cc
		   		   
QT += core

# -I /usr/src/ltilib/install/include/bfl
