#include <stdio.h>

static int count[256];

int main(int argc, char **argv) {

    int i, j;

    if(argc == 1) {
        printf("Usage: %s words\n", argv[0]);
        return 1;
    }

    /* Clear out the frequency buffer */
    for(i=0; i<256; i++)
        count[i] = 0;

    /* Fill the frequency buffer */
    for(j=1; argv[j]; j++)
        for(i=0; argv[j][i]; i++)
            count[argv[j][i]]++;

    /* Print out the frequency buffer */
    for(i=0; i<256; i++)
        if(count[i])
            printf("%c found %i time%s\n", i, count[i], count[i]-1?"s":"");

    return 0;
}
