//HW03_02_3
//HW03 2번 test3

//좌클릭으로 rotate
//우클릭으로 translate
//Z,X 키로 scale
//화살표로 카메라 시점 이동 (원래는 관잘자 시점 이동이었음 )

#include <math.h>
#include <stdio.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>

typedef float vec3_t[3];
vec3_t rot = {0., 0., 0.};
vec3_t eye = {0., 0., -50.};
vec3_t center = {0., 0., 0.};
vec3_t trans = {0., 0., 0.};
vec3_t scale = {0.3, 0.3, 0.3};
//vec3_t vpn = {0., 0., 0.};

float size = 20;
float theta = .0;
float thetaDelta = .125;
float eyeDelta = .125;
//float scale = 0.3;
float scaleData = 1.125;
float R = 0;
float G = 0;
float B = 0;
int i, j;
int mouseX = 0;
int mouseY = 0;
int mouseState = 0;
int mouseButton = 0;
int projection = 0;
int depthOn = 0;
int fillOn = 1;
int windowWidth, windowHeight;
float height = 0.01;
float antiheight = 5;
float antitheta = .0;
float antithetaDelta = 0.125;
float vpn = 40;
float r=0.05;

GLUquadricObj *c = NULL;

void myDisplay()
{
    glClearColor(R,G,B,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(!projection)//eye는 관찰자의 눈, center은 카메라가 바라보는 방향.
        gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);

    glLineWidth(5);
    //x y z축
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1000.0,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,1000.0,0.0);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,1000.0);
    glEnd();

    glRotatef(rot[0], 1.0f, 0.0f, 0.0f);
    glRotatef(rot[1], 0.0f, 1.0f, 0.0f);
    glRotatef(rot[2], 0.0f, 0.0f, 1.0f);

    glTranslatef(trans[0], 0.0f, 0.0f);
    glTranslatef(0.0f, trans[1], 0.0f);
    glTranslatef(1.0f, 0.0f, trans[2]);

    glScalef(scale[0], scale[1], scale[2]);

    glPushMatrix();//이전 상태 저장
    glTranslatef(0,0,0.1);
    glScalef(1,1,1);
    glColor3f(1.0, 0.0, 0.0);
    if(fillOn) glutSolidCube(60);
    glColor3f(0,0,0);
    glutWireCube(60);
    glPopMatrix();//t,r,s한것 보여주기.

    glFlush();
    glutSwapBuffers();
}





void myLookAt(int key){
   if (key == GLUT_KEY_UP) eye[2]-=3;//Problem02-2 camera moving closer
   else if(key==GLUT_KEY_DOWN) eye[2] +=3;//Problem02-2 camera moving closer
   else if(key==GLUT_KEY_LEFT) eye[0] -=3;//Problem02-2 camera moving sideways
   else if(key==GLUT_KEY_RIGHT) eye[0] +=3;//Problem02-2 camera moving sideways
}

void myResize(int width, int height){
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if(projection){
      glOrtho(-size*-1.75, size*1.75,-size,size,-size*2,size*2);
      eye[2]=0;
   }else{
      gluPerspective(60.,(float)width/height,.1,100.);
      eye[2]=38;
      myLookAt(0);
   }
   glEnable(GL_DEPTH_TEST);
   windowWidth = width;
   windowHeight = height;
}

void myKeyboard(unsigned char key, int x, int y){
    switch(key){
    case 'a'://Problem02-1 axis moving
        //trans[0]+=1;//x axis moving
        //trans[1]+=1;//y axis moving
        trans[2]+=1;//z axis moving
        break;
    case 'b'://Problem02-1 axis rotation
        rot[0]+=1;//x axis rotation
        //rot[1]+=1;//y axis rotation
        //rot[2]-=1;//z axis rotation
        break;
    case 'c'://Problem02-1 axis scaling
        //scale[0]+=0.01;//x axis scaling
        //scale[1]+=0.01;//y axis scaling
        scale[2]+=0.01;//z axis scaling
        break;
    case 'e'://Problem02-2 VPN fixed and move camera
        eye[0] -= 1;
        center[0] -= 1;
        break;
    case 'd':
        depthOn = !depthOn;
        if(depthOn) glEnable(GL_DEPTH_TEST);
        else glDisable(GL_DEPTH_TEST);
        break;
    case 27:
        exit(1);
        break;
    }
    glutPostRedisplay();
}

        //vpn[0] = center[0]-eye[0];
        //vpn[2] = center[2]-eye[2];

void mySKeyboard(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        break;
        case GLUT_KEY_DOWN:
        break;
        case GLUT_KEY_LEFT:
        break;
        case GLUT_KEY_RIGHT:
        break;
        default: return;
    }
    myLookAt(key);
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    srand((unsigned int)time (0));
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Test_OpenGL_1114");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myResize);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(mySKeyboard);
    glutMainLoop();
    return 0;
}
