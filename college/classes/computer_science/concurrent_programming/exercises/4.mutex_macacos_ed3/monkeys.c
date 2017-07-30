// gcc -o monkeys -pthread monkeys.c

// Existem 2 morros ligados por uma corda
// Em cada morro infinitos macacos
// Macacos vão de A para B e de B para A
// Não pode haver macacos indo nas duas direcoes ao mesmo tempo
// Podem haver infinitos macacos na corda
// Macacos voltam ao morro por teletransporte

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MONKEYS_A 14
#define MONKEYS_B 4

// counters
int mkyA_counter = 0 ;
int mkyB_counter = 0 ;


pthread_mutex_t rope_lock;				// rope lock
pthread_mutex_t mkyA_counter_lock;		// mkyA lock 
pthread_mutex_t mkyB_counter_lock;		// mkyB lock 

void* fromAtoB(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		
		pthread_mutex_lock(&mkyA_counter_lock);
		mkyA_counter++;
		if(mkyA_counter==1)	pthread_mutex_lock(&rope_lock);	
		pthread_mutex_unlock(&mkyA_counter_lock);
		
		// entering rope
		printf("monkeyA %d: entering rope - %d monkeysA using rope.\n", i, mkyA_counter);  sleep(2);
		
		pthread_mutex_lock(&mkyA_counter_lock);
		mkyA_counter--;
		
		// leaving rope
		printf("monkeyA %d: leaving rope - %d monkeysA using rope.\n", i, mkyA_counter);

		if(mkyA_counter==0) pthread_mutex_unlock(&rope_lock);
		pthread_mutex_unlock(&mkyA_counter_lock);

		// teleporting from B to A
		printf("monkeyA %d: teleporting back to A\n", i); sleep(5);
	}
}

void* fromBtoA(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		pthread_mutex_lock(&mkyB_counter_lock);
		mkyB_counter++;
		if(mkyB_counter==1) pthread_mutex_lock(&rope_lock);	
		pthread_mutex_unlock(&mkyB_counter_lock);
		
		// entering rope
		printf("monkeyB %d: entering rope - %d monkeysB using rope.\n", i, mkyB_counter); sleep(2);
		
		pthread_mutex_lock(&mkyB_counter_lock);
		mkyB_counter--;

		// leaving rope
		printf("monkeyB %d: leaving rope - %d monkeysB using rope.\n", i, mkyB_counter);

		if(mkyB_counter==0) pthread_mutex_unlock(&rope_lock);
		pthread_mutex_unlock(&mkyB_counter_lock);

		// teleporting from A to B
		printf("monkeyB %d: teleporting back to B\n", i); sleep(5);
	}
}

int main()
{
	pthread_t mkyA_thread[MONKEYS_A];
	pthread_t mkyB_thread[MONKEYS_B];
	int i;
	int* id;

	for(i=0;i<MONKEYS_A;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&mkyA_thread[i], NULL, fromAtoB, (void*) (id));
	}

	for(i=0;i<MONKEYS_B;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&mkyB_thread[i], NULL, fromBtoA, (void*) (id));
	}

	// because is infinity loop
	pthread_join(mkyA_thread[0], NULL);
	return 0;
}