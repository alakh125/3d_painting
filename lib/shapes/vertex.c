//Alakh_CSCIx229 library
//Alakh Patel
#include "../Alakh_CSCIx229.h"

/*  modified from ex8, used in sphere2
 *  Draw vertex in polar coordinates
 *  color (r,g,b)
 */
void vertex(double th,double ph, double r, double g, double b)
{
  //  glColor3f(Cos(th)*Cos(th) , Sin(ph)*Sin(ph) , Sin(th)*Sin(th));
  glColor3f(r,g,b);
  glVertex3d(Sin(th)*Cos(ph) , Sin(ph) , Cos(th)*Cos(ph));
}
