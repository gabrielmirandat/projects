CC = gcc
FLAGS = -lncurses -lmenu -lSDL -lSDL_mixer
INC = -I 'include/'
OBJ = engine.o grafico.o jogo.o 
OBJTESTE = unit.o testeunit.o
CPROGS = src/game
CPROGSTESTE = src/test


all: jogo teste

jogo: clear
	$(CC) -Wall -c $(FLAGS) $(INC) -fprofile-arcs -ftest-coverage $(CPROGS)/*.c
	$(CC) -Wall $(OBJ) $(FLAGS) -fprofile-arcs -ftest-coverage -o jogo
	make clean

teste: clear
	$(CC) -Wall -c -lcunit $(FLAGS) $(INC) $(CPROGSTESTE)/*.c $(CPROGS)/engine.c $(CPROGS)/grafico.c
	$(CC) -Wall $(OBJTESTE) engine.o grafico.o -lcunit $(FLAGS) -o teste
	make clean

clean:
	rm -f *.o

clear:	
	clear
	
depurar:
	$(CC) -g -lcunit $(CPROGS)
