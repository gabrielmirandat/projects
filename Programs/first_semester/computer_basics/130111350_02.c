/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Computacao Basica - 02/2013
    Aluno(a): <Gabriel Martins de Miranda>
    Matricula: <130111350>
    Turma: E
    Versão do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao: O programa em questao faz uma simulacao do famoso jogo da forca, em que sao lidas de um arquivo tipo texto as
palavras decifradas e seus respectivos pontos.A cada erro, a variavel "perdeu" diminui em uma unidade, sendo que o jogador
usuario possui 6 chances para decifrar cada palavra. */

#include<stdio.h>
#include <stdlib.h>

void mostra_tela(int *pontos_total,int *pontos,int *forca,char *palavra_decifrada,char *alfabeto,int *cont_forca,int *achou){
    int i;

    printf("\n--------------------------------------------------------------------------------\n");
    printf("*** JOGO DA FORCA *** \n");
    printf("PONTUACAO ACUMULADA:%d. \n",*pontos_total);
    printf("PONTUACAO A RECEBER PARA ESTA PALAVRA:%d.\n",*pontos);
    printf("1-cabeca 2-tronco 3-braco direito 4-braco esquerdo 5-perna direita 6-perna esquerda \n");
    /*caso o jogador erre alguma vez,o vetor "forca eh atualizado e sao mostradas na tela os numeros 
    correspondentes as partes do corpo perdidas*/
    if(*cont_forca>0){   
        for(i=0;i<*cont_forca;i++){
            forca[i]=i+1;
            printf("%d ",forca[i]);
        }
    }
    printf(" \n\n\n%s \n",palavra_decifrada);
    printf("%s \n",alfabeto);
}

void preenchimento(char *palavra_decifrada,int *tam_palavra_alvo){
    int i;

    /*a cada nova palavra em cada rodada,"palavra_decifrada" recebe 
    'underscore' correspondente ao tamanho da palavra alvo"*/
    for(i=0;i<*tam_palavra_alvo;i++){ 
        palavra_decifrada[i]='_';
    }
    palavra_decifrada[i]='\0';
}

void letra_alfabeto(char *letra,char *alfabeto){
    int i;

    i=0;
    /*loop para testar a consistencia da resposta do jogador,
    que nao pode ser barra de espaco e nem enter*/
    while((*letra==' ') || (*letra=='\n') || (*letra<65) || (*letra>90)){    
        printf("ERRO!Informe uma letra valida:\n");
        scanf("%c",letra);
        getchar();
    }
    /*loop de consistencia para ver se a letra ja foi utilizada
     pelo jogador*/
    while(*letra!=alfabeto[i]&&alfabeto[i]!='\0'){  
        i=i+1;
        if(alfabeto[i]=='\0'){
            printf("ERRO!Informe uma letra que ainda nao foi utilizada:\n");
            scanf("%c",letra);
            getchar();
            i=0;
        }
    }
}

void letra_palavra(int *achou,char *palavra_alvo,char *palavra_decifrada,char *letra){
    int i;

    i=0;
    *achou=0;
    while(palavra_alvo[i]!='\0'){
        if (*letra==palavra_alvo[i]){
            palavra_decifrada[i]=palavra_alvo[i];
            /* caso o usuario acerte alguma letra,uma 'flag' eh acionada 
            mostrando que ele nao deve perder pontos, nem chances e nem partes da forca*/
            *achou=1;  
        }
        i++;
    }
}

void compacta_alfabeto(char *alfabeto,char *letra){
    int i;

    i=0;
    while(alfabeto[i]!=*letra && alfabeto[i]!='\0'){
        i=i+1;
    }
    /*a cada letra valida usada pelo jogador, a string "alfabeto"
    deve ser atualizada retirando-se a letra utilizada*/
    while(alfabeto[i]!='\0'){ 
        alfabeto[i]=alfabeto[i+1];
        i=i+1;
    }
}

