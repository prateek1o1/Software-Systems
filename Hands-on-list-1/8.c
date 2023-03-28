/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to open a file in read only mode, read line by line and display each line as it is read.Close the file when end of file is reached.
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (void) {
int fd;
char Reader;
fd=open("File",O_RDONLY);
while(read(fd,&Reader,1))
{

if(Reader == '\n')
getchar();
else
write(1,&Reader,1);
}
close(fd);
}
