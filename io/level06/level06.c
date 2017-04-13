#include <string.h>

// The devil is in the details - nnp
void copy_buffers(char *argv[])
{
	char buf1[32], buf2[32], buf3[32];

	strncpy(buf2, argv[1], 31);
	strncpy(buf3, argv[2], sizeof(buf3));
	strcpy(buf1, buf3);
}

int main(int argc, char *argv[])
{
	copy_buffers(argv);
	return 0;
}
