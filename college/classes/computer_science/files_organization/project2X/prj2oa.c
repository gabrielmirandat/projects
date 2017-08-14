#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/prj2oa.h"

/*para limpar a tela do terminal*/
#ifdef _WIN32
    #define CLEAR "cls" /* soh funciona no windows */
#else
    #define CLEAR "clear" /* soh funciona no linux ou mac (unix) */
#endif



/******************VARIAVEIS GLOBAIS****************************/
char str1[10];
char str2[43];      /*palavras current do arquivo*/
char concatenado[50];

FILE* fp1;   /*ponteiro do arquivo lista.txt*/
FILE* fp2;   /*ponteiro do arquivo arvindice.txt*/

int bytes_lista;  /*tamanho de cada registro*/
int bytes_arvore = 145;

int IND_RAIZ=0;
int IND_PAG_ATUAL=0;
int FLAG_COMPARACAO;
int FLAG_ARV;
int FLAG_PROBLEMA=0;
int SEEKS =0;
int ACHOU=0;
int IND=0;

char str_vazia[31] = "                              ";
Registro vetor_aux[5];



/******************************FUNCOES**************************/  
PAGINA* inicia_pagina(PAGINA* atual){
  int i;
  atual = (PAGINA*) malloc(sizeof(PAGINA));
  /*memset preenche vetor*/
  for(i=0;i<4;i++){
    strcpy(atual->chave[i].nome,str_vazia);
  }
  
  for(i=0;i<5;i++) atual->prr_filha[i]=-1;
  
  atual->N_DE_CHAVES = 0;
  atual->N_DE_FILHOS = 0;
  
  atual->indice = 0;
  
  return atual;
  
}

/*retorna quantos bytes há por registro*/
void bytes_registro(){
    char str[100];
    
    fp1=fopen("content/lista.txt","r");
    if(fp1=NULL){
      printf("Erro ao abrir lista.txt.\n");
      exit(0);
    }
    fscanf(fp1,"%[^\n]s",str);
    bytes_lista=strlen(str)+1;
    fclose(fp1);
}


/* le cada registro p/ criar os indices primários*/
void leitor_arquivo(PAGINA* pag){

    fp1=fopen("content/lista.txt","r");
    if(fp1=NULL){
      printf("Erro ao abrir lista.txt.\n");
      exit(0);
    }
    while(fscanf(fp1,"%s",str1)>0){
        fseek(fp1,1,SEEK_CUR);
        fread(str2,1,41,fp1);
        str2[40]='\0';
        fseek(fp1,19,SEEK_CUR);
        concatenador();
	
        pag = recupera_info_arquivo(pag,IND_RAIZ);
	      inicia_constantes_globais();
	      compara_arvore(IND_RAIZ,concatenado);
	      if (FLAG_COMPARACAO==-1) construtor_B_tree(pag);
    }
    fclose(fp1);
}

void concatenador(){
    int j;
    int i=0;
    
    memset(concatenado,' ',sizeof(concatenado));
    
    while(str1[i]!='\0'){
        concatenado[i]=str1[i];
        i++;
    }
    j=i;
    i=0;
    while(str2[i]!='\0'){
        concatenado[j]=str2[i];
        i++;
        j++;
    }
    concatenado[30]='\0';
}

/* Rearranja os elementos do vetor vet[0..tam-1] 
de modo que fiquem em ordem crescente == HEAPSORT*/
void ordenacao( Registro* vet, int tam){
   tam=tam-1;
   int p, m;
   for (p = tam/2; p >= 0; --p)
      peneira( p, tam, vet);
   for (m = tam; m >= 1; --m) {
      troca_posicao(vet,0, m);
      peneira( 0, m-1, vet);
   }
}

/*Recebe p em 0..m e rearranja o vetor vet[0..m] de modo 
que o "subvetor" cuja current é p seja um max-heap.
Supõe que os "subvetores" cujas raízes são filhos
de p já são max-heaps.*/

void peneira( int p, int m, Registro* vet){
   int f = 2*p;
   while (f <= m) {  
      if (f < m && strcmp(vet[f].nome,vet[f+1].nome)<0)  ++f;
      //f é o filho "mais valioso" de p
      
      if (strcmp(vet[f/2].nome,vet[f].nome)>=0) break;
      troca_posicao(vet,f/2, f);
      f *= 2;
   }
}

