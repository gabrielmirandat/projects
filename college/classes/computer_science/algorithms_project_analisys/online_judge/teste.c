#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  char data[100000];
  int a[100000];
int i=0;    
if (fgets(data, sizeof data, stdin)) {
        while(data[i] != EOF){
		a[i] = data[i]; i++;}
    }  
int num_elements = i;

printf("\nList after sorting\n");
   for(i = 0; i <= num_elements; i++)
	printf("%d ", a[i]);

   

  return(0);
}
