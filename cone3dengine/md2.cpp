/***************************************************************************
                          md2.cpp  -  description
                             -------------------
    begin                : Thu Dec 28 2000
    copyright            : (C) 2000 by Marius Andra
    email                : marius@hot.ee

   The model loading part of this file was created by Naveed Ahmed
   his e-mail is Greatman@softhome.net. He also created the original code
   to display models and animation one frame at a time. That code was
   taken from his 3D engine (based on nehe tut 23) with his permission
   
   I modified it to make smooth animations and added the support for guns
   and made some more small improvements (e.g classes) ...

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <stdlib.h>

#include "md2.h"

#define NUMVERTEXNORMALS 162

// Quake 2 normals are indexed. Use avertexnormals[normalindex][x/y/z] and 
// you'll have you normals.

float avertexnormals[NUMVERTEXNORMALS][3] = {
{-0.525731f, 0.000000f, 0.850651f},
{-0.442863f, 0.238856f, 0.864188f},
{-0.295242f, 0.000000f, 0.955423f},
{-0.309017f, 0.500000f, 0.809017f},
{-0.162460f, 0.262866f, 0.951056f},
{0.000000f, 0.000000f, 1.000000f},
{0.000000f, 0.850651f, 0.525731f},
{-0.147621f, 0.716567f, 0.681718f},
{0.147621f, 0.716567f, 0.681718f},
{0.000000f, 0.525731f, 0.850651f},
{0.309017f, 0.500000f, 0.809017f},
{0.525731f, 0.000000f, 0.850651f},
{0.295242f, 0.000000f, 0.955423f},
{0.442863f, 0.238856f, 0.864188f},
{0.162460f, 0.262866f, 0.951056f},
{-0.681718f, 0.147621f, 0.716567f},
{-0.809017f, 0.309017f, 0.500000f},
{-0.587785f, 0.425325f, 0.688191f},
{-0.850651f, 0.525731f, 0.000000f},
{-0.864188f, 0.442863f, 0.238856f},
{-0.716567f, 0.681718f, 0.147621f},
{-0.688191f, 0.587785f, 0.425325f},
{-0.500000f, 0.809017f, 0.309017f},
{-0.238856f, 0.864188f, 0.442863f},
{-0.425325f, 0.688191f, 0.587785f},
{-0.716567f, 0.681718f, -0.147621f},
{-0.500000f, 0.809017f, -0.309017f},
{-0.525731f, 0.850651f, 0.000000f},
{0.000000f, 0.850651f, -0.525731f},
{-0.238856f, 0.864188f, -0.442863f},
{0.000000f, 0.955423f, -0.295242f},
{-0.262866f, 0.951056f, -0.162460f},
{0.000000f, 1.000000f, 0.000000f},
{0.000000f, 0.955423f, 0.295242f},
{-0.262866f, 0.951056f, 0.162460f},
{0.238856f, 0.864188f, 0.442863f},
{0.262866f, 0.951056f, 0.162460f},
{0.500000f, 0.809017f, 0.309017f},
{0.238856f, 0.864188f, -0.442863f},
{0.262866f, 0.951056f, -0.162460f},
{0.500000f, 0.809017f, -0.309017f},
{0.850651f, 0.525731f, 0.000000f},
{0.716567f, 0.681718f, 0.147621f},
{0.716567f, 0.681718f, -0.147621f},
{0.525731f, 0.850651f, 0.000000f},
{0.425325f, 0.688191f, 0.587785f},
{0.864188f, 0.442863f, 0.238856f},
{0.688191f, 0.587785f, 0.425325f},
{0.809017f, 0.309017f, 0.500000f},
{0.681718f, 0.147621f, 0.716567f},
{0.587785f, 0.425325f, 0.688191f},
{0.955423f, 0.295242f, 0.000000f},
{1.000000f, 0.000000f, 0.000000f},
{0.951056f, 0.162460f, 0.262866f},
{0.850651f, -0.525731f, 0.000000f},
{0.955423f, -0.295242f, 0.000000f},
{0.864188f, -0.442863f, 0.238856f},
{0.951056f, -0.162460f, 0.262866f},
{0.809017f, -0.309017f, 0.500000f},
{0.681718f, -0.147621f, 0.716567f},
{0.850651f, 0.000000f, 0.525731f},
{0.864188f, 0.442863f, -0.238856f},
{0.809017f, 0.309017f, -0.500000f},
{0.951056f, 0.162460f, -0.262866f},
{0.525731f, 0.000000f, -0.850651f},
{0.681718f, 0.147621f, -0.716567f},
{0.681718f, -0.147621f, -0.716567f},
{0.850651f, 0.000000f, -0.525731f},
{0.809017f, -0.309017f, -0.500000f},
{0.864188f, -0.442863f, -0.238856f},
{0.951056f, -0.162460f, -0.262866f},
{0.147621f, 0.716567f, -0.681718f},
{0.309017f, 0.500000f, -0.809017f},
{0.425325f, 0.688191f, -0.587785f},
{0.442863f, 0.238856f, -0.864188f},
{0.587785f, 0.425325f, -0.688191f},
{0.688191f, 0.587785f, -0.425325f},
{-0.147621f, 0.716567f, -0.681718f},
{-0.309017f, 0.500000f, -0.809017f},
{0.000000f, 0.525731f, -0.850651f},
{-0.525731f, 0.000000f, -0.850651f},
{-0.442863f, 0.238856f, -0.864188f},
{-0.295242f, 0.000000f, -0.955423f},
{-0.162460f, 0.262866f, -0.951056f},
{0.000000f, 0.000000f, -1.000000f},
{0.295242f, 0.000000f, -0.955423f},
{0.162460f, 0.262866f, -0.951056f},
{-0.442863f, -0.238856f, -0.864188f},
{-0.309017f, -0.500000f, -0.809017f},
{-0.162460f, -0.262866f, -0.951056f},
{0.000000f, -0.850651f, -0.525731f},
{-0.147621f, -0.716567f, -0.681718f},
{0.147621f, -0.716567f, -0.681718f},
{0.000000f, -0.525731f, -0.850651f},
{0.309017f, -0.500000f, -0.809017f},
{0.442863f, -0.238856f, -0.864188f},
{0.162460f, -0.262866f, -0.951056f},
{0.238856f, -0.864188f, -0.442863f},
{0.500000f, -0.809017f, -0.309017f},
{0.425325f, -0.688191f, -0.587785f},
{0.716567f, -0.681718f, -0.147621f},
{0.688191f, -0.587785f, -0.425325f},
{0.587785f, -0.425325f, -0.688191f},
{0.000000f, -0.955423f, -0.295242f},
{0.000000f, -1.000000f, 0.000000f},
{0.262866f, -0.951056f, -0.162460f},
{0.000000f, -0.850651f, 0.525731f},
{0.000000f, -0.955423f, 0.295242f},
{0.238856f, -0.864188f, 0.442863f},
{0.262866f, -0.951056f, 0.162460f},
{0.500000f, -0.809017f, 0.309017f},
{0.716567f, -0.681718f, 0.147621f},
{0.525731f, -0.850651f, 0.000000f},
{-0.238856f, -0.864188f, -0.442863f},
{-0.500000f, -0.809017f, -0.309017f},
{-0.262866f, -0.951056f, -0.162460f},
{-0.850651f, -0.525731f, 0.000000f},
{-0.716567f, -0.681718f, -0.147621f},
{-0.716567f, -0.681718f, 0.147621f},
{-0.525731f, -0.850651f, 0.000000f},
{-0.500000f, -0.809017f, 0.309017f},
{-0.238856f, -0.864188f, 0.442863f},
{-0.262866f, -0.951056f, 0.162460f},
{-0.864188f, -0.442863f, 0.238856f},
{-0.809017f, -0.309017f, 0.500000f},
{-0.688191f, -0.587785f, 0.425325f},
{-0.681718f, -0.147621f, 0.716567f},
{-0.442863f, -0.238856f, 0.864188f},
{-0.587785f, -0.425325f, 0.688191f},
{-0.309017f, -0.500000f, 0.809017f},
{-0.147621f, -0.716567f, 0.681718f},
{-0.425325f, -0.688191f, 0.587785f},
{-0.162460f, -0.262866f, 0.951056f},
{0.442863f, -0.238856f, 0.864188f},
{0.162460f, -0.262866f, 0.951056f},
{0.309017f, -0.500000f, 0.809017f},
{0.147621f, -0.716567f, 0.681718f},
{0.000000f, -0.525731f, 0.850651f},
{0.425325f, -0.688191f, 0.587785f},
{0.587785f, -0.425325f, 0.688191f},
{0.688191f, -0.587785f, 0.425325f},
{-0.955423f, 0.295242f, 0.000000f},
{-0.951056f, 0.162460f, 0.262866f},
{-1.000000f, 0.000000f, 0.000000f},
{-0.850651f, 0.000000f, 0.525731f},
{-0.955423f, -0.295242f, 0.000000f},
{-0.951056f, -0.162460f, 0.262866f},
{-0.864188f, 0.442863f, -0.238856f},
{-0.951056f, 0.162460f, -0.262866f},
{-0.809017f, 0.309017f, -0.500000f},
{-0.864188f, -0.442863f, -0.238856f},
{-0.951056f, -0.162460f, -0.262866f},
{-0.809017f, -0.309017f, -0.500000f},
{-0.681718f, 0.147621f, -0.716567f},
{-0.681718f, -0.147621f, -0.716567f},
{-0.850651f, 0.000000f, -0.525731f},
{-0.688191f, 0.587785f, -0.425325f},
{-0.587785f, 0.425325f, -0.688191f},
{-0.425325f, 0.688191f, -0.587785f},
{-0.425325f, -0.688191f, -0.587785f},
{-0.587785f, -0.425325f, -0.688191f},
{-0.688191f, -0.587785f, -0.425325f},
};

// Reset the time back to 0
int CModelMD2::ResetTime()
{
  frametime=0;
  framestarttime=0;
  return 1;
}

// The main animation.
int CModelMD2::Animate(float x, float y, float z,float time)
{
  glPushMatrix();

  // Calculate how much time has passed  
  newtime = SDL_GetTicks();
  if(framestarttime==0) framestarttime=newtime;
  frametime=newtime-framestarttime;
  float tim=frametime/time;

  // and Display the model
  if(GetFrame()+1>model->IntroFrames[1])
  {
    Render(x,y,z,GetFrame(),model->IntroFrames[0],tim);
    if(isweapon)
      RenderWeapon(x,y,z,GetFrame(),model->IntroFrames[0],tim);
  } else {
    Render(x,y,z,GetFrame(),GetFrame()+1,tim);
    if(isweapon)
      RenderWeapon(x,y,z,GetFrame(),GetFrame()+1,tim);
  }

  // If the animation has reached it's end start at the beginning and return 2
  if((frametime/time)>=1)
  {
    framestarttime=newtime;
    SetFrame(GetFrame()+1);
    if(GetFrame() > model->IntroFrames[1]){
      SetFrame(model->IntroFrames[0]);
      return 3;}
    if(GetFrame() == model->IntroFrames[1]) return 4;
    return 2;
  }
  
  // else return 1
  return 1;
}


// Animate from frame1 to frame2
int CModelMD2::Animate2(float x, float y, float z,float frame1,
                                       float frame2,float time)
{
  glPushMatrix();

  newtime = SDL_GetTicks();
  frametime=newtime-framestarttime;
  Render(x,y,z,frame1,frame2,frametime/time);
  if(isweapon)
    RenderWeapon(x,y,z,frame1,frame2,frametime/time);

  if((frametime/time)>=1)
  {
    framestarttime=newtime;
    return 2;
  }
  return 1;
}

// Set the animation range
int CModelMD2::Animation(int startframe, int stopframe)
{
  model->IntroFrames[0] = startframe;
  model->IntroFrames[1] = stopframe;
  return 1;
}

// Set the current frame
int CModelMD2::SetFrame(int frame)
{
  model->CurrFrame = frame;
  return 1;
}

// Get the current frame
int CModelMD2::GetFrame()
{
  return model->CurrFrame;
}

// Get the number of the last frame
int CModelMD2::GetLastFrameNum()
{
  return model->numFrames-1;
}

// Render the current frame (no animation)
// (Useful when you have some still statues
//  in the wall that come to life.)
int CModelMD2::RenderCurrentFrame(float x,float y,float z)
{
  Render(x,y,z,GetFrame(),GetFrame(),1);
  if(isweapon)
    RenderWeapon(x,y,z,GetFrame(),GetFrame(),1);

  return 1;
}

// Render the weapon
int CModelMD2::RenderWeapon(float x, float y, float z, int curframe,
                                            int nextframe,float pol)
{
  float  x1, y1, z1, x2, y2, z2;
  float nx1,ny1,nz1,nx2,ny2,nz2;
  if(pol>1) pol=1;

  // Get the points to the current and the next frame.

  md2coord *pointListPtr;
  md2coord *pointListPtr2;
  pointListPtr = &weapon->pointList[ weapon->numPoints * curframe];
  pointListPtr2 = &weapon->pointList[ weapon->numPoints * nextframe];

  // Bind the texture and begin drawing triangles
  glBindTexture(GL_TEXTURE_2D, weapont.texID);
  glBegin(GL_TRIANGLES);

  for(int i=0; i<weapon->numTriangles; i++ )
  {
    glTexCoord2f(weapon->st[ weapon->triIndex[i].stIndex[0] ].s, weapon->st[ weapon->triIndex[i].stIndex[0] ].t);
    // Get the points into shorter-named variables.
    x1 = pointListPtr[ weapon->triIndex[i].meshIndex[0] ].pt[0];
    y1 = pointListPtr[ weapon->triIndex[i].meshIndex[0] ].pt[1];
    z1 = pointListPtr[ weapon->triIndex[i].meshIndex[0] ].pt[2];
    x2 = pointListPtr2[ weapon->triIndex[i].meshIndex[0] ].pt[0];
    y2 = pointListPtr2[ weapon->triIndex[i].meshIndex[0] ].pt[1];
    z2 = pointListPtr2[ weapon->triIndex[i].meshIndex[0] ].pt[2];
    nx1 = pointListPtr[ weapon->triIndex[i].meshIndex[0] ].ln[0];
    ny1 = pointListPtr[ weapon->triIndex[i].meshIndex[0] ].ln[1];
    nz1 = pointListPtr[ weapon->triIndex[i].meshIndex[0] ].ln[2];
    nx2 = pointListPtr2[ weapon->triIndex[i].meshIndex[0] ].ln[0];
    ny2 = pointListPtr2[ weapon->triIndex[i].meshIndex[0] ].ln[1];
    nz2 = pointListPtr2[ weapon->triIndex[i].meshIndex[0] ].ln[2];

    // Get a normal between the current frame and the next frame.
    // Same with the points.
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );


    glTexCoord2f( weapon->st[ weapon->triIndex[i].stIndex[1] ].s, weapon->st[ weapon->triIndex[i].stIndex[1] ].t );
    x1 = pointListPtr[ weapon->triIndex[i].meshIndex[1] ].pt[0];
    y1 = pointListPtr[ weapon->triIndex[i].meshIndex[1] ].pt[1];
    z1 = pointListPtr[ weapon->triIndex[i].meshIndex[1] ].pt[2];
    x2 = pointListPtr2[ weapon->triIndex[i].meshIndex[1] ].pt[0];
    y2 = pointListPtr2[ weapon->triIndex[i].meshIndex[1] ].pt[1];
    z2 = pointListPtr2[ weapon->triIndex[i].meshIndex[1] ].pt[2];
    nx1 = pointListPtr[ weapon->triIndex[i].meshIndex[1] ].ln[0];
    ny1 = pointListPtr[ weapon->triIndex[i].meshIndex[1] ].ln[1];
    nz1 = pointListPtr[ weapon->triIndex[i].meshIndex[1] ].ln[2];
    nx2 = pointListPtr2[ weapon->triIndex[i].meshIndex[1] ].ln[0];
    ny2 = pointListPtr2[ weapon->triIndex[i].meshIndex[1] ].ln[1];
    nz2 = pointListPtr2[ weapon->triIndex[i].meshIndex[1] ].ln[2];
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );


    glTexCoord2f( weapon->st[ weapon->triIndex[i].stIndex[2] ].s, weapon->st[ weapon->triIndex[i].stIndex[2] ].t );
    x1 = pointListPtr[ weapon->triIndex[i].meshIndex[2] ].pt[0];
    y1 = pointListPtr[ weapon->triIndex[i].meshIndex[2] ].pt[1];
    z1 = pointListPtr[ weapon->triIndex[i].meshIndex[2] ].pt[2];
    x2 = pointListPtr2[ weapon->triIndex[i].meshIndex[2] ].pt[0];
    y2 = pointListPtr2[ weapon->triIndex[i].meshIndex[2] ].pt[1];
    z2 = pointListPtr2[ weapon->triIndex[i].meshIndex[2] ].pt[2];
    nx1 = pointListPtr[ weapon->triIndex[i].meshIndex[2] ].ln[0];
    ny1 = pointListPtr[ weapon->triIndex[i].meshIndex[2] ].ln[1];
    nz1 = pointListPtr[ weapon->triIndex[i].meshIndex[2] ].ln[2];
    nx2 = pointListPtr2[ weapon->triIndex[i].meshIndex[2] ].ln[0];
    ny2 = pointListPtr2[ weapon->triIndex[i].meshIndex[2] ].ln[1];
    nz2 = pointListPtr2[ weapon->triIndex[i].meshIndex[2] ].ln[2];
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );
  }

  glEnd();

  return 1;
}


int CModelMD2::Render(float x, float y, float z, int curframe,int nextframe,float pol)
{
  float  x1, y1, z1, x2, y2, z2;
  float nx1,ny1,nz1,nx2,ny2,nz2;
  if(pol>1) pol=1;

  // Get the points to the current and the next frame.
  md2coord *pointListPtr;
  md2coord *pointListPtr2;
  pointListPtr = &model->pointList[ model->numPoints * curframe];
  pointListPtr2 = &model->pointList[ model->numPoints * nextframe];

  // Bind the texture and begin drawing triangles
  glBindTexture(GL_TEXTURE_2D, modelt.texID);
  glBegin(GL_TRIANGLES);

  for(int i=0; i<model->numTriangles; i++ )
  {
    glTexCoord2f(model->st[ model->triIndex[i].stIndex[0] ].s, model->st[ model->triIndex[i].stIndex[0] ].t);
    // Get the points into shorter-named variables.
    x1 = pointListPtr[ model->triIndex[i].meshIndex[0] ].pt[0];
    y1 = pointListPtr[ model->triIndex[i].meshIndex[0] ].pt[1];
    z1 = pointListPtr[ model->triIndex[i].meshIndex[0] ].pt[2];
    x2 = pointListPtr2[ model->triIndex[i].meshIndex[0] ].pt[0];
    y2 = pointListPtr2[ model->triIndex[i].meshIndex[0] ].pt[1];
    z2 = pointListPtr2[ model->triIndex[i].meshIndex[0] ].pt[2];
    nx1 = pointListPtr[ model->triIndex[i].meshIndex[0] ].ln[0];
    ny1 = pointListPtr[ model->triIndex[i].meshIndex[0] ].ln[1];
    nz1 = pointListPtr[ model->triIndex[i].meshIndex[0] ].ln[2];
    nx2 = pointListPtr2[ model->triIndex[i].meshIndex[0] ].ln[0];
    ny2 = pointListPtr2[ model->triIndex[i].meshIndex[0] ].ln[1];
    nz2 = pointListPtr2[ model->triIndex[i].meshIndex[0] ].ln[2];
    // Get a normal between the current frame and the next frame.
    // Same with the points.
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );

    glTexCoord2f( model->st[ model->triIndex[i].stIndex[1] ].s, model->st[ model->triIndex[i].stIndex[1] ].t );
    x1 = pointListPtr[ model->triIndex[i].meshIndex[1] ].pt[0];
    y1 = pointListPtr[ model->triIndex[i].meshIndex[1] ].pt[1];
    z1 = pointListPtr[ model->triIndex[i].meshIndex[1] ].pt[2];
    x2 = pointListPtr2[ model->triIndex[i].meshIndex[1] ].pt[0];
    y2 = pointListPtr2[ model->triIndex[i].meshIndex[1] ].pt[1];
    z2 = pointListPtr2[ model->triIndex[i].meshIndex[1] ].pt[2];
    nx1 = pointListPtr[ model->triIndex[i].meshIndex[1] ].ln[0];
    ny1 = pointListPtr[ model->triIndex[i].meshIndex[1] ].ln[1];
    nz1 = pointListPtr[ model->triIndex[i].meshIndex[1] ].ln[2];
    nx2 = pointListPtr2[ model->triIndex[i].meshIndex[1] ].ln[0];
    ny2 = pointListPtr2[ model->triIndex[i].meshIndex[1] ].ln[1];
    nz2 = pointListPtr2[ model->triIndex[i].meshIndex[1] ].ln[2];
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );


    glTexCoord2f( model->st[ model->triIndex[i].stIndex[2] ].s, model->st[ model->triIndex[i].stIndex[2] ].t );
    x1 = pointListPtr[ model->triIndex[i].meshIndex[2] ].pt[0];
    y1 = pointListPtr[ model->triIndex[i].meshIndex[2] ].pt[1];
    z1 = pointListPtr[ model->triIndex[i].meshIndex[2] ].pt[2];
    x2 = pointListPtr2[ model->triIndex[i].meshIndex[2] ].pt[0];
    y2 = pointListPtr2[ model->triIndex[i].meshIndex[2] ].pt[1];
    z2 = pointListPtr2[ model->triIndex[i].meshIndex[2] ].pt[2];
    nx1 = pointListPtr[ model->triIndex[i].meshIndex[2] ].ln[0];
    ny1 = pointListPtr[ model->triIndex[i].meshIndex[2] ].ln[1];
    nz1 = pointListPtr[ model->triIndex[i].meshIndex[2] ].ln[2];
    nx2 = pointListPtr2[ model->triIndex[i].meshIndex[2] ].ln[0];
    ny2 = pointListPtr2[ model->triIndex[i].meshIndex[2] ].ln[1];
    nz2 = pointListPtr2[ model->triIndex[i].meshIndex[2] ].ln[2];
    glNormal3f( x+nx1 + pol * (nx2 - nx1), y+ny1 + pol * (ny2 - ny1), z+nz1 + pol * (nz2 - nz1) );
    glVertex3f( x+x1 + pol * (x2 - x1), y+y1 + pol * (y2 - y1), z+z1 + pol * (z2 - z1) );

  }

  glEnd();

  return 1;
}


// Load the model
int CModelMD2::LoadModel( const char *fileName, const char *textureName)
{
  FILE *hFile = fopen( fileName, "rb" );

  /* check the file open command */
  if( hFile != NULL )
  {
    int fileLen;
    char *buffer;
    md2modelHeader *mdh;
    md2frame *frm;
    md2coord *pointList, *pointListPtr;
    md2mesh *triIndex, *bufIndexPtr;
    md2stTexCoord *st;
    md2stTexture *stPtr;
    int i, j;

    /* find length of file */
    fseek( hFile, 0, SEEK_END );
    fileLen = ftell( hFile );
    fseek( hFile, 0, SEEK_SET );

    /* read in file */
    buffer = (char *)malloc( fileLen+1 );
    fread( buffer, sizeof( char ), fileLen, hFile );

    /* get pointer to file header */
    mdh = (md2modelHeader *)buffer;

    /* construct the model data structure */
    model = (md2modelData *)malloc( sizeof( md2modelData ));

    /* create a pointlist */
    pointList = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ * mdh->numFrames );
    model->pointList = pointList;
    model->numPoints = mdh->numXYZ;
    model->numFrames = mdh->numFrames;

    model->currentmorph = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ);

    /* loop for number of frames in file */
    for( j=0; j<mdh->numFrames; j++ )
    {
      /* offset to points in frame */
      frm = (md2frame *)&buffer[ mdh->offsetFrames + mdh->framesize * j ];
      pointListPtr = (md2coord *)&pointList[ mdh->numXYZ * j ];
      for( i=0; i<mdh->numXYZ; i++ )
      {
        pointListPtr[i].pt[0] = frm->scale[0] * frm->fp[i].v[0] + frm->translate[0];
        pointListPtr[i].pt[2] = frm->scale[1] * frm->fp[i].v[1] + frm->translate[1];
        pointListPtr[i].pt[1] = frm->scale[2] * frm->fp[i].v[2] + frm->translate[2];

        pointListPtr[i].ln[0] = avertexnormals[frm->fp[i].lightNormalIndex][0];
        pointListPtr[i].ln[1] = avertexnormals[frm->fp[i].lightNormalIndex][1];
        pointListPtr[i].ln[2] = avertexnormals[frm->fp[i].lightNormalIndex][2];

        pointListPtr[i].pt[0] /= 128;
        pointListPtr[i].pt[1] /= 128;
        pointListPtr[i].pt[2] /= 128;
      }
    }

    do {
      /* see if there is a texture associated with the file */
      modelt.width = 1;
      modelt.height = 1;
      if (modelt.LoadPCX((char *)textureName))
      {
        /* create the texture list */
        st = (md2stTexCoord *)malloc( sizeof( md2stTexCoord ) * mdh->numST );
        model->numST = mdh->numST;
        model->st = st;

        stPtr = (md2stTexture *)&buffer[mdh->offsetST];
        for( i=0; i<mdh->numST; i++ )
        {
          st[i].s = (float)stPtr[i].s / (float)modelt.width;
          st[i].t = (float)stPtr[i].t / (float)modelt.width;
        }

        model->zoomstop = false;
      }
    } while( 0 );                      /* only do once */

    /* create a mesh list */
    triIndex = (md2mesh *)malloc( sizeof( md2mesh ) * mdh->numTris );
    model->numTriangles = mdh->numTris;
    model->triIndex = triIndex;

    /* point to indexes in buffers */
    bufIndexPtr = (md2mesh *)&buffer[mdh->offsetTris];

    for( i=0; i<mdh->numTris; i++ )
    {
      triIndex[i].meshIndex[0] = bufIndexPtr[i].meshIndex[0];
      triIndex[i].meshIndex[1] = bufIndexPtr[i].meshIndex[1];
      triIndex[i].meshIndex[2] = bufIndexPtr[i].meshIndex[2];
      triIndex[i].stIndex[0] = bufIndexPtr[i].stIndex[0];
      triIndex[i].stIndex[1] = bufIndexPtr[i].stIndex[1];
      triIndex[i].stIndex[2] = bufIndexPtr[i].stIndex[2];
    }

    /* cleanup */
    free( buffer );
  }
  return 1;
}

