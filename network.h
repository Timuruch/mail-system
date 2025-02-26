#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

typedef struct network network;
typedef struct clients clients;

struct network{
	int s_sock;
	struct sockaddr_in addr;
	socklen_t addrlen;
};

struct clients{
	int clients[10];
	int client;
	int max_amount;
};

void init_sock(network* nm, char* ip, int port);

void cnct(network* nm);

void lstn(network* nm);

int acpt(network* nm);

void cls(int sockfd);

//Servrer talking functions
void sv_send(int operator, char* text);

char* sv_recv(int operator);

//Client talking functions
void cl_send(network* nm, char* text);

int cl_recv(network* nm);
