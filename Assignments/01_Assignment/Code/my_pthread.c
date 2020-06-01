// File:	my_pthread.c
// Author:	Yujie REN
// Date:	09/23/2017

// name:
// username of iLab:
// iLab Server:

#include "my_pthread_t.h"

/* create a new thread */
int my_pthread_create(my_pthread_t *thread, pthread_attr_t *attr, void *(*function)(void *), void *arg)
{
   return 0;
}

/* give CPU possession to other user level threads voluntarily */
int my_pthread_yield()
{
   return 0;
}

/* terminate a thread */
void my_pthread_exit(void *value_ptr)
{
}

/* wait for thread termination */
int my_pthread_join(my_pthread_t thread, void **value_ptr)
{
   return 0;
}

/* initial the mutex lock */
int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr)
{
   return 0;
}

/* acquire the mutex lock */
int my_pthread_mutex_lock(my_pthread_mutex_t *mutex)
{
   return 0;
}

/* release the mutex lock */
int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex)
{
   return 0;
}

/* destroy the mutex */
int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex)
{
   return 0;
}