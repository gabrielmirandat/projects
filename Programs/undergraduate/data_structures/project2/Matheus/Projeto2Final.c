/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula: <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador: gcc version 4.8.1 (Ubuntu/Linaro 4.8.1-10ubuntu9)
    Descricao: O programa tem por objetivo simular um aeroporto simples com
    tres pistas, onde o numero de voos que se aproximam, os que desejam decolar
    e tambem seu nivel de gasolina sao gerados aleatoriamente no inicio do
    programa. O algoritmo deve então ordenar esses eventos de acordo com o nivel
    de prioridade de cada caso.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

char nome_voo[7]; //variavel global contendo o nome do voo retirado da fila

struct voo //funcao retirada dos slides de simulacao de eventos discretos
{
    char nome[7];
    char tipo;      //aproximacoes e decolagens
    int combA;      //combustível
    struct voo* prox;
};
typedef struct voo Voo;

struct FilaVoos
{
    Voo* inicio;
    Voo* fim;
};
typedef struct FilaVoos FilaVoos;

FilaVoos* cria (void)
{
    FilaVoos* f = (FilaVoos*) malloc(sizeof(FilaVoos));
    f->inicio = f->fim = NULL;
    return f;
};

Voo* ins_fim (Voo* fim, char nome[], char tipo, int comb) //funcao auxiliar de incersao retirada do livro Celes e Rangel da PUC-Rio
{
    Voo* p = (Voo*) malloc(sizeof(Voo));
    strcpy(p->nome, nome);
    p->tipo = tipo;
    p->combA = comb;
    p->prox = NULL;
    if (fim != NULL)
        fim->prox = p;
    return p;
}

void insere (FilaVoos* f, char nome[], char tipo, int comb) //funcao de incersao retirada do livro Celes e Rangel da PUC-Rio
{
    f->fim = ins_fim(f->fim, nome, tipo, comb);
    if (f->inicio==NULL)
        f->inicio = f->fim;
}

int geraRand(int min, int max) //funca de gerar numeros aleatorios aproveitada da especificacao do trabalho
{
    int r;
    r=min+rand()%(max-min+1);
    return r;
}

int vazia (FilaVoos* f) //funcao que verifica se fila esta vazia
{
    return (f->inicio==NULL);
}

void imprime(FilaVoos* f) //funcao de imprimir filas retirada do livro Celes e Rangel da PUC-Rio
{
    Voo* q;
    for (q=f->inicio; q!=NULL; q=q->prox)
        printf("%s\t\t%d\n", q->nome, q->combA);
}

Voo* ret_ini (Voo* ini) //funcao auxiliar de remocao retirada do livro Celes e Rangel da PUC-Rio
{
    Voo* p = ini->prox;
    free(ini);
    return p;
}

void retira (FilaVoos* f) //funcao de remocao retirada do livro Celes e Rangel da PUC-Rio
{
    if (vazia(f))
    {
        printf("Fila vazia.\n");
        return;
    }
    strcpy(nome_voo,f->inicio->nome); //salva nome do voo retirado
    f->inicio = ret_ini(f->inicio);
    if (f->inicio == NULL)
        f->fim = NULL;
}

int comb_prox (FilaVoos* f) //funcao de verificar combustivel do proximo elementos da fila
{
    int comb;
    comb = f->inicio->combA;
    return comb;
}

void diminui_comb(FilaVoos* f) //funcao que diminui combustivel dos voos
{
    Voo* q;
    for (q=f->inicio; q!=NULL; q=q->prox)
        q->combA--;
}

