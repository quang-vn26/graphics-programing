#include <GL/glut.h>
#include <iostream>
//using namespace std;
int height = 480;
int width = 640;
struct Point {
    GLint x;
    GLint y;
};

Point p1, p2;
//ve theo truc x, cac buoc se tang theo x+1, voi he so go nam trong khoan (0,1)
void lineBres(Point p1, Point p2) {
    int Dx,Dy,P,x,y,const1,const2;

    if(p1.x>p2.x && p1.y>p2.y){
        Point tmp;
        tmp = p1;
        p1=p2;
        p2=tmp;
    }

    Dx=p2.x-p1.x;//khoang cach giua 2 x
    Dy=p2.y-p1.y;//khoang cach giua 2 y

    const1=2*Dy; //neu pi<0
    const2=2*(Dy-Dx);//neu pi>=0

    P=2*Dy-Dx;//Gia tri p tai diem dau tien
    x=p1.x;		y=p1.y;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    while (x<=p2.x)
    {
        //ve diem
        glVertex3i(x,y,0);
        //p(i+1) = p(i)+conts1 de tich tiep p(i+1)
        if (P<0)
            P+=const1;
        else
        {
            //p>=0 thi p(i+1)=,.. tang y len 1
            P+=const2;
            y++;
        }
        //luong tang x len 1 vi dang ve tren truc x
        x++;
    }
//    glEnd();
    glEnd();
    //?
    glFlush();
}
// doan m (-1,0)
void lineBres2(Point p1, Point p2) {
    int Dx,Dy,P,x,y,const1,const2;

    if(p1.x>p2.x ){
        Point tmp;
        tmp = p1;
        p1=p2;
        p2=tmp;
    }

    Dx=p2.x-p1.x;//khoang cach giua 2 x
    Dy=p2.y-p1.y;

    const1=2*Dy; //neu pi<0
    const2=2*(Dy-Dx);//neu pi>=0

    P=2*Dy-Dx;//Gia tri p tai diem dau tien
    x=p1.x;		y=p1.y;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    while (x<=p2.x)
    {
        //ve diem
        glVertex3i(x,y,0);
        //p(i+1) = p(i)+conts1 de tich tiep p(i+1)
        if (P<0)
            P-=const1;
        else
        {
            //p>=0 thi p(i+1)=,.. giam y len 1
            P-=const2;
            y--;
        }
        //luong tang x len 1 vi dang ve tren truc x
        x++;
    }
//    glEnd();
    glEnd();
    //?
    glFlush();
}
void lineBres3(Point p1, Point p2) {
    int Dx,Dy,P,x,y,const1,const2;

    if(p1.x>p2.x ){
        Point tmp;
        tmp = p1;
        p1=p2;
        p2=tmp;
    }


    int d1 = p1.x-p2.x;
    int d2 = 0;
    x=p1.x;		y=p1.y;
    P=0;//Gia tri p tai diem dau tien

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    while (y<=p2.y)
    {
        //ve diem
        glVertex3i(x,y,0);
        //p(i+1) = p(i)+conts1 de tich tiep p(i+1)
        if (P<0)
            P=-2*x+2*x+2*p1.x-2*x;
        else
        {
            P=-2*(x+1)+2*x+2*p1.x-2*x;
            x++;
        }
        //luong tang x len 1 vi dang ve tren truc x
        y++;
    }
//    glEnd();
    glEnd();
    //?
    glFlush();
}
void drawRect(int x1,int x2,int y1,int y2){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glRecti(x1, x2, y1, y2);
    glColor3f(0.0, 0.0, 0.0);
//    cohenSuth();
    glFlush();

}
void myMouseFunc(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        p1.x = x;
        p1.y = height - y;
    }
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        p2.x = x;
        p2.y = height - y;
        int Dx=p2.x-p1.x;//khoang cach giua 2 x
        int Dy=p2.y-p1.y;
        double m = 1.0*Dy/Dx;
        printf("m=%f\n",m);

        drawRect(p1.x,p1.y,p2.x,p2.y);
        printf("p1.x: %d,p1.y=%d\n",p1.x,p1.y);
        printf("p2.x: %d,p2.y=%d\n",p2.x,p2.y);
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();
    glFlush ();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(width   , height);
    glutCreateWindow("Ve duong thang");
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    init();
    glutMainLoop();

    return 0;
}
