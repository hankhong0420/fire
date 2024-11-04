#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUMBER 3
#define sleep_TIME_LEVELS 4.0
pthread_mutex_t mutex;
void *thrd_func(void *arg)
{
	int num = (unsigned long long)arg;
	int sleep_time = 0;
	int res;
	res = pthread_mutex_lock(&mutex);
	if(res){	
		printf("Thread %d lock failed \n",num);
		pthread_mutex_unlock(&mutex);
		pthread_exit(NULL);
	}
	printf("Thread %d is hold mutex \n", num);
	sleep_time = (int )(rand() * sleep_TIME_LEVELS / (RAND_MAX))+1;
	printf("thread %d :sleep %d \n",num, sleep_time);
	sleep(sleep_time);
	printf("Thread %d freed mutex \n", num);
	
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread[THREAD_NUMBER];
	int num = 0, res;
	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	for(num = 0; num < THREAD_NUMBER; num++)
	{
		res = pthread_create(&thread[num], NULL,thrd_func,(void*) (unsigned long long)num);
		if(res != 0){
			printf("create thread %d failed \n", num);
			exit(res);
		}

	}

	for(num = 0; num < THREAD_NUMBER; num++){
		pthread_join(thread[num], NULL);

	}
	pthread_mutex_destroy(&mutex);
	return 0;



}
