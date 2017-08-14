// gcc -o avioes -pthread aeroporto.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define AV 4
pthread_mutex_t lock_pista;

void* aviao(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		printf("%d: voando\n",i);
		sleep(5);
		printf("%d: vai pousar\n",i);
		
		pthread_mutex_lock(&lock_pista);
		printf("%d: pousando - usando a pista\n",i);
		sleep(2);
		printf("%d: pousou - liberando a pista\n",i);
		pthread_mutex_unlock(&lock_pista);

		sleep(1);

		pthread_mutex_lock(&lock_pista);
		printf("%d: decolando - usando a pista\n",i);
		sleep(1);
		printf("%d: decolou - liberando a pista\n",i);
		pthread_mutex_unlock(&lock_pista);
	}
}

int main()
{
	pthread_t a[AV];
	int i;
	int* id;

	for(i=0;i<AV;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&a[i], NULL, aviao, (void*) (id));
	}
	// pq eh loop infinito
	pthread_join(a[0], NULL);
	return 0;
}