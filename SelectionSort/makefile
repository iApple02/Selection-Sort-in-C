CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJ = sort.o file.o generate.o logging.o linkedList.o colour.o newSleep.o
EXEC = sort

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

Sort.o : sort.c
	$(CC) $(CFLAGS) sort.c -c

File.o : file.c
	$(CC) $(CFLAGS) file.c -c

Generate.o : generate.c
	$(CC) $(CFLAGS) generate.c -c

Logging.o : logging.c 
	$(CC) $(CFLAGS) logging.c -c

LinkedList.o : linkedList.c 
	$(CC) $(CFLAGS) linkedList.c -c

colour.o : colour.c
	$(CC) $(CFLAGS) colour.c -c

newSleep.o : newSleep.c
	$(CC) $(CFLAGS) newSleep.c -c

clean :
	rm -f $(EXEC) $(OBJ)
