/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write two programs so that both can communicate by FIFO -Use one way communication. 
*/

/*PROGRAM 2
*/
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int main ()
{
char Box[100];
int FileDesc;
FileDesc=open("FifoFor20",O_RDONLY);
read(FileDesc,&Box,sizeof(Box));
printf("Message=%s",Box);
return 0;
}

