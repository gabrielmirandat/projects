// mostra os proc em background
$ps -l 

FLAGS DE ESTADO: descrevem o estado de execução do processo.
•  UID: 			grupo do usuário que startou o processo
•  pid: 			identificador único do processo
•  ppid: 			pid do pai do processo
•  CP: 				fator de utilização de CPU
•  PRI: 			prioridade do processo
•  NI: 				parâmetro para o escalonador
•  SZ:				tamanho do segmento de dados + pilha
•  RSS: 			Memória real utilizada pelo processo
•  WCHAN: 			evento pelo qual o processo está esperando
•  STAT: 			status de execução do processo
•  TT: 				terminal associado ao processo
•  TIME: 			tempo de CPU (user+system)
•  COMMAND: 		arquivo executável que gerou o processo

// novas modificacoes pc biblioteca
EXECUÇÃO DE EXECUTÁVEL
int execl(char *path, char *argv[0], char *argv[1],..., (char *) 0);
	- mantem o pid, o ppid, os parâmetros do escalonador, o real uid, os descritores de arquivos abertos
	- são alteradas a imagem do processo na memória, o conjunto de registradores e o uid efetivo

TERMINO DE PROCESSOS
"sempre que um filho termina, o pai deve ser avisado"

se o pai morre, filhos passam a ser filhos do init
se filho morre sem avisar, fica no estado morrendo <zombie> ou <defunct>

exit
	- fecha todos os descritores de arquivos
	- status salvo até pai executar um wait
	- não retorna, causa término do programa
	
wait
	- bloqueia pai até que um dos filhos termine
	- retorna -1 se o pai não tem filhos, se filho parado, se filho terminou por sinal, senão terminou por exit

ESCALONAMENTO DE PROCESSOS
- prioridades dinâmicas
- política round-robin por fila
- favorece I/O bound
- 'aging': impedir starvation de forma que processos que há muito esperam tem prioridade decrementada
	- int nice(incr) = substitui fator base por incr

// 	

MOTIVOS DE BLOQUEIO:
•  P:  esperando que a página corrente seja carregada
•  D:  esperando I/O
•  T:  parado por um utilitário de debug
•  S:  dormindo por poucos segundos
•  I:  dormindo por muitos segundos
	
COMUNICACAO
•  Pipes;
•  Filas de mensagens;
•  Memória compartilhada;
•  Semáforos;
•  Sinais
	
'Pipes'
- buffers protegidos em memória, acessados segundo a política FIFO
- Cria pipe, cria processo(fork duplica os descritores de arquivos), 
  um processo lê e outro escreve
- 'cria' 
	int pipe(int fd[2]);
	fd[0] é leitura
	fd[1] é escrita
	retorna 0 em sucesso, -1 em erro
- 'escreve' 
	int write(int fd, char *buf, int nbyte);
	escreve 'nbyte' do buffer 'buf' no descritor 'fd'
	retorna num de bytes escritos, senão -1
- 'le'
	int read(int fd, char *buf, int nbyte);
	lê 'nbyte' do arquivo 'fd' no buffer 'buf'
	retorna num de bytes lidos, senão -1

'Filas de mensagem'
- Filas permanentes em memoria ou disco sendo que só processos autorizados tem acesso
- Cria fila, obtem identificador da fila, le ou escreve na fila, remove a fila
- 'includes'
	#include <sys/types.h>
	#include <sys/ipc.h>
	#include <sys/msg.h>
- 'cria'
	int msgget(key_t key, int IPC_CREAT | msgflg);
	cria fila com chave 'key' e permissoes 'msgflg'
	retorna id da fila 'msgid', senão -1
- 'obtem'
	int msgget(key_t key, int msgflg);
	processo cujas permissoes setadas para 'msgflg' obtem 'id' da fila de chave 'key'
	retorna id da fila 'msgid', senão -1
- 'envia'
	int msgsnd(int msgid, struct msgbuf *msgp, int msgsize, int msgflg);
	envia mensagem em 'msgp' de tamanho 'msgsize' para a fila 'msgid' com flags de bloqueio 'msgflg'
		msgp = {long mtype; char mtext[1];}
		msgflg = IPC_NOWAIT(sem bloqueio) ou 0(com bloqueio)
	retorna 0, senão -1
- 'recebe'
	int msgrcv(int msgid, struct msgbuf *msgp, int msgsize, long msgtyp, int msgflg);
	recebe mensagem de tipo 'msgtyp' de tamanho 'msgsize' da fila 'msgid' com flags de bloqueio 'msgflg' em 'msgbuf'
		msgp->mtype deve ser igual a msgtyp
		msgflg = IPC_NOWAIT(sem bloqueio) ou 0(com bloqueio)
	retorna num de bytes recebidos, senão -1
- 'deletar'
	int msgctl(int msgid, IPC_RMID, struct msqid_ds *buf); 
	remove fila de id 'msgid' apenas pelo usuário que criou a fila ou um superusuário
	retorna 0, senão -1

