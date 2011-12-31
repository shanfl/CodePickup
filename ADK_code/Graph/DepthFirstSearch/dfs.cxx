/**
 * @file dfs.cxx    Contains the Depth-First Search implementation
 * @brief 
 *   Implementation of Depth First Search algorithm over a graph.
 *
 * @author George Heineman
 * @date 6/15/08
 */

#include "dfs.h"

/** 
 * Visit a vertex, u, in the graph and update information.
 * \param graph    the graph being searched.
 * \param u        the vertex being visited.
 * \param d        array of counter values when each vertex is discovered.
 * \param f        array of counter values when each vertex is finished.
 * \param pred     array of previous vertices in the depth-first search tree.
 * \param color    array of vertex colors in the depth-first search tree.
 * \param ctr      counter to use for assigning d[] and f[] values.
 * \param labels   structure to store all edge labels.
 */
void dfs_visit (Graph const &graph, int u,               /* in */
	 vector<int> &d, vector<int> &f,                 /* out */
	 vector<int> &pred, vector<vertexColor> &color,  /* out */
	 int &ctr, list<EdgeLabel> &labels) {            /* out */
  color[u] = Gray;
  d[u] = ++ctr;

  // process all neighbors of u.
  for (VertexList::const_iterator ci = graph.begin(u);
       ci != graph.end(u); ++ci) {
    int v = ci->first;

    // Compute edgeType and add to labelings. Default to cross
    edgeType type = Cross;
    if (color[v] == White) { type = Tree; }
    else if (color[v] == Gray) { type = Backward; }
    else { if (d[u] < d[v]) type = Forward; }
    labels.push_back(EdgeLabel (u, v, type));

    // Explore unvisited vertices immediately and record pred[].
    // Once recursive call ends, backtrack to adjacent vertices.
    if (color[v] == White) {
      pred[v] = u;
      dfs_visit (graph, v, d, f, pred, color, ctr, labels);
    }
  }

  color[u] = Black;  // our neighbors are complete; now so are we.
  f[u] = ++ctr;
}

/**
 * Perform Depth First Search starting from vertex s, and compute the
 * values d[u] (when vertex u was first discovered), f[u] (when all
 * vertices adjacent to u have been processed), pred[u] (the predecessor
 * vertex to u in resulting depth-first search forest), and label edges
 * according to their type.
 *
 * \param graph    the graph being searched.
 * \param s        the vertex to use as the source vertex.
 * \param d        array of counter values when each vertex is discovered.
 * \param f        array of counter values when each vertex is finished.
 * \param pred     array of previous vertices in the depth-first search tree.
 * \param labels   structure to store all edge labels.
 */
void dfs_search (Graph const &graph, int s,          /* in */
	 vector<int> &d, vector<int> &f,             /* out */
	 vector<int> &pred, list<EdgeLabel> &labels) /* out */
{
  // initialize d[], f[], and pred[] arrays. Mark all vertices White
  // to signify unvisited. Clear out edge labels.
  int ctr = 0;
  const int n = graph.numVertices();
  vector<vertexColor> color (n, White);
  d.assign(n, -1);
  f.assign(n, -1);
  pred.assign(n, -1);
  labels.clear();

  // Search starting at the source vertex; when done, visit any
  // vertices that remain unvisited.
  dfs_visit (graph, s, d, f, pred, color, ctr, labels);
  for (int u = 0; u < n; u++) {
    if (color[u] == White) {
      dfs_visit (graph, u, d, f, pred, color, ctr, labels);
    }
  }
}
