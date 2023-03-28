/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to change the exiting message queue permission. (use msqid_ds structure). 
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h> 

int main ()
{
key_t K;                   
int Qid;              
struct msqid_ds Attr; 
int msgctlStatus;               
K = ftok(".", 1);
Qid = msgget(K, IPC_CREAT | 0700);

msgctlStatus = msgctl(Qid, IPC_STAT, &Attr);
printf("Key: %d\n", K);
printf("Message Queue Identifier: %d\n", Qid);
printf("access permissionis %od\n", Attr.msg_perm.mode);

Attr.msg_perm.mode = 0777;
msgctl(Qid, IPC_SET, &Attr);

printf("Key: %d\n", K);
printf("Message Queue Identifier: %d\n", Qid);
printf("access permissionis %od\n", Attr.msg_perm.mode);
return 0;
}
