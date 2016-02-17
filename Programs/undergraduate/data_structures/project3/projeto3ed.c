/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao:O projeto em questao trabalha como um solucionador com preenchimento
        em backtracking de um matriz previamente preenchida*/


#include<stdio.h>   /*bibliotecas*/
#include<stdlib.h>


/*para limpar a tela do terminal*/
#ifdef _WIN32
    #define CLEAR "cls" /* soh funciona no windows */
#else
    #define CLEAR "clear" /* soh funciona no linux ou mac (unix) */
#endif


int tam_mat_ori;    /*tamanho da matriz lido do arquivo*/
int n,CONTADOR =0;    /*n=tamanho verdadeiro da matriz, pois os cantos sao*/
int** mat_aux;        /*preenchidos com -1*/
    /*matriz auxiliar, com posicoes previamente preenchidas com -1*/


  /*funcoes usadas no programa*/

void andador(int i,int j,int mat[][n],int N_atual);

void printador_matriz(int mat[][n]);

void construcao_matriz(int mat[][n],FILE* fp);

int encontrar_valor(int* linha, int* coluna,int mat[][n]);

int solucao_encontrada(int mat[][n]);

int numero_ja_existe(int N_atual,int mat[][n]);

void constroi_texto(int mat[][n]);


void construcao_matriz(int mat[][n],FILE* fp){
    int i,j;

    mat_aux = (int**) malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        mat_aux[i] = (int*) malloc(sizeof(int)*(n));
    }

    j=0;
    for(i=0;i<n;i++){           /*constroi laterais com -1 e o que ja vem preenchido*/
        mat[i][j]=-1;
        mat_aux[i][j]=-1;
    }
    j=n-1;
    for(i=0;i<n;i++){
        mat[i][j]=-1;
        mat_aux[i][j]=-1;
    }
    i=0;
    for(j=1;j<n-1;j++){
        mat[i][j]=-1;
        mat_aux[i][j]=-1;
    }
    i=n-1;
    for(j=1;j<n-1;j++){
        mat[i][j]=-1;
        mat_aux[i][j]=-1;
    }

    for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){
            fscanf(fp,"%d",&mat[i][j]); /*constroi matriz auxiliar*/
            if(mat[i][j]==0){
                mat_aux[i][j]=0;
            }else{
                mat_aux[i][j]=-1;
            }
        }
    }
}

void printador_matriz(int mat[][n]){
    int i,j;
    for(i=1;i<n-1;i++){         /*printa a matriz na tela*/
        for(j=1;j<n-1;j++){
            printf("%d\t",mat[i][j]);;
        }
        printf("\n");
    }
    printf("\n");
}


int encontrar_valor(int* linha, int* coluna,int mat[][n]){
    int i,j;
    for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){     /*encontra a linha e a coluna da posicao semente*/
            if(mat[i][j]==1){
                int N_atual=mat[i][j];
                *linha=i;
                *coluna=j;
                return N_atual;
            }
        }
    }
    printf("\nO numero semente usado pelo programa eh 1. Insira uma matriz que possua 1.\n");
    exit(1);
}

void andador(int i,int j,int mat[][n],int N_atual){

    if(CONTADOR==0){            /*funcao que busca a solucao*/
        mat[i][j]=0;
    }

    if(N_atual!=1 && mat[i][j]!=N_atual){
        if(numero_ja_existe(N_atual,mat))
            return;
    }

    if(mat[i][j]==0 || mat[i][j]==N_atual){

        mat[i][j]=N_atual;


        CONTADOR++;
        N_atual++;
        system (CLEAR);
        printador_matriz(mat);


        andador(i+1,j,mat,N_atual);

        andador(i-1,j,mat,N_atual);

        andador(i,j-1,mat,N_atual);

        andador(i,j+1,mat,N_atual);

        andador(i-1,j+1,mat,N_atual);

        andador(i-1,j-1,mat,N_atual);

        andador(i+1,j-1,mat,N_atual);

        andador(i+1,j+1,mat,N_atual);



        if((solucao_encontrada(mat)==0) && mat_aux[i][j]!=-1){
            mat[i][j]=0;    /*verifica se e possivel o backtracking na pos. atual*/
        }
        system (CLEAR);
        printador_matriz(mat);


        }
}

int solucao_encontrada(int mat[][n]){
    int i,j;
    for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){
            if(mat[i][j]==0){   /*verifica se achou a solucao*/
                return 0;
            }
        }
    }
    for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){
            if(mat[i][j]==tam_mat_ori*tam_mat_ori){
                return 1;
            }
        }
    }
    return 0;
}


int numero_ja_existe(int N_atual, int mat[][n]){
    int i,j;
    for(i=1;i<n-1;i++){     /*verifica se o N_atual ja existe em outra posicao da*/
        for(j=1;j<n-1;j++){     /*matriz*/
            if(mat[i][j]==N_atual){
                return 1;
            }
        }
    }
    return 0;
}


void constroi_texto(int mat[][n]){  /*constroi o arquivo texto se houver solucao*/
    int i,j;
    FILE* fp;

    fp= fopen("content/solucaoProj3.txt","w");

    fprintf(fp,"%d\n",tam_mat_ori);

    for(i=1;i<n-1;i++){
        for(j=1;j<n-1;j++){
            fprintf(fp,"%d ",mat[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
 }

int main(){
    FILE* fp;
    int linha=0;
    int coluna=0;
    int i,j;

    fp=fopen("content/entradaProj3.txt","r");

    fscanf(fp,"%d",&tam_mat_ori);

    if(tam_mat_ori<6 || tam_mat_ori>10){
        printf("\nO tamanho da matriz deve estar entre 6 ou 10.\n");
        exit(1);
    }

    n = tam_mat_ori+2;

    int mat[n][n];

    construcao_matriz(mat,fp);

    fclose(fp);

    int N_atual = encontrar_valor(&linha,&coluna,mat);

    andador(linha,coluna,mat,N_atual);

    if(solucao_encontrada(mat)){
        constroi_texto(mat);
        printf("\n\nSolucao encontrada.\n");
    }else{
        printf("\n\nSolucao nao encontrada.\n");
    }

    return 0;
}
