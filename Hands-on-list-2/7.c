/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *7. Write a simple program to print the created thread ids.
*/

#include <pthread.h> 
#include <stdio.h>   
#include <unistd.h>
#include <stdlib.h> 

void *PrintThreadIdentity(void *argv)
{
    printf("Thread: %lu\n", pthread_self());
    return NULL;    
}

void main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, PrintThreadIdentity, NULL);
    pthread_join(tid,NULL);

    exit(0);
}
