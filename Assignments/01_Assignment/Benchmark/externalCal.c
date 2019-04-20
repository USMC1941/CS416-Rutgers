// File:	externalMerge.c
// Author:	Yujie REN
// Date:	09/23/2017

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#include <pthread.h>

#include "../my_pthread_t.h"

#define DEFAULT_THREAD_NUM 2
#define RAM_SIZE 160
#define RECORD_NUM 10
#define RECORD_SIZE 4194304

pthread_mutex_t   mutex;

int thread_num;

int* counter;
pthread_t *thread;

int *mem = NULL;

int sum = 0;

int itr = RECORD_SIZE / 16;

void external_calculate(void* arg) {
	int i = 0, j = 0, k = 0;
	int n = *((int*) arg);

	for (k = n; k < RECORD_NUM; k += thread_num) {

		char a[3];
		char path[20] = "./record/";

		sprintf(a, "%d", k);
		strcat(path, a);

		FILE *f;
		f = fopen(path, "r");
		if (!f) {
			printf("failed to open file %s, please run ./genRecord.sh first\n", path);
			exit(0);
		}

		for (i = 0; i < itr; ++i) {
			// read 16B from nth record into memory from mem[n*4]
			for (j = 0; j < 4; ++j) {
				fscanf(f, "%d", &mem[k*4 + j]);
				pthread_mutex_lock(&mutex);
				sum += mem[k*4 + j];
				pthread_mutex_unlock(&mutex);
			}
		}
		fclose(f);
	}
}

void verify() {
	int i = 0, j = 0, k = 0;

	char a[3];
	char path[20] = "./record/";

	sum = 0;
	memset(mem, 0, RAM_SIZE);

	for (k = 0; k < 10; ++k) {
		strcpy(path, "./record/");
		sprintf(a, "%d", k);
		strcat(path, a);

		FILE *f;
		f = fopen(path, "r");
		if (!f) {
			printf("failed to open file %s, please run ./genRecord.sh first\n", path);
			exit(0);
		}

		for (i = 0; i < itr; ++i) {
			// read 16B from nth record into memory from mem[n*4]
			for (j = 0; j < 4; ++j) {
				fscanf(f, "%d\n", &mem[k*4 + j]);
				sum += mem[k*4 + j];
			}
		}
		fclose(f);
	}

	printf("verified sum is: %d\n", sum);
}

void sig_handler(int signum) {
	printf("%d\n", signum);
}

int main(int argc, char **argv) {
	int i = 0;

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

	mem = (int*)malloc(RAM_SIZE);
	memset(mem, 0, RAM_SIZE);

	pthread_mutex_init(&mutex, NULL);

	struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

	for (i = 0; i < thread_num; ++i)
		pthread_create(&thread[i], NULL, &external_calculate, &counter[i]);

	signal(SIGABRT, sig_handler);
	signal(SIGSEGV, sig_handler);

	for (i = 0; i < thread_num; ++i)
		pthread_join(thread[i], NULL);

	clock_gettime(CLOCK_REALTIME, &end);
    printf("running time: %lu micro-seconds\n", (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000);

	printf("sum is: %d\n", sum);

	pthread_mutex_destroy(&mutex);

	// feel free to verify your answer here:
	verify();

	free(mem);
	free(thread);
	free(counter);

	return 0;
}
