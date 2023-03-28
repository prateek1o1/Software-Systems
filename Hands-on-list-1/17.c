/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to simulate online ticket reservation.Implement write lock.Write a program to open a file, store a ticket number and exit. Write a separate program, to
 *open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (void) {
	
	int fd;
	struct 
	{
	 int tickets;	
	} T1;
	
	struct flock lock;
        
	fd=open("TicketDatabaseFile",O_RDWR);
    read(fd,&T1,sizeof(T1));
       	
	lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
	lock.l_len=0;
 	lock.l_pid=getpid();
	
	printf("Wating to get into the critical section!\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Current ticket number: %d\n",T1.tickets);
	T1.tickets++;
	lseek(fd,0,SEEK_SET);	
	
	printf("Inside critical section!\n");
	printf("Press any key to unlock!\n");
	write(fd,&T1,sizeof(T1));
	getchar();
	
	lock.l_type=F_UNLCK;
	printf("Unlocked!\n");
	fcntl(fd,F_SETLK,&lock);
	printf("End of the Program!\n");
}
