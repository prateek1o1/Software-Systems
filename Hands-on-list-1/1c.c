/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create the following types of a files using (i) shell command (ii) system call c.FIFO (mkfifo Library Function or mknod system call.
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (void) {
        //Shell Command
	//mkfifo myfifofile
	
	mkfifo( "myfifofile", 0666 );
	mknod("mynodfile", S_IFIFO | 0666, 0);
}
