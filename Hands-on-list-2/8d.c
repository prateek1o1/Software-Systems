/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program using signal system call to catch the following signals. 
 *d. SIGALRM (use alarm system call)
*/

#include <signal.h>   
#include <stdlib.h>   
#include <stdio.h>    
#include <unistd.h>

void Catch()
{
    printf("Signal SIGALRM has been caught!\n");
    exit(0);
}

void main()
{
    alarm(1);
    signal(SIGALRM, (void *)Catch);
    while(1);
}