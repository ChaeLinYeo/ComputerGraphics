//This is Final
//hw02test03
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

GLsizei winWidth=600, winHeight=600;
GLfloat xwcMin=-200.0, xwcMax=400.0;
GLfloat ywcMin=-200.0, ywcMax=400.0;

int shape;
int isfill;
int num;

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

void scale2D(GLfloat sx, GLfloat sy, wcPt2D fixedPt){
    Matrix3x3 matScale;
    matrix3x3SetIdentity(matScale);

    matScale[0][0]= sx;
    matScale[0][2]=(1-sx)*fixedPt.x;
    matScale[1][1]= sy;
    matScale[1][2]=(1-sy)*fixedPt.y;

    matrix3x3PreMultiply(matScale, matComposite);
}

float rand_FloatRange(float a, float b){
    return ((b-a)*((float)rand()/RAND_MAX))+a;
}

//filltriangle
void filltriangle(){
    //random color
    glColor3ub(rand()%256 , rand()%256 , rand()%256);
    glLineWidth(rand()%10); //선굵기
    float x = rand()%225;
    float y = rand()%225;
    float r = rand()%100;

    //float x = rand()%(bx+1-ax)+ax;
    //float y = rand()%(by+2-ay)+ay;
    //float x = rand_FloatRange(cos(60)*r,225-cos(60)*r);
    //float y = rand_FloatRange(sin(30)*r,225-sin(30)*r);

    //삼각형 세 정점 좌표들 계산
    printf("triangle coor : x : %f y : %f r : %f\n",x,y,r);
    float c_x = x;
    float c_y = y+r;
    float b_x = x + r*cos(60);
    float b_y = y - r*0.5;
    float a_x = x - r*cos(60);
    float a_y = y- r*0.5;

    glBegin(GL_POLYGON);
    glVertex2f(c_x, c_y);
    glVertex2f(b_x, b_y);
    glVertex2f(a_x, a_y);
    glEnd();
}
//unfilltriangle
void unfilltriangle(){
    //random color
    glColor3ub(rand()%256 , rand()%256 , rand()%256);
    glLineWidth(rand()%10); //선굵기
    float x = rand()%225;
    float y = rand()%225;
    float r = rand()%100;
    //float x = rand()%(bx+1-ax)+ax;
    //float y = rand()%(by+2-ay)+ay;
    //float x = rand_FloatRange(cos(60)*r,225-cos(60)*r);
    //float y = rand_FloatRange(sin(30)*r,225-sin(30)*r);

    //삼각형 세 정점 좌표들 계산
    printf("triangle coor : x: %f y : %f r : %f\n",x,y,r);
    float c_x = x;
    float c_y = y+r;
    float b_x = x + r*cos(60);
    float b_y = y - r*0.5;
    float a_x = x - r*cos(60);
    float a_y = y- r*0.5;

    glBegin(GL_LINE_LOOP);
    glVertex2f(c_x, c_y);
    glVertex2f(b_x, b_y);
    glVertex2f(a_x, a_y);
    glEnd();
}

//GL_LINE_LOOP는 정점끼리 선으로 이음
//GL_POLYGON은 안을 칠함
void line(){
    glColor3ub(rand()%256 , rand()%256 , rand()%256);//random color
    glLineWidth(rand()%10); //선굵기
    float x1 = rand()%225;
    float y1 = rand()%225;
    float x2 = rand()%225;
    float y2 = rand()%225;
    printf("line coor : x1 : %f y1 : %f\n",x1,y1);
    printf("line coor : x2 : %f y2 : %f\n",x2,y2);
    GLint k;
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}





void unfillsquare()
{
    glColor3ub(rand()%256 , rand()%256 , rand()%256);//random color
    glLineWidth(rand()%10); //선굵기
    float x = rand()%100;
    float y = rand()%100;
    double sidelength = rand()%100;
    double halfside = sidelength / 2;
    glBegin(GL_LINE_LOOP);//unfill
    glVertex2d(x + halfside, y + halfside);
    glVertex2d(x + halfside, y - halfside);
    glVertex2d(x - halfside, y - halfside);
    glVertex2d(x - halfside, y + halfside);
    glEnd();
}
void fillsquare()
{
    glColor3ub(rand()%256 , rand()%256 , rand()%256);//random color
    glLineWidth(rand()%10); //선굵기
    float x = rand()%100;
    float y = rand()%100;
    double sidelength = rand()%100;
    double halfside = sidelength / 2;
    glBegin(GL_POLYGON);//unfill
    glVertex2d(x + halfside, y + halfside);
    glVertex2d(x + halfside, y - halfside);
    glVertex2d(x - halfside, y - halfside);
    glVertex2d(x - halfside, y + halfside);
    glEnd();
}




//unfill circle
void unfillcircle() {
    glColor3ub(rand()%256 , rand()%256 , rand()%256);
    glLineWidth(rand()%10); //선굵기
    float dx = rand()%100;
    float dy = rand()%100;
    float r = rand()%100;
    //printf("unfillcircle coor : %f %f\n",x,y);
    glBegin(GL_LINES);
    for (int i = 0; i < 360; i++)
    {
        double x = r * cos(i) + dx;
        double y = r * sin(i) + dy;
        glVertex3f(x, y, 0);

        x = r * cos(i + 0.1) + dx;
        y = r * sin(i + 0.1) + dy;
        glVertex3f(x, y, 0);
    }
    glEnd();
}
void fillcircle() {
    glColor3ub(rand()%256 , rand()%256 , rand()%256);
    glLineWidth(rand()%10); //선굵기
    float dx = rand()%100;
    float dy = rand()%100;
    float r = rand()%100;
    //printf("unfillcircle coor : %f %f\n",x,y);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++)
    {
        double x = r * cos(i) + dx;
        double y = r * sin(i) + dy;
        glVertex3f(x, y, 0);

        x = r * cos(i + 0.1) + dx;
        y = r * sin(i + 0.1) + dy;
        glVertex3f(x, y, 0);
    }
}


void displayFcn(){
    GLfloat tx = rand(), ty = rand();
    GLfloat sx = rand(), sy = rand();
    GLdouble theta = pi/2.0;
    glClear(GL_COLOR_BUFFER_BIT);
    int i;
    for (i=0; i<num; i++){
        isfill = rand()%2;
        shape = rand() % 4;
        if(shape==0){   //선
            line();
            printf("\n선\n");
        }
        else if(shape==1){  //정삼각형
            printf("\n정삼각형 \n");
            if(isfill == 1)
                filltriangle();
            else
                unfilltriangle();
        }
        else if(shape==2){  //정사각형
            printf("\n정사각형 \n");
            if(isfill==1)
                fillsquare();
            else
                unfillsquare();
        }
        else if(shape==3){  //원
            printf("\n원 \n");
            if(isfill == 1)
                fillcircle();
            else
                unfillcircle();
        }
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
    srand(time(NULL));

    printf("표시할 도형의 개수: ");
    scanf("%d", &num);

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
