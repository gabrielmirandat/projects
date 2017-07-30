// Gabriel Martins de Miranda - 130111350
// gcc -o soma_matriz -pthread soma_matriz.c
// barreira
// [] N por M
// inicializa barreira com valor que diz quantas threads vão parar até liberar todas as threads
// wait para na barreira

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10
#define M 5

// barreira
pthread_barrier_t barreira;
// matriz
int matriz[N][M];
// vetor
int vetor[N];
// mutex
pthread_mutex_t mtx;

void* soma(void* arg);
void printa_matriz();
void printa_vetor();
void preenche_matriz();

void* soma(void* arg)
{
	int id = *((int*) arg);
	
	int parcial = 0;
	for(int i=0; i< M; i++)
	{
		parcial += matriz[id][i];
	}

	vetor[id] = parcial;
	pthread_mutex_lock(&mtx);
	printa_vetor();
	pthread_mutex_unlock(&mtx);
	pthread_barrier_wait(&barreira);

	if(id==0)
	{
		int total = 0;
		
		printf("\n");
		for(int i=0; i< N; i++)
		{
			total += vetor[i];
		} 

		printf("soma total: %d\n", total);
	}
}

void printa_matriz()
{
	printf("matriz:\n");
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			printf("%3d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printa_vetor()
{
	printf("vetor: ");
	for(int i=0; i<N; i++)
		printf("%3d ", vetor[i]);
	printf("\n");

}

void preenche_matriz()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			matriz[i][j] = i;
		}
	}
}

int main()
{
	int i;
	int* id;
	// threads usadas
	pthread_t soma_thread[N];
	// inicializa barreira
	pthread_barrier_init(&barreira, NULL, N); 

	preenche_matriz();
	printa_matriz();

	// cria threads
	for(i=0;i<N;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&soma_thread[i], NULL, soma, (void*) (id));
	}	

	// possivel porque eh loop infinito
	pthread_join(soma_thread[0], NULL);
}
