#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"


int main(){
	int menu;

	do{
		printf(" _________________________________Projeto TR1_____________________________________ \n");
		printf("|                                  1. Comecar testes                              |\n");
		printf("|                                  0. Sair                                        |\n");
		printf("|_________________________________________________________________________________|\n");
		menu = getchar();
		switch(menu){
			case 49:
				Fazer_Pedido();
		}
	}while(menu == 49);
	
	return(0);
}