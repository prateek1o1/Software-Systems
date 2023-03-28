/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to implement semaphore to protect any critical section.
 *a. rewrite the ticket number creation program using semaphore 
*/

#include <unistd.h>    
#include <stdio.h>     
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h> 
#include <sys/stat.h> 
#include <sys/fcntl.h> 

int  main()
{
	struct 
	{
	 int tickets;	
	} T1;

    int fd;            
    key_t semKey;      
    int semid;  

    fd = open("TicketDatabaseFile", O_CREAT | O_RDWR, S_IRWXU);
    read(fd, &T1, sizeof(T1));

    union semun
    {
        int val;               
        struct semid_ds *buf;  
        unsigned short *array; 
        struct seminfo *__buf; 
    } semSet;

    semKey = ftok(".", 'd');

    semid = semget(semKey, 1, 0); 
    if (semid == -1)
    {
        semid = semget(semKey, 1, IPC_CREAT | 0700); 
        semSet.val = 1;
        semctl(semid, 0, SETVAL, semSet);
    
    }
    
    struct sembuf semOp;
    semOp.sem_num=0;
    semOp.sem_flg=0;
    semOp.sem_op=-1;

    printf("Just before locking\n");
    semop(semid, &semOp, 1);

    printf("Inside locking press any key to unlock!\n");
    T1.tickets+=1;
    lseek(fd, 0, SEEK_SET);
    write(fd, &T1, sizeof(T1));
    
    printf("Ticker number= %d\n", T1.tickets);
    getchar();

    semOp.sem_op = 1;
    semop(semid, &semOp, 1);
    
    printf("Unlocked\n");

    close(fd);

    return 0;
}