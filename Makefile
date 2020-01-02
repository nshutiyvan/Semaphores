
CR="arm-linux-gcc"
CC="gcc"
FLAGS="-Wall"

OBJS=sem.o sync.o

.PHONY:clean all
all: $(OBJS)
	 $(CC) $(FLAGS) -o Sem sem.o -lrt -pthread 
	 $(CC) $(FLAGS) -o Sync sync.o -lrt -pthread
 
sem.o:sem.c
		$(CC) $(FLAGS) -c -o sem.o  sem.c 

sync.o:sync.c
		$(CC) $(FLAGS) -c -o sync.o sync.c

clean:
	rm -rf Sem sem.o