/*troca_posição indice 1 por indice 2*/
void troca_posicao(Registro* vet, int ind1, int ind2){
   char pal_aux[31];
   
   strcpy(pal_aux,vet[ind2].nome);
  
   strcpy(vet[ind2].nome,vet[ind1].nome);
  
   strcpy(vet[ind1].nome,pal_aux);

}


/*realiza a pesquisa sequencial no vetor*/
int pesquisar(Registro* vet, int ind, char* busca){
    int achou=-1;
    int contador;
    int fim= ind-1;
    
    for(contador=0;contador<=fim;contador++){
      if(strcmp(vet[contador].nome,busca)==0){
        achou=contador;
        break;
      }
    }
    return achou; 
}

void printar_pagina_atual_tela(PAGINA* atual){
    int i;
    
    
    for(i=0;i<4;i++){
      printf("chave%d: %s\n",i+1,atual->chave[i].nome);
    }
    
    for(i=0;i<5;i++){
      printf("pag_filha%d: %d\n",i+1,atual->prr_filha[i]);
    }
    
    printf("N_DE_CHAVES:%d\n",atual->N_DE_CHAVES);
    printf("N_DE_FILHOS:%d\n",atual->N_DE_FILHOS);
    printf("IND_PAG_ATUAL:%d\n\n",atual->indice);
}


void printar_pagina_atual_arquivo(PAGINA* atual, int byte_offset){
  fp2=fopen("content/arvindice.txt","r+");
  
  if(fp2==NULL)  fp2=fopen("content/arvindice.txt","w");

  if(fp2=NULL){
      printf("Erro ao abrir arvindice.txt.\n");
      exit(0);
  }
  
  fseek(fp2,byte_offset*bytes_arvore,SEEK_SET);
  
  fprintf(fp2,"%d|%d |%s|%s|%s|%s| %02d|%02d|%02d|%02d|%02d\n",
     atual->N_DE_CHAVES,atual->N_DE_FILHOS,atual->chave[0].nome,atual->chave[1].nome,
     atual->chave[2].nome,atual->chave[3].nome,atual->prr_filha[0], atual->prr_filha[1],
     atual->prr_filha[2],atual->prr_filha[3],atual->prr_filha[4]);
  
  fclose(fp2);

}


PAGINA* recupera_info_arquivo(PAGINA* pag,int byte_offset){
  fp2=fopen("content/arvindice.txt","r+"); 
  if(fp2=NULL){
    printf("Erro ao abrir arvindice.txt.\n");
    exit(0);
  }

  char ch;
  char ch2[3];
  int i;
  
  fseek(fp2,byte_offset*bytes_arvore,SEEK_SET);
  
  ch = fgetc(fp2);
  
  pag->N_DE_CHAVES = ch - '0';
  
  ch = fgetc(fp2);
  ch = fgetc(fp2);
  
  pag->N_DE_FILHOS = ch - '0';
  
  fseek(fp2,2,SEEK_CUR);
 
  for(i=0;i<4;i++){
    fread(pag->chave[i].nome,30,1,fp2);
    pag->chave[i].nome[30] = '\0';
    ch = fgetc(fp2);
  }

  ch = fgetc(fp2);
  
  for(i=0;i<5;i++){
    fread(ch2,2,1,fp2);
    ch2[2]='\0';
    pag->prr_filha[i] = atoi(ch2);
    ch = fgetc(fp2);
  }
  
  pag->indice = byte_offset;
  
  fclose(fp2);
  
  return pag;
}



