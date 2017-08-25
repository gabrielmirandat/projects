// gcc life_the_universe_and_everything.c -Wall -g -o life_the_universe_and_everything
#include <stdio.h>
#include<stdlib.h>

int main(void) 
{
	// your code here
	int *p=0;
	int i=0;
	//int inp=0;
	int len=0;
	//clrscr();
	int n=0;
	
	n=5000;
	p=(int*)malloc(n*sizeof(int));
	
	for(i=0;i<n;++i)
	{
		if(p==NULL)
		{
			//printf("Memory not available\n");
			exit(1);
		}
		//printf(" enter number : ");

		scanf("%d",p+i);
		if(*(p+i)==42) break;

	}
	len=i;
	//printf(" value of i is %d\n",len);
	//printf("Numbers entered are\n");

	for(i=0;i<len;++i)
		printf("%d \t",*(p+i));
	
	return 0;
}
