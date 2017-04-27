/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao:O programa em questao cria um grafo orientado que representa a amizade entre pessoas
    e calcula com um indice a popularidade entre eles.
    
    Obs: O programa deve ler de um arquivo de texto com os nomes das pessoas.*/
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define pessoas 22
#define d 0.85

struct no
{
    char nome[50];
    int num; //id
    int amizades; //nro de amigos
    float ranking;
    struct no *prox;
    struct no *next;
}; typedef struct no No;

struct grafo
{
    int V;
    int A;
    No *inicio;
}; typedef struct grafo Grafo;

No* cria(void) //Cria no vazio
{
    return NULL;
}

No* inserir(Grafo *p, No *l, char *nome, int num) // Insere nomes no grafo
{

    No *novo= (No *) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->num = num;
    novo->amizades = 0;
    novo->ranking = 1;

    if(l == NULL) //se o grafo vazio
    {
        novo->next = l;
        p->inicio = novo;
        p->V++;
        return novo;
    }
    else
    {
        novo->next = NULL;
        l->next = novo;
        return novo;
    }
}

No* cria_aresta(Grafo *p, No *N, int i) //cria amizades
{
    No *novo =(No *) malloc(sizeof(No));
    p->A++;
    N->prox = novo;
    novo->ranking = 0;
    novo->amizades = 0;
    novo->next = NULL;
    novo->prox = NULL;
    novo->num = i;
    return novo;
}

void calc_rank(No *N, float *peso) //calcula ranking
{
    No *n;
    float r;

    while(N != NULL)
    {
        if(N->amizades != 0)
        {
            r = (N->ranking)/(float)(N->amizades); //divide o ranking pela nro de amigos
            n = N->prox;
            while(n != NULL){
				*(peso+n->num-1) = *(peso+n->num-1) + r; //soma o valor recebido com o atual
				n = n->prox;
			}
        }
        N = N->next;
    }
}

void imprimir(No *N, FILE *fp) //imprime amigos na tela e imprime ranking na tela e no arquivo
{
    No* n = N;

    while(N != NULL)
    {

        printf("\n%.3f  %s", N->ranking, N->nome);
        fprintf(fp, "%.2f %s", N->ranking, N->nome);

        n = N->prox;

        if(n!=NULL){
			printf("\n\tID dos amigos: ");
			fprintf(fp, "\tID dos amigos: ");
		}

        while(n != NULL)
        {
			printf("%d ", n->num);
            fprintf(fp, "%d ", n->num);
            n = n->prox;
        }

        fprintf(fp, "\n");
        N = N->next;

    }
    printf("\n\n");
}

No* ordenar(No* noh) //ordena por ranking
{
    No* p = noh;
    No* ant = NULL;
    No* aux = NULL;

    while(p != NULL) {
        if(ant != NULL) {
            if(ant->ranking < p->ranking) {
                if(aux == NULL) {
                    ant->next = p->next;
                    p->next = ant;
                    ant = NULL;
                    noh = p;
                }
                else {
                    ant->next = p->next;
                    p->next = ant;
                    aux->next = p;
                    p = noh;
                    ant = NULL;
                    aux = NULL;
                }
            }
            else {
                aux = ant;
                ant = p;
                p = p->next;
            }
        }
        else {
            ant = p;
            p = p->next;
        }
    }
    return noh;
}

int main(void)
{
    No *N, *aux;
    FILE *fp;
    int i, j, amigo;
    char nome[50];
    float peso[pessoas];

    Grafo *p = (Grafo *) malloc(sizeof(Grafo));
    p->V = 0;
    p->A = 0;
    N = cria();

    fp = fopen("../content/nomes.txt", "r");

    if (fp == NULL)
    {
        printf("O arquivo nao existe\n");
        printf("\nPressione qualquer tecla para sair...");
        getchar();
        return 0;
    }
    
    i=1;
    for(i = 1; i <= pessoas; i++) //lendo arquivo de texto
    {
        fscanf(fp, "%[^\n]", nome);
        N = inserir(p, N, nome, i);
        printf("%d  %s\n", i, nome);
        getc(fp);
    }
    printf("\n");

    aux = p->inicio;
	
	amigo = -1;
    for(i = 0; i < pessoas; i++)
    {
        N = aux;
        printf("Digite os IDs dos amigos de %s, ou 0 para sair:", aux->nome);

        while(amigo != 0)
        {
            scanf("%d", &amigo);

            if(amigo != 0)
            {
                N = cria_aresta(p, N, amigo);
                aux->amizades++;
            }
        }

        aux = aux->next;
        amigo = -1;
    }

    for(i = 0; i < pessoas; i++) //calcular rank
    {
        for(j = 0; j < pessoas; j++)
            peso[j] = 0;

        N = p->inicio;
        calc_rank(N, peso);

        for(j = 0; j < pessoas; j++)
        {
            N->ranking = N->ranking + peso[j]*d + (1-d);
            N = N->next;
        }
    }

    fp = fopen("../content/amigosED20141.txt", "w");

    p->inicio = ordenar(p->inicio);

    printf("\n\nRanking em ordem decrescente e adjacentes:\n");
    imprimir(p->inicio, fp);
	getchar();
    printf("\nPressione qualquer tecla para sair");
    getchar();

    fclose(fp);
    return 0;
}
