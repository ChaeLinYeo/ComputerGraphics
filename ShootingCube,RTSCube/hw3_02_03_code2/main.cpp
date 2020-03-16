//HW03_02_4
//HW03 2번 test1

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
#include <iostream>

typedef float vec3_t[3];
vec3_t rot = {0., 0., 0.};
vec3_t eye = {0., 0., -50.};
vec3_t center = {0., 0., 0.,};
vec3_t trans = {0., 0., 0.,};
//vec3_t vpn = {0., 0., 0.};

GLfloat o1_rot = 0.0f; // 지구의 자전각
GLUquadricObj *obj; // 구를 그리기 위한 객체 포인터

float rotate = 0.0f;

float size = 20;
float theta = .0;
float thetaDelta = .125;
float eyeDelta = .125;
float scale = 0.3;
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
float vpn = 30;
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
    glRotatef(rot[2], 1.0f, 0.0f, 1.0f);
    //glScalef(scale, scale, scale);
    //glRotatef(-80., 1., 0., 0.);

    glTranslatef(trans[1], 0.0f, 0.0f);
    glTranslatef(0.0f, trans[2], 0.0f);
    glTranslatef(1.0f, 0.0f, trans[0]);
    //glTranslatef(scale, scale, scale);
    //glTranslatef(1., 0., 0.);

    glScalef(scale, scale, scale);

    glPushMatrix();//이전 상태 저장
    glTranslatef(0,0,0.1);
    glScalef(1,1,1);
    glColor3f(1.0, 0.0, 0.0);
    if(fillOn) glutSolidCube(60);
    glColor3f(0,0,0);glutWireCube(5);
    glutWireCube(60);
    glPopMatrix();//t,r,s한것 보여주기.


    glFlush();
    glutSwapBuffers();
}

void xaxisrot(){
    for(int i=0; i<20; i++){
        glRotatef(rot[0], 1.0f, 0.0f, 0.0f);
        rot[0]+=0.005;
    }
}

void myLookAt(int key){
    //관찰자 시점 이동. 2번 첫번째 카메라 옆으로 이동, 두번째 가까이 이동
   if (key == GLUT_KEY_UP) eye[2]-=3;
   else if(key==GLUT_KEY_DOWN) eye[2] +=3;
   else if(key==GLUT_KEY_LEFT) eye[1] -=3;
   else if(key==GLUT_KEY_RIGHT) eye[0] +=3;
    /*
    //카메라 시점 이동
    if (key == GLUT_KEY_UP) center[2]-=3;
   else if(key==GLUT_KEY_DOWN) center[2] +=3;
   else if(key==GLUT_KEY_LEFT) center[1] -=3;
   else if(key==GLUT_KEY_RIGHT) center[0] +=3;
    */
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
    case'f':
        fillOn = !fillOn;
    case 'p':
        projection = !projection;
        myResize(windowWidth, windowHeight);
        break;
    case 'd':
        depthOn = !depthOn;
        if(depthOn) glEnable(GL_DEPTH_TEST);
        else glDisable(GL_DEPTH_TEST);
        break;
    case 'l':
        R = rand() / 32767.0;
        G = rand() / 32767.0;
        B = rand() / 32767.0;

    case 'n':
        R =0; G = 0; B= 0; break;
    case 'q':
        exit(1);
        break;
    case 27:
        exit(1);
        break;
    case 'a'://1번 축 움직이기. trans[]값 바꿔서 xyz축 조정
        //trans[1]-=1;//x축
        //trans[0]-=1;//z축
        trans[2]-=1;//y축
        break;
    case 'b'://1번 축 회전하기
        //rot[1]-=1;//y축
        rot[0]-=10;//x축
        //rot[2]-=10;//z축
        break;
    case 'c'://1번 스케일변화
        //scale+=0.01;
        scale-=0.01;
        break;
    case 'e'://2번 세번째, VPN고정하고 카메라 이동
        //vpn[0] = center[0]-eye[0];//x축
        //vpn[2] = center[2]-eye[2];
        eye[0]=vpn*cos(r)+center[0];
        eye[2]=vpn*sin(r)+center[2];
        r+=0.5;
        break;
    }
    glutPostRedisplay();
}


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


void Reshape(int w, int h)
{
    if(h == 0)
        h = 1;
    float ratio = 1.0f * w/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1f, 100);
    glMatrixMode(GL_MODELVIEW);
}
void draw_cube()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2],
              0, 0, -10,
              0, 1.0f, 0);
    glRotatef(rotate, 1, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(10);
    rotate += 0.05;
    for(int i=0; i<4; i++){
        eye[2]+=0.0005;
    }
    glutSwapBuffers();
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
    //glutDisplayFunc(xaxisrot);
    //glutDisplayFunc(myDisplay);
    //glutReshapeFunc(myResize);
    //glutKeyboardFunc(myKeyboard);
    //glutSpecialFunc(mySKeyboard);
    glutDisplayFunc(draw_cube);
    glutReshapeFunc(Reshape);
    glutIdleFunc(draw_cube);

    glutMainLoop();
    return 0;
}

