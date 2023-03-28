/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to implement semaphore to protect any critical section.
 *d. remove the created semaphore 
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    key_t K;
    int semid;

    K = ftok(".", 'a');
    semid = semget(K, 1, IPC_CREAT | 0777);
  
    printf("Deleting the semaphore!\n");
    semctl(semid, 0, IPC_RMID);
}