#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <cmath>

using namespace std;

void init()
{
 glOrtho(-10, 10, -10, 10, -10, 10);
}

void func1()
{
 glClearColor(1, 1, 1, 0);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0, 0, 0);
 glPointSize(3);
 glBegin(GL_POINTS);
 for (double x = 0; x <= 7; x += 0.01) {
  glVertex2f(x, (double) sqrt(4*x));
  glVertex2f(x, -(double) sqrt(4*x));
 }
 glEnd();
 glFlush();
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitWindowPosition(50, 50);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Parabola");
 init();
 glutDisplayFunc(func1);
 glutMainLoop();

 return 0;
}
