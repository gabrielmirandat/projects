'Threads'
ptheads 	-> padrão POSIX (Portable Operation System Interface)
<pthread.h> -> todas as funções threads e tipos de dados
-lpthread 	-> linha de comando

'Criação de threads'
tipo pthread_t 	-> pthread_t thread_id;
				-> identificador da thread

thread function	-> void* print_xs (void* unused)
				-> código a ser executado após a criação de uma thread -> parâmetro void* e retorno void*

pthread_create  -> pthread_create (&thread_id/*thread_pointer*/, NULL/*object_pointer*/, &print_xs/*function_pointer*/, NULL/*function_args*/);
				-> cria thread.

compile	-> gcc CriandoThread.c -o CriandoThread -lpthread

'Passando dados para threads'
thread_args	-> struct char_print_parms thread1_args; pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
			-> é void*. Necessita struct de tipos para cada função thread. Passagem por ponteiro.

'Juntando threads'
pthread_join	-> pthread_join (thread1_id/*thread_ID*/, NULL/*return_pointer*/);
				-> impede que a main termine antes de determinada thread. Como um wait.

'Cancelando threads'
pthread_cancel	-> pthread_cancel(a_thread/*thread_ID*/);
				-> cancela uma thread.

pthread_exit	-> destrói thread.

'Sincronização de threads (possibilidade de 2 threads usarem o mesmo recurso)'
'Semaphore'

semáforos -> gerenciador de tráfego (vias são trechos do código). 
		  -> Atuam como “porteiros” controlando o acesso de 'n' threads a um recurso.

mutexes   -> 'mutual exclusion' -> bloqueador de trechos de códigos. 
		  -> Indicados para travar (lock) acesso a um recurso comum sendo geralmente utilizados para sincronizar dois threads.

'Semáforos POSIX'
<semaphore.h>	-> todas as funções e tipos para semáforos. Semáforo é uma lista dinâmica de threads.

sem_t s;		-> tipo semáforo

sem_init		-> int sem_init(sem_t *sem/*semaphore_pointer*/, int pshared/*isShared - +de1thread?*/, unsigned int value/*initial_value*/);
				-> inicia semáforo com valor inicial.

sem_wait	-> int sem_wait(sem_t *s/*semaphore_pointer*/);
			-> operação P. Bloqueia thread. Decrementar/aguardar. Processo crítico.

sem_post	-> int sem_post(sem_t *s/*semaphore_pointer*/);
			-> operação V.Incrementa semáforo.A primeira thread da fila do semáforo é desbloqueada. 
			-> Incrementar/liberar. Processo não crítico.

sem_destroy	-> sem_destroy(&bin_sem/*semaphore_pointer*/);
			-> destrói semáforo

'Mutex'

pthread_mutex_t	-> pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
				-> variável mutex com inicialização de mutex
				-> PTHREAD_MUTEX_INITIALIZER = mutex deste tipo suspende indefinidamente a thread que tenta usá-lo recursivamente. Default.
				-> PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP = solicitação feita pela thread “dona” do mutex provoca um erro (EDEADLK).
				-> PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP = mutex recursivo

pthread_mutex_init    -> pthread_mutex_init(&lock/*mutex_pointer*/, NULL);
				      -> manual

pthread_mutex_lock    -> pthread_mutex_lock(&mutex/*mutex_pointer*/);
				      -> para thread requisitar trava. Se mutex livre, thread passa a ser dona, senão, espera sua vez.

pthread_mutex_trylock -> O mesmo. Mas não bloqueia a thread se o mutex estiver travado. Ao invés disso, ela retorna um código de erro (EBUSY).

pthread_mutex_unlock  -> pthread_mutex_unlock(&mutex);
				      -> libera mutex.

pthread_mutex_destroy -> pthread_mutex_destroy(&mutex)
				      -> destrói mutex.







