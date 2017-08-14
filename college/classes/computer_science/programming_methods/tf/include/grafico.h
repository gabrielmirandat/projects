

/** @file */

/** ***********************************************************************
 *  Interfaces explícitas
 *@brief função printa_nome: imprime em uma janela a logo do jogo:"Protetores"
 *
 *@param local_win ponteiro para janela local
 *@param yrel inteiro que representa a posição relativa de y na janela
 *@param xrel inteiro que representa a posição relativa de x na janela
 *
 *@return VOID
 *
 *  ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 * -local_win precisa ser diferente de NULL\n
 * -yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 * -xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *  ASSERTIVAS DE SAIDA\n
 * -Imprime a logo do jogo na janela relativa linha por linha, ou seja, incrementando o yrel\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * 
 *  Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void printa_nome(WINDOW *local_win,int yrel,int xrel);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função printa_casas: imprime em uma janela as casas dos personagens,\n
 * as quais servirão posteriormente para upgrade no level dos heróis. Printa também as variaveis globais\n
 * COMIDA E DINHEIRO para dar suporte a escolha do usuario no upgrade dos herois.
 *
 *@param local_win ponteiro para janela local
 *
 *@return VOID
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 * -local_win precisa ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n
 * -imprime as casas na janela relativa linha por linha, ou seja, incrementando o yrel.\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada.\n
 * -também imprime os ganhos de vel, hp, dano e range relativo ao personagem de cada casa.\n\n
 * 
 * Interfaces implícitas\n
 * -Imprime na tela os valores atuais das variáveis globais COMIDA e DINHEIRO
 * ***********************************************************************/
void printa_casas(WINDOW *local_win);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função mostra_heroi: mostra o heroi, quando chamada por alguma função.
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *@param tipo inteiro que representa o tipo do herói
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-tipo só pode ser 0, 1 ou 2, referente ao ninja\n
 * das montanhas, ao mago e à feiticeira, respectivamente\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime os heróis na janela relativa linha por linha, ou seja, incrementando o yrel\n
 * de acordo com o tipo\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void mostra_heroi(WINDOW *local_tela, int yrel, int xrel, int tipo);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função apaga_personagem: apaga o personagem, quando chamada por alguma função
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime espaços na janela relativa linha por linha, ou seja, incrementando o yrel,\n
 * apagando assim o que estiver na tela\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void apaga_personagem(WINDOW *local_tela,int yrel,int xrel);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função apaga_inimigo: apaga os inimigos, quando chamada por alguma função
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime espaços na janela relativa linha por linha, ou seja, incrementando o yrel,\n
 * apagando assim o que estiver na tela\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void apaga_inimigo(WINDOW *local_tela,int yrel,int xrel);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função apaga_boss: apaga o boss
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime espaços na janela relativa linha por linha, ou seja, incrementando o yrel,\n
 * apagando assim o que estiver na tela\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void apaga_boss(WINDOW *local_tela,int yrel,int xrel);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função apaga_janela: apaga a janela local
 *
 *@param local_win ponteiro para janela local
 *
 *@return VOID
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 * -local_win precisa ser diferente de NULL\n
 *
 *ASSERTIVAS DE SAIDA\n
 * -enche a janela de espaços com werase, apaga a borda da janela com espaços ' '\n
 * -atualiza a janela (printa os espaços) com o wrefresh\n
 * -desaloca a memória associada com a estrutura de janela.\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void apaga_janela(WINDOW *local_win);



