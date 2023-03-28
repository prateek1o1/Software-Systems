/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to remove the message queue. 
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
K = ftok(".", 1);

Qid = msgget(K, IPC_CREAT | 0700);

printf("Key is %d\n", K);
printf("Message Queue Identifier is %d\n", Qid);
msgctl(Qid, IPC_RMID, NULL);

return 0;
}
