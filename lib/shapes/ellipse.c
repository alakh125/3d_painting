//Alakh_CSCIx229 library
//Alakh Patel
#include "../Alakh_CSCIx229.h"

/*  
 *  Draw an ellipse
 *     at (x,y,z)
 *     rotation angles(x_angle, y_angle, z_angle)
 *     radii (x_rad,y_rad,z_rad)
 *     color (r,g,b)
 */
void ellipse(
                    double x, double y, double z, 
                    double x_angle, double y_angle, double z_angle,
                    double x_rad, double y_rad, double z_rad, 
                    double r, double g, double b) {
   const int d=15;

  //  Save transformation
  glPushMatrix();
  //  Offset and scale
  glTranslated(x,y,z);
  glRotated(x_angle,1,0,0);  
  glRotated(y_angle,0,1,0);  
  glRotated(z_angle,0,0,1);  
  glScaled(x_rad,y_rad,z_rad);
  
  //  Latitude bands
  for (int ph=-90;ph<90;ph+=d)
  {
    glBegin(GL_QUAD_STRIP);
    for (int th=0;th<=360;th+=d)
    {
      glTexCoord2f(Cos(th), Sin(ph));
      glNormal3f(Sin(th),Sin(ph),Cos(th));
      vertex(th,ph,r,g,b);
      vertex(th,ph+d,r,g,b);
    }
    glEnd();
  }
  //undo transformations`
  glPopMatrix();
}