#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// ps -fjh -p $(pidof prog1)

int pids[15];


main()
{
   int pid;
   int state;

   if (( pid = fork()) < 0) { printf("erro na criacao do p0\n"); exit(1);}

   if (pid == 0)
   { // p0
	    pids[0] = getpid();
	    printf("p0\n");

		if (( pid = fork()) < 0) { printf("erro na criacao do p1\n"); exit(1);}
		
		if (pid == 0)
		{ // p1
		    pids[1] = getpid();
		    printf("p1\n");

			// if (execl("", (char *) 0) < 0) printf("erro no execl = %d\n", errno);
			sleep(20);
     		exit(1);
		}
		else
   		{
			if (( pid = fork()) < 0) { printf("erro na criacao do p2\n"); exit(1);}
		
			if (pid == 0)
			{ // p2
			    pids[2] = getpid();
			    printf("p2\n");


				// if (execl("", (char *) 0) < 0) printf("erro no execl = %d\n", errno);
				sleep(20);
     			exit(2);
			}
			else
	   		{
	     		// pai criou dois filhos
	     		sleep(20);
	     		sleep(1);
	     		waitpid(pids[1]);
	     		waitpid(pids[2]);
	     	}
     	}
     	exit(0);
   }
   else
   {
   		// escalonador
   		sleep(30);
	    waitpid(pids[0]);
   }
}
     
