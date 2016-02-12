/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Computacao Basica - 02/2013
    Aluno(a): <Gabriel Martins de Miranda>
    Matricula: <130111350>
    Turma: E
    Versão do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao: O programa em questao funciona como uma nova versao do antigo trabalho em 
    que eh criado o famoso jogo da forca.Nesta versao, foram declaradas algumas variaveis 
    globais, alem de alocacao dinamica de memoria para uma matriz, um vetor e uma string. 
    Tambem eh mostrado o desenho da forca. */

#include<stdio.h>
#include<stdlib.h>  /*biblioteca para alocacao dinamica*/
#include<string.h>


/* soh funciona no windows */
#ifdef _WIN32
    #define CLEAR "cls" 
/* soh funciona no linux ou mac (unix) */
#else
    #define CLEAR "clear" 
#endif


typedef struct {
    char nomejogador[20];
    int pontuacao;
} tipoRanking;


typedef struct {
    char nometema[20];
} tipoTema;


int m;   /*qtd de palavras ou linhas*/                                   
char** palavras; /*matriz de palavras*/
int* pontos; /*vetor de pontos*/
int palavra_alvo; /*indice palavra atual*/
char* palavra_decifrada; /*vetor de '_'*/
char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int pontos_total; /*qtd total de pontos*/
char forca[23][31]; /*matriz forca*/
int cont_forca; /*indica proxima parte do corpo*/
char binario_texto[20];/*tema do binario que vai sar lido do arquivo texto*/
tipoTema temas; /*variavel que guarda os temas no arquivo binario*/
tipoRanking Ranking;/**/
char continua='s'; /*"continua" recebe 'sim' para entrar no loop principal*/
int perdeu=7;     /*para entrar no loop, "perdeu" recebe um valor maior que zero. 
                    Como sao 7 as chances, resolvi colocar 7*/
tipoRanking* vet_ranking;
char ranking_bin[15] ="ranking.bin";  /*arquivo de onde sera gravado o Ranking*/
char temas_bin[10]="temas.bin";


int menu() {
    int opcao;

    system (CLEAR);
    printf("1. JOGAR \n");
    printf("2. CONSULTAR RANKING \n");
    printf("3. CRIAR NOVO TEMA \n");
    printf("4. SAIR \n");

    printf("INFORME O NUMERO CORRESPONDENTE AO QUE DESEJA FAZER: \n");
    scanf("%d",&opcao);
    getchar();
    if(opcao<1 || opcao>4){
        printf("ERRO! Informe um numero valido.\n");
        scanf("%d",&opcao);
	getchar();
    }
    
    return(opcao);
}


int escolhe_tema() {
    FILE* fp;
    int i,escolha_jogador;

    system (CLEAR);
    
    
    fp=fopen(temas_bin,"rb");
    if((fp==NULL)){
        printf("NÃO HÁ TEMAS CADASTRADOS. PARA JOGAR É NECESSÁRIO CADASTRAR UM TEMA PRIMEIRO. ACESSE A OPÇÃO 3 DO MENU PRINCIPAL.\n");
        getchar();
        return 1;
    }else{
        i=0;
        while(fread(&temas,sizeof(tipoTema),1,fp)>0){
            printf("%d\t %s \n",i+1,temas.nometema);
            i++;
        }
        printf("(DIGITE 0 (ZERO) PARA SAIR)\n\n");
	    printf("INFORME O NUMERO CORRESPONDENTE AO TEMA QUE DESEJA JOGAR: \n"); 
        scanf("%d",&escolha_jogador);
	    getchar();

        if(escolha_jogador==0){
            return 1;
        }
   
        while(escolha_jogador<1 || escolha_jogador>i){
            printf("NÚMERO INVÁLIDO. DIGITE NOVAMENTE!\n");
            scanf("%d",&escolha_jogador);
	    getchar();
        }
        
        fseek(fp,(sizeof(tipoTema)*(escolha_jogador-1)),0);
        fread(&temas,sizeof(tipoTema),1,fp);
        fclose(fp);
        strcpy (binario_texto,temas.nometema);
       
        printf("Informe seu nome/apelido/nickname. \n");
        scanf("%[^\n]s",Ranking.nomejogador);
	    getchar();

    }
    getchar();
    return (10);
}        
        
