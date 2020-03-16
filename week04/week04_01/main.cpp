#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
GLsizei winWidth=600, winHeight=500;
GLubyte label[] = "JanFebMarAprMayJunJulAugSepOctNovDec";

GLint dataValue[12] = {420, 342, 324, 310, 262, 185, 190, 196, 217, 240, 312, 438}; //for linegraph, bar chart
GLint dataValue_for_pie[12] = {10.0, 7.0, 13.0, 5.0, 13.0, 14.0, 3.0, 16.0, 5.0, 3.0, 17.0, 8.0};   // for piechart
void init(void){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-winWidth, winWidth, -winHeight, winHeight); //change to this code for Piechart
    //gluOrtho2D(0, winWidth, 0, winHeight);
}

void Writelabel(){
    glColor3f(1,0,0);
    glRasterPos2i(100, 100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
    glRasterPos2i(150, 150);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'C');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'G');
    glFlush();
}

void drawline(){
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(300, 300);
    glVertex2i(100, 200);
    glEnd();
    glFlush();
}

void drawstar(){
    glColor3f(1,0,0);
    glRasterPos2i(200, 200);
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
    glFlush();
}

void drawrect(){
    glColor3f(1,0,0);
    glRecti(300, 300, 200, 100);
    glFlush();
}

void drawcircle(){
    glColor3f(1,0,0);
    double rad = 100;
    glBegin(GL_LINE_STRIP);

    for(int i=0; i<360; i++){
        double angle, x, y;
        angle = i*3.141592 / 180;
        x = rad*cos(angle);
        y = rad*sin(angle);
        glVertex2f(x, y);

        if(i == 90 || i == 215 || i == 300){
            glVertex2i(0, 0);
            glVertex2i(x, y);
        }
    }
    glEnd();
    glFlush();
}

void linegraph(){
//fill here
    glColor3f(1,1,1);
    glRasterPos2i(-500,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'J');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'n');
    glRasterPos2i(-450,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'F');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'b');
    glRasterPos2i(-400,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'r');
    glRasterPos2i(-350,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'p');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'r');
    glRasterPos2i(-300,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'y');
    glRasterPos2i(-250,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'J');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'u');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'n');
    glRasterPos2i(-200,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'J');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'u');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'l');
    glRasterPos2i(-150,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'u');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'g');
    glRasterPos2i(-100,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'p');
    glRasterPos2i(-50,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'c');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 't');
    glRasterPos2i(0,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'o');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'v');
    glRasterPos2i(50,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'D');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'c');


    glColor3f(1,0,0);
    int gap = -500;
    for(int i=0; i<12; i++){
        glRasterPos2i(gap, dataValue[i]);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
        gap+=50;
    }
    glFlush();

    glColor3f(0,0,1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(-500, 420);
    glVertex2i(-450, 342);
    glVertex2i(-400, 324);
    glVertex2i(-350, 310);
    glVertex2i(-300, 262);
    glVertex2i(-250, 185);
    glVertex2i(-200, 190);
    glVertex2i(-150, 196);
    glVertex2i(-100, 217);
    glVertex2i(-50, 240);
    glVertex2i(0, 312);
    glVertex2i(50, 438);
    glEnd();
    glFlush();
}

void barchart(){
//fill here
    glColor3f(1,1,1);
    glRasterPos2i(-500,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'J');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'n');
    glRasterPos2i(-450,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'F');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'b');
    glRasterPos2i(-400,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'r');
    glRasterPos2i(-350,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'p');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'r');
    glRasterPos2i(-300,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'M');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'a');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'y');
    glRasterPos2i(-250,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'J');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'u');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'n');
    glRasterPos2i(-200,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'J');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'u');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'l');
    glRasterPos2i(-150,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'A');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'u');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'g');
    glRasterPos2i(-100,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'S');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'p');
    glRasterPos2i(-50,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'O');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'c');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 't');
    glRasterPos2i(0,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'N');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'o');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'v');
    glRasterPos2i(50,-100);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'D');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'c');

    glColor3f(1,0,0);
    //x1, y1, x2, y2
    //glRecti(-480, 0, -450, 420);
    int x1 = -480;
    int y1 = -450;
    for(int i=0; i<12; i++){
        glRecti(x1, 0, y1, dataValue[i]);
        y1+=50;
        x1+=50;
    }
    glFlush();
}


void piechart(){
    glColor3f(0,0,1);
    double rad = 300;
    int j = 0;
    double com;
    com = 360*dataValue_for_pie[j]/100;
    glBegin(GL_LINE_STRIP);
        for(int i = 0; i <360;i++){
            double angle,x,y,x1,y1,be;
            angle = i*3.141592/180;
            x = rad*cos(angle);
            y = rad*sin(angle);
            glVertex2f(x,y);
            if(i ==0){
                glVertex2i(0,0);
                glVertex2i(x,y);
                com = 360*dataValue_for_pie[j++]/100;
                be = i;
            }
            if(i == be+com){
                glVertex2i(0,0);
                glVertex2i(x,y);
                 com = 360*dataValue_for_pie[j++]/100;
                be = i;
            }

        }
    glEnd();
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("basics");
    init();

    //glutDisplayFunc(Writelabel);
    //glutDisplayFunc(drawline);
    //glutDisplayFunc(drawstar);
    //glutDisplayFunc(drawrect);
    //glutDisplayFunc(drawcircle);

    glutDisplayFunc(linegraph);
    //glutDisplayFunc(barchart);
    //glutDisplayFunc(piechart);
    glutMainLoop();
    return 0;
}
