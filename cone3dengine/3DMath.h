#ifndef _3DMATH_H
#define _3DMATH_H

#define PI 3.1415926535897932					// This is our famous PI

// This is used to hold 3D points and vectors.
struct VECTOR3D
{
	float x, y, z;						
};


//	This returns a perpendicular vector from 2 given vectors by taking the cross product.
VECTOR3D Cross(VECTOR3D vVector1, VECTOR3D vVector2);

//	This returns a vector between 2 points
VECTOR3D Vector(VECTOR3D vPoint1, VECTOR3D vPoint2);

//	This returns the magnitude of a normal (or any other vector)
float Magnitude(VECTOR3D vNormal);

//	This returns a normalize vector (A vector exactly of length 1)
VECTOR3D Normalize(VECTOR3D vNormal);

//	This returns the normal of a polygon (The direction the polygon is facing)
VECTOR3D Normal(VECTOR3D vTriangle[]);

// This returns the distance the plane is from the origin (0, 0, 0)
// It takes the normal to the plane, along with ANY point that lies on the plane (any corner)
float PlaneDistance(VECTOR3D Normal, VECTOR3D Point);

// This takes a triangle (plane) and line and returns true if they intersected
bool IntersectedPlane(VECTOR3D vPoly[], VECTOR3D vLine[], VECTOR3D &vNormal, float &originDistance);


/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *


// This returns the dot product between 2 vectors
float Dot(VECTOR3D vVector1, VECTOR3D vVector2);

// This returns the angle between 2 vectors
double AngleBetweenVectors(VECTOR3D Vector1, VECTOR3D Vector2);

// This returns an intersection point of a polygon and a line (assuming intersects the plane)
VECTOR3D IntersectionPoint(VECTOR3D vNormal, VECTOR3D vLine[], double distance);

// This returns true if the intersection point is inside of the polygon
bool InsidePolygon(VECTOR3D vIntersection, VECTOR3D Poly[], long verticeCount);

// Use this function to test collision between a line and polygon
bool IntersectedPolygon(VECTOR3D vPoly[], VECTOR3D vLine[], int verticeCount);


/////// * /////////// * /////////// * NEW * /////// * /////////// * /////////// *

#endif 


/////////////////////////////////////////////////////////////////////////////////
//
// * QUICK NOTES * 
//
// We added 4 new math functions to our library.  A few of these functions will 
// be used constantly throughout your 3D programming careers, so make sure you know them.
// They are :  Dot()	AngleBetweenVectors()	IntersectionPoint()   InsidePolygon()
//
// We also added a helper function called IntersectedPolygon(), which calls
// IntersectionPoint() and InsidePolygon().  This is the function that the client
// will call.  We don't need to call the other 2 functions by themselves anywhere else.
//
// From now on, the dot product will be one of the biggest math functions you will use.
// It's importance is right behind vectors and normals.
//
// Read more about these functions in 3DMath.cpp
//
// DigiBen
// www.GameTutorials.com
//
//


