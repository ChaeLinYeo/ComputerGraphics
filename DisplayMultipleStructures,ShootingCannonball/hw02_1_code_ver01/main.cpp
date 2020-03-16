//hw02_2_test03
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
GLdouble v, theta, s, alpa;
GLdouble t;

GLsizei winWidth=600, winHeight=600;
GLfloat xwcMin=-10.0, xwcMax=300.0;
GLfloat ywcMin=-10.0, ywcMax=300.0;

class wcPt2D{
public:
    GLfloat x, y;
};

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 matComposite;
const GLdouble pi = 3.14159;

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void matrix3x3SetIdentity(Matrix3x3 matIdent3x3){
    GLint row, col;
    for(row=0; row<3; row++){
        for(col=0; col<3; col++)
            matIdent3x3[row][col]=(row==col);
    }
}

void matrix3x3PreMultiply(Matrix3x3 m1, Matrix3x3 m2){
    GLint row, col;
    Matrix3x3 matTemp;

    for(row=0; row<3; row++){
        for(col=0; col<3; col++)
            matTemp[row][col]=m1[row][0]*m2[0][col] + m1[row][1]*m2[1][col] + m1[row][2]*m2[2][col];
    }

    for(row=0; row<3; row++){
        for(col=0; col<3; col++)
            m2[row][col]=matTemp[row][col];
    }
}

void translate2D(GLfloat tx, GLfloat ty){
    Matrix3x3 matTransl;
    matrix3x3SetIdentity(matTransl);

    matTransl[0][2]= tx;
    matTransl[1][2]= ty;

    matrix3x3PreMultiply(matTransl, matComposite);
}

void rotate2D(wcPt2D pivotPt, GLfloat theta){
    Matrix3x3 matRot;
    matrix3x3SetIdentity(matRot);
    matRot[0][0]=cos(theta);
    matRot[0][1]=-sin(theta);
    matRot[0][2]=pivotPt.x*(1-cos(theta))+pivotPt.y*sin(theta);
    matRot[1][0]=sin(theta);
    matRot[1][1]=cos(theta);
    matRot[1][2]=pivotPt.y*(1-cos(theta))-pivotPt.x*sin(theta);

    matrix3x3PreMultiply(matRot, matComposite);
}

void scale2D(GLfloat sx, GLfloat sy, wcPt2D fixedPt){
    Matrix3x3 matScale;
    matrix3x3SetIdentity(matScale);

    matScale[0][0]= sx;
    matScale[0][2]=(1-sx)*fixedPt.x;
    matScale[1][1]= sy;
    matScale[1][2]=(1-sy)*fixedPt.y;

    matrix3x3PreMultiply(matScale, matComposite);
}

void transformVerts2D(GLint nVerts, wcPt2D* verts){
    GLint k;
    GLfloat temp;

    for(k=0; k<nVerts; k++){
        temp = matComposite[0][0]*verts[k].x + matComposite[0][1]*verts[k].y + matComposite[0][2];
        verts[k].y = matComposite[1][0]*verts[k].x + matComposite[1][1]*verts[k].y + matComposite[1][2];
        verts[k].x = temp;
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
    GLint nVerts=3;
    wcPt2D verts[3]={{25.0, 0.0},{15.0, 10.0},{35.0, 10.0}};//�ﰢ���� ���� verts
    wcPt2D centroidPt;
    GLint k, xSum=0, ySum=0;
    centroidPt.x = 0;
    centroidPt.y = 0;
    wcPt2D pivPt, fixedPt;
    pivPt = centroidPt;
    fixedPt = centroidPt;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    triangle(verts);

    for(t=1; t<=10; t++){
        matrix3x3SetIdentity(matComposite);
        GLdouble tx = v*cos(pi*theta/180)*t;
        GLdouble ty = v*sin(pi*theta/180)*t - 5*t*t;//pivot����Ʈ �ٲ�°� ������Ʈ ->��Ʈ���̵�
        // 180�����°�, �������� �ٲ���� �ؼ�.
        translate2D(v*cos(pi*theta/180), 5-10*t + v*sin(pi*theta/180));
        centroidPt.x = tx;
        centroidPt.y = ty;//������Ʈ �� ������ tx ty��ŭ. ������ǥ �ű�
        rotate2D(centroidPt, pi*alpa/180);
        scale2D(s, s, centroidPt);
        transformVerts2D(nVerts, verts);
        triangle(verts);
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
    printf("�ʼӵ� v : ");
	scanf("%lf", &v);
	printf("�߻簢�� theta : ");
	scanf("%lf", &theta);
	printf("�����ϻ�� s : ");
	scanf("%lf", &s);
	printf("ȸ����� alpa : ");
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
