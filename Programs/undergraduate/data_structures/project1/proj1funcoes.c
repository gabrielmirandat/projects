/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula:  <>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao: O programa em questao utiliza uma metrica para verificar por meio de um
    produto vetorial a semelhanca entre dois arquivos, indicando se houve ou nao plagio.
    Pelo produto vetorial, pode-se verificar que angulos antre 0 e 45 indicam plagio, enquanto
    que entre 45 e 90 indicam nao-plagio. */

    	/*Arquivo de implementacao das funcoes da interface do programa*/
	
#include"proj1biblioteca.h" /*interface da TAD*/

char string[15];	/*variavel que guarda a informacao tirada dos textos*/
int tamanho;		/*tamanho da variavel "string"*/


struct lista{
    char info[15];	/*representacao do no das listas. "info" guardara ou palavras ou sinais de pontuacao*/
    int frequencia;
    struct lista* prox;		/*ponteiro para proximo no*/
};

LISTA* inicializa(void){	/*inicializa um ponteiro de LISTA com NULL*/
    return NULL;		/*funcao basica de lista = slide TAD lista encadeada e livro Celes PucRio*/
}

int vazia(LISTA* p){		/*verifica se a lista tem algum no*/
    if(p==NULL)			/*funcao basica de lista = slide TAD lista encadeada e livro Celes PucRio*/
        return 1;		/*se for NULL retorna true, caso contrario, retorna false*/
    else
        return 0;
}

LISTA* buscador_pontuacao(char* arquivo,LISTA* p){
    FILE* fp=fopen(arquivo,"r");
    int i;

    while(fscanf(fp,"%s",string)>0){
        tamanho=strlen(string);
        if(string[tamanho-1]>(char) 32 && string[tamanho-1]< (char) 64 && tamanho==1){
            p=insere(p,string);
        }else if(string[tamanho-1]>(char) 32 && string[tamanho-1]< (char) 64){
            char nova_string[2];
            nova_string[0]=string[tamanho-1];
            nova_string[1]='\0';
            p=insere(p,nova_string);		/*separa palavras e pontuacoes do texto corrente*/
        }					/*apos separar a pontuacao, chama a funcao de insercao de elementos*/
    }

    fclose(fp);
    return p;
}


LISTA* buscador_palavra(char* arquivo,LISTA* p){
    FILE* fp=fopen(arquivo,"r");
    int i;

    while(fscanf(fp,"%s",string)>0){
        tamanho=strlen(string);
        if(string[tamanho-1]> (char) 64 && string[tamanho-1]< 123){
            p=insere(p,string);
        }else if(string[tamanho-1]>(char) 32 && string[tamanho-1]< (char) 64 && tamanho!=1){
                char nova_string[tamanho];
                for(i=0;i<tamanho-1;i++){
                    nova_string[i]=string[i];
                }
                nova_string[i]='\0';
                p=insere(p,nova_string);	/*parecida com buscador_pontuacao, mas separa as palavras*/
        }					/*chama funcao de insercao de novos nos na lista de palavras*/
    }
    fclose(fp);
    return p;
}

LISTA* insere(LISTA* p,char* conteudo){
    tamanho=strlen(conteudo);
    if(vazia(p)){
        LISTA* nova = (LISTA*) malloc(sizeof(LISTA));	/*verifica se eh o primeiro no*/
        strcpy(nova->info,conteudo);
        nova->frequencia = 1;
        nova->prox = NULL;
        return nova;
    }
    				/*insere nos com as informacoes das funcoes buscador*/
    LISTA* auxiliar = p;	

    int achou=0;

    while(achou==0 && auxiliar!=NULL){
            if(strcmp(auxiliar->info,conteudo)==0){	/*loop para verificar se a info ja existe na lista*/
                achou=1;
                break;
            }
            auxiliar=auxiliar->prox;
    }

    if(achou==1){			/*caso a info exista, apenas incrementar a frequencia desta*/
        auxiliar->frequencia++;
    }else{
        LISTA* nova = (LISTA*) malloc(sizeof(LISTA));
        strcpy(nova->info,conteudo);	/*se represente noca info, aloca um novo no e atualiza o ponteiro da main*/
        nova->frequencia = 1;
        nova->prox=p;
        p=nova;
        }
    return p;
}

void mostra_tela(LISTA* p){	/*funcao que mostra todos os elementos da lista,*/
    if(vazia(p)){		/*sendo o conteudo e a frequencia de cada no*/
        printf("\t--LISTA VAZIA--\n\n");
        return;
    }
    int i;
    i=0;
    LISTA* aux;
    for(aux=p;aux!=NULL;aux=aux->prox){
            i++;
            printf("%d.\t  Conteudo:%s\t",i,aux->info);
            printf("Frequencia:%d\n",aux->frequencia);
    }
}

