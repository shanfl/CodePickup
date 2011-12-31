/***************************************************************************
                                 initstuff.h
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

#ifndef __INITSTUFF_H__
#define __INITSTUFF_H__

#include "log.h"

class CInitStuff
{
  public:
  CInitStuff() { }
  ~CInitStuff() { destroyWindow(); }

  void screenShot();
  unsigned char * getPixelsRGB();
  unsigned char * getPixelsBGR();
  int initSDL(int width, int height, int bpp, int fullscreen, int mode, int audio);
  int setTitle(char * title);
  int initGL();
  int resizeGLScene(int width, int height);
  int destroyWindow();
};

#endif
