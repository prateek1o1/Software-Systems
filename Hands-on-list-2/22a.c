/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
#include <errno.h>

int main ()
{
int retval;
fd_set FileSet;
struct timeval timming;
int FileDesc;

//char WriteBox[]={"PROGRAM 1!\n"};
char ReadBox[100];

mkfifo("FifoFor22",0666);
FileDesc=open("FifoFor22",O_RDWR);

FD_ZERO(&FileSet);
FD_SET(FileDesc,&FileSet);

timming.tv_sec = 10;
timming.tv_usec = 0;
retval=select(FD_SETSIZE, &FileSet, NULL, NULL, &timming);

   if(retval==-1)
	  perror("select()\n");
  else if(retval)
    {
      read(FileDesc,&ReadBox,sizeof(ReadBox));
      printf("%s",ReadBox);
    }
  else
	  printf("Timeout\n");
  
close(FileDesc);

return 0;
}
