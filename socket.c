#include "socket.h"
#include "common.h"


void init_SA_data(struct sockaddr_in *servaddr)
{
    servaddr->sin_family = AF_INET;
    servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr->sin_port = htons(SERVER_PORT);
}

void *rcv_messages(void *new_socket)
{
    sint32 read_ret = 0;
    uint8 buff[MAXLINE+1] = {0};

    while (1)
    {
        read_ret = read(*(sint32 *)new_socket, buff, sizeof(buff) - 1);
        ERROR_CHECK(read_ret, "read");
        if (read_ret <= 0)
        {
            puts("GET_MESSAGES: Disconnected.");
            break;
        }

        buff[read_ret] = '\0';
        printf("Reveived message: %s\n", buff);
    }

    return NULL;
}

void *snd_messages(void *new_socket)
{
    sint32 write_ret = 0;
    sint8 snd[MAXLINE+1] = {0};

    while (1)
    {
        scanf("%20s", snd);
        write_ret = write(*(sint32 *)new_socket, snd, strlen(snd));
        ERROR_CHECK(write_ret, "read");

        //printf("write_ret = %d\n", write_ret);
    }

    return NULL;
}