/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao: O programa utiliza uma tabela hash para acesso rapido de palavras de um texto */




#include<stdio.h>
#include<stdlib.h>  /*biblioteca para alocacao dinamica*/
#include<string.h>
#include<math.h>


struct lista{
    char info[20];
    int vet_arq[11];
    struct lista* prox;		/*ponteiro para proximo no*/
};

typedef struct lista LISTA;


LISTA* inicializa(void);
int vazia(LISTA* p);
void libera(LISTA* l);
LISTA* insere(LISTA* p,char* conteudo,int arq);
LISTA* cria_lista(LISTA* p);    /*funcoes = interface*/
void mostra_tela(LISTA* p);
void cria_texto_indice(LISTA* p);
int hash(char* atual,int tipo);
void espalhamento(LISTA* p);
void interagir_usuario();
void printar_hash_vet();
void libera_vetor();

int tam_global=100;
LISTA** VETOR_HASH; /*vetor de registros de acesso rapido*/
FILE* hdoc;
int colisoes=0;
int TOTAL_PALAVRAS=0;


LISTA* inicializa(void){	/*inicializa um ponteiro de LISTA com NULL*/
    return NULL;		/*funcao basica de lista = slide TAD lista encadeada e livro Celes PucRio*/
}

int vazia(LISTA* p){		/*verifica se a lista tem algum no*/
    if(p==NULL)			/*funcao basica de lista = slide TAD lista encadeada e livro Celes PucRio*/
        return 1;		/*se for NULL retorna true, caso contrario, retorna false*/
    else
        return 0;
}

void libera(LISTA* l){		/*funcao de liberacao dos nos da lista alocados dinamicamente*/
	LISTA* p=l;		/*funcao basica de lista = slide TAD lista encadeada e livro Celes PucRio*/
    while(p!=NULL){
        LISTA* t = p->prox;
        free(p);
        p=t;
    }
}

LISTA* insere(LISTA* p,char* conteudo,int arq){
    int i;
    if(vazia(p)){
        LISTA* nova = (LISTA*) malloc(sizeof(LISTA));	/*verifica se eh o primeiro no*/
        for(i=0;i<=10;i++){
            nova->vet_arq[i]=0;
        }
        strcpy(nova->info,conteudo);
        nova->vet_arq[arq]=1;
        nova->prox = NULL;
        return nova;
    }

    LISTA* auxiliar = p;

    int achou=0;

    while(achou==0 && auxiliar!=NULL){
            if(strcmp(auxiliar->info,conteudo)==0){	/*loop para verificar se a info ja existe na lista*/
                achou=1;
                break;
            }
            auxiliar=auxiliar->prox;
    }

    if(achou==1){
           auxiliar->vet_arq[arq]=1;
    }else{
        LISTA* nova = (LISTA*) malloc(sizeof(LISTA));
        for(i=0;i<=10;i++){
            nova->vet_arq[i]=0;
        }
        strcpy(nova->info,conteudo);
        nova->vet_arq[arq]=1;
        nova->prox=p;
        p=nova;
    }
    return p;
}

LISTA* cria_lista(LISTA* p){
    FILE* fp;
    int arq,aux_tam_global=0;
    char palavra_atual[20];

    fp=fopen("doc1.txt","r");
    arq=1;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc2.txt","r");
    arq=2;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc3.txt","r");
    arq=3;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc4.txt","r");
    arq=4;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc5.txt","r");
    arq=5;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc6.txt","r");
    arq=6;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc7.txt","r");
    arq=7;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc8.txt","r");
    arq=8;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc9.txt","r");
    arq=9;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    fp=fopen("doc10.txt","r");
    arq=10;
    while(fscanf(fp,"%s",&palavra_atual)>0){
        p=insere(p,palavra_atual,arq);
        aux_tam_global++;
    }
    if(aux_tam_global<tam_global)
        tam_global=aux_tam_global;

    fclose(fp);
    aux_tam_global=0;

    return p;

}

void mostra_tela(LISTA* p){	/*funcao que mostra todos os elementos da lista,*/
    if(vazia(p)){
        printf("\t--LISTA VAZIA--\n\n");
        return;
    }
    int i;
    i=0;
    LISTA* aux;
    for(aux=p;aux!=NULL;aux=aux->prox){
            i++;
            printf("%d.\t  Conteudo:%s\n",i,aux->info);
    }
}

