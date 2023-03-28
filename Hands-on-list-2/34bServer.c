/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to create a concurrent server.
 *b. use pthread_create 
*/

#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     
#include <pthread.h>    


void Func(int *fd)
{
    char received[100];

    write(*fd, "This is a message from server!", 30);
    printf("Data sent!\n");

    read(*fd, received, 100);
    printf("Data received: %s\n", received);

    close(*fd);
}

void main()
{
    int sfd, cfd;
    int bindStatus;
    int listenStatus;
    int CZ;

    struct sockaddr_in adr, client;

    pthread_t tid;

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Socket created successfully!\n");

    adr.sin_addr.s_addr = htonl(INADDR_ANY);
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);

    bindStatus = bind(sfd, (struct sockaddr *)&adr, sizeof(adr));
    if (bindStatus == -1)
    {
        perror("Error in binding!");
        _exit(0);
    }
    printf("Binding to socket successful!\n");

    listenStatus = listen(sfd, 2);
    if (listenStatus == -1)
    {
        perror("Error in listen for connections!");
        _exit(0);
    }
    printf("Listening for connections!\n");

    while (1)
    {
        CZ = (int)sizeof(client);
        cfd = accept(sfd, (struct sockaddr *)&client, &CZ);
        if (cfd == -1)
            perror("Error while accepting a connection!");
        else
        {   
            if (pthread_create(&tid, NULL, (void *)Func, &cfd))
                perror("Error in creating thread");
        }
    }

    close(sfd);
}