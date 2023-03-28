/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create an orphan process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
 
int main(void)
{
	if(!fork())
	{
	
	 printf("Child Process!\n");
	 printf("Child Process Process ID: %d\n",getpid());
	 printf("Putting child To Sleep!\n");
	 sleep(3);
	 printf("Child has become Orphan!\n");
	 printf("Child's Parent  Process Process ID: %d\n",getppid());
	}

	else
	{
	 sleep(1);
	 printf("Parent Process!\n");
	 printf("Parent Process Process ID: %d\n",getpid());
	}
}
