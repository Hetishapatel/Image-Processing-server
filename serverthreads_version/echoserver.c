/*
g++ -c -I /usr/local/include/opencv4 echoserver.c echo.c csapp.h csapp.c 
g++ echo.o echoserver.o csapp.o  -o echoserver -lpthread -lopencv_core -lopencv_imgproc -lopencv_highgui  -L/usr/local/lib -lopencv_imgcodecs -L/usr/lib

*/

#include "csapp.h"

void echo(int connfd);
void *thread(void *vargp);

int main(int argc, char **argv)
{
  int listenfd, *connfdp;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr;
  pthread_t tid;
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(0);
  }
  listenfd = Open_listenfd(argv[1]);
  fprintf(stderr,"A\n");
  while (1) {
    clientlen=sizeof(struct sockaddr_storage);
    fprintf(stderr,"B\n");
    connfdp = (int *) Malloc(sizeof(int));
    *connfdp = Accept(listenfd, (SA *) &clientaddr, &clientlen);
    fprintf(stderr,"C\n");
    Pthread_create(&tid, NULL, thread, connfdp);
  }
}
/* Thread routine */
void *thread(void *vargp)
{
  fprintf(stderr,"D\n");
  int connfd = *((int *)vargp);
  Pthread_detach(pthread_self());
  Free(vargp);
  echo(connfd);
  Close(connfd);
  return NULL;
}
