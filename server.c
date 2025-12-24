
#include <pthread.h>
#include "socket.h"
#include "common.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    sint32 bind_ret = 0, listen_ret = 0;
    sint32 listenfd = 0, new_socket = 0;
    struct sockaddr_in servaddr = {0};
    socklen_t servaddrlen = sizeof(servaddr);

    pthread_t thread;

    // create socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(listenfd, "get_socket");

    // enable to reuse socket after restart
    sint32 opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // initializing structure
    bzero(&servaddr,sizeof(servaddr));
    init_SA_data(&servaddr);
    puts("Structure init done.");

    // bind socket
    bind_ret = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    ERROR_CHECK(bind_ret, "bind");
    puts("Binding done.");

    listen_ret = listen(listenfd, SOMAXCONN);
    ERROR_CHECK(listen_ret, "listen");
    puts("Listening...");
    new_socket = accept(listenfd, (struct sockaddr *)&servaddr, &servaddrlen);
    ERROR_CHECK(new_socket, "accept");
    puts("Connection accepted.");

    pthread_create(&thread, NULL, rcv_messages, (void*)&new_socket);

    snd_messages((void *)&new_socket);

    pthread_join(thread, NULL);
    close(new_socket);
    close(listenfd);

    return 0;
}