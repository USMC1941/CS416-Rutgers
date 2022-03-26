# CS416 Assignment 0: The Segfault That Wasn't

## Overview

In this assignment you will take some skeleton code that dereferences memory address 0, and cause it to run to completion through the clever use of a signal handler.

This assignment is intended to expand upon and reinforce details of the stack, processes and how the OS executes code.

You will need to do a fair amount of investigation and reading in order to accomplish this assignment. If you are unfamiliar or uncomfortable with C, it will take longer.

When you compile, be sure to use 32-bit mode (`-m32`) and no optimizations (`-O0`) in order to make your code as consistent as possible between runs.

This assignment is individual. Feel free to converse with other students about the assignment, but do not collaborate.

## Specifics of Operation

Taking the skeleton code attached below, add a signal handler that causes the code to run to completion.

-   You can not change any code BUT the signal handler.

The signal handler in the code will be called on any segmentation violation.

-   Dereferencing memory address `0` is pretty much guaranteed to do that.

Linux will first run your signal handler to give you a chance to address the segment fault.

-   If you return from the signal handler and the same signal occurs, then Linux will stop your code with a segmentation fault.

You must, in the signal handler only, make sure the segmentation fault does not occur a second time.

The problem is that Linux will attempt to run the offending instruction again.

-   So you must somehow make it not run that instruction.

The key to doing this is the signal number.

---

When your code hits the segment fault, it asks the OS what to do.

-   The OS notices you have a signal handler declared, so it hands the reins over to your signal handler.
-   In the signal handler, you get a signal number as an input to tell you which type of signal occurred.

This is the start of your cunning plan.

-   That integer is sitting in the stored stack of your code that had been running.
-   If you grab the address of that `int`, you can then build a pointer TO your code's stored stack frame, pointing at the place where the flags and signals are stored.
-   You can now manipulate ANY value in your code's stored stack frame.

You can't change the access of memory address `0`, but you can make it not happen.

You need to advance the program counter manually, so that when your signal handler returns, the OS will load your code, but it will start running it AFTER the bad access, making it as if the bad access never happened.

---

### Things you will need to find out:

1. Where is the program counter stored, relative to where the signal/flags are stored?

-   Once you know this, you can increment the pointer pointing to the segment fault flag to point at the program counter

2. How long is the bad instruction?

-   You need to look at the assembly and determine how long the bad instruction is in order to increment the program counter by the correct amount to skip to the next instruction.

### Some helpful bits:

-   You can compile C to assembly, rather than machine code, by compiling with the `-S` switch.
-   You can compile C with debugging information by using the `-g` switch, so that you can use GDB, the C debugger.
    -   You can do a lot of things with GDB.
    -   You can, for instance, step through the code line by line until it segment faults, and look at stack frame data as you go.

## Resources

Attached is the skeleton code you should edit.

## Submission

-   Submit your code through Sakai before the due date.
-   Your code must operate on one of the iLab machines.
-   Your code must use the attached C code as a base.
-   You must not change the main function, but you may alter the signal handler.
-   Note your name and the iLab machine you wrote and tested your code on as comment at the top of the file.
-   Submit your undead source code on Sakai, being sure to note in the comments which machine you ran and tested your code on.
