#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
void drawTriangle()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
   // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex2f(-0.5, 0.75);
                glVertex2f(-0.75, 0.25);
                glVertex2f(-0.25, 0.25);
        glEnd();

        int v;
        float pent[5][2], ang, da = 6.2832 / 5.0;   // da is central angle between vertices in radians

        for (v = 0; v < 5; v++)  {                  // Computes vertex coordinates.
            ang = v * da;
            pent[v][0] = 0.3*cos (ang)+0.5;
            pent[v][1] = 0.3*sin (ang)+0.5;
        }

        glBegin (GL_POLYGON);                                         // Draws pentagon.
           for (v = 0; v < 5; v++)  glVertex2fv(pent[v]);
        glEnd();


    glBegin (GL_POLYGON);                                         // Draws pentagon.
        glVertex2f(-0.25, 0);
        glVertex2f(0.25, 0);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();




    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating  triangle");
    glutDisplayFunc(drawTriangle);
    glutMainLoop();
    return 0;
}