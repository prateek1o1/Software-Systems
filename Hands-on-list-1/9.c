/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main (void) 
{ 	struct stat FileInfo;
	int fd;

	fd=open("File",O_RDWR|O_CREAT,0744);
	fstat(fd, &FileInfo);

	printf("Inode= %ld\n",FileInfo.st_ino);
	printf("Number of Hard-links= %ld\n",FileInfo.st_nlink);
	printf("Uid= %u\n",FileInfo.st_uid);
	printf("Gid= %u\n",FileInfo.st_gid);
    printf("Size= %ld\n",FileInfo.st_size);
	printf("Block Size= %ld\n",FileInfo.st_blksize);
	printf("Number of Blocks= %ld\n",FileInfo.st_blocks);
	printf("Time of Last Access= %s",ctime(&FileInfo.st_atime));
	printf("Time of Last Modification= %s",ctime(&FileInfo.st_mtime));
	printf("Time of Last Change= %s",ctime(&FileInfo.st_ctime));
}
