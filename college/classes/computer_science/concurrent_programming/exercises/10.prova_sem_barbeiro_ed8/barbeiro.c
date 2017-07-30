// gcc -o barbeiro -pthread barbeiro.c

// Barbeiro usando semaforos
// barbeiro dorme se não tem cliente esperando
// se tdas cadeiras ocupadas, cliente vai embora
// se tem cadeira, cliente senta 
// se ninguem está na cadeira do barbeiro, um 
// cliente pode sentar, e fica parado, quando o 
// barbeiro acaba de cortar, fica parado, cliente 
// sai



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// semaforos
sem_t cadeiras_sem, cadeira_barbeiro_sem, barbeiro_sem, cliente_sem;

// definicao de valores
#define CADEIRAS 4
#define CLIENTES 7
#define VAZIO 0
#define UNITARIO 1

void* barbeiro()
{
	while(1)
	{
		printf("barbeiro: Dormindo.\n");
		sem_wait(&barbeiro_sem);
		sleep(1);	
		printf("barbeiro: Fui acordado, cortando cabelo de cliente.\n");
		printf("barbeiro: Pode dormir, cliente.\n");
		sleep(3);

		printf("barbeiro: Liberando cliente.\n");
		sem_post(&cliente_sem);
	}
}

void* cliente(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		// sem_wait(&full);
		int sentou = sem_trywait(&cadeiras_sem);
		
		if(sentou==0)
		{
			printf("\t\tcliente %d: Sentei na cadeira de espera.\n", i);
			sleep(1);

			// sentando na cadeira do barbeiro
			sem_wait(&cadeira_barbeiro_sem);
			sem_post(&cadeiras_sem);
			printf("\t\tcliente %d: Liberei cadeira de espera e sentei na cadeira do barbeiro.\n", i);
			sleep(1);

			// acordando barbeiro
			sem_post(&barbeiro_sem);
			printf("\t\tcliente %d: Acordando barbeiro, vou cortar.\n", i);
			sleep(1);
			
			// esperando pra ir embora
			sem_wait(&cliente_sem);	
			sem_post(&cadeira_barbeiro_sem);	
			printf("\t\tcliente %d: Fui liberado. Saindo e liberando cadeira do barbeiro.\n", i);
			sleep(1);
		}
		else
		{
			printf("\t\tcliente %d: Sem vaga, indo embora.\n", i);
			sleep(1);
		}

	}
}

int main()
{
	pthread_t barbeiro_thread;
	pthread_t cliente_thread[CLIENTES];
	
	// inicia semaforos
	int thread_or_process = 0;
	
	sem_init(&cadeiras_sem, thread_or_process, CADEIRAS); 
	sem_init(&cadeira_barbeiro_sem, thread_or_process, UNITARIO); 
	sem_init(&barbeiro_sem, thread_or_process, VAZIO); 
	sem_init(&cliente_sem, thread_or_process, VAZIO); 

	int i;
	int* id;

	// cria thread do barbeiro
	pthread_create(&barbeiro_thread, NULL, barbeiro, 0);

	// cria threads dos clientes
	for(i=0;i<CLIENTES;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&cliente_thread[i], NULL, cliente, (void*) (id));
	}

	// possivel porque eh loop infinito
	pthread_join(barbeiro_thread, NULL);
	
	return 0;
}