#include "reEx.h"

/**
 * Funcao principal
 * @param exp expressao em aritmetica infixa
 */
int main(int argc, char **argv)
{
	float	tempoInicio = 0, tempoFim = 0, tempoGasto;
	char 	exp[100];

	// tempo para o benchmark
	// obtem momento inicial
	tempoInicio = (float)clock()/CLOCKS_PER_SEC;

	// usa argumentos passados na linha de comando ou solicita-os
	if(argc > 2)
	{
		printf("Erro na entrada. Consulte o readme para mais informacoes.\n");
	}
	if(argc == 2 )
	{
		strcpy(exp,argv[1]);
		int len = strlen(argv[1]);
		exp[len] = '\0';
	}else
	{
		printf("Digite a expressao:\n~>");
		scanf("%[^\n]", exp);
		getchar();
	}

	// passa a expressao de infixa para posfixa
	infixa_para_posfixa(exp);

	// avalia a expressao
	avalia_expressao(exp);

	// obtem momento final
	tempoFim = (float)clock()/CLOCKS_PER_SEC; 

	// obtem duracao do programa
	tempoGasto = tempoFim - tempoInicio; 

	// imprimi o tempo gasto pelo programa
	printf("O tempo gasto foi %fs\n", tempoGasto); 
	return 0;

}



/**
 * Funcao para colocar nodos no topo da pilha
 * @param 	num valor numerico a ser colocado na pilha
 * @param 	stack ponteiro para a pilha
 * @param 	caracter caracter a ser colocado na pilha
 */
void push_stack(uint64_t num, struct pilha * stack, char caracter)
{
	// aloca espaco para nodo auxiliar
	struct nodo * aux = (struct nodo *) malloc(sizeof(struct nodo));
	// atribui os valores do nodo inicial com os recebidos como parametros
	aux->num48 		= num;
	aux->caracter	= caracter;
	// indica proximo nodo como o topo da pilha
	aux->prox 		= stack->first;
	// faz nodo auxiliar ocupar todo da pilha
	stack->first 	= aux;
}


/**
 * Funcao que retira um nodo do topo da pilha e o retorna como estrutura dados
 * @param 	stack ponteiro para a pilha
 */
struct dados* pop_stack(struct pilha * stack)
{
	// aloca espaco para estrutura dados 
	struct dados * dado = (struct dados*)malloc(sizeof(struct dados));
	struct nodo * aux = NULL;

	// gerencia o caso de pop em pilha vazia
	if(stack->first == NULL)
	{
		printf("Pilha vazia \n" );
		exit(1);
	}

	// obtem valores do topo da pilha na estrutura de dados
	aux = stack->first;
	dado->num = aux->num48;
	dado->car = aux->caracter;
	// faz o topo ser o proximo elemento
	stack->first = aux->prox;
	// libera o elemento removido
	free(aux);
	// retorna a estrutura dados
	return dado;
}

/**
 * Funcao que retorna a precedencia de um operador
 * @param 	c char representando operador
 */
int precedencia(char c)
{
	if     (c=='*' || c=='/') return 3;
	else if(c=='+' || c=='-') return 2;
	else if(c=='(') 		  return 1;
	return -1;
}

/**
 * Funcao que transforma de infixa para posfixa
 * @param 	exp string da expressao
 */
void infixa_para_posfixa(uint8_t* exp)
{
	// contadores
	int i = 0, j =0;
	// representa a expressao de saida
	char aux[100];
	// representa caractere do topo da pilha
	char topo;

	// inicializa pilha que mantem os operadores
	struct pilha * pilhaConverte = (struct pilha*) malloc(sizeof(struct pilha));
	pilhaConverte->first = NULL; 
	// fim inicializacao

	// le a expressao de entrada da esquerda para a direita
	// ate o fim
	while(exp[i] != '\0')
	{
		// se for um operando, concatena ao final da mensagem
		// de saida
		if(exp[i] >= '0' && exp[i] <= '9')
		{
			aux[j] = exp[i]; j++;
		}
		// se for abre parenteses, da push na pilha de operadores
		else if(exp[i] == '(')
		{
        	push_stack(-1, pilhaConverte, '(');
		}
		// se for fecha parenteses, da pop na pilha de operadores 
		// ate o abre parenteses correspondente ser removido. Concatena 
		// cada operador ao final da mensagem de saida
        else if(exp[i] == ')')
        {
        	topo = pop_stack(pilhaConverte)->car;
        	while(topo != '(')
        	{
        		aux[j] = topo; j++;
        		topo = pop_stack(pilhaConverte)->car;
        	}
        }
        // se for um espaço, apenas pula pro proximo
        else if(exp[i] == ' ');
        // se for *, /, +, ou -, da push na pilha de operadores. 
        // Entretanto, primeiro remove todos os operadores ja na pilha 
        // que tem precedencia maior ou igual e os concatena na mensagem
        // se saida
        else
        {
        	while(pilhaConverte->first != NULL && 
        		  precedencia(pilhaConverte->first->caracter) >= 
        		  precedencia(exp[i]))
        	{
        		aux[j] = pop_stack(pilhaConverte)->car; j++;
        	}
        	push_stack(-1, pilhaConverte, exp[i]); 
        	// gerencia quando separar os operandos na mensagem de saida
        	if(aux[j-1] != ' ' && aux[j-1] != '*' && aux[j-1] != '/' &&
        	   aux[j-1] != '+' && aux[j-1] != '-')
        	{
        		aux[j] = ' '; j++;	
        	}
        }

        i++;
    }

    // apos processar toda a mensagem de saida, qualquer 
    // operador que ainda ficou na pilha deve ser concatenado 
    // ao final da mensagem de saida
    while(pilhaConverte->first != NULL)
    {
    	aux[j] = pop_stack(pilhaConverte)->car; j++;
    }

    // caractere delimitador da mensagem 
    aux[j] = '\0';

	// mostra na tela a posfixa correspondente
	printf("posfixa equivalente %s\n", aux);
	strcpy(exp, aux);
}


