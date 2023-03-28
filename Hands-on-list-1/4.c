/*Name- Prateek Chhimwal
 *Roll Number- MT2022080 
 *Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
	int fd;

	fd=open("TemporaryFile",O_RDWR|O_EXCL,0744); //O_EXCL Fail if the file does exist and O_CREAT is set.
	printf("fd=%d\n",fd);
	printf("errno=%d\n",errno);
	return 0;
}
