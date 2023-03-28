/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write two programs so that both can communicate by FIFO -Use one way communication. 
*/

/*PROGRAM 1
*/
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int main ()
{
int FileDesc;
char Box[]={"Namaskara from PROGRAM 1!\n"};
mkfifo("FifoFor20",0666);
FileDesc=open("FifoFor20",O_WRONLY);
write(FileDesc,&Box,sizeof(Box));
close(FileDesc);
return 0;
}