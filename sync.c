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

int main (void)
{
    pid_t   n1;      /* Process ID from fork() */
    pid_t   n2;      /* Process ID from fork() grand childreen  */
    

    printf ("%d main  start\n", getpid());



    char nameA[] = "nameAAA";
    char nameB[] = "nameBBB";
    char nameC[] = "nameCCC";
    char nameD[] = "nameDDD";

    sem_t *     semdA = SEM_FAILED;
    sem_t *     semdB = SEM_FAILED;
    sem_t *     semdC = SEM_FAILED;
    sem_t *     semdD = SEM_FAILED;

    
   
    semdA = sem_open(nameA, O_CREAT | O_EXCL, 0600, 0);
    semdB = sem_open(nameB, O_CREAT | O_EXCL, 0600, 0);

    semdC = sem_open(nameC, O_CREAT | O_EXCL, 0600, 0);
    semdD = sem_open(nameD, O_CREAT | O_EXCL, 0600, 0);

  

    n1 = fork(); 
    n2 = fork(); 
  
    if (n1 > 0 && n2 > 0) { 
        
        printf("A:%d \n", 1); 
        sem_post(semdA);
        sem_wait(semdD);
        printf("A:%d \n", 5);
        sem_post(semdA); 
    } 

    else if (n1 == 0 && n2 > 0) 
    { 
       sem_wait(semdA);
       printf("B:%d \n", 2);        
       sem_post(semdB);
       sem_wait(semdA);
       printf("B:%d \n", 6);
        sem_post(semdB); 
    } 


    else if (n1 > 0 && n2 == 0) 
    {   
        sem_wait(semdB);
        printf("C:%d \n", 3); 
        sem_post(semdC);
        sem_wait(semdB);
        printf("C:%d \n", 7);
        sem_post(semdC); 
    } 


    else {
        sem_wait(semdC); 
        printf("D:%d \n", 4);
        sem_post(semdD);
        sem_wait(semdC); 
        printf("D:%d \n", 8);
        sem_post(semdD); 

        sem_unlink(nameA);
        sem_unlink(nameB);
        sem_unlink(nameC);
        sem_unlink(nameD);

        sem_destroy(semdA);
        sem_destroy(semdB);
        sem_destroy(semdC);
        sem_destroy(semdD);
    } 
    // printf ("%d main  exit\n", getpid());
    return (0);
}