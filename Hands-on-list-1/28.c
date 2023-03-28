/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to get maximum and minimum real time priority.
*/

#include <stdio.h>
#include <sched.h>
 
int main(void)
{
int PriorityMaximum,PriorityMinimum;

PriorityMaximum=sched_get_priority_max(SCHED_FIFO);
PriorityMinimum=sched_get_priority_min(SCHED_FIFO);

printf("The Maximum Priority With FIFO Scheduling= %d\n",PriorityMaximum);
printf("The Minimum Priority With FIFO Scheduling= %d\n",PriorityMinimum);
}
