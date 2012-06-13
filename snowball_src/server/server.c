#include "server.h"

int main(int argc, char *argv[])
{
  int listenfd = 0, connfd = 0, n = -1;
  struct sockaddr_in serv_addr;

  char receivBuff[MAX_LENGTH + 1];

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(receivBuff, '0', sizeof(receivBuff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(5000);

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 10);

  while(1)
  {
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);


    while ((n = read(connfd, receivBuff, 1) > 0))
    {

      receivBuff[n] = 0;
      printf ("message receive from client is : |%s| with n = %i\n", receivBuff, n);
      memset(receivBuff, '0', sizeof(receivBuff));
    }

    close(connfd);
    sleep(1);
  }
}
