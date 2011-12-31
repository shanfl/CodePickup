#include "player.h"

const float piover180 = 0.0174532925f;

int frames[21][2] =
{
 {0,39}, {40,45}, {46,53}, {54,57}, {58,61}, {62,65},
 {66,71}, {72,83}, {84,94}, {95,111}, {112,122},
 {123,134}, {135,153}, {154,159}, {160,168}, {169,172},
 {173,177}, {178,183}, {184,189}, {190,197}, {40,45}
};

int CPlayer::move(float amount,float utime)
{
  xpos += sin(yrot*piover180)*amount*utime;
  zpos += cos(yrot*piover180)*amount*utime;
}

int CPlayer::jumpup()
{
//  if(model.GetFrame() < frames[PLAYER_JUMP][0] || model.GetFrame() > frames[PLAYER_JUMP][1])
  if(jump==0) jump=1;
}

int CPlayer::init(char *dir, char *mdl, char *mdlt, char *wep, char *wept, float x, float y, float z)
{
  char file1[255],file2[255];
  sprintf(file1,"%s/%s",dir,mdl);
  sprintf(file2,"%s/%s",dir,mdlt);
  model.LoadModel(file1,file2);
  sprintf(file1,"%s/%s",dir,wep);
  sprintf(file2,"%s/%s",dir,wept);
  model.LoadWeapon(file1,file2);

  set(x,y,z);
  model.SetFrame(0);
  model.Animation(0,39);
  return 0;
}

int CPlayer::draw()
{
  int rv;
  glPushMatrix();
  glTranslatef(xpos,ypos,zpos);
  glRotatef(yrot+90,0,1,0);
  if(transform)
  {
    rv=model.Animate2(0,0,0,f1,f2,80);
    if(rv==2)
    {
      transform=0;
      model.SetFrame(f2);
      if(jump==2) jump=3;
      if(attack==2) attack=3;
      if(pain==2)  pain=3;
      if(pain==12) pain=13;
      if(pain==22) pain=23;
    }
    rv=0;
  } else {
    rv=model.Animate(0,0,0,80);
  }
  if(rv==2 || rv==3 || rv==4)
  {
    if(crouch==0)
    {
      if(rv==4 && jump!=0) jump=0;
      if(rv==4 && attack!=0) attack=0;
      if(rv==4 && pain!=0) pain=0;
      if(attack==1 && (model.GetFrame() < frames[PLAYER_ATTACK][0] || model.GetFrame() > frames[PLAYER_ATTACK][1]))
      {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_ATTACK][0],frames[PLAYER_ATTACK][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_ATTACK][0];
          transform=1;
          attack=2;
        }
      } else if(pain==1 && (model.GetFrame() < frames[PLAYER_PAIN1][0] || model.GetFrame() > frames[PLAYER_PAIN1][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_PAIN1][0],frames[PLAYER_PAIN1][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_PAIN1][0];
          transform=1;
          pain=2;
        }
      } else if(pain==11 && (model.GetFrame() < frames[PLAYER_PAIN2][0] || model.GetFrame() > frames[PLAYER_PAIN2][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_PAIN2][0],frames[PLAYER_PAIN2][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_PAIN2][0];
          transform=1;
          pain=12;
        }
      } else if(pain==21 && (model.GetFrame() < frames[PLAYER_PAIN3][0] || model.GetFrame() > frames[PLAYER_PAIN3][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_PAIN3][0],frames[PLAYER_PAIN3][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_PAIN3][0];
          transform=1;
          pain=22;
        }
      } else if(jump==1 && (model.GetFrame() < frames[PLAYER_JUMP][0] || model.GetFrame() > frames[PLAYER_JUMP][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_JUMP][0],frames[PLAYER_JUMP][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_JUMP][0];
          transform=1;
          jump=2;
        }
      } else if(run==1 && jump==0 && taunt==0 && attack==0 && pain==0 && death==0 && (model.GetFrame() < frames[PLAYER_RUN][0] || model.GetFrame() > frames[PLAYER_RUN][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_RUN][0],frames[PLAYER_RUN][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_RUN][0];
          transform=1;
        }
      } else if(run==0 && jump==0 && taunt==0 && attack==0 && pain==0 && death==0 && (model.GetFrame() < frames[PLAYER_STAND][0] || model.GetFrame() > frames[PLAYER_STAND][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_STAND][0],frames[PLAYER_STAND][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_STAND][0];
          transform=1;
        }
      }
    } else {
      if(rv==4 && jump==3) jump=0;
      if(rv==4 && attack==3) attack=0;
      if(rv==4 && pain>=3) pain=0;
      if(attack==1 && (model.GetFrame() < frames[PLAYER_CROUCH_ATTACK][0] || model.GetFrame() > frames[PLAYER_CROUCH_ATTACK][1]))
      {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_CROUCH_ATTACK][0],frames[PLAYER_CROUCH_ATTACK][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_CROUCH_ATTACK][0];
          transform=1;
          attack=2;
        }
      } else if(pain==1 && (model.GetFrame() < frames[PLAYER_CROUCH_PAIN][0] || model.GetFrame() > frames[PLAYER_CROUCH_PAIN][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_CROUCH_PAIN][0],frames[PLAYER_CROUCH_PAIN][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_CROUCH_PAIN][0];
          transform=1;
          pain=2;
        }
      } else if(jump==1 && (model.GetFrame() < frames[PLAYER_JUMP][0] || model.GetFrame() > frames[PLAYER_JUMP][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_JUMP][0],frames[PLAYER_JUMP][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_JUMP][0];
          transform=1;
         jump=2;
        }
      } else if(run==1 && jump==0 && taunt==0 && attack==0 && pain==0 && death==0 && (model.GetFrame() < frames[PLAYER_CROUCH_WALK][0] || model.GetFrame() > frames[PLAYER_CROUCH_WALK][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_CROUCH_WALK][0],frames[PLAYER_CROUCH_WALK][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_CROUCH_WALK][0];
          transform=1;
        }
      } else if(run==0 && jump==0 && taunt==0 && attack==0 && pain==0 && death==0 && (model.GetFrame() < frames[PLAYER_CROUCH_STAND][0] || model.GetFrame() > frames[PLAYER_CROUCH_STAND][1])) {
        if(transform==0)
        {
          model.Animation(frames[PLAYER_CROUCH_STAND][0],frames[PLAYER_CROUCH_STAND][1]);
          f1=model.GetFrame();
          f2=frames[PLAYER_CROUCH_STAND][0];
          transform=1;
        }
      }

    }
  }
  glPopMatrix();
}


