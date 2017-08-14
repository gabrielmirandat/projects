// Kurose cap 4
// Medhi cap 2

#include <stdio.h>
#define MAX 20

struct node
{
    int dist[MAX];
    int via[MAX];
}rt[MAX];

int main()
{
    int dmat[MAX][MAX];
    int n,i,j,k,m,count, convergencia=0;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix :\n");
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&dmat[i][j]);
            dmat[i][i]=0;
            rt[i].dist[j]=dmat[i][j];
            rt[i].via[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    for(k=0;k<n;k++)
                    {
                        if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
                        {
                            rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                            rt[i].via[j]=k;
                            count++;
                        }
                    }
                }
            }
            convergencia++;

            printf("\n\n convergencia %d \nValidacao\n",convergencia);

            printf("\n\nState value for router 1 is \n");
            for(m=0;m<n;m++)
            {
                printf("\t\nnode %d via %d Distance%d",m+1,rt[0].via[m]+1,rt[0].dist[m]);
            }

        }while(count!=0);

        printf("\n\n A convergencia foi de %d passos \n",convergencia);

        for(i=0;i<n;i++)
        {
            printf("\n\nState value for router %d is \n",i+1);
            for(j=0;j<n;j++)
            {
                printf("\t\nnode %d via %d Distance%d",j+1,rt[i].via[j]+1,rt[i].dist[j]);
            }
        }
    printf("\n\n");
}
