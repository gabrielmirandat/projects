#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/******************ESTRUTURAS DE DADOS**************************/  

/* registro de cada chave*/
struct registro{
  char nome[31];
};

typedef struct registro Registro;

/* no de cada página*/
struct paginas{
 Registro chave[4]; /*4 chaves da pagina (concatenado)*/
 int prr_filha[5]; /*5 filhos(paginas) da pagina PG */
 int N_DE_CHAVES; /* qtd de chaves presentes*/
 int N_DE_FILHOS; 
 int indice;
};

typedef struct paginas PAGINA;



/******************************HEADERS**************************/ 
PAGINA* inicia_pagina(PAGINA* atual);
void bytes_registro();
void leitor_arquivo(PAGINA* pag);
void concatenador();
void ordenacao( Registro* vet, int tam);
void peneira( int p, int m, Registro* vet);
void troca_posicao(Registro* vet, int ind1, int ind2);
int pesquisar(Registro* vet, int ind, char* busca);
void printar_pagina_atual_tela(PAGINA* atual);
void printar_pagina_atual_arquivo(PAGINA* atual, int byte_offset);
void construtor_B_tree(PAGINA* current);
PAGINA* recupera_info_arquivo(PAGINA* atual,int byte_offset);
void compara_arvore(int indice,char* palavra);
void inicia_constantes_globais();
void menu();
void buscar_registro(PAGINA* current);
int incluir_registro();