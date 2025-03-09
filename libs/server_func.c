#include "../headers/server_func.h"

char* get_str(char* str, int begin, int end){
	char output[20] = { 0 };
	for (int x = begin;x < end;x++)
		output[begin-x] = str[x];
	char* out = output;
	return out;
}

char* check_coms(char* com, client* cl) {
	char* response = "ERRR";
	char str[8] = { 0 };
	char str_backup[30] = { 0 };

	strcpy(str_backup, com);
	printf("%ld,%ld\n", strlen(com), strlen(str_backup));
	printf("%s\n", str_backup);
	
	strncpy(str, str_backup, 4);
	printf("%s\n", str);

	if(strcmp(str, "LSRQ") == 0) {
		response = "USRQ";
	}else if (strcmp(str, "BYE") == 0){
		cl->is_conn = 0;
	}else if (strcmp(str, "USNM") == 0){/*
		char* username;
		username = get_str(com, 5, strlen(com));	*/
		printf("User: %s\n", str_backup);
		response = "BYE";
	}

	return response;
}

