//Alakh_CSCIx229 library
//Alakh Patel
#include "../Alakh_CSCIx229.h"

/*
 * Creates a ground plane made up of many partitions of squares
 * r,g,b is color of plane
 * x_n/z_n/y set plane corners and y-level
 *   x2>x1;z2>z1;x2&z2>=0
 * allows you to set number of partitions
 */
void partitioned_square(double x_1, double z_1, double x_2, double z_2, double y,
                        double r, double g, double b,
                        int num_partitions_x, int num_partitions_z                )
{
  glPushMatrix();

  double x_incr = (x_2 - x_1)/num_partitions_x;
  double z_incr = (z_2 - z_1)/num_partitions_z;
  
  for(double x = x_1; x < x_2; x+=x_incr) {
    for(double z = x_1; z < z_2; z+=z_incr) {
      //set color
      glColor3f(r,g,b);
  
      //draw first triangle
      glBegin(GL_TRIANGLES);
      glNormal3f(0,1,0);
      glTexCoord2f(x,z);        glVertex3d(x,y,z);
      glTexCoord2f(x+x_incr,z); glVertex3d(x+x_incr,y,z);
      glTexCoord2f(x,z+z_incr); glVertex3d(x,y,z+z_incr);
      glEnd();
  
      //draw second triangle
      glBegin(GL_TRIANGLES);
      glNormal3f(0,1,0);
      glTexCoord2f(x+x_incr,z+z_incr); glVertex3d(x+x_incr,y,z+z_incr);
      glTexCoord2f(x+x_incr,z);        glVertex3d(x+x_incr,y,z);
      glTexCoord2f(x,z+z_incr);        glVertex3d(x,y,z+z_incr);
      glEnd();
    }
  }

  glPopMatrix();
}