void mostra_tela_intersec(LISTA* p,LISTA* q){ 
    if(vazia(p) || vazia(q)){
        printf("Nao existe informacao em comuM.\n\n");
        return;
    }

    LISTA* aux1;
    LISTA* aux2;		/*mostra na tela apenas as informacoes que existem em comum entre*/
    int achou,i;		/*as duas listas*/

    i=0;
    aux1=p;
    aux2=q;
    int nulo;

    nulo=0;

    while(aux1!=NULL){		/*loop que faz a verificacao*/
        achou=0;
        while(aux2!=NULL && achou==0){
            if(strcmp(aux1->info,aux2->info)==0){
                nulo++;
                achou=1;
            }
            aux2=aux2->prox;
        }
        if(achou==1){
            i++;
            printf("%d.\t",i);
            printf("A INFORMACAO -%s-\tEH COMUM AOS DOIS TEXTOS.\n",aux1->info);
        }
        aux2=q;
        aux1=aux1->prox;
    }
    if(nulo==0){
       printf("Nao existe informacao em comuM.\n\n");
    }
}

LISTA* ordenar(LISTA* p){		
    if(vazia(p)){
        return NULL;
    }

    LISTA* aux;
    LISTA* temp;		/*funcao que faz a ordenacao da lista por ordem decrescente*/
    LISTA* ant;			/*de frequencia*/
    int i,qtd_elementos;


    qtd_elementos=0;
    for(aux=p;aux!=NULL;aux=aux->prox){
        qtd_elementos++;
    }

    aux=p;

    int fez_troca=1;

    while(fez_troca==1){
        fez_troca=0;
        for(i=0;i<qtd_elementos-1;i++){
            if(aux->prox->frequencia>aux->frequencia){
                if(i==0){
                    if(p->prox->frequencia>p->frequencia){
                        p=aux->prox;
                    }
                }

                temp = aux->prox;		/*o metodo utilizado para ordenar foi o BubbleSort,*/
                				/*implementado para trabalhar com a lista*/
                aux->prox =temp->prox;

                temp->prox=aux;

                if(ant!=NULL){
                    ant->prox = temp;
                }
                fez_troca=1;

            }else{
                aux=aux->prox;
            }

            if(i==0){
                ant=p;
            }else{
                ant=ant->prox;
            }
        }
        aux=p;
        temp=NULL;
        ant=NULL;
    }
    return p;
}

float comparacao(LISTA* p,LISTA* q){
    if(vazia(p) && vazia(q)){
        return (0.00000);
    }
    if(vazia(p) || vazia(q)){
        return (PI/2);
    }
    LISTA* aux1;			/*funcao para calculo de metrica de projecao e metrica do*/
    LISTA* aux2;			/*angulo por produto vetorial*/
    int m_projecao,achou;
    float mod1,mod2;
    aux1=p;
    aux2=q;

    m_projecao=0;
    while(aux1!=NULL){
        achou=0;
        while(aux2!=NULL && achou==0){
            if(strcmp(aux1->info,aux2->info)==0){
                achou=1;
                break;
            }
            aux2=aux2->prox;
        }
        if(achou==1){
            m_projecao=m_projecao+(aux1->frequencia*aux2->frequencia);
        }
        aux2=q;
        aux1=aux1->prox;
    }
    mod1=0;

    for(aux1=p;aux1!=NULL;aux1=aux1->prox){
        mod1=mod1 +(aux1->frequencia*aux1->frequencia);
    }
    mod1 = sqrt(mod1);

    mod2=0;

    for(aux2=q;aux2!=NULL;aux2=aux2->prox){
        mod2=mod2 + (aux2->frequencia*aux2->frequencia);
    }
    mod2 = sqrt(mod2);
    
    float ang = acos((float)m_projecao/(mod1*mod2));

    return ang;
}

float nome_arquivos(char* arq_1,char* arq_2){		/*funcao que mostra na tela quais arquivos*/
    printf("--PRIMEIRO ARQUIVO:%s.--\n",arq_1);		/*usados pelo usuario*/

    printf("--SEGUNDO  ARQUIVO:%s.--\n",arq_2);

}

float metrica_angulo(float ang_palavra,float ang_pontuacao){
	
    float ang_final = ((0.9)*ang_palavra + (0.1)*ang_pontuacao);

    float ang_graus = ((ang_final*180)/PI);	/*metrica adicional para calculo do angulo final*/
    						/*Foi dado peso de 90% para o angulo de palavras e*/
    if(isnan(ang_graus)){			/*10% para o angulo de sinais de pontuacao*/
    	    ang_graus = 0.00;
    }
    
    printf("--ANGULO EM GRAUS ENTRE OS ARQUIVOS = %.2f--\n",ang_graus);

    return ang_graus;
    
}

void plagio(float ang_tot){	/*funcao de conclusao, faz conversao do angulo final para porcentagem*/
	float porcentagem;	/*de igualdade entre os textos e confirma se houve ou nao plagio.*/

	porcentagem = (1 - (ang_tot/90.0));

	porcentagem = porcentagem*100;

	printf("--OS ARQUIVOS SAO %.2f%% IGUAIS.--\n",porcentagem);

	if(ang_tot<45.0){
		printf("--HOUVE PLAGIO.--\n");
	}else{
		printf("--NAO HOUVE PLAGIO.--\n");
	}	
}	

void libera(LISTA* l){		/*funcao de liberacao dos nos da lista alocados dinamicamente*/
	LISTA* p=l;		/*funcao basica de lista = slide TAD lista encadeada e livro Celes PucRio*/
    while(p!=NULL){
        LISTA* t = p->prox;
        free(p);
        p=t;
    }
}


