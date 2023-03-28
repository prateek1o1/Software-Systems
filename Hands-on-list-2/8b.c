/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program using signal system call to catch the following signals.
 *b. SIGINT
*/

#include <signal.h> 
#include <stdio.h>  
#include <stdlib.h> 

void catch()
{
    printf("SIGINT signal has been caught!\n");
    exit(0);
}

void main()
{
    signal(SIGINT, (void *)catch);
    raise(SIGINT);        
}
