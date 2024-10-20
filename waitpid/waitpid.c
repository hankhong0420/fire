#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid, child_pid;
	int status;
	
	pid = fork();
	if(pid < 0){
		printf("error fork");

	}else if( pid == 0){
		printf("I am a child process !, my pid is %d", getpid());
		sleep(3);
		printf(" I am about to quit the process\n");
		exit(0);
	}else{
		child_pid = waitpid(pid , &status, WUNTRACED);
		if(child_pid == pid){
			printf("GET exit child process id %d", child_pid);
			printf("GET child status:%d",status);
	}else{
		printf("some error occured");
	
	}
	exit(0);


	}




}
