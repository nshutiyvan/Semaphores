
CR="arm-linux-gcc"
CC="gcc"
FLAGS="-Wall"

OBJS=sem.o sync.o rendez.o

.PHONY:clean all 
all: $(OBJS)
	 $(CC) $(FLAGS) -o Sem sem.o -lrt -pthread 
	 $(CC) $(FLAGS) -o Sync sync.o -lrt -pthread
	 $(CC) $(FLAGS) -o Rendez rendez.o -lrt -pthread
 
sem.o:sem.c
		$(CC) $(FLAGS) -c -o sem.o  sem.c 

sync.o:sync.c
		$(CC) $(FLAGS) -c -o sync.o sync.c

rendez.o:rendez.c
		$(CC) $(FLAGS) -c -o rendez.o rendez.c	
clean:
	rm -rf Sem sem.o Rendez rendez.o Sync sync.o

	