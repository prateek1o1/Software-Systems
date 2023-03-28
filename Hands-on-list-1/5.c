/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd. 
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (void) {

	creat("Temporary11",0744);
	creat("Temporary12",0744);
	creat("Temporary13",0744);
	creat("Temporary14",0744);
	creat("Temporary15",0744);

	while(1);

	//Run in background
	//$./a.out &

	//File Descriptor Table
	//cd /proc/PID/fd
	
	//ls /proc/PID/fd
}
