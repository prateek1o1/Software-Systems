/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to find out the opening mode of a file. Use fcntl.
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main (void) {
int fd, returnflag;

fd=open("Result12",O_CREAT|O_RDWR,0744);
returnflag=fcntl(fd,F_GETFL);

switch(returnflag & O_ACCMODE)
{

case(0): printf("Access Mode- O_RDONLY\n");
	  break;
case(1): printf("Access Mode- O_WRONLY\n");
	  break;
case(2): printf("Access Mode- O_RDWR\n");
	  break;
case(64): printf("Access Mode- O_CREAT\n");
	  break;
}

close(fd);
}
