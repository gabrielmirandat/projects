#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _PROJETO1MP_H_
#define _PROJETO1MP_H_

/*para limpar a tela do terminal*/
#ifdef _WIN32
    #define CLEAR "cls" /* soh funciona no windows */
#else
    #define CLEAR "clear" /* soh funciona no linux ou mac (unix) */
#endif


/******************************************************************************
 * ASSERTIVAS ESTRUTURAIS DA LISTA DUPLAMENTE ENCADEADA:
 * - pLista->pAnt==NULL => pLista==pOrigem;
 * - pLista->pAnt->pProx==pLista => pLista!=pOrigem;
 * - pLista->pProx==NULL => pLista==pUltimoElem;
 * - pLista->pProx->pAnt==pLista => pLista!= pUltimoElem;
 * - pLista->pAnt->pProx==pLista->pProx->pAnt => pLista!= pOrigem && pLista!= pUltimoElem;
 * - pLista==NULL => Não há elementos na lista;
 * - pLista->pOrigem == NULL => tam_atual==0
*******************************************************************************/
struct lista{
    char palavra[15];
    int ocorrencias;
    struct lista* ant;
    struct lista* prox;
};
typedef struct lista Lista;
Lista** vet;
extern int mudanca_lista;
extern int tamanho_atual;

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função vazia: verifica se pLista é NULO, ou seja, se não há elementos na lista
 *
 *PARÂMETROS:
 * l = ponteiro para inicio da lista
 *
 *RETORNO:
 * booleano = 1(verdade== lista vazia) 0(falso== lista possui elementos)
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com Lista* l ==NULL p/ corretude da função.
 *
 *ASSERTIVAS DE SAIDA
 * se pLista==NULL a lista está vazia,
 * senão conterá elementos.   
 * ***********************************************************************/
int vazia (Lista* l);		

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função cria: inicializa um nó com uma palavra do texto ou digitada pelo usuário
 *
 *PARÂMETROS:
 * pal = string associada que representa pLista->palavra de cada nó.
 *
 *RETORNO:
 * p = pLista recém-criado,que irá representar um nó na lista. como ainda não foi 
 * associado à lista corrente, possui os ponteiros de anterior e proximo nulos e 
 * n_de_ocorrencias iguais a zero.
 * 
 *ASSERTIVAS DE ENTRADA
 * pal precisa possuir o ultimo caractere NULO--\0-- e possuir no máximo 14 letras,
 * pois o tamanho da palavra foi definido com 15 posições.
 *
 *ASSERTIVAS DE SAIDA
 * pLista->palavra será pal
 * pLista-> ocorrencias será ZERO
 * pLista-> pAnt e pLista-> pProximo são NULOS;
 * ***********************************************************************/			
Lista* cria (char* pal);	

/* função insere_ordenado: insere elemento em ordem */
/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função insere_ordenado: insere elemento na lista corrente na ordem lexicografica
 * crescente do ASCII, sendo que letras maiúsculas são menores lexicograficamente
 * do que as minúsculas
 *
 *PARÂMETROS:
 * -l = ponteiro que representa o início da lista.
 * -pal = string associada que representa pLista->palavra de cada nó. Gerada a partir
 * do arquivo texto ou inserção do usuário.
 * -tam_atual = variavel global que representa o tamanho atual de elementos na lista
 * 
 * RETORNO:
 * l = ponteiro que representa o inicio da atualizado, sendo que a atualização só
 * se faz necessária se o elemento for inserido na lista vazia ou for o novo
 * primeiro elemento da lista.
 * 
 *ASSERTIVAS DE ENTRADA
 * -l precisa ter sido inicializada com NULL e pal ter o ultimo elemento NULO e ser
 * menor ou igual a 14.
 * -tam_atual>= 0
 * -pLista->pOrigem == NULL => tam_atual==0
 *
 * ASSERTIVAS DE SAIDA
 * se lista era vazia
 * 	pLista->pOrigem é o novo elemento
 * se novo elemento for menor que o primeiro
 * 	novo elemento é a pOrigem
 * 	antiga_origem->pAnt = novo elemento
 * 	nova_origem->pProx = antiga_origem
 * se novo elemento for maior que o ultimo
 * 	novo elemento é o pUltimoElem
 * 	antigo_ultimo->pProx = novo_ultimo
 * 	novo_ultimo->pAnt = antigo_ultimo
 * se novo elemento já existir
 * 	n_ocorrencias do elemento é incrementado
 * se novo elemento menor que algum elemento do meio
 * 	novo elemento inserido no meio
 * Em todos os casos o pLista->ocorrencias recebe 1 e o numero de elementos na lista
 * é incrementado, menos quando o elemento ja existia.
 * ***********************************************************************/			
Lista* insere_ordenado (Lista* l, char* pal);

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função libera: libera a memória alocada pela lista duplamente encadeada.
 *
 *PARÂMETROS:
 * l= referencia para primeiro nó da lista
 *
 *RETORNO:
 * void
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 *
 *ASSERTIVAS DE SAIDA
 * referencia de lista p recebe a lista atual para percorre-la até o ultimo
 * elemento sem mudar o ponteiro de inicio da lista, liberando a memoria
 * de cada elemento
 * ***********************************************************************/		
