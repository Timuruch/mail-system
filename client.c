#include <stdio.h>
#include "network.h"
#include <string.h>

int main() {
	/*
	network nm;
	init_sock(&nm, "127.0.0.1", 8080);
	cnct(&nm);
	cls(&nm);*/
	
	char* ip_addr = "";
	char* username = "";
	char* mail = "rdst@127.0.0.1";
	int flag = 0;

	for (int x = 0;x < strlen(mail);x++){
		if (mail[x] == '@') {
			flag = 1;
			continue;
		} 

		if (!flag) {
			int len = strlen(username);
			char buf[len+1];
			strcpy(buf, username);
			buf[len] = mail[x];
			buf[len+1] = 0;
			username = strdup(buf);
		}

		if (flag) {
			int len = strlen(ip_addr);
			char buf[len+1];
			strcpy(buf, ip_addr);
			buf[len] = mail[x];
		       	buf[len+1] = 0;	
                        ip_addr = strdup(buf);
		}
	}

	printf("Username: %s\n", username);
	printf("Server IP: %s\n", ip_addr);
	printf("Mail: %s\n", mail);
	
	network nm;
	init_sock(&nm, ip_addr, 4500);
	cnct(&nm);
	//send_txt(&nm, "Hello World!");
	cls(&nm);

	return 0;
}
