//Alakh_CSCIx229 library
//Alakh Patel
#include "../Alakh_CSCIx229.h"

void penguino(double x, double y, double z, 
                     double x_rot, double y_rot, double z_rot, 
                     double x_scale, double y_scale, double z_scale,
                     unsigned int penguin_texts[], int texMode) {
  //TODO: arm positioning - set constant for now.
  int left_init = -75;
  int right_init = 0;
  //save transformations
  glPushMatrix();
  //set penguin scale, rotation, then position
  glTranslated(x,y,z);
  glRotated(x_rot,1,0,0);  
  glRotated(y_rot,0,1,0);  
  glRotated(z_rot,0,0,1);  
  glScaled(x_scale, y_scale, z_scale);
  
  //draw the penguin
  //penguin body
  //mainframe
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV , GL_TEXTURE_ENV_MODE , texMode ? GL_REPLACE:GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,penguin_texts[0]);
  ellipse(0,0.7,0,0,0,0,0.5,0.7,0.5,0.1,0.1,0.1);
  glDisable(GL_TEXTURE_2D);
  //chest
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV , GL_TEXTURE_ENV_MODE , texMode ? GL_REPLACE:GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,penguin_texts[1]);
  ellipse(-0.1,1.0,0.2,0,0,0,0.2,0.2,0.3,1,1,1); //right
  ellipse(0.1,1.0,0.2,0,0,0,0.2,0.2,0.3,1,1,1);  //left
  //stomach
  ellipse(0,0.7,0.2,0,0,0,0.4,0.4,0.4,1,1,1);
  glDisable(GL_TEXTURE_2D);

  //penguin head
  //mainframe
  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV , GL_TEXTURE_ENV_MODE , texMode ? GL_REPLACE:GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D,penguin_texts[0]);
  ellipse(0,1.3,0,0,0,0,0.3,0.5,0.3,0,0,0);
  glDisable(GL_TEXTURE_2D);
  //eyes
  ellipse(-0.075,1.4,0.2,0,0,0,0.1,0.15,0.1,1,1,1); //right
  ellipse(0.075,1.4,0.2,0,0,0,0.1,0.15,0.1,1,1,1); //left
  //pupils
  ellipse(-0.1,1.4,0.3,0,0,0,0.05,0.075,0.05,0,0,0); //right
  ellipse(0.1,1.4,0.3,0,0,0,0.05,0.075,0.05,0,0,0); //left
  //beak 
  cone(0,1.3,0.5,0,0,0,0.1,0.05,0.3,1,1,0);

  //penguin arms
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,penguin_texts[0]);
  ellipse(-0.6,1.2,0.3,45,right_init,45,0.2,0.6,0.2,0,0,0); //right
  ellipse(0.45,1.2,0.3,-45,left_init,90,0.2,0.6,0.2,0,0,0);  //left
  glDisable(GL_TEXTURE_2D);

  //penguin legs
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,penguin_texts[0]);
  ellipse(-0.3,0.1,0.1,45,0,0,0.2,0.4,0.2,0,0,0);
  ellipse(0.35,0.1,0.3,-45,0,0,0.2,0.4,0.2,0,0,0);
  glDisable(GL_TEXTURE_2D);

  //feet
  //right foot
  cone(-0.275,-0.1,0.7,0,-15,0,0.1,0.1,0.4,1,1,0);
  cone(-0.275,-0.1,0.7,0,-30,0,0.1,0.1,0.4,1,1,0);
  cone(-0.275,-0.1,0.7,0,-45,0,0.1,0.1,0.4,1,1,0);
  //left foot
  cone(0.2,-0.125,0.9,0,15,0,0.1,0.1,0.4,1,1,0);
  cone(0.1,-0.125,1,0,30,0,0.1,0.1,0.4,1,1,0);
  cone(0,-0.125,1,0,45,0,0.1,0.1,0.4,1,1,0);
  glPopMatrix();
}
