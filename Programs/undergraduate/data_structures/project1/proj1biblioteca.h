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

    			/*interface da TAD */
    
    
#define PI 3.141592654  /*constante PI definida para calculo do angulo em graus*/
			/*usado na funcao metrica_angulo*/
typedef struct lista LISTA;	/*definicao do tipo LISTA*/

LISTA* inicializa(void);

int vazia(LISTA* p);

LISTA* buscador_pontuacao(char* arquivo,LISTA* p);

LISTA* buscador_palavra(char* arquivo,LISTA* p);	/*funcoes usadas pelo programa e implementadas*/
							/*no arquivo projfuncoes.c, onde sao comentadas*/
LISTA* insere(LISTA* p,char* conteudo);			

void mostra_tela(LISTA* p);

void mostra_tela_intersec(LISTA* p,LISTA* q);

LISTA* ordenar(LISTA* p);

float comparacao(LISTA* p,LISTA* q);

float nome_arquivos(char* arq_1,char* arq_2);

float metrica_angulo(float ang_palavra,float ang_pontuacao);

void plagio(float ang_tot);

void libera(LISTA* l);


