#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	pid_t pid, child_pid;
	int status;
	pid = fork();

	if (pid < 0) {
		printf("error fork \n");
	}else if( pid == 0){
		printf("I am a child process , my pid is %d \n",getpid());
		sleep(3);
		printf("i am about to quit the process \n");
		exit(0);
	}else {
		child_pid = wait(&status);
		if(child_pid == pid){
			printf("get exit child process id %d",child_pid);
			printf("get child exit status:%d",status);
	}else{
		printf("some error occured\n");
	}
		exit(0);
	}
	
	return 0;


}
