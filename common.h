#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define ERROR_CHECK(a,b) if (a < 0) {printf("Error on >> %s << step.\nValue of variable = %d\n", b, a); perror("error"); exit(-1);}
#define MAXLINE 4096u

typedef unsigned char uint8;
typedef char          sint8;
typedef unsigned int  uint32;
typedef int           sint32;

#endif