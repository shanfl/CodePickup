/***************************************************************************
                                 main.cpp
                             -------------------
    begin                : Thu Oct 25 17:50:01 EET 2001
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

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define SAME_CLOCKNESS 1
#define DIFF_CLOCKNESS 0

// #include "mmgr.h"

//#include "3DMath.h"
#include "vectormath.h"
#include "initstuff.h"
#include "response.h"
#include "texture.h"
#include "frustum.h"
#include "player.h"
#include "3dmath.h"
#include "camera.h"
#include "skybox.h"
#include "vector.h"
#include "octre.h"
#include "font.h"
#include "log.h"
#include "md2.h"

CInitStuff C3D;
CFont C3DFont;
CSkyBox sky;

float lastframe,thisframe; 
int ff, fps;

float LightAmbient[]={0.5f,0.5f,0.5f,1.0f};
float LightDiffuse[]={1.0f,1.0f,1.0f,1.0f};
float LightPosition[]={0.0f,0.0f,2.0f,1.0f};

float spd=0.05;

COctree octree;
CFrustum frustum;
CPlayer player;
CPlayer player2;
CCamera camera;

long lframetime;
float utime;

CTexture textures[5];

CTriangle *triangles;
int *triangles2;
int numtriangles=0;
long fff=0;

int screenWidth=1024;
int screenHeight=768;
int screenBPP=32;
int fullScreen=1;

float z=0.0;               // Z rotation
GLfloat xrot=0;            // x rotation
GLfloat yrot=0;            // y rotation
GLfloat walkbias = 0;
GLfloat walkbiasangle = 0;
GLfloat lookupdown = 0.0;
float heading=0;

const float piover180 = 0.0174532925f;

float xmin=0, ymin=0, zmin=0, xmax=0, ymax=0, zmax=0, xabs=0, yabs=0, zabs=0, maxabs=0;

int foundCollision;
double nearestDistance;
CVector3D nearestIntersectionPoint;
CVector3D nearestPolygonIntersectionPoint;
CVector3D tempVector;
CVector3D source, normalizedVelocity, velocity;

int check_same_clock_dir2(CVector3D pt1, CVector3D pt2, CVector3D pt3, CVector3D norm)
{  
   float testi, testj, testk;
   float dotprod;
   // normal of trinagle
   testi = (((pt2.y - pt1.y)*(pt3.z - pt1.z)) - ((pt3.y - pt1.y)*(pt2.z - pt1.z)));
   testj = (((pt2.z - pt1.z)*(pt3.x - pt1.x)) - ((pt3.z - pt1.z)*(pt2.x - pt1.x)));
   testk = (((pt2.x - pt1.x)*(pt3.y - pt1.y)) - ((pt3.x - pt1.x)*(pt2.y - pt1.y)));

   // Dot product with triangle normal
   dotprod = testi*norm.x + testj*norm.y + testk*norm.z;

   // answer
   if(dotprod >= -0.02f) 
      return SAME_CLOCKNESS;
   else 
      return DIFF_CLOCKNESS;
}
float PlaneDistance(CVector3D n, CVector3D p)
{
  return -((n.x*p.x)+(n.y*p.y)+(n.z*p.z));
}

int rayTriangleIntersect(CTriangle tri, CVector3D pt1, CVector3D pt2)
{
  CVector3D normal = tri.normal;
  float ordist = PlaneDistance(normal, tri.v[0]);
  float d1 = ((normal.x * pt1.x)+(normal.y * pt1.y)+(normal.z * pt1.z))+ordist;
  float d2 = ((normal.x * pt2.x)+(normal.y * pt2.y)+(normal.z * pt2.z))+ordist;

  if(d1*d2>0) return 1;
  return 0;
}

int check_intersect_tri(CVector3D pt1, CVector3D pt2, CVector3D pt3, CVector3D linept, CVector3D vect,
                        CVector3D* pt_int)
{
   float V1x, V1y, V1z;
   float V2x, V2y, V2z;
   CVector3D norm;
   float dotprod;
   float t;

   // vector form triangle pt1 to pt2
   V1x = pt2.x - pt1.x;
   V1y = pt2.y - pt1.y;
   V1z = pt2.z - pt1.z;

   // vector form triangle pt2 to pt3
   V2x = pt3.x - pt2.x;
   V2y = pt3.y - pt2.y;
   V2z = pt3.z - pt2.z;

   // vector normal of triangle
   norm.x = V1y*V2z-V1z*V2y;
   norm.y = V1z*V2x-V1x*V2z;
   norm.z = V1x*V2y-V1y*V2x;

   // dot product of normal and line's vector if zero line is parallel to triangle
   dotprod = norm.x*vect.x + norm.y*vect.y + norm.z*vect.z;

   if(dotprod < 0)
   {
      //Find point of intersect to triangle plane.
      //find t to intersect point
      t = -(norm.x*(linept.x-pt1.x)+norm.y*(linept.y-pt1.y)+norm.z*(linept.z-pt1.z))/
             (norm.x*vect.x+norm.y*vect.y+norm.z*vect.z);

      // if ds is neg line started past triangle so can't hit triangle.
      if(t < 0) return 0;

      pt_int->x = linept.x + vect.x*t;
      pt_int->y = linept.y + vect.y*t;
      pt_int->z = linept.z + vect.z*t;

      CVector3D Pt_int;

      Pt_int.x=pt_int->x;
      Pt_int.y=pt_int->y;
      Pt_int.z=pt_int->z;

      if(check_same_clock_dir2(pt1, pt2, Pt_int, norm) == SAME_CLOCKNESS)
      {
         if(check_same_clock_dir2(pt2, pt3, Pt_int, norm) == SAME_CLOCKNESS)
         {
            if(check_same_clock_dir2(pt3, pt1, Pt_int, norm) == SAME_CLOCKNESS)
            {
               // answer in pt_int is insde triangle
               return 1;
            }
         }
      }
/*      if(check_same_clock_dir2(pt1, pt2, Pt_int, norm) == DIFF_CLOCKNESS)
      {
         if(check_same_clock_dir2(pt2, pt3, Pt_int, norm) == DIFF_CLOCKNESS)
         {
            if(check_same_clock_dir2(pt3, pt1, Pt_int, norm) == DIFF_CLOCKNESS)
            {
               // answer in pt_int is insde triangle
               return 1;
            }
         }
      }
*/
   }
   CVector3D tv;
   norm=tv-norm;
   // dot product of normal and line's vector if zero line is parallel to triangle
   dotprod = norm.x*vect.x + norm.y*vect.y + norm.z*vect.z;

   if(dotprod < 0)
   {
      //Find point of intersect to triangle plane.
      //find t to intersect point
      t = -(norm.x*(linept.x-pt1.x)+norm.y*(linept.y-pt1.y)+norm.z*(linept.z-pt1.z))/
             (norm.x*vect.x+norm.y*vect.y+norm.z*vect.z);

      // if ds is neg line started past triangle so can't hit triangle.
      if(t < 0) return 0;

      pt_int->x = linept.x + vect.x*t;
      pt_int->y = linept.y + vect.y*t;
      pt_int->z = linept.z + vect.z*t;

      CVector3D Pt_int;

      Pt_int.x=pt_int->x;
      Pt_int.y=pt_int->y;
      Pt_int.z=pt_int->z;

      if(check_same_clock_dir2(pt1, pt2, Pt_int, norm) == SAME_CLOCKNESS)
      {
         if(check_same_clock_dir2(pt2, pt3, Pt_int, norm) == SAME_CLOCKNESS)
         {
            if(check_same_clock_dir2(pt3, pt1, Pt_int, norm) == SAME_CLOCKNESS)
            {
               // answer in pt_int is insde triangle
               return 1;
            }
         }
      }
/*      if(check_same_clock_dir2(pt1, pt2, Pt_int, norm) == DIFF_CLOCKNESS)
      {
         if(check_same_clock_dir2(pt2, pt3, Pt_int, norm) == DIFF_CLOCKNESS)
         {
            if(check_same_clock_dir2(pt3, pt1, Pt_int, norm) == DIFF_CLOCKNESS)
            {
               // answer in pt_int is insde triangle
               return 1;
            }
         }
      }
*/
   }
   return 0;
}


