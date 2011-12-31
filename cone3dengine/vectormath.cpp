#include "vector.h"
#include "vectormath.h"

#define PI 3.141592654
#define EPSILON 0.2f

CVector3D cross(CVector3D v1,CVector3D v2)
{
  CVector3D temp;
  temp.x=(v1.y*v2.z)-(v1.z*v2.y);
  temp.y=(v1.z*v2.x)-(v1.x*v2.z);
  temp.z=(v1.x*v2.y)-(v1.y*v2.x);
  return temp;
}

CVector3D calcnormal(CVector3D v1,CVector3D v2,CVector3D v3)
{
  CVector3D temp1, temp2, normal;
  temp1 = v3-v1; temp2 = v2-v1;
  normal=cross(temp1,temp2);
  normal.normalize();
  return normal;
}

double dot(CVector3D v1, CVector3D v2)
{
  return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
}

// Inputs: plane origin, plane normal, ray origin, ray vector.
// NOTE: both vectors are assumed to be normalized
double intersectRayPlane(CVector3D rOrigin, CVector3D rVector, CVector3D pOrigin, CVector3D pNormal)
{
  double d = -(dot(pNormal, pOrigin));
  double number = dot(pNormal,rOrigin) + d;
  double denom = dot(pNormal,rVector);
  return -(number/denom);
}

inline double lengthOfVector(CVector3D v)
{
  return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
};

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

// ----------------------------------------------------------------------
// Name  : CheckPointInTriangle()
// Input : point - point we wish to check for inclusion
//         a - first vertex in triangle
//         b - second vertex in triangle 
//         c - third vertex in triangle
// Notes : Triangle should be defined in clockwise order a,b,c
// Return: TRUE if point is in triangle, FALSE if not.
// -----------------------------------------------------------------------  

int CheckPointInTriangle(CVector3D point, CVector3D a, CVector3D b, CVector3D c) {
        
int pos = 0;
int neg = 0;

float halfplane;
// Calculate normal to plane of triangle
CVector3D v1 = b-a; // edge a->b

CVector3D v2 = c-a;
CVector3D normal = cross(v1,v2);
normal.normalize();
        
// Create a halfplane for each edge : a->b , b->c and c->a

// a->b
CVector3D n = cross(v1,normal);
halfplane = dot(point,n) - dot(a,n);

if (halfplane > EPSILON)
pos++;
else if(halfplane < -EPSILON)
neg++;
        
// b->c
v1 = c-b;
n = cross(v1,normal);
halfplane = dot(point,n) - dot(b,n);

if (halfplane > EPSILON)
pos++;
else if(halfplane < -EPSILON)
neg++;        
        
// c->a
v1 = a-c;
n = cross(v1,normal);
halfplane = dot(point,n) - dot(c,n);

if (halfplane > EPSILON)
pos++;
else if(halfplane < -EPSILON)
neg++;                
        
// result:
if (!neg || !pos)
return 1;

return 0;
}
/*
int CheckPointInTriangle(CVector3D point, CVector3D a, CVector3D b, CVector3D c)
{
  double total_angles = 0.0f;
       
  // make the 3 vectors
  CVector3D v1 = point-a;
  CVector3D v2 = point-b;
  CVector3D v3 = point-c;
  
  v1.normalize();
  v2.normalize();
  v3.normalize();

  total_angles += acos(dot(v1,v2));   
  total_angles += acos(dot(v2,v3));
  total_angles += acos(dot(v3,v1)); 
     
  if (fabs(total_angles-2*PI) <= 0.005)
   return (1);
     
  return(0);
}
*/

int classifyPoint(CVector3D point, CVector3D pO, CVector3D pN)
{
  CVector3D dir = pO - point;
  double d=dot(dir,pN);

  if(d<-0.001f) return PLANE_FRONT;
  else if(d>0.001f) return PLANE_BACKSIDE;

  return ON_PLANE;
}

// ----------------------------------------------------------------------
// Name  : intersectRaySphere()
// Input : rO - origin of ray in world space
//         rV - vector describing direction of ray in world space
//         sO - Origin of sphere 
//         sR - radius of sphere
// Notes : Normalized directional vectors expected
// Return: distance to sphere in world units, -1 if no intersection.
// -----------------------------------------------------------------------  

double intersectRaySphere(CVector3D rO, CVector3D rV, CVector3D sO, double sR) {
	
   CVector3D Q = sO-rO;
   
   double c = Q.getlength();
   double v = dot(Q,rV);
   double d = sR*sR - (c*c - v*v);

   // If there was no intersection, return -1
   if (d < 0.0) return (-1.0f);

   // Return the distance to the [first] intersecting point
   return (v - sqrt(d));
}


