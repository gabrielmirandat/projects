Programação dinâmica

60 slides (http://www.geeksforgeeks.org/)
	- .ppt PowerPoint 2000/XP
	- teoria básica
	- 5 principais algoritmos em ordem de dificuldade
	- utilidade prática dos algoritmos
	- Algoritmos devem ser comentados
	- exemplos de como os algoritmos resolvem o problema
	- algortimos diferentes dos vistos em sala
	- pra cada algoritmo pegar código fonte em C/C++ e comentar

100 exercicios (https://hotpot.uvic.ca/index.php)
	- principais aspectos da teoria
	- mostrar como o algoritmo funciona com simulações do que o algoritmo deve fazer em determinado passo

Devem estar compactados neste .zip um .zip para cada algoritmo
	- Código comentado
	- Apresentacao
	- .jqz
	- scorm .zip
	- texto indicando o que cada um fez

dinâmica_06_12345_Jose_06_22345_Maria_06_32345_Joao.zip. 
Documento que conste todos os integrantes indicando o que cada elemento do grupo fez

Somos 4
	- Se 2 algoritmos por pessoa, 8 algoritmos 
		- 100/8 = 12,5 questões por algoritmo
		- 60/8 = 7,5 slides por algoritmo
	- Se 3 algoritmos por pessoa, 12 algoritmos
		- 100/12 = 8,33	 questões por algoritmo
		- 60/12 = 5 slides por algoritmo

Um .zip para cada algoritmo
	// fonte comentado
	- Código comentado
	// slides com teoria básica, utilidade pratica, exemplos de solução
	- Apresentacao
	// exercicíos de teoria básica, funcionamento com simulações do algoritmo
	- .jqz
	- scorm .zip
	// texto falando quem fez o que nesse algoritmo
	- texto indicando o que cada um fez


Já tem 'barra', 'subsequência comum', 'knapsack' 

http://www.geeksforgeeks.org/category/algorithm/dynamic-programming/
The painter’s partition problem
Given a large number, check if a subsequence of digits is divisible by 8
Minimum sum submatrix in a given 2D array
Maximum sum subsequence with at-least k distant elements
Number of NGEs to the right
Length of Longest Balanced Subsequence
Tile Stacking Problem
Counting pairs when a person can form pair with at most one
Count of strings where adjacent characters are of difference one
Longest Repeated Subsequence
Sub-tree with minimum color difference in a 2-coloured tree
Longest alternating sub-array starting from every index in a Binary Array
Longest Common Subsequence with at most k changes allowed
Count all subsequences having product less than K
Number of ways to arrange N items under given constraints

http://www.sanfoundry.com/dynamic-programming-problems-solutions/
01 - Kadane’s Algorithm
02 - 0 1 Knapsack Problem
03 - Longest Increasing Subsequence Problem
04 - Edit Distance Problem
05 - Integer Knapsack Problem
06 - Fibonacci Numbers Problem
07 - Rod Cutting Problem
08 - Subset Sum Problem
09 - Parentheses Expressions Problem – Catalan numbers
10 - Forming Triangles Problem
11 - Change Making Problem
12 - Coin Change Problem
13 - Number of Ways to Reach a Given Score Problem
14 - Matrix Chain Multiplication Problem
15 - Maximum Value of Gifts Problem
16 - Rod Cutting – Maximum Product Problem
17 - Stolen Values Problem
18 - Assembly Line Scheduling
19 - Shortest Common Subsequence Problem
20 - Boredom Problem
21 - Longest Common Subsequence Problem
22 - Binary Trees with N Keys Problem
23 - Balanced Partition Problem
24 - Box Stacking Problem
25 - Building Bridges
26 - Dice Throw Problem
27 - Longest Substring Without Duplication Problem
28 - Optimal Game Strategy Problem
29 - Minimum Number of Jumps Problem
30 - Binomial Coefficients Problem
31 - Counting Boolean Parenthesization Problem
32 - Building Problem
33 - Longest Common Substring Problem
34 - Longest Palindromic Subsequence Problem
35 - Make Palindrome Problem
36 - Minimum number of Squares Problem
37 - Sum of Digits Problem
38 - Alice Kindergarden Candies Problem
39 - Mixtures Problem
40 - Blueberries Problem
41 - Army Problem
42 - Double Helix Problem
43 - Length of the Longest Arithmetic Progression Problem
44 - Newspaper Headline Problem
45 - Stock Maximize Problem
46 - Stock Market Problem
47 - Treats for the Cows
48 - Weighted Activity Selection Problem
49 - Assignments Problem
50 - Bellman Ford Algorithm
51 - Bytelandian Gold Coins Problem
52 - Cut Ribbon Problem
53 - Flloyd Warshall Algorithm
54 - Non Decreasing Digits Problem
55 - T-Primes Problem
56 - Trigraphs Problem


Teoria

Programação Dinâmica

- resolver um problema complexo
	- quebrando em subproblemas simples
	- armazenando soluções num array
	- salva tempo de computação em troca de espaço de armazenamento

- formas de implementação
	- Memoização (top-down)
		- começa com problema original
		- quebra em subproblemas
		- resolve subproblemas de forma semelhante
	- Tabulação (bottom-up)
		- resolve todos os subproblemas primeiro
		- armazena tudo em array
		- baseado nos resultados do array, encontra soluções dos problemas top

- propriedades dos problemas que podem ser resolvidos
	- subproblemas que se sobrepoem
		- problema pode ser quebrado em subproblemas
		- subproblemas são utilizados múltiplas vezes
		- se não se sobrepoem, não há ganho em armazenar soluções que não serão utilizadas novamente
	- subestrutura ótima
		- propriedade em que uma solução ótima do problema original pode ser construída de soluções ótimas dos subproblemas

- passos da solução
	- 1. expressar solução matematicamente
	- 2. expressar solução recursivamente
	- 3. desenvolver um algoritmo bottom-up ou top-down