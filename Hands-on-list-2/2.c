/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to print the system resource limits. Use getrlimit system call. 
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

    getrlimit(RLIMIT_AS, &resourceLimits);
    printf("Maximum size of process's virtual memory in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);
    
    getrlimit(RLIMIT_CORE, &resourceLimits);
    printf("Maximum size of a core file in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);
    
    getrlimit(RLIMIT_CPU, &resourceLimits);
    printf("Maximum CPU time that the process can consume in seconds");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);
   
    getrlimit(RLIMIT_DATA, &resourceLimits);
    printf("Maximum size of process's data segement in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);
    
    getrlimit(RLIMIT_RTPRIO, &resourceLimits);
    printf("Ceiling on the real-time priority");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_RTTIME, &resourceLimits);
    printf("Amount of CPU time that a  process scheduled  under a real-time scheduling policy in milliseconds");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    printf("The number of signals that may be queued");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    printf("Maximum  size of the process stack in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_FSIZE, &resourceLimits);
    printf("Maximum size of files that  the  process  may  create in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_LOCKS, &resourceLimits);
    printf("Maximum number of locks that a process may establish");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_MEMLOCK, &resourceLimits);
    printf("Maximum number of bytes of memory that may be locked into RAM");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_MSGQUEUE, &resourceLimits);
    printf("Maximum number of bytes of that can be allocated for POSIX message queues");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_NICE, &resourceLimits);
    printf("Ceiling of the process's nice value");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_NOFILE, &resourceLimits);
    printf("Maximum file descriptor in bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_NPROC, &resourceLimits);
    printf("Limit on the number of threads");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);

    getrlimit(RLIMIT_RSS, &resourceLimits);
    printf("Limit on the  number of virtual pages resident in the RAM in  bytes");
    Display(resourceLimits.rlim_cur, resourceLimits.rlim_max);


}
