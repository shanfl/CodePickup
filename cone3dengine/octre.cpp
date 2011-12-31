#include <GL/gl.h>

#include "mmgr.h"

#include "texture.h"
#include "frustum.h"
#include "vector.h"
#include "trigs.h"
#include "octre.h"
#include "log.h"

#define NUMTRISINNODE 10

long numdrawn=0;
int lines=0;

int incube(CTriangle *triangles, int *tris, int id, int t, float xc, float yc, float zc, float w)
{
  float xmin, xmax, ymin, ymax, zmin, zmax;
  if(t==0) {xmin=xc-w;ymin=yc-w;zmin=zc-w;xmax=xc;ymax=yc;zmax=zc;}
  if(t==1) {xmin=xc;ymin=yc-w;zmin=zc-w;xmax=xc+w;ymax=yc;zmax=zc;}
  if(t==2) {xmin=xc-w;ymin=yc;zmin=zc-w;xmax=xc;ymax=yc+w;zmax=zc;}
  if(t==3) {xmin=xc;ymin=yc;zmin=zc-w;xmax=xc+w;ymax=yc+w;zmax=zc;}
  if(t==4) {xmin=xc-w;ymin=yc-w;zmin=zc;xmax=xc;ymax=yc;zmax=zc+w;}
  if(t==5) {xmin=xc;ymin=yc-w;zmin=zc;xmax=xc+w;ymax=yc;zmax=zc+w;}
  if(t==6) {xmin=xc-w;ymin=yc;zmin=zc;xmax=xc;ymax=yc+w;zmax=zc+w;}
  if(t==7) {xmin=xc;ymin=yc;zmin=zc;xmax=xc+w;ymax=yc+w;zmax=zc+w;}

  // The position of the triangle
  float tri[3][3]={
  {triangles[tris[id]].v[0].x,triangles[tris[id]].v[0].y,triangles[tris[id]].v[0].z},
  {triangles[tris[id]].v[1].x,triangles[tris[id]].v[1].y,triangles[tris[id]].v[1].z},
  {triangles[tris[id]].v[2].x,triangles[tris[id]].v[2].y,triangles[tris[id]].v[2].z}};

  // Here we just build a box on the info we got
  float triz[12][3][3] =
  {
    {{xmin,ymin,zmax},{xmax,ymin,zmax},{xmax,ymax,zmax}},
    {{xmin,ymin,zmax},{xmax,ymax,zmax},{xmin,ymax,zmax}},
    {{xmin,ymin,zmin},{xmax,ymin,zmin},{xmax,ymax,zmin}},
    {{xmin,ymin,zmin},{xmax,ymax,zmin},{xmin,ymax,zmin}},
    {{xmin,ymin,zmin},{xmin,ymin,zmax},{xmin,ymax,zmin}},
    {{xmin,ymin,zmax},{xmin,ymax,zmax},{xmin,ymax,zmin}},
    {{xmax,ymin,zmin},{xmax,ymin,zmax},{xmax,ymax,zmin}},
    {{xmax,ymin,zmax},{xmax,ymax,zmax},{xmax,ymax,zmin}},
    {{xmin,ymin,zmin},{xmin,ymin,zmax},{xmax,ymin,zmax}},
    {{xmin,ymin,zmin},{xmax,ymin,zmax},{xmax,ymin,zmin}},
    {{xmin,ymax,zmin},{xmin,ymax,zmax},{xmax,ymax,zmax}},
    {{xmin,ymax,zmin},{xmax,ymax,zmax},{xmax,ymax,zmin}}
  };

  // Check the box with the triangle. If a match, then return 1
  for(int i=0;i<12;i++)
  {
    if(tri_tri_intersect(triz[i][0],triz[i][1],triz[i][2],tri[0],tri[1],tri[2]) == 1) return 1;
  }

  for(int i=0;i<3;i++)
  {
    float x=triangles[tris[id]].v[i].x, y=triangles[tris[id]].v[i].y, z=triangles[tris[id]].v[i].z;
    if(xmin<=x && x<=xmax && ymin<=y && y<=ymax && zmin<=z && z<=zmax) return 1;
  }
  return 0;
}

void COctree::togglelines()
{
  lines=!lines;
}

long COctree::getNumDrawn()
{
  return numdrawn;
}

void COctree::resetNumDrawn()
{
  numdrawn = 0;
}

