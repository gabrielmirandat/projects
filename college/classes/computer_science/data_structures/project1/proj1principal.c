/*  Universidade de Brasilia
    Instituto de Ciencias Exatas
    Departamento de Ciencia da Computacao
    Estrutura de Dados - 1/2014
    Aluno(a): <Matheus de Oliveira Vieira>  Matricula: <130126420>
    Aluno(a): <Gabriel Martins de Miranda>  Matricula: <130111350>
    Turma: E
    Versao do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
    Descricao: O programa em questao utiliza uma metrica para verificar por meio de um
    produto vetorial a semelhanca entre dois arquivos, indicando se houve ou nao plagio.
    Pelo produto vetorial, pode-se verificar que angulos antre 0 e 45 indicam plagio, enquanto
    que entre 45 e 90 indicam nao-plagio. */

    			/*arquivo principal : representa a main do programa*/
			
#include"proj1biblioteca.h"  /*aqui eh incluida a biblioteca de funcoes criadas*/


int main(){
    char arquivo1[20];    /*declaracao de variaveis*/
    char arquivo2[20];
    LISTA* pal_txt_1;
    LISTA* pal_txt_2;	/*referencias para ponteiros tipo LISTA*/
    LISTA* pont_txt_1;
    LISTA* pont_txt_2;

    printf("\t     -------   PROGRAMA DE VERIFICACAO DE PLAGIO   -------\n\n");
    printf("INFORME O TEXTO 1.\n");
    scanf("%s",arquivo1);
    getchar();					/*leitura de arquivos*/
    printf("INFORME O TEXTO 2.\n");
    scanf("%s",arquivo2);
    getchar();

    FILE* temp1;FILE* temp2;
    temp1=fopen(arquivo1,"r");
    temp2=fopen(arquivo2,"r");
    if(!temp1 || !temp2){
      printf("\nImpossivel abrir algum dos arquivos.\n");
      exit(-1);
    }else{
      fclose(temp1);fclose(temp2);
    }
    
    pal_txt_1=inicializa();			/*inicializa cada variavel tipo LISTA com NULL*/
    pal_txt_2=inicializa();
    pont_txt_1=inicializa();
    pont_txt_2=inicializa();



    pal_txt_1=buscador_palavra(arquivo1,pal_txt_1);		/*cada ponteiro passa a referenciar o inicio da lista*/

    pont_txt_1=buscador_pontuacao(arquivo1,pont_txt_1);

    pal_txt_2=buscador_palavra(arquivo2,pal_txt_2);

    pont_txt_2=buscador_pontuacao(arquivo2,pont_txt_2);



    pal_txt_1=ordenar(pal_txt_1);

    pont_txt_1=ordenar(pont_txt_1);	/*cada lista eh ordenada, atualizando o ponteiro que as representa*/

    pal_txt_2=ordenar(pal_txt_2);

    pont_txt_2=ordenar(pont_txt_2);

    /*funcao adicional para mostrar na tela cada no de cada lista, sua informacao e frequencia*/
    /*
    printf("\n\n---PALAVRAS E FREQUENCIA DO TEXTO 1---\n\n");	
    mostra_tela(pal_txt_1);
    printf("\n\n---SINAIS E FREQUENCIA DO TEXTO 1---\n\n");
    mostra_tela(pont_txt_1);
    printf("---PALAVRAS E FREQUENCIA DO TEXTO 2---\n\n");
    mostra_tela(pal_txt_2);
    printf("\n\n---SINAIS E FREQUENCIA DO TEXTO 2---\n\n");
    mostra_tela(pont_txt_2);*/


    printf("\n\n---PALAVRAS COMUNS ENTRE AS DUAS LISTAS---\n");	/*mostra na tela as informacoes comuns entre os textos*/
    mostra_tela_intersec(pal_txt_1,pal_txt_2);
    printf("\n\n---SINAIS COMUNS ENTRE AS DUAS LISTAS---\n");
    mostra_tela_intersec(pont_txt_1,pont_txt_2);


    printf("\n\n\t\t\t-------   CONCLUSAO   -------\n\n");
    float ang_pal = comparacao(pal_txt_1,pal_txt_2);		/*calculos para metrica da comparacao*/

    float ang_pont = comparacao(pont_txt_1,pont_txt_2);

    nome_arquivos(arquivo1,arquivo2);	/*mostra na tela os arquivos usados*/

    float ang_total=metrica_angulo(ang_pal,ang_pont);	/*metrica adicional para angulo final*/
    
    plagio(ang_total);	/*calcula a porcentagem da igualdade entre os textos*/

    libera(pal_txt_1);

    libera(pal_txt_2);	/*libera todas as listas*/

    libera(pont_txt_1);

    libera(pont_txt_2);

    return 0;

}
