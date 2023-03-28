/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor. 
*/

# include <unistd.h>
# include <stdio.h>
int main ()
{

int X[2];
char store[11];

pipe(X);
write(X[1],"Hello World",11);
read(X[0],store,sizeof(store));
printf("%s\n",store);
return 0;
}