// Load the weapon
int CModelMD2::LoadWeapon( const char *fileName, const char *textureName)
{
  FILE *hFile = fopen( fileName, "rb" );

  /* check the file open command */
  if( hFile != NULL )
  {
    int fileLen;
    char *buffer;
    md2modelHeader *mdh;
    md2frame *frm;
    md2coord *pointList, *pointListPtr;
    md2mesh *triIndex, *bufIndexPtr;
    md2stTexCoord *st;
    md2stTexture *stPtr;
    int i, j;
    /* find length of file */
    fseek( hFile, 0, SEEK_END );
    fileLen = ftell( hFile );
    fseek( hFile, 0, SEEK_SET );

    /* read in file */
    buffer = (char *)malloc( fileLen+1 );
    fread( buffer, sizeof( char ), fileLen, hFile );

    /* get pointer to file header */
    mdh = (md2modelHeader *)buffer;

    /* construct the model data structure */
    weapon = (md2modelData *)malloc( sizeof( md2modelData ));

    /* create a pointlist */
    pointList = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ * mdh->numFrames );
    weapon->pointList = pointList;
    weapon->numPoints = mdh->numXYZ;
    weapon->numFrames = mdh->numFrames;

    weapon->currentmorph = (md2coord *)malloc( sizeof( md2coord ) * mdh->numXYZ);

    /* loop for number of frames in file */
    for( j=0; j<mdh->numFrames; j++ )
    {
      /* offset to points in frame */
      frm = (md2frame *)&buffer[ mdh->offsetFrames + mdh->framesize * j ];
      pointListPtr = (md2coord *)&pointList[ mdh->numXYZ * j ];
      for( i=0; i<mdh->numXYZ; i++ )
      {
        pointListPtr[i].pt[0] = frm->scale[0] * frm->fp[i].v[0] + frm->translate[0];
        pointListPtr[i].pt[2] = frm->scale[1] * frm->fp[i].v[1] + frm->translate[1];
        pointListPtr[i].pt[1] = frm->scale[2] * frm->fp[i].v[2] + frm->translate[2];

        pointListPtr[i].pt[0] /= 128;
        pointListPtr[i].pt[1] /= 128;
        pointListPtr[i].pt[2] /= 128;
      }
    }

    do {
      /* see if there is a texture associated with the file */
      weapont.width = 1;
      weapont.height = 1;
      if (weapont.LoadPCX((char *)textureName))
      {
        /* create the texture list */
        st = (md2stTexCoord *)malloc( sizeof( md2stTexCoord ) * mdh->numST );
        weapon->numST = mdh->numST;
        weapon->st = st;

        stPtr = (md2stTexture *)&buffer[mdh->offsetST];
        for( i=0; i<mdh->numST; i++ )
        {
          st[i].s = (float)stPtr[i].s / (float)weapont.width;
          st[i].t = (float)stPtr[i].t / (float)weapont.width;
        }
 
        weapon->zoomstop = false;
      }
    } while( 0 );                      /* only do once */

    /* create a mesh list */
    triIndex = (md2mesh *)malloc( sizeof( md2mesh ) * mdh->numTris );
    weapon->numTriangles = mdh->numTris;
    weapon->triIndex = triIndex;

    /* point to indexes in buffers */
    bufIndexPtr = (md2mesh *)&buffer[mdh->offsetTris];

    for( i=0; i<mdh->numTris; i++ )
    {
      triIndex[i].meshIndex[0] = bufIndexPtr[i].meshIndex[0];
      triIndex[i].meshIndex[1] = bufIndexPtr[i].meshIndex[1];
      triIndex[i].meshIndex[2] = bufIndexPtr[i].meshIndex[2];
      triIndex[i].stIndex[0] = bufIndexPtr[i].stIndex[0];
      triIndex[i].stIndex[1] = bufIndexPtr[i].stIndex[1];
      triIndex[i].stIndex[2] = bufIndexPtr[i].stIndex[2];
    }

    /* cleanup */
    free( buffer );
  }
  isweapon=1;
  return 1;
}
