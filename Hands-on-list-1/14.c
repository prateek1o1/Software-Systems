/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. Program should be able to identify any type of a file. 
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main (int argc, char *argv[]) 
{ 	struct stat buffer;
	stat(argv[1], &buffer);
	mode_t modeoffile;
	modeoffile=buffer.st_mode & S_IFMT; //S_IFMT This is a bit mask used to extract the file type code from a mode value.

	
	if(modeoffile==S_IFBLK)
		printf("Block special file\n");
	if(modeoffile==S_IFCHR)
		printf("Character special file\n");
	if(modeoffile==S_IFDIR)
	 	printf("Directory\n");
	if(modeoffile==S_IFIFO)
		printf("FIFO special file\n");
	if(modeoffile==S_IFLNK)
		printf("Symbolic link\n");
	if(modeoffile==S_IFREG)
		printf("Regular file\n");
	if(modeoffile==S_IFSOCK)
               printf("Socket\n");
return 0;
        
}
