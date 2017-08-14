#include"engine.h"
#include"grafico.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

extern int saida;
extern int DINHEIRO;
extern int COMIDA;
extern int FASE;
extern int hp_inim_1,hp_inim_2,hp_inim_3;
extern int CARREGAR;

/** @file */


/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testeiniciaunidade: função que testa se a função que inicia uma unidade está funcionando corretamente\n
 * ao testar se atribuiu corretamente todos os parametros para cada um dos atributos e se retorna um ponteiro para uma\n
 * nova unidade
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 *-varias variaveis do tipo unidade são iniciadas com NULL e logo depois são atribuidos os valores especificos\n\n
 *Interfaces implícitas\n
 * -Inicia a variável global fase como 1
 */
void testiniciaunidade(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testPosicaoMapa: função que testa se a posição do heroi no mapa está correta
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -inicia a janela com os valores de posição do heroi e depois verifica se o heroi foi mostrado no lugar certo\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testPosicaoMapa(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testVel: função que testa se a velocidade de movimento do herói está correta
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -inicia as variaveis de posição inicial, com a posição atual da janela, e depois manda imprimir o herói com\n
 *a posição modificada pelo valor de velocidade e depois testa se está correto\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testVel(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testAngulo: função que testa se o ângulo é modificado corretamente
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -a função pega as posições da janela e chama a função troca_pangular para mudar o ângulo\n
 *-depois testa se a mudança ocorreu corretamente\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testAngulo(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testVelAngular: função que testa se a velocidade angular está sendo aplicada corretamente
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 *-a função pega as posições da janlea e chama a função troc_pangular duas vezes para mudar o ângulo\n
 *-depois verifica se a foi aplicado corretamente\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testVelangular(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testDistMaxTiro: função que testa se a função que calcula se o inimigo está dentro do alcance do herói
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 *-testa se a função retorna um (1) em caso de o inimigo estar dentro do alcance (por ambos os lados)\n
 *-testa se a função retorna zero (0) em caso de o inimigo estar fora do alcance (por ambos os lados)\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testDistMaxTiro(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testVida: função que testa se a função tira_vida_heroi está funcionando corretamente
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -chama a função tira_vida_heroi duas vezes e verifica se os valores de vida do herói foram atualizados corretamente\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testVida(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testDanoPSeg: função que testa se a função tira_vida_ini está funcionando corretamente
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -chama a função tira_vida_ini duas vezes e verifica se os valores de vida do inimigo foram atualizados corretamente\n
 * -testa se o dano lateral aplicado duas vezes é maior que aplicar o dano normal duas vezes\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testDanoPSeg(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testDanoDAngulo: função que testa se a função dano_relativo está funcionando corretamente
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -chama a função dano_relativo e verifica se o valor de dano que essa função retorna é maior que o valor de dano normal\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testDanoDAngulo(void);

/** ******************************************************************************************************************
 * Interfaces explícitas
 * @brief função testVida: função que testa se a função libera_memoria está funcionando corretamente
 *
 * @param void
 *
 * @return void
 *
 * ASSERTIVA DE ENTRADA/HIPÓTESES\n
 *-void\n
 *
 * ASSERTIVA DE SAÍDA\n
 * -chama a função libera_memoria e verifica se está retornando um ponteiro não nulo\n\n
 *Interfaces implícitas\n
 * -Não altera variáveis globais
 */
void testlibera(void);
