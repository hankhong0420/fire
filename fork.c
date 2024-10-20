#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	pid_t result;
	printf("This is a fork demo \n");
	result = fork();
	if(result == -1 ){
		printf("fork error");


	}else if (result == 0){
		printf("The returned value is %d, in chield process,my pid is %d", result,getpid());
	

	}else{
		printf("The returned value is %d ,in father process, my pid is %d ", result,getpid());
	}
	return result;

}
