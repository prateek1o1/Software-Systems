/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to execute ls -Rl by the following system calls
 d. execv
*/

#include <unistd.h>
 
int main(void)
{
const char * argv[]={"ls","-Rl",0};

execv("/bin/ls",(void *) argv);
}
