/*
TRABALHO 1
Nome: OTÁVIO ALVES DIAS
Matrícula: 12/0131480
Curso: Engenharia de Computação
Disciplina: Métodos de Programação
Turma: A
Prof: Jan Mendonça
*/

/*	Arquivo com o corpo das funções	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*Função de criar uma lista*/
ListaDupla* CriarLista(){
	return (NULL);
}

/*Função que verifica se uma lista está vazia*/
int Vazia(ListaDupla* lis){
	if(lis==NULL){
		return 1;
	}else{
		return 0;
	}
}

/*Função de inserção no começo da lista*/
ListaDupla* InserirListaInicio(ListaDupla* lis, char* info){
	ListaDupla* novo = (ListaDupla*)malloc(sizeof(ListaDupla));
	novo->informacao = (char*)malloc(strlen(info)*sizeof(char));
	/*INSERINDO NO INICIO DA LISTA*/
		strcpy(novo->informacao,info);
		novo->prox = lis;
		if(!Vazia(lis)){
			lis->ant = novo;
		}

	return novo;
}

/*Função para criar uma estrutura do tipo Posição*/
Posicao* CriarPosicao(void){
	Posicao* fila = (Posicao*)malloc(sizeof(Posicao));
	fila->inicio = fila->fim = NULL;
return fila;
}

/*Função auxiliar de inserção no fim da lista*/
ListaDupla* InserirAux(Posicao* Pos,char* info){
	ListaDupla* L = (ListaDupla*)malloc(sizeof(ListaDupla));
	L->informacao = (char*)malloc(strlen(info)*sizeof(char));
	strcpy(L->informacao,info);
	if(Pos->fim!=NULL){
		Pos->fim->prox = L;
		L->ant = Pos->fim;
	}
	return L;
}

/*Função primária de inserção no fim da lista*/
ListaDupla* InserirListaFinal(ListaDupla* lis,Posicao* p, char* info){
	p->fim = InserirAux(p,info);
	if(p->inicio==NULL){
		p->inicio = p->fim;
	}
	lis = p->inicio;

	return lis;
}

/*Função de impressão dos elementos da lista*/
void ImprimirLista(ListaDupla* lis){
	ListaDupla* p;
	
	if(!Vazia(lis)){
		for(p=lis;p!=NULL;p=p->prox){
			printf("Indice: %d\nInformacao: %s\n",p->indice,p->informacao);
		}
	}else{
		printf("\nA lista esta vazia.\n");
	}
}

/*Função para retirar elementos no inicio da lista*/
ListaDupla* RetirarListaInicio(ListaDupla* lis){
	ListaDupla* aux = (ListaDupla*)malloc(sizeof(ListaDupla));
	if(!Vazia(lis)){
		aux = lis->prox;
		aux->ant = NULL;
		free(lis);
		}else{
			printf("\nNao foi possivel remover.\n");
		}

return aux;
}

/*Função para retirar elementos no fim da lista*/
Posicao* RetirarListaFinal(Posicao* p){
	ListaDupla* aux = (ListaDupla*)malloc(sizeof(ListaDupla));
	aux = p->fim->ant;
	p->fim->ant->prox = NULL;	
	free(p->fim);
	p->fim = aux;
	
return p;
}

/*Função para buscar um dado elemento na lista*/
ListaDupla* BuscarLista(ListaDupla* lis,char* info){
	ListaDupla* aux;
	if(!Vazia(lis)){
		for(aux=lis;aux!=NULL;aux=aux->prox){
			if(strcmp(aux->informacao,info)==0){
				return aux;
			}
		}
	}
return NULL;
}

/*Função para remover um elemento em qualquer posição da lista*/
ListaDupla* RetirarLista(Posicao* pos,ListaDupla* lis,char* info){
	ListaDupla* aux = NULL;
	ListaDupla* p = lis;
	
	while((p!=NULL)&&(strcmp(p->informacao,info)!=0)){
		aux = p;
		p=p->prox;
	}
	if(p==NULL){
		return lis;
	}
	if(aux==NULL){
		pos->inicio = p->prox;
		lis = pos->inicio;
		lis->ant = NULL;
		free(p);
		return lis;
		}else{
			if(p->prox!=NULL){
				p->prox->ant = aux->prox;
				aux->prox = p->prox;
				free(p);
			}else{
				aux = pos->fim->ant;
				p = pos->fim->ant->ant;
				free(pos->fim);
				pos->fim = aux;
				pos->fim->ant = p;
				pos->fim->prox = NULL;
			}
		}

		return lis;
}

