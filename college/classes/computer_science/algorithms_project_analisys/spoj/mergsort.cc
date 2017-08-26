// g++ mergsort.cc -Wall -g -o mergsort
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace :: std;

#define max_size 100000

int input_list[max_size];
int input_size;

// merges two sublists of input_list[].
// first sublist is input_list[low1..mid]
// second sublist is input_list[mid+1..high]
void merging(int low, int mid, int high) 
{
  int low1, low2, index;
  int temp[max_size-1];

  index = low1 = low;
  low2 = mid + 1;

  // compare until end of one of two sublists
  while(low1 <= mid && low2 <= high)
  {
    if(input_list[low1] <= input_list[low2])
    {
       temp[index] = input_list[low1];
       low1++;
    }
    else
    {
       temp[index] = input_list[low2];
       low2++;
    }

    index++;
  }

  // copy first sublist
  while(low1 <= mid)
  {    
    temp[index++] = input_list[low1];
    low1++;
  }

  // copy second sublist
  while(low2 <= high)
  {   
    temp[index++] = input_list[low2];
    low2++;
  }

  
  // copy temp to input_list
  for(index = low; index <= high; index++)
    input_list[index] = temp[index];
}

// 1.Se n= 1, fim.
// 2.Recursivamente ordene A[ 1..n/2]e A[ n/2 +1 .. n ] .
// 3."merge" duas listas ordenadas
void sort(int low, int high) 
{
  int mid;

  if(low < high) {
    //1. find middle point to divide array in two halfs
    mid = (low + high) / 2;
    //2. call merge sort for first half
    sort(low, mid);
    //3. call merge sort for second half
    sort(mid+1, high);
    //4. merge the two halves sorted in 2 and 3
    merging(low, mid, high);
  }  
}

void read_input() {
  
  string line;
  getline(cin,line);

  stringstream ss (line);

  int i = 0;
  while ( ss>>input_list[i++] && i <= max_size); // this might look a bit ugly
  input_size = i - 1;
}

int main() { 
   
  read_input();

  // cout << "List before sorting\n";
  // for (int i =0; i < input_size; i++) // checking the content of the list
  //     cout<<input_list[i]<<" ";

  sort(0, input_size-1);

  // cout << "\nList after sorting\n";
  for (int i =0; i < input_size; i++) // checking the content of the list
      cout<<input_list[i]<<" ";

  // cout << "\nEnd\n";
  return 0;
}
