/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
 *Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
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
fd=open("RoomDatabase",O_RDWR);

//READ LOCK
lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();

printf("Before Entering Into Critical Section\n");
fcntl(fd,F_SETLKW,&lock);
printf("Inside The Critical Section....\n");
printf("Enter To Unlock..\n");
getchar();
printf("Unlocked\n");
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("End of Program!\n");
}

