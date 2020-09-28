//ve duong thang
#include <GL/glut.h>
int x1=0;
int y1=0;
int x2=250;
int y2=150;

void lineBres(int x1, int y1, int x2, int y2){
    int Dx,Dy,P,x,y,const1,const2;
    Dx=x2-x1;	Dy=y2-y1;
    const1=2*Dy;	const2=2*(Dy-Dx);
    P=2*Dy-Dx;
    x=x1;		y=y1;
    glBegin(GL_POINTS);
    while (x<=x2)
    {
        glVertex3i(x,y,0);

        if (P<0)
            P+=const1;
        else
        {
            P+=const2;
            y++;
        }
        x++;
    }
    glEnd();
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    lineBres(x1, y1, x2, y2);
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* khởi tạo chế độ vẽ single buffer và hệ màu RGB */
    glutInitWindowSize (600, 600); /* khởi tạo window kích thước 250 x 250 */
    glutInitWindowPosition (10, 10); /* khởi tạo window tại ví trí (100,100) trên screen */
    glutCreateWindow("VE DUONG THANG DUNG TT BRESENHAM");

    glClearColor(1.0,1.0,1.0,0.0);
    glOrtho(-300, 300, -300, 300, -1.0, 1.0);
    glutDisplayFunc(mydisplay);
    glutMainLoop();
}