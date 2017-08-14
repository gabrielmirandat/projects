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

uint64_t tamanho_arquivo = 0;
uint64_t tamanho_padd_bits = 0;
uint64_t tamanho_padd_tam = 0;

// estrutura buffer (A,B,C,D) para calcular hash da mensagem
struct md5
{
	uint32_t A; 
	uint32_t B;
	uint32_t C;
	uint32_t D;
} bmd5 = {.A = 0x67452301, .B = 0xefcdab89, .C = 0x98badcfe, .D = 0x10325476};

// rotacao circular a esquerda
#define SHIFT_ESQ_CIRC(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

// funcao para ler arquivo de entrada
uint8_t* lerArquivo(uint8_t *arquivo_entrada)
{
	// mensagem completa lida do arquivo
	uint8_t *mensagem;
	FILE *entrada_fp = NULL;

	entrada_fp = fopen(arquivo_entrada, "rb");
	if (entrada_fp == NULL) {
		printf("arquivo nao encontrado.\n");
		exit(1);
	}

	// pega tamanho do arquivo para alocacao
	fseek(entrada_fp, 0, SEEK_END);
	tamanho_arquivo = ftell(entrada_fp);
	fseek(entrada_fp,0,SEEK_SET);

	// aloca memoria
	mensagem = (uint8_t*) malloc(tamanho_arquivo);
	
	// realiza leitura
	fread(mensagem, tamanho_arquivo, 1 , entrada_fp);

	// mostra na tela tamanho em bytes do arquivo
	printf("tamanho_arquivo: %lu\n", tamanho_arquivo);

	// mostra mensagem
#ifdef DEBUG_MEM	
	for(int i=0, j=0; i<tamanho_arquivo; i++, j++)
	{
		printf("%x", mensagem[i]);
		if(j==10){printf("\n"); j=0;}
	}
	printf("\n\n");
#endif	

	// fecha arquivo
	fclose(entrada_fp);
	
	return mensagem;
}

// funcao para concatenar os bits
uint8_t* concatenarBits(uint8_t *mensagem)
{
	// quantidade de padding para mensagem ser 
	// congruo a 56 modulo 64
	int padding;
	// mensagem apos a concatenacao
	uint8_t *mensagem_concatenada, *ponteiro;
	
	int resto = tamanho_arquivo%64;
	if(resto<56) padding = 56 - resto;
	else padding = 64-resto + 56;

	// tamanho da mensagem com padding
	tamanho_padd_bits = tamanho_arquivo + padding;

	// realoca espaco da mensagem incluindo padding
	mensagem_concatenada = (uint8_t*) realloc(mensagem, tamanho_padd_bits);

	// mostra tamanho com padding
	printf("tamanho_padd_bits: %lu\n", tamanho_padd_bits);

	// inclui o bit 1 ordem baixa primeiro
	ponteiro = &mensagem_concatenada[tamanho_arquivo];
	ponteiro[0] = 0x80;
	
	// inclui os zeros do padding
	for(int i=1; i<padding-1; i++)
	{
		ponteiro[i]=0x00;
	}

	// mostra mensagem apos padding
#ifdef DEBUG_MEM	
	for(int i=0,j=0; i<tamanho_padd_bits; i++,j++)
	{
		printf("%x", mensagem_concatenada[i]);
		if(j==10){printf("\n"); j=0;}
	}
	printf("\n\n");
#endif

	return 	mensagem_concatenada;
}

// funcao para concatenar o tamanho 
uint8_t* concatenarTamanho(uint8_t *mensagem)
{
	// ordens alta e baixa de 32 bits da mensagem
	// de entrada
	uint32_t baixo_32b, alto_32b;
	uint64_t tamanho_64b;
	// mensagem apos a concatenacao
	uint8_t *mensagem_concatenada, *ponteiro;
	// novo tamanho da mensagem, do passo anterior
	// adicionada do tamanho da mensagem original 
	// em 64 bits
	tamanho_padd_tam = tamanho_padd_bits + 8;

	// realoca espaco da mensagem incluindo padding
	mensagem_concatenada = (uint8_t*) realloc(mensagem, tamanho_padd_tam);

	// mostra tamanho com padding
	printf("tamanho_padd_tam: %lu\n", tamanho_padd_tam);

	// divide os 64 bits em ordem alta e baixa
	// alto_32b = tamanho_arquivo >> 32;
	// baixo_32b = tamanho_arquivo;

	tamanho_64b = 8*tamanho_arquivo; 			
    // memcpy(mensagem + tamanho_padd_bits, &bits_len, 4);
 	ponteiro = &mensagem_concatenada[tamanho_padd_bits];
	ponteiro[0] = tamanho_64b;
	ponteiro[1] = tamanho_64b >> 8;
	ponteiro[2] = tamanho_64b >> 16;
	ponteiro[3] = tamanho_64b >> 24;

	ponteiro[4] = tamanho_64b >> 32;
	ponteiro[5] = tamanho_64b >> 40;
	ponteiro[6] = tamanho_64b >> 48;
	ponteiro[7] = tamanho_64b >> 56;
	
	// mostra nova mensagem concatenada
#ifdef DEBUG_MEM		
	for(int i=0, j=0; i<tamanho_padd_tam; i++, j++)
	{
		printf("%x", mensagem_concatenada[i]);
		if(j==10){printf("\n"); j=0;}
	}
	printf("\n");
#endif	

	return 	mensagem_concatenada;
}

