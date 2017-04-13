#include <stdio.h>
#include <unistd.h>
#include <string.h>

int good(int addr) {
        printf("Address of hmm: %p\n", addr);
}
                
int hmm() {
        printf("Win.\n");
        execl("/bin/sh", "sh", NULL);
}

extern char **environ;

int main(int argc, char **argv) {
	/* Stack layout for local variables:
	 * 
	 *  Offset	Length	Variable
	 *  0		4	i
	 *  4		4	limit
	 *  8		4	fptr
	 *  12		4	hmmptr
	 *  16		32	buf
	 *
	 * Possible overflow solution:
	 * 1. Input data size = 32 + 4 + 4
	 * 2. First 32 bytes is arbitary
	 * 3. Next 4 bytes must specify hmmptr's 
	 */

        int i, limit;

        for(i = 0; environ[i] != NULL; i++) 
        memset(environ[i], 0x00, strlen(environ[i]));

        int (*fptr)(int) = good;
        char buf[32];
        
        if(strlen(argv[1]) <= 40) limit = strlen(argv[1]);
        
        for(i = 0; i <= limit; i++) {
                buf[i] = argv[1][i];
		 if(i < 36) buf[i] = 0x41;
        }

        int (*hmmptr)(int) = hmm;

        (*fptr)((int)hmmptr);
        
        return 0;
        
}

