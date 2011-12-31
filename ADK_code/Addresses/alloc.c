/**
 * @file alloc.c    Task to allocate fixed number of elements.
 * @brief Example to simply time the allocation of a fixed number of
 * elements whose size is determined by the user.
 * 
 * @author George Heineman
 * @date 6/15/08
 */

#include <stdlib.h>

/** Number of instances to allocate. */
int numT = 1048576;

/** Storage for each of these allocated objects. */
void *addr[1048576];

/** In this context, this becomes the SIZE of the allocated space, as directed by the -n command line argument. <b>Note: This behavior is unusual. You have been warned. </b> */
extern int numElements;

/** No preprocessing needed. */
void prepareInput() {

}

/** Execute by invoking malloc(numElements) a total of numT times. */
void execute() { 
  int i;

  for (i = 0; i < numT; i++) {
    addr[i] = malloc(numElements);
  }
}

/** No postprocessing needed. */
void postInputProcessing() { 
}

/** No specific problem usage. */
void problemUsage() { 

}

