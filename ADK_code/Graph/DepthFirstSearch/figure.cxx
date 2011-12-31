/**
 * @file Graph/DepthFirstSearch/figure.cxx    Contains Figure for book.
 * @brief 
 *   Sample graph to be used to generate figure in book. Ultimately used
 *   by Dijkstra's algorithm.
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include <iostream>

#include "Graph.h"
#include "dfs.h"

/** figure 6-14 for Algorithms in Nutshell. */
int main (int argc, char **argv) {
  int n = 6;
  int i;
  Graph g (n,true);


  g.addEdge (0, 1, 6);
  g.addEdge (1, 4, 11);
  g.addEdge (0, 3, 18);
  g.addEdge (0, 2, 8);
  g.addEdge (2, 3, 9);
  g.addEdge (5, 2, 7);
  g.addEdge (4, 5, 3);
  g.addEdge (5, 3, 4);

  vector<int> d(g.numVertices());
  vector<int> f(g.numVertices());
  vector<int> pred(g.numVertices());
  list<EdgeLabel> labels; 

  dfs_search (g, 0, d, f, pred, labels);

  for (i = 0; i < n; i++) {
    cout << i << ": " << d[i] << "-" << f[i] << " " << pred[i] << "\n";
  }

  for (list<EdgeLabel>::const_iterator it = labels.begin();
       it != labels.end(); ++it) {
    EdgeLabel ei = (*it);
    cout << ei.describe() << "\n";
  }

}



