/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to send messages to the message queue. Check $ipcs -q 
*/

# include <unistd.h>
# include <stdlib.h>
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
    
    char *msg_text = "Greetings!";
    M.mtype = 1;
    strcpy(M.mtext,msg_text);
    msgsnd(Qid, &M, sizeof(M), 0);
    return 0;
}
