#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Contributed by Torch

int limit, c;
int getebp() { __asm__("movl %ebp, %eax"); }

void f(char *s)
{
	int *i;
	char buf[260];

	i = (int *)getebp();
	limit = *i - (int)buf + 1;

	for (c = 0; c < limit && s[c] != '\0'; c++)
		buf[c] = s[c];
}

int main(int argc, char **argv)
{
	int cookie = 1000;

	if (argc != 2) exit(1);
		f(argv[1]);

	if ( cookie == 0xdefaced ) {
		setresuid(geteuid(), geteuid(), geteuid());
		execlp("/bin/sh", "/bin/sh", "-i", NULL);
	}

	return 0;
}