int criar_tema() {
    FILE* fp;
    FILE* fp2;
    char temas_texto[20];
    int flag,k1,k2,i,pontuacao_palavra;
    char cadastra,c;
    char palavra_tema[20];

    
    system (CLEAR);

    printf("INFORME UM TEMA A SER CRIADO:\n");
    scanf("%s",temas_texto);
    getchar();
    
    fp=fopen(temas_bin,"a+b");
    flag=0;
    while(flag==0){
        rewind(fp);
        flag=1;
        while(fread(&temas,sizeof(tipoTema),1,fp)>0 && flag==1){
            k1=strlen (temas.nometema);
            k2=strlen (temas_texto);
            i=0;
	    if(k1==k2){
                while(temas.nometema[i]==temas_texto[i] && temas.nometema[i]!='\0'){
                    i++;
                }
	    }    
            if(i==k1){
                printf("TEMA JÁ EXISTENTE. ESCOLHA OUTRO TEMA!\n");
                scanf("%s",temas_texto);
         	getchar();
                flag=0;
            }
        }
    }
    fclose(fp);
    fp2=fopen(temas_texto,"w");
    cadastra='s';
    c= (char) 10;

    while(cadastra=='s' || cadastra=='S'){
        printf("DIGITE UMA PALAVRA PARA O TEMA:\n");
        scanf("%s",palavra_tema);
	getchar();
        fprintf(fp2,"%s ",palavra_tema);
        printf("DIGITE UMA PONTUACAO PARA A PALAVRA:\n");
        scanf("%d",&pontuacao_palavra);
	getchar();
        fprintf(fp2,"%d",pontuacao_palavra);
        printf("DESEJA CADASTRAR MAIS UMA PALAVRA? (S/N)\n");
        scanf("%c",&cadastra);
	getchar();
	if(cadastra=='s' || cadastra=='S'){
	    fprintf(fp2,"%c",c);
	}
	while(cadastra!='s' && cadastra!='S' && cadastra!='n' && cadastra!='N'){
            printf("ERRO! INFORME UMA RESPOSTA VALIDA!(S/N)\n");
            scanf("%c",&cadastra);
	    getchar();
        } 
    }

    fclose(fp2);
    strcpy (temas.nometema,temas_texto);
    
    fp=fopen(temas_bin,"a+b");
    
    fwrite(&temas,sizeof(tipoTema),1,fp);
    fclose(fp);
    return 3;
}
    
int ranking(){
    FILE* fp;
    int Fez_troca,cont_ranking,i;
    tipoRanking aux;
    
    
    system (CLEAR);
    
    fp = fopen(ranking_bin,"rb");

    if(fp==NULL){
        printf("NAO FOI CADASTRADO NENHUM JOGADOR AINDA!");
        getchar();
    }else{  
        cont_ranking=0;
        while(fread(&Ranking,sizeof(tipoRanking),1,fp)>0){
            cont_ranking=cont_ranking+1;
	}
      
        rewind(fp);
        vet_ranking = ((tipoRanking*) malloc(sizeof(tipoRanking)*(cont_ranking)));

        i=0;
        while(fread(&Ranking,sizeof(tipoRanking),1,fp)>0){
            vet_ranking[i]= Ranking;
            i++;
        }

        fclose(fp);

        Fez_troca=1;
        while(Fez_troca==1){
            Fez_troca=0;
            for(i=0;i<cont_ranking-1;i++){ 
                if(vet_ranking[i].pontuacao < vet_ranking[i+1].pontuacao){
                    aux=vet_ranking[i];
                    vet_ranking[i]=vet_ranking[i+1];
                    vet_ranking[i+1]=aux;
                    Fez_troca=1;
                }
            }
        }
        getchar();
	printf("*** RANKING ***\n\n");
        for(i=0;i<cont_ranking;i++){
	    printf("%d\t%s\t%d\n",i+1,vet_ranking[i].nomejogador,vet_ranking[i].pontuacao);
	}
        getchar();
        free(vet_ranking);
    }

    return 2;
}

void libera_dinamica(){ /*funcao que libera o espaco de memoria alocado dinamicamente*/
    int i;
    
    for (i=0;i<m;i++){
        free(palavras[i]);
    }
    free(palavras);
    free(pontos);
    free(palavra_decifrada);
}


