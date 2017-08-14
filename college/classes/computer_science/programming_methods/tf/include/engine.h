#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include<assert.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>


/** @file */


/** **********************************************************************
 * ASSERTIVAS ESTRUTURAIS\n
 *-É utilizado um vetor do tipo ponteiro para a struct Unidade.\n
 *-Cada atributo é acessado como cabeca[posicao].atributo. O int posicao não\n
 *   pode ser menor ou maior que os indices válidos do vetor. Que tem 7 posições;\n
 *-0<=posicao<=6.
 *  **********************************************************************/


struct unidade{      /** posicao em relacao a ponta superior da janela*/
  int y;             /** posicao em relacao a ponta esquerda da janela*/
  int x;             /** fator somado a quanto a unidade se move por turno */
  int velocidade;    /** possiveis direcoes de ataque (2)*/
  int qtd_angulo;    /**posição de ataque atual. Pode ser 1 ou 2 */
  int pangular;      /** qtd de vida da unidade*/
  int vida;          /**o quanto a unidade causa de damage no inimigo */
  int dano;         /**distancia máxima do tiro. */ 
  int dist_tiro;  
}; 

typedef struct unidade Unidade;

/** CONSTANTES*/

#define MOVEX 0
#define MOVEY 1
#define DELAY 23000

/** VARIÁVEIS GLOBAIS*/
                                      /**saida é 0 ou 1*/
int saida;                            /**DINHEIRO>=0*/
int DINHEIRO;                         /**COMIDA>0*/
int COMIDA;                           /**FASE está entre 1 e 9*/
int FASE;                             /**hp_inim>0*/
int hp_inim_1,hp_inim_2,hp_inim_3;    /**CARREGAR é 0 ou 1*/
int CARREGAR;



/** ***********************************************************************
 * Interfaces explícitas
 * @brief função inicia_unidade: inicia uma struct unidade com os seus vários parâmetros
 *
 * @param y inteiro que representa a posição y da unidade
 * @param x inteiro que representa a posição x da unidade
 * @param vel inteiro que indica o quanto a unidade se move na direita ou esquerda
 * @param ang inteiro que representa quantas variações de ângulo a unidade possui
 * @param pang inteiro que representa a posição angular da unidade
 * @param life inteiro que representa a vida da unidade
 * @param damage inteiro que representa quanto dano uma unidade pode causar à outra
 * @param dist_tiro inteiro que indica o range(distancia maxima de tiro) da unidade
 *
 * @return novo: ponteiro para Unidade com atributos inicializados
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 * -y e x devem ser menores ou iguais às máximas dimensões da tela(LINES e COLS, respectivamente) e maiores que 0\n
 * -a vel deve ser maior que zero e menor ou igual ao máximo permitido para cada herói\n
 * -ang tem de ser maior que 0. No nosso jogo,só pode ser 2\n
 * -pang só pode ter os valores 1 ou 2.\n
 * -life deve ser maior ou igual 0(quando a unidade morre) e menor ou igual ao máximo permitido para cada herói\n
 * -damage deve ser maior que 0 e menor ou igual ao máximo permitido para cada herói\n
 * -dist_tiro deve ser maior que zero e menor que o tamanho da janela na direção x\n
 * ASSERTIVAS DE SAIDA\n
 * -inicializa cada atributo da struct com os parâmetros recebidos\n\n
 *
 *Interfaces implícitas\n
 *-Não altera variáveis globais  
 * ***********************************************************************/
Unidade* inicia_unidade(int y,int x,int vel,int ang, int pang,int life,int damage,int dist_tiro);

/** ***********************************************************************
 * Interfaces explícitas
 * @brief função libera_memoria: libera a memória reservada para a struct
 *
 *@param unity ponteiro p/ struct Unidade.
 *
 *@return void
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-unity precisa ter sido inicializa com NULL\n
 *
 *ASSERTIVAS DE SAIDA\n
 *-desaloca memória para a struct\n\n
 * Interfaces implícitas\n
 *-Não altera variáveis globais  
 * ***********************************************************************/
void libera_memoria(Unidade* unity);

