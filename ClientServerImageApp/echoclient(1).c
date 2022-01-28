/*
gcc -g echoclient.c ../csapp.h ../csapp.c -lpthread -o client.out

gcc -g echoclient.c csapp.h csapp.c -lpthread -o client.out
*/

#include <stdio.h>
#include <stdlib.h>
#include "csapp.h"

#define BUFSIZEMAX 15*1024

int main(int argc, char **argv)
{
    
    FILE *fr;
    char *buf[BUFSIZEMAX];

    fr = fopen("godzilla.gif" , "rb+" );
    fread(buf, 1, BUFSIZEMAX, fr);
    
    int clientfd;
    char *host;
    // int port;
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    // port = atoi(argv[2]);

    clientfd = Open_clientfd(host, argv[2]);
    Rio_readinitb(&rio, clientfd);

    Rio_writen(clientfd, buf, BUFSIZEMAX);

    Close(clientfd);
    exit(0);

}