/** ***********************************************************************
 * Interfaces explícitas
 *@brief função mostra_inimigo: mostra os inimigos, quando chamada por alguma função
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime os inimigos na janela relativa linha por linha, ou seja, incrementando o yrel\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void mostra_inimigo(WINDOW *local_tela, int yrel, int xrel);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função printa_instrucoes: mostra as intruções do jogo, quando chamada por alguma outra função
 *
 *@param local_win ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_win deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime as instruções relativas às regras a serem utilizadas no jogo\n
 * na janela relativa linha por linha, ou seja, incrementando o yrel\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void printa_instrucoes(WINDOW *local_win,int yrel,int xrel);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função printa_status: mostra o status de cada personagem do jogo, quando chamada por alguma outra função
 *
 *@param local_win ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *@param cabeca vetor de struct Unidade(ponteiro)
 *@param unidade inteiro que representa qual tipo de herói
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_win deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-cabeca deve ser diferente de NULL\n
 *-unidade deve ser um valor maior ou igual a zero e menor ou igual a dois\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime OS STATUS relativos a cada herói a ser utilizado no jogo\n
 * na janela relativa linha por linha, ou seja, incrementando o yrel\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void printa_status(WINDOW *local_win,int yrel,int xrel,Unidade* cabeca, int unidade);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função printa_boss: mostra o boss na tela, quando chamada por alguma função, na última fase
 *
 *@param local_tela ponteiro p/ janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime o boss na janela relativa linha por linha, e quando ele se move, muda o xrel\n\n
 * Interfaces implícitas\n
 * -Cria uma variável yrel local, que depende da constante LINES de cada computador
 * ***********************************************************************/
void printa_boss(WINDOW *local_win, int xrel);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função printa_tiro: mostra o tiro de cada herói do jogo, quando chamada por alguma outra função
 *
 *@param local_win ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *@param cabeca vetor de struct Unidade(ponteiro)
 *@param unidade inteiro que representa qual tipo de herói
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_win deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-cabeca deve ser diferente de NULL\n
 *-unidade deve ser um valor maior ou igual a zero e menor ou igual a dois\n
 *ASSERTIVAS DE SAIDA\n
 * -imprime o range do tiro de cada herói a ser utilizado no jogo\n
 * na janela relativa linha por linha, ou seja, incrementando o xrel\n\n
 * Interfaces implícitas\n
 * -Verifica a constante COLS de cada computador para não permitir que o range\n
 * saia do campo de visão do jogador ou apareça do outro lado da tela
 * ***********************************************************************/
void printa_tiro(WINDOW* local_win,int yrel, int xrel, Unidade* cabeca,int unidade);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função mostra_pangular: printa um caracter 'o' na direção do o ângulo\n
 * que o personagem está apontando, ou seja, mostra a posição do ângulo
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *@param fator inteiro que representa quantos espaços o caracter estará distante do herói\n
 *@param coordenada inteiro que representa para qual coordenada o "o"
 * está (x para MOVEX(0)) ou y para MOVEY(1))
 *
 *@return VOID
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-fator assume qualquer vaor inteiro\n
 *-coordenada só pode ser 0 ou 1(MOVEX ou MOVEY, respectivamente)\n
 *ASSERTIVAS DE SAIDA\n
 * -printa o "o" em uma posiçao relativa ao herói, com uma distância dependente\n
 * de "fator" espaços indicando para onde o herói aponta(seu ângulo),\n
 * podendo ser na direção x ou y dependendo de "coordenada"\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void mostra_pangular(WINDOW*local_tela,int yrel,int xrel,int fator,int coordenada);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função troca_pangular: muda a direção do caracter 'o' para uma nova direção do ângulo\n
 * que o personagem aponta
 *
 *@param local_tela ponteiro p/ janela
 *@param yrel inteiro que representa a posição y relativa à janela
 *@param xrel inteiro que representa a posição x relativa à janela
 *@param cabeca vetor de struct Unidade(ponteiro),sendo que a posição 0 é para a struct\n
 * ninja das montanhas, a posição 1 é para  struct do mago e a posição 2 é para a struct da feiticeira
 *@param unidade inteiro que representa qual o tipo de herói cuja posição angular será trocada.
 *
 *@return cabeca: vetor de struct atualizado(ponteiro)
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-yrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-xrel tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-cabeca deve ser diferente de NULL\n
 *-unidade: inteiro que só pode ser igual aos valores 0, 1 e 2(ninja, mago e feiticeira, respectivamente)\n
 *ASSERTIVAS DE SAIDA\n
 * -muda a posição do caracter "o" do herói do vetor "cabeca" na posição "unidade",\n
 * indicando que o ânglo do herói mudou\n
 * -Se pangular era 1, vai para 2; se era 2, vai para 1.\n
 * -Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
Unidade* troca_pangular(WINDOW *local_tela,int yrel,int xrel,Unidade* cabeca,int unidade);


