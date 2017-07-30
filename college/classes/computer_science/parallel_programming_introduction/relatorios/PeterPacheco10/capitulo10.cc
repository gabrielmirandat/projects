Design and Coding of Parallel Programs

	Foi vista a construção e codificação de programas paralelos, que podem ser classificados 
como orientados a dados ou controle. No primeiro, os dados são divididos entre os processos 
que executam praticamente as mesmas instruções. No segundo, são divididos em tarefas, portanto 
processos diferentes têm funções diferentes. Há o híbrido, mas o a abordagem a dados é mais comum, 
já que é mais fácil e escalável. 
	A orientação a dados foi ilustrada no problema de solução de sistema linear usando método de Jacobi. 
Foi visto que o método permite fácia paralelização dos dados escalares (n e tolerância de convergência) 
e vetores, que foram divididos e comunicados entre os processos. 
	Foi codificado também um programa para ordenar uma lista distribuída, em aboradagem paralela de dados, 
seguindo o padrão serial de codificação. Foi construído de duas formas, tanto de cima para baixo quanto de 
baixo para cima, com funções de debug e macros. 
	Foram vistas duas funções novas, MPI_Alltoall e MPI_Alltoallv, que dividem send_buffer entre processos 
dentro de comm. No primeiro, o tamanho de cada dado é fixo, enquanto no segundo é configurável.

