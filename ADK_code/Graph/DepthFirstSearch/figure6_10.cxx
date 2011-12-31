/**
 * @file figure6_10.cxx    Contains Figure for book.
 * @brief 
 *   Sample graph to be used to generate figure in book.
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include <iostream>

#include "dfs.h"

/** Example to use in Chapter 6 */
int main (int argc, char **argv) {
  int n = 16;
  Graph g (n,false);

  g.addEdge (0, 6,  3);
  g.addEdge (0, 8,  7);
  g.addEdge (0, 1,  7);
  g.addEdge (1, 3,  2);
  g.addEdge (1, 2,  2);
  g.addEdge (2, 10, 1);
  g.addEdge (2, 11, 8);

  g.addEdge (3, 4,  3);
  g.addEdge (3, 12, 4);
  g.addEdge (4, 5,  2);
  g.addEdge (4, 13, 1);
  g.addEdge (5, 9,  1);
  g.addEdge (5, 6,  3);
  g.addEdge (7, 9,  3);
  g.addEdge (8, 14, 2);
  g.addEdge (7, 8,  1);
  g.addEdge (6, 7,  3);

  g.addEdge (9, 15, 13);

  // prepare output values.
  vector<int> d(g.numVertices());
  vector<int> f(g.numVertices());
  vector<int> pred(g.numVertices());
  list<EdgeLabel> labels; 

  // compute
  dfs_search (g, 0, d, f, pred, labels);

  for (int i = 0; i < n; i++) {
    cout << i << ": " << pred[i] << " " << d[i] << "-" << f[i] << " " << "\n";
  }

  cout << " Note that this graph is undirected which means that\n";
  cout << " All edges appear twice in the graph\n";
  // the order of the edges reflects the order of the search
  for (list<EdgeLabel>::const_iterator it = labels.begin();
       it != labels.end(); ++it) {
    EdgeLabel ei = (*it);
    cout << ei.describe() << "\n";
  }
}


