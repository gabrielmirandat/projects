CC = gcc
CFLAGS = -Wall
SRC = src
INC = -I 'include/'
CPROGS = src/project
OPROGS = projeto1mp.o projeto1mpteste.o
CPROGSTEST = src/test
OPROGSTEST = unit.o testeunit.o

all: projeto1mp teste

projeto1mp: clear
	$(CC) $(CFLAGS) -c $(INC) $(CPROGS)/*.c
	$(CC) $(CFLAGS) $(OPROGS) -o projeto1mp
	make clean

teste: clear
	$(CC) $(CFLAGS) -c $(INC) -lcunit $(CPROGS)/projeto1mp.c $(CPROGSTEST)/*.c
	$(CC) $(CFLAGS) projeto1mp.o $(OPROGSTEST)  -lcunit -o teste
	make clean

depurar: clear
	$(CC) -g -lcunit $(INC) $(CPROGS)/projeto1mp.c $(CPROGSTEST)/*.c 

clean:
	@rm -f *.o

clear:
	clear



	