/** ***********************************************************************
 *Interfaces explícitas
 * @brief função menu_principal: mostra o menu principal, que possui uma minitela de opções a serem escolhidas\n
 *(novo jogo,carregar jogo e sair) ,a logo do jogo(protetores),os heróis(ninja da montanha, mago e feiticeira)e a instruções do jogo.
 *
 *@param cabeca vetor de struct Unidade(ponteiro),\n
 *sendo que a posição 0 é para a struct ninja das montanhas, a posição 1 é para  struct do mago e\n
 *a posição 2 é para a struct da feiticeira, as posiçoes 3, 4 e 5 para os inimigos 1, 2 e 3,\n
 *respectivamente e a 6 para o boss
 *
 *@return cabeca - vetor de struct ponteiro de unidade
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-cabeca tem de ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA  \n                                                                                                                                            saida,DINHEIRO,COMIDA,FASE,hp_inim,CARREGAR                                                                                                                     
 * -um menu é apresentado para o usuário com opçoes 1. Novo jogo 2. Carregar jogo e 3.Sair.\n
 *-Também são mostrados janelas explicitadas em brief. De acordo com a escolha do usuario variaveis globais são alteradas para dar inicio\n
 * ao jogo\n\n
 * 
 * Interfaces implícitas\n
 *-novo jogo inicializa a variavel global saida com "0" para que possa entrar nas fases da main\n
 * sendo que a opção sair inicializa esta variável com 1, impedindo entrada em qualquer fase do jogo\n
 *-carregar jogo tenta abrir o arquivo texto "saveatual.txt" no modo leitura para carregar parametros\n
 * da estrutura cabeca e das variaveis globais DINHEIRO, COMIDA,FASE,hp_inim_1,hp_inim_2,hp_inim_3 e \n
 * seta a variavel global CARREGAR como 1 se tudo der certo.
 * ***********************************************************************/
Unidade* menu_principal(Unidade* cabeca);


/** ***********************************************************************
 * Interfaces explícitas
 * @brief função game: começa um jogo e antes apresenta uma janela com as características atuais de cada\n
 * herói e escolha para iniciar com algum deles. Mostra as principais características do jogo sendo que o usuário\n
 * pode realizar todas as opções mostradas nas intruções da função menu_principal
 *
 *@param cabeca vetor de struct Unidade(ponteiro),sendo que a posição 0 é para a struct ninja das montanhas,\n
 * a posição 1 é para  struct do mago e a posição 2 é para a struct da feiticeira,as posiçoes 3, 4 e 5 para os\n
 * inimigos 1, 2 e 3,respectivamente e 6 para o boss
 *@return cabeca vetor de struct Unidade atualizado
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-cabeca tem de ser diferente de NULL\n
 *-variaveis globais (saida!=1 e CARREGAR!=1) OU (saida!=1 e CARREGAR==1 e FASE == FASE-1).\n
 *
 *ASSERTIVAS DE SAIDA\n                                                                                                                                             saida,COMIDA,FASE
 *-janelas que mostram HP, COMIDA, DINHEIRO,FASE, herois e inimigos são inicializadas. Se o usuario passar\n
 * de fase, é chamada a função para mostrar os upgrades. Caso contrario, o jogo é encerrado.\n
 *-o jogo é encerrado caso: 1)apertado ESC 2)inimigo chegar ao início da tela 3)hp de qualquer herói que seja\n
 * chegar a 0 4)a comida acabar\n\n
 *Interfaces implícitas\n
 *-saida é iniciado com 1. Caso o usuario aperte ESC ou perca, nada é feito com ela. Caso ele passe da\n
 *fase, saida = 2 e é chamada a função de upgrades.\n
 *-COMIDA é decrementada de 1 unidade periodicamente a cada duas ações do jogador\n
 *-é testado se FASE==10(caso do boss) ou não(caso normal). De acordo com esta informações as várias ações da\n
 * função tomam rumos distintos.
 * ***********************************************************************/
Unidade* game(Unidade* cabeca);



/** ***********************************************************************
 *Interfaces explícitas
 *@brief função cria_cabeca: cria uma posição da cabeca(um vetor de struct) para uma unidade,\n
 * em uma determinada posição
 *
 *@param vet vetor de struct Unidade(ponteiro).
 *@param pos int que indica a posição do vetor a ser alterado(0 para ninja, 1 para mago e 2 para feiticeira).
 *@param uni ponteiro para struct unidade, que será inserida na posição pos de vet
 *
 * @return vet: vetor de struct(cabeça) atualizado(ponteiro)
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-vet tem de ser inicializado com NULL\n
 *-pos só pode ser 0, 1 ou 2(ninja, mago e feiticeira, respectivamente) 3,4,5, ou 6\n
 *-uni tem de ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n
 *-cria uma posição do vetor cabeça para uma determinada unidade uni em determinada posição pos.\n
 *-Atribui a cada atributo de struct da posição pos o atributo de struct da uni\n
 *-Então cabeca sai como um vetor de struct com os atributos de uni para a posição pos\n\n
 *  Interfaces implícitas\n
 *-Não altera variáveis globais  
 * ***********************************************************************/
