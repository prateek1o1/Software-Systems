/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).
*/

#include <stdio.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	struct sched_param parameter;
	parameter.sched_priority=15;

int policy=sched_getscheduler(getpid());

if(policy==SCHED_FIFO) 
{	printf("Scheduling Policy is SCHED_FIFO\n");
        sched_setscheduler(getpid(),SCHED_RR,&parameter);
	printf("Modified Scheduling Policy is SCHED_RR\n");
}
else if(policy==SCHED_RR)
{	printf("Scheduling Policy is SCHED_RR\n");
	sched_setscheduler(getpid(),SCHED_OTHER,&parameter);
	printf("Modified Scheduling Policy is SCHED_OTHER\n");
}
else
{	printf("Scheduling Policy is SCHED_OTHER\n");
	sched_setscheduler(getpid(),SCHED_FIFO,&parameter);
	printf("Modified Scheduling Policy is SCHED_FIFO\n");
}
}
