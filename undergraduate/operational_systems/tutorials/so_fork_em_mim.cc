
int execl(char *path, char *argv[0], char *argv[1],..., (char *) 0);
	- mantém PID, PPID, parâmetros do processo filho dado pelo fork

- quando um processo pai morre, filhos passam a ser filhos do init	
- wait serve para avisar o pai da morte de um filho
- se filho morre mas não avisa o pai, é um processo em estado "morrendo", ou um "zombie", ou "defunct"