Unidade* cria_cabeca(Unidade* vet,int pos, Unidade* uni);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função tira_vida_ini: função que verfifaca as posições do herói e do inimigo e atualiza\n
 *a variável da vida do inimigo de acordo com o dano causado pelo herói.\n
 *O dano é maior se for o caso de um ataque lateral
 *
 *@param cabeca vetor de struct Unidade(ponteiro), sendo que a posição 0 é para a struct ninja das montanhas,\n
 *a posição 1 é para  struct do mago, a posição 2 é para a struct da feiticeira, as posiçoes 3, 4 e 5 para os inimigos 1, 2 e 3,\n
 *respectivamente e a 6 para o boss
 *@param x_hero inteiro que representa a posição do herói no eixo x
 *@param x_inimigo inteiro que representa a posição do inimigo no eixo x
 *@param INIM_NA_MIRA inteiro que representa qual dos inimigos o herói está atacando
 *@param unidade inteiro que representa qual tipo de herói que está atacando
 *
 *@return cabeca: vetor de struct atualizado(ponteiro)
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-cabeca deve ser diferente de NULL\n
 *-x_hero tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-x_inimigo tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-INIM_NA_MIRA deve ser maior ou igual a três e menor ou igual a cinco\n
 *-unidade: inteiro que só pode ser igual aos valores 0, 1 e 2(ninja, mago e feiticeira, respectivamente)\n
 *ASSERTIVAS DE SAIDA\n                                                                                                                                              DINHEIRO,FASE
 *-verifica se o range do herói condiz com as distâncias entre as posições relativas no eixo x\n
 *-verifica qual o inimigo que está na mira do herói e quanto será o dano através de funções auxiliares\n
 *-verifica se foi possível realizar o ataque do herói contra o inimigo\n\n
 * Interfaces implícitas\n
 *-é testado se FASE==10(caso do boss) ou não(caso normal). De acordo com esta informações as várias ações da\n
 * função tomam rumos distintos.\n
 *-se o inimigo acabou de morrer, (HP chegou em 0), o jogador recebe uma quantia em dinheiro correspondente a\n
 * 30 unidades somados com a vida do inimigo que sofre o ataque/100
 * ***********************************************************************/
Unidade* tira_vida_ini(Unidade* cabeca,int x_hero,int x_inimigo,int INIM_NA_MIRA, int unidade);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função range_dist_maxima: função que verifica se as posições do herói e do inimigo estão dentro do alcance
 *de ataque
 *
 *@param x_heroi inteiro que representa a posição do herói no eixo x
 *@param x_ini inteiro que representa a posição do inimigo no eixo x
 *@param cabeca vetor das unidades
 * @param unidade inteiro que representa qual o heroi
 *@param ind_range inteiro que representa o indice relativo a qual unidade tera o range testado
 *
 *@return int: retorna 1 se está dentro do alcance ou 0 caso contrário
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-x_heroi tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-x_ini tem de ser maior ou igual a zero e menor que o máximo da janela\n
 * cabeca não pode ser NULL\n
 * unidade vai de 0 a 2\n
 *-ind_range tem de ser maior ou igual a zero e menor ou igual a 5\n
 *ASSERTIVAS DE SAIDA\n                                                                                                                                              FASE
 *-a função teste se unidade == ind_range. Se for, o range é relativo ao herói. Se não, é\n
 *relativo ao inimigo\n
 *-caso o oponente de ind_range esteja no range de ind_range, a função retorna 1. Caso contrário,\n
 *0\n\n
 * Interfaces implícitas\n
 *-é testado se FASE==10(caso do boss) ou não(caso normal). De acordo com esta informações as várias ações da\n
 * função tomam rumos distintos.
 * ***********************************************************************/
int range_dist_maxima(int x_heroi,int x_ini,Unidade* cabeca,int unidade,int ind_range);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função tira_vida_heroi: função que permite os inimigos realizarem um ataque ao heroi
 *
 *@param cabeca vetor de struct Unidade(ponteiro), sendo que a posição 0 é para a struct ninja das montanhas,\n
 *a posição 1 é para  struct do mago, a posição 2 é para a struct da feiticeira, as posiçoes 3, 4 e 5 para os inimigos 1, 2 e 3,\n
 *respectivamente e 6 é o boss
 *@param unidade inteiro que representa qual tipo de herói que está sendo atacado
 *@param x_heroi inteiro que representa a coordenada x do herói
 *@param x_inimigo inteiro que representa a coordenada x do inimigo
 *
 *@return cabeca: vetor de struct atualizado(ponteiro)
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-cabeca deve ser diferente de NULL\n
 *-unidade deve ser um valor maior ou igual a zero e menor ou igual a dois\n
 *-x_heroi tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-x_inimigo tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n                                                                                                                                              FASE
 *-para cada inimigo que ainda possui vida é retirado o valor correspondente ao seu dano\n\n
 * Interfaces implícitas\n
 *-é testado se FASE==10(caso do boss) ou não(caso normal). De acordo com esta informações as várias ações da\n
 * função tomam rumos distintos.
 * ***********************************************************************/
