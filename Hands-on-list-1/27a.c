/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute ls -Rl by the following system calls
 a. execl
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(void)
{
	execl("/bin/ls","ls","-Rl", (char *)0);
}
