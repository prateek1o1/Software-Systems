/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to display the environmental variable of the user (use environ).
*/

#include <stdio.h>

int main (void)
{
extern char **environ; // The variable environ points to an array of pointers to strings called the "environment".
int item=0;

while(environ[item])
	{
	if(*((environ[item])+0)=='U' && *((environ[item])+4)=='=') //USER
	printf("%s\n",environ[item]);
	item++;
	}

return 0;
}
