/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program using signal system call to catch the following signals.
 *c. SIGFPE 
*/

#include <signal.h> 
#include <stdio.h>  
#include <stdlib.h> 

void catch()
{
    printf("SIGFPE signal has been caught!\n");
    exit(0);
}

void main()
{
    signal(SIGFPE, (void *)catch);
    raise(SIGFPE);        
}

