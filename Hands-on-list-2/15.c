/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a simple program to send some data from parent to the child process.
*/

# include <unistd.h>
# include <stdio.h>
int main ()
{
int fd[2];
char store[45];
pipe(fd);

if(!fork())
{
printf("Child Process\n");
close(fd[1]);
read(fd[0],store,sizeof(store));
printf("%s\n",store);
}
else
{
printf("Parent Process\n");
close(fd[0]);
write(fd[1],"Greeting, A Message From Your Parent!\n",37);
}
return 0;
}
