//https://community.khronos.org/t/midpoint-algorithm-bresenham-drawing-a-parabola/77074
#include <gl\glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void init(void)
{
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Parabola: Midpoint Algorithm");
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(-100.0,100.0,-100.0,100.0);
    glPointSize(1);
}
void setPixel(GLint xCoord, GLint yCoord)
{
    glBegin(GL_POINTS);
    glVertex2i(xCoord, yCoord);
    glEnd();
}

void parabolaPlotPoints(GLint xc, GLint yc){
    setPixel(xc,round(yc));
    setPixel(-(xc),round(yc));
}

void midpoint_parabola(int x0, int y0, int xEnd, int yEnd)
{
    int k;
    float p, xIncrement, yIncrement, x=x0,y=y0, xx, yy;
    //for (k=0;k<=100;k++)
    for (k=x0;k<=0;k++)
    {
        xIncrement=1.0;
        //x+=xIncrement;
        yIncrement=(2*x+1)/100;
        //y+=yIncrement;
        //p=((x+1)*(x+1))-100*(y+0.5); //decision function, y=(1/100)x^2ÀÌ¹Ç·Î
        p=((x+1)*(x+1))/100-(y-0.5);
        xx=x+1;
        yy=y+1;
        if (p<=0)
        {
            x+=xIncrement;
            y+=yIncrement;
            //p=p+(2*x+2)+1;
            //p=p+2*x+1;
            //p=p+2*x+3;
            p=p-(2*x)-1;
            parabolaPlotPoints(xx,yy);
            //setPixel(xx,round(y));
            //setPixel(-(xx),round(y));
        }
        else
        {
            x+=xIncrement;
            y+=yIncrement;
            //p=p+2*x-100;
            //p=p+(2*x)-97;
            //p=p+(2*x + 2)+1-(2*y - 2);
            //p=p+(2*x)+1-(2*y);
            p=p+(2*x)-101;
            //setPixel(xx,round(yy));
            //setPixel(-(xx),round(yy));
            parabolaPlotPoints(xx,yy);
        }
        printf("%f,%f",x,y);
    }
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    midpoint_parabola(-100,100,100,100);
    glFlush();
}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}
