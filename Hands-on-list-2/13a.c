/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 * Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
*/

#include <signal.h> 
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void Catch()
{
    printf("SIGSTOP signal is received!\n");
    exit(0);
}

void main()
{
    pid_t pid = getpid();
    printf("PID: %d\n", pid);
    signal(SIGSTOP, Catch);
    
    printf("Putting the process to sleep for 10s\n");
    sleep(20);
}