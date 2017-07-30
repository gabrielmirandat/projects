/************************************************************************/
// Universidade de Brasilia
//
// Resolvedor de equacao posfixa atraves de entrada infixa
// posfixa refere-se a notacao polonesa reversa
// 
//
// Ultima modificacao - 07/10/2016
//
// Bárbara Varanda Rangel
// Gabriel Martins de Miranda
// Jadiel Teófilo Amorim de Oliveira
// Marcos Cordeiro Fleury
// Túlio de Carvalho Matias
//
/************************************************************************/



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>

#ifdef WINDOWS
  #define atoll(S) _atoi64(S)
#endif


// dados obtidos do pop da pilha
struct dados
{
	uint64_t num;
	char car;
};

// nodos da pilha
struct nodo{
	uint64_t num48;
	char caracter;
	struct nodo* prox;
};

// pilha como nodo do topo da pilha
struct pilha{
	struct nodo * first;
};




// converte da infixa para a posfixa 
void in_to_pos_fixed(uint8_t* exp );

// funcao de calculo soma arit 48bits
uint64_t soma(uint64_t num,uint64_t num_aux);

// funcao de calculo subtracao arit 48bits
uint64_t subtracao(uint64_t num,uint64_t num_aux);

// funcao de calculo multiplicacao arit 48bits
uint64_t multiplicacao(uint64_t num,uint64_t num_aux);

// funcao de calculo divisao arit 48bits
uint64_t divisao(uint64_t num,uint64_t num_aux);

// funcao para a avaliacao da expressao
void avalEx(uint8_t* exp );

