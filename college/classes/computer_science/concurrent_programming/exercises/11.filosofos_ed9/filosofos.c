// Gabriel Martins de Miranda - 130111350
// gcc -o filosofos -pthread filosofos.c
// jantar dos filosofos 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define FILOSOFOS 5
#define ESQ(id) ((id+FILOSOFOS-1)%FILOSOFOS)
#define DIR(id) ((id+1)%FILOSOFOS)

void* filosofo(void* id);
void pega_garfo(int id);
void testa_comer(int id);
void devolve_garfo();

enum
{
	PENSANDO,
	COMENDO,
	FAMINTO
};

int estado[FILOSOFOS];
pthread_mutex_t m;
sem_t filosofo_sem[FILOSOFOS];

void* filosofo(void* arg)
{

	int id = *((int*) arg);

	while(1)
	{
		// PENSA
		printf("%d: pensando.\n", id); 
		sleep(1);
		pega_garfo(id);
		// COMER
		printf("%d: comendo.\n", id); 
		sleep(1);
		devolve_garfo(id);
	}
}

void pega_garfo(int id)
{
	pthread_mutex_lock(&m);
	printf("%d: tentando pegar garfos.\n", id); 
	sleep(1);
	estado[id] = FAMINTO;
	testa_comer(id);
	pthread_mutex_unlock(&m);
	sem_wait(&filosofo_sem[id]);
}


void testa_comer(int id)
{
	if((estado[id] == FAMINTO) && (estado[ESQ(id)] != COMENDO) && (estado[DIR(id)] != COMENDO))
	{
		estado[id] = COMENDO;
		sem_post(&filosofo_sem[id]);
	}
}

void devolve_garfo(int id)
{
	pthread_mutex_lock(&m);
	printf("%d: devolvendo garfos.\n", id); 
	sleep(1);
	estado[id] = PENSANDO;
	testa_comer(ESQ(id));
	testa_comer(DIR(id));
	pthread_mutex_unlock(&m);
}

int main()
{
	int i;
	int* id;
	pthread_t filosofo_thread[FILOSOFOS];
	
	// inicia semaforos e estados
	for(i=0;i<FILOSOFOS;i++)
	{
		int ret = sem_init(&filosofo_sem[i], 0, 0); 
		estado[i] = PENSANDO;
	}	

	// cria thread dos filosofos
	for(i=0;i<FILOSOFOS;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&filosofo_thread[i], NULL, filosofo, (void*) (id));
	}	

	// possivel porque eh loop infinito
	pthread_join(filosofo_thread[0], NULL);
}
