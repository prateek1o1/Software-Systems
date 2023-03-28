/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
int main(void)
{
	int childone,childtwo,childthree;
	if(!(childone=fork()))
	{
		sleep(3);
	}
	else
	{
	if(!(childtwo=fork()))
	{
		sleep(6);
	}
	else
	{
	if(!(childthree=fork()))
	{ 
		sleep(9);
	}
	else
	{       printf("Parent Waiting for Childthree\n");
	       	waitpid(childthree,NULL,0);
	}
	}
	}
}
