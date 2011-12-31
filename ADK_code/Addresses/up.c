/**
 * @file up.c    Task to free elements from address table in order.
 * @brief Allocated memory stored in the 'addr' table are free'd in reverse order.
 * 
 * @author George Heineman
 * @date 6/15/08
 */

#include <stdlib.h>

/** Required code to populate addr table with appropriate number of allocated memory pointers */
extern void fillList();

/** Number of instances that were allocated. */
extern int numT;

/** The table of allocated memory. */
extern void *addr[];

/** Preprocess by populating the 'addr' table with all allocated memory. */
void prepareInput() {
  fillList();
}

/** Task to execute is to release all memory in order. */
void execute() { 
  int i;

  for (i = 0; i < numT; i++) {
    free (addr[i]);
    addr[i] = NULL;
  }
}
