#ifndef __VECTORMATH_H__
#define __VECTORMATH_H__

#include "vector.h"

#define PLANE_BACKSIDE 1
#define PLANE_FRONT    2
#define ON_PLANE       3

CVector3D cross(CVector3D v1,CVector3D v2);
CVector3D calcnormal(CVector3D v1,CVector3D v2,CVector3D v3);
double dot(CVector3D v1, CVector3D v2);
double intersectRayPlane(CVector3D rOrigin, CVector3D rVector, CVector3D pOrigin, CVector3D pNormal);
inline double lengthOfVector(CVector3D v);
CVector3D closestPointOnLine(CVector3D a, CVector3D b, CVector3D p);
CVector3D closestPointOnTriangle(CVector3D a, CVector3D b, CVector3D c, CVector3D p);
int classifyPoint(CVector3D point, CVector3D rO, CVector3D pN);
int CheckPointInTriangle(CVector3D point, CVector3D a, CVector3D b, CVector3D c);
double intersectRaySphere(CVector3D rO, CVector3D rV, CVector3D sO, double sR);

#endif

