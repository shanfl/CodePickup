/***************************************************************************
                                 texture.cpp
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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <GL/gl.h>

#include "texture.h"

//#define FALSE 1
//#define TRUE 0

typedef struct _pcxHeader
{
  short id[2];
  short offset[2];
  short size[2];
} pcxHeader;

int CTexture::LoadPCX(char *filename)
{
  FILE *hTexFile = fopen( filename, "rb" );
  /* check the file open command */
  if( hTexFile != NULL )
  {
    int imgWidth, imgHeight, texFileLen, imgBufferPtr, i;
    pcxHeader *pcxPtr;
    unsigned char *imgBuffer, *texBuffer, *pcxBufferPtr, *paletteBuffer;

    /* find length of file */
    fseek( hTexFile, 0, SEEK_END );
    texFileLen = ftell( hTexFile );
    fseek( hTexFile, 0, SEEK_SET );

    /* read in file */
    texBuffer = (unsigned char *)malloc( texFileLen+1 );
    fread( texBuffer, sizeof( char ), texFileLen, hTexFile );

    /* get the image dimensions */
    pcxPtr = (pcxHeader *)texBuffer;
    imgWidth = pcxPtr->size[0] - pcxPtr->offset[0] + 1;
    imgHeight = pcxPtr->size[1] - pcxPtr->offset[1] + 1;

    /* image starts at 128 from the beginning of the buffer */
    imgBuffer = (unsigned char *)malloc( imgWidth * imgHeight );
    imgBufferPtr = 0;
    pcxBufferPtr = &texBuffer[128];

    /* decode the pcx image */
    while( imgBufferPtr < (imgWidth * imgHeight) )
    {
      if( *pcxBufferPtr > 0xbf )
      {
        int repeat = *pcxBufferPtr++ & 0x3f;
        for( i=0; i<repeat; i++ )
	{
          imgBuffer[imgBufferPtr++] = *pcxBufferPtr;
	}
          
      } else {
        imgBuffer[imgBufferPtr++] = *pcxBufferPtr;
      }
      pcxBufferPtr++;
    }
    /* read in the image palette */
    paletteBuffer = (unsigned char *)malloc( 768 );
    for( i=0; i<768; i++ )
      paletteBuffer[i] = texBuffer[ texFileLen-768+i ];

    width=imgWidth;
    height=imgHeight;

    /* now create the OpenGL texture */
    {
      int i, j;
      imageData = (unsigned char *)malloc( width * height * 3 );
      for (j = 0; j < imgHeight; j++)
      {
        for (i = 0; i < imgWidth; i++)
        {
          imageData[3*(j * width + i)+0]
            = paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+0 ];
          imageData[3*(j * width + i)+1]
            = paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+1 ];
          imageData[3*(j * width + i)+2]
            = paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+2 ];
        }
      }
    }
    /* cleanup */
    free( paletteBuffer );
    free( imgBuffer );
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D(GL_TEXTURE_2D,0,3,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,imageData);
    freeData();
  } else {
    /* skip the texture setup functions */
    return 0;
  }
  bpp=24;

  return 1;
}

int CTexture::LoadTGA(char *filename)			// Loads A TGA File Into Memory
{
  return LoadTGA(filename,1);
}

int CTexture::freeData()
{
  if(imageData != 0)
  {
    delete [] imageData;
  }
  return 0;
}

