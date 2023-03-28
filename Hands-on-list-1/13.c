/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main(void)
{
  int retval;
  fd_set set;
  struct timeval timeout;

  FD_ZERO (&set);
  FD_SET (STDIN_FILENO, &set);

  timeout.tv_sec = 5;
  timeout.tv_usec = 0;

  retval=select (FD_SETSIZE,&set, NULL, NULL,&timeout);

  if(retval==-1)
	  perror("select()\n");
  else if(retval)
	  printf("Input available\n");
  else
	  printf("Timeout\n");
  
  return 0;

}


