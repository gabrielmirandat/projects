#include "vetor_distancia.h"

int main(int argc, char* argv[])
{
    // ponteiro para arquivo de entrada
    FILE* arq_entrada;

    if(argc < 2)
    {
        printf("\nModo de usar: ./vetor_distancia topologia.txt.\n");
        exit(1);
    }

    // leitura do arquivo
    arq_entrada = fopen(argv[1], "r");
    if(arq_entrada == NULL) 
    {
    	printf("\nErro ao abrir arquivo.\n");
    	exit(1);
    }

    // obtem dados dos nodos do arquivo de entrada
    entrada(arq_entrada);
    completa_matriz();

    // realiza algoritmo vetor distancia para 
    // calculo das melhores rotas
    vetor_distancia();

    // mostra informacoes de convergencia finais 
    // para cada nodo
    mostra_convergencia_final();
    return 0;
}


// le o arquivo de entrada
// e obtem nodos, vizinhos e custos
// nodos e vizinhos podem ter um ou dois algarismos
// custos podem ter ate tres algarismos
int entrada(FILE* arq)
{
   	char line[1000];
    int contador, no_atual, vizinho, vizinho_2, custo, custo_2, custo_3;
   	NNOS = 0;
   	
    // le linha do arquivo ate o fim
    while (fscanf(arq,"%s",line) > 0) 
    {
		// printf("%s\n", line);
        contador=0;
		
        // obtem nodo
        int no_atual = line[0]  - '0';
        if(line[contador+1] == ';')
            contador=2;
        else
        {
            no_atual = no_atual*10 + line[contador+1] - '0';
            contador=3;
        }
        
        // le caracteres da linha ate o fim
        while(line[contador]!='\0')
		{
			// obtem vizinhos de ate dois digitos
            vizinho = line[contador] - '0';
            // se apenas um digito
            if(line[contador+1]=='[')
                contador+=2;
            // se dois digitos
            else
            {
                vizinho = vizinho*10 + line[contador+1] - '0';
                contador+=3;
            }

            // obtem custos de ate tres digitos
            custo = line[contador] - '0';
            // se apenas um digito
            if(line[contador+1] == ']')
                contador+=3;
            // se dois digitos
            else if(line[contador+2] == ']')
            {
                custo = custo*10 + line[contador+1] - '0';
                contador+=4;
            // se tres digitos
            }else
            {
                custo = custo*100 + line[contador+1]*10 + line[contador+2] - '0';
                contador+=5;
            }

			// preenche linha da matriz de custos para o nodo atual
            atribui_vizinhos_matriz(no_atual, vizinho, custo);
			// printf("%d %d %d\n", no_atual, vizinho, custo);
		}
		// obtem numero de nodos
        NNOS++;
	}

	printf("\n");
    fclose(arq);
    return 1;
}

// constroi matriz com os vizinhos
// obtidos da entrada
int atribui_vizinhos_matriz(int no_atual, int vizinho, int custo)
{
	matriz_custos[no_atual-1][vizinho-1] = custo;
}

// completa nao-vizinhos com infinito, 999,
// e inicializa a tabela dos nodos e
// distancia pro proprio nodo como zero
void completa_matriz()
{
	for(int i=0;i < NNOS; i++)
	{
		// inicializa convergencias para cada nodo
        convergencias[i]=0;
        for(int j=0;j < NNOS; j++)
		{
			// distancia para proprio nodo custa zero
            if(i==j) matriz_custos[i][j]=0;
            // distancia para nao-vizinhos eh infinito
			if(i!=j && matriz_custos[i][j]==0) matriz_custos[i][j]=999;

			// construcao inicial das tabelas
            // custo para se chegar ao nodo
			roteador[i].dist[j]=matriz_custos[i][j];
            // qual vizinho tomar para chegar ao nodo
            roteador[i].via[j]=j;

			printf("%*d", 4, matriz_custos[i][j]);	
		}
		printf("\n");
	}
}

