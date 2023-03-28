/*Name- Prateek Chhimwal
 *Roll Number- MT2022080
 *Write a program to communicate between two machines using socket.
*/

#include <sys/types.h>  
#include <stdio.h>      
#include <unistd.h>     
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdlib.h>

void main()
{
    int sfd, cfd, BS, LS, CZ;

    struct sockaddr_in adr, client;
    char received[100];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("Error in creating socket!");
        _exit(0);
    }
    printf("Socket created successfully!\n");

    adr.sin_addr.s_addr = htonl(INADDR_ANY);
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);

    BS = bind(sfd, (struct sockaddr *)&adr, sizeof(adr));
    if (BS == -1)
    {
        perror("Error while binding name to socket!\n");
        _exit(0);
    }
    printf("Binding successful!\n");

    LS = listen(sfd, 2);
    if (LS == -1)
    {
        perror("Error in listen for connections!");
        _exit(0);
    }
    printf("Listening for connections!\n");

    CZ = (int)sizeof(client);
    cfd = accept(sfd, (struct sockaddr *)&client, &CZ);
    if (cfd == -1)
        perror("Error in accepting a connection!");
    else
    {


        write(cfd, "This is a message from server!", 30);
        printf("Data sent!\n");

        read(cfd, received, 100);
        printf("Data received: %s\n", received);

    }

    close(cfd);
    close(sfd);
}