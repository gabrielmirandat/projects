/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao: O programa em questao funciona como um simulador de aeroporto,ocorren-
    do a seguinte ordem de eventos:
        -gerado avioes que se aproximam do aeroporto;
        -gerado avioes que ja estao no aeroporto;
        -os que se aproximam sao ordenados em uma fila de prioridade por combustivel;
        -em intervalos de 5 minutos, a prioridade e para quem quer aterrissar;
        -os que aterrissaram vao para a garagem, e la precisam esperar pelo menos
            1 intervalo de tempo a mais, controlado pela variavel "espera";
        -em um intervalo de 5 minutos tambem, apos a espera na garagem, os avioes
            pedem permissao para decolar;.
     Foram criadas duas filas, uma para os avioes que querem permissao para aterrissar
      e outra para os que querem permissao para decolar.Nenhuma pista das 3 fica ociosa
      durante a execucao do programa, a nao ser quando o primeiro da fila de permissao
      para decolar ainda nao completou o tempo de espera na garagem ou nao haver espera.
      para decolar. Por outro lado, no caso de 3 ou mais avioes com combustivel zero
      na fila para aterrissar, o excesso e mandado para outro aeroporto e todas as
      pistas sao ocupadas pelos restantes, nao havendo mais espaço para decolar no
      intervalo em questao.*/

    	/*Arquivo de implementacao das funcoes da interface do programa*/


#include<stdio.h>
#include<stdlib.h>  /*biblioteca para alocacao dinamica*/
#include<string.h>
#include<time.h>    /*bibliteca que auxilia a gerar numeros aleatorios*/


int PISTA_1=-1; /*->controla o uso da pista 1, -1 para vazia e 1 para em uso.*/
int PISTA_2=-2; /*->controla o uso da pista 2, -2 para vazia e 2 para em uso.*/
int PISTA_3=-3; /*->controla o uso da pista 3, -3 para vazia e 3 para em uso.*/
int Nr_aproximacoes;
int Nr_decolagens;
int Nr_voos;
char matriz_nomes[42][7]={"VG3001","JJ4404","LN7001","TG1501","GL7602","AZ1009","VG3002","RL7880","AL0012","TT4544","TG1505",
"VG3003","JJ4403","JJ4401","LN7002","AZ1002","AZ1007","GL7604","AZ1003","JJ4403","TG1502","GL7601","TT4500","RL7801",
"GF4681","GF4690","AZ1020","JJ4435","AZ1065","LF0978","RL7867","GL7675","LF0972","VG3070","GL7672","AZ1079","VG3072",
"RL7870","AL0072","TT4574","TG1575","VG3073"}; /*nomes usados pelos voos*/
int CONT_NOME=0;    /*contador global para a matriz de nomes dos voos*/


typedef struct no No;                     

typedef struct fila Fila;   



struct no{          /*no da fila*/
    char nome[7];       /*nome do voo*/
    int combus;         /*combustivel de cada aviao*/
    int espera;         /*tempo de espera, usado para poder decolar*/
    struct no* prox;    /*ponteiro para proximo aviao*/
};


struct fila{    /*estrutura da fila*/
    No* ini;    /*ponteiro para inicio da fila*/
    No* fim;    /*ponteiro para fim da fila*/
};


Fila* cria();

int vazia(Fila* f);

No* ins_fim_decolagem(No* fim);

void insere_decolagem(Fila* f);

No* ret_ini_aproximacao(No* ini);

void retira_inicio_aproximacao(Fila* f);

void insere_prioridade_aproximacao(Fila* f);

No* criador_nos_prioridade();

void gerador_nomes(char* nome);

int gerador_numeros(int min,int max);

void garagem_func(Fila* aproximacao,Fila* decolagem);

void decolagem_func(Fila* decolagem);

int decol_aux(int pista, Fila* decolagem);

void printar_fila(No* inicio);

void ajuste_combustivel(Fila* aproximacao);

void ajuste_tempo_espera(Fila* decolagem);

void verifica_decolagens(Fila* decolagem);




