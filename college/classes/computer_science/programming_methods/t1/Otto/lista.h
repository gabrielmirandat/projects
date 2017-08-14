/*
TRABALHO 1
Nome: OT�VIO ALVES DIAS
Matr�cula: 12/0131480
Curso: Engenharia de Computa��o
Disciplina: M�todos de Programa��o
Turma: A
Prof: Jan Mendon�a
*/

/*	Arquivo Header	*/
#include <stdio.h>


/*	Estrutura de Lista	*/
struct listadupla{
	int indice;
	char* informacao;
	struct listadupla *prox;
	struct listadupla *ant;
};
typedef struct listadupla ListaDupla;

struct posicao{
	ListaDupla* inicio;
	ListaDupla* fim;
};
typedef struct posicao Posicao;

/*	Fun��es */
ListaDupla* CriarLista();
int Vazia();
ListaDupla* InserirListaInicio();
Posicao* CriarPosicao();
ListaDupla* InserirAux();
ListaDupla* InserirListaFinal();
void ImprimirLista();
ListaDupla* RetirarListaInicio();
Posicao* RetirarListaFinal();
ListaDupla* BuscarLista();
ListaDupla* RetirarLista();
ListaDupla* InserirOrdenado();
ListaDupla* ArrumarIndice();
ListaDupla* InserirIndice();
ListaDupla* RemoverIndice();
ListaDupla* LerArquivo();
void GravarArquivo();


