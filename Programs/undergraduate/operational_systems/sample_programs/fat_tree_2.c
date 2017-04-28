// http://stackoverflow.com/questions/23709888/how-to-use-wait-in-c#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define getNChild(c) pow(2,(c)) - 1
int root;

void ProcRec(int index)
{
     pid_t pid;
     int noChild = getNChild(index);

     int i= 0;
     for(i = 0; i < noChild; i++)
     { 
          pid = fork();

        if (pid > 0)
        {
            /* parent process */
        }
        else if (pid == 0)
        {
            /* child process. */
            // createProc(index+1);
            printf("index+1");
        }
        else
        {
            /* error */
            exit(EXIT_FAILURE);
        }
    }

    if(getpid() == root)
    {
        sleep(1); 
        pid = fork();
        if(pid == 0);
          // execl("/usr/bin/pstree", "pstree", getppid(), 0);    
    }
}


void main()
{
	ProcRec(2);

	root = getpid();
	exit(9);
}

