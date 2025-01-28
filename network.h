#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

typedef struct network network;

struct network{
	int s_sock;
	int c_sock;
	struct sockaddr_in addr;
	socklen_t addrlen;
};

void init_sock(network* nm, char* ip, int port);

void cnct(network* nm);

void lstn(network* nm);

void acpt(network* nm);

void cls(network* nm);

void send_txt(network* nm, char* text);

char* recieve(network* nm);