/** ******************************************************************************************
 * Interfaces explícitas
 *@brief função mostra_HP: imprime na tela a informação de vida do herói e dos inimigos, assim como\n
 * quantidade de dinheiro, comida e a fase atual
 *
 *@param local_tela ponteiro para janela
 *@param cabeca vetor de struct Unidade(ponteiro), sendo que a posição 0 é para a struct ninja das montanhas,\n
 *a posição 1 é para  struct do mago, a posição 2 é para a struct da feiticeira, as posiçoes 3, 4 e 5 para os inimigos 1, 2 e 3,\n
 *respectivamente
 *@param unidade inteiro que representa qual o tipo de herói cuja vida será mostrada na tela
 *
 *@return void
 *
 *ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-local_tela deve ser diferente de NULL\n
 *-cabeca deve ser diferente de NULL\n
 *-unidade: inteiro que só pode ser igual aos valores 0, 1 e 2(ninja, mago e feiticeira, respectivamente)\n
 *ASSERTIVAS DE SAIDA\n
 *-imprime na janela a informação sobre a vida da unidade e também de mais três inimigos, a quantidade de comida e dinheiro\n
 *-Depois, atualiza a tela com um wrefresh de local_tela para que a mudança seja visualizada\n
 *-Se estiver na fase 10 (boss) mostra o hp do boss\n\n
 * Interfaces implícitas\n
 * -Mostra o valor das variáveis globais DINHEIRO, COMIDA, FASE e utiliza a variável COLS  de cada computador para ver o local de impressão
 ****************************************************************************************** */
void  mostra_HP(WINDOW *local_tela,Unidade*cabeca,int unidade);

/** ***********************************************************************
 * Interfaces explícitas
 *@brief função cria_menu: cria um menu nas quais o usuário pode escolher uma opção de jogo
 *
 *@param Colunas inteiro que representa a quantidade de colunas a ser mandada para a função newwin
 *@param Linhas inteiro que representa a quantidade de linhas a ser mandada para a função newwin
 *@param y_inicial inteiro que representa o y_inicial a ser mandado para a função newwin
 *@param x_inicial inteiro que representa o x_inicial a ser mandado para a função newwin
 *@param choices ponteiro de ponteiro de char a ser mandado para a função printa_menu
 *@param qtd_opcoes inteiro que representa a quantidade de opções do menu
 * 
 *@return int choice que representa a escolha do usuário
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 *-Colunas tem de ser maior quw zero e menor que o máximo da janela\n
 *-Linhas tem de ser maior que zero e menor que o máximo da janela\n
 *-y_inicial tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-x_inicial tem de ser maior ou igual a zero e menor que o máximo da janela\n
 *-choices não pode ser NULL\n
 *-qtd_opçoes tem de ser maior que 0 e do tamanho certo do número de opções\n
 *
 *ASSERTIVAS DE SAIDA\n
 * -cria um menu, chama a função printa_menu, move o highlight de acordo com as opções e\n
 * se o usuário usar uma tecla inválida, avisa-o\n
 * -retorna choice que representa a escolha do usuário\n\n
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
int cria_menu(int Colunas, int Linhas, int y_inicial, int x_inicial, char** choices,int qtd_opcoes);


/** ***********************************************************************
 * Interfaces explícitas
 *@brief função print_menu: mostra um contorno(pela função box) nas dimensões da janela\n
 * nas quais o usuário pode escolher uma opção de jogo
 *
 *@param menu_win ponteiro p/ janela
 *@param highlight inteiro que representa qual opção está em destaque
 *@param choices ponteiro de ponteiro de char vindo como parâmetro da função cria_menu
 *@param n_choices inteiro que representa a quantidade de opções do menu vindo como parâmetro da função cria_menu
 *
 * @return VOID
 *
 * ASSERTIVAS DE ENTRADA/HIPÓTESES\n
 * -menu_win precisa ter sido inicializa com NULL\n
 * -highlight foi inicializado com 1 na função menu\n
 * -choices não pode ser NULL\n
 * -n_choices tem de ser maior que 0 e do tamanho certo do número de opções\n
 *
 *ASSERTIVAS DE SAIDA\n
 * -muda o highlight de acordo com as entradas do usuário no teclado e atualiza com o refresh\n\n
 *
 * Interfaces implícitas\n
 * -Não altera variáveis globais
 * ***********************************************************************/
void print_menu(WINDOW *menu_win, int highlight,char** choices,int n_choices);

