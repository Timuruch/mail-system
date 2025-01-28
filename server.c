#include <stdio.h>
#include "network.h"

int main() {
	network nm;
	init_sock(&nm, "127.0.0.1", 40);
	lstn(&nm);
	acpt(&nm);

	char* text = recieve(&nm);
	printf("%s", text);

	cls(&nm);
	return 0;
}
