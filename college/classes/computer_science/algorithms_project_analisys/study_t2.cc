10_Aula_divide

# DIVIDIR PARA CONQUISTAR
	1. 'Dividir' o problema em subproblemas
	2. 'Conquistar' os subproblemas de forma recursiva
	3. 'Combinar' as soluções dos subproblemas

	# Merge sort
		'dividir para conquistar' Θ(nlgn)
		1. 'Dividir': trivial
		2. 'Conquistar' ordenar recursivamente 2 subarrays
		3. 'Combinar' fusão das listas em tempo linear

		T(n) = 2T(n/2) + Θ(n)
		2 - num subprob
		n/2 - tam do subprob
		Θ(n) - trabalho de dividir e combinar

	# Elevar a potencia //calcular a^n
		'ingênio' Θ(n)
		while(i<=pow){
			sum=sum*num;
			i++;
		}

		'dividir para conquistar' Θ(lgn)
		///papel///

	# Fibonacci	
		'recursivo ingênuo' Ω(φ^n) //tempo exponencial com razão áurea
		///papel///

		'linear' Θ(n)
		for( int i = 2; i<= n; i++){
			f = f_n1 + f_n2;
			f_n2 = f_n1;
			f_n1 = f;
		}

		'quadrado' Θ(1)
		Fn = φ^n / sqrt(5), arredondado para inteiro mais próximo

		'quadrado recursivo' Θ(lg n)
		///papel///

	# Multiplicação de matrizes
		'padrão' Θ(n³)
		for i ← 1 to n
			do for j ← 1 to n
				do cij ← 0
					for k ← 1 to n
						do cij ← cij + aik ⋅bkj

		'dividir para conquistar' Θ(n³)
		///papel///
		T(n) = 8T(n/2) + Θ(n²)

		'strassen' Θ (n^(lg7))
		Multiplicar matrizes 2×2 com apenas 7 mults recursivas
		7 mults, 18 somas/subs
		1. 'Dividir': particiona A e B em (n/2)×(n/2)
		2. 'Conquistar': faz 7 multiplicações de (n/2)×(n/2)
		3. 'Combinar': forma C usando + e –

		T(n) = 7 T(n/2) + Θ(n²)
		ganha para valores n>=32

	# Layout VLSI // Colocar uma árvore binária completa com n folhas em um grid usando a menor área possível
		'normal' Θ(nlgn)
		'H-tree' Θ(n)

	## VANTAGENS
		- Problemas complexos são transformados em problemas mais simples
		- São úteis para programação paralelas pois os subproblemas são independentes
		- Podem ser mais eficientes em termos de utilização da memória (cache hit)
		- Podem fazer cálculos mais precisos pois tendem a lidar com números de mesma grandeza

	## Conclusão
		- Dividir para conquistar é apenas uma das várias técnicas de projeto de algoritmos
		- Algoritmos dividir para conquistar podem ser analisados pelo método mestre
		- Algoritmos dividir para conquistar costumam levar a algoritmos eficientes

11_Aula_quicksort

# Quick sort
	// Ordena no lugar
	// Muito pratico com otimizações

	'dividir para conquistar'
	1. 'Dividir': particiona array em dois subarrays em torno do pivot x
				  subarray inferior<=x<=elementos no subarray superior
	2. 'Conquistar' ordena recursivamente os dois subarrays
	3. 'Combinar' trivial (particionamento em tempo linear)

	- Assume que todos os elementos são diferentes
	- Na pratica, existem algoritmos de particionamento melhores para quando existem elementos duplicados
	- Seja T(n) = o pior caso em uma array de n elementos
	
	## Pior caso - Θ(n²)
	- Entrada está em ordem inversa
	- Particiona sobre o elemento min ou max
	- Um lado da partição sempre ficará sem elementos
	- T(n) = T(0) + T(n-1) + Θ(n)

	## Melhor caso - Θ(nlgn)
	- Com sorte, PARTITION divide ao meio exato
	- T(n) = 2T(n/2) + Θ(n)
	- raro

	## Quase melhor - Θ(nlgn)
	- Divide 1/10 para 9/10
	- T(n) = T(1/10n) + T(9/10n) + Θ(n)
	- sorte!

	# Hoare
	- Quicksort original é mais rápido fazendo menos trocas
	- Vetor ordenado não faz nenhuma troca
	- Vetor com todos os elementos repetidos não tem O(n²) (é O(nlogn) )

	# Quicksort randomizado
	- para se ter sorte em geral!
	- Tempo de execução é independente da ordem da entrada
	- Não existem suposições a serem feitas sobre a distribuição de entrada
	- Nenhuma entrada específica leva ao pior caso
	- O pior caso é determinado somente pelo gerador de números aleatórios

	## Na prática
	- Quicksort é um ótimo algoritmo de uso geral
	- Quicksort é tipicamente duas vezes mais rápido que o merge sort
	- Quicksort pode se beneficiar substancialmente de otimizações de código
	- Quicksort tem bom desempenho mesmo em sistemas com memória virtual e caching


