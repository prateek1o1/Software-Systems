/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program using sigaction system call to catch the following signals. 
 *c. SIGFPE   
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 
#include <stdlib.h>

void Handler(int N)
{
    printf("Signal caught is SIGFPE %d\n", N);
    exit(0);
}

void main()
{
    struct sigaction Act;
    Act.sa_handler = Handler;
    Act.sa_flags = 0;

    sigaction(SIGFPE, &Act, NULL);
    raise(SIGFPE);
}
