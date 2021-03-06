#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

inline int round (const float a){return int(a+0.5);}
GLfloat width=800.0, height=600.0;

void drawAxis(void){
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-width/2, 0);
    glVertex2f(width/2, 0);
    glVertex2f(0, -height/2);
    glVertex2f(0, height/2);
    glEnd();
}

class Vertex2D{
public:
    GLfloat x, y;
    Vertex2D(GLfloat x_, GLfloat y_){
        x = x_;
        y = y_;
    }
};

void drawPolygon(Vertex2D*verts, GLint nVerts){
    GLint k;
    glBegin(GL_POLYGON);
    for (k=0;k<nVerts;k++){
        glVertex2f(verts[k].x, verts[k].y);
    }
    glEnd();
}
//Practice1=================================
void translatePolygon(Vertex2D*verts, GLint nVerts, GLfloat tx, GLfloat ty){
    GLint k;
    for(k=0; k<nVerts; k++){
        //Move x by tx, move y by ty
        verts[k].x = verts[k].x + tx;
        verts[k].y = verts[k].y + ty;
    }
}

void drawPractice_1(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //draw x-axis, y-axis
    drawAxis();
    Vertex2D tri_1[3] = {{50.0, 25.0},{150.0, 25.0},{100.0, 100.0}};

    //draw triangle (RED)
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(tri_1, 3);

    //translate triangle (GREEN)
    glColor3f(0.0,1.0,0.0);
    translatePolygon(tri_1, 3, -100.0, -50.0);
    drawPolygon(tri_1, 3);

    glFlush();
}




//Practice2================================
void rotatePolygon_v1(Vertex2D*verts, GLint nVerts, GLfloat degree){
    GLint k;
    GLfloat theta = degree * 3.14 / 180;
    for(k=0; k<nVerts; k++){
        Vertex2D temp = verts[k];
        temp.x = verts[k].x * cos(theta)-verts[k].y * sin(theta);
        temp.y = verts[k].x * sin(theta)+verts[k].y * cos(theta);
        verts[k] = temp;
    }
}

void rotatePolygon_v2(Vertex2D*verts, GLint nVerts, Vertex2D pivPt, GLfloat degree){
    GLint k;
    GLfloat theta = degree* 3.14 / 180;
    for(k=0; k<nVerts; k++){
        //Move to origin,
        //and then rotate
        //Move back to the original position
        Vertex2D temp = verts[k];

        verts[k].x = verts[k].x - pivPt.x;
        verts[k].y = verts[k].y - pivPt.y;

        temp.x = verts[k].x * cos(theta) - verts[k].y * sin(theta);
        temp.y = verts[k].x * sin(theta) + verts[k].y * cos(theta);
        verts[k] = temp;

        verts[k].x = verts[k].x + pivPt.x;
        verts[k].y = verts[k].y + pivPt.y;
    }
}

void drawPractice_2(void){
    glClear(GL_COLOR_BUFFER_BIT);
    //draw x-axis, y-axis
    drawAxis();
    Vertex2D tri_1[3]={{50.0, 25.0}, {150.0, 25.0}, {100.0, 100.0}};
    Vertex2D tri_2[3]={{50.0, 25.0}, {150.0, 25.0}, {100.0, 100.0}};
    Vertex2D tri_3[3]={{50.0, 25.0}, {150.0, 25.0}, {100.0, 100.0}};
    Vertex2D tri_4[3]={{150.0, 25.0}, {250.0, 25.0}, {200.0, 100.0}};

    //draw triangle (RED)
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(tri_1, 3);

    //rotate triangle with origin(YELLOW)
    glColor3f(0.5, 0.5, 0.0);
    rotatePolygon_v1(tri_2, 3, 180);
    drawPolygon(tri_2, 3);

    //rotate triangle with pivot (RED)
    glColor3f(0.5, 0.0, 0.0);
    rotatePolygon_v2(tri_3, 3, Vertex2D(100, 50), 180);
    drawPolygon(tri_3, 3);

    //draw triangle (BLUE)
    glColor3f(0.0, 0.0, 1.0);
    drawPolygon(tri_4, 3);
    //rotate triangle with T->R_v1 -> T(BLUE)
    glColor3f(0.0, 0.0, 0.5);
    //Using the translate function,
    //perform similar rotation as pivot rotation(RED)
    translatePolygon(tri_4, 3, -200, -50);
    rotatePolygon_v1(tri_4, 3, 180);
    translatePolygon(tri_4, 3, +200, +50);
    drawPolygon(tri_4, 3);

    glFlush();
}








//Practice3======================================
void scalePolygon_v1(Vertex2D*verts, GLint nVerts, GLfloat sx, GLfloat sy){
    GLint k;
    for(k=0; k<nVerts; k++){
        //scale x by sx, scale y by sy
        verts[k].x = verts[k].x * sx;
        verts[k].y = verts[k].y * sy;
     }
}

void scalePolygon_v2(Vertex2D*verts, GLint nVerts, Vertex2D pivPt, GLfloat sx, GLfloat sy){
    //Perform pivot scale
    GLint k;
    for(k=0; k<nVerts; k++){
        //scale x by sx, scale y by sy
        verts[k].x = verts[k].x - pivPt.x;
        verts[k].y = verts[k].y - pivPt.y;

        verts[k].x = verts[k].x * sx;
        verts[k].y = verts[k].y * sy;

        verts[k].x = verts[k].x + pivPt.x;
        verts[k].y = verts[k].y + pivPt.y;
     }
}

void drawPractice_3(void){
    glClear(GL_COLOR_BUFFER_BIT);

    //draw x-axis, y-axis
    drawAxis();

    Vertex2D square_1[4] = {{0.0, 0.0},{0.0, 200.0}, {200.0, 200.0}, {200.0, 0.0}};
    Vertex2D square_2[4] = {{0.0, 0.0},{0.0, -200.0}, {-200.0, -200.0}, {-200.0, 0.0}};

    //draw square (RED)
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(square_1, 4);

    //scalesquare with origin (RED)
    glColor3f(0.5, 0.0, 0.0);
    scalePolygon_v1(square_1, 4, 0.5, 0.5);
    drawPolygon(square_1, 4);

    //draw square (BLUE)
    glColor3f(0.0, 0.0, 1.0);
    drawPolygon(square_2, 4);
    //scale square with pivot(BLUE)
    glColor3f(0.0, 0.0, 0.5);
    scalePolygon_v2(square_2, 4, Vertex2D(-100, -100), 0.5, 0.5);
    drawPolygon(square_2, 4);

    glFlush();
}


void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-width/2, width/2, -height/2, height/2);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);
    glutCreateWindow("TRS");
    init();
    glutDisplayFunc(drawPractice_2);
    glutMainLoop(); //display everything and wait
    return 0;
}
