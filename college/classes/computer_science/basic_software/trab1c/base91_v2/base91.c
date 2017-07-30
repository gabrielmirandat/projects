
/************************************************************************/
// Universidade de Brasilia
//
// Codificacao e decodificacao base 85
//
// Ultima modificacao - 14/09/2016
//
// Bárbara Varanda Rangel
// Gabriel Martins de Miranda
// Jadiel Teófilo Amorim de Oliveira
// Marcos Cordeiro Fleury
// Túlio de Carvalho Matias
//
/************************************************************************/

#ifdef __WIN32

#include <windows.h>
#include "base91.h"

double benchmark() // Funcao que retorna tempo atual
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

#else

#define _POSIX_C_SOURCE 199309L
#include <sys/resource.h>
// #include <sys/time.h>
#include <time.h>
#include "base91.h"

// double benchmark() // Funcao que retorna tempo atual
// {
//     struct timeval t;
// 	// struct timezone tzp;
//     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, ...);
//     return t.tv_sec + t.tv_usec*1e-6;
// }

#endif

//Variavel com o tamanho do arquivo
int arq_tam_bytes = 0;

int main(int argc, char **argv)
{
	// float bench = benchmark();
	uint8_t *arquivo_entrada = NULL;
	char *operacao 			 = NULL;
	uint16_t *texto;


	//Argumentos - se foram passado como parametro na execucao, utiliza-se dos mesmos
	if(argc == 3 )
	{
		arquivo_entrada 	= argv[1];
		operacao 			= argv[2];
	}
	else //Se algum dos dois nao foi especificado (arquivo ou operacao)
	{
		operacao  			= (char*) malloc(sizeof(char));
		arquivo_entrada  	= (char*) malloc(10*sizeof(char));
		//tamanho maximo do nome do arquivo em 10 caracteres

		printf("Digite a operacao desejada:\n~>");
		scanf("%c", operacao);
		getchar();

		printf("Digite o arquivo de entrada desejado:\n~>");
		scanf("%s", arquivo_entrada);
		getchar();
	}


	//chama a funcao que le o texto do arquivo selecionado
	texto = lerArq(arquivo_entrada);

	// Verifica se deseja-se codificar ou decodificar
	if(*operacao  == 'c')
		codificar(texto);
	else
		if(*operacao  == 'd')
			decodificar(texto);
		else
		{
			printf("Comando de execucao incorreto, consulte o readmeBasE91 para instrucoes\n");
			exit(0);
		}
		
	free(texto);
	// bench -= benchmark();
	// printf("%f\n", - bench);
	return 0;

}

/**
 * le o texto do arquivo, devolve um ponteiro para a string
 * @param 	arquivo_entrada - nome do arquivo de entrada
 */
uint16_t *lerArq(uint8_t *arquivo_entrada)
{
	
	uint16_t *texto;
	FILE * fp = NULL;

	fp = fopen(arquivo_entrada, "rb");
	if (fp == NULL) 
	{
		printf("Arquivo nao encontrado.\n");
		exit(1);
	}

	//Pega o tamanho do arquivo para a alocacao
	fseek(fp, 0, SEEK_END);
	arq_tam_bytes = ftell(fp);
	fseek(fp,0,SEEK_SET);

	// aloca a memoria
	texto = (uint16_t *) malloc(arq_tam_bytes+1);

	// Realiza a leitura
	fread(texto, arq_tam_bytes, 1 , fp);
	
	fclose(fp);
	return texto;
}

/**
 * le o texto do arquivo, devolve um ponteiro para a string
 * @param 	texto - ponteiro vetor  inteiro 8 bits a ser codificada
 * @param 	arquivo de saida com o a codificacao
 */
void codificar(uint16_t *texto)
{
	uint8_t saida8bit[2];
	uint16_t valor_decimal = 0;

	
	FILE *fp = NULL;
	//Abre arquivo para colocar a saida
	fp = fopen("codificado.b91", "w");

	int qtd_iteracoes = (arq_tam_bytes*8/13);
	int qtd_bits_sobram = (arq_tam_bytes*8%13);

	for(int i=0;i < qtd_iteracoes; i++)
	{
		// pega o valor inteiro dos 16 bits e incrementa 
		// ponteiro para os proximos 16 bits
		valor_decimal = *texto++;	// (*texto), texto++;
		// faz texto retornar 3 bits
		texto >>= 3;			
		// para pegar apenas os 13 bits
		valor_decimal >>= 3;
		
		saida8bit[0] = ENC_TAB[valor_decimal/91];	
		saida8bit[1] = ENC_TAB[valor_decimal%91];	
		fprintf(fp, "%c", saida8bit[0]);
		fprintf(fp, "%c", saida8bit[1]);
	}

	// trata bits restantes
	valor_decimal = *texto;
	valor_decimal >>= (3+13-qtd_bits_sobram);
	saida8bit[0] = ENC_TAB[valor_decimal/91];	
	saida8bit[1] = ENC_TAB[valor_decimal%91];	
	fprintf(fp, "%c", saida8bit[0]);
	fprintf(fp, "%c", saida8bit[1]);

	fclose(fp);

}


/**
 * le o texto do arquivo, devolve um ponteiro para a string
 * @param 	texto ponteiro vetor  inteiro 8 bits a ser decodificada
 * @param 	arquivo de saida com o a decodificacao
 */
void decodificar(uint16_t *texto){

}