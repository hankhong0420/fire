#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int err;
	printf("this is a excel function test demo !\n");
	err = execl("/bin/ls","ls", "-la", NULL);
	if (err < 0){
		printf("exeel fail \n");



	}
	printf("Done \n");

	return 0;



}
