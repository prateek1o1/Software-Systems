/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h> 
#include <sys/time.h>

unsigned long long rdtsc()
{
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A"(dst));
	return dst;
}

int main()
{
	long long  start,end;
	start =rdtsc();
	for(int i=0;i<100;i++)
	{
	 getppid();
	}
	end=rdtsc();
	printf("Difference is: %llu nanoseconds\n",(long long)((end-start)/2.4));
	return 0;
}