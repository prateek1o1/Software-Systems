/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process 
*/

#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    pid_t childPid, parentPid;
    int killStatus;
    childPid = fork();

    if (!childPid)
    {
        printf("Child Process %d\n", getpid());
        printf("Parent Process %d\n", getppid());
        sleep(3);

        killStatus = kill(getppid(), SIGKILL);
        if (!killStatus)
        {
            sleep(3);
            printf("Child is now orphan!\n");
        }
    }
    else
    {
        while (1);
    }
}