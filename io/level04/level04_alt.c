/*
 *         semi realistic exploit dev level
 *                 
 *                         situation: sysadmin made powertop a suid so he can run it from normal user
 *
 *                                 bla
 *                                 */

#include <unistd.h>

int main(int argc, char**argv, char **env)
{
        execve("/usr/sbin/powertop", argv, env);
}
 
