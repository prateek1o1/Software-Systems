/*Name- Prateek Chhimwal
 *Roll Number- MT2022080 
 *Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
*/
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;

	fd=creat("TemporaryFile",0744);
	printf("fd=%d\n",fd);
	return 0;
}
