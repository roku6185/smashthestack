#include <string.h>

// A little learning is a dangerous thing; drink deep, or taste not the Pierian
// spring: there shallow draughts intoxicate the brain, and drinking largely 
// sobers us again - Alexander Pope

void do_the_nasty(char *argv[])
{
	char buf[32];
	strncpy(buf, argv[1], sizeof(buf));
	strncat(buf, argv[2], sizeof(buf)-strlen(buf)-1);
}

int main(int argc, char *argv[])
{
	do_the_nasty(argv);
	return 0;
}
