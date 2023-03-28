/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 * Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
*/

#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>     
#include <stdlib.h> 

void main(int argc, char *argv[])
{
    pid_t P;
    if (argc != 2)
    {
        printf("Give PID!\n");
        exit(0);
    }
    P = atoi(argv[1]);
    if(kill(P, SIGSTOP)==0)
        printf("Successfully sent SIGSTOP signal to process (%d)\n", P);    
}