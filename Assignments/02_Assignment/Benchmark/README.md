# Benchmark

## Instructions

How to run the benchmark (run `parallelCal` as an example)

1. Copy `Benchmark` folder to your pthread library directory and `make` your pthread.
2. Run `./make`
3. Run `./parallelCal 6` (which means create 6 user-level threads to run parallelCal. You could change this parameter to test how thread numbers affect performance)

## Notes

* You're free to modify `Makefile` in `Benchmark` if you add new files in your pthread library.
* To run each benchmark, if the result is same with the verified result (doing the same thing in a single thread), then your thread library is good.
* Before running `externalCal`, run `genRecord.sh` first to generate some random records.