// gcc -o db -pthread db.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define READER 4
#define WRITER 4

int reader_counter = 0 ;

//lock1
pthread_mutex_t db_lock;
//lock2
pthread_mutex_t reader_counter_lock;

void* readers(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		//2
		pthread_mutex_lock(&reader_counter_lock);
		
		reader_counter++;
		
		if(reader_counter==1)
		{
			//1
			pthread_mutex_lock(&db_lock);	
		} 
		
		//2
		pthread_mutex_unlock(&reader_counter_lock);
		
		// ler dados
		printf("reader %d: reading data - %d readers using db.\n", i, reader_counter);
		sleep(2);

		//2
		pthread_mutex_lock(&reader_counter_lock);
		
		reader_counter--;
		printf("reader %d: stop reading data - %d readers using db.\n", i, reader_counter);

		if(reader_counter==0) 
		{
			//1
			pthread_mutex_unlock(&db_lock);
		}
		
		//2
		pthread_mutex_unlock(&reader_counter_lock);

		// processa dados lidos
		printf("reader %d: processing data\n", i);
		sleep(5);
		printf("reader %d: stop processing data\n", i);
	}
}

void* writers(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		sleep(2);

		// produz dados
		printf("writer %d: producing data\n", i);
		sleep(3);
		printf("writer %d: stop producing data\n", i);

		//1
		pthread_mutex_lock(&db_lock);

		// escreve dados no bd
		printf("writer %d: writing data - writer using db.\n", i);
		sleep(3);
		printf("writer %d: stop writing data - writer left db.\n", i);

		//1
		pthread_mutex_unlock(&db_lock);

	}
}

int main()
{
	pthread_t reader_thread[READER];
	pthread_t writer_thread[WRITER];

	int i;
	int* id;

	for(i=0;i<READER;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&reader_thread[i], NULL, readers, (void*) (id));
	}

	for(i=0;i<WRITER;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&writer_thread[i], NULL, writers, (void*) (id));
	}

	// pq eh loop infinito
	pthread_join(reader_thread[0], NULL);
	return 0;
}