/**
 * Funcao que avalia a expressao posfixa e imprime seu resultado
 * @param 	exp string da expressao
 */
void avalia_expressao(uint8_t* exp)
{
	// contadores
	int i = 0, j =0;
	// para armazenar todos os algarismos de 
	// um numero
	char aux[100];
	// resultado final
	uint64_t result = 0;
	// primeiro e segundo operandos das operaçoes
	uint64_t num48 = 0, num48_aux = 0;
	
	// inicializa pilha
	struct pilha * stack = (struct pilha*) malloc(sizeof(struct pilha));
	stack->first = NULL; 
	// fim inicializacao

	// percorre mensagem profixa ate o fim
	while(exp[i] != '\0')
	{
		// se for um espaco vai para a proxima posicao
		if(exp[i] == ' ')
		{
			i++;
			continue;
		}
		// switch que permite analisar os caracteres
		// quando se acha operadores retira dois da pilha de operandos, 
		// faz a operacao e coloca o operando resultante na pilha 
		switch(exp[i])
		{
			// se operador soma
			case '+' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(soma(num48, num48_aux), stack, '\0');
				i++;
				break;
			// se operador subtracao
			case '-' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(subtracao(num48, num48_aux), stack, '\0');
				i++;
				break;
			// se operador multiplicacao
			case '*' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(multiplicacao(num48, num48_aux), stack, '\0');
				i++;
				break;
			// se operador divisao
			case '/' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(divisao(num48, num48_aux), stack, '\0');
				i++;
				break;
			// se operando
			default	:
				// quando acha operandos, obtem todos os seus algarismos 
				// e coloca-o na pilha 
				while((exp[i] != '+')&&(exp[i] != '*')&&(exp[i] != '/')&&
					  (exp[i] != '-')&&(exp[i] != ' ')&&(exp[i] != '\0'))
				{
					aux[j] = exp[i];
					j++;
					i++;
				}
				
				// delimita operando
				aux[j] = '\0';
				// passa para um inteiro 48 bits (implementado com 64)
				num48 = atoll(aux) & 0xffffffffffff;
				j = 0;

				// operando colocado na pilha
				push_stack(num48, stack, '\0');
		}
	}

	// o resultado se encontra na pilha
	result = pop_stack(stack)->num & 0xffffffffffff;
	
	// caso o bit 48 for 1 entao eh um numero negativo, inverte e soma 1
	if( result >> 47)
	{
		result = ((~ result )+ 1)& 0xffffffffffff;
		printf("O resultado eh -%" PRId64 "\n", result);
	}else
		printf("O resultado eh %" PRId64 "\n", result);
}


/**
 * Funcao de calculo subtracao arit 48bits
 * @param 	num valor 48 bits para a operacao
 * @param 	num_aux segundo valor 48 bits para a operacao
 */
uint64_t soma(uint64_t num, uint64_t num_aux)
{
	printf("soma de %" PRId64 " com %" PRId64 " = %" PRId64 "\n", num, num_aux, num + num_aux);
	return (num + num_aux) & 0xffffffffffff;
}


/**
 * Funcao de calculo subtracao arit 48bits
 * @param 	num valor 48 bits para a operacao
 * @param 	num_aux segundo valor 48 bits para a operacao
 */
uint64_t subtracao(uint64_t num, uint64_t num_aux)
{
	printf("subtracao de %" PRId64 " com %" PRId64 " = %" PRId64 "\n", num, num_aux, num - num_aux);
	return (num - num_aux) & 0xffffffffffff;
}


/**
 * Funcao de calculo multiplicacao arit 48bits
 * @param 	num valor 48 bits para a operacao
 * @param 	num_aux segundo valor 48 bits para a operacao
 */
uint64_t multiplicacao(uint64_t num, uint64_t num_aux)
{
	printf("multiplicacao de %" PRId64 " com %" PRId64 " = %" PRId64 "\n", num, num_aux, num * num_aux);
	return (num * num_aux) & 0xffffffffffff;
}


/**
 * Funcao de calculo divisao arit 48bits
 * @param 	num valor 48 bits para a operacao
 * @param 	num_aux segundo valor 48 bits para a operacao
 */
uint64_t divisao(uint64_t num, uint64_t num_aux)
{
	printf("divisao de %" PRId64 " com %" PRId64 " =%" PRId64 "\n", num, num_aux, num / num_aux);
	return (num / num_aux) & 0xffffffffffff;
}