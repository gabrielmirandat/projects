#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto1mp.h"

extern int mudanca_lista;
extern int tamanho_atual;

int vazia (Lista* l){
    if (l == NULL)
        return 1;
    else
        return 0;
}

Lista* cria (char* pal){
    Lista* p = (Lista*) malloc(sizeof(Lista));
    strcpy(p->palavra,pal);
    p->ocorrencias=0;
    p->ant=NULL;
    p->prox=NULL;
    return p;
}

Lista* insere_ordenado (Lista* l, char* pal){
    Lista* novo = cria(pal); /* cria novo nó */
    Lista* ante = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura posição de inserção */
    while (p != NULL && strcmp(p->palavra,pal)<0) {
        ante = p;
        p = p->prox;
    }
    /* insere elemento */
    if(ante==NULL && p==NULL){/*insere na vazia*/
      l=novo;
      l->ocorrencias= 1;
      tamanho_atual=tamanho_atual+1;
    }else if (ante==NULL) { /* insere elemento no início */
        novo->prox = p;
        p->ant=novo;
        l = novo;
        l->ocorrencias=1;
        tamanho_atual++;
    }else if(p==NULL){ /*insere fim*/
        ante->prox=novo;
        novo->ant=ante;
        novo->ocorrencias =1;
        tamanho_atual++;
    }else if(strcmp(p->palavra,pal)==0) { /* se for a mesma palavra*/
        free(novo);
        p->ocorrencias=p->ocorrencias+1;
    }else { /* insere elemento no meio da lista */
        novo->prox = ante->prox;
        ante->prox = novo;
        novo->ant=ante;
        p->ant=novo;
        novo->ocorrencias =1;
        tamanho_atual++;
    }
    return l;
}


void libera (Lista* l){
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; /* guarda referência para o próximo elemento*/
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}

Lista* construcao_lista(Lista* l, FILE* fp){
    int i;
    char pal_atual[15];
    char ch;
    while( (ch=fgetc(fp))!= EOF ){
        if(((int)ch>=65 && (int)ch<=90) || ((int)ch>=97 && (int)ch<=122)){
            i=0;
            while (ch!= EOF &&(((int)ch>=65 && (int)ch<=90) || ((int)ch>=97 && (int)ch<=122))){
                pal_atual[i]=ch;
                i++;
                ch=fgetc(fp);
            }
            pal_atual[i]='\0';
            l=insere_ordenado(l,pal_atual);
        }
    }
    fclose(fp);
    return l;
}


void imprime(Lista* l){
    Lista* p=l;
    while(!vazia(p)){
        printf("info: %s\n",p->palavra);
        printf("ocorre: %d\n",p->ocorrencias);
        p=p->prox;
    }
    printf("\ntam_atual:%d",tamanho_atual);
}

Lista* inserir_elemento(Lista* l,char* elemento){
  l=insere_ordenado(l,elemento);
  mudanca_lista=1;

  return l;
}

Lista* retirar_elemento(Lista* l, char* pal){

  if(vazia(l)){
      printf("Impossível remover. Lista vazia.");
      return l;
  }

   Lista* p=l;
   Lista* ante=NULL;

   while (p != NULL && strcmp(p->palavra,pal)!=0) {
        ante = p;
        p = p->prox;
   }

   if(tamanho_atual==1){/*se só há um elemento na lista*/
        free(p);
        l=NULL;
        tamanho_atual--;
        mudanca_lista=1;
   }else if (ante == NULL) { /* retira elemento do início */
        l=p->prox;
        l->ant=NULL;
        free(p);
        tamanho_atual--;
        mudanca_lista=1;
   }else if(p==NULL){ /* elemento a ser retirado não esta na lista */
        printf("O elemento que deseja remover nao existe na lista.\n");
   }else if(p->prox==NULL){/*o elemento a ser removido é o último*/
        ante->prox=NULL;
        free(p);
        tamanho_atual--;
        mudanca_lista=1;
   }else if(strcmp(p->palavra,pal)==0) { /* se estiver no meio*/
        ante->prox=p->prox;
        p->prox->ant=ante;
        free(p);
        tamanho_atual--;
        mudanca_lista=1;
   }
   return l;
}

int buscar_elemento(Lista* l,char* valor){
    int n_ocorre,i;
    n_ocorre=0;
    int inicio=0;
    int fim= tamanho_atual-1;
    int meio=0;

    if(mudanca_lista){
        Lista* p = l;
        if(vet!=NULL){
            free(vet);
        }
        vet = (Lista**) malloc(sizeof(Lista*)*(tamanho_atual));

        for(i=0;i<tamanho_atual;i++){
            vet[i] = NULL;
        }

        i=0;
        while(p!=NULL){
            vet[i]=p;
            i++;
            p=p->prox;
        }
    }
    
    int achou=0;
    while((inicio<= fim) &&(!achou)) {
        meio=((fim+inicio)/2);
        if (strcmp(valor,vet[meio]->palavra)<0){
            fim=meio-1;
        }else if(strcmp(valor,vet[meio]->palavra)>0) {
            inicio=meio+1;
        }else{
            achou=1;
        }
    }
    mudanca_lista=0;

    if (achou) {
        //printf("%s foi encontrado na posicao %d.\n",valor, meio+1);
        n_ocorre = vet[meio]->ocorrencias;
        //printf("%s ocorre %d vezes.\n",valor,n_ocorre);
    }else {
        //printf("%s nao foi encontrado.\n", valor);
        n_ocorre=0;
    }
    return n_ocorre;
}

void tela(Lista* l){
  system("clear");
  int resp;
  char pal[15];

  resp=1;
  while(resp!=0){
    printf("1. Inserir um elemento.\n");
    printf("2. Retirar um elemento.\n");
    printf("3. Buscar um elemento.\n");
    printf("4. Imprimir lista.\n");
    printf("0. Sair\n\n");

    printf("Selecione uma opcao:\n");
    scanf("%d",&resp);
    getchar();

    switch(resp){
      case 1:
	system("clear");
	printf("Insira um elemento na lista:\n");
	scanf("%s",pal);
	getchar();
	l=inserir_elemento(l,pal);
	break;
      case 2:
	system("clear");
	printf("Insira o elemento que deseja remover:\n");
	scanf("%s",pal);
	getchar();
	l=retirar_elemento(l,pal);
	break;
      case 3:
	system("clear");
	printf("Informe a palavra que deseja buscar:\n");
	scanf("%s",pal);
	getchar();
	buscar_elemento(l,pal);
	break;
      case 4:
	system("clear");
	imprime(l);
	break;
      default:
	resp=0;
    }
    printf("\npressione enter:");
    getchar();
    system("clear");
  }
}