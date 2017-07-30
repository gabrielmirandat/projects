// gcc -o prod_cons -pthread prod_cons.c

// Produtor e consumidor usando 
// semaforos

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty;	int thread_or_process, ret ,empty_value;
sem_t full;	    int full_value;
pthread_mutex_t prod_lock;

// numero de produtores e consumidores
#define PRODUTORES 4
#define CONSUMIDORES 2

// define buffer 
#define buffer_size 10
// const int buffer_size=10;
int buffer[buffer_size];
// contador do buffer
int counter = 0;
// posicoes no contador
int prod_pos=0;
int cons_pos=0;


void* produtor(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		// item produzido pelo produtor
		int p = (int) (drand48()*1000); // aleatorio
		
		// tira permissao
		sem_wait(&empty);
		// fecha lock
		pthread_mutex_lock(&prod_lock);
		
		// insere item produzido
		buffer[prod_pos] = p;
		prod_pos = (prod_pos + 1)%buffer_size;
		counter++;
		printf("%d: Elemento inserido no buffer= %d.\n", i, p); 
		sleep(1);

		if(counter==(buffer_size-1))
		{
			printf("%d: Cheio.\n", i);
		}
		
		pthread_mutex_unlock(&prod_lock);
		sem_post(&full);

		sleep(1);
	}
}

void* consumidor(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		sem_wait(&full);
		pthread_mutex_lock(&prod_lock);

		int c = buffer[cons_pos];
		cons_pos = (cons_pos + 1)%buffer_size;
		counter--;
		printf("\t\t%d: Elemento consumido do buffer= %d.\n", i, c); 
		sleep(1);

		if(counter==(buffer_size-2))
		{
			printf("\t\t%d: Já cabem elementos.\n", i);
		}
		
		pthread_mutex_unlock(&prod_lock);
		sem_post(&empty);

		// usando c
		printf("\t\t%d: Usando elemento consumido.\n", i); 
		sleep(1);
	}
}

int main()
{
	srand48(time(NULL));

	pthread_t produtor_thread[PRODUTORES];
	pthread_t consumidor_thread[CONSUMIDORES];
	
	/* initialize a private semaphore */
	thread_or_process = 0;
	empty_value = buffer_size;
	full_value  = 0;
	ret = sem_init(&empty, thread_or_process, empty_value); 
	ret = sem_init(&full, thread_or_process, full_value); 

	int i;
	int* id;

	// cria thread dos produtores
	for(i=0;i<PRODUTORES;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&produtor_thread[i], NULL, produtor, (void*) (id));
	}

	// cria threads dos consumidores
	for(i=0;i<CONSUMIDORES;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&consumidor_thread[i], NULL, consumidor, (void*) (id));
	}

	// possivel porque eh loop infinito
	pthread_join(produtor_thread[0], NULL);
	
	return 0;
}