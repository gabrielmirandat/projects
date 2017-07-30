#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void funcao_sigsegv()
{
   printf("recebi segment fault. Vou morrer!!!\n");
   exit(1);
}

main()
{
   char *p;
   signal(SIGSEGV, funcao_sigsegv);
   
   /* vou forcar um segment fault */
   printf("%d", *p);
}
