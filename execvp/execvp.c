#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int err;
	char *argv[]={
	"ls","-la",NULL
};
	printf("this is a execvp function test demo\n");

	err = execvp("ls", argv);
	if(err < 0) {
	printf("execvp fail \n");
}
	return 0;
}
