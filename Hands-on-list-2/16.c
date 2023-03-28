/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to send and receive data from parent to child vice versa. Use two way communication.
*/

# include <unistd.h>
# include <stdio.h>

int main ()
{
int f1[2];
int f2[2];
char bufferx[50];
char buffery[50];
pipe(f1);
pipe(f2);
if(!fork())
{
close(f2[0]);
printf("Enter Message Which Child Will Send=");
scanf("%[^\n]",bufferx);
write(f2[1],bufferx,sizeof(bufferx));
close(f1[1]);
read(f1[0],buffery,sizeof(buffery));
printf("Message From Parent= %s\n",buffery);
}
else
{
close(f2[1]);
read(f2[0],bufferx,sizeof(bufferx));
printf("Message From Child= %s\n",bufferx);
close(f1[0]);
printf("Enter Message Which Parent Will Send=");
scanf("%[^\n]",buffery);
close(f1[0]);
write(f1[1],buffery,sizeof(buffery));
}
return 0;
}
