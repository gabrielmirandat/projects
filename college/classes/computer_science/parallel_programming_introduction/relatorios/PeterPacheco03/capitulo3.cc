Programação Paralela com MPI (Message Passing Interface)
Usaremos o MPICH ()

Cada processo é um processador

1- Diretiva de usuario para colocar uma copia do executavel em cada processador
2- Cada processador executa sua copia
3- Diferentes processadores executam diferentes trechos dependendo de seu rank

MIMD Programming
-> SPMD - um único source executado por vários processos diferenciados pelo ranking
		- todos os programas no livro usarão SPMD

SIMD é uma forma de programar MIMD (!= de SPMD)

MPI
-> mpi.h
	- MIP_Init: chamada única vez antes de todas as outras
	- MPI_Finalize: chamada uma única bez por ultimo. Limpa tudo.
	- MPI_Comm_rank: retorna rank do processo como segundo parâmetro. O primeiro é um comunicador.
		*comunicador -> coleçao de processos que podem trocar mensagens entre si. MPI_COMM_WORLD é o global. Segurança entre processos.
		*passar comunicadores diferentes para bibliotecas.
	- MPI_Comm_size: retorna número de processos existentes no comunicador como segundo parâmetro.
	- MPI_Send: manda mensagem p/ processo.
	- MPI_Recv: recebe mensagem de processo.
		*mensagem -> dados + envelope -> dados + destino + tamanho/identificador de fim + endereço do source
		*dupla ou simples -> dupla(printed or stored + float) ou simples(string com printed/stored e float)
		*tag/tipo de mensagem -> por exemplo, tag 0 é pra printar e tag 1 é pra storar. De 0 a 32767.
		*Envelope -> 1. Rank do receptor
				 	 2. Rank do emissor
				 	 3. Tag
				 	 4. Comunicador
	- MPI_Get_count: retorna tamanho da mensagem recebida. Não muito usada.