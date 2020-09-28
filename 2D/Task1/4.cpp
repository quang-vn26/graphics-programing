////parabol

// sin(x)
#include<GL/glut.h>
#include<math.h>


const GLfloat factor =0.1f;

void myDisplay(void)
{
    GLfloat x;

    glClear(GL_COLOR_BUFFER_BIT);

    {

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        {
            // x-axis
            glVertex3f(-100.0f, 0.0f, 0.0f);
            glVertex3f(100.0f, 0.0f, 0.0f);

            // y-axis
            glVertex3f(0.0f, -100.0f, 0.0f);
            glVertex3f(0.0f, 100.0f, 0.0f);

            glEnd();
            glBegin(GL_LINE_STRIP);
            for (x = -2.0f / factor; x < 2.0f / factor; x += 0.005f)
            {
                glVertex2f((x*factor)/4, sin(x)/(x));
            }
            glEnd();
            glFlush();
        }
    }

    glFlush();
    glutSwapBuffers();
}




int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Sin(x)");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;

}



//#include <GL/glut.h>
//void init() {
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//    glColor3f(0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, 480, 0, 640);
//}
//
//void display() {
//    GLfloat midY = 240;
//    GLfloat midX = 320;
//
//    GLfloat y = 0;
//
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POINTS);
//    for(GLfloat x = -400; x <= 400; x+=0.05) {
//        y = x*x;
//        glVertex2f(midX + x, midY + y);
//    }
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowPosition(200, 400);
//    glutInitWindowSize(640, 480);
//    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
//    glutCreateWindow("parabol");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}