/**
 * @file Graph/DepthFirstSearch/test3.cxx   Test Case for Depth-First Search
 * @brief 
 *   A test case
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include <cassert>
#include <iostream>

#include "Graph.h"
#include "dfs.h"

/** My example to use in Chapter 6 */
int main (int argc, char **argv) {
  int n = 16;
  int i;
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

  // some edge types known from graph. These are a better test case
  for (list<EdgeLabel>::const_iterator it = labels.begin();
       it != labels.end(); ++it) {
    EdgeLabel ei = (*it);

    // a tree
    if (ei.src() == 0 && ei.target() == 1) {
      assert (ei.type() == Tree);
    }

    // a back
    if (ei.src() == 8 && ei.target() == 0) {
      assert (ei.type() == Backward);
    }

    // a forward
    if (ei.src() == 5 && ei.target() == 9) {
      assert (ei.type() == Forward);
    }

    // no CROSS EDGES in undirected graph
    assert (ei.type() != Cross);
  }

  cout << "Passed test\n";

}