void libera (Lista* l);	

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função construcao_lista: percorre o arquivo texto de onde as palavras estão
 * sendo tiradas, armazena-as numa string e manda para a criação de nós ordenados.
 *
 *PARÂMETROS:
 * l= referencia para primeiro nó da lista
 * fp= ponteiro para o arquivo texto
 * 
 *RETORNO:
 * l= lista criada com as palavras extraidas do texto
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 * fp precisa ser diferente de NULL
 *
 *ASSERTIVAS DE SAIDA
 * enquanto não se chegou ao final do arquivo
 * 	se o caractere constituir palavra
 * 		enquanto o caractere é valido
 * 			string sendo criada
 *		fim da palavra recebe NULO
 * 		criação dos nos com a palavra recem extraida
 * arquivo é fechado
 * ***********************************************************************/				
Lista* construcao_lista(Lista* l, FILE* fp);


/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função imprime: mostra todos os elementos presentes na lista.
 *
 *PARÂMETROS:
 * l= referencia para primeiro nó da lista
 * tam_atual = var global que representa o tamanho atual da lista
 * 
 *RETORNO:
 * void
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 * tam_atual>= 0
 *
 *ASSERTIVAS DE SAIDA
 * ponteiro p percorre a lista l enquanto não é NULO e imprime a palavra, quantas 
 * vezes ela ocorre e o tamanho atual da lista
 * ***********************************************************************/		
void imprime(Lista* l);

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função inserir_elemento: O usuário insere a palavra que ele quer que contenha na
 * lista, além das tiradas do arquivo texto.
 *
 *PARÂMETROS:
 * l= referencia para primeiro nó da lista
 * mudanca_lista = variavel global que indica se a lista foi alterada ou não. Usada
 *para auxiliar o vetor de pesquisa binária. 
 * 
 *RETORNO:
 * l = inicio de arquivo atualizado
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 * mudança_lista==1(se houver remoção ou inserção) || mudanca_lista==0
 *
 *ASSERTIVAS DE SAIDA
 * palavra é lida do teclado e enviada para a inserção ordenada na lista
 * mudança_lista=TRUE
 * ***********************************************************************/
Lista* inserir_elemento(Lista* l,char* elemento);	

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função retirar_elemento: O usuário insere a palavra que ele quer remover da lista
 * atual. Ela retira também todas as ocorrencias do elemento.
 *
 *PARÂMETROS:
 * l= referencia para primeiro nó da lista
 * mudanca_lista = variavel global que indica se a lista foi alterada ou não. Usada
 *para auxiliar o vetor de pesquisa binária. 
 * tamanho_atual = numero de elementos atualmente na lista
 * 
 *RETORNO:
 * l = inicio de arquivo atualizado
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 * mudança_lista==1(se houver remoção ou inserção) || mudanca_lista==0
 * tamanho_atual>=0
 *
 *ASSERTIVAS DE SAIDA
 * se só há um elemento na lista
 * 	elemento é retirado
 * 	l vira nula
 * se elemento esta no inicio
 * 	novo_inicio = pLista->pOrigem->pProximo
 * se elemento não existe na lista
 * 	nada feito
 * se elemento é o último
 * 	pLista->pUltimoElem->pAnt->pProximo= NULL;
 * se elemento estiver no meio
 * 	pLista->pAnt->pProx = pLista->pProx
 * Em todos os casos tamanho_atual do numero de elementos é diminuido de uma
 * unidade e flag de mudança na lista é acionada, a menos que a palavra não 
 * exista na lista.
 * ***********************************************************************/
Lista* retirar_elemento(Lista* l, char* pal);					

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função buscar_elemento: O usuário insere a palavra que ele deseja procurar
 * e é feita uma busca binária para ver se o elemento pesquisado existe. É retorna-
 * do o numero de ocorrências.
 *
 *PARÂMETROS:
 * -l= referencia para primeiro nó da lista
 * -mudanca_lista = variavel global que indica se a lista foi alterada ou não. Usada
 *para auxiliar o vetor de pesquisa binária. 
 * -tamanho_atual = indica o tamanho atual da lista.
 *RETORNO:
 * n_ocorre = numero de vezes que a palavra pesquisada ocorre. É ZERO caso a 
 * palavra pesquisada não existir.
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 * mudança_lista==1(se houver remoção ou inserção) || mudanca_lista==0
 * tamanho_atual>=0
 *
 *ASSERTIVAS DE SAIDA
 * caso tenha havido mudança na lista
 * 	se o vetor não for nulo, ele é liberado
 * 	vetor é criado com a lista atualizada
 * usuario insere a palavra de busca
 * a busca binaria é feita e é retornado o numero de ocorrencias da palavra
 * 
 * ***********************************************************************/
int buscar_elemento(Lista* l,char* valor);		

/*************************************************************************
 *ESPECIFICAÇÃO DA FUNÇÃO: 
 * função tela: Um menu é apresentado ao usuário em que ele pode escolher o que
 * fazer com a lista.
 *
 *PARÂMETROS:
 * l= referencia para primeiro nó da lista
 * 
 *RETORNO:
 * void
 * 
 *ASSERTIVAS DE ENTRADA
 * l precisa ter sido inicializa com NULL
 *
 *ASSERTIVAS DE SAIDA
 * A escolha do usuario é armazenada na variavel resp. Caso o usuário inserir ZERO,
 * o programa é desligado
 * ***********************************************************************/
void tela(Lista* l);

#endif //_PROJETO1MP_H_