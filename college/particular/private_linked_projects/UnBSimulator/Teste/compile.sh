#! /bin/bash

#dpkg -s libboost-dev | grep 'Version' --Version: 1.54.0.1ubuntu1

echo "compiling example1.."
g++ example1.cc -lboost_system -lboost_thread -o example1
echo "compiling example2.."
g++ example2.cc -lboost_system -lboost_thread -o example2
echo "compiling sample1.."
g++ sample1.cc -lboost_system -lboost_thread -lboost_timer -lopencv_core -o sample1
echo "comiling simulator_threads.."
cd simulator_threads/
make 
cd ..