int CTexture::LoadTGA(char *filename, int maketexture)			// Loads A TGA File Into Memory
{
  GLubyte TGAcomment[1];                         // Nr. of bytes used for the comment
  GLubyte TGAheader[11]={0,2,0,0,0,0,0,0,0,0,0}; // Uncompressed TGA Header
  GLubyte TGAcompare[11];                        // Used To Compare TGA Header
  GLubyte		header[6];									// First 6 Useful Bytes From The Header
  GLuint		bytesPerPixel;								// Holds Number Of Bytes Per Pixel Used In The TGA File
  GLuint		imageSize;									// Used To Store The Image Size When Setting Aside Ram
  GLuint		temp;										// Temporary Variable
  GLuint		type=GL_RGBA;								// Set The Default GL Mode To RBGA (32 BPP)
  int i;

  CLog::addLine2("Loading texture %s ....",filename);

  FILE *file = fopen(filename, "rb");						// Open The TGA File

  if(file==NULL ||                               // Does File Even Exist?
    fread(TGAcomment,1,sizeof(TGAcomment),file)!=sizeof(TGAcomment) || // Try to read the comment byte
    fread(TGAcompare,1,sizeof(TGAcompare),file)!=sizeof(TGAcompare) || // Are There 12 Bytes To Read?
    memcmp(TGAheader,TGAcompare,sizeof(TGAheader))!=0 || // Does The Header Match What We Want?
    fread(header,1,sizeof(header),file)!=sizeof(header)) // If So Read Next 6 Header Bytes
  {
    if (file == NULL) {									// Did The File Even Exist? *Added Jim Strong*
      return FALSE;									// Return False
    } else {
      fclose(file);									// If Anything Failed, Close The File
      return FALSE;									// Return False
    }
   }


  char comment[TGAcomment[0]];                   // If the tga image has a comment then read it
  if(TGAcomment[0] != 0)
    fread(comment, 1, sizeof(comment), file);

	width  = header[1] * 256 + header[0];			// Determine The TGA Width	(highbyte*256+lowbyte)
	height = header[3] * 256 + header[2];			// Determine The TGA Height	(highbyte*256+lowbyte)
	CLog::addLine2("..%dx%d..",width,height);

 	if(	width	<=0	||								// Is The Width Less Than Or Equal To Zero
		height	<=0	||								// Is The Height Less Than Or Equal To Zero
		(header[4]!=24 && header[4]!=32))					// Is The TGA 24 or 32 Bit?
	{
		fclose(file);										// If Anything Failed, Close The File
		return FALSE;										// Return False
	}

	bpp	= header[4];							// Grab The TGA's Bits Per Pixel (24 or 32)
	bytesPerPixel	= bpp/8;						// Divide By 8 To Get The Bytes Per Pixel
	imageSize		= width*height*bytesPerPixel;	// Calculate The Memory Required For The TGA Data

	imageData=(GLubyte *)malloc(imageSize);		// Reserve Memory To Hold The TGA Data

	if(	imageData==NULL ||							// Does The Storage Memory Exist?
		fread(imageData, 1, imageSize, file)!=imageSize)	// Does The Image Size Match The Memory Reserved?
	{
		if(imageData!=NULL)						// Was Image Data Loaded
			free(imageData);						// If So, Release The Image Data

		fclose(file);										// Close The File
		return FALSE;										// Return False
	}

	for(i=0; i<(int)(imageSize); i+=bytesPerPixel)		// Loop Through The Image Data
	{														// Swaps The 1st And 3rd Bytes ('R'ed and 'B'lue)
		temp=imageData[i];							// Temporarily Store The Value At Image Data 'i'
		imageData[i] = imageData[i + 2];	// Set The 1st Byte To The Value Of The 3rd Byte
		imageData[i + 2] = temp;					// Set The 3rd Byte To The Value In 'temp' (1st Byte Value)
	}

	fclose (file);											// Close The File

	if(maketexture == 1)
	{
	  // Build A Texture From The Data
	  glGenTextures(1, &texID);					// Generate OpenGL texture IDs

	  glBindTexture(GL_TEXTURE_2D, texID);			// Bind Our Texture
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtered
	  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Filtered

	  if (bpp==24)									// Was The TGA 24 Bits
	  {
		  type=GL_RGB;										// If So Set The 'type' To GL_RGB
	  }

	  glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, imageData);
      freeData();
    }
	CLog::addLine("....... done");
	return TRUE;											// Texture Building Went Ok, Return True
}
