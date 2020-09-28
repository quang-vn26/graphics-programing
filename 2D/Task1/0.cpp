#include <GL/glut.h>
// (or others, depending on the system in use)
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
// Set display-window color to white.
    glMatrixMode (GL_PROJECTION);
// Set projection parameters.
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}
void lineSegment (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin (GL_LINES);
    glVertex2i (180, 15);
    glVertex2i (10, 145);
    glEnd ( );
    glFlush ( );
// Clear display window.
// Set line segment color to green.
// Specify line-segment geometry.
// Process all OpenGL routines as quickly as possible.
}
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
// Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
// Set display mode.
    glutInitWindowPosition (50, 100);
// Set top-left display-window position.
    glutInitWindowSize (400, 300);
// Set display-window width and height.
    glutCreateWindow ("An Example OpenGL Program"); // Create display window.
    init ( );
    glutDisplayFunc (lineSegment);
    glutMainLoop ( );
// Execute initialization procedure.
// Send graphics to display window.
// Display everything and wait.
}