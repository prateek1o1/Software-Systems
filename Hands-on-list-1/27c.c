/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute ls -Rl by the following system calls
 c. execle
*/

#include <stdio.h>
#include <unistd.h>
 
int main(void)
{
	const char * env[]={"PATH=/bin/:/usr/bin","TERM=console",0};
 	execle("/bin/ls","ls","-Rl",(char *) 0,(void *) env);
}
