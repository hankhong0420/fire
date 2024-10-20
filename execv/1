#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int err;
	char *argv[] = {
	"ls","-la",NULL
};
	printf("this is execv function test demo");
	err = execv("/bin/ls", argv);
	if (err < 0){
		printf("execv fail\n");
	}



	return 0;
}
