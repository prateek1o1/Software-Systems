/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *19. Create a FIFO file by
 *a. mknod command
 *b. mkfifo command
 *c. Use strace command to find out, which command (mknod or mkfifo) is better.
 *i. mknod system call
 *ii. mkfifo library function 
*/

# include <unistd.h>
# include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>  
int main ()
{
mknod("FIFO_FILE-2",S_IFIFO,0);
}
