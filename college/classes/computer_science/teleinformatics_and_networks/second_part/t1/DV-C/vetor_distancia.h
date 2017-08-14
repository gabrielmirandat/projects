// Kurose cap 4
// Medhi cap 2
// gcc -o vetor_distancia vetor_distancia.c -lm
// ./vetor_distancia entrada?.txt

#ifndef __VETOR_DIST__
#define __VETOR_DIST__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 30

// estrutura que representa a tabela vetor distancia
// que eh trocada entre os nodos
typedef struct
{
    int dist[MAX];
    int via[MAX];
} nodo;

// -- variaveis
// tabelas dos nodos
nodo roteador[MAX];    
// numero de nodos usados
// deve ser menor que MAX
int NNOS;
// matriz de custos
int matriz_custos[MAX][MAX];
// numero de convergencias para
// cada nodo
int convergencias[MAX];
// numero da maior convergencia
int maior_convergencia;
// media de convergencias finais
float media_convergencias;
// desvio padrao das convergencias finais
float desvio_convergencias;

// -- funcoes
// le o arquivo de entrada
// e obtem nodos, vizinhos e custos
int entrada(FILE* arq);
// constroi matriz com os vizinhos
// obtidos da entrada
int atribui_vizinhos_matriz(int i, int j, int valor);
// completa nao-vizinhos com infinito, 999,
// e inicializa a tabela dos nodos e
// distancia pro proprio nodo como zero
void completa_matriz();
// realiza o algoritmo de vetor distancia e
// atribui convergencias
void vetor_distancia();
// calcula media da maior_convergencia entre nodos
float media(int vetor[]);
// calcula desvio padrao da maior_convergencia entre nodos
float desvio(int vetor[], float med);
// mostra a convergencia final das tabelas
void mostra_convergencia_final();

#endif //__VETOR_DIST__