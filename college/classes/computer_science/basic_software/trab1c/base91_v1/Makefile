# sample makefile
# gcc -std=c99 -o outputfile source.c
CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = outputfile
OBJS = main.o
SRCS = main.c

$(OUTFILE): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)