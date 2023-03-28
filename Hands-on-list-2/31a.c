/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create a semaphore and initialize value to the semaphore.
 *a. create a binary semaphore
*/

#include <unistd.h>    
#include <stdio.h>     
#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h> 

void main()
{
    key_t K;
    int SEM_ID;

    union semun {
        int val; 
    } semSet;

    K = ftok(".", 5);
    
    SEM_ID = semget(K, 1, IPC_CREAT | 0777);
    semSet.val = 1;
    semctl(SEM_ID, 0, SETVAL, semSet);
}