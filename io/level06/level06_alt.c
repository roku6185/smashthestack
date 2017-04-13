#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>

char pass[32];

int main(int argc, char * argv[])
{

        char buf[32];
        FILE *f;

        f = fopen("level06_alt.pass", "r");

        fgets(pass, 32, f);
        fgets(buf, 999, stdin);

        if(!strcmp(buf, pass)) {
                printf("Success!\n");
                setreuid(geteuid(), geteuid());
                execl("/bin/sh", NULL, NULL);
        }

        return 0;
}
