/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create a concurrent server.
 *b. use pthread_create 
*/

#include <sys/types.h>  
#include <stdio.h>      
#include <unistd.h>     
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdlib.h>

void main()
{
    int sfd; 
    int connectStatus;        
    struct sockaddr_in address;  
    char Received[100];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    
    printf("Socket created successfully!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(sfd, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        perror("Error in connecting to server!");
        exit(0);
    }
    printf("Connection established!\n");

    
    read(sfd, Received, 100);
    printf("Data received: %s\n", Received);

    write(sfd, "This is a message from client!", 30);
    printf("Data sent!\n");

    close(sfd);
}