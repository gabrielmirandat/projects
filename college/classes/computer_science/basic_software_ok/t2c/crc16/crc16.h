/************************************************************************/
// Universidade de Brasilia
//
// Codificacao e decodificacao base 85
//
// Ultima modificacao - 23/09/2016
//
// Bárbara Varanda Rangel
// Gabriel Martins de Miranda
// Jadiel Teófilo Amorim de Oliveira
// Marcos Cordeiro Fleury
// Túlio de Carvalho Matias
//
/************************************************************************/


/*
As funções de CRC premitem tanto o cálculo do CRC de um arquivo de entrada 
(seja passado via linha de comando ou lido pelo programa), quanto a checagem se 
o arquivo está integro, com base no CRC, recebendo um segundo arquivo com o CRC, 
ou sendo passado via linha de comando. O CRC, por padrão, é impresso no terminal.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>

#define CRC_POL 0x8005 // x^16+ x^15+ x^2+ 1


//funcao de leitura
uint8_t* lerArq(uint8_t *arquivo_entrada);

// Funcao de calculo CRC
int calcularCRC(uint8_t *texto);

// Funcao que trunca os bits de um byte
uint8_t reverter(uint8_t bin);


