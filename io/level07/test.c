#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        int count = -1073741813; //atoi(argv[1]);
        int buf[10];

	if (count >= 10) {
		printf("count didn't pass constraint: < 10\n");
		return 1;
	}

	int test = count << 2;

	printf("signed:\t\t%d\n", count);
	printf("unsigned:\t%u\n", count);
	printf("test:\t%u (%d)\n", test, test);
	memcpy(buf, argv[2], count * sizeof(int));
	printf("buf:\t\t[%s]\n", buf);

        return 0;
}

