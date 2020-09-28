#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// diem trung tam cua hinh tron
int xc=320 , yc=240;
int height = 500;
int width = 500;
struct diem{
    GLint x;
    GLint y;
};
diem p1,p2;

// 8 diem doi xung de ve
void point8(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc+y, yc+x);
    glVertex2i(xc+y, yc-x);
    glVertex2i(xc-x, yc-y);
    glVertex2i(xc-y, yc-x);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc-y, yc+x);
    glEnd();
}

//dung thuoat toanbresenham de ve hinh tron voi ban kinh r
void bresenham_circle(int r)
{
    int x=0,y=r;
    float pk=3.0-2*r;

    //ve diem
    point8(x,y);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    int k;
    // tim cac dinh cho den khi x=y
    while(x < y)
    {
        x = x + 1;
        if(pk < 0)
            pk = pk + 4*x+6;
        else
        {
            y = y - 1;
            pk = pk + 4*(x - y) + 10;
        }
        point8(x,y);
    }
    glEnd();
    glFlush();
}
void midpoint_circle(int r){
    int x,y,p;
    x=0;
    y=r;
    p=5/4-r;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    while (x<=y) {
        point8(x,y);
        if (p<0)
            p+=2*x+3;
        else{
            p+=2*(x-y)+5;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

//hien thi
void display(void)
{

//    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glPopMatrix();
    glFlush();


}
void myMouseFunc(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        p1.x = x;
        p1.y = height - y;

        xc = p1.x;
        yc = p1.y;
    }
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        p2.x = x;
        p2.y = height - y;

        int radius = (int)sqrt((p1.x -p2.x)*(p1.x -p2.x)+(p1.y -p2.y)*(p1.y -p2.y));
//        bresenham_circle(radius);
        midpoint_circle(radius);
        printf("p1.x: %d,p1.y=%d\n",p1.x,p1.y);
        printf("p2.x: %d,p2.y=%d\n",p2.x,p2.y);
        printf("radius: %d\n",radius);
    }
}

void Init()
{
    //dat mau trang
    glClearColor(1.0,1.0,1.0,0);
    // mau ve mau den
    glColor3f(0.0,0.0,0.0);

    gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
    //dang ki su dung thu vien glut
    glutInit(&argc,argv);
    //che do hien thi
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // vi tri cua so va kich thuoc
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,height);

    glutCreateWindow("bresenham_circle");

    Init();
    //goi ham hien thi
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunc);
    // loop
    glutMainLoop();
}