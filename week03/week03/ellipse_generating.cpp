#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

inline int round (const float a) {return int (a+0.5);}
void setPixel(GLint xCoord, GLint yCoord){
    glBegin (GL_POINTS);
    glVertex2i(xCoord, yCoord);
    glEnd();
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry){
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;
    void ellipsePlotPoints(int, int, int, int);

    ellipsePlotPoints (xCenter, yCenter, x, y);

    p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py){
        x++;
        px += twoRy2;
        if (p < 0)
            p += Ry2 + px;
        else{
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints (xCenter, yCenter, x, y);
    }
    p = round(Ry2 * (x+0.5) * (x+0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
    while (y > 0){
        y--;
        py = twoRx2;
        if (p>0)
            p += Rx2 - py;
        else{
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
}

void ellipsePlotPoints (int xCenter, int yCenter, int x, int y)
{
    setPixel(xCenter + x, yCenter + y);
    setPixel(xCenter - x, yCenter + y);
    setPixel(xCenter + x, yCenter - y);
    setPixel(xCenter - x, yCenter - y);
}

void init (void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
