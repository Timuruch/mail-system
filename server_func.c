#include "server_func.h"

char* check_coms(char* com) {
	char* response = "[404] No command implemented!";
	char str[20];

	strncpy(str, com, (sizeof(str)-1));
	
	if(strcmp(str, "LSRQ?") == 0) {
		response = "[100] Command done. Sandly no power to compute!";
	}

	return response;
}

