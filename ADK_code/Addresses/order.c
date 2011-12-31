/**
 * @file order.c    Base task definition for building 'addr' table.
 * @brief Constructs the 'addr' table full of allocated memory. Only later options (UP, DOWN, SCATTERED) determine the order in which it is free'd.
 * 
 * @author George Heineman
 * @date 6/15/08
 */

#include <stdlib.h>
#include <stdio.h>

/** Number of elements to allocate. */
int numT = 1048576;

/** Addresses to store the allocated memory. */
char *addr[1048576];

/** In this context, this becomes the SIZE of the allocated space, as directed by the -n command line argument. <b>Note: This behavior is unusual. You have been warned. </b> */
extern int numElements;

/** Should information be printed during the processing of this function? */
extern int verbose;

/** 
 * Constructs the 'addr' table to contain 'numT' allocated memory regions, each
 * of size 'numElements'.
 */
void fillList() {
  int i;
  for (i = 0; i < numT; i++) {
    addr[i] = malloc(numElements);
  }

  if (verbose) {
    for (i = 0; i < 10 && i< numT; i++) {
      printf ("%ld [size:%d] [distance from next:%ld]\n",
	      (long) addr[i], numElements, (long)(addr[i+1]-addr[i]));
    }
  }
}


/** Validate that all 'addr' entries are NULL. */
void postInputProcessing() { 
  int i;
    for (i = 0; i < numT; i++) {
      if (addr[i] != NULL) {
	printf ("Address %d was not free'd.\n");
	exit (1);
      }
    }
}

/** No specific problem usage flags. */
void problemUsage() { 

}

