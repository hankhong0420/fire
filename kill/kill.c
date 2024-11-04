#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int ret;
	if((pid =fork()) < 0){
		printf("fork error\n");
		exit(1);
	}

	if (pid == 0){
		printf("child pid : %d is wait for any singal\n", getpid());
		raise(SIGSTOP);
		exit(0);
	}else{
		sleep(1);
		if((waitpid(pid, NULL, WNOHANG)) == 0){
			if((ret = kill(pid, SIGKILL)) == 0){
				printf("parent kill %d \n", pid);
			}

		}
		waitpid(pid, NULL, 0);
		exit(0);
	}
}
