// gcc -o pombo_cartas -pthread pombo_cartas.c

// problema do pombo usando semaforo
// Quando o pombo esta em A, usuarios
// colocam carta ate um limite
// Quando limite alcançado
// voa ate a cidade B, esvazia e volta

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// representa o semaforo do pombo
// para permitir a viagem
sem_t empty;	int thread_or_process, ret ,empty_value;
// representa o semaforo da sacola
// cada usuario pega uma permissao
sem_t full;	    int full_value;
// lock do contador de cartas colocadas na sacola
pthread_mutex_t sacola_lock;

#define USUARIOS 55

const int CAPACIDADE_SACOLA = 30;
int cont_sacola = 0;

void* pombo(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		// tira permissao
		sem_wait(&empty);
		// fecha lock da sacola
		pthread_mutex_lock(&sacola_lock);
		
		// faz a viagem pra b
		// descarrega sacola
		// volta pra a
		
		printf("Pombo viajando pra B.\n"); sleep(1);
		printf("Pombo descarregando sacola.\n"); sleep(1);
		while(cont_sacola > 0)
		{
			sem_post(&full);
			cont_sacola--;
		}


		printf("Pombo voltando pra A.\n"); sleep(1);
		pthread_mutex_unlock(&sacola_lock);
	}
}

void* usuario(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		
		// tira permissao
		sem_wait(&full);
		// pega lock da sacola
		pthread_mutex_lock(&sacola_lock);

		printf("\t\tUsuario: %d: Colocando carta na sacola.\n", i); sleep(1);
		
		cont_sacola++;
		
		
		if(cont_sacola==CAPACIDADE_SACOLA)
		{
			printf("\t\tUsuario: %d: Sacola cheia. Pode ir pombo.\n", i);
			sem_post(&empty);
		}
		
		pthread_mutex_unlock(&sacola_lock);
	}
}

int main()
{

	pthread_t pombo_thread;
	pthread_t usuario_thread[USUARIOS];
	
	/* initialize a private semaphore */
	thread_or_process = 0;
	empty_value = 0;
	full_value  = CAPACIDADE_SACOLA;
	ret = sem_init(&empty, thread_or_process, empty_value); 
	ret = sem_init(&full, thread_or_process, full_value); 

	int i;
	int* id;

	// cria thread do pombo
	pthread_create(&pombo_thread, NULL, pombo, (void*) (id));
	
	// cria threads dos usuarios
	for(i=0;i<USUARIOS;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&usuario_thread[i], NULL, usuario, (void*) (id));
	}

	// possivel porque eh loop infinito
	pthread_join(pombo_thread, NULL);
	
	return 0;
}