/*
inline int check_intersect_sphere_tri(CTriangle tri, CVector3D linept, float radius,CVector3D *pt)
//actually it's just a distance to triangle test, but that's the same.
{
  CVector3D norm;
  float d;
  float t;

  norm=tri.normal;
  d=tri.d;

  float dx = norm.x*linept.x;
  float dy = norm.y*linept.y;
  float dz = norm.z*linept.z;
  float D = dx+dy+dz+d;

  if((D <= radius))
  {
    CVector3D PT;

    PT.x=linept.x-D*norm.x;
    PT.y=linept.y-D*norm.y;
    PT.z=linept.z-D*norm.z;

    pt->x=PT.x;
    pt->y=PT.y;
    pt->z=PT.z;

    if(check_same_clock_dir2(tri.v[0], tri.v[1], PT, norm) == SAME_CLOCKNESS)
    {
      if(check_same_clock_dir2(tri.v[1], tri.v[2], PT, norm) == SAME_CLOCKNESS)
      {
        if(check_same_clock_dir2(tri.v[2], tri.v[0], PT, norm) == SAME_CLOCKNESS)
        {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}
*/


int DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  // Rotate and Translate
  camera.doit();
//  gluLookAt(0,0.4,0,player.xpos,0.4,player.zpos,0,lookupdown>90&&lookupdown<270?-1:1,0);

  glColor3f(1,1,1);
  fff++;
  frustum.UpdateFrustum();
  octree.resetNumDrawn();
  octree.draw(triangles,textures,&fff,&frustum,1);

  player.draw();
  player2.draw();

  sky.draw(camera.lookupdown,360-camera.yrot);

  C3DFont.SetSize(1,1.5); C3DFont.PrintText(188,10,0,"Cone3D Octree Engine");
  glColor3f(1,1,0);
  C3DFont.SetSize(1,1); C3DFont.PrintText(screenWidth-308,screenHeight-16,0,"http://cone3d.gamedev.net");
  C3DFont.SetSize(0.8,0.8); C3DFont.PrintText(0,0,0,"FPS: %d",fps);
  C3DFont.PrintText(0,14,0,"Drawn: %d",octree.getNumDrawn());
  int iic=0;
  VECTOR3D l[2];
  l[0].x=camera.x;
  l[0].y=camera.y+0.2;
  l[0].z=camera.z;
  l[1].x=camera.x+(cos(camera.lookupdown*0.0174532925f)*camera.dist * sin((camera.yrot) * 0.0174532925f));
  l[1].y=camera.y+0.2+(sin(camera.lookupdown*0.0174532925f)*camera.dist);
  l[1].z=camera.z+(cos(camera.lookupdown*0.0174532925f)*camera.dist * cos((camera.yrot) * 0.0174532925f));
  for(int i=0;i<numtriangles;i++)
  {
    VECTOR3D vPoly[3];
    vPoly[0].x=triangles[i].v[0].x; vPoly[0].y=triangles[i].v[0].y; vPoly[0].z=triangles[i].v[0].z;
    vPoly[1].x=triangles[i].v[1].x; vPoly[1].y=triangles[i].v[1].y; vPoly[1].z=triangles[i].v[1].z;
    vPoly[2].x=triangles[i].v[2].x; vPoly[2].y=triangles[i].v[2].y; vPoly[2].z=triangles[i].v[2].z;
    if(IntersectedPolygon(vPoly, l, 3)) iic=1;
//    if(check_intersect_tri(triangles[i].v[0], triangles[i].v[1], triangles[i].v[2], pt1, pt2-pt1,&tempvector)==1) iic=1;
  }
  C3DFont.PrintText(0,28,0,"X: %f Z: %f IC: %d",player.xpos,player.zpos,iic);
  C3DFont.PrintText(0,42,0,"P1: %f %f %f   P2: %f %f %f\n",l[0].x,l[0].y,l[0].z,l[1].x,l[1].y,l[1].z);
