int execl(char *path, char *argv[0], char *argv[1],..., (char *) 0);
	- mantem o pid, o ppid, os parâmetros do escalonador, o real uid, os descritores de arquivos abertos
	- são alteradas a imagem do processo na memória, o conjunto de registradores e o uid efetivo

- quando um processo pai morre, filhos passam a ser filhos do init	
- wait serve para avisar o pai da morte de um filho
- se filho morre mas não avisa o pai, é um processo em estado "morrendo", ou um "zombie", ou "defunct"
	
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

// Código
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
escalonador:// cria memoria compartilhada, estrutura da fat tree, semaforo
```
-- define sinal
void (*signal(sig, func))()
signal(SIGTERM, onExitSignal); // Sent by OS to end this process
signal(SIGINT,  onExitSignal); // Ctrl + C from terminal
signal(SIGQUIT, onExitSignal); // Ctrl + \ from terminal
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
executa_postergado:// faz pedido na memoria compartilhada
```
-- obtem mem compartilhada
int shmget(key_t key, int size, int shmflg);
int shmId = shmget(KEY_JOB_REQUEST_POOL_MEM, sizeof(JobRequestPool), 0700);
-- mapeia segmento de mem
char *shmat(int shmid, char *shmaddr, int shmflg);
void* ptr = shmat(shmId, NULL, 0);
-- desfaz mapeamento de mem
int shmdt(int shmid);
if (shmdt(jrp) == -1)
-- suspende execução por minimo segundos
int sleep( unsigned seconds)
sleep(1);	
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
shutdown:// solicita fim do escalonador, seta na memoria compartilhada
```
-- obtem mem compartilhada
int shmget(key_t key, int size, int shmflg);
int shmId = shmget(KEY_JOB_REQUEST_POOL_MEM, sizeof(JobRequestPool), 0700);
-- mapeia segmento de mem
char *shmat(int shmid, char *shmaddr, int shmflg);
void* ptr = shmat(shmId, NULL, 0);
-- desfaz mapeamento de mem
int shmdt(int shmid);
if (shmdt(jrp) == -1)
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
consts:// define valores de chave e outros
```
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
execution_manager:// um nodo da arvore
```
-- envia sinal ao processo
int kill (pid_t pid, int sig);
kill(manager->childProcesses[i], SIGKILL);
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
fat_tree:// estrutura da fat tree
```
-- cria pipe
int pipe(int fd[2]);
if (pipe(creationSuccessPipe) == -1)
-- escreve no pipe
int write(int fd, char *buf, int nbyte);
writeResult = write(creationSuccessPipe[1], &nodeCreationResult, sizeof(nodeCreationResult));
-- le do pipe
int read(int fd, char *buf, int nbyte);
readResult = read(creationSuccessPipe[0], &nodeCreationResult + bytesReceived, sizeof(nodeCreationResult) - bytesReceived);
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
fat_tree_brigde:// ponte da fat tree (para arvore gorda), tem 1,2,3 canais (comunicação dual-flex), tem 2 pipes (4 desc)
```
-- cria pipe
int pipe(int fd[2]);
if (pipe(pipes + i * 2) == -1)
-- escreve no pipe
int write(int fd, char *buf, int nbyte);	
result = write(bridge->pipes[pipeIndex], (const char*)buffer + writtenBytes, bufferLength - writtenBytes);	
-- le do pipe
int read(int fd, char *buf, int nbyte);
readBytes = read(bridge->pipes[pipeIndex], outBuffer, maxCharacters);
-- le do pipe
int read(int fd, char *buf, int nbyte);
readBytes = read(readFd, outBuffer, maxCharacters);
-- manipula descritor de arquivo
int fcntl(int fd, int cmd, ... /* arg */ );
int fStatus = fcntl(readFd, F_GETFL);
if (fcntl(readFd, F_SETFL, fStatus | O_NONBLOCK) == -1)
fcntl(readFd, F_SETFL, pipeFlags & (~O_NONBLOCK));
fcntl(readFd, F_SETFL, pipeFlags);
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
linked_list:// jobs que terminaram de executar
```
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
lock:// semaforo para acessar memoria compartilhada
```
-- cria semaforo
int semget(key_t key, int nsems, int IPC_CREAT | semflg);
int semId = semget(semaphore_key, 1, IPC_CREAT | IPC_EXCL | 0700);
-- obtem semaforo
int semget(key_t key, int nsems, int semflg);
int semId = semget(semaphore_key, 1, 0700);
-- realiza operacao em semaforo
int semop(int semid, struct sembuf *sops, int nsops);
result = semop(lock, &operation, 1);
-- remove semaforo
int semctl(int shmid, int semnum, int IPC_RMID, union semun{ val; struct semid_ds *buf; ushort *array;} arg; shmid_ds *buf);
else if (semctl(semId, 0, SETVAL, semVal) == -1)
if (semctl(lock, 0, IPC_RMID) == -1)	
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
priority_queue:// jobs a serem mandados executar de acordo com prioridade/ jobs nunca executados
```
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
protocol:// formato da mensagem nos pipes
```
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
scheduler:// implementaçao do escalonador
```
-- cria mem compartilhada
int shmget(key_t key, int size, int IPC_CREAT | shmflg);
int shmId = shmget(KEY_JOB_REQUEST_POOL_MEM, sizeof(JobRequestPool), IPC_CREAT | IPC_EXCL | 0700);
-- mapeia segmento de mem
char *shmat(int shmid, char *shmaddr, int shmflg);
void* ptr = shmat(shmId, NULL, 0);
-- desfaz mapeamento de mem
int shmdt(int shmid);
if (shmdt(jrp) == -1)
-- remove segmento de mem
int shmctl(int shmid, IPC_RMID, struct shmid_ds *buf);
if (shmctl(shmId, IPC_RMID, NULL) == -1)
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
utils:// funcoes utilitarias
```
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -


















