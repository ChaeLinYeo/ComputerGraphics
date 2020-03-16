//HW_03 1������ test03 ������!
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
    glutInitDisplayMode(GLUT_RGB);   //���÷��� ȭ�� ����
    glutInitWindowSize(500,500);//������ ������
    glutInitWindowPosition(0,0);
    glutCreateWindow("Geometric Transformation sequence");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //viewport�� �����ϰ� �Ǿ��� �� �Ͼ �� �ִ�
    //�ְ������� ���µ� ���
    glOrtho(-250.0, 250.0, -250.0, 250.0, -200.0, 200.0);
    printf("�ʼӵ� v : ");
   scanf("%lf", &v);
   printf("�߻簢�� theta : ");
   scanf("%lf", &theta);
   printf("�����ϻ�� s : ");
   scanf("%lf", &s);
   printf("ȸ����� alpa : ");
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
    for(t=1; t<20; t++){//10�ʰ� display
        GLdouble tx = v*cos(pi*theta/180)*t;
        GLdouble ty = v*sin(pi*theta/180)*t - 5*t*t;
        //pivot����Ʈ �ٲ�°� ������Ʈ -> ��Ʈ���̵�
        glPushMatrix();//���� ���� ����
        glTranslatef(tx, ty, tx);//translate
        glRotatef(alpa*t, 1.0, 1.0, 0.0);
        glScalef(s*t, s*t, s*t);
        glColor3f(1.0, 0.0, 0.0);
        glutWireCube(5);
        glPopMatrix();//t,r,s�Ѱ� �����ֱ�.

    }
    glPopMatrix();
    glFlush();
}
//scale, rotate, transition ����� �ʿ��ϴ�.
        //translatePolygon(tri_1, 3, v*cos(pi*theta/180), 5-10*t + v*sin(pi*theta/180));//translate
        //rotatePolygon_v2(tri_1, 3, centroidPt);//rotate
        //scalePolygon_v2(tri_1, 3, centroidPt, s, s);//scale
        //wcPt2D*verts�� tri_1 : �ﰢ�� �� ������ ��ǥ
        //GLint nVerts�� 3 : �ﰢ�� ������ ����
        //GLfloat tx�� v*cos(pi*theta/180) : x��ǥ
        //GLfloat ty�� 5-10*t + v*sin(pi*theta/180) : y��ǥ
        //GLdouble tx = t*5;
        //GLdouble ty = t*10;//pivot����Ʈ �ٲ�°� ������Ʈ -> ��Ʈ���̵�
