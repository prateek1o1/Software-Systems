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
	
	T1.tickets=10;

	fd=open ("TicketDatabaseFile",O_CREAT|O_RDWR,0744);
	write(fd,&T1,sizeof(T1));
	close(fd);
	
	fd=open("TicketDatabaseFile",O_RDONLY);
	read(fd,&T1,sizeof(T1));
	printf("Ticket= %d\n",T1.tickets);
	close(fd);
}
