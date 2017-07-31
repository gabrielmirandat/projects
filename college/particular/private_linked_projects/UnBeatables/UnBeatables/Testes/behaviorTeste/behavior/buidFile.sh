#!/bin/bash
g++ -c -Wall $1.cpp -lpthread
g++ -L /lib -lpthread $1.o -o $1 -lrt -lpthread