// realiza o algoritmo de vetor distancia e
// atribui convergencias
void vetor_distancia()
{
    // inicializa variaveis
    int qlq_nodo_alterou=0, flag4, tabela_i_alterou;
    maior_convergencia = 0;
    
    // tabela_i_alterou para mostrar atualizacao do nodo quatro,
    // nodo escolhido para validacao
    printf("\nVALIDACAO - NODO 4\n");
    flag4 =  1;
    do
    {
        // tabela_i_alterou para sabermos ate quando devemos continuar as iteracoes
        // quando nao eh setada significa que nenhum roteador qlq_nodo_alterou
        // a sua tabela, entao saimos do loop
        qlq_nodo_alterou=0;
        // para mostrar a validacao do nodo quatro
        if(flag4 == 1)
        {
            printf("\npasso:%d\n",maior_convergencia);
            // printf("\n\nTabela atualizada para roteador 4  \n");

            // mostra a tabela vetor distancia para o nodo quatro
            for(int m=0;m<NNOS;m++)
            {
                // printf("\t\n nodo %d via %d distancia %d" ,m+1, roteador[3].via[m]+1,roteador[3].dist[m]);
                printf("%d via %d distancia %d\n" ,m+1, roteador[3].via[m]+1,roteador[3].dist[m]);
            }
            
            // seta novamente para zero
            flag4 = 0;
        }

        // maior convergencia entre todos os nodos
        maior_convergencia++;

        // para cada roteador e todos os seus vizinhos,
        // testa se ha uma distancia menor entre eles 
        // passando por um outro nodo (do i)
        for(int i=0;i<NNOS;i++)
        {
            // para testar se no i mudou neste passo
            tabela_i_alterou = 0;
            // testa para todos os nodos (para o j)
            for(int j=0;j<NNOS;j++)
            {
                // se ha um caminho passando por k
                // menor que o anterior (via k)
                for(int k=0;k<NNOS;k++)
                {
                    // testa para saber se caminho de i para j via k eh melhor que
                    // o que tinha antes
                    if(roteador[i].dist[j]>matriz_custos[i][k]+roteador[k].dist[j])
                    {
                        // mostra mudanca na tabela do nodo quatro (validacao)
                        if(i==3)
                        {
                            // printf("\n\nRecebi a tabela do nodo %d \n Percebi que passando por ele meu caminho para o nodo %d eh menor que o anterior. Atualizei \n",k+1, j+1);
                            printf("\trecebi tabela de %d - atualizei caminho para %d\n",k+1, j+1);
                            flag4 = 1;
                        }

                        // atualiza tabela vetor distancia
                        roteador[i].dist[j]=roteador[i].dist[k]+roteador[k].dist[j];
                        roteador[i].via[j]=k;
                        qlq_nodo_alterou = 1;
                        tabela_i_alterou = 1;

                    }
                }

            }

            // incrementa numero de convergencia para 
            // nodo i
            if(tabela_i_alterou!=0)
                convergencias[i]=convergencias[i]+1;

        }
    }while(qlq_nodo_alterou!=0);   
}


// calcula media da maior_convergencia entre nodos
float media(int vetor[])
{
    int i;
    float media=0.0;

    for(i=0 ; i<NNOS ; i++)
        media += vetor[i];

    return (media/NNOS);
}

// calcula desvio padrao da maior_convergencia entre nodos
float desvio(int vetor[], float med)
{
    int i;
    float soma_2=0.0;

    // somatorio de cada elemento do vetor menos a media ao quadrado
    for(i=0 ; i<NNOS ; i++)
        soma_2 = soma_2 + (vetor[i] - med)*(vetor[i] - med);

    return sqrt(soma_2/NNOS);
}

// mostra a convergencia final das tabelas
void mostra_convergencia_final()
{
    media_convergencias, desvio_convergencias = 0.0;

    // mostra tabela para cada roteador
    printf("\nTABELAS FINAIS\n");
    for(int i=0;i<NNOS;i++)
    {
        printf("\nnodo %d - %d iteracoes\n",i+1, convergencias[i]);
        
        for(int j=0;j<NNOS;j++)
        {
            printf("%d via %d distancia %d\n",j+1,roteador[i].via[j]+1,roteador[i].dist[j]);
        }
    }

    // mostrando media e desvio padrao
    printf("\n\nMAIOR CONVERGENCIA - %d PASSOS\n",maior_convergencia-1);
    media_convergencias = media(convergencias);
    desvio_convergencias = desvio(convergencias, media_convergencias);
    printf("MEDIA - %.2f \nDESVIO PADRAO - %.2f\n",media_convergencias, desvio_convergencias);
}