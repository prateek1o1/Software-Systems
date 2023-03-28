/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
 c. use fcntl
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main (void) {
int fdone,fdtwo,length;
char storage[100];

strcpy(storage,"USING FCNTL()\n");
length=strlen(storage);

fdone=open("Result11C",O_CREAT|O_RDWR,0744);
fdtwo=fcntl(fdone,F_DUPFD,0);
write(fdone,storage,length);
write(fdtwo,storage,length);

close(fdone);
close(fdtwo);
}
