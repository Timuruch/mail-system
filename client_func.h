#include <stdio.h>
#include <string.h>

typedef struct mail mail;

struct mail {
	char* mail;
	char username[20];
	char ip_addr[20];
};

int get_creds(mail info);
