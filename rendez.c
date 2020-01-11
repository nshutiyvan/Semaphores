#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdlib.h>

int main (int argc,char* argv[])
{
    int  process_count = 4;
    sem_t *     semP = SEM_FAILED;
    sem_t *     semGO = SEM_FAILED;
    semP = sem_open("semP",O_CREAT|O_EXCL,3);
    int sem_val =0;
    sem_val = sem_wait(semP);
    if(sem_val != 0)
        printf("Statement 1");
    printf("%d",sem_val); 
    sem_unlink("semP");
       
    return (0);
}