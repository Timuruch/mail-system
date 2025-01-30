#include "network.h"

void init_sock(network* nm, char* ip, int port){
	nm->s_sock = socket(AF_INET, SOCK_STREAM, 0);
	nm->addrlen = sizeof(nm->addr);
	if (nm->s_sock == -1)
		perror("Sock init error!\n");
	else
		printf("Inited socket!\n");

	nm->addr.sin_addr.s_addr = inet_addr(ip);
	nm->addr.sin_port = htons(port);
	nm->addr.sin_family = AF_INET;
}

void cnct(network* nm) {
	//add here a check if not connected
	if (nm->c_sock = connect(nm->s_sock, (struct sockaddr*)&nm->addr, nm->addrlen) != 0)
		perror("Error while connecting occured");
	else
		printf("No errors while connecting occured!\n");
}

void lstn(network* nm) { 
	if (bind(nm->s_sock, (struct sockaddr *)&nm->addr, nm->addrlen) == -1)
		perror("Bind error");
	else
		printf("Bind sucsessful!\n");
	
	if (listen(nm->s_sock, 5) == -1)
		perror("Error with listen");
	else
		printf("Listen sucsessful!\n");
}

void acpt(network* nm) {	
	nm->c_sock = accept(nm->s_sock, (struct sockaddr*)&nm->addr, &nm->addrlen);
	if(nm->c_sock == -1)
		perror("Error with accept");
	else
		printf("Accept succsessful!\n");
}

void cls(network* nm) {
	close(nm->s_sock);
	close(nm->c_sock);
}

void send_txt(network* nm, char* text) {
	int len = strlen(text);

	send(nm->c_sock, text, strlen(text), 0);
}

void recieve(network* nm) {
	char msg[256] = {0};
	recv(nm->c_sock, msg, sizeof(msg), 0);
	printf("%s\n", msg);
}
