#include <stdio.h>
#include "network.h"

//start of server funcs
//i will ned to merge them someday 
//to another file, like 'server_tools.c'

char* check_coms(char* com){
	char* response = "[404] No command implemented!";

	printf("%s\n", com);
	printf("%ld\n", strlen(com));
	
	if (com == "LSRQ?") {
		response = "[100] Command done. Sadly no power to compute!";
	}

	return response;
}

//end of server funcs

int main() {
	network nm;
	init_sock(&nm, "127.0.0.1", 4500);
	lstn(&nm);
	int client = acpt(&nm);

//	int a = sv_recv(client);
//	sv_send(client, "Hello Back!");
	sv_send(client, check_coms(sv_recv(client)));
	
	cls(client);
	cls(nm.s_sock);
	return 0;
}

//Plans
//add support for multiple connections someday
//add a feature that supports many people at once
//then add a support for mnemonic functions
