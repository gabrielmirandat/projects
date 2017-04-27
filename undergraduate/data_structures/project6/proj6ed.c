/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao:O programa calcula o menor caminho entre diversas cidades visitando-se umas as outras
        dado um grafo nao-orientado */




#include<stdio.h>
#include<stdlib.h>  /*biblioteca para alocacao dinamica*/
#include<string.h>
#include<math.h>


struct aresta{  /*estruturas de arestas*/
    int vinicial;
    int vfinal;
    int distancia;
    struct aresta* prox;
};
typedef struct aresta Aresta;


int vetor_vertices_visitados[14];
Aresta* lista_adjacencia[14]; /*lista de adjacencia*/
Aresta* current_arc;


int numero_vertice(char* nome); /*funcoes*/
void le_arquivo();
void cria_aresta_lista(char* primeira,char* segunda, char* terceira);
void printar_lista();
void caminhos(int ini);
int ciclo(int cic);
char* vertice_numero(int num);




int numero_vertice(char* nome){ /*atribui numeros as cidades p/ facilitar o programa*/
    int retorno;

    if((strcmp("Brasilia",nome)==0)||(strcmp("Brasília",nome)==0)){
        retorno=0;
    }else if((strcmp("Goiania",nome)==0)||(strcmp("Goiânia",nome)==0)){
        retorno=1;
    }else if(strcmp("Campo Grande",nome)==0){
        retorno=2;
    }else if(strcmp("Blumenau",nome)==0){
        retorno=3;
    }else if(strcmp("Curitiba",nome)==0){
        retorno=4;
    }else if(strcmp("Santos",nome)==0){
        retorno=5;
    }else if(strcmp("Belo Horizonte",nome)==0){
        retorno=6;
    }else if(strcmp("Rio de Janeiro",nome)==0){
        retorno=7;
    }else if((strcmp("Joao Pessoa",nome)==0)||(strcmp("João Pessoa",nome)==0)){
        retorno=8;
    }else if(strcmp("Campina Grande",nome)==0){
        retorno=9;
    }else if(strcmp("Boa Vista",nome)==0){
        retorno=10;
    }else if((strcmp("Belem",nome)==0)||(strcmp("Belém",nome)==0)){
        retorno=11;
    }else if((strcmp("Florianopolis",nome)==0)||(strcmp("Florianópolis",nome)==0)){
        retorno=12;
    }else if((strcmp("Petropolis",nome)==0)||(strcmp("Petrópolis",nome)==0)){
        retorno=13;
    }

    return retorno;
}

char* vertice_numero(int num){
    char* retorno;

    if(num==0){
        retorno="Brasilia";
    }else if(num==1){
        retorno="Goiania";
    }else if(num==2){
        retorno="Campo Grande";
    }else if(num==3){
        retorno="Blumenau";
    }else if(num==4){
        retorno="Curitiba";
    }else if(num==5){
        retorno="Santos";
    }else if(num==6){
        retorno="Belo Horizonte";
    }else if(num==7){
        retorno="Rio de Janeiro";
    }else if(num==8){
        retorno="Joao Pessoa";
    }else if(num==9){
        retorno="Campina Grande";
    }else if(num==10){
        retorno="Boa Vista";
    }else if(num==11){
        retorno="Belem";
    }else if(num==12){
        retorno="Florianopolis";
    }else if(num==13){
        retorno="Petropolis";
    }

    return retorno;
}


void le_arquivo(){ /*le do arquivo e monta lista*/
    FILE* fp;
    int i,atual,ind1,ind2,ind3;
    char frase[150];
    char primeira[25];
    char segunda[25];
    char terceira[10];

    fp=fopen("content/entradaProj6.txt","r");
    if(!fp){
      printf("\nentradaProj6.txt nao encontrado.\n");
      exit(-1);
    }
    
    while((fgets(frase,sizeof(frase),fp))!=NULL){
        atual =0;
        ind1=0;
        ind2=0;
        ind3=0;

        while(frase[atual]!='\0'){
            if(frase[atual]=='p' && frase[atual+1]=='a')
                break;
            primeira[ind1]=frase[atual];
            ind1++;
            atual++;
        }
        primeira[ind1-1]='\0';

        while(frase[atual]!=' '){
            atual++;
        }
        atual++;

        while(frase[atual]!=':'){
            segunda[ind2]=frase[atual];
            atual++;
            ind2++;
        }
        segunda[ind2]='\0';

        atual++;
        atual++;
        while(frase[atual]!=' '){
            terceira[ind3]=frase[atual];
            atual++;
            ind3++;
        }
        terceira[ind3]='\0';

        cria_aresta_lista(primeira,segunda,terceira);
    }
    fclose(fp);
}

