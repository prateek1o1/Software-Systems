/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Find out the priority of your running program.Modify the priority with nice command.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h> 

int main(void)
{
int which = PRIO_PROCESS;
id_t pid;
pid = getpid();

int ret1,ret2;
getpriority(which,pid);
printf("Current priority= %d\n",getpriority(which,pid));
ret2=nice(10);
perror("nice ret: ");
printf("Priority after executing nice= %d\n",getpriority(which,pid));
getchar();
}
