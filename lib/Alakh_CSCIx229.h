#ifndef CSCIx229
#define CSCIx229

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

// GLEW _MUST_ be included first
#ifdef USEGLEW
#include <GL/glew.h>
#endif
//  Get all GL prototypes
#define GL_GLEXT_PROTOTYPES
//  Select SDL, SDL2, GLFW or GLUT
#if defined(SDL2)
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#elif defined(SDL)
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#elif defined(GLFW)
#include <GLFW/glfw3.h>
#elif defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//  Make sure GLU and GL are included
#ifdef __APPLE__
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
// Tell Xcode IDE to not gripe about OpenGL deprecation
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#else
#include <GL/glu.h>
#include <GL/gl.h>
#endif
//  Default resolution
//  For Retina displays compile with -DRES=2
#ifndef RES
#define RES 1
#endif

//  cos and sin in degrees
#define Cos(th) cos(3.14159265/180*(th))
#define Sin(th) sin(3.14159265/180*(th))

#ifdef __cplusplus
extern "C" {
#endif

//Standard Library (Vlakkes)
void Print(const char* format , ...);
void Fatal(const char* format , ...);
unsigned int LoadTexBMP(const char* file);
void Project(double fov,double asp,double dim);
void ErrCheck(const char* where);
int  LoadOBJ(const char* file);

//Shapes Library (Alakh)
void vertex(double th, double ph, 
            double r, double g, double b);

void cone(double x, double y, double z,
          double x_angle, double y_angle, double z_angle,
          double width, double height, double length,
          double r, double g, double b);

void ellipse(double x, double y, double z, 
             double x_angle, double y_angle, double z_angle,
             double x_rad, double y_rad, double z_rad, 
             double r, double g, double b);

//  precondition: x2>x1; z2>z1; x2&z2 nonnegative
void partitioned_square(double x_1, double z_1, double x_2, double z_2, double y,
                        double r, double g, double b,
                        int num_partitions_x, int num_partitions_z                         
);

//Objects Library (Alakh)
void penguino(double x, double y, double z, 
                     double x_rot, double y_rot, double z_rot, 
                     double x_scale, double y_scale, double z_scale,
                     unsigned int penguin_texts[], int texMode);

#ifdef __cplusplus
}
#endif

#endif
