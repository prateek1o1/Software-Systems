/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a separate program (for each time domain) to set a interval timer in 10sec and 10 micro second
 *a. ITIMER_REAL 
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <signal.h>

void main (int argc, char *argv[])
{
struct itimerval t1;
printf("Enter '1' to set 10 seconds or '2' to set 10 milliseconds timer!\n");
int v;
scanf("%d",&v);       

switch(v)
{
case 1:
t1.it_interval.tv_sec = 0;
t1.it_interval.tv_usec = 0;
t1.it_value.tv_sec = 10;
t1.it_value.tv_usec = 0;
break;

case 2:
t1.it_interval.tv_sec = 0;
t1.it_interval.tv_usec = 0;
t1.it_value.tv_sec = 0;
t1.it_value.tv_usec = 10;
break;

default:
printf("Please Provide Correct Input!\n");
break;
}
setitimer(ITIMER_REAL, &t1,NULL);
while(1);
}
