/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call. 
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 

void Catch()
{
    printf("\nSIGINT has been caught!\n");
}

void main()
{
    printf("SIGINT ignored for 8 seconds\n");
    signal(SIGINT, SIG_IGN);
    sleep(8);

    printf("Catch with SIGINT!\n");
    signal(SIGINT, (void *)Catch);
    sleep(3);

    printf("Default handler!\n");
    signal(SIGINT, SIG_DFL);
    sleep(3);
}
