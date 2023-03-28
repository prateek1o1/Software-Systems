/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write two programs so that both can communicate by FIFO -Use two way communications. 
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

int main ()
{
int FileDesc;
char WriteBox[]={"Namaskara from PROGRAM 1!\n"};
char ReadBox[100];

mkfifo("FirstFifoFor21",0666);
mkfifo("SecondFifoFor21",0666);

FileDesc=open("SecondFifoFor21",O_RDONLY);
read(FileDesc,&ReadBox,sizeof(ReadBox));
printf("Message=%s",ReadBox);
close(FileDesc);

FileDesc=open("FirstFifoFor21",O_WRONLY);
write(FileDesc,&WriteBox,sizeof(WriteBox));
close(FileDesc);

return 0;
}