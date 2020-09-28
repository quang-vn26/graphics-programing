#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
//tam cua elip
int xc , yc;
int height = 500;
int width = 640;
int a,b;
struct diem{
    GLint x;
    GLint y;
};
diem p1,p2;

//ve do thi 4 diem bang cach xu dung thuoc tinh doi xung cua elip
void put4pixel(int xc,int yc, int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc+x, yc+y);
    glVertex2i(xc+x, yc-y);
    glVertex2i(xc-x, yc+y);
    glVertex2i(xc-x, yc-y);
    glEnd();
}

// Hàm vẽ đường tròn bằng bresenham's
// thuật toán vẽ đường tròn
void bresenham_eclipse(int xc,int yc, int a, int b)
{
    double x,y,p,x0, y0,a2,b2;
    a2=a*a; b2=b*b;
    x=0;
    y=b;
    p=-2*b+1+2*b2/(a2);
    x0=a2/(sqrt(a2+b2)); y0=b2/(sqrt(a2+b2));

    while (x<=x0){
        put4pixel(xc,yc,x,y);
        if (p<0) p+=2*b2*(2*x+3)/a2;
        else{
            p+=4*(1-y)+ 2*b2 * (2*x+3)/a2;
            y--;
        }
        x++;
    }
    x=a; y=0; p=2*a2/b2 - 2*a+1;
    while (y<=y0){
        put4pixel(xc,yc,x,y);
        if (p<0 ) p+=2*a2*(2*y+3)/b2;
        else{
            p+=4*(1-x) + 2*a2*(2*y+3)/b2;
            x--;
        }
        y++;
    }
    glEnd();
    glFlush();
}
void display(void)
{
    glPushMatrix();
    /* Xóa bộ đệm đến các giá trị đặt trước */
    glClear(GL_COLOR_BUFFER_BIT);
    glPopMatrix();

    glFlush();
}
//ham xu li click chuot
void myMouseFunc(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        p1.x = x;
        p1.y = height - y;

        xc = p1.x;
        yc = p1.y;
    }
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

        //cac bien theo thu tu la vi tri tam(xc,yc) va ()
        bresenham_eclipse(p1.x,p1.y,a,b);
        printf("p1.x: %d,p1.y=%d\n",p1.x,p1.y);
    }
}

void Init()
{
    /* Đặt màu trong thành trắng */
    glClearColor(1.0,1.0,1.0,0);
    /* Set fill color to black */
    glColor3f(0.0,0.0,0.0);
    /* glViewport(0 , 0 , 640 , 480); */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
    cout << "Nhap a: "; cin>>a;
    cout << "Nhap b: ";cin>>b;

    /* Khởi tạo thư viện GLUT * /
    glutInit(&argc,argv);
    /* Đặt chế độ hiển thị ban đầu */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /*  Đặt vị trí và kích thước cửa sổ ban đầu*/
    glutInitWindowPosition(0,0);
    glutInitWindowSize(width,height);
    //   / * Tạo cửa sổ với tiêu đề "DDA_Line" * /
    glutCreateWindow("bresenham_elip");
    // / * Khởi tạo màu vẽ * /
    Init();
    //goi ham hien thi
    glutDisplayFunc(display);
    //kich hoat su kien chuot
    glutMouseFunc(myMouseFunc);
    //tiep tuc hoat dong cho den khi chuong trinh dong
    glutMainLoop();
}