// funcao F(X,Y,Z) = XY v not(X) Z
uint32_t F(uint32_t X, uint32_t Y, uint32_t Z)
{
	return ((X & Y) | (~X & Z));
}

// funcao G(X,Y,Z) = XZ v Y not(Z)
uint32_t G(uint32_t X, uint32_t Y, uint32_t Z)
{
	return ((X & Z) | (Y & ~Z));;
}

// funcao H(X,Y,Z) = X xor Y xor Z
uint32_t H(uint32_t X, uint32_t Y, uint32_t Z)
{
	return X ^ Y ^ Z;
}

// funcao I(X,Y,Z) = Y xor (X v not(Z))
uint32_t I(uint32_t X, uint32_t Y, uint32_t Z)
{
	return Y ^ (X | ~Z);
}

// processa cada bloco de 16 palavras
// baseados no RFC proposto e no pseudocodigo
// de https://pt.wikipedia.org/wiki/MD5
void processa(uint8_t *mensagem)
{
	uint32_t *M, AA, BB, CC, DD, X[16];
	int N;
	// usa parte binaria dos senos dos inteiros (em radianos) como constante
	// parte inteira de 4294967296 * abs(sin(i))
	uint32_t T[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

    // shifts usados em cada passo do algoritmo md5
    uint32_t s[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

	// olha a mensagem em passos de 32 bits
	// e obtem tamanho considerando 32 bits
	// seja M[0 ... N-1] as palavras da mensagem resultante,
	// em que N eh um multiplo de 16
	M = (uint32_t*) mensagem;
	// numero de palavras na mensagem
	N = tamanho_padd_tam / 4;

	// processa cada bloco de 16 palavras
	for(int n=0; n<N/16; n++)
	{
		// copia bloco n em X
     	for(int j=0; j<16;j++)
     	{
     		X[j] = M[n*16+j];
     	}

     	// salva A como AA, B como BB, C como CC e D como DD
     	AA = bmd5.A;
     	BB = bmd5.B;
		CC = bmd5.C;
	    DD = bmd5.D;

	    // sao 4 passos de 16 operacoes
        for(int i = 0; i<64; i++)
        {
			uint32_t f, g;
 
            /* passo 1 */
		    /* Let [abcd k s i] denote the operation a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s). */
		    /* Do the following 16 operations. */
		    /* [ABCD  0  7  1]  [DABC  1 12  2]  [CDAB  2 17  3]  [BCDA  3 22  4] */
		    /* [ABCD  4  7  5]  [DABC  5 12  6]  [CDAB  6 17  7]  [BCDA  7 22  8] */
		    /* [ABCD  8  7  9]  [DABC  9 12 10]  [CDAB 10 17 11]  [BCDA 11 22 12] */
		    /* [ABCD 12  7 13]  [DABC 13 12 14]  [CDAB 14 17 15]  [BCDA 15 22 16] */
            if (i < 16) 
            {
                f = F(BB,CC,DD);
                g = i;
            } 
            /* passo 2 */
		    /* Let [abcd k s i] denote the operation a = b + ((a + G(b,c,d) + X[k] + T[i]) <<< s). */
		    /* Do the following 16 operations. */
		    /* [ABCD  1  5 17]  [DABC  6  9 18]  [CDAB 11 14 19]  [BCDA  0 20 20] */
		    /* [ABCD  5  5 21]  [DABC 10  9 22]  [CDAB 15 14 23]  [BCDA  4 20 24] */
		    /* [ABCD  9  5 25]  [DABC 14  9 26]  [CDAB  3 14 27]  [BCDA  8 20 28] */
		    /* [ABCD 13  5 29]  [DABC  2  9 30]  [CDAB  7 14 31]  [BCDA 12 20 32] */
            else if (i < 32) 
            {
                f = G(BB,CC,DD);
                g = (5*i + 1) % 16;
            } 
            /* passo 3 */
		    /* Let [abcd k s t] denote the operation a = b + ((a + H(b,c,d) + X[k] + T[i]) <<< s). */
		    /* Do the following 16 operations. */
		    /* [ABCD  5  4 33]  [DABC  8 11 34]  [CDAB 11 16 35]  [BCDA 14 23 36] */
		    /* [ABCD  1  4 37]  [DABC  4 11 38]  [CDAB  7 16 39]  [BCDA 10 23 40] */
		    /* [ABCD 13  4 41]  [DABC  0 11 42]  [CDAB  3 16 43]  [BCDA  6 23 44] */
		    /* [ABCD  9  4 45]  [DABC 12 11 46]  [CDAB 15 16 47]  [BCDA  2 23 48] */
            else if (i < 48) 
            {
                f = H(BB,CC,DD);
                g = (3*i + 5) % 16;          
            } 
            /* passo 4 */
		    /* Let [abcd k s t] denote the operation a = b + ((a + I(b,c,d) + X[k] + T[i]) <<< s). */
		    /* Do the following 16 operations. */
		    /* [ABCD  0  6 49]  [DABC  7 10 50]  [CDAB 14 15 51]  [BCDA  5 21 52] */
		    /* [ABCD 12  6 53]  [DABC  3 10 54]  [CDAB 10 15 55]  [BCDA  1 21 56] */
		    /* [ABCD  8  6 57]  [DABC 15 10 58]  [CDAB  6 15 59]  [BCDA 13 21 60] */
		    /* [ABCD  4  6 61]  [DABC 11 10 62]  [CDAB  2 15 63]  [BCDA  9 21 64] */
			else 
            {
                f = I(BB,CC,DD);
                g = (7*i) % 16;
            }

            uint32_t temp = DD;
            DD = CC;
            CC = BB;
            BB = BB + SHIFT_ESQ_CIRC((AA + f + T[i] + X[g]), s[i]);
            AA = temp;

            #ifdef DEBUG_ITER
            	if(i<5) printf("\n debug %d: AA=%x;BB=%x;CC=%x;DD=%x", i,AA,BB,CC,DD);
            	if(i==63) printf("\n debug %d: AA=%x;BB=%x;CC=%x;DD=%x", i,AA,BB,CC,DD);
            #endif
		}
 
        // incrementa cada um dos quatro registradores pelo valor que possuia
		// antes do bloco ter começado
		bmd5.A = bmd5.A + AA;
	    bmd5.B = bmd5.B + BB;
	    bmd5.C = bmd5.C + CC;
	    bmd5.D = bmd5.D + DD;

	    #ifdef DEBUG_ITER
            printf("\n iter %d: A=%x;B=%x;C=%x;D=%x", n, bmd5.A,bmd5.B,bmd5.C,bmd5.D);
        #endif
	}
}

void mostraResultado(char* arquivo_saida)
{
	// para saida em little endian
    uint8_t *saida;
    FILE *saida_fp = fopen(arquivo_saida, "w");
 
    // mostra resultado formatado
 	saida = (uint8_t*) &bmd5.A;
    printf("\n\n%2.2x%2.2x%2.2x%2.2x", saida[0], saida[1], saida[2], saida[3]);
    fprintf(saida_fp, "%2.2x%2.2x%2.2x%2.2x", saida[0], saida[1], saida[2], saida[3]);
 
    saida = (uint8_t*) &bmd5.B;
    printf("%2.2x%2.2x%2.2x%2.2x", saida[0], saida[1], saida[2], saida[3]);
    fprintf(saida_fp, "%2.2x%2.2x%2.2x%2.2x", saida[0], saida[1], saida[2], saida[3]);

 	saida = (uint8_t*) &bmd5.C;
    printf("%2.2x%2.2x%2.2x%2.2x", saida[0], saida[1], saida[2], saida[3]);
    fprintf(saida_fp, "%2.2x%2.2x%2.2x%2.2x", saida[0], saida[1], saida[2], saida[3]);
 
    saida = (uint8_t*) &bmd5.D;
    printf("%2.2x%2.2x%2.2x%2.2x\n", saida[0], saida[1], saida[2], saida[3]);
    fprintf(saida_fp, "%2.2x%2.2x%2.2x%2.2x\n", saida[0], saida[1], saida[2], saida[3]);
    
    fclose(saida_fp);
}