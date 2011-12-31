/***************************************************************************
                                 font.h
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

#ifndef __FONT_H__
#define __FONT_H__

#include "log.h"
#include "texture.h"

class CFont
{
  public:
  CFont() {sizex=1.0f; sizey=1.0f;};
	~CFont() {KillFont();};
  int BuildFont(char *file);
  int PrintText(int x, int y, char type, char *fmt, ...);
  int KillFont();
  int SetSize(float x, float y);

  CTexture font;
  int base;
  float sizex,sizey;
};

#endif
