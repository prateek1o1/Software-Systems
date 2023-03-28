/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create the following types of a files using (i) shell command (ii) system call a. Soft link (symlink system call).
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
	//Shell Command
	//ln -s sourcefile sftlnkfile
	
	symlink ("sourcefile", "softlinkfile") ;
	perror("link ret: ");
}
