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
	if (connect(nm->s_sock, (struct sockaddr*)&nm->addr, nm->addrlen) < 0)
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

int acpt(network* nm) {	
	int client = accept(nm->s_sock, (struct sockaddr*)&nm->addr, &nm->addrlen);
	if(client == -1)
		perror("Error with accept");
	else
		printf("Accept succsessful!\n");
	return client;
}

void cls(int sockfd) {
	close(sockfd);
}

//Server talking functions
void sv_send(int operator, char* text){
	int sent = send(operator, text, strlen(text), 0);
	if (sent < 0)
		perror("Error 'sv_send()': ");
}

char* sv_recv(int operator){
	char msg[256] = { 0 };
	recv(operator, &msg, sizeof(msg), 0);
	char* buffer = msg;
	return buffer;
}

//Client talking functions
void cl_send(network* nm, char* text) {
	int sd = send(nm->s_sock, text, strlen(text), 0);
	if (sd < 0)
		perror("Error 'cl_send()': ");
}

int cl_recv(network* nm) {
	char msg[256] = { 0 };
	int recieved = recv(nm->s_sock, &msg, sizeof(msg), 0);
	printf("Text: %s\n", msg);
	return recieved;
}
