#include <stdlib.h>
#include <mcheck.h>

/* This is an c++ example using the native mtrace functions.
 It can be used to verify that mtrace actually works on the current system.

 PREREQUISITE: set the env variable MALLOC_TRACE, the target log file
 like MALLOC_TRACE=~/mtrace.out

 COMPILE: g++ -o ./test test_mtrace.cc
 RUN: ./test
 
 After running the program there should be content in the specified log file.
  */
int main(void)
{

	mtrace(); /* Starts the recording of memory allocations and releases */
	double *a = NULL;
	a = (double *)malloc(sizeof(double));
	if (a == NULL)
	{
		return 1; // return error codeS
	}
	muntrace();
	return 0; 
}