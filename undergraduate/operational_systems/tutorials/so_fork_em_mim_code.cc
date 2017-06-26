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
