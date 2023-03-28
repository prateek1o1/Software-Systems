/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute an executable program.
 a. use some executable program
 b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
void main(int args, char *argv[])
{
	execl("./14.out","PROGRAM TO IDENTIFY TYPE OF FILE- 14.c",argv[1],NULL);

}
