Capitulo 13 - Advanced Point-to-Point Communication

13.1 An example: Coding Allgather
13.1.1 Function Parameters
13.1.2 Ring Pass Allgather
13.2 Hypercubes
13.2.1 Additional Issues in the Hypercube Exchange
13.2.2 Details on the Hypercube Algorithm
13.3 Send-receive
13.4 Null Processes 
13.5 Nonblocking Communication
13.5.1 Ring Allgather with Nonblocking Communication
13.5.2 Hypercube Allgather with Nonblocking Communication
13.6 Persistent Communication Requests
13.7 Communication Modes
13.7.1 Synchronous Mode
13.7.2 Ready Mode 
13.7.3 Buffered Mode 
13.8 The Last Word on Point-to-Point Communication
13.9 Summary


	'MPI_Send' e 'MPI_Recv' são bloqueantes. No capítulo, são estudados as funções não-bloqueantes do MPI. Algumas implementações 
de 'Allgather' são mostradas com funções bloqueantes e são mostradas formas para tornar as funções aprendidas até aqui mais confiáveis 
e rápidas.
	As funções 'MPI_Sendrecv' e 'MPI_Sendrecv_replace' são apresentadas. Elas têm a característica de evitar deadlocks usando comunicações 
emparelhadas. Funções não-bloqueantes fornecem um meio de sobreposição de comunicação e computação, além de melhora de performance. São 
apresentadas as funções 'MPI_Isend' e 'MPI_Irecv', não-bloqueantes. 
	São abordades solicitações persistentes de comunicação, com possibilidade ainda maior de sobreposição de comunicação e computação. 
	Ainda são comentados alguns modos de comunicação, sendo que é possível ao programador explicitamente dizer ao sistema se deve-se 
usar mensagens bufferizadas e onde elas devem ser alocadas.

	Foram estudados dois algoritmos para 'Allgather' com a programação de hipercubos.
	Foram estudadas as funções 'MPI_Sendrecv' e 'MPI_Sendrecv_replace'. Ambas tanto enviam quanto recebem informação e gerenciam automaticamente 
a bufferização. A segunda versão utiliza o mesmo armazenamento tanto para envio quanto recebimento. Úteis para troca de dados entre processos ou 
deslocamento de dados. Com 'MPI_PROC_NULL', troca-se dados com um processo não existente.
	Também foi apresentado comunicação não-bloqueante, que provê maior performance. Para isto, são usados 'MPI_Isend', 'MPI_Irecv' e 'MPI_Wait'.
O buffer usado não pode ser modificado, já que ao retornar de 'MPI_Isend' ou 'MPI_Irecv' a operação pode não ter sido completada - de enviar e receber. 
Para completar a operação, deve-se chamar 'MPI_Wait'.
	Com solicitações permanentes de comunicação podemos evitar o custo de recalcular o envelope de mensagens que muito se repetem. No envio, por exemplo, 
usamos 'MPI_Send_init', 'MPI_Start' e 'MPI_Wait'. Com 'MPI_Send_init', as configurações do envio são feitos uma única vez, que cria uma solicitação 
reusável. Para iniciar o envio, usa-se 'MPI_Start'. Para completar o envio, chamamos 'MPI_Wait' como de costume. O mesmo esquema é usado no recebimento
de dados.
	Os modos de comunicação MPI são 'standard', 'synchronous', 'ready' e 'buffered'. Recebimento de dados só usa modo 'standard', enquanto envio pode usar todos 
eles. No modo 'stardard', bufferização fica a cargo do sistema. No 'synchronous', bufferização nunca é utilizada, sendo que o envio não completa enquanto que 
o receptor não começar a receber os dados. No 'ready', enviasse sem saber ainda quem é o receptor até que ele se mostre. No modo 'buffered', sempre ocorre 
bufferização. Para cada um dos modos, existem envio 'bloqueante', envio 'não-bloqueante' e envio 'persistente', sendo escolhidos na chamada da função pela adição 
da inicial maiúscula. No modo 'buffered', é necessário definir e liberar buffers, sendo a cargo do programador. Deve-se usar um buffer por processo.  
	São mostradas outras funções ponto a ponto úteis, como variações da 'MPI_Wait' para completar múltiplas operações não-bloqueantes e 'MPI_Test' para 
testar se a operação não-bloqueante foi finalizada.