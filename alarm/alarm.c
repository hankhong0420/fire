#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
	printf("\nthis is an alarm test function\n");
	alarm(12);
	sleep(20);
	printf("end\n");
	return 0;






}
