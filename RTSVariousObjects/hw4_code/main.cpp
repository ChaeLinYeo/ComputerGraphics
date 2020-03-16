#include <GL/glut.h>
#include <stdlib.h>
#include "RgbImage.h"
#include "math.h"
GLfloat xRotated_1, yRotated_1, zRotated_1;
GLfloat xRotated_2, yRotated_2, zRotated_2;
GLfloat xRotated_3, yRotated_3, zRotated_3;
GLfloat xRotated_4, yRotated_4, zRotated_4;
GLfloat xRotated_5, yRotated_5, zRotated_5;
GLuint texture[15];
GLfloat obj_size =0.5f;
GLfloat obj_size0 = 0.0f;
GLfloat a = 0.5;
GLfloat b = 1/(2*(1 + sqrt(5)) / 2);
#define X .525731112119133606
#define Z .850650808352039932

#define DEF_D 5
#define PI 3.1415926535898
/*  Macro for sin & cos in degrees */
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))

//Input 2 FileName
void loadTextureFromFile(char *filename1, char *filename2, char *filename3, char *filename4, char *filename5, char *filename6,
                         char *filename7,char *filename8,char *filename9,char *filename10,char *filename11,char *filename12,
                         char *filename13,char *filename14){
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    RgbImage theTexMap1(filename1);
    RgbImage theTexMap2(filename2);
    RgbImage theTexMap3(filename3);
    RgbImage theTexMap4(filename4);
    RgbImage theTexMap5(filename5);
    RgbImage theTexMap6(filename6);
    RgbImage theTexMap7(filename7);
    RgbImage theTexMap8(filename8);
    RgbImage theTexMap9(filename9);
    RgbImage theTexMap10(filename10);
    RgbImage theTexMap11(filename11);
    RgbImage theTexMap12(filename12);
    RgbImage theTexMap13(filename13);
    RgbImage theTexMap14(filename14);

    glGenTextures(15, texture); // Create The texture

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
    //3 Texture
    glBindTexture(GL_TEXTURE_2D,texture[2]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap3.GetNumCols(), theTexMap3.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap3.ImageData());
    //4 Texture
    glBindTexture(GL_TEXTURE_2D,texture[3]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap4.GetNumCols(), theTexMap4.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap4.ImageData());
    //5 Texture
    glBindTexture(GL_TEXTURE_2D,texture[4]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap5.GetNumCols(), theTexMap5.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap5.ImageData());
    //6 Texture
    glBindTexture(GL_TEXTURE_2D,texture[5]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap6.GetNumCols(), theTexMap6.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap6.ImageData());
    //7 Texture
    glBindTexture(GL_TEXTURE_2D,texture[6]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap7.GetNumCols(), theTexMap7.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap7.ImageData());
    //8 Texture
    glBindTexture(GL_TEXTURE_2D,texture[7]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap8.GetNumCols(), theTexMap8.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap8.ImageData());
    //9 Texture
    glBindTexture(GL_TEXTURE_2D,texture[8]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap9.GetNumCols(), theTexMap9.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap9.ImageData());
    //10 Texture
    glBindTexture(GL_TEXTURE_2D,texture[9]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap10.GetNumCols(), theTexMap10.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap10.ImageData());
    //11 Texture
    glBindTexture(GL_TEXTURE_2D,texture[10]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap11.GetNumCols(), theTexMap11.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap11.ImageData());
    //12 Texture
    glBindTexture(GL_TEXTURE_2D,texture[11]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap12.GetNumCols(), theTexMap12.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap12.ImageData());
    //13 Texture
    glBindTexture(GL_TEXTURE_2D,texture[12]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap13.GetNumCols(), theTexMap13.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap13.ImageData());
    //14 Texture
    glBindTexture(GL_TEXTURE_2D,texture[13]);  //Bind texture[1]
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap14.GetNumCols(), theTexMap14.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap14.ImageData());
}


void vertex(double th2,double ph2)
{
   double x = Sin(th2)*Cos(ph2);
   double y = Cos(th2)*Cos(ph2);
   double z =          Sin(ph2);
   glVertex3d(x,y,z);
}



