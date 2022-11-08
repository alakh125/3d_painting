//Alakh_CSCIx229 library
//Alakh Patel
#include "../Alakh_CSCIx229.h"

/*  
 *  Draw a cone 
 *     at (x,y,z)
 *     rotation angles(x_angle, y_angle, z_angle)
 *     radii (x_rad,y_rad,z_rad)
 *     color (r,g,b)
 */
void cone(double x, double y, double z,
                 double x_angle, double y_angle, double z_angle,
                 double width, double height, double length,
                 double r, double g, double b) {
  /*LIGHTING NOTES
   *
   * y angle will affect the cone's direction in the x-z plane. 
   *   -tip of the cone points in the -sin(yangle) in x and -cos(yangle) in z.
   * x angle affects the cone's direction in the y axis.
   *   -tip of the cone points in -sin(xangle) in y
   * 
   * back of the cone sits at x-width, y-height, z-length
   * 
   * in all other directions the suface normal should point outwards from the rotated triangle fan face 
   */
  
  glPushMatrix();
  
  glRotated(x_angle,1,0,0);  
  glRotated(y_angle,0,1,0);  
  glRotated(z_angle,0,0,1);  
  
  glColor3f(r,g,b);
  //TODO: fix triangle fan
  glBegin(GL_TRIANGLE_FAN);
  //set normal for tip of the cone
  glNormal3f(Sin(y_angle),Sin(x_angle),Cos(z_angle));
  glVertex3d(x,y,z);
  
  //fan triangles and set normal on outwards face
  for (int th=0;th<=360;th+=15) {
    glNormal3f(Cos(th), Sin(th), Cos(th));
    glVertex3d(width*Cos(th)+x,height*Sin(th)+y,z-length);
  }

  //TODO: this was one way to try to set the normal for the bottom of the plane and completing the back of the cone...but it isn't quite there yet.
  //draw a circle at the bottom and then make that normal face outwards in the opposite direction of the tip
  //note that circle is already rotated to the proper position
  // glColor3f(0,0,0);
  // float x_circ = 0;
  // float y_circ = 0; 
  // for (int th=0;th<=360;th+=15)
  // {
  //   glNormal3f(-Sin(y_angle),-Sin(x_angle),-Cos(z_angle));
  //   x_circ+=sin(th)*width;
  //   y_circ+=cos(th)*height;
  //   glVertex3f(x_circ-width,y_circ-height,z-length);
  // }

  glEnd();
  glPopMatrix();
}