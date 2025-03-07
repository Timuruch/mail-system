#include <stdio.h>
#include <string.h>

typedef struct mail mail;

struct mail {
	char* mail;
	char username[20];
	char ip_addr[20];
	int run;
};

int get_creds(mail* info);

char* process_coms(char* text, mail* info);
