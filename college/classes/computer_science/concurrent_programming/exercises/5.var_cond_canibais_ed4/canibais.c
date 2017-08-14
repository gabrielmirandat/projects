// gcc -o canibais -pthread canibais.c

// Existe 1 cozinheiro e varios canibais
// Enquanto tem comida, o cozinheiro dorme
// Se nao, o canibal que pegou a ultima comida 
// acorda o cozinheiro pra fazer mais

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define CANIBAIS 4

pthread_cond_t coz = PTHREAD_COND_INITIALIZER;
pthread_cond_t can = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock;
int comida = 0;

void* cozinheiro()
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		while(comida>0)
		{
			printf("Tem comida o suficiente, vou dormir.\n");
			pthread_cond_wait(&coz,&lock);
		}

		// fazer comida
		printf("Preparando 10 porçoes de comida.\n");
		sleep(2);
		comida=10;

		// acorda canibais
		printf("Acordem canibais, a comida ta na mesa.\n");
		pthread_cond_broadcast(&can);

		pthread_mutex_unlock(&lock);
	}
}

void* canibal(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		pthread_mutex_lock(&lock);
		while(comida==0)
		{ 
			printf("\t\t%d: Nao tem comida, vou dormir.\n", i);
			pthread_cond_wait(&can,&lock);
		}

		// pega comida
		comida--;
		printf("\t\t%d: Peguei minha porçao, sobrou %d.\n", i,comida);

		if(comida==0)
		{
			printf("\t\t%d: Acorda cozinheiro, cabou a comida!\n", i);
			pthread_cond_signal(&coz);	
		} 

		pthread_mutex_unlock(&lock);

		// comendo comida
		printf("\t\t%d: To comendo, bom demais.\n", i);
		sleep(1);
	}
}

int main()
{
	pthread_t cozinheiro_thread;
	pthread_t canibal_thread[CANIBAIS];
	int i;
	int* id;

	// criando cozinheiro
	pthread_create(&cozinheiro_thread, NULL, cozinheiro, NULL);

	for(i=0;i<CANIBAIS;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&canibal_thread[i], NULL, canibal, (void*) (id));
	}

	// because is infinity loop
	pthread_join(cozinheiro_thread, NULL);
	
	return 0;
}