/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to run a script at a specific time using a Daemon process.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int init_daemon (void){
	if(!fork()) 
	{
		setsid();
		chdir("/");
		umask(0);
		time_t curr,run;
		run=time(&curr)+5;
		
		printf("Hello I Will Run At: %s",ctime(&run));
		
		do{
		time(&curr);	
		}
		while(curr!=run);
		
		printf("Greeting! Hello\n");
		return 0;
	}
	else
	{
		exit(0);		
	}
}
void main(void)
{
	init_daemon();
}
