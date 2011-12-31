#include <GL/gl.h>
#include <GL/glu.h>

#include "skybox.h"

void CSkyBox::build(char *dirr)
{
  char file[255];
  sprintf(file,"%s/up.tga",dirr); up.LoadTGA(file);
  sprintf(file,"%s/dn.tga",dirr); dn.LoadTGA(file);
  sprintf(file,"%s/lf.tga",dirr); lf.LoadTGA(file);
  sprintf(file,"%s/rt.tga",dirr); rt.LoadTGA(file);
  sprintf(file,"%s/bk.tga",dirr); bk.LoadTGA(file);
  sprintf(file,"%s/ft.tga",dirr); ft.LoadTGA(file);
}

void CSkyBox::draw(float x, float y)
{
	glPushMatrix();
	glLoadIdentity();
	glRotatef(x,1,0,0);
	glRotatef(y,0,1,0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D); 

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0f,1,0.1f,100000.0f);
	glMatrixMode(GL_MODELVIEW);

	float s = 1000;

	glColor4f(1,1,1,1);
	glBindTexture(GL_TEXTURE_2D, ft.texID);
	glBegin(GL_QUADS);
		//front
		glTexCoord2f(0.0, 0.0); glVertex3f( s,-s, s);
		glTexCoord2f(1.0, 0.0); glVertex3f(-s,-s, s);
		glTexCoord2f(1.0, 1.0); glVertex3f(-s, s, s);
		glTexCoord2f(0.0, 1.0); glVertex3f( s, s, s);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, bk.texID);
	glBegin(GL_QUADS);
		//back
		glTexCoord2f(0.0, 0.0); glVertex3f(-s,-s, -s);
		glTexCoord2f(1.0, 0.0); glVertex3f( s,-s, -s);
		glTexCoord2f(1.0, 1.0); glVertex3f( s, s, -s);
		glTexCoord2f(0.0, 1.0); glVertex3f(-s, s, -s);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, dn.texID);
	glBegin(GL_QUADS);
		//bott
		glTexCoord2f(1.0, 1.0); glVertex3f( s,-s, s);
		glTexCoord2f(0.0, 1.0); glVertex3f( s,-s, -s);
		glTexCoord2f(0.0, 0.0); glVertex3f(-s,-s, -s);
		glTexCoord2f(1.0, 0.0); glVertex3f(-s,-s, s);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, up.texID);
	glBegin(GL_QUADS);
		//top
		glTexCoord2f(0.0, 1.0); glVertex3f(-s,s, -s);
		glTexCoord2f(0.0, 0.0); glVertex3f( s,s, -s);
		glTexCoord2f(1.0, 0.0); glVertex3f( s,s, s);
		glTexCoord2f(1.0, 1.0); glVertex3f(-s,s, s);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, rt.texID);
	glBegin(GL_QUADS);
		//left
		glTexCoord2f(0.0, 0.0); glVertex3f( s,-s, -s);
		glTexCoord2f(1.0, 0.0); glVertex3f( s,-s, s);
		glTexCoord2f(1.0, 1.0); glVertex3f( s, s, s);
		glTexCoord2f(0.0, 1.0); glVertex3f( s, s, -s);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, lf.texID);
	glBegin(GL_QUADS);
		//right
		glTexCoord2f(0.0, 0.0); glVertex3f(-s,-s, s);
		glTexCoord2f(1.0, 0.0); glVertex3f(-s,-s, -s);
		glTexCoord2f(1.0, 1.0); glVertex3f(-s, s, -s);
		glTexCoord2f(0.0, 1.0); glVertex3f(-s, s, s);
	glEnd();

	glPopMatrix();
/*

  glBindTexture(GL_TEXTURE_2D, up.texID);
  glBegin(GL_TRIANGLES);
  glTexCoord2f(0,0); glVertex3f(0,1,0);
  glTexCoord2f(1,0); glVertex3f(1,1,0);
  glTexCoord2f(1,1); glVertex3f(1,1,1);
  glTexCoord2f(1,1); glVertex3f(1,1,1);
  glTexCoord2f(0,1); glVertex3f(0,1,1);
  glTexCoord2f(0,0); glVertex3f(0,1,0);
  glEnd();
*/
}



