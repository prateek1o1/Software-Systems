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
	
	int item,fd;
	
	struct 
	{
	 int room;
	 int people;	 
	} R[3];
	
	for(item=0;item<3;item++){
	R[item].people=0;
	R[item].room=item+1;
	}
	
	fd=open("RoomDatabase",O_CREAT|O_RDWR,0744);
	write(fd,R,sizeof(R));
	close(fd);
}
