/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao:O programa em questao cria um grafo orientado que representa a amizade entre pessoas
    e calcula com um indice a popularidade entre eles */




#include<stdio.h>
#include<stdlib.h>  /*biblioteca para alocacao dinamica*/
#include<string.h>
#include<math.h>

struct vertice{
    char nome[15];  /*vertice do digrafo*/
    float rank;
    struct vertice* prox;
};

typedef struct vertice Vertice;

Vertice* lista_adjacencia[22];
Vertice* lista_adjacencia_invertida[22]; /*variaveis globais*/
FILE* fp;
int CONTADOR;

void criador_nos();
void constroi_amizade();
void calcular_ranking();
void libera_lista_adjacencia_invertida();
void libera_lista_adjacencia(); /*funcoes*/
void printar_amizade();
void liberar_invertida();
void printar_amizade_invertida();
Vertice* cria_ordenado(Vertice* l, float v );
void libera(Vertice* l);




void criador_nos(){
    int i;
    char nome[15];
    for(i=0;i<22;i++){
        Vertice* no = (Vertice*)malloc(sizeof(Vertice));
        no->rank = 1.00;
        no->prox = NULL;

        Vertice* no2 = (Vertice*)malloc(sizeof(Vertice));
        no2->rank = 1.00;
        no2->prox = NULL;

        printf("Informe o nome do %d° vertice.\n",i+1);
        scanf("%s",&nome);
        getchar();

        strcpy(no->nome,nome);
        strcpy(no2->nome,nome);

        lista_adjacencia[i] = no;
        lista_adjacencia_invertida[i] = no2;
    }
}

void constroi_amizade(){
    char add,nome[15];
    int i,j;
    Vertice* aux;

    for(i=0;i<22;i++){
        printf("Deseja adicionar algum amigo para %s ?\n",lista_adjacencia[i]->nome);
        scanf("%c",&add);
        getchar();

        while(add=='s' || add=='S'){
            printf("Informe o amigo:\n");
            scanf("%s",&nome);
            getchar();

            j=0;
            while(j<22 && (strcmp(lista_adjacencia[j]->nome,nome)!=0)){
                j++;
            }
            if(j==22){
                printf("O nome informado nao existe.\n");
                exit(-1);
            }

            Vertice* no = (Vertice*)malloc(sizeof(Vertice));
            no->rank = 1.00;
            no->prox = NULL;
            strcpy(no->nome,nome);

            aux=lista_adjacencia[i]->prox;
            lista_adjacencia[i]->prox=no;
            no->prox=aux;

            Vertice* no2 = (Vertice*)malloc(sizeof(Vertice));
            no2->rank = 1.00;
            no2->prox = NULL;
            strcpy(no2->nome,lista_adjacencia[i]->nome);

            aux= lista_adjacencia_invertida[j]->prox;
            lista_adjacencia_invertida[j]->prox = no2;
            no2->prox=aux;

            /*printar_amizade();

            printar_amizade_invertida();*/



            printf("Adicionar mais amigos para %s ?\n",lista_adjacencia[i]->nome);
            scanf("%c",&add);
            getchar();
        }
    }
}


void calcular_ranking(){
    int i,j,cont_amigos,iteracoes;
    float soma,soma_aux;
    char nome[15];
    Vertice* aux;
    Vertice* aux2;
    Vertice* aux3;

    iteracoes=0;

    for(iteracoes=0;iteracoes<22;iteracoes++){
        for(i=0;i<22;i++){
            soma=0;
            aux=lista_adjacencia_invertida[i]->prox;
            while(aux!=NULL){
                strcpy(nome,aux->nome);

                j=0;
                while(j<22 && (strcmp(lista_adjacencia[j]->nome,nome)!=0)){
                    j++;
                }

                cont_amigos=0;
                aux2=lista_adjacencia[j]->prox;
                while(aux2!=NULL){
                    aux2=aux2->prox;
                    cont_amigos++;
                }

                j=0;
                while(j<22 && (strcmp(lista_adjacencia[j]->nome,nome)!=0)){
                    j++;
                }

                soma_aux=0.00;

                soma_aux= ((lista_adjacencia_invertida[j]->rank)/(cont_amigos));

                soma=soma+soma_aux;

                aux=aux->prox;
            }

            lista_adjacencia_invertida[i]->rank = (0.15 + 0.85*soma);
        }
    }
}

