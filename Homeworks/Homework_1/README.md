# HW0: Skills Survey

## Instructions

* Be as truthful as possible on the questions below. 
* The goal is to accurately assess your abilities and to optimally place you with other students that will compliment you.  It is not to get every question right. 
* Please refrain from using external resources to try to find answers. 
* Use only what you knew before you saw this questionnaire, trial and error and perhaps the man pages.

## Preliminary Questions

NetID:

Expected Graduation Date (month/year):

Which section are you in:
* Section 1
* Section 2
* Section 3

Semesters Completed in Current Degree:

Undergrad Degree/Major: (circle)
* CS
* Math
* Stats
* Eng
* Bio
* Eco
* Other -

Grad Degree/Major: (circle)
* None yet
* CS
* Math
* Stats
* Eng
* Bio
* Eco
* Other -

Have you had a course in:
* Data Structures
* Discrete Math
* Computer Algorithms
* Operating Systems
* Computer Architecture

Rate Proficiency in: [0-9]
* UNIX\Linux
* Assembly
* C
* C++
* Java
* Python

Rate Proficiency in: [0-9]
* Programming
* Algorithms
* Proving Theorems
* Machine Learning
* Computer Systems
* Networking
* Compilers


Rate Proficiency in: [0-9]
* Physics
* EE
* Comp Eng
* Bio
* Stats

Describe Yourself As: [0-9]
* Programme
* Mathematician
* Engineer
* Technician
* Biologist
* Algorithmicist

## Questions

<ol start="0">
  <li>Predict the output of this snippit: </li>
  
  ```c
int main() {
	int main = 56;
	printf("%d\n", main);
	return 0;
}
  ```
 a) Compiler Error
 
b) Depends on the compiler

c) 5

d) none of above
 
  <li>Predict the output of this snippit: </li>
  
  ```c
#include <stdio.h>

int main() {
	char ch;
	if (ch = printf("")) {
		printf("It matters\n");
	}
	else {
		printf("It doesn't matter\n");
	}

	return 0;
}

  ```
  
a) It matters

b) It doesn’t matter

c) Run time error

d) Nothing
  
  <li>How many times is Hello world printed by the code snippit below?</li>
  
  ```c
  int main() {
	fork();
	fork();
	printf("Hello world\n");
}
  ```
a) 1

b) 2

c) 4

d) 8

  <li>What is the output of this C code?</li>
  
  ```c
  #include <stdio.h>

int main() {
	int x = 1, y = 0, z = 5;
	int a = x && y || ++z;

	printf("%d\n", z++);
}
  ```
a) 1

b) 5

c) 6

d) 7

  
  
  <li>What is the output of this C code?</li>
  
  ```c
  #include <stdio.h>

int main() {
	int y = 2;
	int z = y + (y = 10);
	printf("%d\n", z);
}
  ```
a) 2

b) 4

c) 20

d) Compile time error
 
  <li>What is the output of this C code?</li>
  
  ```c
  #define max(a) a

int main() {
	int x = 1;
	switch (x)
	{
		case max(2):
			printf("yes\n");
		case max(1):
			printf("no\n");
		break;
	}
}
  ```
  
a) yes

b) no

c) Runtime error

d) Compile time error

  <li>What is the output of this C code?</li>
  
  ```c
  #include <stdio.h>

int main() {
	int x = 35;
	printf("%d %d %d", x == 35, x = 50, x > 40);
}
  ```  
  
a) 1 50 1

b) 0 50 0

c) Runtime error

d) Compile time error

  <li>You have two numbers, A and B. 
  
  Using bitwise operations and loops, write code to determine how many bits must be flipped in order to turn A in to B.</li>

e.g.

A: 101001

B: 10**01**01

Answer: 2 bits

  <li>Presume you have an implementation of Quicksort that picks the first element in a list as its pivot. 
  
  Construct a list of 13 numbers that would make this algorithm run in O(n^2) time.</li>
  
 
  <li>Write code to solve the below in O(n) time with one pass over the array. If you can not, provide your best code and state the asymptotic running time.</li>
  
  * In this challenge, given an array of integers, the goal is to efficiently find the subarray that has the greatest positive value when all of its elements are summed together.
  * Write some code that, if given an array of integers, will find the subarray that has the greatest sum. A subarray is a contiguous subset of the original array.
  * Keep in mind the maximal subarray is not necessary a proper subset, and might contain the whole original array.
    * Be careful. Some array elements may be negative, so less can be more.
    * If all the elements in an array are negative, the maximal sum should be null as we are interested in the greatest positive value, not the greatest arithmetic value.
 * For example: Given the array: `{1, 2, -5, 4, -3, 2}`
    * The maximum sum of a subarray is 4 and it contains only the element 4.
 * Before you write the code, take some time to think of the most efficient solution possible; it may surprise you. The major goal of this question is to test your algorithmic skills rather than merely your ability to write code quickly.

  <li>RE pattern matching. 

  Draw an NFA (nondeterministic finite state automata) that recognizes the same language that the regular expression `((A*B | C )* | D )`</li>


  <li>Are there any preferences you have for grouping?</li>
</ol>
