#include <stdio.h>
#include <string.h>

typedef struct client client;

struct client{
	int client_sock;
	int is_conn;
	char username[20];
};

char* check_coms(char* com, client* cl);
