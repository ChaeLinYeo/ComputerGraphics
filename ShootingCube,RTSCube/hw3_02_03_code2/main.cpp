//HW03_02_4
//HW03 2�� test1

//��Ŭ������ rotate
//��Ŭ������ translate
//Z,X Ű�� scale
//ȭ��ǥ�� ī�޶� ���� �̵� (������ ������ ���� �̵��̾��� )

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

GLfloat o1_rot = 0.0f; // ������ ������
GLUquadricObj *obj; // ���� �׸��� ���� ��ü ������

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
    if(!projection)//eye�� �������� ��, center�� ī�޶� �ٶ󺸴� ����.
        gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);

    //x y z��
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

    glPushMatrix();//���� ���� ����
    glTranslatef(0,0,0.1);
    glScalef(1,1,1);
    glColor3f(1.0, 0.0, 0.0);
    if(fillOn) glutSolidCube(60);
    glColor3f(0,0,0);glutWireCube(5);
    glutWireCube(60);
    glPopMatrix();//t,r,s�Ѱ� �����ֱ�.


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
    //������ ���� �̵�. 2�� ù��° ī�޶� ������ �̵�, �ι�° ������ �̵�
   if (key == GLUT_KEY_UP) eye[2]-=3;
   else if(key==GLUT_KEY_DOWN) eye[2] +=3;
   else if(key==GLUT_KEY_LEFT) eye[1] -=3;
   else if(key==GLUT_KEY_RIGHT) eye[0] +=3;
    /*
    //ī�޶� ���� �̵�
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
    case 'a'://1�� �� �����̱�. trans[]�� �ٲ㼭 xyz�� ����
        //trans[1]-=1;//x��
        //trans[0]-=1;//z��
        trans[2]-=1;//y��
        break;
    case 'b'://1�� �� ȸ���ϱ�
        //rot[1]-=1;//y��
        rot[0]-=10;//x��
        //rot[2]-=10;//z��
        break;
    case 'c'://1�� �����Ϻ�ȭ
        //scale+=0.01;
        scale-=0.01;
        break;
    case 'e'://2�� ����°, VPN�����ϰ� ī�޶� �̵�
        //vpn[0] = center[0]-eye[0];//x��
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

