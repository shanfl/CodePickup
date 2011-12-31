/***************************************************************************
                                 texture.h
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

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "log.h"

#include "GL/gl.h"

class CTexture
{
  public:
  CTexture() { };
  ~CTexture() { };
  int LoadTGA(char *filename);
  int LoadTGA(char *filename,int maketexture);
  int LoadPCX(char *filename);
  int freeData();

  unsigned char *imageData;
  int bpp,width,height;

  GLuint texID;
};
#endif

