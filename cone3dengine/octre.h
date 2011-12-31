#ifndef __OCTREE_H__
#define __OCTREE_H__

class COctree
{
  public:
//  ~COctree() { if(node==1) delete [] tris; }
  int build(CTriangle *triangles, int *triangles2, float xmi, float xma, float ymi, float yma, float zmi, float zma, int numtris);
  int draw(CTriangle *triangles, CTexture *textures, long *framenr, CFrustum *frustum, int checkFrustum);
  long getNumDrawn();
  void resetNumDrawn();
  void demolish();
  void togglelines();

  int node;
  int numtriangles;
  float xmin, ymin, zmin, xmax, ymax, zmax, xc, yc, zc, width, w, centerpoint[3];
  int *tris;
  int built;
  COctree *nodes;
};

#endif

