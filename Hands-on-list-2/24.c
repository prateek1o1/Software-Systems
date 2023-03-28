/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create a message queue and print the key and message queue id.
*/

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h> 
# include <sys/ipc.h>   
# include <sys/msg.h>   

int main ()
{
key_t K;      
int MessageIdentifier; 

K = ftok(".", 'a');

MessageIdentifier = msgget(K, IPC_CREAT | 0744);
printf("Key: %d\n", K);
printf("Message Queue Identifier: %d\n", MessageIdentifier);    
return 0;
}