/*Função para inserir elementos ordenadamente em uma lista*/
ListaDupla* InserirOrdenado(Posicao* pos,ListaDupla* lis, char* info){
	ListaDupla* novo = (ListaDupla*)malloc(sizeof(ListaDupla));
	novo->informacao = (char*)malloc(strlen(info)*sizeof(char));
	strcpy(novo->informacao,info);
	novo->prox = NULL;
	novo->ant = NULL;
	ListaDupla* p=lis;
	ListaDupla* aux=lis;


	while(p!=NULL && (strcmp(p->informacao,info)<0)){
		aux=p;
		p=p->prox;
	}

	if(Vazia(lis)){
		pos->inicio = pos->fim = lis = novo;
	}else{
		if(p==NULL) {/*se p=null, é a última posição*/
			aux->prox=novo;
			novo->ant=aux;
			pos->fim=novo;
		} else {
			if (aux==p) {/*inserção no inicio*/
				novo->prox=p;
				p->ant=novo;
				pos->inicio= lis = novo;
			} else {/*inserção no meio*/
				aux->prox=novo;
				novo->ant=aux;
				p->ant=novo;
				novo->prox=p;
			}
		}
	}

return lis;
}

/*Função que arruma os indices posição de cada elemento da lista*/
ListaDupla* ArrumarIndice(ListaDupla* lis){
	ListaDupla* p;
	int contador=0;
	for(p=lis;p!=NULL;p=p->prox){
		contador++;
		p->indice=contador;
	}
	return lis;
}

/*Função para inserção de um elemento em um dado indice*/
ListaDupla* InserirIndice(Posicao* pos,ListaDupla* lis, char* info, int indice){
	ListaDupla* novo = (ListaDupla*)malloc(sizeof(ListaDupla));
	ListaDupla* p=lis;
	ListaDupla* aux;
	novo->informacao = (char*)malloc(strlen(info)*sizeof(char));
	strcpy(novo->informacao,info);
	novo->indice = indice;
	
	if(Vazia(lis)){ /*Não tem elemento, então insere novo*/
		novo->indice = 1;
		pos->inicio=pos->fim=lis=novo;
	}else{
		if(indice==1){ /*Significa que quer inserir no começo*/
			 pos->inicio = lis = InserirListaInicio(lis,info);
		}else{
			while(p!=NULL && p->indice!=indice){ /*Procura pelo indice desejado*/
				aux = p;
				p=p->prox;
			}
			
			if(p==NULL){/*Se p=NULL, então encontra-se na ultima posicao.Insere no fim*/
				lis = InserirListaFinal(lis,pos,info);
			}else{ /*A inserção é feita no meio da lista*/
				novo->prox = p;
				p->ant = novo;
				aux->prox = novo;
				novo->ant = aux;
			}
		}
	}
	lis = ArrumarIndice(lis);
return lis;
}

/*Função para remover um elemento em um dado indice*/
ListaDupla* RemoverIndice(Posicao* pos,ListaDupla* lis,int indice){
	ListaDupla* p=lis;
	ListaDupla* aux;
	
		if(Vazia(lis)){ /*Não tem elemento, então não remove*/
			printf("\nNao foi possivel remover a posicao do indice indicado pois a lista esta vazia.\n");
		}else{
			while(p!=NULL && p->indice!=indice){
				aux = p;
				p=p->prox;
			}
			if(indice==1){ /*Remoção no inicio*/
				pos->inicio = lis = RetirarListaInicio(lis);
			}else{
				if(p->prox==NULL){ /*Remoção no fim*/
					pos = RetirarListaFinal(pos);
				}else{
					aux->prox = p->prox;
					p->prox->ant = aux;
					free(p);
				}
			}
		}
	
	lis = ArrumarIndice(lis);
return lis;
}

/*Função para ler de um arquivo*/
ListaDupla* LerArquivo(Posicao* pos,ListaDupla* lis,FILE *fp,char* arquivo){
	char caracter;
	int contador=0;
	char* palavra=NULL;

	fp = fopen(arquivo,"r");
	if(fp==NULL){
		printf("\nErro ao abrir o arquivo. O programa sera encerrado.\n");
		exit(1);
	}
	
	caracter = fgetc(fp);
	while (caracter!=EOF){
		if (caracter!='\n') {
			if (contador==0){
				palavra = (char*) malloc(2*sizeof(char));
			}
			if (contador>=1){
				palavra = realloc(palavra,(contador+2)*sizeof(char));
			}
			palavra[contador] = caracter;
			contador++;
		}else{
			if (contador>0){
				palavra[contador] = '\0';
				lis = InserirOrdenado(pos,lis,palavra);
				contador = 0;
			}
		}
		caracter = fgetc(fp);
	}
	lis = ArrumarIndice(lis);
	fclose(fp);
return lis;
}

/*Função para gravar um arquivo*/
void GravarArquivo(ListaDupla* lis,FILE *fp,char* arquivo){
	ListaDupla* p;
	
	fp = fopen(arquivo,"w+");
	if(fp==NULL){
		printf("\nErro ao abrir o arquivo. O programa sera encerrado.\n");
		exit(1);
	}
	
	if(!Vazia(lis)){
		for(p=lis;p!=NULL;p=p->prox){
			fprintf(fp,"%s",p->informacao);
			fprintf(fp,"\n");
		}
		printf("\nArquivo Gravado Com Sucesso.\n");
	}else{
		printf("\nNao foi possivel gravar o arquivo. A lista esta vazia.\n");
	}
	fclose(fp);
}