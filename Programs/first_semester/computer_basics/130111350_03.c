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
#include<string.h>
#include<stdlib.h>

int m;   /*qtd de palavras ou linhas*/                                   
char** palavras; /*matriz de palavras*/
int* pontos; /*vetor de pontos*/
int palavra_alvo; /*indice palavra atual*/
char* palavra_decifrada; /*vetor de '_'*/
char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int pontos_total; /*qtd total de pontos*/
char forca[23][31]; /*matriz forca*/
int cont_forca; /*indica proxima parte do corpo*/




void libera_dinamica(){
    int i;
    
    for (i=0;i<m;i++){
        free(palavras[i]);
    }
    free(palavras);
    free(pontos);
    free(palavra_decifrada);
}


void inicializa_forca(){
    int i,j;

    for(i=0;i<23;i++){
        for(j=0;j<30;j++){
        forca[i][j]=' ';
        }
    }
    for(i=0;i<23;i++){
        forca[i][30]='\0';
    }     

    i=1;
    for(j=6;j<23;j++){
        forca[i][j]='-';
    }
    forca[i][5]='+';
    forca[i][23]='+';

    j=5;
    for(i=2;i<19;i++){
        forca[i][j]='|';
    }
    forca[2][23]='|';
    forca[3][23]='|';
    forca[4][23]='+';
    
    i=19;
    for(j=4;j<7;j++){
        forca[i][j]='+';
    }
    
    i=20;
    for(j=3;j<8;j++){
        forca[i][j]='+';
    }

    i=21;
    for(j=2;j<9;j++){
        forca[i][j]='+';
    }
        
}

void imprime_forca () {
    int i;

    i=0;

    for(i=0;i<23;i++){
        printf("%s\n",forca[i]);
    }

}
    

void cabeca_forca () {
    int i,j;

    i=5;
    for(j=22;j<25;j++){
        forca[i][j]='_';
    }

    i=6;
    forca[i][21]=(char) 47;
    forca[i][25]=(char) 92;
  
    i=7;
    forca[i][21]=(char) 92;
    forca[i][25]=(char) 47;
    forca[i][22]='_';
    forca[i][24]='_';

}

void tronco_forca () {
    int i,j;

    j=23;
    forca[8][j]='|';
    forca[9][j]='+';
    forca[10][j]='|';
    forca[11][j]='|';
    forca[12][j]='|';
    
    i=9;
    forca[i][22]='-';
    forca[i][24]='-';

}

void braco_direito_forca () {
    

    forca[10][25]=(char) 92;
    forca[11][26]=(char) 92;
    forca[12][27]=(char) 92;

}

void braco_esquerdo_forca () {
    

    forca[10][21]=(char) 47;
    forca[11][20]=(char) 47;
    forca[12][19]=(char) 47;

}

void perna_direita_forca () {
   
    forca[13][24]=(char) 92;
    forca[14][25]=(char) 92;
    forca[15][26]=(char) 92;
    forca[16][27]=(char) 92;

}

void perna_esquerda_forca () {
   

    forca[13][22]=(char) 92;
    forca[14][21]=(char) 92;
    forca[15][20]=(char) 92;
    forca[16][19]=(char) 92;

}

void corda_forca () {
    int i;


    i=4;
    forca[i][21]='_';
    forca[i][22]='_';
    forca[5][20]=(char) 47;
    forca[6][19]=(char) 47;
    forca[7][19]=(char) 92;

    i=8;
    forca[i][20]='-';
    forca[i][21]='-';
    forca[i][22]='-';
    forca[i][24]='-';
    forca[i][25]='-';
    forca[i][26]='-';

}

void matriz_arquivo(char *arquivo){
    FILE *fp;
    int n,i,aux_pontos;
    
    fp=fopen(arquivo,"r"); /*arquivo aberto para leitura*/
    if(fp) {
        
        m=0;
        n=0;
        i=0;
        while(!feof (fp)){
            while (fgetc(fp)!=(char) 32) {
                i++;
            }
            fscanf(fp,"%d",&aux_pontos);
            if (i>n) {
                n=i;
            }
            m++;
        }

       fclose(fp);
   
       fp=fopen(arquivo,"r"); /*arquivo aberto para leitura*/


        palavras = (char**) malloc(sizeof(char*)*m);
        for(i=0;i<m;i++){
            palavras[i] = (char*) malloc(sizeof(char)*(n+1));
        }

        pontos = (int*) malloc(sizeof(int)*m);
        


        palavra_decifrada = (char*) malloc(sizeof(char)*(n+1));
        

        i=0;
        while ((fscanf(fp,"%s",palavras[i])> 0)){
            fscanf(fp,"%d",&pontos[i]);
            i++;
        }

        fclose(fp);
    }else{
        printf("\nArquivo nao encontrado.\n");
        exit(-1);
    }
}

void mostra_tela(int *cont_forca,int *achou){
    int i;

    printf("\n--------------------------------------------------------------------------------\n");
    printf("*** JOGO DA FORCA *** \n");
    printf("PONTUACAO ACUMULADA:%d. \n",pontos_total);
    printf("PONTUACAO A RECEBER PARA ESTA PALAVRA:%d.\n",pontos[palavra_alvo]);
    imprime_forca();

    /*caso o jogador erre alguma vez,o vetor "forca eh atualizado e sao mostradas 
    na tela os numeros correspondentes as partes do corpo perdidas*/
    if(*cont_forca>0){   
        
        if(*cont_forca>5){  
                 perna_esquerda_forca();
                 
       	}
	else if(*cont_forca>4){
                 perna_direita_forca();
                 
        }
	else if(*cont_forca>3){ 
                 braco_esquerdo_forca();
                 
        }
	else if(*cont_forca>2){
                 braco_direito_forca();
                 
        }
	else if(*cont_forca>1){
                 tronco_forca();
                   
        }
	else{
                cabeca_forca();
                
       }
        
    	printf(" \n\n\n%s \n",palavra_decifrada);
   	printf("%s \n",alfabeto);
	}
	 imprime_forca();
}


