//ctrlPt 5개로 늘리고 ctrlPt도 화면상에 찍기
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>

GLsizei winWidth=600, winHeight=600;
GLfloat xwcMin=-300.0, xwcMax=300.0;
GLfloat ywcMin=-300.0, ywcMax=300.0;
class wcPt3D{
public:
    GLfloat x,y,z;
};
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
}
void plotPoint(wcPt3D bezCurvePt)
{
    glBegin(GL_POINTS);
    glVertex2f(bezCurvePt.x, bezCurvePt.y);
    glEnd();
}
void binomialCoeffs(GLint n, GLint* C)
{
    GLint k, j;
    for(k=0;k<=n; k++){
        C[k]=1;
        for(j=n;j>=k+1;j--)
            C[k]*=j;
        for(j=n-k;j>=2;j--)
            C[k]/=j;
    }
}

void computeBezPt(GLfloat u, wcPt3D* bezPt, GLint nCtrlPts, wcPt3D* ctrlPts, GLint* C)
{
    GLint k, n=nCtrlPts-1;
    GLfloat bezBlendFcn;
    bezPt->x=bezPt->y=bezPt->z=0.0;

    for(k=0; k<nCtrlPts;k++){
        bezBlendFcn = C[k]*pow(u,k)*pow(1-u,n-k);
        bezPt->x +=ctrlPts[k].x*bezBlendFcn;
        bezPt->y +=ctrlPts[k].y*bezBlendFcn;
        bezPt->z +=ctrlPts[k].z*bezBlendFcn;
    }
}

void bezier(wcPt3D* ctrlPts, GLint nCtrlPts, GLint nBezCurvePts)
{
    wcPt3D bezCurvePt;
    GLfloat u;
    GLint *C, k;

    C=new GLint[nCtrlPts];

    binomialCoeffs(nCtrlPts-1, C);
    for(k=0;k<=nBezCurvePts;k++){
        u=GLfloat(k)/GLfloat(nBezCurvePts);
        computeBezPt(u, &bezCurvePt, nCtrlPts, ctrlPts, C);
        plotPoint(bezCurvePt);
    }
    delete[] C;
}

void displayFcn()
{
    GLint nCtrlPts=5, nBezCurvePts=1000;

    wcPt3D ctrlPts[5] = {{-40.0, -40.0,0.0},{-10.0,200.0,0.0},{10.0,-200.0,0.0},{40.0,40.0,0.0},{-30.0,50.0,0.0}};

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(6);
    for (int i=0;i<5;i++){
        glColor3f(0.0,0.0,1.0);
        plotPoint(ctrlPts[i]);
    }

    glPointSize(2);
    glColor3f(1.0,0.0,0.0);
    bezier(ctrlPts,nCtrlPts,nBezCurvePts);
    glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glViewport(0,0,newHeight,newWidth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(xwcMin, xwcMax, ywcMin, ywcMax);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("BezierCurve");

    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();

    return 0;
}
