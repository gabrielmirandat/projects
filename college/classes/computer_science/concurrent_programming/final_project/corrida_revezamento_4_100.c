// gcc -o corrida_revezamento_4_100 -pthread corrida_revezamento_4_100.c

// atletismo, revezamento 4 por 100 com passe de bastao
// são 4 pistas, 4 corredores por pista, cada corredor participa
// por 100 metros. A exclusao mutua eh dada pela linha de chegada, 
// ja que nao eh possivel que dois atletas cheguem ao mesmo tempo
// para cruzar a linha. O atleta deve obter exclusao mutua do indice
// que indica a ordem da chegada, indicar sua pista e incrementar o indice do vetor

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// --funcoes
// usada para dar passadas pelos atletas
void* correr(void* arg);
// inicializa matriz de passos dos corredores
void inicializa_matriz_passos(void);
// mostra ordem de chegada dos corredores
void mostra_resultados_corrida(void);

// --variaveis
// semaforos dos corredores
// para dizer qual corredor da pista está correndo
sem_t sem_corredor[16];

// mutex para acesso a linha de chegada
// para vencer, o corredor deve cruzar a linha de chegada
pthread_mutex_t mtx_chegada;

// mutex para printar na tela
pthread_mutex_t mtx_printar_tela;

// vetor que indica ordem de chegada, sendo o indice a ordem
// de chegada e o valor a pista, indice compartilhado
int ordem_de_chegada[4];
int ind_ordem_de_chegada = -1;

// representa quantos passos deu cada corredor
// a linha indica o corredor e a coluna sua pista
int matriz_corredor_passos[4][4];

void* correr(void* arg)
{
	int i = *((int*) arg);

	while(1)
	{
		// corredor atual tenta tomar a vez para dar passos
		// de acordo com o semaforo de corredores
		sem_wait(&sem_corredor[i]);
		
		sleep(1);
		// numero de passos dado pelo corredor 
		// aleatorio entre 1 e 10
		int passos_atual = (int) (drand48()*5 + 5);		//entre 5 e 10 para teste+
		// obtem pista
		int pista = i%4;
		// obtem corredor da pista
		int corredor = i/4; 

		// atualiza nro de passos do corredor na matriz
		matriz_corredor_passos[corredor][pista]+=passos_atual;
		// obtem numero de passos do corredor
		int passos = matriz_corredor_passos[corredor][pista];
		
		// numero maximo de passos em 100
		passos = passos>100? 100:passos;

		pthread_mutex_lock(&mtx_printar_tela);
		if(pista==0) 	  printf("%d:%d\n", corredor, passos);
		else if(pista==1) printf("\t%d:%d\n", corredor, passos);
		else if(pista==2) printf("\t\t%d:%d\n", corredor, passos);
		else if(pista==3) printf("\t\t\t%d:%d\n", corredor, passos);
		pthread_mutex_unlock(&mtx_printar_tela);

		// caso o corredor ainda nao tenha dado os 100 passos
		if(passos < 100)
		{
			// colocar permissao para correr novamente
			sem_post(&sem_corredor[i]);
		}
		// caso o corredor tenha terminado sua participacao
		else
		{
			// se o corredor atual nao for da ultima pista
			if(corredor!= 3)
			{
				// faz o passe de bastao
				// coloca a permissao para o corredor da pista a frente
				sem_post(&sem_corredor[i+4]);

				pthread_mutex_lock(&mtx_printar_tela);
				if(pista==0) 	  printf("%d:PASSOU\n", corredor);
				else if(pista==1) printf("\t%d:PASSOU\n", corredor);
				else if(pista==2) printf("\t\t%d:PASSOU\n", corredor);
				else if(pista==3) printf("\t\t\t%d:PASSOU\n", corredor);
				pthread_mutex_unlock(&mtx_printar_tela);
				
				pthread_exit(0);
			// caso seja o corredor da ultima pista
			}else
			{
				pthread_mutex_lock(&mtx_chegada);
				// incrementa indice de ordem de chegada
				ind_ordem_de_chegada++;
				ordem_de_chegada[ind_ordem_de_chegada] = pista;
				pthread_mutex_unlock(&mtx_chegada);

				pthread_mutex_lock(&mtx_printar_tela);
				if(pista==0) 	  printf("%d:CHEGOU\n", corredor);
				else if(pista==1) printf("\t%d:CHEGOU\n", corredor);
				else if(pista==2) printf("\t\t%d:CHEGOU\n", corredor);
				else if(pista==3) printf("\t\t\t%d:CHEGOU\n", corredor);
				pthread_mutex_unlock(&mtx_printar_tela);

				pthread_exit(0);
			}
		}
	}
}

void inicializa_matriz_passos(void)
{
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			matriz_corredor_passos[i][j] =0;
}

void mostra_resultados_corrida(void)
{
	printf("\n----resultados----\n");

	printf("1º-> pista %d.\n", ordem_de_chegada[0]);
	printf("2º-> pista %d.\n", ordem_de_chegada[1]);
	printf("3º-> pista %d.\n", ordem_de_chegada[2]);
	printf("4º-> pista %d.\n", ordem_de_chegada[3]);

}

int main()
{
	srand48(time(NULL));

	pthread_t corredor_thread[16];
	
	// inicializa os semaforos 
	// como no inicio apenas os 4 primeiro corredores estao correndo, 
	// eles ja começam com uma permissao enquanto os outros com nenhuma
	int permissoes = 1;
	for(int i=0; i<16; i++)
	{
		sem_init(&sem_corredor[i], 0 /*thread*/, permissoes /*permissoes*/); 
		if(i==3) permissoes=0; 
	}

	int i;
	int* id;

	// cria threads dos corredores
	for(i=0;i<16;i++)
	{
		id = (int*) malloc(sizeof(int));
		*id = i;
		pthread_create(&corredor_thread[i], NULL, correr, (void*) (id));
	}

	// espera pelos ultimos corredores
	pthread_join(corredor_thread[12], NULL);
	pthread_join(corredor_thread[13], NULL);
	pthread_join(corredor_thread[14], NULL);
	pthread_join(corredor_thread[15], NULL);

	mostra_resultados_corrida();
	
	return 0;
}