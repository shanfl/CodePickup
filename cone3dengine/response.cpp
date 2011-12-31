//-----------------------------------------------------------------------------
// File: Response.cpp
//
// Desc: Implementation of the collision response
//
// Copyright (c) 2000 Telemachos of Peroxide
// www.peroxide.dk
//-----------------------------------------------------------------------------

#include "vectormath.h"

#include <stdio.h>

#define EPSILON 0.2f
#define PLANE_BACKSIDE 1
#define PLANE_FRONT    2
#define ON_PLANE       3
#define FALSE 0
#define TRUE 1

CVector3D ellipsoidRadius(.1,.19,.1);

CVector3D collideWithWorld(CVector3D position, CVector3D velocity);
CVector3D tv;

inline double lengthOfVector(CVector3D v) {
 return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline CVector3D wedge(CVector3D v1, CVector3D v2) {
 CVector3D result;
 
 result.x = (v1.y * v2.z) - (v2.y * v1.z);
 result.y = (v1.z * v2.x) - (v2.z * v1.x);
 result.z = (v1.x * v2.y) - (v2.x * v1.y); 	
 
 return (result);	
}

inline void setLength(CVector3D& v, float l) {
 float len = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);	
 v.x *= l/len;
 v.y *= l/len;
 v.z *= l/len;
} 

inline void normalizeVector(CVector3D& v) {
 float len = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);	
 v.x /= len;
 v.y /= len;
 v.z /= len;
}

inline int isZeroVector(CVector3D& v) {
 if ((v.x == 0.0f) && (v.y == 0.0f) && (v.z == 0.0f))
   return 1;
   
  return 0;
}

// ----------------------------------------------------------------------
// Name  : CheckPointInTriangle()
// Input : point - point we wish to check for inclusion
//         sO - Origin of sphere
//         sR - radius of sphere 
// Notes : 
// Return: TRUE if point is in sphere, FALSE if not.
// -----------------------------------------------------------------------  

int CheckPointInSphere(CVector3D point, CVector3D sO, double sR) {
	
 float d = lengthOfVector(point-sO);
 
 if(d<= sR) return 1;
 return 0;
}

// ----------------------------------------------------------------------------
// Descr : Structure keeping track of the collisions as we find them. 
// Note  : Somewhat simplified from what is needed if you deside to implement
//         the features described in the section of dynamic geometry.
// ----------------------------------------------------------------------------

struct TCollisionPacket {
 
 // data about player movement
 CVector3D velocity;
 CVector3D sourcePoint;
  
 // radius of ellipsoid.  
 CVector3D eRadius;
  
 // for error handling  
 CVector3D lastSafePosition;
 int stuck;
    
 // data for collision response 
 int foundCollision;
 double    nearestDistance; // nearest distance to hit
 CVector3D nearestIntersectionPoint; // on sphere
 CVector3D nearestPolygonIntersectionPoint; // on polygon
} collision;

CTriangle *triangl;
int numtriangl;
void itri(CTriangle *tri, int nt) {numtriangl=nt;triangl=tri;collision.eRadius.x=0.1;collision.eRadius.y=0.1;collision.eRadius.z=0.1;}



// ----------------------------------------------------------------------
// Name  : CheckCollision()
// Descr : Checks one mesh for collision
// Return: updated collision structure.
// -----------------------------------------------------------------------  

