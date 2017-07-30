Capitulo 11 - More On Performance

12.1 Amdahl1s Law
12.2 Work and Overhead
12.3 Sourcer of Overhead
12.4 Scalability
12.5 Potential Problems in Estimating Performance
12.5.1 Networks of Workstations and Resource Contention 
12.5.2 Load Balancing and Idle Time
12.5.3 Overlapping Communication and Computation
12.5.4 Collective Communication
12.6 Performance Evaluation Tools
12.6.1 MPIs Profiling Interface
12.6.2 Upshot

	É continuado com o assunto de performance do capítulo anterior. É apresentada a lei de Amdahl e como ela foi reavaliada com a 
ideia da escalabilidade de sistemas paralelos. Ainda ao final é abordado o problema de se medir performance em problemas paralelos, 
assunto iniciado no capítulo anterior, e também um software para auxiliar nesta medição. A lei de Amdahl implicava que sistemas paralelos 
de grande escala seriam limitados quanto ao aumento proporcional de velocidade, entretanto foi conseguido por um grupo de pesquisadores 
um aumento de cem vezes em velocidade num processador com 1024 núcleos, o que fez necessitar uma reavaliação da lei, principalmente pela 
ideia de escalabilidade. Escalabilidade significa a possibilidade de um programa de manter dada eficiência enquanto o número de processadores
e a complexidade ou tamanho do problema aumentam.	 

	Por Amdahl, se uma fração s de um programa é inerentemente serial (que não é possível paralelizar), o máximo de aceleração que ele 
consegue obter é de 1/s independente de quantos núcleos sejam usados. Um exemplo é um programa 10% inerente serial, o máximo de aceleração 
é 1/1/10 = 10 independente do número de processos usados.
	É fato que se temos um problema fixo e aumentamos o número de processos, a eficiência diminui. Mas se aumentarmos o poder computacional, 
aumentamos também o tamanho do problema a se resolver. Isto nos leva ao conceito de escalabilidade. Um programa é escalável se conseguimos 
manter uma eficiência constante aumentando o tamanho do problema ao mesmo tempo em que aumentamos o número de processos. Temos aqui o conceito 
de trabalho e sobrecarga. O trabalho feito por um programa serial é seu tempo de execução, enquanto que o feito por um programa paralelo é 
a soma dos trabalhos de cada processo. A sobrecarga em um programa paralelo é a diferença entre o trabalho feito por um programa paralelo e seu 
correspondente serial. A eficiência é o trabalho do equivalente serial dividido pelo trabalho do paralelo. 
	São três as fontes de sobrecarga em programas paralelos: comunicação interprocesso, tempo ocioso de processo e custo adicional de 
processamento (processamento não necessário no equivalente serial). Além disso, existem casos em que há maior dificuldade de mensurar 
a performance no sistema paralelo, que são contenção de recursos, desbalanceamento de carga, sobreposição de processamento em comunicação 
e comunicação coletiva. Devido a estes fatores, pode-se usar uma interface fornecida pelo MPI que permite que usuários criem 
a própria biblioteca para cada função do MPI que desejam analisar.
	Também é apresentado um programa que pode ser usado para estudar o comportamento de programas paralelos, o Upshot. Ele permite geração de 
gráficos de Gantt de programas paralelos, que mostram os avanços de cada processo relacionados ao todo ou separadamente.
