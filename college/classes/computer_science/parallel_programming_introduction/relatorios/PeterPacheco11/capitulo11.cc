Capitulo 11 - Performance

11.1 Serial Program performance
11.2 An Example: The Serial Trapezoidal Rule
11.3 What about the I/O
11.4 Parallel Program Performance Analyses
11.5 The Cost of Communication
11.6 An Example: The Parallel Trapezoidal Rule
11.7 Taking Timings 


	O capítulo foca na estimação de performance em programas paralelos, em que aborda métodos para estimar 
esta temporização. Entende-se a ineficiência em detalhe dos métodos já praticados em sistemas seriais 
no contexto paralelo, sendo que mais vale a pena um modelo empírico. Embora focado na velocidade de 
processamento, há outras variáveis que interferem na validação do programa, como o  custo para construí-lo.
Deve-se analisar o custo de construção de um programa para justificar se vale ou não a pena melhorar sua performance.

	Para estimar a performance de um programa paralelo, deve-se seguir uma série de passos. Que são desenvolver a fórmula
do tempo de execução e usá-lo em pedaços de interesse do código. Faça a análise serial no pedaço de interesse, tomando 
a temporização de nuâncias. Tome diferenças e meça a velocidade.
	Para possibilitar a medição da temporização, usa-se MPI_Barrier para sincronizar processos e MPI_Wtime para medir 
tempo decorrido. 

int MPI_Barrier(MPI_Comm comm /*in*/)
double MPI_Wtime(void)



