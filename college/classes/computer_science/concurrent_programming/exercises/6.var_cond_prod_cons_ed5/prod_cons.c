// gcc -o prod_cons -pthread prod_cons.c

// Produtor e consumidor usando 
// variavel de condicao

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// define var de condicoes e mutex
pthread_cond_t prod = PTHREAD_COND_INITIALIZER;
pthread_cond_t cons = PTHREAD_COND_INITIALIZER;
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
		
		pthread_mutex_lock(&prod_lock);
		while(counter == buffer_size)
		{
			printf("%d: Buffer cheio, vou dormir.\n", i); 
			pthread_cond_wait(&prod, &prod_lock);
		}

		buffer[prod_pos] = p;
		prod_pos = (prod_pos + 1)%buffer_size;
		counter++;
		printf("%d: Elemento inserido no buffer= %d.\n", i, p); 
		sleep(1);

		if(counter==1)
		{
			printf("%d: Buffer já tem elemento, acordando consumidor.\n", i);
			pthread_cond_signal(&cons);
		}

		pthread_mutex_unlock(&prod_lock);

		sleep(1);
	}
}

void* consumidor(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		pthread_mutex_lock(&prod_lock);
		while(counter==0)
		{
			printf("\t\t%d: Buffer vazio, vou dormir.\n", i);
			pthread_cond_wait(&cons, &prod_lock);
		}

		int c = buffer[cons_pos];
		cons_pos = (cons_pos + 1)%buffer_size;
		counter--;
		printf("\t\t%d: Elemento consumido do buffer= %d.\n", i, c); 
		sleep(1);

		if(counter==(buffer_size-1))
		{
			printf("\t\t%d: Já cabem elementos, acordando produtor.\n", i);
			pthread_cond_signal(&prod);
		}
		pthread_mutex_unlock(&prod_lock);

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