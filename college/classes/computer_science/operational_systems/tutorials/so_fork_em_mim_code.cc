escalonador:// cria memoria compartilhada, estrutura da fat tree, semaforo
```
-- define sinal
void (*signal(sig, func))()
signal(SIGTERM, onExitSignal); // Sent by OS to end this process
signal(SIGINT,  onExitSignal); // Ctrl + C from terminal
signal(SIGQUIT, onExitSignal); // Ctrl + \ from terminal
// onExitSignal - seta userCancelled = 1;
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
executa_postergado:// faz pedido na memoria compartilhada
```
-- obtem mem compartilhada
int shmget(key_t key, int size, int shmflg);
int shmId = shmget(KEY_JOB_REQUEST_POOL_MEM, sizeof(JobRequestPool), 0700);
// 0700 - usa setuid setado, permissao owner, remove permissao de grupo, remove permissao do mundo
-- mapeia segmento de mem
char *shmat(int shmid, char *shmaddr, int shmflg);
void* ptr = shmat(shmId, NULL, 0);
// NULL - sistema escolhe endereço
// 0 - sem flags
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
// 0700 - usa setuid setado, permissao owner, remove permissao de grupo, remove permissao do mundo
-- mapeia segmento de mem
char *shmat(int shmid, char *shmaddr, int shmflg);
void* ptr = shmat(shmId, NULL, 0);
// NULL - sistema escolhe endereço
// 0 - sem flags
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
// manager->childProcesses[i] - ids de todos os processos filhos do gerenciador caso exista mais de um
-- waitpid
pid_t waitpid(pid_t pid, int *stat_loc, int options);
pid = waitpid(-1, &status, blocking ? 0 : WNOHANG);
// pid - pid do filho que passou
// -1  - espera qualquer filho
// status - status de execução desse filho
// 0 - bloqueia ate status pronto
// WNOHANG - no bloqueia
// se -1 e 0 vira um wait normal
-- wait comum
pid_t wait(int *wstatus);
while (wait(NULL) == -1 && errno == EINTR);
// NULL - ignora status do filho
// retorna pid do filho, -1 se erro
// EINTR - chegou sinal
-- execl
int execl(const char *path, const char *arg, ...);
if (execl(job->programPath, getFilenameFromPath(job->programPath), (char*)NULL) == -1)
// job->programPath - caminho do executavel
// getFilenameFromPath(job->programPath) - primeiro argumento é o proprio nome
// (char*)NULL) - indica fim do parametros
// so retorna se houve erro
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
fat_tree:// estrutura da fat tree
```
-- cria pipe
int pipe(int fd[2]);
if (pipe(creationSuccessPipe) == -1)
// apenas para escalonador saber se fat tree criada com sucesso
-- escreve no pipe
int write(int fd, char *buf, int nbyte);
writeResult = write(creationSuccessPipe[1], &nodeCreationResult, sizeof(nodeCreationResult));
// creationSuccessPipe[1] - descritor de escrita
-- le do pipe
int read(int fd, char *buf, int nbyte);
readResult = read(creationSuccessPipe[0], &nodeCreationResult + bytesReceived, sizeof(nodeCreationResult) - bytesReceived);
// creationSuccessPipe[0] - descritor de leitura
// bytesReceived - para receber resposta do numero total de nos da arvore
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
fat_tree_brigde:// ponte da fat tree (para arvore gorda), tem 1,2,3 canais (comunicação dual-flex), tem 2 pipes (4 desc)
```
-- cria pipe
int pipe(int fd[2]);
if (pipe(pipes + i * 2) == -1)
  // pipes + i * 2 - para criar dois pipes por canal, duplex
-- escreve no pipe
int write(int fd, char *buf, int nbyte);	
result = write(bridge->pipes[pipeIndex], (const char*)buffer + writtenBytes, bufferLength - writtenBytes);	
// eh blocante! Nao para pra sinal, so retorna quando todo dado tiver sido copiado
// bridge->pipes[pipeIndex] - escreve no pipe certo da bridge
// buffer + writtenBytes - copia ate todo o tamanho do buffer
-- le do pipe
int read(int fd, char *buf, int nbyte);
readBytes = read(bridge->pipes[pipeIndex], outBuffer, maxCharacters);
// nao blocante! Se nao tem dado pra ler, retorna -1
// bridge->pipes[pipeIndex] - le toda mensagem do pipe certo da bridge
// outBuffer - buffer de saida
readBytes = read(readFd, outBuffer, maxCharacters);
// eh blocante! Retorna -1 se erro
-- manipula descritor de arquivo
int fcntl(int fd, int cmd, ... /* arg */ );
int fStatus = fcntl(readFd, F_GETFL);
// F_GETFL - retorna modo de acesso e status das flags
if (fcntl(readFd, F_SETFL, fStatus | O_NONBLOCK) == -1)
// F_SETFL - seta status das flags 
// O_NONBLOCK - atribui descritor de leitura como nao-blocante
fcntl(readFd, F_SETFL, pipeFlags & (~O_NONBLOCK));
// F_SETFL - seta status das flags 
// ~O_NONBLOCK - atribui descritor de leitura como blocante
fcntl(readFd, F_SETFL, pipeFlags);
// F_SETFL - seta status das flags 
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
// 1 - cria so um semaforo
// IPC_EXCL - se semaforo ja existe para key semget() falha com errno EEXIST
// 0700 - usa setuid setado, permissao owner, remove permissao de grupo, remove permissao do mundo
-- obtem semaforo
int semget(key_t key, int nsems, int semflg);
int semId = semget(semaphore_key, 1, 0700);
-- realiza operacao em semaforo
int semop(int semid, struct sembuf *sops, int nsops);
result = semop(lock, &operation, 1);
// lock - id do sem
// operation - estrutura da operaçao
// dois tipos, acquireLock(lock) seta operation.sem_op -1 e releaseLock(lock) seta operation.sem_op 1
-- configura semaforo
int semctl(int shmid, int semnum, int IPC_RMID, union semun{ val; struct semid_ds *buf; ushort *array;} arg; shmid_ds *buf);
else if (semctl(semId, 0, SETVAL, semVal) == -1)
// SETVAL - seta o valor do semaforo pra 1
if (semctl(lock, 0, IPC_RMID) == -1)	
// IPC_RMID - remove semaforo
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
// IPC_EXCL - se segmento ja existe para key shmget() falha com errno EEXIST
// 0700 - usa setuid setado, permissao owner, remove permissao de grupo, remove permissao do mundo
-- mapeia segmento de mem
char *shmat(int shmid, char *shmaddr, int shmflg);
void* ptr = shmat(shmId, NULL, 0);
// NULL - sistema escolhe endereço
// 0 - sem flags
-- desfaz mapeamento de mem
int shmdt(int shmid);
if (shmdt(jrp) == -1)
-- remove segmento de mem
int shmctl(int shmid, IPC_RMID, struct shmid_ds *buf);
if (shmctl(shmId, IPC_RMID, NULL) == -1)
// IPC_RMID - para remover segmento
-- waitpid
pid_t waitpid(pid_t pid, int *stat_loc, int options);
if (waitpid(-1, NULL, WNOHANG) == -1 && errno != EINTR)
// retorno -1 indica que foi interrompido por sinal
// WNOHANG - passa sem esperar status pronto
// errno != EINTR - não foi interrupção
```
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- - -- -- -- - -- -- -- - - ---- - -- -- - -- -- - -- -- - -- - -- -- - -
utils:// funcoes utilitarias
```
```
