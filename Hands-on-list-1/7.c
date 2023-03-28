/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
char list[1000];
int fd,HowMuchRead;

fd=open("File",O_RDONLY);
HowMuchRead=read(fd,list,sizeof(list));

close(fd);

fd=open("CopyFile",O_CREAT|O_WRONLY,0744);
write(fd,list,HowMuchRead);

close(fd);

}
