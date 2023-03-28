/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to set (any one) system resource limit. Use setrlimit system call.  
*/

#include <sys/time.h>     
#include <sys/resource.h> 
#include <stdio.h>        

void Display(rlim_t soft, rlim_t hard)
{
    printf("\nSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld \n", soft);

    printf("Hard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld \n", hard);
    
}

void main()
{
    int status;                   
    struct rlimit resourceLimits; 

    getrlimit(RLIMIT_NOFILE, &resourceLimits);
    printf("Maximum file descriptor in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    resourceLimits.rlim_cur=2048;
    setrlimit(RLIMIT_NOFILE, &resourceLimits);
    printf("Maximum file descriptor in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

}