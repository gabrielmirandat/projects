
#include "reEx.h"

/**
 * @param exp expressao em aritmetica infixa
 */
int main(int argc, char **argv){
	float	tempoInicio = 0, tempoFim = 0, tempoGasto;
	char exp[100];

	// tempo para o bench
	tempoInicio = (float)clock()/CLOCKS_PER_SEC;//Pega o momento inicial

	//Argumentos - se foram passado como parametro na execucao, utiliza-se dos mesmos
	if(argc > 2){
		printf("Erro na entrada. Consulte o readme para mais informacoes.\n");
	}
	if(argc == 2 ){
		strcpy(exp,argv[1]);
		int len = strlen(argv[1]);
		exp[len] = '\0';
	}else{
		printf("Digite a expressao:\n~>");
		scanf("%[^\n]", exp);
		getchar();
	}
		// printf("%s\n", exp);
		// printf("%d\n", argc);

	// in_to_pos_fixed(exp);

	avalEx(exp);

	tempoFim = (float)clock()/CLOCKS_PER_SEC; //Pega o tempo em que acabou 

	tempoGasto = tempoFim - tempoInicio; // Pega o tempo da duracao do programa

	printf("O tempo gasto foi %fs\n", tempoGasto); // Imprime o tempo gasto
	return 0;

}

void push_stack(uint64_t num, struct pilha * stack, char caracter){
	struct nodo * aux = (struct nodo *) malloc(sizeof(struct nodo));
	aux->num48 		= num;
	aux->caracter	= caracter;
	aux->prox 		= stack->first;
	stack->first 	= aux;
}

struct dados* pop_stack(struct pilha * stack){
	struct dados * dado = (struct dados*)malloc(sizeof(struct dados));
	struct nodo * aux = NULL;

	if(stack->first == NULL){
		printf("Pilha vazia \n" );
		exit(1);
	}

	aux = stack->first;
	dado->num = aux->num48;
	dado->car = aux->caracter 	;
	stack->first = aux->prox;
	
	free(aux);

	return dado;
}

void in_to_pos_fixed(uint8_t* exp){
	int c_parentes = 0;
	int i = 0, j =0;
	char aux[100];
	
	//Inicializa pilha
	struct pilha * pilhaConverte = (struct pilha*) malloc(sizeof(struct pilha));
	pilhaConverte->first = NULL; 
	//Fim inicializacao

	while(exp[i] != '\0'){
		//se achar o parenteses abrindo coloca ele na pilha
		if(exp[i] == '('){
			push_stack(-1, pilhaConverte,'(');
			i++;
			continue;
		}
		// se achar o fechando vai tirando tudo da pilha
		if(exp[i] == ')'){
			while(1){ //laco para retirar da pilha quando acha parentesis fechando
				aux[j] = pop_stack(pilhaConverte)->car;
				if(aux[j] != '(')
					j++;
				else {
					aux[j] = '\0';
					break;
				}
			}
			i++;
			continue;
		}
		switch(exp[i]){
			case '+' :
				push_stack(-1, pilhaConverte, '+');
				i++;
				break;
			case '-' :
				push_stack(-1, pilhaConverte, '-');
				i++;
				break;
			case '*' :
				push_stack(-1, pilhaConverte, '*');
				i++;
				break;
			case '/' :
				push_stack(-1, pilhaConverte, '/');
				i++;
				break;
			case ' ' :
				aux[j] = exp[i];
				j++;
				i++;
				break;
			default	:
				// Se for um numero pega a parte da string equivalente a ele
				while((exp[i] != '+')&&(exp[i] != '*')&&(exp[i] != '/')&&(exp[i] != '(')&&(exp[i] != ')')&&(exp[i] != '\0')&&(exp[i] != ' ')){
					aux[j] = exp[i];
					aux[j + 1] = ' ';
					j += 2;
					i++;
				}

		}
	}
				aux[j] = '\0';
				printf("%s\n", aux);
				strcpy(exp, aux);


}



void avalEx(uint8_t* exp){
	int i = 0;
	int j = 0;
	char aux[100];
	uint64_t result = 0;
	uint64_t num48 = 0;
	uint64_t num48_aux = 0;
	//Inicializa pilha
	struct pilha * stack = (struct pilha*) malloc(sizeof(struct pilha));
	stack->first = NULL; 
	//Fim inicializacao
	while(exp[i] != '\0'){
		//se for um espaco vai para a proxima posicao
		if((exp[i] == '(')||(exp[i] == ')')||(exp[i] == ' ')){
			i++;
			continue;
		}
		switch(exp[i]){
			case '+' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(soma(num48, num48_aux), stack, '\0');
				i++;
				break;
			case '-' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(subtracao(num48, num48_aux), stack, '\0');
				i++;
				break;
			case '*' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(multiplicacao(num48, num48_aux), stack, '\0');
				i++;
				break;
			case '/' :
				num48_aux 	= pop_stack(stack)->num;
				num48 		= pop_stack(stack)->num;
				push_stack(divisao(num48, num48_aux), stack, '\0');
				i++;
				break;
			default	:
				printf("%d-%c-\n", i, exp[i]);
				// Se for um numero pega a parte da string equivalente a ele
				while((exp[i] != '+')&&(exp[i] != '*')&&(exp[i] != '/')&&(exp[i] != '(')&&(exp[i] != ')')&&(exp[i] != '\0')&&(exp[i] != ' ')){
					aux[j] = exp[i];
					j++;
					i++;
				}
				aux[j] = '\0';
				// passa para um inteiro 48 (implementado com 64)
				num48 = atoll(aux) & 0xffffffffffff;
				// printf("%llu\n", num48);
				j = 0;

				//Coloca o numero na pilha
				push_stack(num48, stack, '\0');
		}
	}
	result = pop_stack(stack)->num & 0xffffffffffff;
	if( result >> 47){
		result = ((~ result )+ 1)& 0xffffffffffff;
		printf("-%016llx\n", result);
	}else
		printf("%016llx\n", result);
}

// Funcao de calculo subtracao arit 48bits
uint64_t soma(uint64_t num, uint64_t num_aux){
	printf("soma de %016llx com %016llx = %016llx\n", num, num_aux, num + num_aux);
	return (num + num_aux) & 0xffffffffffff;

}

// Funcao de calculo subtracao arit 48bits
uint64_t subtracao(uint64_t num, uint64_t num_aux){
	printf("subtracao de %016llx com %016llx = %016llx\n", num, num_aux, num - num_aux);
	return (num - num_aux) & 0xffffffffffff;

}

// Funcao de calculo multiplicacao arit 48bits
uint64_t multiplicacao(uint64_t num, uint64_t num_aux){
	printf("multiplicacao de %016llx com %016llx = %016llx\n", num, num_aux, num * num_aux);
	return (num * num_aux) & 0xffffffffffff;
}

// Funcao de calculo divisao arit 48bits
uint64_t divisao(uint64_t num, uint64_t num_aux){
	printf("divisao de %016llx com %016llx = %016llx\n", num, num_aux, num / num_aux);
	return (num / num_aux) & 0xffffffffffff;
}