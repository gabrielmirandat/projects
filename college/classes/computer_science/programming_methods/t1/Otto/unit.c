/*
TRABALHO 1
Nome: OTÁVIO ALVES DIAS
Matrícula: 12/0131480
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "unit.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

/* Função para testar se a função CriarLista funciona corretamente. Verifica se o ponteiro retornado é NULL. */
void TesteCriarLista(void){
	ListaDupla* lis;
	lis = CriarLista();
	CU_ASSERT_PTR_NULL(lis);
}

/* Função para testar se a função CriarLista funciona corretamente. Verifica se o ponteiro inicio e fim retornados são NULL. */
void TesteCriarPosicao(void){
	Posicao* p;
	p = CriarPosicao();
	CU_ASSERT_PTR_NULL(p->fim);
	CU_ASSERT_PTR_NULL(p->inicio);
}

/*Função para testar se a função que verifica se uma lista está vazia funciona corretamente. Verifica se o retorn é 1*/
void TesteVazia(void){
	ListaDupla* lis;
	int retorno;
	lis = CriarLista();
	retorno = Vazia(lis);
	CU_ASSERT_TRUE(retorno);
}

/*Função para testar se a inserção no inicio de uma lista funciona corretamente. Verifica se o retorno é diferente de NULL e se a palavra inserida consta na lista*/
void TesteInserirListaInicio(void){
	ListaDupla* lis;
	lis = CriarLista();
	lis = InserirListaInicio(lis,"Abacaxi");
	CU_ASSERT_PTR_NOT_NULL(lis);
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Abacaxi");
}

/*Função para testar se a inserção no fim de uma lista funciona corretamente.Verifica se o retorno é diferente de NULL, se as palavras inseridas constam na lista e se o ponteiro anterior foi corretamente alocado*/
void TesteInserirListaFinal(void){
	ListaDupla* lis;
	Posicao* p;
	lis = CriarLista();
	p = CriarPosicao();
	lis = InserirListaFinal(lis,p,"Banana");
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Banana");
	lis = InserirListaFinal(lis,p,"Manga");
	CU_ASSERT_STRING_EQUAL(lis->prox->informacao,"Manga");
	CU_ASSERT_STRING_EQUAL(lis->prox->ant->informacao,"Banana");
}

/*Função para testar se a remoção de um elemento no inicio da lista funciona corretamente. Verifica se a informação restante é igual a inicial*/
void TesteRetirarListaInicio(void){
	ListaDupla* lis;
	lis = CriarLista();
	lis = InserirListaInicio(lis,"Abacaxi");
	lis = InserirListaInicio(lis,"Banana");
	lis = RetirarListaInicio(lis);
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Abacaxi");
}

/*Função para testar se a remoção de um elemento no final da lista funciona corretamente. Verifica o p->fim se é igual a informação inicial*/
void TesteRetirarListaFinal(void){
	ListaDupla* lis;
	Posicao* p;
	lis = CriarLista();
	p = CriarPosicao();
	lis = InserirListaFinal(lis,p,"Banana");
	lis = InserirListaFinal(lis,p,"Manga");
	p = RetirarListaFinal(p);
	CU_ASSERT_STRING_EQUAL(p->fim->informacao,"Banana");
}
/*Função para testar se a função de busca em uma lista funciona corretamente.*/
void TesteBuscarLista(void){
	ListaDupla* lis;
	ListaDupla* info;
	Posicao* p;
	p = CriarPosicao();
	lis = CriarLista();
	lis = InserirListaFinal(lis,p,"Abacaxi");
	lis = InserirListaFinal(lis,p,"Banana");
	lis = InserirListaFinal(lis,p,"Manga");
	info = BuscarLista(lis,"Banana");
	CU_ASSERT_STRING_EQUAL(info->informacao,"Banana");
}

/*Função para testar se a remoção de um elemento em qualquer da lista funciona corretamente.*/
void TesteRetirarLista(void){
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = InserirListaFinal(lis,p,"Abacaxi");
	lis = InserirListaFinal(lis,p,"Banana");
	lis = InserirListaFinal(lis,p,"Manga");
	lis = RetirarLista(p,lis,"Banana");
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Abacaxi");
	CU_ASSERT_STRING_EQUAL(lis->prox->informacao,"Manga");
}



/*Função para testar se a inserção ordenada de elementos na lista funciona corretamente.*/
void TesteInserirOrdenado(void){
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = InserirOrdenado(p,lis,"Manga");
	lis = InserirOrdenado(p,lis,"Banana");
	lis = InserirOrdenado(p,lis,"Abacaxi");
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Abacaxi");
	CU_ASSERT_STRING_EQUAL(lis->prox->informacao,"Banana");
	CU_ASSERT_STRING_EQUAL(lis->prox->prox->informacao,"Manga");
}

/*Função para testar se os indices de elementos na lista foram ordenados corretamente.*/
void TesteArrumarIndice(void){
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = InserirOrdenado(p,lis,"Manga");
	lis = InserirOrdenado(p,lis,"Banana");
	lis = InserirOrdenado(p,lis,"Abacaxi");
	lis = ArrumarIndice(lis);
	CU_ASSERT_EQUAL(lis->indice,1);
	CU_ASSERT_EQUAL(lis->prox->indice,2);
	CU_ASSERT_EQUAL(lis->prox->prox->indice,3);
}

/*Função para testar se a inserção de um elemento em um dado indice da lista funciona corretamente.*/
void TesteInserirIndice(void){
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = InserirOrdenado(p,lis,"Manga");
	lis = InserirOrdenado(p,lis,"Banana");
	lis = InserirOrdenado(p,lis,"Abacaxi");
	lis = ArrumarIndice(lis);
	lis = InserirIndice(p,lis,"Caqui",2);
	CU_ASSERT_STRING_EQUAL(lis->prox->informacao,"Caqui");
}


/*Função para testar se a remoção de um elemento em um dado indice da lista funciona corretamente.*/
void TesteRetirarIndice(void){
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = InserirOrdenado(p,lis,"Manga");
	lis = InserirOrdenado(p,lis,"Banana");
	lis = InserirOrdenado(p,lis,"Abacaxi");
	lis = ArrumarIndice(lis);
	lis = RemoverIndice(p,lis,2);
	CU_ASSERT_STRING_EQUAL(lis->prox->informacao,"Manga");
}

/*Função para testar se a leitura de um arquivo é efetuada com sucesso.*/
void TesteLerArquivo(void){
	FILE *fp=NULL;
	ListaDupla* LerArquivo();
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = LerArquivo(p,lis,fp,"leitura.txt");
	CU_ASSERT_PTR_NOT_NULL(lis);
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Abacaxi");
}

/*Função para testar se a gravação de um arquivo é efetuada com sucesso.*/
void TesteGravarArquivo(void){
	FILE *fp=NULL;
	ListaDupla* lis;
	lis = CriarLista();
	Posicao* p;
	p = CriarPosicao();
	lis = InserirOrdenado(p,lis,"Manga");
	lis = InserirOrdenado(p,lis,"Banana");
	lis = InserirOrdenado(p,lis,"Abacaxi");
	lis = ArrumarIndice(lis);
	GravarArquivo(lis,fp,"gravacao.txt");
	lis = LerArquivo(p,lis,fp,"gravacao.txt");
	CU_ASSERT_PTR_NOT_NULL(lis);
	CU_ASSERT_STRING_EQUAL(lis->informacao,"Abacaxi");
}



	