void drawScene(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightpos[] = {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    //GLfloat ambient[] = {0.5, 0.5, 0.5, 1.0 };
    //glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    //GLfloat specular[] = {1, 1, 1, 1 };
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    GLfloat diffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    //Cube
    glPushMatrix();
    glTranslatef(-4.0, 0.0, -5);
    glRotatef(xRotated_1, 1, 0, 0);
    glRotatef(yRotated_1, 0, 1, 0);
    glRotatef(zRotated_1, 0, 0, 1);
    // Making cube (3 quads with texture 6)
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    //Front Face
        glTexCoord2f(0.0f,0.0f); glVertex3f(-obj_size,-obj_size, obj_size);
        glTexCoord2f(1.0f,0.0f); glVertex3f(obj_size,-obj_size, obj_size);
        glTexCoord2f(1.0f,1.0f); glVertex3f(obj_size, obj_size, obj_size);
        glTexCoord2f(0.0f,1.0f); glVertex3f(-obj_size,obj_size, obj_size);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
        //Back Face
        glTexCoord2f(1.0f,0.0f); glVertex3f(-obj_size,-obj_size, -obj_size);
        glTexCoord2f(1.0f,1.0f); glVertex3f(-obj_size,obj_size, -obj_size);
        glTexCoord2f(0.0f,1.0f); glVertex3f(obj_size,obj_size, -obj_size);
        glTexCoord2f(0.0f,0.0f); glVertex3f(obj_size,-obj_size, -obj_size);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
        //Top Face
        glTexCoord2f(0.0f,1.0f); glVertex3f(-obj_size,obj_size, -obj_size);
        glTexCoord2f(0.0f,0.0f); glVertex3f(-obj_size,obj_size, obj_size);
        glTexCoord2f(1.0f,0.0f); glVertex3f(obj_size,obj_size, obj_size);
        glTexCoord2f(1.0f,1.0f); glVertex3f(obj_size,obj_size, -obj_size);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
        // Bottom Face
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-obj_size, -obj_size, -obj_size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( obj_size, -obj_size, -obj_size);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( obj_size, -obj_size,  obj_size);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-obj_size, -obj_size,  obj_size);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);
        //Right face
        glTexCoord2f(1.0f, 0.0f); glVertex3f( obj_size, -obj_size, -obj_size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( obj_size,  obj_size, -obj_size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( obj_size,  obj_size,  obj_size);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( obj_size, -obj_size,  obj_size);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_QUADS);
        //Left Face
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-obj_size, -obj_size, -obj_size);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-obj_size, -obj_size,  obj_size);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-obj_size,  obj_size,  obj_size);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-obj_size,  obj_size, -obj_size);
    glEnd();
    glPopMatrix();

    //Tetrahedron
    glPushMatrix();
    glTranslatef(-2.0, 0.0, -5);
    glRotatef(xRotated_2, 1, 0, 0);
    glRotatef(yRotated_2, 0, 1, 0);
    glRotatef(zRotated_2, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Front }
        glTexCoord2f(1.0f, 0.0f); glVertex3f(obj_size, -obj_size, obj_size); // { Front }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( -obj_size,-obj_size, obj_size); // { Front }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Right }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size0,-obj_size, -obj_size); // { Right }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size,obj_size); // { Right }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Back }
        glTexCoord2f(0.0f, 0.0f);glVertex3f( -obj_size,-obj_size,obj_size); // { Back }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(obj_size0,-obj_size,-obj_size); // { Back }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[9]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size0, -obj_size, -obj_size); // { Back }
        glTexCoord2f(0.0f, 0.0f);glVertex3f( -obj_size,-obj_size,obj_size); // { Back }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(obj_size,-obj_size,obj_size); // { Back }
    glEnd();
    glPopMatrix();

    //Pyramid
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5);
    glRotatef(xRotated_3, 1, 0, 0);
    glRotatef(yRotated_3, 0, 1, 0);
    glRotatef(zRotated_3, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Front }
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-obj_size,-obj_size, obj_size); // { Front }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size, obj_size); // { Front }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Back }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size,-obj_size,-obj_size); // { Back }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Back }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Right }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size,-obj_size, obj_size); // { Right }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size,-obj_size); // { Right }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Left }
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Left }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size, obj_size); // { Left }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Bottom }
        glTexCoord2f(1.0f, 1.0f);glVertex3f(obj_size,-obj_size,-obj_size);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(obj_size,-obj_size,obj_size);
        glTexCoord2f(0.0f, 0.0f);glVertex3f(-obj_size,-obj_size,obj_size);
    glEnd();
    glPopMatrix();

    //Octahedron
    glPushMatrix();
    glTranslatef(2.0, 0.0, -5);
    glRotatef(xRotated_4, 1, 0, 0);
    glRotatef(yRotated_4, 0, 1, 0);
    glRotatef(zRotated_4, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Front }
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-obj_size,-obj_size, obj_size); // { Front }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size, obj_size); // { Front }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Right }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size,-obj_size, obj_size); // { Right }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size,-obj_size); // { Right }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Back }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size,-obj_size,-obj_size); // { Back }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Back }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, obj_size, obj_size0); // { Left }
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Left }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size, obj_size); // { Left }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, -3*obj_size, obj_size0); // { Front }
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-obj_size,-obj_size, obj_size); // { Front }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size, obj_size); // { Front }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, -3*obj_size, obj_size0); // { Right }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size,-obj_size, obj_size); // { Right }
        glTexCoord2f(0.0f, 1.0f);glVertex3f( obj_size,-obj_size,-obj_size); // { Right }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glBegin( GL_TRIANGLES );
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, -3*obj_size, obj_size0); // { Back }
        glTexCoord2f(1.0f, 0.0f);glVertex3f( obj_size,-obj_size,-obj_size); // { Back }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Back }
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);glVertex3f( obj_size0, -3*obj_size, obj_size0); // { Left }
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-obj_size,-obj_size,-obj_size); // { Left }
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-obj_size,-obj_size, obj_size); // { Left }
    glEnd();
    glPopMatrix();


    //Icosahedron
    glPushMatrix();
    glTranslatef(4.0, 0.0, -5);
    glRotatef(xRotated_5, 1, 0, 0);
    glRotatef(yRotated_5, 0, 1, 0);
    glRotatef(zRotated_5, 0, 0, 1);
    //A
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(b,a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-b,a,0);
    glEnd();
    //B
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-b,a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(b,a,0);
    glEnd();
    //C
    glBindTexture(GL_TEXTURE_2D, texture[9]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(0,-b,a);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-a,0,b);
    glEnd();
    //D
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(a,0,b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(0,-b,a);
    glEnd();
    //E
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(0,-b,-a);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(a,0,-b);
    glEnd();
    //F
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-a,0,-b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(0,-b,-a);
    glEnd();
    //G
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,-b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(b,-a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-b,-a,0);
    glEnd();
    //H
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,-b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-b,-a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(b,-a,0);
    glEnd();
    //I
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(-b,a,0);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-a,0,b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-a,0,-b);
    glEnd();
    //J
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(-b,-a,0);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-a,0,-b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-a,0,b);
    glEnd();
    //K
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(b,a,0);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(a,0,-b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(a,0,b);
    glEnd();
    //L
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(b,-a,0);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(a,0,b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(a,0,-b);
    glEnd();
    //M
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-a,0,b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-b,a,0);
    glEnd();
    //N
    glBindTexture(GL_TEXTURE_2D, texture[9]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(b,a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(a,0,b);
    glEnd();
    //O
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-b,a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-a,0,-b);
    glEnd();
    //P
    glBindTexture(GL_TEXTURE_2D, texture[11]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(a,0,-b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(b,a,0);
    glEnd();
    //Q
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,-b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-a,0,-b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-b,-a,0);
    glEnd();
    //R
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,-b,-a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(b,-a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(a,0,-b);
    glEnd();
    //S
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,-b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(-b,-a,0);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-a,0,b);
    glEnd();
    //T
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin( GL_POLYGON );
        glTexCoord2f(0.0f, 0.0f);glVertex3f(0,-b,a);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(a,0,b);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(b,-a,0);
    glEnd();
    glPopMatrix();



/*
    //Making sphere
    //https://www.davidwparker.com/2011/09/05/opengl-screencast-8-drawing-in-3d-part-3-spheres/
    glPushMatrix();
    glTranslatef(5.0, 0.0, -5);
    glRotatef(xRotated_5, 1, 0, 0);
    glRotatef(yRotated_5, 0, 1, 0);
    glRotatef(zRotated_5, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    GLUquadric *sphere; // object 선언
    sphere = gluNewQuadric(); // object 생성
    gluSphere(sphere, 1.0f, 50, 10);  // sphere 그리기
    glFlush();
    glDisable(GL_TEXTURE_2D);
    */
}

void resizeWindow(int x, int y)
{
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1, 1, -1, 1, 1, -1);
    //Angle of view : 60 degrees
    //Near clipping plane distance    :0.5
    //Far clipping plane distance : 20.0
    gluPerspective(60.0, (GLdouble)x/(GLdouble)y, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);    //Use the whole window for rendering
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
    case 'a':
        xRotated_1 += 5;
        zRotated_1 += 5;
        break;
    case 's':
        xRotated_2 += 5;
        zRotated_2 += 5;
        break;
    case 'd':
        xRotated_3 += 5;
        zRotated_3 += 5;
        break;
    case 'f':
        xRotated_4 += 5;
        zRotated_4 += 5;
        break;
    case 'g':
        xRotated_5 += 5;
        zRotated_5 += 5;
        break;
    default:
        break;
    }
    drawScene();
}

char* filename1 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture01.bmp";
char* filename2 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture02.bmp";
char* filename3 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture03.bmp";
char* filename4 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture04.bmp";
char* filename5 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture05.bmp";
char* filename6 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture06.bmp";
char* filename7 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture07.bmp";
char* filename8 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture08.bmp";
char* filename9 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture09.bmp";
char* filename10 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture10.bmp";
char* filename11 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture11.bmp";
char* filename12 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture12.bmp";
char* filename13 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture13.bmp";
char* filename14 = "C:/Users/x220/Desktop/ComputerGraphics/HW04/texture14.bmp";

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Simple Texture");

    loadTextureFromFile(filename1, filename2, filename3, filename4, filename5, filename6,filename7,
                        filename8,filename9,filename10,filename11,filename12,filename13,filename14);

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resizeWindow);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
