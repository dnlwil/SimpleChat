#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "common.h"

#define SERVER_PORT 9999
 
int get_socket_X(void);
void init_SA_data(struct sockaddr_in *servaddr);
void *rcv_messages(void *new_socket);
void *snd_messages(void *new_socket);

#endif