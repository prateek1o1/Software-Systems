/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute an executable program.
 a. use some executable program
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(void)
{
	execl("./3.out","3.c",NULL);
}
