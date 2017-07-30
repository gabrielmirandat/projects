/************************************************************************
* Universidade de Brasilia
* Hash MD5
* Ultima modificacao - 30/09/2016
*
* Bárbara Varanda Rangel
* Gabriel Martins de Miranda
* Jadiel Teófilo Amorim de Oliveira
* Marcos Cordeiro Fleury
* Túlio de Carvalho Matias
************************************************************************/

// consideraçoes: As funções de hash devem receber como parâmetros um ou dois arquivos, 
// sendo ambos opcionais, o primeiro de entrada e o segundo de saída. Caso não sejam passados 
// via linha de comando devem ser fornecidos pelo usuário. O hash da string ou arquivo, por padrão, 
// é impresso no terminal.

#ifndef _MD5_H_
#define _MD5_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
// #include <inttypes.h>

// funcao para ler arquivo de entrada
uint8_t* lerArquivo(uint8_t *arquivo_entrada);

// funcao para concatenar os bits
uint8_t* concatenarBits(uint8_t *texto);

// funcao para concatenar o tamanho 
uint8_t* concatenarTamanho(uint8_t *texto);

// funcao F(X,Y,Z) = XY v not(X) Z
uint32_t F(uint32_t X, uint32_t Y, uint32_t Z);

// funcao G(X,Y,Z) = XZ v Y not(Z)
uint32_t G(uint32_t X, uint32_t Y, uint32_t Z);

// funcao H(X,Y,Z) = X xor Y xor Z
uint32_t H(uint32_t X, uint32_t Y, uint32_t Z);

// funcao I(X,Y,Z) = Y xor (X v not(Z))
uint32_t I(uint32_t X, uint32_t Y, uint32_t Z);

// processa cada bloco de 16 palavras
// baseados no RFC proposto e no pseudocodigo
// de https://pt.wikipedia.org/wiki/MD5
void processa();

// mostra o resultado do buffer md5
void mostraResultado(char* arquivo_saida);

#endif // _MD5_H_


          
          
          

