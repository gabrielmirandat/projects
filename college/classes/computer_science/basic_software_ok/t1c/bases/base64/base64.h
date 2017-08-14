/************************************************************************/
// Universidade de Brasilia
//
// Codificacao e decodificacao base 85
//
// Ultima modificacao - 09/09/2016
//
// Bárbara Varanda Rangel
// Gabriel Martins de Miranda
// Jadiel Teófilo Amorim de Oliveira
// Marcos Cordeiro Fleury
// Túlio de Carvalho Matias
//
/************************************************************************/

/*When encoding, each group of 4 bytes is taken as a 32-bit binary number, 
most significant byte first (Ascii85 uses a big-endian convention). This is 
converted, by repeatedly dividing by 85 and taking the remainder, into 5 
radix-85 digits. Then each digit (again, most significant first) is encoded 
as an ASCII printable character by adding 33 to it, giving the ASCII characters 
33 ("!") through 117 ("u").
 
 Because all-zero data is quite common, an exception is made for the sake of 
 data compression, and an all-zero group is encoded as a single character "z" 
 instead of "!!!!!".
 
 Groups of characters that decode to a value greater than 232 − 1 (encoded as "s8W-!") 
 will cause a decoding error, as will "z" characters in the middle of a group. 
 White space between the characters is ignored and may occur anywhere to accommodate 
 line-length limitations.*/


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>


//Pegar o texto, dividir em segmentos de 32 bytes,
//Pegar esse valor em decimal, usar o codigo que fiz para encontrar 5 numeros em radix 85
//Cada um deles somado a 33 vira um codigo ascii

//funcao de leitura
uint8_t* lerArq(uint8_t *arquivo_entrada);

// Funcao de codificacao
void codificar(uint8_t *texto);

//Funcao de decodificacao
void decodificar(uint8_t *texto);

int8_t buscaletra(char letra);

static char tabela64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
int TAMANHO;