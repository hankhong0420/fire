#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig)
{
	printf("\n this signal numble is %d ",sig);
	if(sig == SIGINT){
		printf(" i have get sigint \n");
		printf("the signal is automatically restored to the default handler \n");
	}
}

int main()
{
	struct sigaction act ;
	printf("this is sigaction function test \n");
	act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &act, NULL);
	while(1){
		printf("wait for the SIGINT , pleaese ctrl +c \n");
	sleep(1);

	}

	exit(0);

}
