/**
 * @file Graph/DepthFirstSearch/test2.cxx   Test Case for Depth-First Search
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

/** cormen example, p. 481,  first edition */
int main (int argc, char **argv) {
  int n = 8;
  int i;
  Graph g(n,true);

  g.addEdge (0, 4);
  g.addEdge (1, 5);
  g.addEdge (1, 0);
  g.addEdge (4, 1);
  g.addEdge (5, 4);
  g.addEdge (2, 5);
  g.addEdge (2, 1);
  g.addEdge (6, 2);
  g.addEdge (6, 5);
  g.addEdge (3, 7);
  g.addEdge (3, 6);
  g.addEdge (7, 6); 
  g.addEdge (7, 3);

  vector<int> d(g.numVertices());
  vector<int> f(g.numVertices());
  vector<int> pred(g.numVertices());
  list<EdgeLabel> labels;

  dfs_search (g, 2, d, f, pred, labels);

  for (i = 0; i < n; i++) {
    cout << i << ": " << d[i] << "-" << f[i] << " " << pred[i] << "\n";
  }

  for (list<EdgeLabel>::const_iterator it = labels.begin();
       it != labels.end(); ++it) {
    EdgeLabel ei = (*it);
    cout << ei.describe() << "\n";
  }

  // spot check some (hardly sufficient! but just a quick check).
  assert (d[1] == 2);
  assert (f[1] == 9);
  assert (pred[1] == 2);

  // some edge types known from graph. These are a better test case
  for (list<EdgeLabel>::const_iterator it = labels.begin();
       it != labels.end(); ++it) {
    EdgeLabel ei = (*it);

    // a cross
    if (ei.src() == 6 && ei.target() == 2) {
      assert (ei.type() == Cross);
    }

    // a tree
    if (ei.src() == 2 && ei.target() == 1) {
      assert (ei.type() == Tree);
    }

    // a back
    if (ei.src() == 4 && ei.target() == 1) {
      assert (ei.type() == Backward);
    }

    // a cross
    if (ei.src() == 6 && ei.target() == 2) {
      assert (ei.type() == Cross);
    }
  }

  cout << "Passed test\n";

}