12_Prog_Dinamica

# Programação Dinâmica
	- para resolver problemas de otimização

	## tips
	'Subestrutura Ótima' Uma solução ótima para uma instância do problema contém a solução ótima dos subproblemas
	'Subproblemas Sobrepostos' Uma solução recursiva contém um “pequeno” número de subproblemas distintos que se repetem varias vezes
	'Memoização' Depois de calcular a solução para um subproblema, guarde o resultado em uma tabela. As chamadas subsequentes verificam se o trabalho está na tabela e evita refazer o trabalho
	
	## Como funciona
	1. resolver subproblemas menores e sobrepostos
	2. grava os subproblemas resolvidos em uma tabela
	   (evita que sejam resolvidos mais de uma vez)
	3. Obtem a resposta procurada a partir da tabela

	## 4 passos
	1. Caracterizar a estrutura de uma das soluções ótimas
	2. Defina recursivamente o valor de uma solução ótima
	3. Calcule o valor de uma solução ótima de forma bottom up
	4. Construa uma solução ótima a partir das informações calculadas

	# Problema da barra
		- dado barra de tam n
		- preços para i=1,2,...,n
		- renda máxima podendo cortar peças

		Tam i 1  2  3  4  5  6  7  8  9  10
		preço 1  5  8  9  10 17 17 20 24 30

		n= i1 + i2 + ...+ ik (tamanho é junção de tamanhos menores)
		rn = pi1 + pi2 +... + pik (preço total é a soma dos preços)

		- O valor de rn para n >= 1 pode ser definido em termos das rendas ótimas para as barras menores
		- rn = max ( pn, r1+rn-1, r2+rn-2  ,...rn-1+r1)
		- pn significa não cortar a barra de tamanho n
	 	- Subestrutura ótima : uma solução ótima para um problema incorpora a solução ótima para os subproblemas relacionados que podem ser resolvidos de forma independente

	 	'CUT-ROD (p,n)'

	 	##top down
	 	- “Memoização” salva os resultados parciais para evitar retrabalho
	 	'MEMOIZ-CUT-ROD(p,n)'

	 	##bottom-up
	 	'BOTTOM-UP-CUT-ROD(p,n)' θ(n²)
	 	'EXTENDED-BOTTOM-UP-CUT-ROD(p,n)'

 	# Maior subsequencia comum (LCS)
		- dadas duas subsequências x[1 . . m] e y[1 . . n] 
		- encontrar maior subsequência que é comum as duas, sendo que podem existir várias destas subsequencias
		- comparações de arquivos (diff unix), múltiplas alterações (github), bioinformática
		- é uma sequencia de símbolos em ordem

		'força bruta' O(n2^m )
			- Verifica todas as subsequencias de x[1 . . m] para ver se é também uma subsequencia de y[1 . . n]
			- 'pior caso' O(n2^m )

		'recursivo' Θ(mn)
			1. Verifique o tamanho da maior subsequencia comum
			2. Estenda o algoritmo para encontrar a própria LCS
			///papel///

			Pior caso: x[i] != y[j], no caso onde o algoritmo avalia dois subproblemas onde apenas um parâmetro é decrementado



