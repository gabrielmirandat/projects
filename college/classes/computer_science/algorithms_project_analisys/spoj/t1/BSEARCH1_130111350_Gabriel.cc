// g++ bsearch1.cc -Wall -g -o bsearch1
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace :: std;

#define max_value 1000000000
#define max_size 100000
#define max_queries 500000


// -10^9 <= input_list[i] <= 10^9
// 0 < num_elements <= 10^5
// 0 < num_queries <= 5*10^5

// first line
int num_elements; // number of elements
int num_queries;  // number of queries

int binary_search (int * input_list, int low, int high, int query) {
	// not in list
	if (low > high)
		return -1;
	
	int mid = (low + high) / 2;
	
	// found on middle 
	if (input_list[mid] == query) {
		if (mid == 0 || input_list[mid - 1] != query)
			return mid;
		return binary_search (input_list, low, mid - 1, query);
	}
	// is on left side
	if (input_list[mid] > query)
		return binary_search(input_list, low, mid - 1, query);
	
    // is on right side  
	return binary_search(input_list, mid + 1, high, query);
}

void run() 
{
  
    // second line
	int query, input_list[max_size];

	scanf ("%d %d", &num_elements, &num_queries);
	for (int i = 0; i < num_elements; i++)
		scanf ("%d", &input_list[i]);
	for (int z = 0; z < num_queries; z++) {
		scanf ("%d", &query);
		printf ("%d\n", binary_search(input_list, 0, num_elements-1, query));
	}
}

int main() 
{ 
  run();
  return 0;
}