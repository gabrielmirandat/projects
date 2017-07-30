#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basE91.h"

static char *buffer_entrada, *buffer_saida;
struct basE91 b91;

void codificar(void)
{
	size_t l = tam_linha_saida;
	size_t ltotal = 0;
	size_t i, s, n;
	char x;

	while ((s = fread(buffer_entrada, 1, tam_buffer_entrada, stdin)) > 0) {
		
		// size_t basE91_encode(struct basE91 *b, const void *i, size_t len, void *o);
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
	
	// size_t basE91_encode_end(struct basE91 *b, void *o);
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

	perror("Codificado com sucesso!");
	fclose(stdout);
	printf("Codificado com sucesso!");
}

size_t basE91_encode(struct basE91 *b /*estrutura b91*/, 
					 const void *i    /*buffer_entrada*/, 
					 size_t len		  /*tamanho*/, 
					 void *o 		  /*buffer_saida*/)
{
	// *ib recebe endereço do buffer_entrada
	const unsigned char *ib = i;
	// *ob recebe endereço do buffer_saida
	unsigned char *ob = o;
	size_t n = 0;

	// enquanto nao acaba a quantidade de bytes lidos 
	// do arquivo de entrada
	while (len--) 
	{
		b->fila = b->fila | (*ib++ << b->nbits); // b->fila |= *ib++ << b->nbits;
		b->nbits = b->nbits + 8;
		
		if (b->nbits > 13) /* enough bits in fila */
		{	
			unsigned int val = b->fila & 0x1FFF; //8191

			if (val > 0x58) //88
			{
				b->fila = b->fila >> 13;
				b->nbits = b->nbits - 13;
			} else /* we can take 14 bits */
			{	
				val = b->fila & 0x3FFF; //16383
				b->fila = b->fila >> 14;
				b->nbits = b->nbits - 14;
			}
			ob[n++] = ENC_TAB[val % 91];
			ob[n++] = ENC_TAB[val / 91];
		}
	}

	return n;
}

/* process remaining bits from bit fila; write up to 2 bytes */

size_t basE91_encode_end(struct basE91 *b /*estrutura b91*/,
						 void *o 		  /*buffer_saida*/)
{
	unsigned char *ob = o;
	size_t n = 0;

	if (b->nbits) {
		ob[n++] = ENC_TAB[b->fila % 91];
		if (b->nbits > 7 || b->fila > 90)
			ob[n++] = ENC_TAB[b->fila / 91];
	}
	b->fila = 0;
	b->nbits = 0;
	b->valor = -1;

	return n;
}

void decodificar(void)
{
	size_t s;

	while ((s = fread(buffer_entrada, 1, tam_buffer_entrada, stdin)) > 0) {
		// size_t basE91_decode(struct basE91 *, const void *, size_t, void *);
		s = basE91_decode(&b91, buffer_entrada, s, buffer_saida);
		
		
		fwrite(buffer_saida, 1, s, stdout);
	}
	
	// size_t basE91_decode_end(struct basE91 *, void *);
	s = basE91_decode_end(&b91, buffer_saida);	/* empty bit fila */
	
	fwrite(buffer_saida, 1, s, stdout);
}

/* process remaining bits; write at most 1 byte */

size_t basE91_decode(struct basE91 *b /*estrutura b91*/, 
					 const void *i    /*buffer_entrada*/, 
					 size_t len		  /*tamanho*/, 
					 void *o 		  /*buffer_saida*/)
{
	// *ib recebe endereço do buffer_entrada
	const unsigned char *ib = i;
	// *ob recebe endereço do buffer_saida
	unsigned char *ob = o;
	size_t n = 0;
	unsigned int d;

	while (len--) {
		d = DEC_TAB[*ib++];
		if (d == 91)
			continue;	/* ignore non-alphabet chars */
		if (b->valor == -1)
			b->valor = d;	/* start next value */
		else {
			b->valor += d * 91;
			b->fila |= b->valor << b->nbits;
			b->nbits += (b->valor & 8191) > 88 ? 13 : 14;
			do {
				ob[n++] = b->fila;
				b->fila >>= 8;
				b->nbits -= 8;
			} while (b->nbits > 7);
			b->valor = -1;	/* mark value complete */
		}
	}

	return n;
}

size_t basE91_decode_end(struct basE91 *b /*estrutura b91*/,
						 void *o 		  /*buffer_saida*/)
{
	unsigned char *ob = o;
	size_t n = 0;

	if (b->valor != -1)
		ob[n++] = b->fila | b->valor << b->nbits;
	b->fila = 0;
	b->nbits = 0;
	b->valor = -1;

	return n;
}

void guia()
{
	printf("Para rodar:\n");
	printf("./basE91 <arquivo_entrada> <arquivo_saida> <operaçao>\n");
	printf("./base91\n\n");
}


int main(int argc, char **argv)
{
	// informa como o programa deve ser usado
	guia();

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
		
		printf("(max:10) Arquivo de entrada: \n->");
		scanf("%s", arquivo_entrada);
		getchar();

		printf("(max:10) Arquivo de saida: \n->");
		scanf("%s", arquivo_saida);
		getchar();
		

		printf("(c ou d) Operacao desejada: \n->");
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
		fputs("\nErro ao alocar memoria ao buffer.\n", stderr);
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

	// inicia estrutura de suporte
	b91.fila = 0;
	b91.nbits = 0;
	b91.valor = -1;

	if(*operacao == 'c')
	{
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
