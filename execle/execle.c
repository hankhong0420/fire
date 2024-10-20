#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
	int err;
	char *envp[] = {
	"/bin",NULL
	};
	printf("this is a execle function test demo ! \n");
	err = execle("/bin/ls","ls","-la",NULL,envp);
	if (err < 0){
		printf("execle fail \n");
	}

	return 0;

}
