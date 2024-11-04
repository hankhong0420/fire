#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUMBER 3
#define REPEAT_NUMBER 3
#define DELAY_TIME_LEVELS 3.0

sem_t sem[THREAD_NUMBER];
void *thread_func(void *arg)
{
	int num = (unsigned long long )arg;
	int delay_time = 0;
	int count = 0;
	sem_wait(&sem[num]);
	printf("thread %d is starting \n", num);
	for(count = 0 ; count < REPEAT_NUMBER; count++){
		delay_time = (int)(rand() * DELAY_TIME_LEVELS/(RAND_MAX)) + 1;
	sleep(delay_time);
	printf(" Thread %d :kob %d delay = %d\n", num, count,delay_time);
	}
	printf("thread %d finished \n", num);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread[THREAD_NUMBER];
	int no = 0,res;
	void *thread_ret;
	srand(time(NULL));
	for( no =0; no <  THREAD_NUMBER; no++){
		sem_init(&sem[no], 0, 0);
		res = pthread_create(&thread[no], NULL, thread_func, (void *)(unsigned long long) no);
		if( res != 0){
			printf("create thread %d failed \n", no);
			exit(res);
		}
	}
	printf("create treads success\n waiting for threads to finish \n");
	sem_post(&sem[ THREAD_NUMBER -1);
	for( no = THREAD_NUMBER -1; no >= 0; no --){
		res = pthread_join(thread[no], &thread_ret);
		if(!res){
			printf("thread %d joined \n", no);
		}else{
			printf("thread %d join failed \n", no);

		}
		sem_post(&sem[(no + THREAD_NUMBER -1) % THREAD_NUMBER] );

	}
	
	for (no = 0; no < THREAD_NUMBER; no++){
		sem_destory(&sem[no]);
	}
	return 0;
}
