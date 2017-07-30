Dealing with I/O

8.1 - Dealing with stdin, stdout and stderr
	8.1.1 - Attribute Caching
	8.1.2 - Callback Functions
	8.1.3 - Identifying the I/O Process Rank
	8.1.4 - Caching an I/O Process Rank
	8.1.5 - Retrieving the I/O Process Rank
	8.1.6 - Reading from stdin
	8.1.7 - Writing to stdout
	8.1.8 - Writing to stderr and Error Checking 
8.2 - Limited Access to stdin
8.3 - File I/O
8.4 - Array I/O
	8.4.1 - Data Distributions
	8.4.2 - Model Problem
	8.4.3 - Distribution of the Input 
	8.4.4 - Derived Datatypes
	8.4.5 - The Extent of a Derived Datatype
	8.4.6 - The Input Code
	8.4.7 - Printing the Array 
	8.4.8 - An Example
8.5 Summary

	O objetivo primordial do capítulo foi desenvolver aplicações simples de entrada e saída para programas paralelos. 
Pelo menos um processo deve ter a capacidade de realizar funções de entrada e saída – printf, scanf, … - e torná-las 
em funções coletivas, sendo os dados lidos pelo processo I/O e distribuídos aos outros e dados a serem escritos reunidos 
dos outros processos pelo processo I/O e por ele escritos. 
	Todas as funções I/O devem recebem um argumento do comunicador. Como o rank dos processos I/O dependem de comunicador, 
é possível unir estas informações em caching de atributos, que são ponteiros para int, que apontam para o conteúdo dos 
atributos, rank do processo I/O. Como podem ter vários atributos em cache num comunicador, uma chave é necessária para 
identificá-los.
	Atributos e chaves são locais, cada processo tem chaves e atributos diferentes. As funções de acesso são locais, atributos
podem estar definidos ou não para processos diferentes.
	Criamos chaves com "MPI_Keyval_create". Retorna ponteiro pra chave, útil para achar rank do processo de I/O.
	Para duplicar um comunicador, usamos "MPI_Comm_dup". Para deletar um comunicador, "MPI_Comm_free". Ambas são passadas como 
argumento callback de "MPI_Keyval_create". Ainda há como deletar um atributo com "MPI_Attr_delete". Existem funções predefinidas 
para "MPI_Comm_dup" e "MPI_Comm_free", que são "MPI_DUP_FN" e "MPI_NULL_DELETE_FN", sendo que a primeira simplesmente copia 
o ponteiro do atributo e a segunda não faz nada. 
	Para determinar ranks de processos que podem usar I/O, usamos o atributo "MPI_IO". Este atributo deve ser cacheado junto 
com "MPI_COMM_WORLD". Seu conteúdo pode tanto ser MPI_PROC_NULL (não pode usar I/O), MPI_ANY_SOURCE(todos podem usar I/O) ou 
o rank do processo. Podemos determinar seu valor ou de qualquer outro atributo com "MPI_Attr_get". Após encontrar o rank do 
processo com I/O, podemos cacheá-lo com o comunicador chamando "MPI_Attr_put". 
	Foi criado um comunicador separado para I/O, mas podemos querer o rank I/O por meio de outro comunicador. Com 
"MPI_Comm_compare", podemos comparar grupos e contextos de dois comunicadores. Se iguais, retorna "MPI_IDENT", se grupos 
iguais com contextos diferentes, "MPI_CONGRUENT", se grupos com mesmos processos em outra ordem, "MPI_SIMILAR", senão 
"MPI_UNEQUAL". Existe também "MPI_Group_translate_ranks". 
	A função de entrada Cscanf obtém rank do processo I/O, lê dados desse processo e broadcast pra todos os outros processos. 
A função de saída Cprintf obtém o rank de I/O, coleta dados de todos os processo no processo 0 e mostras os dados dele. Em 
Cerror, obtemos códigos de erros de todos os processos e enviamos a todos eles, se algum com problema, o processo I/O mostra ranks
deles e todos os processos chamam "MPI_Abort", que tenta desligar todos os processos do comunicador. 
	Alguns problemas básicos são abordados. Pelo menos um processo pode acessar stdout e stderr, mas existem implementações que 
não permite acesso à stdin. São três as soluções: usar linha de argumento, que em muitas implementações compartilha com todos os 
outros processos, usar um arquivo C separado com entradas ou usar um arquivo que não stdin. Na terceira opção, surgem os problemas
dos arquivos em sistemas paralelos, sendo um deles ter certeza de que cada processo acessa um arquivo diferente. 
	Para ganhar performance usando dados de I/O, podemos usar arrays de I/O, sendo as distribuições em bloco, cíclica ou em 
bloco e cíclica. Para arrays cíclicos, um único processo pode se encarregar de I/O enquanto que as funções de I/O são operações 
coletivas. A de entrada, Read_entries, obtém rank do processos I/O, lê dados de um array simples e usa "MPI_Scatter". A de 
saída, Print_entries, obtém rank do I/O e "MPI_Gather" de todos os processos no de I/O, printando na tela. Porém há problemas da 
não linearidade dos dados na memória e do que é passado pra cada processo. Para passar por estes problemas, usa-se o tipo de 
dados "MPI_UB", que muda a extensão de um tipo artificialmente. 



