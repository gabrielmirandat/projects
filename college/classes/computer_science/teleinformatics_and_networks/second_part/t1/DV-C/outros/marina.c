#include <stdio.h>
#include <math.h>
#define MAX 20


float media(int vetor[], int tamanho);
float desvio(int vetor[], int tamanho, float med);

struct node
{
    int dist[MAX];
    int via[MAX];
}rt[MAX];

int main()
{
    int dmat[MAX][MAX];
    int convergencias[MAX];
    int n,i,j,k,m,count, convergencia, flag, flag4 = 0;
    float media_convergencias, desvio_convergencias = 0.0;

    printf("\nEntre a quantidade de nodos : ");
    scanf("%d",&n);
    printf("\nEntre a matriz de custos:\n");

    for(i=0;i<n;i++)
    {
        convergencias[i]=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].via[j]=j;
        }
    }

    flag4 =  1;
    do
    {
        count=0;
        if(flag4 == 1)
        {
            printf("\n\n Validacao para no 4- Passo %d \n",convergencia);
            printf("\n\nTabela atualizada para roteador 4  \n");

            for(m=0;m<n;m++)
            {
            printf("\t\nnodo %d via %d distancia %d",m+1,rt[3].via[m]+1,rt[3].dist[m]);
            }
            flag4 = 0;
        }

        convergencia++;

        for(i=0;i<n;i++)
        {
            flag = 0;
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                    {
                        if(i==3)
                        {
                            printf("\n\nRecebi a tabela do nodo %d \n Percebi que passando por ele meu caminho para o nodo %d eh menor que o anterior. Atualizei \n",k+1, j+1, k+1);
                            flag4 = 1;
                        }

                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].via[j]=k;
                        count++;
                        flag = 1;

                    }
                }

            }

            if(flag!=0)
                convergencias[i]=convergencias[i]+1;

        }
    }while(count!=0);

    for(i=0;i<n;i++)
    {
        printf("\n\nTabela atualizada para roteador %d \n",i+1);
        printf("\n Convergencia para este no foi de %d iteracao(oes) \n",convergencias[i]);
        for(j=0;j<n;j++)
        {
            printf("\t\nnodo %d via %d distancia %d",j+1,rt[i].via[j]+1,rt[i].dist[j]);
        }
    }
    printf("\n\n");
    printf("\nA maior convergencia foi de %d passos \n",convergencia-1);
    media_convergencias = media(convergencias, n);
    desvio_convergencias = desvio(convergencias, n, media_convergencias);
    printf("\nA media das convergencias foi de %.2f passos com desvio padrao de %.2f passos \n",media_convergencias, desvio_convergencias);

    return 0;
}

float media(int vetor[], int tamanho)
{
    int i;
    float media=0.0;

    for(i=0 ; i<tamanho ; i++)
        media += vetor[i];

    return (media/tamanho);
}

float desvio(int vetor[], int tamanho, float med)
{
    int i;
    float soma_2=0.0;

    for(i=0 ; i<tamanho ; i++)
        soma_2 = soma_2 + (vetor[i] - med)*(vetor[i] - med);

    return sqrt(soma_2/tamanho);
}
