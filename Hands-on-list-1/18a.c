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
struct 
{
int room;
int people;
} R;

int number;
char c;
printf("Which Room To Enter?\n");
scanf("%d",&number);

struct flock lock;
int fd;
fd=open("RoomDatabase",O_RDWR);
read(fd,&R,sizeof(R));

//WRITE LOCK
lock.l_type=F_WRLCK;
lock.l_whence=SEEK_SET;
lock.l_start=(number-1)*sizeof(R);
lock.l_len=sizeof(R);
lock.l_pid=getpid();

lseek(fd,(number-1)*sizeof(R),SEEK_SET);
read(fd,&R,sizeof(R));
printf("Before Entering Into Critical Section\n");

fcntl(fd,F_SETLKW,&lock);
printf("Number of People in the Room: %d\n",R.people);
R.people++;
lseek(fd,(-1)*sizeof(R),SEEK_CUR);
printf("Inside The Critical Section....\n");
printf("Enter To Unlock..\n");
write(fd,&R,sizeof(R));
scanf(" %c",&c);
printf("Unlocked\n");
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("FINISH\n");
}

