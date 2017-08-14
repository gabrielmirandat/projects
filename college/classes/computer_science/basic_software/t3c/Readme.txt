##GRUPO 3
Jadiel Teófilo Amorim de Oliveira
Bárbara Varanda Rangel
Gabriel Martins de Miranda
Marcos Cordeiro Fleury
Túlio de Carvalho Matias

#reEx Resolvedor de expressoes
#Implementação
#Manipulalação em 48 bits
#Genérico ou dependente de arquitetura
#Dificuldades na implementação
#Documentação
#Participantes

#reEx Resolvedor de expressoes
	Desenvolvido em C na plataforma windows e compilado utilizando do comando <gcc -std=c99 reEx.c -lm -o reEx>. 
	A execucao ocorre por meio do comando <reEx "expressao"> (a expressao PRECISA estar entre aspas) sendo a 
expressao uma expressao aritmetica podendo conter interos e operacoes de '+' '-' '*' '/'. 
	Existe tambem a possibilidade de nao especificar a expressao no comando de execucao, fazendo-o apos a 
execucao:
	<reEx> expressao selecionada em tempo de execucao (sem aspas nesse caso).

#Implementação
	O programa implementa diversos algoritmos.

	Conversao infixa para posfixa
		loop:
			0 Caso se encontre um operando, concatena-o ao final da mensagem de saida
			1 Caso se encontre abre parenteses, da push na pilha de operadores
			2 Caso se encontre fecha parenteses, da pop na pilha de operadores ate o 
			  abre parenteses correspondente ser removido. Concatena cada operador ao
			  final da mensagem de saida
			3 Caso se encontre espaco ignore-o
			4 Caso se encontre *, /, +, ou -, da push na pilha de operadores. Entretanto, 
			  primeiro remove todos os operadores ja na pilha que tem precedencia maior ou 
			  igual e os concatena na mensagem de saida
			5 Caso se encontre um \0 encerra.
		Fim loop
			6 Caso algum operador ainda ficou na pilha, é concatenado ao final da mensagem
			  de saida

	Calculo da expressao posfixa 48 bit
		loop:
			1 Caso se encontre um numero passe-o para a representacao 48bit e coloque na pilha
			2 Caso se encontre um operador retire dois termos da pilha, execute a operacao e 
		      coloque o resultado na pilha.
			3 Caso se encontre espaco ignore-o 
			5 Caso se encontre um \0 retira-se o ultimo valor que ficou na pilha, trata-se do 
		      resultado, imprime-o e encerra.
		Fim loop

#Manipulalação em 48 bits
	A arquitetura 48bit foi implementada utilizando-se do tipo uint64_t presente na biblioteca 
stdint. Para isso descartou-se os ultimos dois bytes utilizando-se da mascara 0xffffffffffff 
e de verificacao do ultimo bit para saber se o valor estava negativo.

#Genérico ou dependente de arquitetura
	Apesar do tipo uint64_t ser usado, maquinas 32 bits suportam seu uso.
Em windows, usa-se _atoi64 em vez de atoll.

#Dificuldades na implementação
	Tratar dos parentesis e separação dos algarismos da pilha. Sem maiores problemas

#Documentação
	O código foi totalmente comentado. Divididos em cabeçalho (reEx.h) e fonte (reEx.c)

#Participantes
	Jadiel Teófilo Amorim de Oliveira - Modelagem completa e implementação da funcao avaliadora de expressoes   
	Bárbara Varanda Rangel - Pesquisa na modelagem em 48 bits
	Gabriel Martins de Miranda - Implementacao da conversao de infixa para posfixa, documentacao e correção
	Marcos Cordeiro Fleury - Pesquisa e auxilio na implementacao pilha
	Túlio de Carvalho Matias - Implementação 48 bits e pilha