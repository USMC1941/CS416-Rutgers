# Benchmark

## Running
How to run the benchmark (Using `parallelCal` as an example)
   1. Copy benchmark folder to your pthread library directory and `make` your pthread
	2. `./make`
	3. Run `./parallelCal 6`, which means "create 6 user-level threads to run `parallelCal`". You could change this parameter to test how thread numbers affect performance.


You're free to modify `Makefile` in Benchmark if you add new files in your pthread library

To run each benchmark, if the result is same with the verified result (doing the same thing in a single thread), then your thread library is good.

Before running externalCal, run `genRecord.sh` first to generate some random records. 


## Updates:
Since the interface of your thread library starts with `my_pthread_XXX` while the benchmark uses `pthread_XXX`, I suggest that you add the following to the end of your library header file:

```c
#define USE_MY_PTHREAD 1   // Comment it if you want to use real pthread

#ifdef USE_MY_PTHREAD
#define pthread_t my_pthread_t
#define pthread_mutex_t my_pthread_mutex_t
#define pthread_create my_pthread_create
#define pthread_exit my_pthread_exit
#define pthread_join my_pthread_join
#define pthread_mutex_init my_pthread_mutex_init
#define pthread_mutex_lock my_pthread_mutex_lock
#define pthread_mutex_unlock my_pthread_mutex_unlock
#define pthread_mutex_destroy my_pthread_mutex_destroy
#endif
```

By doing so the benchmark will run your thread library instead of real pthread library.

You may also want to compare performance of your thread library and real pthread library in your report.
   * To test real pthread using this benchmark, just comment the first line of Macro (`#define USE_MY_PTHREAD 1`).

To make the running time of `genRecord` shorter, you could modify the `genRecord.sh` to decrease the iteration number (`1048576`) in the inner loop.