13_Aula_guloso
• Algoritmo guloso
• Representação de grafo
• Árvore de extensão mínima
• Substrutura ótima
• Escolha gulosa
• Algoritmo de Prim

# Algoritmos gulosos (greedy)

	# Problema do troco
		- dar troco de 48 centavos
		- usando menor numero de moedas possível
		- moedas disponíveis 25, 10, 5 e 1 centavos
		- Solução: escolher a maior moeda que não excede o valor faltante
		- Sempre faz a melhor escolha a cada passo (passo guloso). Esta faz parte da solução global ótima
		- Um algoritmo guloso sempre escolhe a melhor decisão possível a cada passo baseado na suposição de que isto irá levar a melhor decisão ótima.
		- Escolha a cada passo
			1. possível (Satisfaz as restrições do problema)
			2. Localmente ótima (Deve ser a melhor decisão dentre as possíveis)
			3. Irrevogável (Uma vez escolhido não se pode mudar)
		- Nem sempre um algoritmo guloso leva a um resultado ótimo ou a uma solução possível

		25 (falta 23)
		10 (falta 13)
		10 (falta 3)
		1,1,1

		- Problema genérico: dado um número ilimitado de moedas com valores v1>v2>...>vm , dê o troco de valor n com o menor número de moedas possível

		- para v1 = 7, v2 = 5, v3 = 1 e n = 10
		- para v1 = 7, v2 = 5, v3 = 3 e n = 11

		'guloso'
			- 7 (falta 3)
			- 1, 1 ,1
			- A solução certa é 5 5!

			- 7 (falta 4)
			- 3 (falta 1)
			- Solução errada!
			- A solução certa é 5 3 3!

		'dinâmica'
			- pode resolver de forma ótima

	# Problema da mochila fracionada 'Knapsack fracionario'
		- dado mochila que suporta peso máximo W
		- enchar mochila de forma que contenha maior valor (benefício) possível
		- cada item i tem peso wi e benefício bi
		- pode pegar uma fração xi de um item i

		'guloso'
			- escolher sempre item com maior benefício por peso
			- mantendo peso total no máximo W

			item       1   2   3   4   5
			peso 	   4   8   2   6   1
			beneficio  12  32  40  30  50
			ben/Peso   3   4   20  5   50

			Com W=10, pega 1 do 5 (50)
						   2 do 3 (20+20)
						   6 do 4 (5+5+5+5+5+5)
						   1 do 2 (4) = 124

			- complexidade - O(nlogn)
				- os itens podem ser ordenados e depois percorridos em ordem (maior beneficio/peso primeiro)

			- solução gulosa é correta
				- suponha que exista uma solução melhor. Então existe um xk que substituindo um xi da solução obtida dá um benefício total maior. Neste caso como o benefício/peso de xk é menor xi então xk>xi violando a restrição <= W

	# Problema da mochila 0/1 'Knapsack 0/1'
		- dado mochila que suporta um peso W > 0
		- dado um conjunto S de n itens com pesos wi >0
		- e n benefícios bi > 0 para i = 1,...,n
		- S = {(item1, w1, b1), (item2, w2, b2),. . . ,(itemn, wn, bn)}
		- Encontre um subconjunto de itens que não exceda o peso W e maximize o benefício total
		- O item é colocado inteiro ou não é colocado (0/1)

		'força bruta' Ω(2^n)
			- listar todos os 2^n conjuntos possíveis
			- eliminar os que excedem o peso W
			- escolher o dá maior benefício

		'guloso'
			item       1   2   3
			peso 	   5   10  25
			beneficio  70  90  140 - 14 - 9 - 5.6
			W = 25
			- solução ótima = 1 (70) + 2 (90) = 160 e sobra w=10
			- guloso1 = escolher sempre o mais caro
				- sol = 3 (140) - NÃO ÓTIMO

			item       1   2   3
			peso 	   5   10  20
			beneficio  150 60  140 - 30 - 6 - 7
			W = 25
			- solução ótima = 1 (150) + 3 (140) = 290
			- guloso2 = escolher sempre o mais leve
				- sol = 1 (150) + 2 (60) = 210 e sobra w=10 - NÃO ÓTIMO

			item       1   2   3
			peso 	   5   20  10
			beneficio  50  140 60 - 10 - 7 - 6
			W = 30
			- solução ótima = 1 (50) + 2 (140) = 190 e sobra w=5
			- guloso3 = escolher sempre o maior custo/beneficio
				- sol = 1 (150) + 2 (60) = 210 e sobra w=10 - NÃO ÓTIMO

	## guloso vs progamação dinâmica
		- quando aplicar guloso?
			- quando solução ótima global pode ser obtida a partir de uma escolha ótima (gulosa) local
			- quando uma solução ótima do problema contem uma solução ótima para os subproblemas
		- gulosos nem sempre são ótimos
		
		- em comum: Subestrutura ótima
		- diferença: propriedade da escolha gulosa
		- Programação dinâmica pode ser utilizada se o algoritmo guloso não der a solução ótima

	## Grafos
		- Um 'grafo dirigido' G = (V, E) é um par ordenado que consiste de um conjunto V de vertices e um conjunto E ⊆ V × V de arestas
		- Um 'grafo não direcionado' G = (V, E), o conjunto de arestas E consiste de pares não ordenados
		- Nos dois casos, temos |E| =O(V²)
		- Se G e conexo, então |E| ≥ |V| – 1, o que implica que lg |E| = Θ(lgV)

		# Matriz de adjacencia
			- A matriz de adjacencia de um grafo G = (V, E), onde V = {1, 2, ..., n}, é a matriz A[1 . . n, 1 . . n]
			- Θ(V²) espaço 

		# Lista de adjacencia
			- Uma lista de adjacência de um vértice v ∈ V é uma lista Adj[v] dos vértices adjacentes a v
			- Para grafos não direcionados, |Adj[v]| = grau(v).
			- Para grafos direcionados, |Adj[v]| = grau-saida(v)
			- Θ(V + E) espaço

		# Arvore de extensão mínima (AEM)
			- 'Minimum spanning tree'
			- Aplicações para redes de computadores, eletricidade, rodovias, abastecimento de água, telecomunicações
			- Entrada: Um grafo conexo não direcionado G = (V, E) onde cada aresta tem um peso w
			- Saída: Uma árvore de extensão T — uma árvore que conecta todos os vértices com um peso mínimo w
			- Tem problemas sobrepostos
			- Pode ser resolvido com Programação Dinâmica
			- Escolha gulosa: a escolha ótima local é a escolha ótima global

		# Algoritmo de Prim (PEGA MENORES ARESTAS A PARTIR DOS VERTICES CONECTADOS QUE NAO FORMAM CICLO)
			- Idéia: Manter V – A como uma fila de prioridade Q. Nomeia cada vértice em Q com o peso da aresta de menor peso que o conecta a um vértice em A
			- Θ(V)
			- Tempo = Θ(V)·T EXTRACT-MIN + Θ(E)·T DECREASE-KEY
			- O algoritmo de Kruskal roda em tempo O(E lg V) ou O(E lg E) pois E <= |V²|

		# Algoritmo de Kruskal (PEGA SEMPRE MENOR ARESTAS SEM FORMAR CICLOS)
			1. Ordena todas as arestas em ordem crescente
			2. Pega a menor aresta disponível. Se adicionada ela forma um ciclo então descarta. Senão inclui
			3. Repete passo 2) até incluir todos os vértices
			- Complexidade O(E log E)
			
			
