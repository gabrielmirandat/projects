// gcc -o pombo_cartas -pthread pombo_cartas.c

// problema do pombo usando mutex
// Quando o pombo esta em A, usuarios
// colocam carta ate um limite
// Quando limite alcançado
// voa ate a cidade B, esvazia e volta

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// lock para pombo fazer viagem
pthread_mutex_t pombo_lock;
// lock do contador de cartas colocadas na sacola
pthread_mutex_t sacola_lock;

#define USUARIOS 55

const int CAPACIDADE_SACOLA = 30;
int cont_sacola = 0;

void* pombo(void* arg)
{
	int i = *((int*) arg);

	sleep(1);
	while(1)
	{
		pthread_mutex_lock(&pombo_lock);
		pthread_mutex_lock(&sacola_lock);
		
		// faz a viagem pra b
		// descarrega sacola
		// volta pra a
		
		printf("Pombo viajando pra B.\n"); sleep(1);
		printf("Pombo descarregando sacola.\n"); sleep(1);
		while(cont_sacola > 0)
		{
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
		
		pthread_mutex_lock(&pombo_lock);
		if(i==0) pthread_mutex_lock(&sacola_lock);

		printf("\t\tUsuario: %d: Colocando carta na sacola.\n", i);
		
		cont_sacola++;
		
		if(cont_sacola==CAPACIDADE_SACOLA)
		{
			printf("\t\tUsuario: %d: Sacola cheia. Pode ir pombo.\n", i);
			pthread_mutex_unlock(&pombo_lock);
		}
		
		pthread_mutex_unlock(&sacola_lock);
		sleep(1);
	}
}

int main()
{

	pthread_t pombo_thread;
	pthread_t usuario_thread[USUARIOS];
	
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