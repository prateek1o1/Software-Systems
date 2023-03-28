/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
 *a. access permission
 *b. uid, gid
 *c. time of last message sent and received
 *d. time of last change in the message queue
 *e. size of the queue
 *f. number of messages in the queue
 *g. maximum number of bytes allowed
 *h. pid of the msgsnd and msgrcv
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h> 

int main ()
{
 key_t K;               
int MessageQueue;              
struct msqid_ds Attr; 

K = ftok(".", 1);
MessageQueue = msgget(K, IPC_CREAT | 0744);
msgctl(MessageQueue, IPC_STAT, &Attr);

    printf("access permission is %od\n", Attr.msg_perm.mode);
    printf("uid is %d\n", Attr.msg_perm.uid);
    printf("gid is %d\n", Attr.msg_perm.gid);
    printf("time of last message sent and received are %ld & %ld\n", Attr.msg_stime,Attr.msg_rtime);    
    printf("size of queue is %ld\n", Attr.__msg_cbytes);
    printf("number of messages in the queue are %ld\n", Attr.msg_qnum);
    printf("maximum number of bytes allowed in the queue are %ld\n", Attr.msg_qbytes);
    printf("pid of last message sent & received are %d & %d\n", Attr.msg_lspid,Attr.msg_lrpid);
return 0;
}
