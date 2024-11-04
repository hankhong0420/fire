#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
	unsigned int seconds;
	printf("\n this is an alarm test function\n");
	seconds = alarm(20);
	printf("last alarm seconds remaing is %d \n", seconds);
	printf("process sleep 5 senconds \n");
	sleep(5);
	printf("sleep woke up , rest alarm \n");
	seconds = alarm(5);
	printf("last alarm seconds remaining is %d \n", seconds);
	sleep(20);
	printf("end");

	return 0;


}