void preenchimento(int *tam_palavra_alvo){
    int i;

    /*a cada nova palavra em cada rodada,"palavra_decifrada" 
    recebe 'underscore' correspondente ao tamanho da palavra alvo"*/
    for(i=0;i<*tam_palavra_alvo;i++){ 
        palavra_decifrada[i]='_';
    }
    palavra_decifrada[i]='\0';
}

void letra_alfabeto(char *letra){
    int i;

    i=0;
    /*loop para testar a consistencia da resposta do jogador,
    que nao pode ser barra de espaco e nem enter*/
    while((*letra==' ') || (*letra=='\n') || (*letra<65) || (*letra>90)){     
        printf("ERRO!Informe uma letra valida:\n");
        scanf("%c",letra);
        getchar();
    }
    /*loop de consistencia para ver se a letra ja foi utilizada pelo jogador*/
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

void letra_palavra(int *achou,char *letra){
    int i;

    i=0;
    *achou=0;
    while(palavras[palavra_alvo][i]!='\0'){
        if (*letra==palavras[palavra_alvo][i]){
            palavra_decifrada[i]=palavras[palavra_alvo][i];
            /* caso o usuario acerte alguma letra,uma 'flag' eh acionada 
            mostrando que ele nao deve perder pontos, nem chances e nem partes da forca*/
            *achou=1;  
        }
        i++;
    }
}

void compacta_alfabeto(char *letra){
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

void compara(char *continua,int *respondeu){
    int i;

    i=0;
    while(palavra_decifrada[i]==palavras[palavra_alvo][i] && palavra_decifrada[i]!='\0'){
        i++;
    }
     /*aqui eh testado se o jogador descobriu a palavra e pergunta-se se ele deseja continuar 
     jogando. Se sim,o programa repete o jogo para a proxima palavra.Se nao, apenas eh finalizado o programa.*/
    if(palavra_decifrada[i]=='\0'){
        *respondeu=1;
        pontos_total=pontos_total+pontos[palavra_alvo];
        printf("PARABENS!VOCE DECIFROU A PALAVRA E ACUMULOU %d PONTOS.\n",pontos[palavra_alvo]);
        printf("%s \n",palavras[palavra_alvo]);
        printf("PONTUACAO TOTAL:%d.\n",pontos_total);
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

int main (void) {
    /*arquivo de onde serao retiradas as palavras do jogo*/
    char arquivo[40] = "content/palavras.txt";  
    char letra,continua;
    /*"achou" representa se o jogador escolheu uma letra que pertence a "palavra_alvo"*/
    /*"perdeu" representa as chances do jogador, que no caso sao 6*/
    /*"cont_forca"representa o contador para mostrar a forca*/
    /*"respondeu" indica se o jogador descobriu a palavra antes de se esgotarem as tres chances*/
    int achou,perdeu,cont_forca,i,tam_palavra_alvo,respondeu;


    matriz_arquivo(arquivo);
    
    palavra_alvo=0;
    pontos_total=0;
    /*"continua" recebe 'sim' para entrar no loop principal*/
    continua='s'; 
    /*para entrar no loop, "perdeu" recebe um valor maior que zero.
     Como sao 7 as chances, resolvi colocar 7*/
    perdeu=7;     
    while ((palavra_alvo<m) && (perdeu>0) && (continua=='S'|| continua=='s')) {
        /*a cada nova rodada,"respondeu" eh reinicidada*/
        respondeu=0; 
        /*a cada nova rodada,as chances do jogador sao reinicidas*/
        perdeu=7;    
        achou=1;
        /*a contagem para a forca tambem eh reiniciada*/
        cont_forca=0;
        i=0;
        /*a cada rodada, uma nova palavra eh buscada*/
        while(palavras[palavra_alvo][i]!='\0'){ 
            i++;
        }
        tam_palavra_alvo=i;
        preenchimento(&tam_palavra_alvo);
        /*a cada nova rodada,o alfabeto eh reiniciado*/
        for (i=0;i<26;i++) {           
            alfabeto[i] = (char) i+ (char) 65;
        }
        alfabeto[i] = '\0';

        inicializa_forca();
       
        while(respondeu==0 && perdeu>0){
            mostra_tela(&cont_forca,&achou);
            printf("Escolha uma das letras acima para decifrar a palavra:\n");
            scanf("%c",&letra);
            getchar();
            letra_alfabeto(&letra);
            letra_palavra(&achou,&letra);
            /*caso o jogador tenha errado a letra*/
            if(achou==0){             
                perdeu=perdeu-1;
                if(perdeu>0){
                printf("Letra incorreta!!! Voce ainda tem %d chance-s-!",perdeu);
                }else{
                    printf("Letra incorreta!!! Voce nao possui mais chances.\n");
                    pontos_total=pontos_total+pontos[palavra_alvo];
		    corda_forca();
		    imprime_forca();
                    printf("SUA PONTUACAO FINAL FOI DE: %d. \n",pontos_total);
                }
                cont_forca++;
                pontos[palavra_alvo]=pontos[palavra_alvo]-5;
                printf(" Tecle enter para prosseguir!");
                getchar();
            }else {                   /*caso o jogador acerte a letra*/
                printf("ACERTOU! Tecle enter para prosseguir!");
                getchar();
            }
            compacta_alfabeto(&letra);
            compara(&continua,&respondeu);
        }
        palavra_alvo++;
    }
    
    libera_dinamica();
    getchar();
    return (0);
}


