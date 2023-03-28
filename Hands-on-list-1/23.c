/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create a Zombie state of the running program.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h> 
int main(void)
{
if(!fork())
{
	printf("Child Process= %d\n",getpid());
	printf("Child Terminated!\n");
	exit(0);
}
else
{
	printf("Parent Process= %d\n", getpid());
	sleep(20);
	printf("Parent Process is Awake!\n");
}
}
