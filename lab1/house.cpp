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

// void myInit (void) 
// { 
//     // making background color black as first  
//     // 3 arguments all are 0.0 
   
      
//     // breadth of picture boundary is 1 pixel 
//     glPointSize(1.0); 
//     glMatrixMode(GL_PROJECTION);  
//     glLoadIdentity(); 
      
//     // setting window dimension in X- and Y- direction 
//     gluOrtho2D(-780, 780, -420, 420); 
// } 
  
void display (void)  
{ 
         glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(1, 1.0, 0.0);  

    glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
                glVertex2f(-1, 0);
                glVertex2f(-0.5, 0);
                glVertex2f(-0.75, 0.5);
        glEnd();
        glBegin(GL_TRIANGLES);
                glVertex2f(-0.5, 0);
                glVertex2f(0, 0);
                glVertex2f(-0.25, 0.5);
        glEnd();
        glBegin(GL_TRIANGLES);
                glVertex2f(0, 0);
                glVertex2f(0.5, 0);
                glVertex2f(0.25, 0.5);
        glEnd();
        glBegin(GL_TRIANGLES);
                glVertex2f(0.5, 0);
                glVertex2f(1, 0);
                glVertex2f(0.75, 0.5);
        glEnd();
    glColor3f(1, 0, 0.0);  

        glBegin(GL_TRIANGLES);
                glVertex2f(-0.25, -0.25);
                glVertex2f(0.25, -0.25);
                glVertex2f(0, 0);
        glEnd();
        glColor3f(0, 1, 0.0);  

         glBegin(GL_QUADS);
                glVertex2f(-0.25, -0.25);
                glVertex2f(0.25, -0.25);
                glVertex2f(0.25, -0.5);
                glVertex2f(-0.25, -0.5);
        glEnd();

        glColor3f(0, 0, 1);  
        glBegin(GL_QUADS);
                glVertex2f(-0.05, -0.375);
                glVertex2f(0.05, -0.375);
                glVertex2f(0.05, -0.5);
                glVertex2f(-0.05, -0.5);
        glEnd();
        glBegin(GL_QUADS);
                glVertex2f(-0.175, -0.3);
                glVertex2f(-0.1, -0.3);
                glVertex2f(-0.1, -0.375);
                glVertex2f(-0.175, -0.375);
        glEnd();
        glBegin(GL_QUADS);
                glVertex2f(0.05+0.175, -0.3);
                glVertex2f(0.05+0.1, -0.3);
                glVertex2f(0.05+0.1, -0.375);
                glVertex2f(0.05+0.175, -0.375);
        glEnd();
        glColor3f(0, 1, 1);  
        glBegin(GL_LINES);
                 glVertex2f(-0.05, -0.55);
                glVertex2f(0.05, -0.55);
                glVertex2f(0.05, -0.6);
                glVertex2f(-0.05, -0.6);
                glVertex2f(0.05, -0.65);
                glVertex2f(-0.05, -0.65);
        glEnd();
    glFlush(); 
    glFlush(); 
} 
 
// void display (void)  
// { 
//     glClear(GL_COLOR_BUFFER_BIT); 
//     glBegin(GL_POINTS); 
//     float x, y, i; 
      
//     // iterate y up to 2*pi, i.e., 360 degree 
//     // with small increment in angle as 
//     // glVertex2i just draws a point on specified co-ordinate 
//     for ( i = 0; i < (2 * pi); i += 0.001) 
//     { 
//         // let 200 is radius of circle and as, 
//         // circle is defined as x=r*cos(i) and y=r*sin(i) 
//         x = 200 * cos(i); 
//         y = 200 * sin(i); 
          
//         glVertex2i(x, y); 
//     } 
//     glEnd(); 
//     glFlush(); 
// } 


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - Creating  triangle");
    // myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}