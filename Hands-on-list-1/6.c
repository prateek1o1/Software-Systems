/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (void) {

char list[20];

//Input from STDIN
read(0,list,sizeof(list));

//Output to STDOUT
write(1,list,sizeof(list));
}
