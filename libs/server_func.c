#include "../headers/server_func.h"

char* check_coms(char* com, client* cl) {
	char* response = "[404] No command implemented!";
	char str[8];
	
	printf("%s\n", com);

	strncpy(str, com, 5);

	if(strcmp(str, "LSRQ") == 0) {
		response = "USRQ";
	}else if (strcmp(str, "BYE") == 0){
		cl->is_conn = 0;
	}else if (strcmp(str, "USNM") == 0){
		printf("BYES\n");
		response = "BYE";
	}

	return response;
}

