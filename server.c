#include <stdio.h>
#include "headers/network.h"
#include "headers/server_func.h"

int main() {
	network nm;
	init_sock(&nm, "127.0.0.1", 4500);
	lstn(&nm);
	
	client cl;
	
	cl.client_sock = acpt(&nm);
	if (cl.client_sock == -1) {
		printf("Failed to connect to client!\n");
		return 0;
	}

	cl.is_conn = 1;

	while (cl.is_conn)
		sv_send(cl.client_sock, check_coms(sv_recv(cl.client_sock), &cl));
	
	cls(cl.client_sock);
	cls(nm.s_sock);
	return 0;
}
