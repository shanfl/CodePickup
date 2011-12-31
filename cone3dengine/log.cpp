/***************************************************************************
                                 log.cpp
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

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"

#include <GL/gl.h>

#include "log.h"

// This is actually ShiningKnight's log class...

FILE* log;

void CLog::initLog()
{
	//Clear the log contents
	if((log=fopen("log.txt", "wb"))==NULL) return;

	//Close the file, and return a success!
	fclose(log);
}

void CLog::terminateLog()
{
	if(log) fclose(log);
}

void CLog::addLine(char* text, ...)
{
   char temptext[1024];

	va_list ap;

	//Initialize variable argument list
	va_start(ap, text);
	    vsprintf(temptext, text, ap);
	va_end(ap);

	//Open the log file for append
	if((log = fopen("log.txt", "a+"))==NULL) return;

	fprintf(log,"%s\n", temptext);

	//Close the file
	fclose(log);
}

// NO LINEBREAK
void CLog::addLine2(char* text, ...)
{
   char temptext[1024];

	va_list ap;

	//Initialize variable argument list
	va_start(ap, text);
	    vsprintf(temptext, text, ap);
	va_end(ap);

	//Open the log file for append
	if((log = fopen("log.txt", "a+"))==NULL) return;

	fprintf(log,"%s", temptext);

	//Close the file
	fclose(log);
}
