/***************************************************************************
                          md2.h  -  description
                             -------------------
    begin                : Thu Dec 28 2000
    copyright            : (C) 2000 by Marius Andra
    email                : marius@hot.ee
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef __MD2_H__
#define __MD2_H__

#include "texture.h"

typedef struct _modelHeader
{
  int ident;        // A "magic number" that's used to identify the .md2 file
  int version;      // The version of the file, always 8
  int skinwidth;    // Width of the skin(s) in pixels
  int skinheight;   // Height of the skin(s) in pixels
  int framesize;    // Size of each frame in bytes
  int numSkins;     // Number of skins with the model
  int numXYZ;       // Number of vertices in each frame
  int numST;        // Number of texture coordinates in each frame.
  int numTris;      // Number of triangles in each frame
  int numGLcmds;    // Number of dwords (4 bytes) in the gl command list. 
  int numFrames;    // Number of frames
  int offsetSkins;  // Offset, in bytes from the start of the file, to the list of skin names. 
  int offsetST;     // Offset, in bytes from the start of the file, to the list of texture coordinates
  int offsetTris;   // Offset, in bytes from the start of the file, to the list of triangles
  int offsetFrames; // Offset, in bytes from the start of the file, to the list of frames
  int offsetGLcmds; // Offset, in bytes from the start of the file, to the list of gl commands
  int offsetEnd;    // Offset, in bytes from the start of the file, to the end of the file (filesize)
} md2modelHeader;

typedef struct _coord
{
  float pt[3];      // XYZ of a point
  float ln[3];      // XYZ of a the normal for the point
} md2coord;

typedef struct _mesh
{
  unsigned short meshIndex[3]; // indices into the array of vertices in each frames
  unsigned short stIndex[3];   // indices into the array of texture coordinates
} md2mesh;

typedef struct _stTexCoord
{
  float s;
  float t;
} md2stTexCoord;

typedef struct _stTexture
{
   short s;
   short t;
} md2stTexture;

typedef struct _modelData
{
  int numPoints;            // Number of points
  md2coord *pointList;      // List of points
  md2coord *currentmorph;   // Current morph points
  int numTriangles;         // Number of triangles
  int numFrames;            // Number of frames
  md2mesh *triIndex;        // Triangle Index
  int numST;                // Number of texture coordinates
  md2stTexCoord *st;        // List of texture coordinates
  int texWidth, texHeight;  // Texture width and height
  char *texture;            // Not used
  int CurrFrame;            // Current Frames
  int IntroFrames[2];       // Animation start/stop
  int GameFrames[2];        // Not used
  float xscale;             // Not used
  float yscale;             // Not used
  float zscale;             // Not used
  int introzoom;            // Not used
  bool zoomstop;            // Not used
  long zoomstoptime;        // Not used
} md2modelData;

typedef struct _framePoint
{
  unsigned char v[3];             // Scaled vertices. You'll need to multiply them with scale[x] (md2frame) to make them normal.
  unsigned char lightNormalIndex; // Index to the array of normals
} md2framePoint;

typedef struct _frame
{
  float scale[3];      // Used by the v member in the md2framePoint structure
  float translate[3];  // Used by the v member in the md2framePoint structure
  char name[16];       // Name of the frame
  md2framePoint fp[1]; // An array of numXYZ (from header) md2framePoint structures
} md2frame;

class CModelMD2
{
  public:
  CModelMD2() {};
  ~CModelMD2() {};

  // Load the Model
  int LoadModel(const char *fileName, const char *textureName);

  // Load the Texture
  int LoadWeapon(const char *fileName, const char *textureName);

  // This is the function that draws the model on screen. You shouldn't have to call it directly
  int Render(float x, float y, float z, int curframe,int nextframe,float pol);
  
  // This is the function that draws the weapon on screen. You shouldn't have to call it directly
  int RenderWeapon(float x, float y, float z, int curframe,int nextframe,float pol);

  // This renders the current frame of the model (as non animated)
  int RenderCurrentFrame(float x,float y,float z);

  // Set the current frame
  int SetFrame(int frame);

  // Get the current frame
  int GetFrame();

  // Get the number of frames
  int GetLastFrameNum();

  // Reset the frame time (you won't need it)
  int ResetTime();

  // Set the range of the animation. Check out
  // http://www.planetquake.com/polycount/resources/quake2/q2frameslist.shtml
  // for details on frames. Note: you'll have to divide 1 from the numbers in
  // the last column of the table to make it work.
  int Animation(int startframe, int stopframe);

  // Animate the model in the range specified with Animation()
  int Animate(float x, float y, float z,float time);  

  // Animate the model from frame1 to frame2 in time.
  int Animate2(float x, float y, float z,float frame1,float frame2,float time);

private:
  // The Textures
  CTexture modelt,weapont;

  // Model and weapon data
  md2modelData *model,*weapon;

  // Is the weapon loaded?
  int isweapon;

  // Used to count time
  long newtime,frametime,framestarttime;
};

#endif

