/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to receive messages from the message queue.
 *a. with 0 as a flag. 
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h> 
# include <string.h>

int main ()
{
    key_t K;        
    int Qid;   

    struct msgbuf
    {
    long mtype;     
    char mtext[100]; 
    } M;

    K = ftok(".", 1);
    Qid = msgget(K, IPC_CREAT | 0700);
    M.mtype = 1;
    char *msg_text = "Greetings!";
    M.mtype = 1;
    strcpy(M.mtext,msg_text);
    msgsnd(Qid, &M, sizeof(M), 0);
    
    msgrcv(Qid, &M, sizeof(M), M.mtype, 0);
    
    printf("Received Message: %s\n", M.mtext);

    return 0;
}   