'Memória compartilhada'
- Segmento de memória protegido pelo kernel
- Criação do segmento de mem compartilhada, attach dos processos no segmento,
  acesso via ponteiro, removido explicitamente
- 'includes'
	#include <sys/types.h>
	#include <sys/ipc.h>
	#include <sys/shm.h>
- 'cria'
	int shmget(key_t key, int size, int IPC_CREAT | shmflg);
	cria segmento de tam 'size' com chave 'key' e permissoes 'shmflg'
	'uid' e 'gid' da memória são o 'uid' e o 'gid' efetivos do usuário dono do processo
	retorna id da mem 'shmid', senão -1
- 'obtem'
	int shmget(key_t key, int size, int shmflg);
	obtem segmento de tamanho 'size' com chave 'key' e acesso 'shmflg'
	retorna id da mem 'shmid', senão -1
- 'attach'
	char *shmat(int shmid, char *shmaddr, int shmflg);
	mapeia segmento 'shmid' no endereço 'shmaddr' escolhido pelo sistema ou programador com modo de acesso 'shmflg'
		shmaddr = 0(end. de mapeamento escolhido pelo sistema)
		shmflg = read_only ou read/write
	retorna endereço do segmento de memória, senão -1
- 'detach'
	int shmdt(int shmid);
	desfaz mapeamento do segmento de mem
	retorna 0, senão -1
- 'deletar'
	int shmctl(int shmid, IPC_RMID, struct shmid_ds *buf);
	remove o segmento de mem 'shmid' pelo dono ou superusuário
	retorna 0, senão -1

'Semaforos'
- delimitar seção critica, ordem na execução
- operações no semáforo são indivisíveis
- cria conjunto de sems (semid), obtém id, executa operações, remove identificador
- remoção explicita
- 'includes'
	#include <sys/types.h>
	#include <sys/ipc.h>
  	#include <sys/sem.h>
- 'cria'
	int semget(key_t key, int nsems, int IPC_CREAT | semflg);
	cria conjunto de 'nsems' com chave 'key' e permissoes 'semflg'
- 'operacoes'
	int semop(int semid, struct sembuf *sops, int nsops);
	executa conjunto de operacoes descritas em 'sembuf' sobre semaforos 'semid' pelo numero de vezes 'nsops'
			sembuf = {short sem_num;/* numero do semáforo */
				  short sem_op;/* tipo da operação */
				  short sem_flg; /*flags */}

			// entender depois
	retorna 0, senão -1
- 'obtem'
	int semget(key_t key, int nsems, int shmflg);
	obtem conjunto 'nsem' de semaforos com chave 'key' e permissoes 'shmflg'
	retorna id do conjunto senão, -1
- 'deletar'
	int semctl(int shmid, int semnum, int IPC_RMID, union semun{ val; struct semid_ds *buf; ushort *array;} arg; shmid_ds *buf);
	remove conjunto do id 'semid' pelo dono ou superusuário
	retorna 0, senão -1

'Sinais'
- são interrupções que chegam assincronamente aos processos
- ocorre desvio de execução para a rotina de tratamento e posterior volta à execução anterior seguinte 
- a interrupção pode chegar a qualquer momento

SINAIS DO UNIX
•  SIGHUP		1 hangup
•  SIGINT		2 interrupt
•  SIGQUIT		3
•  SIGILL 		4
•  SIGTRAP 		5
•  SIGABRT 		6
•  SIGEMT 		7
•  SIGFPE 		8
•  SIGKILL 		9
•  SIGBUS 		10
•  SIGSEGV 		11
•  SIGSYS 		12
•  SIGPIPE 		13
•  SIGALRM 		14
•  SIGTERM 		15
•  SIGURG 		16
•  SIGSTOP 		17
•  SIGTSTP 		18
•  SIGCONT 		19
•  SIGCHLD 		20
•  SIGTTIN 		21
•  SIGTTOU 		22
•  SIGIO 		23
•  SIGXCPU 		24
•  SIGXFSZ 		25
•  SIGVTALRM 	        26
•  SIGPROF 		27
•  SIGWINCH 	        28
•  SIGLOST 		29
•  SIGUSR1 		30
•  SIGUSR2 		31
- 'includes'
	#include <signal.h>
	void (*signal(sig, func))()		// apenas associa sinal a uma funcao
	void (*func)(); 			// define funcao de tratamento
	retorna a ação tomada anteriormente, senão -1
- 'envio'
	int kill (pid_t pid, int sig);
	envia sinal 'sig' ao processo 'pid'
			sig=0(somente testa a existência do processo pid)
			pid=-1(enviado a todos os processo de uid de usuário ou do sistema)
	retorna 0, senão -1
- 'alarm'
	unsigned int alarm(unsigned int seconds)
	envia SIGALARM ao processo que o chamou depois de 'seconds' segundos
		seconds=0(cancela alarms pendentes)
	retorna o tempo que faltava para o 'alarm' anterior