//  C3DFont.PrintText(0,42,0,"J:%d R:%d C:%d T:%d A:%d P:%d D:%d T:%d",player.jump,player.run,player.crouch,player.taunt,player.attack,player.pain,player.death,player.transform);

  SDL_GL_SwapBuffers();
  return 0;
}

// Read a line from a text file 
void readstr(FILE *f,char *string) 
{ 
 do 
 { 
  fgets(string, 255, f); 
 } while ((string[0] == '/') || (string[0] == '\r') || (string[0] == '\n')); 
 return; 
} 

// Set up the world into sector1
void SetupWorld(char *file)
{ 
  float x, y, z, u, v;
  int loop, vert;
  FILE *filein;
  char oneline[255];

  // Open the file
  filein = fopen(file, "rt");

  // And read in the lines
  readstr(filein,oneline);
  sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);

  triangles = new CTriangle[numtriangles];
  triangles2 = new int[numtriangles];
  numtriangles = numtriangles;

  // While remembering the polygon data
  for (loop = 0; loop < numtriangles; loop++)
  {
    readstr(filein,oneline);
    sscanf(oneline, "%i\n", &triangles[loop].texture);

    triangles[loop].id=loop;
    triangles2[loop]=loop;

    for (vert = 0; vert < 3; vert++)
    {
      readstr(filein,oneline);
      sscanf(oneline, "%f %f %f %f %f %f %f", &x, &y, &z, &u, &v);
      if(x<xmin) {xmin=x;} else if(x>xmax) {xmax=x;}
      if(y<ymin) {ymin=y;} else if(y>ymax) {ymax=y;}
      if(z<zmin) {zmin=z;} else if(z>zmax) {zmax=z;}
      triangles[loop].v[vert].x = x;
      triangles[loop].v[vert].y = y;
      triangles[loop].v[vert].z = z;
      triangles[loop].v[vert].u = u;
      triangles[loop].v[vert].v = v;
    }
    triangles[loop].normal = calcnormal(triangles[loop].v[0],triangles[loop].v[1],triangles[loop].v[2]);
    triangles[loop].d=-(triangles[loop].v[0].x*triangles[loop].normal.x + triangles[loop].v[0].y*triangles[loop].normal.y + triangles[loop].v[0].z*triangles[loop].normal.z);
  }

  // Close the file
  fclose(filein);
  return;
} 

