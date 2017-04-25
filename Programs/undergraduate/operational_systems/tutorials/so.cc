// mostra os proc em background
$ps -l 


COMUNICACAO
•  Pipes;
•  Filas de mensagens;
•  Memória compartilhada;
•  Semáforos;
•  Sinais


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

MOTIVOS DE BLOQUEIO:
•  P:  esperando que a página corrente seja carregada
•  D:  esperando I/O
•  T:  parado por um utilitário de debug
•  S:  dormindo por poucos segundos
•  I:  dormindo por muitos segundos

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
•  SIGVTALRM 	26
•  SIGPROF 		27
•  SIGWINCH 	28
•  SIGLOST 		29
•  SIGUSR1 		30
•  SIGUSR2 		31

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
	retorna 0, senão -1
- 'recebe'
	int msgrcv(int msgid, struct msgbuf *msgp, int msgsize, long msgtyp, int msgflg);
	recebe mensagem de tipo 'msgtyp' de tamanho 'msgsize' da fila 'msgid' com flags de bloqueio 'msgflg' em 'msgbuf'
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
	mapeia segmento 'shmid' no endereço 'shmaddr' escolhido pelo sistema ou programador
	com modo de acesso 'shmflg'
	retorna endereço do segmento, senão -1
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
- cria conjunto de sems (semid), obtém id, executa operações, remove identificador
- 'includes'
	#include <sys/types.h>
	#include <sys/ipc.h>
  	#include <sys/sem.h>
- 'cria'
	int semget(key_t key, int nsems, int IPC_CREAT | semflg);
	cria conjunto de 'nsems' com chave 'key' e permissoes 'semflg'
- 'operacoes'
	int semop(int semid, struct sembuf *sops, int nsops);
	executa conjunto de operacoes descritas em 'sembuf' sobre semaforos 'semid' 
	pelo numero de vezes 'nsops'
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
- ocorre desvio de execução para a rotina de tratamento
- a interrupção pode chegar a qualquer momento
- 'includes'
	#include <signal.h>
	void (*signal(sig, func))()		// apenas associa sinal a uma funcao
	void (*func)(); 				// define funcao de tratamento
	retorna a ação tomada anteriormente, senão -1
- 'envio'
	int kill (pid_t pid, int sig);
	envia sinal 'sig' ao processo 'pid'
	retorna 0, senão -1
- 'alarm'
	unsigned int alarm(unsigned int seconds)
	envia SIGALARM ao processo que o chamou depois de 'seconds' segundos
	retorna o tempo que faltava para o 'alarm' anterior
- 'pause'
	int pause( )
	pára o processo até que um sinal seja recebido
	retorna 0, senão -1
- 'sleep'
	int sleep( unsigned seconds)
	suspende a execução do processo por no mínimo seconds segundos.
	retorna num de segundos que o processo deixou de dormir