14_Aula_Radix
Limites inferiores da ordenação
Árvores de decisão
Ordenação em tempo linear
Counting sort
Radix sort

	## algoritmos comparação
		- usam somente comparação para determinar a ordem relativa dos elementos
		- Ex. inserção, mergesort, quicksort
		- O melhor pior caso até o o momento é O(nlgn)
		- O(nlgn) é o melhor possível?
			- 'Árvores de decisão' podem ajudar nesta análise

	## Árvore de Decisão
		- PARA ORDENAR
		- A ordem dos indices indica a ordem para ficar ordenado
		- A sub-árvore da esquerda mostra a comparação subsequente se ai <= aj
		- A sub-árvore da direita mostra a comparação subsequente se ai >= aj
		- Uma árvore de decisão pode modelar qualquer algoritmo de comparação
		- O algoritmo gera um desvio quando compara dois elementos
		- Á árvore contem as comparações para qualquer execução possível
		- O tempo de execução e o tamanho do caminho
		- Tempo do pior caso é a altura da árvore
		- 'Teorema' Qualquer árvore de decisão que ordene n elementos tem altura Ω (nlgn)
		- 'Prova' A árvore deve conter ≥n! folhas, pois existem n! permutações possíveis. A altura h da árvore binária tem ≤2^h folhas. Então, n! ≤2^h

		⁻ Corolário: O Heapsort e o merge sort são algoritmos de ordenação por comparação assintoticamente ótimos

	## Ordenação em tempo Linear
		# Counting sort - Θ(n+k)
			- Não faz comparação entre elementos
			- 'Entrada' A[1 . . n], onde A[j]∈{1, 2, ..., k}
			- 'Saída' B[1 . . n], ordenada
			- 'Armazenamento auxiliar' C[1 . . k]
			- B[C[A[j]]] = A[j];   C[A[j]]--;
			- Se k = O(n), então counting sort demora Θ(n)
			- preserva a ordem entre os elementos iguais

			- Mas a ordenação 'Comparação' demora Ω(nlgn)!
			- O Counting sort não é uma ordenação por comparação


		# Radix sort
			- Ordenação por Dígito
			- Idéia original era usar o dígito mais significativo (ruim)
			- Idéia melhor foi usar o dígito menos significativo com ordenação auxiliar estável
			- Assume que os números estão ordenados nos t –1 dígitos ordem mais baixa.
			- Ordena no dígito t
			- Dois números que diferem no dígito t já estão ordenados
			- Dois números iguais no dígito t são colocados na mesma ordem que a entrada ⇒ ordem correta

	## Conclusoes
		- Na prática o radix sort é rápido para entradas grandes e é fácil de codificar e manter
		- 'Problema' Diferente do quicksort, o radix sort mostra pouca referencia de localidade, portanto um quicksort otimizado se sai melhor nos processadores modernos com hierarquias de memória

