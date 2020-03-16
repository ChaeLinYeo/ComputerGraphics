#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
GLsizei winWidth =500, winHeight=500;
void init(void){
    glClearColor(0,0,0,0);
    glColor3f(1,1,0);
    glEnable(GL_DEPTH_TEST);
}
GLfloat verts[][3]={//x,y,z
{-1,-1,1},{-1,1,1},{1,1,1},
{1,-1,1},{-1,-1,-1},{-1,1,-1},
{1,1,-1},{1,-1,-1},};
GLfloat colors[][3]={
{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,1,1},{1,0,1},
};
void polygon(int a, int b, int c, int d){
    glColor3fv(colors[a]);
    glBegin(GL_POLYGON);
        glVertex3fv(verts[a]);
        glVertex3fv(verts[b]);
        glVertex3fv(verts[c]);
        glVertex3fv(verts[d]);
    glEnd();
}

void createCube(){
    /*
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(3,0,4,7);
    polygon(4,5,6,7);
    polygon(1,2,6,5);
    polygon(5,4,0,1);
    */
    polygon(0,3,2,5);//¿ÞÂÊ¿·¸é.»¡°£»ö
    polygon(2,3,7,5);//¿À¸¥ÂÊ¿·¸é. ÃÊ·Ï»ö
    //polygon(3,0,4,7);//¹Ù´Ú. ÆÄ¶õ»ö
    //polygon(4,5,6,7);

    //polygon(1,2,6,5);//À­¸é. ³ë¶õ»ö

    //polygon(5,4,0,1);
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-5,5);
}

void display(){
    float x,y,theta;

    theta = 1.0;
    x=2*cos(theta);
    y=2*sin(theta);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,y,2,-1,0,0,0,1,0);

    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
         glVertex3f(10,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
         glVertex3f(0,10,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
         glVertex3f(0,0,10);
    glEnd();

    createCube();


    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("cube");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