- 'pause'
	int pause( )
	pára o processo até que um sinal seja recebido
	retorna nada, senão -1
- 'sleep'
	int sleep( unsigned seconds)
	suspende a execução do processo por no mínimo 'seconds' segundos.
	retorna 0, senão número de segundos que o processo deixou de dormir se houve recepção de sinal


//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//
prob_classicos.pdf

• Os filósofos glutões
• O problema dos leitores/escritores
• O barbeiro dorminhoco

#Questão: Resolver algoritmicamente este
problema de maneira que não haja 'deadlock' nem
'starvation' e que seja permitida a máxima
concorrência possível.

• Os filósofos glutões
	- 5 filosofos em torno de mesa redonda
	- 1 prato na frente e 1 garfo entre cada dois pratos
	- cada filosofo necessita 2 garfos para comer
	- 2 açoes: pensar e comer
	- comer: pegar 1 garfo, pegar outro garfo, comer

1ª solucao - imediata
	'deadlock' se todos os filosofos pegarem ao mesmo tempo
2ª solucao - checa se segundo garfo ocupado
	'starvation' facilmente
3º solucao - com  estados ('pensando', 'comfome', 'comendo'), só come se vizinhos não estão comendo, monitores e var de condição
			 com procedures pega(i), larga(i) e testa(i)

			 // codigo
			 estado[0..4] of 'pensando'
			 condicao[0..4] of 'signaled'

			 pega(i)
			 	estado[i] = 'comfome'
			 	testa(i)
			 	if (estado[i] != 'comendo') condicao[i] = 'wait'

			 larga(i)
				estado[i] = 'pensando'
				testa ((i-1) % 5)  // TODO: pra que?
				testa ((i+1) % 5)  // 

			testa(i)
				if ((estado[(i-1) % 5] != 'comendo') && (estado[i] == 'comfome') && (estado[(i+1) % 5] != 'comendo'))
					estado[i] = 'comendo'
					condicao[i] = 'signal'

			// chamada
			filosofos_glutoes.pega(i);
			/* come */
			filosofos_glutoes.larga(i);
	'starvation' pode ocorrer, livre de deadlock, com exclusão mútua e concorrência máxima

• O problema dos leitores/escritores
	- vários 'leitores' simultâneos 
	- um 'escritor' com acesso exclusivo

1ª solucao - 2 semáforos mutex

			// codigo
			sem mutex = db = 1
			int num_leitores = 0

			reader()
				while(TRUE)
					P(&mutex)
						num_leitores++;
						if(num_leitores==1) P(&db)
					V(&mutex)
					le_dados()
					P(&mutex)
						num_leitores--;
						if(num_leitores==0) V(&db)
					V(&mutex)

			writer()
				while(TRUE)
					P(&db)
						escreve_dados()
					V(&db)
	'boa', mas favorece leitores: escritor não escreve enquanto há leitor lendo

• O barbeiro dorminhoco
	- um barbeiro, uma cadeira de barbeiro
	- várias cadeiras de cliente
	- se não há cliente, barbeiro dorme
	- se chega cliente e barbeiro já está cortando, cliente espera na cadeira
	- se não houver cadeiras, clientes vão embora

1ª solucao - 2 semáforos

			// codigo
			sem clientes = barbeiro = 0
			sem mutex = 1
			int esperando = 0
			int CADEIRAS = 5

			barbeiro()
				while(TRUE)
					P(&clientes)
					p(&mutex)
						esperando--;
					V(&barbeiro)
					V(&mutex)
					corta_cabelo()

			cliente()
				while(TRUE)
					P(&mutex)
						if(esperando<CADEIRAS)
							esperando++;
							V(&clientes)
							V(&mutex)
							P(&barbeiro)
							tem_cabelo_cortado()
						else
							V(&mutex)
							
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//
threads.pdf

processos quanto à custo de troca de contexto
	
	
	'heavyweight' 
		ambiente = espaço de endereçamento, (código, dados, pilha), arquivos abertos
		execução = conjunto de registradores, (PC, SP, Uso geral, etc), estado de execução
		
		- processo= ambiente + estado de execução = contexto
		- única thread de controle
	
	
	
	'lightweight' 
		ambiente(tabela de processos) = espaço de endereçamento, (código, dados, pilha), arquivos abertos
		execução(tabela de threads) = conjunto de registradores, (PC, SP, Uso geral, etc), estado de execução
		
		- maior concorrência na execução dos processos
		- processo= processo/tafera(ambiente) + thread(estado de execução)
		- as threads do processo compartilham o ambiente(memória, descritores de arquivos, etc)	
		- cada processo possui uma tabela de threads associada
		- troca de contexto somente em respeito à execução
		
		'thread'
			- estados: ready, running, blocked
			- compartilham vars globais, descritores abertos
			- necessita sincronização
			
			'Modelo dispecher/worker' - slide 9
							
							
							