15_Aula_P_NP

	## Vários problemas
		- Complexidades O(n²) ,O(nlogn), O(n), O(nm)
		- O tempo é polinomial em relação a entrada N
		- Estes são considerados problemas tratáveis

		- Será possível resolver todos os problemas interessantes em tempo polinomial?

	## Problema difícil
		- Problema do caixeiro viajante (Traveling Salesperson Problem - TSP)
		- Problema do Clique Máximo

		# Problema do caixeiro viajante - Traveling Salesperson Problem - TSP
			- Entrada: um grafo não direcionado com as distâncias na aresta
			- Saída: caminho mais curto que percorre todos os vértices exatamente uma vez e chega ao vértice inicial
			- Problema de otimização
			- Existem n! soluções possíveis
			- Melhor algoritmo conhecido: O(n2^n)
			- 2^n, ou seja, NÃO É POLINOMIAL
			- Intratável
			- Polinomial é x^1000, mas n^x é intratável, n! também é intratável

		# Problema do Clique Máximo
			- Entrada: grafo não direcionado G=(V,A)
			- Saída: o maior subconjunto C de V tal que cada par de vértices em C tem uma aresta entre eles
			- Problema de otimização
			- Existem 2^n soluções possíveis
			- Melhor algoritmo conhecido: O(n2^n)
			- Intratável

	## Problemas interessantes NP
		- Provas matemáticas
			- Pode resolver todos os outros 5 problemas 'Clay Institute' (5 milhões)
			- Criptografia, Vários problemas de otimização, projeto, Inteligência Artificial

		- O que pode ser feitos?
			- Gastar mais tempo e recursos projetando algoritmos para estes
				- Tem sido tentado por décadas
			- Provar que não existe um algoritmo polinomial para estes casos
				- Parece difícil encontrar esta prova
			- Mostrar que estes problemas difíceis são essencialmente equivalentes. Se um deles pode ser resolvido em tempo polinomial então todos eles podem ser também
				- Isto funciona para pelo menos 10.000 problemas difíceis!!

		- Os benefícios da equivalência
			- Combina os esforços de pesquisa
			- Se um problema tem tempo polinomial então todos tem esta solução
			- Outra possibilidade: Uma vez que um limite inferior exponencial for demonstrado para um problema então este limite se mantém para todos eles

		- Se mostrarmos que um problema ∏ é equivalente a 10.000 outros problemas bem estudados que não tem solução eficiente então temos uma forte evidencia de que ∏ é um problema difícil

			1. Identificar as classes de problemas de interesse
			2. Definir a noção de equivalência
			3. Provar esta equivalência

	## Classes de problemas: P e NP
		- Problemas de decisão 'SIM ou NÃO'
			- Outros problemas podem ser convertidos para um problema de decisão
			- Clique-k: existe um clique de tamanho = k?

		- P 'é o conjunto dos problemas que podem ser resolvidos em tempo polinomial'
		- NP '(nondeterministic polynomial time) é o conjunto dos problemas que podem ser resolvidos em tempo polinomial por um computador não determinístico'

		## Computador Não deterministico
			- Existe apenas em teoria
			- Um computador não deterministico “imagina” uma solução e verifica se está correta
			- Se uma solução existe então ele sempre descobre ela
			- Como um computador paralelo com um número infinito de processos e processadores
			- Um processador para cada solução possível
			- Todos os processadores tentam verificar se sua solução funciona
			- Se um processador encontra então ele tem uma solução funcional
			- Então: NP = problemas verificáveis em tempo polinomial

		## P e NP
			- P (Polynomial time) 'problemas que podem ser resolvidos em tempo polinomial'
			- NP (Nondeterministic Polynomial time) 'problemas para os quais uma solução pode ser verificada em tempo polinomial após descoberta'

			# Clique-k está em NP
				- Fácil verificar a solução em tempo polinomial

			# Ordenação não está em NP
				- Não é um problema de decisão

			# Verificar se está ordenado está em NP
				- Sim. Isto é fácil de verificar

			## P é NP?
				- Um dos maiores problemas da Ciência da Computação
				- Muitos suspeitam que não
				- Prêmio de 1 milhão para primeira prova 'Clay Math Institute'
				- P é NP ou 'P está dentro dos problemas NP'?

			## NP-Completos 'dificilmente resolviveis, mais resolve'
				- Resolver um NPC resolve todos os NPCs
				- São os problemas mais difíceis em NP
				- Se qualquer um dos problemas NP-Completos podem ser resolvidos em tempo polinomial então todos podem ser resolvidos em tempo polinomial
				- Então todos os problemas em NP podem ser resolvidos em tempo polinomial (o que mostraria P = NP)
				- 'Então' resolver o TSP em O(n^10000), você provou que P = NP. Você ficaria rico e famoso
				- 'Redutibilidade' um problema Π’ pode ser reduzido em outro problema Π se qualquer instância de Π’ pode ser facilmente reorganizada como uma instância de Π, e resolvendo este se resolve para a instância de Π’
				- Esta reorganização é chamada de transformação
				- Intuitivamente: Se Π’ se reduz a Π, Π’ não é mais difícil de resolver que Π
				- 'Transformação' (x1 , x2 , ..., xn ) = (y1 , y2 , ..., yn ) onde yi = 1 se xi = VERDADEIRO, yi = 0 se xi = FALSO
				- ∏’ é redutível a tempo polinomial para ∏ 'função de transformação é polinomial'

			## NP
				- Temos uma forma de dizer que um problema não é mais difícil que o outro (∏’ ≤ p ∏)
				- Objetivo: mostrar a equivalência entre problemas difíceis
				- Opções:
					- Mostrar a redução entre todos os pares de problemas
					- Diminui o número de reduções usando a transitividade de “≤”
					- Mostrar que todos em NP são redutíveis para um ∏ fixo
					- Mostrar que algum problema ∏’∈NP e equivalente a todos os problemas difíceis

			## Primeiro problema ∏

				# Satisfabilidade booleana (SAT)
