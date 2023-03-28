/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program, call fork and print the parent and child process id.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
if(!fork())
{
	printf("Inside Child Process\n");
	printf("Process ID: %d\n",getpid());
}
else
{

	printf("Inside Parent Process\n");
	printf("Process ID: %d\n",getpid());
}
}
