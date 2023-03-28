/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program using signal system call to catch the following signals. 
 *f. SIGVTALRM (use setitimer system call)
*/

#include <signal.h>   
#include <stdlib.h>   
#include <stdio.h>    
#include <unistd.h>
#include <sys/time.h>

void Catch()
{
    printf("Signal SIGVTALRM has been caught!\n");
    exit(0);
}

void main()
{
    struct itimerval Timings;
    
    Timings.it_value.tv_sec = 1;
    Timings.it_value.tv_usec = 0;
    Timings.it_interval.tv_sec = 0;
    Timings.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &Timings, 0);
    signal(SIGVTALRM, (void *)Catch);

    while(1);
}