int COctree::draw(CTriangle *triangles, CTexture *textures, long *framenr, CFrustum *frustum, int checkFrustum)
{
  if(built!=1) return 0;
  if(node==0)
  {
    if(checkFrustum == 1)
    {
      for(int i=0;i<8;i++)
      {
        int val=frustum->CubeLocation(nodes[i].centerpoint, nodes[i].w);
        if(val==FULL_INSIDE) nodes[i].draw(triangles,textures,framenr,frustum,0);
        else if(val==PARTIAL_INSIDE) nodes[i].draw(triangles,textures,framenr,frustum,1);
      }
    } else {
      for(int i=0;i<8;i++)
      {
        nodes[i].draw(triangles,textures,framenr,frustum,0);
      }
    }
  } else if(numtriangles>0 && built==1) {
    if(lines) {
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
      glVertex3f(xmin,ymin,zmin);
      glVertex3f(xmin,ymin,zmax);
      glVertex3f(xmax,ymin,zmin);
      glVertex3f(xmax,ymin,zmax);
      glVertex3f(xmin,ymax,zmin);
      glVertex3f(xmin,ymax,zmax);
      glVertex3f(xmax,ymax,zmin);
      glVertex3f(xmax,ymax,zmax);
      glVertex3f(xmin,ymin,zmin);
      glVertex3f(xmin,ymin,zmin);
      glVertex3f(xmin,ymin,zmin);
      glVertex3f(xmin,ymax,zmin);
      glVertex3f(xmax,ymin,zmin);
      glVertex3f(xmax,ymax,zmin);
      glVertex3f(xmin,ymax,zmin);
      glVertex3f(xmax,ymax,zmin);
      glVertex3f(xmin,ymin,zmax);
      glVertex3f(xmin,ymin,zmax);
      glVertex3f(xmin,ymin,zmax);
      glVertex3f(xmin,ymax,zmax);
      glVertex3f(xmax,ymin,zmax);
      glVertex3f(xmax,ymax,zmax);
      glVertex3f(xmin,ymax,zmax);
      glVertex3f(xmax,ymax,zmax);
    glEnd();
    glEnable(GL_TEXTURE_2D);
    }

    for(int i=0;i<numtriangles;i++)
    {
      if(triangles[tris[i]].drawn!=*framenr)
      {
        triangles[tris[i]].drawn=*framenr;
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D, textures[triangles[tris[i]].texture].texID);
        glNormal3f(triangles[tris[i]].normal.x,triangles[tris[i]].normal.y,triangles[tris[i]].normal.z);
        glBegin(GL_TRIANGLES);
        glTexCoord2f(triangles[tris[i]].v[0].u,triangles[tris[i]].v[0].v); glVertex3f(triangles[tris[i]].v[0].x,triangles[tris[i]].v[0].y,triangles[tris[i]].v[0].z);
        glTexCoord2f(triangles[tris[i]].v[1].u,triangles[tris[i]].v[1].v); glVertex3f(triangles[tris[i]].v[1].x,triangles[tris[i]].v[1].y,triangles[tris[i]].v[1].z);
        glTexCoord2f(triangles[tris[i]].v[2].u,triangles[tris[i]].v[2].v); glVertex3f(triangles[tris[i]].v[2].x,triangles[tris[i]].v[2].y,triangles[tris[i]].v[2].z);
        glEnd();
        numdrawn++;
      }
    }
  }
}

void COctree::demolish()
{
  if(node==1)
  {
    delete [] tris;
  } else {
    if(nodes[0].built == 1) nodes[0].demolish();
    if(nodes[0].built == 1) nodes[1].demolish();
    if(nodes[0].built == 1) nodes[2].demolish();
    if(nodes[0].built == 1) nodes[3].demolish();
    if(nodes[0].built == 1) nodes[4].demolish();
    if(nodes[0].built == 1) nodes[5].demolish();
    if(nodes[0].built == 1) nodes[6].demolish();
    if(nodes[0].built == 1) nodes[7].demolish();
    delete [] nodes;
  }

}

int COctree::build(CTriangle *triangles, int *triangles2, float xmi, float xma, float ymi, float yma, float zmi, float zma, int numtris)
{
  built=1;
  numtriangles=numtris;
  xmin=xmi;xmax=xma;ymin=ymi;ymax=yma;zmin=zmi;zmax=zma;
  xc=(xmin+xmax)/2;yc=(ymin+ymax)/2;zc=(zmin+zmax)/2;
  width=xma-xmi;
  w=width/2;
  centerpoint[0]=xc;
  centerpoint[1]=yc;
  centerpoint[2]=zc;

  if(numtriangles>NUMTRISINNODE && width>0.1)
  {
    node=0;
    int tr[8][numtriangles];
    int trc[8];
    trc[0]=0;trc[1]=0;trc[2]=0;trc[3]=0;trc[4]=0;trc[5]=0;trc[6]=0;trc[7]=0;
    for(int i=0;i<numtriangles;i++)
    {
      for(int j=0;j<8;j++)
      {
        if(incube(triangles,triangles2,i,j,xc,yc,zc,width/2)==1) {tr[j][trc[j]]=triangles2[i];trc[j]++;}
      }
    }
    nodes = new COctree[8];
    for(int j=0;j<8;j++)
    {
      if(trc[j]>0)
      {
        int *trr=new int[trc[j]];
        for(int i=0;i<trc[j];i++)
        {
          trr[i]=tr[j][i];
        }
        float xmn,xmx,ymn,ymx,zmn,zmx;
        if(j==0) {xmn=xc-w;ymn=yc-w;zmn=zc-w;xmx=xc;ymx=yc;zmx=zc;}
        if(j==1) {xmn=xc;ymn=yc-w;zmn=zc-w;xmx=xc+w;ymx=yc;zmx=zc;}
        if(j==2) {xmn=xc-w;ymn=yc;zmn=zc-w;xmx=xc;ymx=yc+w;zmx=zc;}
        if(j==3) {xmn=xc;ymn=yc;zmn=zc-w;xmx=xc+w;ymx=yc+w;zmx=zc;}
        if(j==4) {xmn=xc-w;ymn=yc-w;zmn=zc;xmx=xc;ymx=yc;zmx=zc+w;}
        if(j==5) {xmn=xc;ymn=yc-w;zmn=zc;xmx=xc+w;ymx=yc;zmx=zc+w;}
        if(j==6) {xmn=xc-w;ymn=yc;zmn=zc;xmx=xc;ymx=yc+w;zmx=zc+w;}
        if(j==7) {xmn=xc;ymn=yc;zmn=zc;xmx=xc+w;ymx=yc+w;zmx=zc+w;}
        nodes[j].build(triangles, trr, xmn, xmx, ymn, ymx, zmn, zmx, trc[j]);
        delete [] trr;
      } else {
        nodes[j].built=0;
      }
    }
  } else {
    node=1;
    tris = new int[numtriangles];
    for(int i=0;i<numtriangles;i++)
    {
      tris[i]=triangles2[i];
    }
  }
}