int main()
{

    srand(time(NULL)); //srand retirada da funcao geraRand para nao gerar mesmos combustiveis

    char nome[42][7] = {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "AZ1009", "VG3002", "RL7880", "AL0012",
                        "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002", "AZ1002", "AZ1007", "GL7604",
                        "AZ1003", "JJ4403", "TG1502", "GL7601", "TT4500", "RL7801", "GF4681", "GF4690", "AZ1020",
                        "JJ4435", "AZ1065", "LF0978", "RL7867", "GL7675", "LF0972", "VG3070", "GL7672", "AZ1079",
                        "VG3072", "RL7870", "AL0072", "TT4574", "TG1575", "VG3073"
                       }; //nomes sugeridos para os voos

    int nro_aprox = 0;
    int nro_decol = 0;
    int nro_voos = 0;
    int decol_rest = 0;

    int i, j, *vetcomb, aux, tempo[2]= {0,0}, stat_p1=0, stat_p2=0, stat_p3=0, acabou=0, ciclo;
    char tipo, continuar='s';

    FilaVoos *p1, *p2, *p3, *espera;

    p1 = cria();
    p2 = cria();
    p3 = cria();
    espera = cria();

    while (continuar =='S' || continuar == 's')
    {
        acabou=0;
        ciclo=12;
        nro_aprox = geraRand(0, 26); //gera numeros aleatorios para os voos
        nro_decol = decol_rest + geraRand(0, nro_aprox/1.625); //nro_aprox/1.625 usado para manter a proporcao de 26/16 (n de aproximacoes e decolagens maximos permitido)
        j = geraRand(0, nro_aprox/1.625);
        nro_voos = nro_aprox+nro_decol;

        vetcomb =(int *) malloc(sizeof(int) * nro_aprox); //aloca vetor para amarzenar combustiveis dinamicamente

        for(i=0; i<nro_aprox; i++)
        {
            vetcomb[i] = geraRand(0,12); //gera quantidade de combstivel e armazena no vetor
            if (i>0)
            {
                j = i;
                while(vetcomb[j]<vetcomb[j-1] && j>0)  //ordena vetor de combustiveis
                {
                    aux=vetcomb[j];
                    vetcomb[j] = vetcomb[j-1];
                    vetcomb[j-1] = aux;
                    j--;
                }
            }
        }

        tipo = 'A';
        for(i=0; i<nro_aprox; i++)  //coloca voos que estao se aproximando nas filas das pistas 1 e 2
        {
            insere (p1, nome[i], tipo, vetcomb[i]);
            i++;
            if (i<nro_aprox)
                insere (p2, nome[i], tipo, vetcomb[i]);
        }

        j = i;
        tipo = 'D';
        for(i=i-1; i<nro_decol-decol_rest+j-1; i++)  //coloca voos que estao decolando na fila da pista 3
        {
            insere (p3, nome[i], tipo, 12);
        }

        printf("\n\n======================================\n");
        printf("Aeroporto da Universidade de Brasilia\n");
        printf("Hora Atual: %.2d:%.2d\n", tempo[1], tempo[0]);
        printf("Numero de Voos Programados: %d\n", nro_voos);
        printf("Numero de Aproximacoes: %d\n", nro_aprox);
        printf("Numero de Decolagens: %d\n", nro_decol);

        if(vazia(p1)!=1) //mostra nome e combustivel de voos que se aproximam
        {
            printf("\nFila de Avioes que se Aproximam:\n\nNome\t\tCombustivel\n");
            imprime(p1);
            imprime(p2);
        }

        if(vazia(p3)!=1) // e dos que aguardam a decolagem
        {
            printf("\nFila de Avioes que Aguardam Decolagem:\n\nNome\t\tCombustivel\n");
            imprime(p3);
        }

        tempo[0] = tempo[0]+5; //passa o primeiro ciclo (5min)

        while (acabou==0) //roda o programa enquanto houver tempo ou avioes
        {

            printf("\nNumero de aproximacoes restantes: %d\n", nro_aprox);
            printf("Numero de decolagens restantes: %d\n\n", nro_decol);
            printf("\nPressione qualquer tecla para continuar...\n");
            getchar();
            printf("\n\n======================================\n");

            if (vazia(espera)==0)
            {
                do //adiciona avioes que estao em solo para a fila de decolagem
                {
                    retira(espera);
                    insere(p3, nome_voo, 'D', 12);
                    printf("%.2d:%.2d\t%s Aguarda para decolar\n",tempo[1], tempo[0], nome_voo);
                }
                while (vazia(espera)==0);
            }

            if (nro_aprox > 0) //se houver aproximacoes
            {
                if(stat_p1 == 0) //se pista 1 estiver disponivel
                {
                    stat_p1 = 1; //ocupa a pista
                    retira(p1); //retira aviao da fila de aproximacao
                    printf("\n%.2d:%.2d\t%s Pousou na pista 1\n", tempo[1], tempo[0], nome_voo);
                    insere(espera, nome_voo, 'D', 12); //adiciona voo na fila dos avioes que aguardam em solo
                    printf("%.2d:%.2d\t%s Esta aguardando em solo\n\n", tempo[1], tempo[0], nome_voo);
                    nro_aprox--;
                    nro_decol++;
                }
            }

            if (nro_aprox > 0) //repete as acoes anteriores para a pista 2
            {
                if(stat_p2 == 0)
                {
                    stat_p2 = 1;

                    retira(p2);
                    printf("\n%.2d:%.2d\t%s Pousou na pista 2\n", tempo[1], tempo[0], nome_voo);

                    insere(espera, nome_voo, 'D', 12);
                    printf("%.2d:%.2d\t%s Esta aguardando em solo\n\n", tempo[1], tempo[0], nome_voo);

                    nro_aprox--;
                    nro_decol++;
                }
            }

            if (nro_aprox > 0)
            {
                if (comb_prox(p1)==0) //se o combustivel do proximo voo for 0, pousa na pista 3
                {
                    printf("*****EMERGENCIA!!! PISTA 3 REQUISITADA PARA ATERRISSAGEM*****\n");
                    if (stat_p3 == 0) //verifica disponibilidade da pista
                    {
                        stat_p3 = 1;
                        retira(p1);

                        insere(espera, nome_voo, 'D', 12);
                        printf("\n%.2d:%.2d\t%s Pousou na pista 3\n", tempo[1], tempo[0], nome_voo);
                        printf("%.2d:%.2d\t%s Esta aguardando em solo\n\n", tempo[1], tempo[0], nome_voo);

                        nro_aprox--;
                        nro_decol++;

                    }
                    else //desvia aeronave se pista estiver ocupada
                    {
                        retira(p1);
                        printf("*****ALERTA GERAL DE DESVIO DA AERONAVE %s *****\n", nome_voo);
                        nro_aprox--;
                    }
                }
            }

            while (nro_aprox > 1 && comb_prox(p2)==0) //verifica se ainda ha avioes com 0 de combustivel
            {
                retira(p2);
                printf("*****ALERTA GERAL DE DESVIO DA AERONAVE %s *****\n", nome_voo);
                nro_aprox--;
            }

            while (nro_aprox > 0 && comb_prox(p1)==0)
            {
                retira(p1);
                printf("*****ALERTA GERAL DE DESVIO DA AERONAVE %s *****\n", nome_voo);
                nro_aprox--;
            }

            if (stat_p3 == 0) //se nao houver emergencias, a pista 3 eh utilizada para decolagens
            {
                if (nro_decol>0)
                {
                    stat_p3 = 1;
                    retira(p3);
                    printf("\n%.2d:%.2d\t%s Decolou da pista 3\n", tempo[1], tempo[0], nome_voo);
                    nro_decol--;
                }
            }

            if (stat_p1 == 0) //se pista 1 estiver disponivel, ela eh utilizada para decolagens tambem
            {
                if (nro_decol>0)
                {
                    stat_p1 = 1;
                    retira(p3);
                    printf("\n%.2d:%.2d\t%s Decolou da pista 1\n", tempo[1], tempo[0], nome_voo);
                    nro_decol--;
                }
            }

            if (stat_p2 == 0) //assim como a pista 2
            {
                if (nro_decol>0)
                {
                    stat_p1 = 1;
                    retira(p3);
                    printf("\n%.2d:%.2d\t%s Decolou da pista 2\n", tempo[1], tempo[0], nome_voo);
                    nro_decol--;
                }
            }

            stat_p1 = 0; //libera pistas para uso
            stat_p2 = 0;
            stat_p3 = 0;

            if ((vazia(p1))==0)
                diminui_comb(p1); //diminui combustiveis dos voos que estao no ar
            if ((vazia(p2))==0)
                diminui_comb(p2);

            tempo[0] = tempo[0]+5; //adianta 1 ciclo (5min)
            ciclo--;


            if(tempo[0]==60)
            {
                tempo[0]=0;
                tempo[1]++;
            }

            if(ciclo==0)
            {
                printf("\n*****  FIM DO CICLO DE 1 HORA *****\n");
                decol_rest=nro_decol;
                printf("\n%d Decolagens restantes.\n", decol_rest);
                do
                {
                    printf("Deseja continuar por mais 1h? (S/N)");
                    scanf("%c", &continuar);
                    getchar();
                }
                while(continuar != 's' && continuar!='s' && continuar!='N' && continuar!='n');
                free(vetcomb);
                break;
            }


            if(nro_decol==0) //se nao houver mais decolagens restantes, o programa eh encerrado
            {
                acabou=1; //flag para sinalizar final
                printf("\n***** FIM DOS VOOS *****\n");
                decol_rest=0;
                printf("\n%d Decolagens restantes.\n", decol_rest);
                do
                {
                    printf("Deseja continuar por mais 1h? (S/N)");
                    scanf("%c", &continuar);
                    getchar();
                }
                while(continuar != 's' && continuar!='s' && continuar!='N' && continuar!='n');
                free(vetcomb);
                break;
            }
        }
    }
    return 0;
}
