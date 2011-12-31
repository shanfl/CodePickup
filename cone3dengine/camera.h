#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"

class CCamera
{
  public:
  CCamera() {dist=0.8;}
  int doit()
  {
    if(hooked)
    {
      if(movewith == 1)
      {
        oldx=x=player->xpos;
        oldy=y=player->ypos;
        oldz=z=player->zpos;
        oldyrot=yrot=player->yrot;

        gluLookAt(x+(cos(lookupdown*0.0174532925f)*dist * sin((yrot) * 0.0174532925f)),y+0.2+(sin(lookupdown*0.0174532925f)*dist),z+(cos(lookupdown*0.0174532925f)*dist * cos((yrot) * 0.0174532925f)),x,y+0.2,z,0,lookupdown>90&&lookupdown<270?-1:1,0);
      } else {
        oldx=x=player->xpos;
        oldz=z=player->zpos;
//        gluLookAt(oldx,0.4,oldz,player->xpos,0.4,player->zpos,0,lookupdown>90&&lookupdown<270?-1:1,1);
      }
    }
  }
  int hook(CPlayer *fella) { player=fella; hooked=1; movewith=1; }

  int hooked;
  int movewith;
  float lookupdown;
  float x,y,z,oldx,oldy,oldz;
  float yrot,oldyrot;
  float dist;

  CPlayer *player;
};

#endif
