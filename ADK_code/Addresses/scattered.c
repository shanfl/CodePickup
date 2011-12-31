/**
 * @file scattered.c    Task to free elements from address table in random order.
 * @brief Allocated memory stored in the 'addr' table are free'd in random order.
 * 
 * @author George Heineman
 * @date 6/15/08
 */

#include <stdio.h>
#include <stdlib.h>

/** Number of instances that were allocated. */
extern int numT;

/** Required code to populate addr table with appropriate number of allocated memory pointers */
extern void fillList();

/** The table of allocated memory. */
extern void *addr[];

/** Using number theory, identify an integer 'k' that can be used to cycle through all elements in addr by simple addition and modulo arithmetic. */
int k;

/** Use 32-bit mask rather than modulo for speed. */
int mask;

/** 
 * Compute the totient(i), which in number theory is the number of times to
 * which you can add i until you get back to zero (modulo the mask). 
 *
 * \param i
 * \return integer representing delta value to add
 */
int totient(int i) {
  int mark = 0;
  int totient = 0;
  do {
    totient++;
    mark = (mark + i) & mask;
  } while (mark != 0);
  return totient;
}

/** Preprocess by computing the totient of the given array. */
void prepareInput() {
  int i;
  mask = numT-1;
  fillList();

  /* now find p such that p cycles through all values of numT-1 */
  for (i = numT/2; i < numT; i++) {
    if (totient(i) == numT) {
      k = i;
      return;
    }
  }

  printf ("Can't find a k to cycle through all values.\n");
}

/** Free all memory. */
void execute() { 
  int i = 0;

  do {
    i = (i + k) & mask;
    free (addr[i]);
    addr[i] = 0;
  } while (i != 0); 
}
