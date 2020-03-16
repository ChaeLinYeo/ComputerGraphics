#include <GL/glut.h>
#include <stdlib.h>
#include "RgbImage.h"

GLfloat xRotated, yRotated, zRotated;
GLuint texture[2]; // Will use 2 texture

//Input 2 FileName
void loadTextureFromFile(char *filename, char *filename2){
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    RgbImage theTexMap1(filename);
    RgbImage theTexMap2(filename2);

    glGenTextures(2, texture); // Create The texture

    //First Texture
    glBindTexture(GL_TEXTURE_2D,texture[0]); //Bind texture[0]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap1.GetNumCols(), theTexMap1.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap1.ImageData());

    //Second Texture
    glBindTexture(GL_TEXTURE_2D,texture[1]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap2.GetNumCols(), theTexMap2.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap2.ImageData());

}

void drawScene(void){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_TEXTURE_2D);
   glLoadIdentity();

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   GLfloat lightpos[] = {-1,-1,-1,2};
   glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
   GLfloat ambient[] = {1,1,0,1};
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

   glTranslatef(0.0,0.0,-5);
   glRotatef(yRotated,0,1,0);
   glRotatef(zRotated, 0, 0, 1);

   glBindTexture(GL_TEXTURE_2D, texture[0]);

   glBegin(GL_QUADS);
   //Front Face 여기 조절해서 텍스처 그라데이션같은거 할 수 있음!
      glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0,-1.0f, 1.0f);
      //glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0,-1.0f, 1.0f);
      glTexCoord2f(1.0f,0.0f); glVertex3f(1.0,-1.0f, 1.0f);
      glTexCoord2f(1.0f,1.0f); glVertex3f(1.0,1.0f, 1.0f);
      glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0,1.0f, 1.0f);
    //Back Face
      glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0,-1.0f, -1.0f);
      glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0,1.0f, -1.0f);
      glTexCoord2f(0.0f,1.0f); glVertex3f(1.0,1.0f, -1.0f);
      glTexCoord2f(0.0f,0.0f); glVertex3f(1.0,-1.0f, -1.0f);
    //Top Face
      glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0,1.0f, -1.0f);
      glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0,1.0f, 1.0f);
      glTexCoord2f(1.0f,0.0f); glVertex3f(1.0,1.0f, 1.0f);
      glTexCoord2f(1.0f,1.0f); glVertex3f(1.0,1.0f, -1.0f);
   glEnd();

    // Making cube (3 quads with texture 2)
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        //Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
            //  Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();

    glFlush();
    glDisable(GL_TEXTURE_2D);
}

void resizeWindow(int x, int y)
{
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Angle of view : 60 degrees
    //Near clipping plane distance :0.5
    //Far clipping plane distance : 20.0
    gluPerspective(60.0, (GLdouble)x/(GLdouble)y, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);    //Use the whole window for rendering
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
    case 'a':
        yRotated += 5;
        zRotated += 5;
    default:
        break;
    }
    drawScene();
}

char* filename1 = "C:/Users/x220/Desktop/ComputerGraphics/week09_2/floor.bmp";
char* filename2 = "C:/Users/x220/Desktop/ComputerGraphics/week09_2/grass.bmp";

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Simple Texture");

    loadTextureFromFile(filename1, filename2);

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resizeWindow);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
