// g++ codesptb.cc -Wall -g -o codesptb
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace :: std;

#define max_size 100000
#define max_value 1000000

// 1 <= num_tests <= 5
// 1 <= num_elements <= 100000
// 1 <= input_list[i] <= 1000000

int num_tests; // number of tests
int num_elements; // number of elements
int input_list[max_size];
int num_changes;


// http://www.cs.mcgill.ca/~cs203/lectures/lecture7/sld005.htm
void process_sort() {
	num_changes = 0;
	int j,key;

	for(int i=1; i < num_elements; ++i)
	{
		key = input_list[i];
		j = i - 1;

		while(j >= 0 && input_list[j]>key)
		{
			input_list[j+1]=input_list[j];
			j = j - 1;
			num_changes++;
		}

		input_list[j+1]=key;
	}
	cout << num_changes << endl;
}

void check(int value, int min, int max)
{
	if(value < min || value > max)
		exit(-1);
}

void run() {
  
  cin >> num_tests;
  check(num_tests,1,5);

  for(int i=1; i <= num_tests; i++)
  {
  	cin >> num_elements;
	check(num_elements,1,max_size);

  	for(int j=0; j < num_elements; j++)
  	{
		cin >> input_list[j];
		check(input_list[j],1,max_value);
  	}
  	process_sort();
  }
}

int main() 
{ 
  run();
  return 0;
}