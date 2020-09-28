
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float	tx	=  10.0;
static float	ty	=  0.0;
static float r=1;
static float g=1;
static float b=1 ;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    //glRotatef(spin, 0.0, 0.0, 1.0);



    glColor3f(r, g, b);

    glTranslatef(tx,ty,0);
    //glColor3f(0.0, 0.1, 0.0);
//			glRotatef(_angle, x, y, z);
    glutSolidTorus(1.0, 20.2, 10, 100); // inner radius, outer radius, sides, segments


    glRectf(-13.5, -13.5, 13.5, 13.5);
    glPopMatrix();

    glFlush();
}

void spinDisplay_left(void)
{
    spin = 5;
    glutPostRedisplay();
    glRotatef(spin, 0.0, 0.0, 1.0);
}

void spinDisplay_right(void)
{
    spin = -5;
    glutPostRedisplay();
    glRotatef(spin, 0.0, 0.0, 1.0);

}


void init(void)
{
    glClearColor (1.0, 0.0, 0.0, 0.0);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

    switch (key) {

        case 'l':
            spinDisplay_left();
            break;

        case 'r':
            spinDisplay_right();
            break;

        case 's':
            glutIdleFunc(NULL);
            break;

        default:
            break;
    }
}

void spe_key(int key, int x, int y)
{

    switch (key) {


        case GLUT_KEY_LEFT:
            tx -=5;
            r=1;
            g=0;
            b=1;
            glutPostRedisplay();
            break;

            //spinDisplay_left();
            //break;

        case GLUT_KEY_RIGHT:
            tx +=5;
            r=0;
            g=1;
            b=0;
            //glColor3f (0.0, 0.0, 1.0);
            glutPostRedisplay();
            break;

            //spinDisplay_right();
            //break;

        case GLUT_KEY_UP:
            ty +=5;
            r=0;
            g=0;
            b=1;
            //glColor3f (0.0, 0.0, 1.0);
            glutPostRedisplay();
            break;


        case GLUT_KEY_DOWN:
            ty -=5;
            r=1;
            g=1;
            b=0;
            //glColor3f (0.0, 0.0, 1.0);
            glutPostRedisplay();
            break;

        default:
            break;
    }
}


void my_mouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay_left);
            break;
        case GLUT_MIDDLE_BUTTON:
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay_right);
            //glutIdleFunc(NULL); // make idle function inactive
            break;
        default:
            break;
    }
}


int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("mist");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
//	glutReshapeFunc(my_reshape);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}