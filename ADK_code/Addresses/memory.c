/**
 * @file memory.c    Stand-alone program to show examples of addresses
 * @brief Provide a small example to show how memory is allocated on the Stack and on the Heap.
 * 
 * @author George Heineman
 * @date 6/15/08
 */

#include <stdlib.h>
#include <string.h>

/** Function accesses the memory and creates its own internal storage. */
void f(char *inner) {
  char temp[11];
  strcpy (temp, "algorithms");
  int i;

  for (i=0; i<11; i++) {
    inner[i] = temp[i];
  }
}

/** Launch program to showcase addresses. */
int main (int argc, char **argv) {
  char *ar1 = malloc(132);
  char *ar2 = malloc(132);
  int i=17, j;

  f (ar2);
  return 0;
}
