#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
void signal_handler(int sig)
{
	printf("\n this signal number is %d \n", sig);
	
	if( sig == SIGINT){
		printf(" i have get sigint \n");
		printf("the signal has restored to the default process mode \n ");
	signal(SIGINT, SIG_DFL);
	}
}

int main()
{
	printf("\n this is an alram test function");
	signal(SIGINT, signal_handler);
	while(1){
		printf("wait for the SIGINT signal , please enter ctrl +c \n ");
	sleep(1);
	}
	exit(0);
}
