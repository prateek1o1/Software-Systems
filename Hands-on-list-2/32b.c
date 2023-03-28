/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to implement semaphore to protect any critical section.
 *b. protect shared memory from concurrent write access
*/

#include <unistd.h>    
#include <stdio.h>     
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h> 
#include <sys/shm.h>

void main()
{
    key_t semKey;      
    int semid;    
    key_t shmKey;         
    int shmid;    
    ssize_t shmSize = 30; 
    char *Data;

    // Semaphore
    union semun
    {
        int val;               
        struct semid_ds *buf;  
        unsigned short *array; 
        struct seminfo *__buf; 
    } semSet;

    semKey = ftok(".", 3321);
    semid = semget(semKey, 1, 0); 
    if (semid == -1)
    {
        semid = semget(semKey, 1, IPC_CREAT | 0700); // Create a new semaphore
        semSet.val = 1;
        semctl(semid, 0, SETVAL, semSet);
    }

    
    shmKey = ftok(".", 3322);//Shared Memory
    shmid = shmget(shmKey, shmSize, IPC_CREAT | 0700);
    Data = shmat(shmid, (void *)0, 0);


    struct sembuf semOp; 
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Before entering critical section!\n");
    semOp.sem_op = -1;
    semop(semid, &semOp, 1);
    
    printf("Inside critical section!\n");
    printf("Enter something in the shared memory!\n");
    scanf("%[^\n]",Data);

    printf("What's in shared memory!\n");

    printf("%s\n", Data);

    printf("Press enter to exit the critical section!\n");

    semOp.sem_op = 1;
    semop(semid, &semOp, 1);

    printf("Unlocked!\n");
}