/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to perform mandatory locking.
 a. Implement write lock
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (void) {
struct flock lock;
int fd;

fd=open("DataFile",O_CREAT|O_RDWR);

lock.l_type=F_WRLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();

printf("Waiting To Enter Into The Critical Section!\n");
fcntl(fd,F_SETLKW,&lock);

printf("Inside The Critical Section!\n");
printf("Enter Key To Unlock!\n");
getchar();

printf("Unlocked\n");
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);

printf("FINISH\n");
}