void construtor_B_tree(PAGINA* current){
  int i=0;
  int j=0;
  
  if(current->prr_filha[0]==-1) FLAG_ARV=2;
  
  if(FLAG_ARV==1){
    while(i<4 && strcmp(current->chave[i].nome,str_vazia)!=0 && strcmp(current->chave[i].nome,concatenado)<0) i++;
    PAGINA* current2=NULL;
    current2 = inicia_pagina(current2);
    current2 = recupera_info_arquivo(current2,current->prr_filha[i]);
    construtor_B_tree(current2);
  }
  
  
  if(FLAG_ARV==2)
  {
    /*se for 2 é porque houveram dois cheios consecutivos*/    
    if(current->N_DE_CHAVES!=4)
    {
      /*coloca concatenado e ordena*/
      strcpy(current->chave[current->N_DE_CHAVES].nome,concatenado);
      current->N_DE_CHAVES = current->N_DE_CHAVES + 1;
      ordenacao(current->chave, current->N_DE_CHAVES);
        
      
      /*se estamos inserindo em nao folha..temos que i é o indice que acessou o filho*/
      if(current->prr_filha[0]!=-1)
      {
        int ind = i+1;
	      int prr = current->prr_filha[ind];
	      current->prr_filha[ind] = IND_PAG_ATUAL;
	      while(ind!=4)
        {
	         ind++;
	         int prr2 = current->prr_filha[ind];
	         current->prr_filha[ind] = prr;
	         prr=prr2;
	      }
        current->N_DE_FILHOS = current->N_DE_FILHOS+1; 
      }
      
      printar_pagina_atual_arquivo(current, current->indice);
      FLAG_ARV=1;
    }else if(current->N_DE_CHAVES==4)
    {  
      /*se for 2 é porque houveram dois cheios consecutivos*/
      FLAG_PROBLEMA++;
      
      /*split normal*/
      for(j=0;j<4;j++) strcpy(vetor_aux[j].nome,current->chave[j].nome); 
      strcpy(vetor_aux[4].nome,concatenado);  
  
      ordenacao(vetor_aux,5);
      
      for(j=0;j<2;j++) strcpy(current->chave[j].nome,vetor_aux[j].nome);
      for(j=2;j<4;j++) strcpy(current->chave[j].nome,str_vazia);
    
      current->N_DE_CHAVES = current->N_DE_CHAVES-2; 
  
      int f1 = current->prr_filha[3];
      int f2= current->prr_filha[4];
      current->prr_filha[3] = -1;
      current->prr_filha[4] = -1;
      
      if(FLAG_PROBLEMA>=2) current->N_DE_FILHOS = current->N_DE_FILHOS - 2;
	
      printar_pagina_atual_arquivo(current,current->indice);
      
      int cond1 = current->indice;
    
      IND_PAG_ATUAL++;
      free(current);
      current=NULL;
      current = inicia_pagina(current);
      current->indice = IND_PAG_ATUAL;
      for(j=0;j<2;j++) strcpy(current->chave[j].nome,vetor_aux[j+3].nome);
      current->N_DE_CHAVES=2;
      
      
      if(FLAG_PROBLEMA>=2)
      {
	      current->prr_filha[0] = f1;
        current->prr_filha[1] = f2;
        current->prr_filha[2] = IND_PAG_ATUAL-1;
	      current->N_DE_FILHOS = current->N_DE_FILHOS + 3;
      }
      
      printar_pagina_atual_arquivo(current,current->indice);
      strcpy(concatenado,vetor_aux[2].nome);
      
      if(cond1==IND_RAIZ)
      {
	      IND_PAG_ATUAL++;
        free(current);
        current=NULL;
        current = inicia_pagina(current);
	      current->indice = IND_PAG_ATUAL;
        strcpy(current->chave[0].nome,concatenado);
        current->N_DE_CHAVES=1;
        current->N_DE_FILHOS=2;
        current->prr_filha[0]=IND_RAIZ;
        current->prr_filha[1]=IND_PAG_ATUAL-1;
        printar_pagina_atual_arquivo(current,IND_PAG_ATUAL);
        IND_RAIZ = IND_PAG_ATUAL;
	      FLAG_ARV=1;
      }
    }  
  }
}  

void compara_arvore(int indice,char* palavra){
  int i;
  if (FLAG_COMPARACAO==-1){
    if(indice!=-1){
      PAGINA* teste_aux = NULL;
      teste_aux = inicia_pagina(teste_aux);
      
      teste_aux = recupera_info_arquivo(teste_aux,indice); //inicia pagina correspondente ao indice
       
      if(pesquisar(teste_aux->chave,4,palavra)!=-1){ //tenta encontrar elemento na pagina atual
        FLAG_COMPARACAO=1; //se encontrar, aciona uma flag p/ sair da função
        return;
      }  
     
      for(i=0;i<5;i++){
        compara_arvore(teste_aux->prr_filha[i],palavra);
      }
    } 
  }
}  

