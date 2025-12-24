#include <stdio.h>
#include <pthread.h>
#include "socket.h"
#include "common.h"

int main()
{
    struct sockaddr_in clientaddr = {0};
    sint32 listenfd = 0;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(listenfd,"socket");

    init_SA_data(&clientaddr);
    sint32 conn_ret = connect(listenfd, (const struct sockaddr *)&clientaddr, sizeof(clientaddr));
    ERROR_CHECK(conn_ret,"connect");

    pthread_t thread;
    pthread_create(&thread, NULL, snd_messages, (void *)&listenfd);

    rcv_messages((void *)&listenfd);

    pthread_join(thread, NULL);
    close(listenfd);
}