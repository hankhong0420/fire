#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int err;
	char *argv[] = {
	"ls", "-la",NULL
	};
	char *envp[] = {
	"/bin", NULL
};
	printf("this is a execve function test demo \n");
	err = execve("/bin/ls", argv, envp);
	return 0;

}
