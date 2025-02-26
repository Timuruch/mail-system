#include "client_func.h"

int get_creds(mail info){
	char mail_cp[100];
	strcpy(mail_cp, info.mail);
	printf(mail_cp);

	char* pch = strchr(info.mail, '@');
	long int place = pch-info.mail+1;
	
	if (pch != NULL) {
		memmove(info.username, mail_cp, place-1);
		memmove(mail_cp, mail_cp+place, strlen(info.mail)-place);
		memmove(info.ip_addr, mail_cp, strlen(info.mail)-place);
		return 0;
	}else
		return 1;
}