void inicia_constantes_globais(){
  FLAG_COMPARACAO=-1;
  FLAG_ARV=1;
  FLAG_PROBLEMA=0;
  SEEKS = 0;
  ACHOU=0;
}

void buscar_registro(PAGINA* current){
  int i=0;

    while(i<4 && strcmp(current->chave[i].nome,str_vazia)!=0 && strcmp(current->chave[i].nome,concatenado)<0) i++;
    
    if(strcmp(current->chave[i].nome,concatenado)==0){
      IND = current->indice;
      ACHOU=1;
      return;
    }else if(current->prr_filha[i]!=-1){
      current = recupera_info_arquivo(current,current->prr_filha[i]);
      SEEKS++;
      buscar_registro(current);
  }
}

int incluir_registro(){
  char opcao[3]; 
  char curso[2];
  char turma[3];
  
  printf("Insira a matricula:\n");
  scanf("%6s",str1);
  getchar();
  printf("Insira o nome:\n");
  scanf("%40[^\n]s",str2);
  getchar();
  
  concatenador();
  inicia_constantes_globais();
  compara_arvore(IND_RAIZ,concatenado);
  
  if(FLAG_COMPARACAO==1){
      printf("Erro. O registro ja existe.\n");
      return 0;
  }  
  
  printf("Insira a opção:\n");
  scanf("%2s",opcao);
  getchar();
  printf("Insira o curso:\n");
  scanf("%1s",curso);  
  getchar();
  printf("Insira turma:\n");
  scanf("%2s",turma);  
  getchar();
  
  fp1 = fopen("content/lista.txt","a");
  if(fp1==NULL){
      printf("Erro ao abrir lista.txt.\n");
      exit(0);
  }  
  
  fprintf(fp1,"%-7s%-41s%-6s%-10s%-2s\n",str1,str2,opcao,curso,turma);
  fclose(fp1);
  return 1;
}


void menu(){
  system("clear");
  int resp;
  int i;
  PAGINA* atual = NULL;
  
  resp=1;
  while(resp!=0){

    printf("1. Visualizar árvore-B.\n");
    printf("2. Buscar registro.\n");
    printf("3. Incluir registro.\n");
    printf("0. Sair\n\n");

    printf("Selecione uma opcao:\n");
    scanf("%d",&resp);
    getchar();

    switch(resp)
    {
      case 1:
	       system("clear");
	       atual = inicia_pagina(atual);
	       for(i=0;i<=IND_PAG_ATUAL;i++)
         {
	           atual = recupera_info_arquivo(atual,i);
             printar_pagina_atual_tela(atual);
	       }
         free(atual);
	    break;
      case 2:
	       system("clear");
	       atual = inicia_pagina(atual);
         inicia_constantes_globais();
         printf("Insira a matricula:\n");
         scanf("%6s",str1);
	       getchar();	
         printf("Insira o nome:\n");
         scanf("%40[^\n]s",str2);
	       getchar();
	       concatenador();
	       atual = recupera_info_arquivo(atual,IND_RAIZ);
	       buscar_registro(atual);
  
	       if(ACHOU==1)
         {
	         atual = recupera_info_arquivo(atual,IND);
	         printar_pagina_atual_tela(atual);
	         printf("%d seeks.\n",SEEKS);  
	       }else if(ACHOU!=1)
           printf("Chave inexistente.\n"); 
         
         free(atual);
	    break;
      case 3:
         system("clear");
	       if(incluir_registro())
         {
	         printf("\ninserido com sucesso!\n");
	         atual = inicia_pagina(atual);
	  
	         atual =  recupera_info_arquivo(atual,IND_RAIZ);
	         inicia_constantes_globais();
	         construtor_B_tree(atual);
  	  
	         free(atual);
	       }
	    break;
      case 0:
	         system("clear");
           resp=0;
	    break;
      default:
	         printf("Insira uma resposta válida.\n"); 
    }
    printf("pressione enter:");
    getchar();
    system("clear");
  }
}