void CheckCollision(TCollisionPacket* colPackage) {
 
 // plane data
 CVector3D p1,p2,p3;
 CVector3D pNormal;
 CVector3D pOrigin;
 CVector3D v1, v2;

 
 // from package
 CVector3D source = colPackage->sourcePoint;
 CVector3D eRadius = colPackage->eRadius;
 CVector3D velocity = colPackage->velocity;	
 
 // keep a copy of this as it's needed a few times
 CVector3D normalizedVelocity = velocity;
 normalizeVector(normalizedVelocity);
 
 // intersection data
 CVector3D sIPoint;    // sphere intersection point
 CVector3D pIPoint;    // plane intersection point 	
 CVector3D polyIPoint; // polygon intersection point
 
 // how long is our velocity
 double distanceToTravel = lengthOfVector(velocity);	
 
 double distToPlaneIntersection;
 double distToEllipsoidIntersection;

 // loop through all faces in mesh
 for (int i=0; i<numtriangl; i++)
  {
     // Get the data for the triangle in question and scale to ellipsoid space
     p1.x = triangl[i].v[0].x / eRadius.x;
     p1.y = triangl[i].v[0].y / eRadius.y;
     p1.z = triangl[i].v[0].z / eRadius.z;
         
     p2.x = triangl[i].v[1].x / eRadius.x;
     p2.y = triangl[i].v[1].y / eRadius.y;
     p2.z = triangl[i].v[1].z / eRadius.z;
             
     p3.x = triangl[i].v[2].x / eRadius.x;
     p3.y = triangl[i].v[2].y / eRadius.y;
     p3.z = triangl[i].v[2].z / eRadius.z;

     // Make the plane containing this triangle.
     pOrigin = p1;
     v1 = p2-p1;
     v2 = p3-p1;
    
        
     // You might not need this if you KNOW all your triangles are valid
//     if (!(isZeroVector(v1) || isZeroVector(v2))) {
                         
     	// determine normal to plane containing polygon  
     	pNormal = wedge(v1, v2);
     	normalizeVector(pNormal);

        //ignore backfaces. What we cannot see we cannot collide with ;)
//        if (dot(pNormal, normalizedVelocity) <= 1.0f) {
    
     		// calculate sphere intersection point
     		sIPoint = source - pNormal;     
        
     		// classify point to determine if ellipsoid span the plane
     		int pClass = classifyPoint(sIPoint, pOrigin, pNormal);
         
     
     		// find the plane intersection point
     		if (pClass == PLANE_BACKSIDE) { // plane is embedded in ellipsoid
     
      			// find plane intersection point by shooting a ray from the 
      			// sphere intersection point along the planes normal.
      			distToPlaneIntersection = intersectRayPlane(sIPoint, pNormal, pOrigin, pNormal);
                       
      			// calculate plane intersection point
      			pIPoint.x = sIPoint.x + distToPlaneIntersection * pNormal.x; 
      			pIPoint.y = sIPoint.y + distToPlaneIntersection * pNormal.y; 
      			pIPoint.z = sIPoint.z + distToPlaneIntersection * pNormal.z; 	
       
     		} 
     		else { 
     
     			// shoot ray along the velocity vector
     			distToPlaneIntersection = intersectRayPlane(sIPoint, normalizedVelocity, pOrigin, pNormal);
               
     			// calculate plane intersection point
     			pIPoint.x = sIPoint.x + distToPlaneIntersection * normalizedVelocity.x; 
     			pIPoint.y = sIPoint.y + distToPlaneIntersection * normalizedVelocity.y; 
     			pIPoint.z = sIPoint.z + distToPlaneIntersection * normalizedVelocity.z; 	


////////////////////////////////////////////////////////////////////////////
/*
			// Surface collision?

			if (p.inside(planeIntersectionPoint, EPSILON))
			{
				// Is this a valid collision?

				if (collisionDistance < -EPSILON * (FLT) 2) continue;

				// Our collision plane is our polygon's plane

				collisionPlane = p.plane();
				collisionType = CT_SURFACE;
			}

			// Edge/Point collision

			else
			{
				// New collision plane origin

				point3	e0, e1;
				bool	edgeFlag;
				collisionPlane.origin() = p.closestPointOnPerimeter(planeIntersectionPoint, e0, e1, edgeFlag);

				// Point collision?

				if (!edgeFlag)
				{
					ray3	toSphere(collisionPlane.origin(), -r.normal());
					if (!unitSphereIntersection(r.origin(), toSphere, collisionDistance)) continue;

					// The collision plane

					sphereIntersectionPoint = collisionPlane.origin() - r.normal() * collisionDistance;
					collisionPlane.vector() = r.origin() - sphereIntersectionPoint;

					// Generate a vector that points from the vertex at the sphere

					vector3	atSphere = r.origin() - collisionPlane.origin();

					// We must be headed at the collision plane
					
					if ((r.vector() ^ atSphere) > 0) continue;

					// The plane is not allowed to face away from the normal of the polygon

					if ((collisionPlane.vector() ^ p.plane().vector()) < 0) continue;

					// The plane is not allowed to face the interior of the polygon

					if (collisionPlane.distance(e0) > 0) continue;
					if (collisionPlane.distance(e1) > 0) continue;

					collisionType = CT_POINT;
				}

				// Edge collision

				else
				{
					// Find the plane defined by the edge and the velocity vector (cross product)
					//
					// This plane will be used to bisect the sphere

					vector3	edgeNormal = e1 - e0;
					edgeNormal.normalize();
					plane3	bisectionPlane(e1, r.normal() % edgeNormal);

					// The intersection of a plane and a sphere is a disc. We want to find the center
					// of that disc. The center of that disc is the closest point on the bisection plane
					// to the center of the sphere.

					point3	discCenter = bisectionPlane.closest(r.origin());

					// If the center of the disc is outside the sphere, then the sphere does not intersect
					// the bisection plane and therefore, will never collide with the edge

					if (discCenter.distance(r.origin()) > 1-EPSILON) continue;

					// Find the closest point on the edge to the center of the disc

					point3	edgePoint = closestPointOnLine(e0, e1, discCenter);

					// Generate a ray that traces back toward the sphere

					ray3	toSphere(edgePoint, discCenter - edgePoint);

					// Trace from the edgePoint back to the sphere.
					//
					// This will be the sphereIntersectionPoint
					
					FLT	t;
					if (!unitSphereIntersection(r.origin(), toSphere, t)) continue;
					sphereIntersectionPoint = toSphere.end(t);

					// Will the sphere interesction point, when travelling along 'r' ever intersect the actual
					// edge?
					//
					// In order to determine this, we'll start by defining a plane that lies on the edge, but is
					// perpendicular to 'r'.

					vector3	edgeVect = (e1 - e0) % r.normal() % (e1 - e0);
					edgeVect.normalize();
					plane3	edgePlane(e0, edgeVect);

					// Next, we'll intersect the edgeVect ray with the plane

					ray3 toLine(sphereIntersectionPoint, r.normal());
					edgePlane.intersect(toLine, t);

					// Finally, does the result end up with a point inside the line segment defined by the
					// two edge points? If not, then the sphere won't intersect the edge.

					if (!isPointInsideEdge(e0, e1, toLine.end(t))) continue;

					// Our collision plane is the tangent plane at the sphereIntersectionPoint

					collisionPlane.vector() = r.origin() - sphereIntersectionPoint;

					// The plane is not allowed to face the interior of the polygon...

					if (collisionPlane.distance(p.calcCenterOfMass()) > -0) continue;

					// The plane is not allowed to face away from the normal of the polygon

					if ((collisionPlane.normal() ^ p.plane().normal()) < 0) continue;

					// Trace from the sphereIntersectionPoint to the plane to find the collisionDistance

					ray3	fromSphere(sphereIntersectionPoint, r.normal());
					VERIFY(collisionPlane.intersect(fromSphere, collisionDistance));

					// Don't allow collisions behind us

					if (collisionDistance < -1) continue;

					collisionType = CT_EDGE;
				}
			}
*/
////////////////////////////////////////////////////////////////////////////          	
     		}

     		// find polygon intersection point. By default we assume its equal to the 
     		// plane intersection point
     
     		polyIPoint = pIPoint;
     		distToEllipsoidIntersection = distToPlaneIntersection;
     
     		if (!CheckPointInTriangle(pIPoint,p1,p2,p3)) { // if not in triangle
     	
      			polyIPoint = closestPointOnTriangle(p1, p2, p3, pIPoint);	
           
      			distToEllipsoidIntersection = intersectRaySphere(polyIPoint, tv-normalizedVelocity, source, 1.0f);
                  
      			if (distToEllipsoidIntersection > 0) { 	
     			// calculate true sphere intersection point
     				sIPoint.x = polyIPoint.x + distToEllipsoidIntersection * -normalizedVelocity.x;
     				sIPoint.y = polyIPoint.y + distToEllipsoidIntersection * -normalizedVelocity.y;
     				sIPoint.z = polyIPoint.z + distToEllipsoidIntersection * -normalizedVelocity.z;
     			}
    
     		} 
     
    
  		// Here we do the error checking to see if we got ourself stuck last frame
   		if (CheckPointInSphere(polyIPoint, source, 1.0f)) 
			colPackage->stuck = 1;
       
    
		// Ok, now we might update the collision data if we hit something
    		if ((distToEllipsoidIntersection > 0) && (distToEllipsoidIntersection <= distanceToTravel)) { 
     			if ((colPackage->foundCollision == FALSE) || (distToEllipsoidIntersection < colPackage->nearestDistance))  {
           
                		// if we are hit we have a closest hit so far. We save the information
      				colPackage->nearestDistance = distToEllipsoidIntersection;
      		       		colPackage->nearestIntersectionPoint = sIPoint;
      				colPackage->nearestPolygonIntersectionPoint = polyIPoint;
      				colPackage->foundCollision = TRUE;
			}
    		} 
           
//	} // if not backface
//   } // if a valid plane
     // You might not need this if you KNOW all your triangles are valid
//     if (!(isZeroVector(v1) || isZeroVector(v2))) {
                         
     	// determine normal to plane containing polygon  
     	pNormal = tv-wedge(v1, v2);
     	normalizeVector(pNormal);

        //ignore backfaces. What we cannot see we cannot collide with ;)
//        if (dot(pNormal, normalizedVelocity) <= 1.0f) {
    
     		// calculate sphere intersection point
     		sIPoint = source - pNormal;     
        
     		// classify point to determine if ellipsoid span the plane
     		pClass = classifyPoint(sIPoint, pOrigin, pNormal);
         
     
     		// find the plane intersection point
     		if (pClass == PLANE_BACKSIDE) { // plane is embedded in ellipsoid
     
      			// find plane intersection point by shooting a ray from the 
      			// sphere intersection point along the planes normal.
      			distToPlaneIntersection = intersectRayPlane(sIPoint, pNormal, pOrigin, pNormal);
                       
      			// calculate plane intersection point
      			pIPoint.x = sIPoint.x + distToPlaneIntersection * pNormal.x; 
      			pIPoint.y = sIPoint.y + distToPlaneIntersection * pNormal.y; 
      			pIPoint.z = sIPoint.z + distToPlaneIntersection * pNormal.z; 	
       
     		} 
     		else { 
     
     			// shoot ray along the velocity vector
     			distToPlaneIntersection = intersectRayPlane(sIPoint, normalizedVelocity, pOrigin, pNormal);
               
     			// calculate plane intersection point
     			pIPoint.x = sIPoint.x + distToPlaneIntersection * normalizedVelocity.x; 
     			pIPoint.y = sIPoint.y + distToPlaneIntersection * normalizedVelocity.y; 
     			pIPoint.z = sIPoint.z + distToPlaneIntersection * normalizedVelocity.z; 	

     		}

     		// find polygon intersection point. By default we assume its equal to the 
     		// plane intersection point
     
     		polyIPoint = pIPoint;
     		distToEllipsoidIntersection = distToPlaneIntersection;
     
     		if (!CheckPointInTriangle(pIPoint,p1,p2,p3)) { // if not in triangle
     	
      			polyIPoint = closestPointOnTriangle(p1, p2, p3, pIPoint);	
           
      			distToEllipsoidIntersection = intersectRaySphere(polyIPoint, tv-normalizedVelocity, source, 1.0f);
                  
      			if (distToEllipsoidIntersection > 0) { 	
     			// calculate true sphere intersection point
     				sIPoint.x = polyIPoint.x + distToEllipsoidIntersection * -normalizedVelocity.x;
     				sIPoint.y = polyIPoint.y + distToEllipsoidIntersection * -normalizedVelocity.y;
     				sIPoint.z = polyIPoint.z + distToEllipsoidIntersection * -normalizedVelocity.z;
     			}
    
     		} 
     
////////////////////////////////////////////////////////////////

/*			else
			{
				// New collision plane origin

				point3	e0, e1;
				bool	edgeFlag;
				collisionPlane.origin() = p.closestPointOnPerimeter(planeIntersectionPoint, e0, e1, edgeFlag);

				// Point collision?

				if (!edgeFlag)
				{
					ray3	toSphere(collisionPlane.origin(), -r.normal());
					if (!unitSphereIntersection(r.origin(), toSphere, collisionDistance)) continue;

					// The collision plane

					sphereIntersectionPoint = collisionPlane.origin() - r.normal() * collisionDistance;
					collisionPlane.vector() = r.origin() - sphereIntersectionPoint;

					// Generate a vector that points from the vertex at the sphere

					vector3	atSphere = r.origin() - collisionPlane.origin();

					// We must be headed at the collision plane
					
					if ((r.vector() ^ atSphere) > 0) continue;

					// The plane is not allowed to face away from the normal of the polygon

					if ((collisionPlane.vector() ^ p.plane().vector()) < 0) continue;

					// The plane is not allowed to face the interior of the polygon

					if (collisionPlane.distance(e0) > 0) continue;
					if (collisionPlane.distance(e1) > 0) continue;

					collisionType = CT_POINT;
				}

				// Edge collision

				else
				{
					// Find the plane defined by the edge and the velocity vector (cross product)
					//
					// This plane will be used to bisect the sphere

					vector3	edgeNormal = e1 - e0;
					edgeNormal.normalize();
					plane3	bisectionPlane(e1, r.normal() % edgeNormal);

					// The intersection of a plane and a sphere is a disc. We want to find the center
					// of that disc. The center of that disc is the closest point on the bisection plane
					// to the center of the sphere.

					point3	discCenter = bisectionPlane.closest(r.origin());

					// If the center of the disc is outside the sphere, then the sphere does not intersect
					// the bisection plane and therefore, will never collide with the edge

					if (discCenter.distance(r.origin()) > 1-EPSILON) continue;

					// Find the closest point on the edge to the center of the disc

					point3	edgePoint = closestPointOnLine(e0, e1, discCenter);

					// Generate a ray that traces back toward the sphere

					ray3	toSphere(edgePoint, discCenter - edgePoint);

					// Trace from the edgePoint back to the sphere.
					//
					// This will be the sphereIntersectionPoint
					
					FLT	t;
					if (!unitSphereIntersection(r.origin(), toSphere, t)) continue;
					sphereIntersectionPoint = toSphere.end(t);

					// Will the sphere interesction point, when travelling along 'r' ever intersect the actual
					// edge?
					//
					// In order to determine this, we'll start by defining a plane that lies on the edge, but is
					// perpendicular to 'r'.

					vector3	edgeVect = (e1 - e0) % r.normal() % (e1 - e0);
					edgeVect.normalize();
					plane3	edgePlane(e0, edgeVect);

					// Next, we'll intersect the edgeVect ray with the plane

					ray3 toLine(sphereIntersectionPoint, r.normal());
					edgePlane.intersect(toLine, t);

					// Finally, does the result end up with a point inside the line segment defined by the
					// two edge points? If not, then the sphere won't intersect the edge.

					if (!isPointInsideEdge(e0, e1, toLine.end(t))) continue;

					// Our collision plane is the tangent plane at the sphereIntersectionPoint

					collisionPlane.vector() = r.origin() - sphereIntersectionPoint;

					// The plane is not allowed to face the interior of the polygon...

					if (collisionPlane.distance(p.calcCenterOfMass()) > -0) continue;

					// The plane is not allowed to face away from the normal of the polygon

					if ((collisionPlane.normal() ^ p.plane().normal()) < 0) continue;

					// Trace from the sphereIntersectionPoint to the plane to find the collisionDistance

					ray3	fromSphere(sphereIntersectionPoint, r.normal());
					VERIFY(collisionPlane.intersect(fromSphere, collisionDistance));

					// Don't allow collisions behind us

					if (collisionDistance < -1) continue;

					collisionType = CT_EDGE;
				}
			}
*/
////////////////////////////////////////////////////////////////
    
  		// Here we do the error checking to see if we got ourself stuck last frame
   		if (CheckPointInSphere(polyIPoint, source, 1.0f)) 
			colPackage->stuck = 1;
       
    
		// Ok, now we might update the collision data if we hit something
    		if ((distToEllipsoidIntersection > 0) && (distToEllipsoidIntersection <= distanceToTravel)) { 
     			if ((colPackage->foundCollision == FALSE) || (distToEllipsoidIntersection < colPackage->nearestDistance))  {
           
                		// if we are hit we have a closest hit so far. We save the information
      				colPackage->nearestDistance = distToEllipsoidIntersection;
      		       		colPackage->nearestIntersectionPoint = sIPoint;
      				colPackage->nearestPolygonIntersectionPoint = polyIPoint;
      				colPackage->foundCollision = TRUE;
			}
    		} 
           
//	} // if not backface
//   } // if a valid plane
 } // for all faces	
}

