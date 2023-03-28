/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
 
int main(void)
{
int fd;
fd=open("Result22",O_CREAT | O_RDWR,0744);
if(!fork ())
{
write(fd,"I AM CHILD\n",10);
}
else
{
write(fd,"I AM PARENT",11);
}
close(fd);
}
