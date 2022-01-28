/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"
#define BUFSIZEMAX 15*1024

void echo(int connfd) 
{
    size_t n; 
    FILE *fw;
    fw = fopen( "serverFile.gif" , "wb+" );
    char buf[BUFSIZEMAX]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    Rio_readlineb(&rio, buf, BUFSIZEMAX);
    fwrite(buf , 1 , BUFSIZEMAX, fw);
    
}
/* $end echo */