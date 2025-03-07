#include "../headers/client_func.h"

int get_creds(mail* info){
	char mail_cp[100];
	strcpy(mail_cp, info->mail);

	char* pch = strchr(info->mail, '@');
	long int place = pch-info->mail+1;
	
	if (pch != NULL) {
		memmove(info->username, mail_cp, place-1);
		memmove(mail_cp, mail_cp+place, strlen(info->mail)-place);
		memmove(info->ip_addr, mail_cp, strlen(info->mail)-place);
		return 0;
	}else
		return 1;
}

char* process_coms(char* text, mail* info){
	char* answer = "ERRR";
	char str[8];
	strncpy(str, text, 5);

	if (strcmp(str, "USRQ") == 0){
		char output[28] = "USNM ";
		strcat(output, info->username);
		answer = output;
	}else if (strcmp(str, "BYE") == 0){
		info->run = 0;
		answer = "BYE";
	}

	return answer;
}
