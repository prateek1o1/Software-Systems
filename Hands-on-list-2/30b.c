/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create a shared memory.
 *b. attach with O_RDONLY and check whether you are able to overwrite.
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/shm.h>   
#include <unistd.h>    
#include <stdio.h>  

int main ()
{
key_t K;      
int SHM_ID;    
ssize_t SHM_SIZE = 20; 
char *S_RDLY;

K = ftok(".", 1);
SHM_ID = shmget(K, SHM_SIZE, IPC_CREAT | 0700); 
S_RDLY = shmat(SHM_ID, (void *)0, SHM_RDONLY);

printf("Shared Memory Identifier is %d\n",SHM_ID);
printf("Enter a string\n");
scanf("%[^\n]",S_RDLY); 
printf("From shared memory: %s\n", S_RDLY); 
return 0;
}