void cria_texto_indice(LISTA* p){
    FILE* fp;
    int i;

    fp=fopen("IndInvert.txt","w");

    while(p!=NULL){
        fprintf(fp,"%s -> ",p->info);
        for(i=1;i<=10;i++){
            if(p->vet_arq[i]==1)
                fprintf(fp,"doc%d ",i);
        }
        fprintf(fp,"\n");
        p=p->prox;
    }
    fclose(fp);
}

int hash(char* atual, int tipo){
    char palavra[20];
    int i,indice;
    int chave=0;

    int ind = strlen(atual);

    for(i=1;i<=ind;i++){
        if(i%2==1){
            chave=chave + (atual[i]%71);
        }else{
            chave=chave + (atual[i]%79);
        }
    }
    indice = chave%tam_global;

    if(tipo==1){
    fprintf(hdoc,"%s chave %d indice %d\n",atual,chave,indice);
    printf("%s chave %d indice %d\n",atual,chave,indice);
    }

    return indice;
}

void espalhamento(LISTA* p){
    hdoc= fopen("HashDocs.txt","w");
    int indice,i,maior;
    int n_colisoes[tam_global];
    LISTA* aux = p;
    LISTA* atual;

    maior=0;
    for(i=0;i<tam_global;i++){
        n_colisoes[i]=0;
    }
    while(aux!=NULL){
        TOTAL_PALAVRAS++;
        indice=hash(aux->info,1);
        atual=aux->prox;
        n_colisoes[indice]++;

        if(VETOR_HASH[indice]==NULL){
           VETOR_HASH[indice]=aux;
           aux->prox=NULL;
        }else{
            colisoes++;
            aux->prox=VETOR_HASH[indice];
            VETOR_HASH[indice]=aux;
        }
        aux=atual;
    }
    for(i=0;i<tam_global;i++){
        if(n_colisoes[i]>maior){
            maior=n_colisoes[i];
        }
    }
    fprintf(hdoc,"n de palavras:%d\n",TOTAL_PALAVRAS);
    printf("n de palavras:%d\n",TOTAL_PALAVRAS);
    fprintf(hdoc,"n max do indice:%d\n",tam_global);
    printf("n max do indice:%d\n",tam_global);
    fprintf(hdoc,"n max de colisoes:%d\n",colisoes);
    printf("n max de colisoes:%d\n",colisoes);
    fprintf(hdoc,"n de elementos da maior lista:%d\n",maior);
    printf("n de elementos da maior lista:%d\n",maior);
    fclose(hdoc);
    /*for(i=0;i<tam_global;i++){
        printf("%d\n",n_colisoes[i]);
    }*/
}

void interagir_usuario(){
    char resposta;
    int indice,i;
    char palavra[20];
    resposta='s';

    while(resposta=='s'|| resposta=='S'){
        printf("Entre com um nome para busca:\n");
        scanf("%s",&palavra);
        getchar();
        indice=hash(palavra,0);
        LISTA* aux =VETOR_HASH[indice];

        while( aux!=NULL &&(strcmp(palavra,aux->info)!=0)){
            aux=aux->prox;
        }
        if(aux!=NULL){
           printf("\npalavra encontrada nos arquivos:\n");
           for(i=0;i<=10;i++){
                if(aux->vet_arq[i]==1)
                    printf("doc%d\n",i);
           }
        }else if(aux==NULL){
            printf("\npalavra nao encontrada.\n");
        }
        resposta='c';
        while(resposta!='s' && resposta!='S' && resposta!='n' && resposta!='N'){
            printf("Deseja procurar outra palavra?(S/N)\n");
            scanf("%c",&resposta);
            getchar();
        }
    }
}

void printar_hash_vet(){
    int i,qtd_lista=0;

    for(i=0;i<tam_global;i++){
        LISTA* aux = VETOR_HASH[i];
        while(aux!=NULL){
            /*printf("%s ",aux->info);*/
            aux=aux->prox;
            qtd_lista++;
        }
        printf("%d",qtd_lista);
        printf("\n");
        qtd_lista=0;
    }
}

void libera_vetor(){    /*libera o vetor de registros*/
    int i;
    for(i=0;i<tam_global;i++){
        free(VETOR_HASH[i]);
    }
}

int main(){
    int i;
    LISTA* p = inicializa();

    p=cria_lista(p);

    cria_texto_indice(p);

    mostra_tela(p);

    VETOR_HASH = (LISTA**) malloc(sizeof(LISTA*)*(tam_global));

    for(i=0;i<tam_global;i++){
        VETOR_HASH[i] = inicializa();
    }

    espalhamento(p);

    interagir_usuario();

    /*printar_hash_vet();*/

    libera(p);

    libera_vetor();

    return 0;
}


