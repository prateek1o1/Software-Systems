/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute ls -Rl by the following system calls
 b. execlp
*/

#include <stdio.h>
#include <unistd.h>
 
int main(void)
{
execlp("ls","ls","-Rl",(char *) 0);	
}
