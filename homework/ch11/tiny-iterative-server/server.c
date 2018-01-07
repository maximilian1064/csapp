#include "../../csapp.h"
#define MAX_LINE 10

int main(int argc, char** argv)
{
    // parsing arguments
    int listenfd, connfd, port, n;
    rio_t rio;
    char buf[MAX_LINE];
    struct sockaddr_in client_sockaddr;
    int client_addrlen;
    struct hostent* client_hostent;
    FILE* fi;

    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <port> <file>\n", argv[0]);
        exit(0);
    }
    port = atoi(argv[1]);

    // setup listenfd 
    listenfd = Open_listenfd(port);

    // establish connection with clients
    while(1)
    {
        client_addrlen = sizeof(client_sockaddr);
        connfd = Accept(listenfd, (SA*)&client_sockaddr, &client_addrlen);

        // print domain name and address of client
        client_hostent = Gethostbyaddr( (const char*)&client_sockaddr.sin_addr.s_addr, 
                                        sizeof(client_sockaddr.sin_addr.s_addr), AF_INET); 
        printf("Connected to client\nHostname: %s\nIP: %s\n", client_hostent->h_name, inet_ntoa(client_sockaddr.sin_addr));

        // store client message in file
        Rio_readinitb(&rio, connfd);
        fi = Fopen(argv[2], "w+");
        while((n = Rio_readlineb(&rio, buf, MAX_LINE)) != 0)
        {
            printf("server receives %d bytes\n", n);
            Fputs(buf, fi);
        }
        Fclose(fi);
        Close(connfd);
    }
    Close(listenfd);

    exit(0);
}
