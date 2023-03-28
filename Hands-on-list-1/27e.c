/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute ls -Rl by the following system calls
 e. execvp
*/

#include <stdio.h>
#include <unistd.h>
 
int main(void)
{
	char * argv[]={"ls","-Rl",0};
	
	execvp("ls",(void *) argv);
}
