// Author: John-Austen Francisco
// Date: 11 January 2018
//
// Preconditions: Appropriate C libraries, iLab machines
// Postconditions: Generates Segmentation Fault for
//                               signal handler self-hack

// Student name:
// Ilab machine used:

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void segment_fault_handler(int signum)
{
   printf("I am slain!\n");

   //Use the signnum to construct a pointer to flag on stored stack
   int *p;
   p = &signum; // Signal handling uses main thread stack. Here, p points to the handler's frame.

   //Increment pointer down to the stored PC

   // Test code to find PC in stored registers when switch to kernel
   //int i = 0;
   //for (i=0; i<=0x10; i++) {
   //	printf("Pointer int: %p\n", *(p+i));
   //}
   p = p + 0xF; // p points to PC of previously stored context

   //Increment value at pointer by length of bad instruction

   /*
   Skip over the following offending instructions (6 bytes):
   8048520:	8b 00                	mov    (%eax),%eax		// This instruction causes segmentation fault. eax is 0.
   8048522:	89 44 24 1c          	mov    %eax,0x1c(%esp)	// Assignment instruction. Part of this statement: r2 = *( (int *) 0 );
   */
   *p += 0x6;
}

int main()
{
   int r2 = 0;

   signal(SIGSEGV, segment_fault_handler);

   r2 = *((int *)0);

   printf("I live again!\n");

   return 0;
}
