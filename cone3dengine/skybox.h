#ifndef __SKYBOX_H__
#define __SKYBOX_H__

#include "texture.h"

class CSkyBox
{
  public:
  CTexture up,dn,lf,rt,bk,ft;
  void build(char *dir);
  void draw(float x, float y);
};

#endif