void cleanup(void)
{
  octree.demolish();
  SDL_Quit();
  if(triangles != 0) delete [] triangles;
  if(triangles2 !=0) delete [] triangles2;
}

int main(int argc, char *argv[])
{
  Uint8* keys;
  int done=0;

  CLog::initLog();
  if(C3D.initSDL(screenWidth,screenHeight,screenBPP,fullScreen,0,0)) exit(0);
  if(C3DFont.BuildFont("data/font/font.tga")) exit(0);

  SetupWorld("data/world.txt");
  xabs=0;yabs=0;zabs=0;

  xabs=xmax-xmin;
  yabs=ymax-ymin;
  zabs=zmax-zmin;
  CLog::addLine("X: %f %f",xmin,xmax);
  CLog::addLine("Y: %f %f",ymin,ymax);
  CLog::addLine("Z: %f %f",zmin,zmax);
  if(xabs>maxabs) maxabs=xabs;
  if(yabs>maxabs) maxabs=yabs;
  if(zabs>maxabs) maxabs=zabs;
  CLog::addLine("Xa: %f",xabs);
  CLog::addLine("Ya: %f",yabs);
  CLog::addLine("Za: %f",zabs);
  CLog::addLine("Ma: %f",maxabs);
  if(xabs<maxabs) {xmin-=((maxabs-xabs)/2); xmax+=((maxabs-xabs)/2);}
  if(yabs<maxabs) {ymax+=((maxabs-yabs)); }
  if(zabs<maxabs) {zmin-=((maxabs-zabs)/2); zmax+=((maxabs-zabs)/2);}
  CLog::addLine("X: %f %f",xmin,xmax);
  CLog::addLine("Y: %f %f",ymin,ymax);
  CLog::addLine("Z: %f %f",zmin,zmax);

  octree.build(triangles, triangles2, xmin, xmax, ymin, ymax, zmin, zmax, numtriangles);

  textures[0].LoadTGA("data/textures/floor1.tga");
  textures[1].LoadTGA("data/textures/light1.tga");
  textures[2].LoadTGA("data/textures/rustyblue.tga");
  textures[3].LoadTGA("data/textures/crate.tga");
  textures[4].LoadTGA("data/textures/weirdbrick.tga");

  lastframe=SDL_GetTicks();
  lframetime=(long)lastframe;

  // Enable light
  glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
  glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
  glEnable(GL_LIGHT1);
//  glEnable(GL_LIGHTING);

  player.init("data/player","tris.md2","player.pcx","weapon.md2","weapon.pcx",5,0.2,5);
  player2.init("data/player2","tris.md2","player.pcx","weapon.md2","weapon.pcx",10,0.2,10);

  sky.build("data/skybox");

  camera.hook(&player);
  itri(triangles, numtriangles);

  glEnable(GL_TEXTURE_2D);
  CLog::addLine("\nStarting main loop");

  while(done == 0)
  {
    SDL_Event event;

    while ( SDL_PollEvent(&event) )
    {
      if ( event.type == SDL_QUIT )  {  done = 1;  }
      if ( event.type == SDL_KEYDOWN )
      {
        if ( event.key.keysym.sym == SDLK_RCTRL ) { player.attac(); }
        if ( event.key.keysym.sym == SDLK_SPACE )
        {
          player.jumpup();
/*
          CVector3D pos(player.xpos,player.ypos,player.zpos);
          CVector3D vel(0,0.03,0);
          pos=GetPosition(pos,vel);
          player.xpos=pos.x;player.ypos=pos.y;player.zpos=pos.z;
*/
        }
        if ( event.key.keysym.sym == SDLK_z ) { camera.hook(&player); }
        if ( event.key.keysym.sym == SDLK_x ) { camera.hook(&player2); }
        if ( event.key.keysym.sym == SDLK_q ) { player2.attac(); }
        if ( event.key.keysym.sym == SDLK_e ) { player2.jumpup(); }
        if ( event.key.keysym.sym == SDLK_1 ) { player.ouch(1); }
        if ( event.key.keysym.sym == SDLK_2 ) { player.ouch(2); }
        if ( event.key.keysym.sym == SDLK_3 ) { player.ouch(3); }
//        if ( event.key.keysym.sym == SDLK_r ) { camera.movewith=!camera.movewith; }
//        if ( event.key.keysym.sym == SDLK_T ) { player.taunt(PLAYER_TAUNT); }
        if ( event.key.keysym.sym == SDLK_ESCAPE ) { done = 1; }
        if ( event.key.keysym.sym == SDLK_RETURN ) { octree.togglelines(); }
        if ( event.key.keysym.sym == SDLK_F12 ) { C3D.screenShot(); }
      }
    }

    DrawGLScene();
    thisframe=SDL_GetTicks();
    utime=(((float)(thisframe-lframetime))*0.09);
    lframetime=(long)thisframe;
    ff++;
    if((thisframe-lastframe) > 1000) {fps=ff; ff=0;lastframe=thisframe;}

    keys = SDL_GetKeyState(NULL);
    // And move the player if neccesary
    if ( keys[SDLK_PAGEUP] == SDL_PRESSED ) {
      camera.lookupdown -= 1.0f*utime;
      if(camera.lookupdown<0) camera.lookupdown+=360;
    }
    if ( keys[SDLK_PAGEDOWN] == SDL_PRESSED ) {
      camera.lookupdown += 1.0f*utime;
      if(camera.lookupdown>360) camera.lookupdown-=360;
    }
    if ( keys[SDLK_UP] == SDL_PRESSED ) {
      CVector3D pos(player.xpos,player.ypos,player.zpos);
      CVector3D vel(sin(player.yrot*piover180)*-spd*utime,0,cos(player.yrot*piover180)*-spd*utime);
      pos=GetPosition(pos,vel);
      player.xpos=pos.x;player.ypos=pos.y;player.zpos=pos.z;
      player.running(1);
    }
    if ( keys[SDLK_DOWN] == SDL_PRESSED ) {
      CVector3D pos(player.xpos,player.ypos,player.zpos);
      CVector3D vel(sin(player.yrot*piover180)*spd*utime,0,cos(player.yrot*piover180)*spd*utime);
      pos=GetPosition(pos,vel);
      player.xpos=pos.x;player.ypos=pos.y;player.zpos=pos.z;
      player.running(1);
    }
    if( (keys[SDLK_DOWN] == keys[SDLK_UP]) )
    {
      player.running(0);
    }
    if( keys[SDLK_c] == SDL_PRESSED )
    {
      player.crouching(1);
    } else {
      player.crouching(0);
    }
    if ( keys[SDLK_LEFT] == SDL_PRESSED ) {
      player.rot(2,utime);
    }
    if ( keys[SDLK_RIGHT] == SDL_PRESSED ) {
      player.rot(-2,utime);
    }

    if ( keys[SDLK_w] == SDL_PRESSED ) {
//      CVector3D pos(player2.xpos,player2.ypos,player2.zpos);
//      CVector3D vel(sin(player2.yrot*piover180)*-0.02*utime,0,cos(player2.yrot*piover180)*-0.02*utime);
//      pos=GetPosition(pos,vel);
//      player2.xpos=pos.x;player2.ypos=pos.y;player2.zpos=pos.z;
      player2.move(-0.02,utime);
      player2.running(1);
    }
    if ( keys[SDLK_s] == SDL_PRESSED ) {
//      CVector3D pos(player2.xpos,player2.ypos,player2.zpos);
//      CVector3D vel(sin(player2.yrot*piover180)*0.02*utime,0,cos(player2.yrot*piover180)*0.02*utime);
//      pos=GetPosition(pos,vel);
//      player2.xpos=pos.x;player2.ypos=pos.y;player2.zpos=pos.z;
      player2.move( 0.02,utime);
      player2.running(1);
    }
/*
    if ( keys[SDLK_w] == SDL_PRESSED ) {
      player2.move(-0.02,utime);
      player2.running(1);
    }
    if ( keys[SDLK_s] == SDL_PRESSED ) {
      player2.move(0.02,utime);
      player2.running(1);
    }
*/
    if( (keys[SDLK_s] == keys[SDLK_w]) )
    {
      player2.running(0);
    }
    if ( keys[SDLK_a] == SDL_PRESSED ) {
      player2.rot(2,utime);
    }
    if ( keys[SDLK_d] == SDL_PRESSED ) {
      player2.rot(-2,utime);
    }

    {
      CVector3D pos(player.xpos,player.ypos,player.zpos);
      CVector3D vel(0,-0.3,0);
      pos=GetPosition(pos,vel);
      player.xpos=pos.x;player.ypos=pos.y;player.zpos=pos.z;
    }

  }

  CLog::addLine("Main loop has ended\n");
  CLog::addLine("cleaning up...\n");
//  cleanup();
  CLog::terminateLog();

  return EXIT_SUCCESS;
}