void printar_amizade(){
    int i;
    Vertice* aux;

    fp=fopen("amigosED20141.txt","w");

    printf("-Lista de adjacencia- \n");
    fprintf(fp,"-Lista de adjacencia- \n");

    for(i=0;i<22;i++){
        printf("%s : ",lista_adjacencia[i]->nome);
        fprintf(fp,"%s : ",lista_adjacencia[i]->nome);
        aux=lista_adjacencia[i]->prox;

        while(aux!=NULL){
            printf("%s ",aux->nome);
            fprintf(fp,"%s ",aux->nome);
            aux=aux->prox;
        }

        printf("\n");
        fprintf(fp,"\n");
    }
    printf("\n");
    fprintf(fp,"\n");
}

void printar_amizade_invertida(){
    int i;
    Vertice* aux;

    printf("-Lista de adjacencia invertida- \n");
    fprintf(fp,"-Lista de adjacencia invertida- \n");

    for(i=0;i<22;i++){
        printf("%s : ",lista_adjacencia_invertida[i]->nome);
        fprintf(fp,"%s : ",lista_adjacencia_invertida[i]->nome);
        aux=lista_adjacencia_invertida[i]->prox;

        while(aux!=NULL){
            printf("%s ",aux->nome);
            fprintf(fp,"%s ",aux->nome);
            aux=aux->prox;
        }

        printf("\n");
        fprintf(fp,"\n");
    }
}


void libera_lista_adjacencia_invertida(){
    int i;
    Vertice* aux;

    for(i=0;i<22;i++){
        Vertice* post= lista_adjacencia_invertida[i]->prox;
        while(post!=NULL){
            aux = post;
            post=post->prox;
            free(aux);
        }
        if(i==21){
            lista_adjacencia_invertida[i]->prox=NULL;
        }else{
            lista_adjacencia_invertida[i]->prox=lista_adjacencia_invertida[i+1];
        }
    }
}

void libera_lista_adjacencia(){
    int i;
    Vertice* aux;

    for(i=0;i<22;i++){
        Vertice* post= lista_adjacencia[i];
        while(post!=NULL){
            aux = post;
            post=post->prox;
            free(aux);
        }
    }
}

void liberar_invertida(){
    int i;
    for(i=0;i<22;i++){
        free(lista_adjacencia_invertida[i]);
    }
}

Vertice* cria_ordenado(Vertice* l, float v ){
    Vertice* novo = (Vertice*) malloc (sizeof(Vertice));
    strcpy(novo->nome,lista_adjacencia_invertida[CONTADOR]->nome);
    novo->rank = v;

    Vertice* ant = NULL;
    Vertice* p = l;
    while(p!=NULL && p->rank>v){
        ant=p;
        p=p->prox;
    }

    if(ant==NULL){
        novo->prox = l;
        l=novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

void libera(Vertice* l){
    Vertice* p =l;
    while(p!=NULL){
        Vertice* t = p->prox;
        free(p);
        p=t;
    }
}

int main(){

    criador_nos();

    constroi_amizade();

    calcular_ranking();

    printar_amizade();

    printar_amizade_invertida();


    libera_lista_adjacencia_invertida();

    Vertice* l;
    l = NULL;

    for(CONTADOR=0;CONTADOR<22;CONTADOR++){
       l = cria_ordenado(l,lista_adjacencia_invertida[CONTADOR]->rank);
    }

    printf("\n-Ranking final-\n");
    fprintf(fp,"\n-Ranking final-\n");

    while(l!=NULL){
        printf("%s : %.5f\n",l->nome,l->rank);
        fprintf(fp,"%s : %.5f\n",l->nome,l->rank);
        l=l->prox;
    }
    fclose(fp);

    libera(l);

    libera_lista_adjacencia();

    liberar_invertida();

    return 0;

}

