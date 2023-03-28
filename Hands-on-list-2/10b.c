/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program using sigaction system call to catch the following signals. 
 *b. SIGINT
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 
#include <stdlib.h>

void Handler(int N)
{
    printf("signal caught is SIGINT %d\n", N);
    exit(0);
}

void main()
{
    struct sigaction Act;
    Act.sa_handler = Handler;
    Act.sa_flags = 0;

    sigaction(SIGINT, &Act, NULL);
    raise(SIGINT);
}
