/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute ls -l | wc.
 *a. use fcntl
*/

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
int main ()
{
int f[2];
pipe(f);
if(!fork())
{
close(1);
fcntl(f[1],F_DUPFD,0);
close(f[0]);
execl("/bin/ls","ls","-l",(char *)0);
}
else
{
close(0);
fcntl(f[0],F_DUPFD,0);
close(f[1]);
execl("/bin/wc","wc",(char *)0);
}
return 0;
}
