/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
 a. Check the return value of lseek.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (void) {
int fd,valueoflseek;

fd=open("Result10",O_RDWR|O_CREAT,0744);
write (fd,"WRITINGTEN",10);
valueoflseek=lseek(fd,10,SEEK_CUR);
write (fd,"TENWRITING",10);

printf("LSEEK VALUE IS: %d\n",valueoflseek);
}
