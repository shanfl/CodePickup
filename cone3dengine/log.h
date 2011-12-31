/***************************************************************************
                                 log.h
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

#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>

class CLog
{
public:
static void addLine(char* text, ...);
static void addLine2(char* text, ...);
static void initLog();
static void terminateLog();
};

#endif
