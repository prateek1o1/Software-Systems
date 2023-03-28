/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int main ()
{
int FileDesc;
char Box[]={"Something written to FIFO within 10 seconds!\n"};

FileDesc=open("FifoFor22",O_WRONLY);
write(FileDesc,&Box,sizeof(Box));
close(FileDesc);
return 0;
}