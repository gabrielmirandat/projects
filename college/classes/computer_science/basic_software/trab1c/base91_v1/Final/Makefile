# sample makefile
# gcc -std=c99 -o outputfile source.c
CC = gcc
CFLAGS = -Wall -std=c99
OUTFILE = outputfile
OBJS = basE91.o
SRCS = basE91.c

$(OUTFILE): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)