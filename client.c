#include <stdio.h>
#include "network.h"
#include "client_func.h"

int main() {
	mail client;
	client.mail = "rdst@127.0.0.1";
/*
	char* pch = strchr(mail, '@');
	long int place = pch-mail+1;
	if (pch != NULL) {
		memmove(username, mail, place-1);
		memmove(mail, mail+place, strlen(mail)-place);
		memmove(ip_addr, mail, strlen(mail)-place);
	}*/
	
	if(get_creds(client)) {
		printf("Failed to get credentials from mail address!\n");
		return 0;
	}

	printf("Username: %s\n", client.username);
	printf("Server IP: %s\n", client.ip_addr);
	printf("Mail: %s\n", client.mail);
	/*
	network nm;
	init_sock(&nm, ip_addr, 4500);
	cnct(&nm);
	cl_send(&nm, "LSRQ?");
	
	int a = cl_recv(&nm);

	cls(nm.s_sock);*/
	return 0;
}
