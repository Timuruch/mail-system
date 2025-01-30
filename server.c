#include <stdio.h>
#include "network.h"

int main() {
	network nm;
	init_sock(&nm, "127.0.0.1", 4500);
	lstn(&nm);
	acpt(&nm);

	recieve(&nm);

	cls(&nm);
	return 0;
}

//Plans
//fix problems with recieving text.
//then add a support for mnemonic functions
//first server then client
