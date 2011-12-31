/***************************************************************************
                                 initstuff.cpp
                             -------------------
    begin                : Thu Oct 25 2001
    copyright            : (C) 2001 by Marius Andra
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

#include "initstuff.h"

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

typedef unsigned char uchar;

int CInitStuff::initSDL(int width, int height, int bpp, int fullscreen, int mode, int audio)
{
  CLog::addLine("Starting SDL Initalization");
  if(audio == 1)
  {
    if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0 )
    {
      CLog::addLine("Unable to initialize SDL: %s\n", SDL_GetError());
      return(1);
    }
  } else {
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
      CLog::addLine("Unable to initialize SDL: %s\n", SDL_GetError());
      return(1);
    }
  }
  CLog::addLine("SDL Initalized");
  CLog::addLine("%d x %d x %d Fullscreen: %d",width,height,bpp,fullscreen);
  CLog::addLine("\nStarting OpenGL Screen Initalization");
  if(fullscreen == 1)
  {
    if ( SDL_SetVideoMode(width, height, bpp, SDL_OPENGL|SDL_FULLSCREEN) == NULL )
    {
      CLog::addLine("Unable to create OpenGL screen: %s\n", SDL_GetError());
      SDL_Quit();
      return(2);
    }
  } else {
    if ( SDL_SetVideoMode(width, height, bpp, SDL_OPENGL) == NULL )
    {
      CLog::addLine("Unable to create OpenGL screen: %s\n", SDL_GetError());
      SDL_Quit();
      return(2);
    }
  }
  CLog::addLine("GL_RENDERER: %s",(char *)glGetString(GL_RENDERER));
  CLog::addLine("GL_VENDOR: %s",(char *)glGetString(GL_VENDOR));
  CLog::addLine("GL_VERSION: %s\n",(char *)glGetString(GL_VERSION));

  initGL();
  resizeGLScene(width,height);

  return 0;
}

int CInitStuff::initGL()
{
  glEnable(GL_TEXTURE_2D);                  // Enable Texture Mapping
  glShadeModel(GL_SMOOTH);                  // Enable Smooth Shading
  glClearColor(0.00f, 0.00f, 0.00f, 0.0f);  // Black Background
  glClearDepth(1.0f);                       // Depth Buffer Setup
  glEnable(GL_DEPTH_TEST);                  // Enables Depth Testing
  glDepthFunc(GL_LEQUAL);                   // The Type Of Depth Testing To Do
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);// Really Nice Perspective Calculations
  return 0;
}

int CInitStuff::resizeGLScene(int width, int height)
{
  CLog::addLine2("Resizing OpenGL Scene .......");

  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f,1,0.1f,100000.0f);
  glMatrixMode(GL_MODELVIEW);
/*
   glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
*/  glLoadIdentity();
  CLog::addLine("....... done");
  return 0;
}

int CInitStuff::setTitle(char * title)
{
  SDL_WM_SetCaption(title, NULL);
  CLog::addLine("Window title set to %s",title);
  return 0;
}

void CInitStuff::screenShot()
{
  uchar *pixels;
  pixels = getPixelsBGR();

  FILE * shot;
  if((shot=fopen("shot.tga", "wb"))==NULL) return;
  int screenStats[4];
  glGetIntegerv(GL_VIEWPORT, screenStats);
  uchar TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};
  uchar Header[6]={((int)(screenStats[2]%256)),((int)(screenStats[2]/256)),((int)(screenStats[3]%256)),((int)(screenStats[3]/256)),24,0};
  fwrite(TGAheader, sizeof(uchar), 12, shot);
  fwrite(Header, sizeof(uchar), 6, shot);
  fwrite(pixels, sizeof(uchar), screenStats[2]*screenStats[3]*3, shot);
  delete [] pixels;
  fclose(shot);

  CLog::addLine("Screenshot taken");
}

unsigned char * CInitStuff::getPixelsRGB()
{
  int screenStats[4];
  glGetIntegerv(GL_VIEWPORT, screenStats);
  unsigned char *pixels;
  pixels = new unsigned char[screenStats[2]*screenStats[3]*3];
  glReadPixels(0, 0, screenStats[2], screenStats[3], GL_RGB, GL_UNSIGNED_BYTE, pixels);
  return pixels;
}

unsigned char * CInitStuff::getPixelsBGR()
{
  int screenStats[4];
  glGetIntegerv(GL_VIEWPORT, screenStats);
  unsigned char *pixels;
  pixels = new unsigned char[screenStats[2]*screenStats[3]*3];
  glReadPixels(0, 0, screenStats[2], screenStats[3], GL_BGR, GL_UNSIGNED_BYTE, pixels);
  return pixels;
}

int CInitStuff::destroyWindow()
{
  CLog::addLine2("Finishing up SDL .......");
  SDL_Quit();
  CLog::addLine("....... done");
  return 0;
}



