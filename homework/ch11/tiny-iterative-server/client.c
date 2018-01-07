#include "../../csapp.h"
#define MAX_LINE 10

int main(int argc, char** argv)
{
    // parsing arguments
    int clientfd;
    char* serv_hostname;
    int serv_port;
    char buf[MAX_LINE];
    rio_t rio;

    if(argc!=3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }
    serv_hostname = argv[1];
    serv_port = atoi(argv[2]);

    // establish connection to server
    clientfd = Open_clientfd(serv_hostname, serv_port);

    // echoing message
    Rio_readinitb(&rio, clientfd);
    while(Fgets(buf, MAX_LINE, stdin) != NULL)
    {
        Rio_writen(clientfd, buf, strlen(buf));
    } 
    Close(clientfd);
    exit(0);
}
