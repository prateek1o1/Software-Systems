/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to implement semaphore to protect any critical section.
 *c. protect multiple pseudo resources (may be two) using counting semaphore
*/

#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

void main(){
int key,semid;
int fd1,fd2;
int a;
fd1=open("Resource1", O_CREAT | O_RDWR, S_IRWXU);
fd2=open("Resource2", O_CREAT | O_RDWR, S_IRWXU);
  union semun
    {
        int val;               
        struct semid_ds *buf;  
        unsigned short *array; 
        struct seminfo *__buf; 
    } semSet;
key = ftok(".",'h');

semid = semget(key,2,0);
    if (semid == -1)
    {
        semid = semget(key, 2, IPC_CREAT | 0700); 
        semSet.val = 1;
        semctl(semid, 0, SETVAL, semSet);
    
    }


struct sembuf s[2];
    s[0].sem_num=0;
    s[0].sem_flg=0;
    s[1].sem_num=0;
    s[1].sem_flg=0;

printf("Locking semaphore1\n");
s[0].sem_op=-1;
semop(semid,&s[0],1);
printf("Inside critical section :----semaphore1\n");
scanf("%d",&a);
write(fd1,"Accessing First Resource",24);
s[0].sem_op = 1;
semop(semid,&s[0],1);
printf("semaphore1 unlocked\n");

printf("Locking semaphore2\n");
s[1].sem_op=-1;
semop(semid,&s[1],1);
printf("Inside critical section :----semaphore2\n");
scanf("%d",&a);
write(fd2,"Accessing Second Resource",25);
s[1].sem_op = 1 ;
semop(semid,&s[1],1);
printf("semaphore 2 unlocked\n");
}