Unidade* tira_vida_heroi(Unidade* cabeca,int unidade,int x_heroi,int x_inimigo);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função dano_relativo: função que calcula o dano adicional causado pelo herói
 *
 *@param cabeca vetor de struct Unidade(ponteiro), sendo que a posição 0 é para a struct ninja das montanhas,\n
 *a posição 1 é para  struct do mago, a posição 2 é para a struct da feiticeira, as posiçoes 3, 4 e 5 para os inimigos 1, 2 e 3,\n
 *respectivamente e 6 é o boss
 *@param unidade inteiro que representa qual tipo de herói que está causando dano
 *
 *@return dano: valor de dano alterado de 0 a 30
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-cabeca deve ser diferente de NULL\n
 *-unidade deve ser um valor maior ou igual a zero e menor ou igual a dois\n
 *ASSERTIVAS DE SAIDA\n
 *-calcula um valor aleatório entre um e trinta, se valor da posição angular do herói for igual a dois\n
 *-adiciona esse valor aleatório ao dano do herói, retorna o valor alterado\n\n
 * Interfaces implícitas\n
 *-Não altera variáveis globais 
 * ***********************************************************************/
int dano_relativo(Unidade* cabeca,int unidade);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função tira_vida_boss : função que calcula a quantidade de dano a ser infligido no chefão
 *
 *@param unidade inteiro que representa qual herói está atacando o chefão
 *@param cabeca vetor de struct Unidade para acessar as informações dos heróis
 *
 *@return dano: retorna o valor de dano atualizado
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-unidade deve ser um inteiro maior ou igual a zero e menor ou igual a dois\n
 *-cabeca deve ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n
 *-verifica qual valor em unidade e atribui novos valores para o dano.Se a unidade estiver com ângulo de\n 
 *ataque em flanco é adicionado mais dano.\n
 *-o boss possui maior resistencia contra o mago, seguido da feit e menor contra o ninja\n\n 
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
int tira_vida_boss(int unidade, Unidade* cabeca);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função tela_upgrades: função que mostra as opções que permitem fazer upgrades nos edifícios.\n
 *Mostra também o valor que cada herói recebe com cada upgrade, além da opção de salvar jogo.
 *
 *@param cabeca vetor de struct Unidade para acessar as informações dos heróis
 *
 *@return cabeca: retorna o ponteiro da cabeça atualizado
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-cabeca deve ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n                                                                                                                                       DINHEIRO,COMIDA,FASE,hp_inim
 *-mostra ao usuário as opções para fazer upgrades nos edifícios e salvar o jogo\n
 *-mostra também o quanto o usuário tem de DINHEIRO e de COMIDA\n
 *-caso o usuário faça alguma compra, o DINHEIRO é diminuído do valor correspondente a compra\n\n
 * 
 * Interfaces implícitas\n
 *- Modifica os valores das variaveis globais COMIDA e DINHEIRO\n
 *- Salva no arquivo texto "saveatual.txt" os dados de cabeca, DINHEIRO, COMIDA, FASE, hp_inim.Se o arquivo\n
 * já existia é recriado e se não existia é criado. 
 * ***********************************************************************/
Unidade* tela_upgrades(Unidade* cabeca);   


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função upgrade_inimigo: função que melhora os atributos dos inimigos
 *
 *@param tipo inteiro que representa qual tipo de upgrade será realizado nos inimigos
 *@param cabeca vetor de struct Unidade para acessar as informações dos inimigos
 *
 *@return cabeca: retorna o ponteiro da cabeça atualizado
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-tipo deve ser um inteiro maior ou igual a um e menor ou igual a cinco\n
 *-cabeca deve ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n
 *-verifica qual valor em tipo e atribui novos valores para variados atributos dos inimigos\n\n
 * Interfaces implícitas\n
 *- Não altera variáveis globais
 * ***********************************************************************/
Unidade* upgrade_inimigo(Unidade*cabeca, int tipo);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função ajuste_hp_inim: função que atualiza os valores de vida dos inimigos
 *
 *@param tipo inteiro que representa qual tipo de modificação será realizada
 *@param cabeca vetor de struct Unidade para acessar as informações dos inimigos
 * 
 *@return cabeca: retorna o ponteiro da cabeça atualizado
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-tipo deve ser um inteiro igual a um ou a dois\n
 *-cabeca de ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n                                                                                                                                           hp_inim
 *-Se o tipo for igual a 1 então a função atualiza os valores das variaveis globais do hp dos inimigos\n
 *-se tipo for igual a 2 então a função atualiza apenas as estruturas\n\n
 * Interfaces implícitas\n
 *-Atualiza os valores das variaveis globais hp_inim_1, hp_inim_2, hp_inim_3 caso a variável tipo esteja com valor 1
 * ***********************************************************************/
Unidade* ajuste_hp_inim(Unidade* cabeca, int tipo);