void inicializa_forca(){ /*funcao que atribui "espaço" para a matriz da forca e desenha apenas a forca*/
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

void imprime_forca () {  /*funcao que imprime a forca na tela*/
    int i;

    i=0;

    for(i=0;i<23;i++){
        printf("%s\n",forca[i]);
    }

}
    

void cabeca_forca () {  /*adiciona a cabeca do personagem na matriz forca*/
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

void tronco_forca () { /*adiciona o tronco do personagem na matriz forca*/
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

void braco_direito_forca () {  /*adiciona o braco direito do personagem na matriz forca*/
    

    forca[10][25]=(char) 92;
    forca[11][26]=(char) 92;
    forca[12][27]=(char) 92;

}

void braco_esquerdo_forca () { /*adiciona o braco esquerdo do personagem na matriz forca*/
    

    forca[10][21]=(char) 47;
    forca[11][20]=(char) 47;
    forca[12][19]=(char) 47;

}

void perna_direita_forca () { /*adiciona a perna direita do personagem na matriz forca*/
   
    forca[13][24]=(char) 92;
    forca[14][25]=(char) 92;
    forca[15][26]=(char) 92;
    forca[16][27]=(char) 92;

}

void perna_esquerda_forca () {  /*adiciona a perna esquerda do personagem na matriz forca*/
   

    forca[13][22]=(char) 47;
    forca[14][21]=(char) 47;
    forca[15][20]=(char) 47;
    forca[16][19]=(char) 47;

}

void corda_forca () {  /*adiciona a corda na matriz forca*/
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

/*funcao que percorre o arquivo texto e aloca as variaveis dinamicamente*/
void matriz_arquivo(){ 
    FILE *fp;
    int n,i,aux_pontos;
    
    /*arquivo aberto para leitura*/
    fp=fopen(binario_texto,"r"); 

    m=0;
    n=0;
    i=0;
    
    while(!feof(fp)){
        while (fgetc(fp)!=(char) 32) {
            i++;
	}
        fscanf(fp,"%d",&aux_pontos);
        if (i>n) {
            n=i;
        }
        m++;
	i=0;
   }
   
   fclose(fp);
   
   /*arquivo aberto para leitura*/
   fp=fopen(binario_texto,"r"); 


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

}

void mostra_tela(int *cont_forca,int *achou){
    system (CLEAR);
    
    printf("*** JOGO DA FORCA *** \n");
    printf("PONTUACAO ACUMULADA:%d. \n",pontos_total);
    printf("PONTUACAO A RECEBER PARA ESTA PALAVRA:%d.\n",pontos[palavra_alvo]);
    

    /*caso o jogador erre alguma vez, sao mostradas na tela as componentes da matriz forca*/
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
    }
    imprime_forca();
    printf(" \n\n\n%s \n",palavra_decifrada);
    printf("%s \n",alfabeto);    
  
}    


void preenchimento(int *tam_palavra_alvo){
    int i;

    /*a cada nova palavra em cada rodada,"palavra_decifrada" recebe 'underscore' 
    correspondente ao tamanho de cada linha da matriz "palavras"*/
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
    while((*letra==' ') || (*letra=='\n')){    
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
    /*a cada letra valida usada pelo jogador, 
    a string "alfabeto" deve ser atualizada retirando-se a letra utilizada*/
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
    /*aqui eh testado se o jogador descobriu a palavra e pergunta-se se ele deseja continuar jogando.
     Se sim,o programa repete o jogo para a proxima palavra.Se nao, apenas eh finalizado o programa.*/
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

int main () {
    FILE* fp;
    char letra;
    int achou,cont_forca,i,tam_palavra_alvo,respondeu,k;
                   /*"achou" representa se o jogador escolheu uma letra que pertence a "palavras[palavra_alvo][i]"*/
                   /*"perdeu" representa as chances do jogador, que no caso sao 7*/
                   /*"cont_forca"representa o contador para mostrar a forca*/
                   /*"respondeu" indica se o jogador descobriu a palavra antes de se esgotarem as sete chances*/
    
    
    
    
    palavra_alvo=0;
    pontos_total=0;
    
    k=1;

    while(k==1 || k==2 || k==3){
        k=menu();
        if(k==1){
            k=escolhe_tema();
	}else if(k==2){
            k=ranking();
        }else if(k==3){
            k=criar_tema();
        }
    }
    
    if(k!=4){
        
        matriz_arquivo();
    }


    while (((palavra_alvo<m) && (perdeu>0) && (continua=='S'|| continua=='s')) && (k!=4)){
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
            /*caso o jogador acerte a letra*/
            }else {                   
                printf("ACERTOU! Tecle enter para prosseguir!");
                getchar();
            }
            compacta_alfabeto(&letra);
            compara(&continua,&respondeu);
        }
        palavra_alvo++;
    }
    
    if(k!=4){
    fp=fopen(ranking_bin,"a+b");   
    Ranking.pontuacao=pontos_total;
    fwrite(&Ranking,sizeof(tipoRanking),1,fp);
    fclose(fp);
    k=ranking();
    

    libera_dinamica();
    getchar();
    }
    return 0;
}


