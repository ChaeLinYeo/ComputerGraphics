//HW_03 1번문제 test03 최종임!
//This is Final!!

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


GLdouble v, s, theta, alpa;
float R = 0;
float G = 0;
float B = 0;

const GLdouble pi = 3.14159;
void displayFcn();
void myLookAt(int key);
void myMouse(int btn, int state, int x, int y);

int main(int argc, char** argv){
    glutInitDisplayMode(GLUT_RGB);   //디스플레이 화면 구성
    glutInitWindowSize(500,500);//윈도우 사이즈
    glutInitWindowPosition(0,0);
    glutCreateWindow("Geometric Transformation sequence");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //viewport를 변경하게 되었을 때 일어날 수 있는
    //왜곡현상을 막는데 사용
    glOrtho(-250.0, 250.0, -250.0, 250.0, -200.0, 200.0);
    printf("초속도 v : ");
   scanf("%lf", &v);
   printf("발사각도 theta : ");
   scanf("%lf", &theta);
   printf("스케일상수 s : ");
   scanf("%lf", &s);
   printf("회전상수 alpa : ");
   scanf("%lf", &alpa);
   printf("%lf %lf %lf %lf\n",v,theta,s,alpa);


    glutDisplayFunc(displayFcn);
    glutMainLoop();
    return 0;
}


void displayFcn(){
    glPushMatrix();
    glTranslatef(-200.0, -200.0, -200.0);
    int t;
    glClearColor(R,G,B,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //gluLookAt(10,-30,80, 0.0,0.0,0.0, 0.0,1.0,0.0);

    glutWireCube(5);
    for(t=1; t<20; t++){//10초간 display
        GLdouble tx = v*cos(pi*theta/180)*t;
        GLdouble ty = v*sin(pi*theta/180)*t - 5*t*t;
        //pivot포인트 바뀌는거 업데이트 -> 센트로이드
        glPushMatrix();//이전 상태 저장
        glTranslatef(tx, ty, tx);//translate
        glRotatef(alpa*t, 1.0, 1.0, 0.0);
        glScalef(s*t, s*t, s*t);
        glColor3f(1.0, 0.0, 0.0);
        glutWireCube(5);
        glPopMatrix();//t,r,s한것 보여주기.

    }
    glPopMatrix();
    glFlush();
}
//scale, rotate, transition 기능이 필요하다.
        //translatePolygon(tri_1, 3, v*cos(pi*theta/180), 5-10*t + v*sin(pi*theta/180));//translate
        //rotatePolygon_v2(tri_1, 3, centroidPt);//rotate
        //scalePolygon_v2(tri_1, 3, centroidPt, s, s);//scale
        //wcPt2D*verts의 tri_1 : 삼각형 세 꼭짓점 좌표
        //GLint nVerts의 3 : 삼각형 꼭짓점 갯수
        //GLfloat tx의 v*cos(pi*theta/180) : x좌표
        //GLfloat ty의 5-10*t + v*sin(pi*theta/180) : y좌표
        //GLdouble tx = t*5;
        //GLdouble ty = t*10;//pivot포인트 바뀌는거 업데이트 -> 센트로이드
