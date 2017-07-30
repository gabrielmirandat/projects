#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basE91.h"

static char *buffer_entrada, *buffer_saida;
static size_t tam_buffer_entrada, tam_linha_saida;
static struct basE91 b91;

static void codificar(void);
static void decodificar(void);

static void codificar(void)
{
	size_t l = tam_linha_saida;
	size_t ltotal = 0;
	size_t i, s;
	char x;

	while ((s = fread(buffer_entrada, 1, tam_buffer_entrada, stdin)) > 0) {
		s = basE91_encode(&b91, buffer_entrada, s, buffer_saida);
		for (i = 0; l <= s; l += tam_linha_saida) {
			x = buffer_saida[l];
			buffer_saida[l] = '\0';
			puts(buffer_saida + i);
			++ltotal;
			buffer_saida[l] = x;
			i = l;
		}
		fwrite(buffer_saida + i, 1, s - i, stdout);
		l -= s;
	}
	s = basE91_encode_end(&b91, buffer_saida);
	if (s || l < tam_linha_saida) {
		buffer_saida[s] = '\0';
		if (s > l) {
			x = buffer_saida[1];
			buffer_saida[1] = '\0';
			puts(buffer_saida);
			++ltotal;
			buffer_saida[0] = x;
		}
		puts(buffer_saida);
		++ltotal;
	}

	// sprintf(status, "\t%lu lines\n", (unsigned long) ltotal);
}

static void decodificar(void)
{
	size_t s;

	while ((s = fread(buffer_entrada, 1, tam_buffer_entrada, stdin)) > 0) {
		s = basE91_decode(&b91, buffer_entrada, s, buffer_saida);
		fwrite(buffer_saida, 1, s, stdout);
	}
	s = basE91_decode_end(&b91, buffer_saida);	/* empty bit queue */
	fwrite(buffer_saida, 1, s, stdout);
}


int main(int argc, char **argv)
{
	// tamanho do buffer para 64 KiB
	size_t tam_buffer 		= 65536;	
	// seta o tamanho da linha de saída pra 76
	tam_linha_saida 		= 76;
	// arquivo de entrada
	char *arquivo_entrada   = NULL;
	// arquivo de saída
	char *arquivo_saida     = NULL;
	// operação desejada
	char *operacao 			= NULL;

	// utiliza parametros de entrada ou solicita ao usuario
	if(argc == 4){
		arquivo_entrada 	= argv[1];
		arquivo_saida		= argv[2];
		operacao 			= argv[3];
	}
	else
	{
		arquivo_entrada  	= (char*) malloc(11*sizeof(char));
		arquivo_saida  	    = (char*) malloc(11*sizeof(char));
		operacao  			= (char*) malloc(sizeof(char));
		
		printf("arquivo de entrada: (max:10)\n");
		scanf("%s", arquivo_entrada);
		getchar();

		printf("arquivo de saida: (max:10)\n");
		scanf("%s", arquivo_saida);
		getchar();
		

		printf("operacao desejada: (c ou d)\n~>");
		scanf("%c", operacao);
		getchar();
	}
	
	// aloca espaço para o buffer de saída
	// buffer de saida eh um buffer com 65536
	// bytes
	buffer_saida = malloc(tam_buffer);
	// se ocorreu erro
	if (!buffer_saida) 
	{
		fputs("\nerro ao alocar memoria ao buffer.\n", stderr);
		return EXIT_FAILURE;
	}

	// redireciona toda a entrada da entrada padrão
	// para o arquivo de entrada. 
	if (freopen(arquivo_entrada, "r", stdin) != stdin) 
	{
		perror(arquivo_entrada);
		return EXIT_FAILURE;
	}

	// redireciona toda a saída que normalmente iria para 
	// a saída padrão para o arquivo de saída. 
	if (freopen(arquivo_saida, "w", stdout) != stdout) 
	{
		perror(arquivo_saida);
		return EXIT_FAILURE;
	}	

	basE91_init(&b91);
	if(*operacao == 'c')
	{
		// a entender
		// definindo tamanho do buffer de entrada 
		// para a codificação
		tam_buffer_entrada = (tam_buffer - 2) << 4;
		tam_buffer_entrada = tam_buffer_entrada / 29;
		// definindo buffer de entrada com
		// sobreposição parcial
		buffer_entrada = buffer_saida + tam_buffer - tam_buffer_entrada;
		// chama a função de codificar
		codificar();
	}else if (*operacao == 'd')
	{
		// a entender
		// definindo tamanho do buffer de entrada 
		// para a decodificação
		tam_buffer_entrada = (tam_buffer - 1) << 3;
		tam_buffer_entrada = tam_buffer_entrada / 15;
		// definindo buffer de entrada com
		// sobreposição para uso eficiente de 
		// memória
		buffer_entrada = buffer_saida + 1;
		// chama a função de decodificar
		decodificar();
	}

	// libera buffer de saída
	free(buffer_saida);

	return EXIT_SUCCESS;
}
