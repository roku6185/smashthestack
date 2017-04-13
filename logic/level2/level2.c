#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char **argv) {
	if (argc < 2) { printf("Fail. More Args...\n"); return 1; } 
	else {
		setresuid(geteuid(),geteuid(),geteuid());
		char buf2[4096];
		char buf[16];
		const char password[]="XXXXXXXXXXX";
		strncpy(buf, argv[1], sizeof(buf) - 1);
		if (strcmp(buf,password) != 0) {
			printf("Wrong.\n");
			return 1;
		}
		else {
			strcpy(buf2,argv[2]);
			printf("%s",buf2);
			return 0;
		}
	}
}
