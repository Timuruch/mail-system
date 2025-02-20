#include <stdio.h>
#include "network.h"

int main() {
	network nm;
	init_sock(&nm, "127.0.0.1", 4500);
	lstn(&nm);
	int client = acpt(&nm);

	int a = sv_recv(client);
	sv_send(client, "Hello Back!");

	cls(a);
	cls(nm.s_sock);
	return 0;
}

//Plans
//fix problems with recieving text.
//then add a support for mnemonic functions
//first server then client
