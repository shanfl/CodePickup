/**
 * @file Graph/DepthFirstSearch/test1.cxx   Test Case for Depth-First Search
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

/** cormen example, p. 479, first edition  */
int main (int argc, char **argv) {
  int n = 6;
  int i;
  Graph g(n,true);

  g.addEdge (0, 3);
  g.addEdge (0, 1);
  g.addEdge (1, 4);
  g.addEdge (2, 5);
  g.addEdge (2, 4);
  g.addEdge (3, 1);
  g.addEdge (4, 3);
  g.addEdge (5, 5);

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

    // a cross
    if (ei.src() == 2 && ei.target() == 4) {
      assert (ei.type() == Cross);
    }

    // a tree
    if (ei.src() == 0 && ei.target() == 1) {
      assert (ei.type() == Tree);
    }

    // a back
    if (ei.src() == 3 && ei.target() == 1) {
      assert (ei.type() == Backward);
    }

    // a cross
    if (ei.src() == 2 && ei.target() == 4) {
      assert (ei.type() == Cross);
    }
  }

  cout << "Passed test\n";

}

