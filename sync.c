#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

sem_t *   A,B,C,D;
int main(){
    sem_t *   A=SEM_FAILED;
    sem_t*    B=SEM_FAILED;
    sem_t*    C=SEM_FAILED; 
    sem_t*    D=SEM_FAILED;
    return 0;
}