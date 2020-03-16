#include <math.h>
#include <stdio.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <stdlib.h>

typedef float vec3_t[3];
vec3_t rot = {0., 0., 0.};
vec3_t eye = {0., 0., 100.};
float count = 100;
int fillOn = 1;

void Reshape(int w, int h){
    float ratio = 1.0f;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 10, 100);
    glMatrixMode(GL_MODELVIEW);
}
void Draw(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, eye[2],
              0, 0, -10,
              0, 1.0f, 0);
    glRotatef(rot[0], 1,0, 0);
    glColor3f(1.0,0,0);
    glutSolidCube(10);
    glColor3f(0,0,0);
    glutWireCube(10);
    rot[0] += 0.05;
    count -=0.05;
    eye[2]-=0.05;
    glutSwapBuffers();
}

void myDisplay(){
    for(;;){
        Draw();
        if(count < 20) break;
    }
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(Reshape);
  // 이벤트 프로세싱 사이클 진입
    glutMainLoop();
    return 0;
}
