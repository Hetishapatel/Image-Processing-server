/*
gcc -g echoserver.c echo.c ../csapp.h ../csapp.c -lpthread  -o server.out

gcc -g echoserver.c echo.c csapp.h csapp.c -lpthread  -o server.out
*/
#include <stdio.h>
#include <stdlib.h>

#include "csapp.h"

void echo(int connfd);
int main(int argc, char **argv)
{
    fprintf(stderr, "Start\n");
    int listenfd, connfd;
    socklen_t clientlen;
    // int port;
    struct sockaddr_storage clientaddr; /* Enough space for any address */
    char client_hostname[MAXLINE], client_port[MAXLINE];
    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    fprintf(stderr, "A\n");
    // port = atoi(argv[1]);
    listenfd = Open_listenfd(argv[1]);
    fprintf(stderr, "B\n");
    while (1) 
    {
        fprintf(stderr, "1\n");
        clientlen = sizeof(struct sockaddr_storage);
        fprintf(stderr, "2\n");
        
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        fprintf(stderr, "3\n");
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
        fprintf(stderr, "4\n");
        fprintf(stderr, "Connected to (%s, %s)\n", client_hostname, client_port);
        fprintf(stderr, "5\n");
        echo(connfd);
        Close(connfd);
    }
    exit(0);
}