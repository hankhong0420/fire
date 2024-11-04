#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(void)
{
	int err;
	printf("this is a execlp function test demo ! \n");

	err = execlp("ls", "ls", "-la",NULL);
	if(err < 0){
		printf("execlp fail\n");


	}

	return 0;

}
