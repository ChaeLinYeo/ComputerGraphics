//This is final!!
//week05_2
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

GLsizei winWidth=500, winHeight=500;
GLfloat xwcMin=-30.0, xwcMax=500.0;
GLfloat ywcMin=-30.0, ywcMax=500.0;
GLdouble v, s, theta, alpa;

class wcPt2D{
public:
    GLfloat x, y;
    Vertex2D(GLfloat x_, GLfloat y_){
        x = x_;
        y = y_;
    }
};

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 matComposite;
const GLdouble pi = 3.14159;

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void translatePolygon(wcPt2D*verts, GLint nVerts, GLfloat tx, GLfloat ty){
    GLint k;
    for(k=0; k<nVerts; k++){
        //Move x by tx, move y by ty
        verts[k].x = verts[k].x + tx;
        verts[k].y = verts[k].y + ty;
    }
}

void rotatePolygon_v2(wcPt2D*verts, GLint nVerts, wcPt2D pivPt){
    GLint k;
    GLfloat t = alpa* 3.14 / 180;
    for(k=0; k<nVerts; k++){
        //Move to origin,
        //and then rotate
        //Move back to the original position
        wcPt2D temp = verts[k];

        verts[k].x = verts[k].x - pivPt.x;
        verts[k].y = verts[k].y - pivPt.y;

        temp.x = verts[k].x * cos(t) - verts[k].y * sin(t);
        temp.y = verts[k].x * sin(t) + verts[k].y * cos(t);
        verts[k] = temp;

        verts[k].x = verts[k].x + pivPt.x;
        verts[k].y = verts[k].y + pivPt.y;
    }
}

void scalePolygon_v2(wcPt2D*verts, GLint nVerts, wcPt2D pivPt, GLfloat sx, GLfloat sy){
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

void triangle(wcPt2D* verts){
    GLint k;
    glBegin(GL_LINE_LOOP);
    for(k=0; k<3; k++)
        glVertex2f(verts[k].x, verts[k].y);
    glEnd();
}

void displayFcn(){
    int t;
    GLint nVerts=3;
    wcPt2D tri_1[3] = {{25.0, 0.0},{15.0, 10.0},{35.0, 10.0}};
    wcPt2D centroidPt;
    centroidPt.x = 0;
    centroidPt.y = 0;
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    triangle(tri_1);
    for(t=1; t<10; t++){
        //matrix3x3SetIdentity(matComposite);
        GLdouble tx = v*cos(pi*theta/180)*t;
        GLdouble ty = v*sin(pi*theta/180)*t - 5*t*t;//pivot포인트 바뀌는거 업데이트 ->센트로이드
        // 180나누는건, 라디안으로 바꿔줘야 해서.
        translatePolygon(tri_1, 3, v*cos(pi*theta/180), 5-10*t + v*sin(pi*theta/180));

        centroidPt.x = tx;
        centroidPt.y = ty;//업데이트 할 때마다 tx ty만큼. 중점좌표 옮김

        rotatePolygon_v2(tri_1, 3, centroidPt);

        scalePolygon_v2(tri_1, 3, centroidPt, s, s);
        triangle(tri_1);
    }
    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);

    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv){
    printf("초속도 v : ");
	scanf("%lf", &v);
	printf("발사각도 theta : ");
	scanf("%lf", &theta);
	printf("스케일상수 s : ");
	scanf("%lf", &s);
	printf("회전상수 alpa : ");
	scanf("%lf", &alpa);
	printf("%lf %lf %lf %lf\n",v,theta,s,alpa);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Geometric Transformation sequence");

    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);

    glutMainLoop();
    return 0;
}