Fila* cria(){  /*cria a fila - ini e fim recebem NULL*/
                    /*funcao basica de fila = livro Celes PucRio slides*/
    Fila* f=(Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

int vazia(Fila* f){ /*verifica se a fila esta vazia*/
                /*funcao basica de fila = livro Celes PucRio slides*/
    return (f->ini == NULL);
}

No* ins_fim_decolagem(No* fim){      /*funcao de insercao no fim (insere_decolagem)*/
    No* p = (No*) malloc(sizeof(No));
    p->combus=20;  /*funcao basica de fila atualizada para o programa = livro Celes PucRio slides*/
    p->espera=1;
    gerador_nomes(p->nome);
    printf("\n\nAVIAO %s EM ESPERA NA GARAGEM.\n\n",p->nome);
    p->prox=NULL;
    if(fim!=NULL){
        fim->prox=p;
    }
    return p;
}

void insere_decolagem(Fila* f){ /*funcao usada para gerar os nos avioes que ja */
                                /*começam na garagem. */
    int qtd_vezes =gerador_numeros(1,16); /*e gerado aleatoriamente o numero de */
                                            /*avioes que ja começam na garagem */
    Nr_decolagens = Nr_decolagens + qtd_vezes;

    printf("\n\nNUMERO DE DECOLAGENS:%d\n\n",Nr_decolagens);

    int i;                      /*funcao basica de fila atualizada para o programa = livro Celes PucRio slides*/
    for(i=1;i<=qtd_vezes;i++){
        f->fim = ins_fim_decolagem(f->fim);
        if(f->ini==NULL){
            f->ini=f->fim;
        }
        getchar();
    }
}

No* ret_ini_aproximacao(No* ini){   /*funcao de retirada do inicio( retira_inicio_aproximacao) */
    No* p = ini->prox;  /*funcao basica de fila atualizada para o programa = livro Celes PucRio slides*/
    free(ini);
    return p;
}

void retira_inicio_aproximacao(Fila* f){ /*funcao usada para retirar excesso de */
                                         /*avioes com combustivel zero*/
    if(vazia(f)){
        return;     /*funcao basica de fila atualizada para o programa = livro Celes PucRio slides*/
    }
    f->ini=ret_ini_aproximacao(f->ini);
    if(f->ini==NULL){
        f->fim=NULL;
    }
}

void insere_prioridade_aproximacao(Fila* f){ /* funcao de insercao com prioridade*/
                                             /*por combustivel na fila de permissao*/
    int i,qtd_vezes;                         /*para aterrissar*/

    qtd_vezes = gerador_numeros(1,26);  /*gerado numero de aproximacoes*/

    Nr_aproximacoes = qtd_vezes;

    printf("\n\nNUMERO DE APROXIMACOES:%d\n",Nr_aproximacoes);

    for(i=1;i<=qtd_vezes;i++){

        No* p = criador_nos_prioridade();

        printf("\n\nAVIAO APROXIMANDO..\n");
        printf("VOO:%s\n",p->nome);
        printf("COMBUSTIVEL:%d\n\n",p->combus);
        getchar();

        No* ant = NULL;

        No* inicio = f->ini;

        while(inicio!=NULL && inicio->combus < p->combus){
            ant=inicio;
            inicio = inicio->prox;
        }
        if(ant==NULL && inicio==NULL){
           f->ini = p;
           f->fim = p;
        }else if(inicio==NULL){
            ant->prox = p;
            f->fim = p;
        }else if(p->combus<=f->ini->combus){
            p->prox = f->ini;
            f->ini=p;
        }else{
            ant->prox=p;
            p->prox= inicio;
        }
    }
}


No* criador_nos_prioridade(){ /*funcao que cria os nos de aproximaçao*/
    No* novo = (No*)malloc(sizeof(No));

    gerador_nomes(novo->nome);
    novo->combus =gerador_numeros(0,12);
    novo->espera=0;
    novo->prox=NULL;

    return novo;
}

void gerador_nomes(char* nome){ /*funcao para atribuir nomes da matriz de nomes aos voos*/
    strcpy(nome,matriz_nomes[CONT_NOME]);
    CONT_NOME = ((CONT_NOME+1)%42);

}


int gerador_numeros(int min,int max){   /*funcao para gerar numeros aleatorios*/
    int numero;
    srand( (unsigned)time(NULL) );  /*funcao aproveitada da especificaçao do projeto 2*/
    numero=min+rand()%(max-min+1);
    return numero;
}

void garagem_func(Fila* aproximacao,Fila* decolagem){
    int i;                      /*funcao que realiza a transiçao para o aviao*/
    if(vazia(aproximacao)){     /*aterrissar e se deslocar ate a garagem*/
        return;
    }
    int qtd_combus_0=0;

    No* aux = aproximacao->ini;


    while(aux!=NULL && aux->combus==0){
        qtd_combus_0++;
        aux=aux->prox;
    }


    if(qtd_combus_0>=3){ /*caso de emergencia quando ha 3 ou mais avios que precisam pousar*/
        if(qtd_combus_0>3){
             for(i=1;i<=(qtd_combus_0-3);i++){
             printf("\n\nAEROPORTO CHEIO..ROTA DO AVIAO %s DESVIADA PARA O AEROPORTO MAIS PROXIMO..\n\n",aproximacao->ini->nome);
             retira_inicio_aproximacao(aproximacao);
             }
        }
        No* p = aproximacao->ini;
        p->combus=20;
        p->prox->combus=20;
        p->prox->prox->combus=20;
        printf("\n\nAVIAO %s REALIZOU UMA OTIMA ATERRISSAGEM NA PISTA 1.DIRIJA-SE PARA A GARAGEM.\n\n",p->nome);
        printf("AVIAO %s REALIZOU UMA OTIMA ATERRISSAGEM NA PISTA 2.DIRIJA-SE PARA A GARAGEM.\n\n",p->prox->nome);
        printf("AVIAO %s REALIZOU UMA OTIMA ATERRISSAGEM NA PISTA 3.DIRIJA-SE PARA A GARAGEM.\n\n",p->prox->prox->nome);
        aproximacao->ini = p->prox->prox->prox;
        decolagem->fim->prox=p;
        p->prox->prox->prox = NULL;
        decolagem->fim = p->prox->prox;
        if(aproximacao->ini==NULL){
            aproximacao->fim=NULL;
        }
        PISTA_1=1;
        PISTA_2=2;
        PISTA_3=3;
    }else{
        for(i=1;i<=2;i++){
            if(aproximacao->ini!=NULL){
                No* p=aproximacao->ini;
                p->combus=20;
                aproximacao->ini = p->prox;
                p->prox=NULL;
                decolagem->fim->prox=p;
                decolagem->fim=p;
                if(i==1){
                    PISTA_1=1;
                    printf("\n\nAVIAO %s REALIZOU UMA OTIMA ATERRISSAGEM NA PISTA 1.DIRIJA-SE PARA A GARAGEM.\n\n",p->nome);
                }else{
                    PISTA_2=2;
                    printf("AVIAO %s REALIZOU UMA OTIMA ATERRISSAGEM NA PISTA 2.DIRIJA-SE PARA A GARAGEM.\n\n",p->nome);
                }
            }
        }
    }
}

void decolagem_func(Fila* decolagem){
    int pista;              /*funcao de transiçao entre os avioes que estao em espera*/
    if(vazia(decolagem)){   /*na garagem e vao decolar*/
        return;
    }
    pista = PISTA_3;
    PISTA_3 = decol_aux(pista,decolagem);
    if(vazia(decolagem)){
        return;
    }
    pista = PISTA_2;
    PISTA_2 = decol_aux(pista,decolagem);
    if(vazia(decolagem)){
        return;
    }
    pista = PISTA_1;
    PISTA_1 = decol_aux(pista,decolagem);

}

int decol_aux(int pista, Fila* decolagem){      /*funcao de controle de decolagem*/
    if(pista==-1 || pista==-2 || pista==-3){    /*verifica se os avioes estão aptos*/
        No* p;                                  /*para decolar*/
        p=decolagem->ini;
        if(decolagem->ini->espera>=2){
            decolagem->ini = p->prox;
            if(pista==-1){
                printf("\n\nAVIAO %s DECOLOU NA PISTA 1..BOM VOO!\n\n",p->nome);
                return 1;
            }else if(pista==-2){
                printf("\n\nAVIAO %s DECOLOU NA PISTA 2..BOM VOO!\n\n",p->nome);
                return 2;
            }else{
                printf("\n\nAVIAO %s DECOLOU NA PISTA 3..BOM VOO!\n\n",p->nome);
                return 3;
            }
            free(p);
        }else{
            printf("\n\nAVIAO %s EM TEMPO DE ESPERA NA GARAGEM.APROVEITE OS MELHORES APERITIVOS DO AEROPORTO!\n\n",p->nome);
        }
    }
    return pista;
}

void printar_fila(No* inicio){ /*percorre os elementos da fila e os mostra*/
    No* aux = inicio;           /*na tela*/
    if(aux==NULL){
        printf("\n->NAO EXISTE ESPERA\n");
    }

    while(aux!=NULL){
        printf("\n\nVOO:%s",aux->nome);
        printf("\nCOMBUSTIVEL:%d",aux->combus);
        printf("\nESPERA:%d\n\n",aux->espera);
        aux=aux->prox;
        getchar();
    }
}

void ajuste_combustivel(Fila* aproximacao){
    if(vazia(aproximacao)){     /*a cada intervalo de 5 minutos,o combustivel*/
        return;                 /*dos avioes que estão no ar e atualizado*/
    }
    No* p=aproximacao->ini;
    while(p!=NULL){
        p->combus--;
        p=p->prox;
    }
}

void ajuste_tempo_espera(Fila* decolagem){
    if(vazia(decolagem)){  /*a cada intervalo de 5 minutos, o tempo de espera*/
        return;             /*dos avioes que se encontram na garagem é atualizado.*/
    }
    No* p=decolagem->ini;
    while(p!=NULL){
        p->espera++;
        p=p->prox;
    }
}

void verifica_decolagens(Fila* decolagem){  /*funcao que verifica a quantidade*/
    No* p = decolagem->ini;                 /*de avioes que restaram na garagem*/
    while(p!=NULL){                     /*apos a iteraçao de uma hora.*/
        Nr_decolagens++;                /*A quantidade e somada com o numero*/
        p=p->prox;                      /*de decolagens caso o usuario queira*/
    }                               /*executar o programa por mais uma hora*/
}


int main(){
     char continua;     /*escolha do usuario se quer adicionar mais uma hora*/
     int HORA;          /*A hora e composta de 12 intervalos de 5 minutos*/
     Fila* aproximacao; /*ponteiro para fila que representa permissao para aterrisar*/
     Fila* decolagem;   /*ponteiro para fila que representa permissao para decolar*/

     aproximacao= cria();  /*cria fila de aproximaçoes*/
     decolagem = cria();    /*cria fila de avioes de garagem*/

     HORA=0;
     continua = 's';
     printf("--------------------BEM-VINDO AO AEROPORTO DE BRASILIA--------------------");
     while(continua=='s' || continua=='S'){ /*a partir da segunda iteraçao o usuario*/
                                            /*define se quer continuar.*/
        insere_prioridade_aproximacao(aproximacao);

        printf("\n\nORDEM DE PERMISSAO PARA POUSO..\n\n");
        printar_fila(aproximacao->ini);

        insere_decolagem(decolagem);

        Nr_voos = Nr_aproximacoes + Nr_decolagens;

        printf("\n\nNUMERO DE VOOS:%d\n",Nr_voos);
        printf("NUMERO DE APROXIMACOES:%d\n",Nr_aproximacoes);
        printf("NUMERO DE DECOLAGENS:%d\n\n",Nr_decolagens);
        getchar();

        int minutos = 0;

        while(minutos<12){ /*iteracao de 12 intervalos de 5 minutos*/
           printf("\n\nHORA:%d",HORA);
           printf("\nINTERVALO DE %d ate %d MINUTOS.",minutos*5,(minutos+1)*5);
           getchar();

           garagem_func(aproximacao,decolagem);

           decolagem_func(decolagem);

           printf("\n\nATUALIZADA FILA DE ESPERA PARA POUSO:\n");
           printar_fila(aproximacao->ini);
           printf("\nATUALIZADA FILA DE ESPERA PARA DECOLAR:\n\n");
           printar_fila(decolagem->ini);

           ajuste_combustivel(aproximacao);

           ajuste_tempo_espera(decolagem);


           minutos++;
           PISTA_1=-1;;
           PISTA_2=-2;
           PISTA_3=-3;

        }
        printf("\n\nDESEJA ADICIONAR MAIS UMA HORA?\n\n");
        scanf("%c",&continua);
        while(continua!='s'&&continua!='S'&&continua!='n'&&continua!='N'){
           printf("\nRESPONDA COM UMA RESPOSTA VALIDA!\n");
           scanf("%c",&continua);
        }
        getchar();
        HORA++;
	HORA = HORA%24;
        Nr_decolagens=0;
        if(decolagem->ini!=NULL){
            verifica_decolagens(decolagem);
        }
     }
     return 0;
}

