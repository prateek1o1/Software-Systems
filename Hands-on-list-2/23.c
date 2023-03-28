/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer). 
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

int main ()
{
long MaximumNoOfFiles;
long PipeSize;
mkfifo("FifoFor23",0666);

PipeSize=pathconf("FifoFor23",_PC_PIPE_BUF);
MaximumNoOfFiles=sysconf(_SC_OPEN_MAX);

printf("Maximum number of files can be opened within a process %ld\n",MaximumNoOfFiles);
printf("Size of pipe (Circular Buffer) %ld\n",PipeSize);
return 0;
}
