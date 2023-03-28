/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to find out time taken to execute getpid system call. Use time stamp counter.
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
	for(int i=0;i<100000;i++)
	{
	 getpid();
	}
	end=rdtsc();
	printf("Difference is: %llu nanoseconds\n",(long long)((end-start)/2.8));
	return 0;
}
