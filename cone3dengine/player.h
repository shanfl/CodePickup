#ifndef __PLAYER_H__
#define __PLAYER_H__

#define PLAYER_STAND 0
#define PLAYER_RUN 1
#define PLAYER_ATTACK 2
#define PLAYER_PAIN1 3
#define PLAYER_PAIN2 4
#define PLAYER_PAIN3 5
#define PLAYER_JUMP 6
#define PLAYER_FLIPOFF 7
#define PLAYER_SALUTE 8
#define PLAYER_TAUNT 9
#define PLAYER_WAVE 10
#define PLAYER_POINT 11
#define PLAYER_CROUCH_STAND 12
#define PLAYER_CROUCH_WALK 13
#define PLAYER_CROUCH_ATTACK 14
#define PLAYER_CROUCH_PAIN 15
#define PLAYER_CROUCH_DEATH 16
#define PLAYER_DEATH1 17
#define PLAYER_DEATH2 18
#define PLAYER_DEATH3 19

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "md2.h"

class CPlayer
{
  public:
  CPlayer() {jump=0;run=0;crouch=0;taunt=0;attack=0;pain=0;death=0;}
  int init(char *dir, char *model, char *modelt, char *wep, char *wept, float x, float y, float z);
  int setAction(int action);
  int draw();
  void set(float x, float y, float z) {xpos=x;ypos=y;zpos=z;};
  int running(int nr) { run=nr; }
  int crouching(int nr) { crouch=nr; }
  int jumpup();
  int attac() { attack=1; }
  int ouch(int nr) { pain=((nr-1)*10)+1; }
  int rot(float amount,float tt) { yrot += amount*tt; if(yrot>360) yrot-=360; if(yrot<0) yrot+=360;}
  int move(float amount,float utime);

  int jump,run,crouch,taunt,attack,pain,death,f1,f2,transform;
  float xpos, ypos, zpos, yrot;
  CModelMD2 model;
};

#endif

