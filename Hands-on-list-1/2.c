/*Name- Prateek Chhimwal
 *Roll Number- MT2022080 
 *Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {

	while(1);
	
	//Run process in background 
	//$./a.out &
	
	//Check proc Directory  
	//$cd /proc/PID
	//$more status
	// cat /proc/PID/status | head
}