void cria_aresta_lista(char* primeira,char* segunda, char* terceira){
    Aresta* art = (Aresta*) malloc(sizeof(Aresta));

    art->vinicial = numero_vertice(primeira);
    art->vfinal = numero_vertice(segunda);
    art->distancia = atoi(terceira);
    art->prox = NULL;

    if(lista_adjacencia[art->vinicial]==NULL){
        lista_adjacencia[art->vinicial]=art;
    }else if(lista_adjacencia[art->vinicial]!=NULL){
        art->prox=lista_adjacencia[art->vinicial];
        lista_adjacencia[art->vinicial]=art;
    }

    Aresta* art_inv = (Aresta*) malloc(sizeof(Aresta));

    art_inv->vinicial = art->vfinal;
    art_inv->vfinal = art->vinicial;
    art_inv->distancia = art->distancia;
    art_inv->prox = NULL;

    if(lista_adjacencia[art_inv->vinicial]==NULL){
        lista_adjacencia[art_inv->vinicial]=art_inv;
    }else if(lista_adjacencia[art_inv->vinicial]!=NULL){
        art_inv->prox=lista_adjacencia[art_inv->vinicial];
        lista_adjacencia[art_inv->vinicial]=art_inv;
    }

}

void printar_lista(){ /*imprime lista de adjacencia. Cada cidade foi numerada de 0 a 13*/
    int i;

    for(i=0;i<14;i++){
        Aresta* aux=lista_adjacencia[i];
        while(aux!=NULL){
            printf("%d-%d-%d ",aux->vinicial,aux->vfinal,aux->distancia);
            aux=aux->prox;
        }
        printf("\n");
    }
    printf("\n");
}

void caminhos(int ini){ /*funcao modificada que trabalha como o algoritmo de Prim.*/
    current_arc==NULL;
    int distancia_tot;
    distancia_tot=0;
    printf("Saindo de %s:\n",vertice_numero(ini));

    int i;
    for(i=0;i<14;i++){
        vetor_vertices_visitados[i]=-1;
    }

    vetor_vertices_visitados[0]=ini;

    i=0;
    int contador=0;
    while(vetor_vertices_visitados[13]==-1){
       contador++;
       int dist=10000;
       while(vetor_vertices_visitados[i]!=-1){
            Aresta* aux=lista_adjacencia[vetor_vertices_visitados[i]];
            while(aux!=NULL){
                if((ciclo(aux->vfinal))==0){
                    if(aux->distancia<dist){
                        dist=aux->distancia;
                        current_arc=aux;
                    }
                }
                aux=aux->prox;
            }
            i++;
        }
        distancia_tot = distancia_tot + current_arc->distancia;
        printf("%s->%s dist:%d \n",vertice_numero(current_arc->vinicial),vertice_numero(current_arc->vfinal),current_arc->distancia);

        vetor_vertices_visitados[contador]=current_arc->vfinal;
        i=0;
    }
    printf("Distancia total percorrida:%d\n\n",distancia_tot);
}

int ciclo(int cic){ /*verifica se aresta forma um ciclo*/
    int i;
    i=0;
    while(vetor_vertices_visitados[i]!=-1){
        if(cic==vetor_vertices_visitados[i]){
            return 1;
        }
        i++;
    }
    return 0;
}


int main(){
    int i;
    for(i=0;i<14;i++){
        lista_adjacencia[i]=NULL;
    }

    le_arquivo();

    /*printar_lista();*/

    caminhos(0);
    caminhos(1);
    caminhos(2);
    caminhos(3);
    caminhos(4);
    caminhos(5);
    caminhos(6);
    caminhos(7);
    caminhos(8);
    caminhos(9);
    caminhos(10);
    caminhos(11);
    caminhos(12);
    caminhos(13);

    return 0;
}
