#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>


#define pi 3.14159
// void drawHollowCircle(){
//     GLfloat x=0,y=0,radius=5;
//     int i;
//     int lineAmount = 2*PI; //# of triangles used to draw circle
    
//     //GLfloat radius = 0.8f; //radius
//     GLfloat twicePi = 2.0f * PI;
//     glClearColor(0.0, 0.0, 0.0, 1.0);
//     glClear(GL_COLOR_BUFFER_BIT);
//     // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

//     glColor3f(1.0, 0.5, 1.0);
//     glBegin(GL_LINE_LOOP);
//         for(i = 0; i <= lineAmount;i+=0.001) { 
//             glVertex2f(
//                 x + (radius * cos(i)), 
//                 y + (radius* sin(i))
//             );
//         }
//     glEnd();
//     glFlush();
// }

void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(0.0, 1.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 
} 
  
void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    float x, y, i; 
      
    // iterate y up to 2*pi, i.e., 360 degree 
    // with small increment in angle as 
    // glVertex2i just draws a point on specified co-ordinate 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x = 200 * cos(i); 
        y = 200 * sin(i); 
          
        glVertex2i(x, y); 
    } 
    glEnd(); 
    glFlush(); 
} 

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating Circle");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}