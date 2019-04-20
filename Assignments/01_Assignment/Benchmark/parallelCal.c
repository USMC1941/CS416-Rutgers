// File:	parallelCal.c
// Author:	Yujie REN
// Date:	09/23/2017

#include <stdio.h>
#include <unistd.h>

#include <pthread.h>

#include "../my_pthread_t.h"

#define DEFAULT_THREAD_NUM 4

#define C_SIZE 100000
#define R_SIZE 10000

pthread_mutex_t   mutex;

int thread_num;

int* counter;
pthread_t *thread;

int*    a[R_SIZE];
int	 pSum[R_SIZE];
int  sum = 0;

/* A CPU-bound task to do parallel array addition */
void parallel_calculate(void* arg) {
	int i = 0, j = 0;
	int n = *((int*) arg);

	for (j = n; j < R_SIZE; j += thread_num) {
		for (i = 0; i < C_SIZE; ++i) {
			pSum[j] += a[j][i] * i;
		}
	}
	for (j = n; j < R_SIZE; j += thread_num) {
		pthread_mutex_lock(&mutex);
		sum += pSum[j];
		pthread_mutex_unlock(&mutex);
	}
}

/* verification function */
void verify() {
	int i = 0, j = 0;
	sum = 0;
	memset(&pSum, 0, R_SIZE*sizeof(int));

	for (j = 0; j < R_SIZE; j += 1) {
		for (i = 0; i < C_SIZE; ++i) {
			pSum[j] += a[j][i] * i;
		}
	}
	for (j = 0; j < R_SIZE; j += 1) {
		sum += pSum[j];
	}
	printf("verified sum is: %d\n", sum);
}

int main(int argc, char **argv) {
	int i = 0, j = 0;
	
	if (argc == 1) {
		thread_num = DEFAULT_THREAD_NUM;
	} else {
		if (argv[1] < 1) {
			printf("enter a valid thread number\n");
			return 0;
		} else
			thread_num = atoi(argv[1]);
	}

	// initialize counter
	counter = (int*)malloc(thread_num*sizeof(int));
	for (i = 0; i < thread_num; ++i)
		counter[i] = i;

	// initialize pthread_t
	thread = (pthread_t*)malloc(thread_num*sizeof(pthread_t));

	// initialize data array
	for (i = 0; i < R_SIZE; ++i)
		a[i] = (int*)malloc(C_SIZE*sizeof(int));

	for (i = 0; i < R_SIZE; ++i)
		for (j = 0; j < C_SIZE; ++j)
			a[i][j] = j;

	memset(&pSum, 0, R_SIZE*sizeof(int));

	// mutex init
	pthread_mutex_init(&mutex, NULL);

	struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

	for (i = 0; i < thread_num; ++i)
		pthread_create(&thread[i], NULL, &parallel_calculate, &counter[i]);

	for (i = 0; i < thread_num; ++i)
		pthread_join(thread[i], NULL);

	clock_gettime(CLOCK_REALTIME, &end);
    printf("running time: %lu micro-seconds\n", (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000);

	printf("sum is: %d\n", sum);

	// mutex destroy
	pthread_mutex_destroy(&mutex);

	// feel free to verify your answer here:
	verify();

	// Free memory on Heap
	free(thread);
	free(counter);
	for (i = 0; i < R_SIZE; ++i)
		free(a[i]);

	return 0;
}
