#include <stdio.h>
#include "network.h"
#include "server_func.h"

int main() {
	network nm;
	init_sock(&nm, "127.0.0.1", 4500);
	lstn(&nm);
	int client = acpt(&nm);

	sv_send(client, check_coms(sv_recv(client)));
	
	cls(client);
	cls(nm.s_sock);
	return 0;
}
