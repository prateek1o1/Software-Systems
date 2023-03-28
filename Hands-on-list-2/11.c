/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to ignore a SIGINT signal then reset the default Act of the SIGINT signal -use sigaction system call.
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h>

void Catch(int N)
{
    printf("Caught signal is SIGINT %d\n", N);
}

void main()
{
    struct sigaction Act;

    printf("Ignoring SIGINT\n");
    Act.sa_handler = SIG_IGN;
    Act.sa_flags = 0;
    sigaction(SIGINT, &Act, NULL);
    sleep(7);

    printf("Handling SIGINT\n");
    Act.sa_handler = Catch;
    Act.sa_flags = 0;
    sigaction(SIGINT, &Act, NULL);
    sleep(7);

    printf("Default Action for SIGINT\n");
    Act.sa_handler = SIG_DFL;
    Act.sa_flags = 0;
    sigaction(SIGINT, &Act, NULL);
    sleep(7);
}