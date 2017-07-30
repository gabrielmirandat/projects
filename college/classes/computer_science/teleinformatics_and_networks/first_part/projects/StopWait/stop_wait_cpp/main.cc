#include <iostream>
#include "include/Communication.h"

int main(int argc, char* argv[])
{
	Communication* com = new Communication();
	com->run();
	delete com;
}