Capitulo 14 - Parallel Algorithms

14.1 Designing a Parallel Algorithm
14.2 Sorting
14.3 Serial Bitonic Sort
14.4 Parallel Bitonic Sort
14.5 Tree Searches and Combinatorial Optimization 
14.6 Serial Tree Search
14.7 Parallel Tree Search
14.7.1 Par_dfs
14.7.2 Service_requests
14.7.3 Work_remains
14.7.4 Distributed Termination Detection
14.8 Summary

	Nem sempre o melhor algoritmo para um sistema paralelo é a versão paralelizada de um programa serial. Na maioria dos casos, 
para se resolver um problema de forma ótima no mundo paralelo, deve-se partir de um novo algoritmo. No capítulo, são ilustrados 
alguns problemas distribuídos e um pouco dos algoritmos usados para resolvê-los. 

	Existem dois tipos de algoritmos paralelos, aqueles baseados de uma versão serial e outros criados especificamente para o munda paralelo.
Foram implementados os algoritmos parallel bitonic e parallel tree search. Parallel bitonic usa a primeira forma de codificação, a baseada 
numa versão serial, enquanto que a segunda foi feita especificamente para ser paralela.
	Aplicou-se o algoritmo parallel tree search para resolver o problema de detecção de terminação distribuída. Deve-se determinar quando uma 
coleção de processos assíncronos terminou de executar. A solução atribui uma quantidade fixa de um recurso indestrutível para o processo zero no 
início da execução. Sempre que trabalho é enviado de um processo a outro, o processo mandante manda metade de seu recurso. Quando um processo não 
tem mais trabalho, manda seu recurso de volta ao processo zero. Quando o processo zero recebe todo o recurso original, o programa termina.
	Com MPI_Probe pode-se checar se uma mensagem de uma fonte específica, dada tag ou certo comunicador está disponível.  

	int MPI_Iprobe(
		int 		source 	/*	in   */
		int 		tag		/*	in   */
		MPI_Comm 	comm 	/*	in   */
		int* 		flag 	/*	out  */
		MPI_Status*	status 	/*	out  */)