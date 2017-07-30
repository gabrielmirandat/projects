/************************************************************************
* Universidade de Brasilia
* Hash MD5
* Ultima modificacao - 23/09/2016
*
* Bárbara Varanda Rangel
* Gabriel Martins de Miranda
* Jadiel Teófilo Amorim de Oliveira
* Marcos Cordeiro Fleury
* Túlio de Carvalho Matias
************************************************************************/

#include "md5.h"

void guia()
{
	printf("Para rodar:\n");
	printf("./md5\n");
	printf("./md5 <arquivo_entrada>\n");
	printf("./md5 <arquivo_entrada> <arquivo_saida>\n\n");
	
}

int main(int argc, char* argv[])
{
    // para mediçao do tempo computacional
    float tempo_inicio = 0, tempo_fim = 0, tempo_gasto;
    // arquivo de entrada
	char *arquivo_entrada   = NULL;
	// arquivo de saída
	char *arquivo_saida     = NULL;
	// mensagem
	uint8_t* mensagem		= NULL;

	// informa como o programa deve ser usado
	guia();

    // pega o momento inicial
    tempo_inicio = (float)clock()/CLOCKS_PER_SEC;

	// utiliza parametros de entrada ou solicita ao usuario
	if(argc >= 3)
	{
		arquivo_entrada 	= argv[1];
		arquivo_saida		= argv[2];
		
	}
	else if(argc == 2)
	{
		arquivo_entrada 	= argv[1];
		arquivo_saida  	    = (char*) malloc(11*sizeof(char));

		printf("(max:10) Arquivo de saida: \n->");
		scanf("%s", arquivo_saida);
		getchar();
	}
	else
	{
		arquivo_entrada  	= (char*) malloc(11*sizeof(char));
		arquivo_saida  	    = (char*) malloc(11*sizeof(char));
		
		printf("(max:10) Arquivo de entrada: \n->");
		scanf("%s", arquivo_entrada);
		getchar();

		printf("(max:10) Arquivo de saida: \n->");
		scanf("%s", arquivo_saida);
		getchar();
	}


	mensagem = lerArquivo(arquivo_entrada);
	mensagem = concatenarBits(mensagem);
	mensagem = concatenarTamanho(mensagem);
	processa(mensagem);
	mostraResultado(arquivo_saida);

	free(mensagem);

	// pega o tempo em que acabou 
    tempo_fim = (float)clock()/CLOCKS_PER_SEC; 

    // pega o tempo da duracao do programa
    tempo_gasto = tempo_fim - tempo_inicio; 

    // imprime o tempo gasto
    printf("O tempo gasto foi %fs\n", tempo_gasto); 

	return EXIT_SUCCESS;

}