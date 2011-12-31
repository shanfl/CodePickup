#include "vector.h"

CVector3D cross(CVector3D v1,CVector3D v2)
{
  CVector3D temp;
  temp.x=(v1.y*v2.z)-(v1.z*v2.y);
  temp.y=(v1.z*v2.x)-(v1.x*v2.z);
  temp.z=(v1.x*v2.y)-(v1.y*v2.x);
  return temp;
}

static CVector3D calcnormal(CVector3D v1,CVector3D v2,CVector3D v3)
{
  CVector3D temp1, temp2, normal;
  temp1 = v3-v1; temp2 = v2-v1;
  normal=cross(temp1,temp2);
  normal.length();
  normal.normalize();
  return normal;
}

double dot(CVector3D v1, CVector3D v2)
{
  return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
}

// Inputs: plane origin, plane normal, ray origin, ray vector.
// NOTE: both vectors are assumed to be normalized
double intersect(CVector3D pOrigin, CVector3D pNormal, CVector3D rOrigin, CVector3D rVector)
{
  double d = -(dot(pNormal, pOrigin));
  double number = dot(pNormal,rOrigin) + d;
  double denom = dot(pNormal,rVector);
  return -(number/denom);
}

inline double lengthOfVector(CVector3D v) { return sqrt(v.x*v.x+v.y*v.y+v.z*v.z); };

CVector3D sphereIntersection(CVector3D point, double radius, CVector3D pOrigin, CVector3D pNormal)
{

}

CVector3D closestPointOnLine(CVector3D a, CVector3D b, CVector3D p)
{
  CVector3D c = p-a;
  CVector3D V = b-a;
  V.normalize();
  double d = V.getlength();;
  double t = dot(V,c);
  if(t < 0) return a;
  if(t > d) return b;

   V.x = V.x * t;
   V.y = V.y * t;
   V.z = V.z * t;

  return  a + V;
}

CVector3D closestPointOnTriangle(CVector3D a, CVector3D b, CVector3D c, CVector3D p)
{
  CVector3D Rab = closestPointOnLine(a,b,p);
  CVector3D Rbc = closestPointOnLine(b,c,p);
  CVector3D Rca = closestPointOnLine(c,a,p);

  double dAB = lengthOfVector(p-Rab);
  double dBC = lengthOfVector(p-Rbc);
  double dCA = lengthOfVector(p-Rca);
  
  double min = dAB;
  CVector3D result = Rab;
  
  if (dBC < min) {
    min = dBC;
    result = Rbc;
  }
 
  if (dCA < min)
   result = Rca;

  return (result);	
}

