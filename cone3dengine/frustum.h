// Frustum.h: Interface of the class CFrustum.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRUSTRUM_H__CA0D0C57_056C_44F8_8AFD_AFDE66FD2451__INCLUDED_)
#define AFX_FRUSTRUM_H__CA0D0C57_056C_44F8_8AFD_AFDE66FD2451__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////
// For more informations on frustum culling visit       //
// http://www.markmorley.com/opengl/frustumculling.html  //
// This class is based on the this tutorial and its code //
///////////////////////////////////////////////////////////

// Return values of the various location functions
#define FULL_OUTSIDE 0
#define PARTIAL_INSIDE 1
#define FULL_INSIDE 2

class CFrustum  
{
public:
	bool CubeInFrustum(float fPoint[3], float fSize);
	bool SphereInFrustum(float fPoint[3], float fRadius);
	bool PointInFrustum(float fPoint[3]);
	void UpdateFrustum();
	int CubeLocation(float fPoint[], float fSize);
	int SphereLocation(float fPoint[3], float fRadius);
	bool RightParallelepipedInFrustum(float fMin[3], float fMax[3]);
	CFrustum();
	virtual ~CFrustum();

protected:
	// The six frustum planes
	float m_fFrustum[6][4];

};

#endif // !defined(AFX_FRUSTRUM_H__CA0D0C57_056C_44F8_8AFD_AFDE66FD2451__INCLUDED_)

