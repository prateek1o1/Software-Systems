/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *6. Write a simple program to create three threads.
*/

#include <pthread.h> 
#include <stdio.h>   
#include <unistd.h>
#include <stdlib.h> 

void *Func(void *data)
{
    printf("Thread: %lu\n", pthread_self());
    return NULL;    
}

void main()
{
    pthread_t First, Second, Third;

    pthread_create(&First, NULL, Func, NULL);
    pthread_create(&Second, NULL, Func, NULL);
    pthread_create(&Third, NULL, Func, NULL);
    
    pthread_join(First,NULL);
    pthread_join(Second,NULL);
    pthread_join(Third,NULL);
    
    exit(0);
}
