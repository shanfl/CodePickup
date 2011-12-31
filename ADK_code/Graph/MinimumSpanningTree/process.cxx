/**
 * @file process.cxx   Driver for timing MST algorithmsn
 * @brief 
 *   Compute performance of Prim's algorithm.
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include <sys/time.h>

#include "mst.h"
#include "report.h"

/** Time before process starts.   */
static struct timeval before;

/** Time after process completes. */
static struct timeval after;

/**
 * Launch the application to time MST. 
 *
 * Command line options include:
 * <ul>
 * <li> <code>-f FILE</code> to load up the graph from a file.
 * <li> <code>-v</code> to output information in verbose mode.
 * </ul>
*/
int main (int argc, char **argv) {
  int idx;
  bool verbose = 0;
  char c;
  char *fileName = 0;

  opterr = 0;   // disable errors
  while ((c = getopt(argc, argv, "f:v")) != -1) {
    idx++;
    switch (c) {

    case 'f':
      fileName = strdup (optarg);
      break;

    case 'v':
      verbose = 1;
      break;

    default:
      break;
    }
  }
  optind = 0;  // reset getopt for next time around.

  if (fileName == 0) {
    printf ("Usage: [-v] -f file\n");
    exit (-1);
  }

  Graph graph(0);
  graph.load (fileName);

  int n = graph.numVertices();
  int i;
  vector<int> pred(n);

  printf ("loaded graph with %d vertices\n", n);
  try {
    gettimeofday(&before, (struct timezone *) NULL);    // begin time
    mst_prim(graph, pred);
    gettimeofday(&after, (struct timezone *) NULL);     // end time

    long usecs = diffTimer (&before, &after);           // show results
    printf("%s\n", timingString(usecs));

    if (verbose) {
      for (i = 0; i < n; i++) {
	printf ("%d. %d\n", i, pred[i]);
      }
    }
  } catch (char const *s) {
    printf ("%s\n", s);
  }
}
