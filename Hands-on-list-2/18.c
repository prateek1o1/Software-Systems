/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdlib.h>

int main ()
{
int F[2];
int G[2];
pipe(F);
pipe(G);
if(!fork())
{
	close(F[0]);
	close(G[1]);
	close(G[0]);
	close(1);
	dup2(F[1],1);
	execl("/bin/ls","ls","-l",(char*) 0);
}
else
{       
	if(!fork())
	{
	close(F[1]);
	close(G[0]);
	close(0);
	dup2(F[0],0);
	close(1);
	dup2(G[1],1);
	execl("/bin/grep","grep ^d","^d",(char*) 0);
	}

	else
	{
	close(F[0]);
	close(F[1]);
	close(G[1]);
	close(0);
	dup2(G[0],0);
	execl("/bin/wc","wc",(char*) 0);
	}
}
return 0;
}
