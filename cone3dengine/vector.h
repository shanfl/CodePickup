#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>

class CVector3D
{
  public:
  CVector3D() {x=0;y=0;z=0;}
  CVector3D(double xx, double yy, double zz) {x=xx;y=yy;z=zz;};

  double getlength() { return sqrt(x*x+y*y+z*z); }
  void normalize() { double mag=sqrt(x*x+y*y+z*z); x=x/mag;y=y/mag;z=z/mag; }

  CVector3D operator+ (CVector3D v2)
  {
    CVector3D temp;
    temp.x=x+v2.x;
    temp.y=y+v2.y;
    temp.z=z+v2.z;
    return temp;
  }

  CVector3D operator- (CVector3D v2)
  {
    CVector3D temp;
    temp.x=x-v2.x;
    temp.y=y-v2.y;
    temp.z=z-v2.z;
    return temp;
  }

  CVector3D operator* (CVector3D v2)
  {
    CVector3D temp;
    temp.x=x*v2.x;
    temp.y=y*v2.y;
    temp.z=z*v2.z;
    return temp;
  }

  CVector3D operator/ (CVector3D v2)
  {
    CVector3D temp;
    temp.x=x/v2.x;
    temp.y=y/v2.y;
    temp.z=z/v2.z;
    return temp;
  }

  CVector3D operator/ (double scalar)
  {
    CVector3D temp;
    temp.x=x/scalar;
    temp.y=y/scalar;
    temp.z=z/scalar;
    return temp;
  }

  CVector3D operator* (double scalar)
  {
    CVector3D temp;
    temp.x=x*scalar;
    temp.y=y*scalar;
    temp.z=z*scalar;
    return temp;
  }

  double x,y,z,u,v;
};

struct CTriangle
{
  CVector3D v[3];
  CVector3D normal;
  int texture;
  int id;
  long drawn;
  float d;
};

#endif

