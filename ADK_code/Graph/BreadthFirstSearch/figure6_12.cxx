/**
 * @file figure6_12.cxx    Sample figure showing Breadth-First Search for book
 * @brief 
 *   Implementation of figure for book.
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include <cassert>
#include <iostream>

#include "bfs.h"

/**  Example to use in Chapter 6 */
int main (int argc, char **argv) {
  int n = 16;
  Graph g (16);

  g.addEdge (0, 8,  7);
  g.addEdge (0, 6,  3);
  g.addEdge (0, 1,  7);
  g.addEdge (1, 3,  2);
  g.addEdge (1, 2,  2);
  g.addEdge (2, 11, 8);
  g.addEdge (2, 10, 1);


  g.addEdge (3, 12, 4);
  g.addEdge (3, 4,  3);

  g.addEdge (4, 13, 1);
  g.addEdge (4, 5,  2);

  g.addEdge (5, 9,  1);
  g.addEdge (5, 6,  3);
  g.addEdge (6, 7,  3);
  g.addEdge (7, 9,  3);
  g.addEdge (7, 8,  1);
  g.addEdge (8, 14, 2);
  g.addEdge (9, 15, 13);

  // prepare output values.
  vector<int> d(n);
  vector<int> pred(n);

  bfs_search (g, 0, d, pred);

  for (int i = 0; i < n; i++) {
    cout << i << ". " << d[i] << " " << pred[i] << "\n";
  }

  // obvious ones, but good enough.
  assert (pred[1] == 0);
  assert (d[1] == 1);

  assert (pred[15] == 9);
  assert (d[15] == 4);

  cout << "Passed Test\n";
}

