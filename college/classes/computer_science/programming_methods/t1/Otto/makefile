CC = gcc
CFLAGS = -Wall
DEPS = lista.h unit.h
OBJ = lista.o unit.o testeunit.o
CPROGS = lista.c unit.c testeunit.c

teste:
	$(CC) $(CFLAGS) -c -lcunit $(CPROGS)
	$(CC) $(CFLAGS) $(OBJ) -lcunit -o teste

clean:
	rm -f *.o
	rm teste
	
depurar:
	$(CC) -g -lcunit $(CPROGS)

teste2:
	$(CC) $(CFLAGS) -c lista.c suamain.c
	$(CC) $(CFLAGS) lista.o suamain.o -o nomedoprograma