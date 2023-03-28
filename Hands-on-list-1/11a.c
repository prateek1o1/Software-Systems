/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
 a. use dup
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main (void) {
int fdone,fdtwo,length;
char storage[100];
strcpy(storage,"Using DUP()\n");
length=strlen(storage);

fdone=open("Result11A",O_CREAT|O_RDWR,0744);
fdtwo=dup(fdone);

write(fdone,storage,length);
write(fdtwo,storage,length);

close(fdone);
close(fdtwo);
}
