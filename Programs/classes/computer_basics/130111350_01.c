/*Universidade de Brasilia
  Instituto de Ciencias Exatas
  Departamento de Ciencia da Computacao
  Computacao Basica – 02/2013
  Aluno(a): Gabriel Martins de Miranda
  Matricula: 130111350
  Turma: E
  Versão do compilador:gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
  Descricao:O programa em questao tem por objetivo solicitar ao usuario informacoes sobre novos cadastros de 
  livros para uma biblioteca.Sao solicitados o titulo,o(s) autor(es),a editora,a edicao,o ano de publicaçao,
  o ISBN,o custo do livro para a biblioteca e a categoria de emprestimo do livro.E tem por saida o numero de
   livros cadastrados,o custo acumulado de todos os livros cadastrados,o titulo e o custo dos livros mais 
   caro e mais barato e o percentual de livros cadastrados em cada categoria.*/

/*Aqui serao declaradas as bibliotecas usadas no programa.*/
#include<stdio.h>
#include<string.h>
int main () {  /*Inicio da funcao "main"*/
/*Aqui sao declaradas as variaveis*/
    char titulo[31];             
    char autor[51];
    char editora[21];
    char ISBN[14];
    /*"titulo_caro"sera usada para guardar o titulo do livro mais caro*/
    char titulo_caro[31]; 
    /*"titulo_brto"sera usada para guardar o titulo do livro mais barato*/
    char titulo_brto[31]; 
    /*"resp" sera usada como condicao para cadastro de novos livros ou nao*/
    char resp; 
    /*"i,k,w,z"sao contadores."i" foi usada para a quantidade de livros.
      "k,w,z"foram usadas para categoria de emprestimo*/
    int  edicao,ano_public,categ_emp,i,k,w,z;
    /*"mais_caro,mais_barato"sao variaveis para guardar o livro mais caro e 
       o mais barato, respectivamente."soma"eh o somatorio do custo para a 
       biblioteca."perc" eh o calculo para mostrar a percentagem de cada 
       categoria.*/
    float custo_bibli,mais_caro,mais_brto,soma,perc1,perc2,perc3;

    resp='s';/*"resp"recebe um sim(s) para que o programa possa ser inicializado no "while"*/
    i=0;
    k=0;   /*As variaveis sao inicializadas para evitar lixo de memoria*/
    w=0;   /*"mais_caro,mais brto"recebem valores com o objetivo de o primeiro custo as receber*/
    z=0;
    soma=0;
    mais_caro=0;  
    mais_brto=9999;
    while(resp=='s' || resp=='S'){
        printf("Informe o titulo do livro: \n");           /*"%[^\n]s"eh para ler a string com espacos*/
        scanf("%[^\n]s",titulo);
        getchar();
        printf("Informe o(s) autor(es) do livro: \n");
        scanf("%[^\n]s",autor);
        getchar();
        printf("Informe a editora: \n");
        scanf("%[^\n]s",editora);
        getchar();
        printf("Informe a edicao do livro: \n");
        scanf("%d",&edicao);
        getchar();
        while(edicao<0){
            printf("ERRO!Informe uma edicao valida: \n"); /*"while"sao para corrigir entradas invalidas*/
            scanf("%d",&edicao);
            getchar();
        }
        printf("Informe o ano de publicao do livro: \n");
        scanf("%d",&ano_public);
        getchar();
        while(ano_public<0 || ano_public>2013){
            printf("ERRO!Informe um ano de publicacao valido: \n");
            scanf("%d",&ano_public);
            getchar();
        }
        printf("Informe o ISBN do livro: \n");
        scanf("%[^\n]s",ISBN);
        getchar();
        printf("Informe o custo do livro para a biblioteca: \n");
        scanf("%f",&custo_bibli);
        getchar();
        while(custo_bibli<0){
            printf("ERRO!Informe o custo do livro novamente: \n");
            scanf("%f",&custo_bibli);
            getchar();
        }
        printf("Informe a categoria de empréstimo do livro: \n");
        scanf("%d",&categ_emp);
        getchar();
        while(categ_emp!=1 && categ_emp!=2 && categ_emp!=3){
            printf("ERRO!Informe uma categoria valida: \n");
            scanf("%d",&categ_emp);
            getchar();
        }

        i=i+1; /*O contador eh adicionado a cada novo cadastro*/
        soma=soma + custo_bibli;
        if(custo_bibli>mais_caro){   /*"if"foram condicionais usadas para atribuir os custos*/
            mais_caro=custo_bibli;
            strcpy(titulo_caro,titulo);
        }
        if(custo_bibli<mais_brto){
            mais_brto=custo_bibli;
            strcpy(titulo_brto,titulo);
        }
        if(categ_emp==1){
            k=k+1;
        }
        else                       /*Os contadores aumentam de "1" para categorias especificas */
            if(categ_emp==2){
                w=w+1;
            }
            else
                if(categ_emp==3){
                    z=z+1;
                }

        printf("DESEJA INCLUIR MAIS LIVROS NO CADASTRO? (S/N) \n"); /*Pergunta para cadastrar novamente*/
        scanf("%c",&resp);
        getchar();
        while(resp!='s' && resp!='S' && resp!='n' && resp!='N'){
            printf("ERRO!Informe uma resposta valida: \n");
            scanf("%c",&resp);
            getchar();
        }
    }
    perc1=((float)k/i)*100;  /*Calculo para a percentagem de cada categoria de emprestimo*/
    perc2=((float)w/i)*100;
    perc3=((float)z/i)*100;
    printf("Foram cadastrados %d livros. \n",i);
    printf("O custo total acumulado eh de %.2f. \n",soma);
    printf("O livro mais caro eh chamado:%s e custa %.2f. \n",titulo_caro,mais_caro);    
    printf("O livro mais barato eh chamado:%s e custa %.2f. \n",titulo_brto,mais_brto);
    printf("O percentual da categoria 1 foi de %.2f%%. \n",perc1);
    printf("O percentual da categoria 2 foi de %.2f%%. \n",perc2); /*Sao apresentados os dados de saida*/
    printf("O percentual da categoria 3 foi de %.2f%%. \n",perc3);
    
    getchar();
    return 0; /*"return 0"eh o retorno de um inteiro para a finalizacao da funcao "main"*/
}