void compara(char *palavra_decifrada,char *palavra_alvo,char *continua,int *pontos,int *pontos_total,int *respondeu){
    int i;

    i=0;
    while(palavra_decifrada[i]==palavra_alvo[i] && palavra_decifrada[i]!='\0'){
        i++;
    }
    /*aqui eh testado se o jogador descobriu a palavra e pergunta-se se ele deseja 
    continuar jogando. Se sim,o programa repete o jogo para a proxima palavra.Se nao, 
    apenas eh finalizado o programa.*/
    if(palavra_decifrada[i]=='\0'){ 
        *respondeu=1;
        *pontos_total=*pontos_total+*pontos;
        printf("PARABENS!VOCE DECIFROU A PALAVRA E ACUMULOU %d PONTOS.\n",*pontos);
        printf("%s \n",palavra_alvo);
        printf("PONTUACAO TOTAL:%d.\n",*pontos_total);
        printf("DESEJA CONTINUAR JOGANDO (S/N)?");
        scanf("%c",continua);
        getchar();
        /*teste para saber a consistencia para continuacao no jogo*/
        while(*continua!='S' && *continua!='s' && *continua!='N' && *continua!='n'){ 
            printf("RESPOSTA INVALIDA. INFORME NOVAMENTE (S/N).");
            scanf("%c",continua);
            getchar();
        }
    }
}

int main () {
    /*ponteiro para o arquivo tipo texto*/
    FILE *fp;  
    /*arquivo de onde serao retiradas as palavras do jogo*/
    char palavras[50] = "content/palavras.txt";  
    char palavra_alvo[21],palavra_decifrada[21],letra,continua;
    char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    /*"achou" representa se o jogador escolheu uma letra que pertence a "palavra_alvo"*/
    /*"perdeu" representa as chances do jogador, que no caso sao 6*/
    /*"cont_forca"representa o contador para mostrar a forca*/
    /*"respondeu" indica se o jogador descobriu a palavra antes de se esgotarem as tres chances*/
    int pontos_total,pontos,achou,perdeu,cont_forca,i,tam_palavra_alvo,respondeu;
    int forca[6];


    /*arquivo aberto para leitura*/
    fp=fopen(palavras,"r"); 
    if(fp) {
        pontos_total=0;
        /*"continua" recebe 'sim' para entrar no loop principal*/
        continua='s'; 
        /*para entrar no loop, "perdeu" recebe um valor maior que zero.
         Como sao 6 as chances, resolvi colocar 6*/
        perdeu=6;     
        while ((fscanf(fp,"%s",palavra_alvo)> 0) && (perdeu>0) && (continua=='S'|| continua=='s')) {
            fscanf(fp,"%d",&pontos);
            /*a cada nova rodada,"respondeu" eh reinicidada*/
            respondeu=0; 
            /*a cada nova rodada,as chances do jogador sao reinicidas*/
            perdeu=6;    
            achou=1;
            /*a contagem para a forca tambem eh reiniciada*/
            cont_forca=0;
            i=0;
            /*a cada rodada, uma nova palavra eh buscada*/
            while(palavra_alvo[i]!='\0'){ 
                i++;
            }
            tam_palavra_alvo=i;
            preenchimento(palavra_decifrada,&tam_palavra_alvo);
            /*a cada nova rodada,o alfabeto eh reiniciado*/
            for (i=0;i<26;i++) {           
                alfabeto[i] = (char) i+ (char) 65;
            }
            alfabeto[i] = '\0';
            while(respondeu==0 && perdeu>0){
                mostra_tela(&pontos_total,&pontos,forca,palavra_decifrada,alfabeto,&cont_forca,&achou);
                printf("Escolha uma das letras acima para decifrar a palavra:\n");
                scanf("%c",&letra);
                getchar();
                letra_alfabeto(&letra,alfabeto);
                letra_palavra(&achou,palavra_alvo,palavra_decifrada,&letra);
                /*caso o jogador tenha errado a letra*/
                if(achou==0){             
                    perdeu=perdeu-1;
                    if(perdeu>0){
                    printf("Letra incorreta!!! Voce ainda tem %d chance-s-!",perdeu);
                    }else{
                        printf("Letra incorreta!!! Voce nao possui mais chances.\n");
                        pontos_total=pontos_total+pontos;
                        printf("SUA PONTUACAO FINAL FOI DE: %d. \n",pontos_total);
                    }
                    cont_forca++;
                    pontos=pontos-5;
                    printf(" Tecle enter para prosseguir!");
                    getchar();
                /*caso o jogador acerte a letra*/
                }else {                  
                    printf("ACERTOU! Tecle enter para prosseguir!");
                    getchar();
                }
                compacta_alfabeto(alfabeto,&letra);
                compara(palavra_decifrada,palavra_alvo,&continua,&pontos,&pontos_total,&respondeu);
            }
        }
        fclose(fp);
    }else{
        printf("\nArquivo nao encontrado.\n");
        exit(-1);
    }
    getchar();
    return 0;
}


