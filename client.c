#include <stdio.h>
#include "headers/network.h"
#include "headers/client_func.h"

int main() {
	mail client;
	client.mail = "rdst@127.0.0.1";
	
	if(get_creds(&client)) {
		printf("Failed to get credentials from mail address!\n");
		return 0;
	}

	printf("Username: %s\n", client.username);
	printf("Server IP: %s\n", client.ip_addr);
	printf("Mail: %s\n", client.mail);
	
	network nm;
	init_sock(&nm, client.ip_addr, 4500);
	cnct(&nm);
	cl_send(&nm, "LSRQ");
	client.run = 1;	

	while (client.run) {
		char* text = cl_recv(&nm);
		printf("S: %s\n", text);
		char* ans = process_coms(text, &client);
		printf("C: %s\n", ans);
		cl_send(&nm, ans);
		getchar();
	}

	cls(nm.s_sock);
	return 0;
}