//-----------------------------------------------------------------------------
// Name: GetPosition()
// Desc: Main collision detection function. This is what you call to get
//       a position.
//-----------------------------------------------------------------------------
CVector3D GetPosition(CVector3D position, CVector3D velocity) {
	
 CVector3D scaledPosition, scaledVelocity;
 CVector3D finalPosition;

 // the first thing we do is scale the player and his velocity to
 // ellipsoid space
 scaledPosition = position / ellipsoidRadius;
 scaledVelocity = velocity / ellipsoidRadius;	
	
 // call the recursive collision response function	
 finalPosition = collideWithWorld(scaledPosition, scaledVelocity);
 	
 // when the function returns the result is still in ellipsoid space, so
 // we have to scale it back to R3 before we return it 	
 finalPosition = finalPosition * ellipsoidRadius;
  
 return finalPosition; 	
	
}


//-----------------------------------------------------------------------------
// Name: collideWithWorld()
// Desc: Recursive part of the collision response. This function is the
//       one who actually calls the collision check on the meshes
//-----------------------------------------------------------------------------
CVector3D collideWithWorld(CVector3D position, CVector3D velocity) {
 
  CVector3D pos;
 
 
  // do we need to worry ?
  if (lengthOfVector(velocity) < EPSILON)
    return position;
   	
 	
  CVector3D destinationPoint = position + velocity;
 
  // reset the collision package we send to the mesh 
  collision.velocity = velocity;
  collision.sourcePoint = position;
  collision.foundCollision = FALSE;
  collision.stuck = FALSE;
  collision.nearestDistance = -1;
  
  CheckCollision(&collision);

  // check return value here, and possibly call recursively 	
	
  if (collision.foundCollision == FALSE)
   { 
     // if no collision move very close to the desired destination. 
     float l = lengthOfVector(velocity);
     CVector3D V = velocity;
     setLength(V, l-EPSILON);
     	
     // update the last safe position for future error recovery	
     collision.lastSafePosition = position;
     
     // return the final position
     return position + V;
   }
  else { // There was a collision
   
    
    // If we are stuck, we just back up to last safe position
    if (collision.stuck)
      return collision.lastSafePosition;
    
    
      
    // OK, first task is to move close to where we hit something :
    CVector3D newSourcePoint;
                   
    // only update if we are not already very close
    if (collision.nearestDistance >= EPSILON) {
         
      CVector3D V = velocity;
      setLength(V, collision.nearestDistance-EPSILON);
      newSourcePoint = collision.sourcePoint + V;
    }
    else
      newSourcePoint = collision.sourcePoint;

   

    // Now we must calculate the sliding plane
    CVector3D slidePlaneOrigin = collision.nearestPolygonIntersectionPoint;
    CVector3D slidePlaneNormal = newSourcePoint - collision.nearestPolygonIntersectionPoint;
  
      
    // We now project the destination point onto the sliding plane
    double l = intersectRayPlane(destinationPoint, slidePlaneNormal, 
                                 slidePlaneOrigin, slidePlaneNormal); 
    
  
    // We can now calculate a new destination point on the sliding plane
    CVector3D newDestinationPoint;
    newDestinationPoint.x = destinationPoint.x + l * slidePlaneNormal.x;
    newDestinationPoint.y = destinationPoint.y + l * slidePlaneNormal.y;
    newDestinationPoint.z = destinationPoint.z + l * slidePlaneNormal.z;
   
    
    // Generate the slide vector, which will become our new velocity vector
    // for the next iteration
    CVector3D newVelocityVector = newDestinationPoint - collision.nearestPolygonIntersectionPoint;
        
       
    // now we recursively call the function with the new position and velocity 
    collision.lastSafePosition = position;
    return collideWithWorld(newSourcePoint, newVelocityVector); 
    
  }
 
}




