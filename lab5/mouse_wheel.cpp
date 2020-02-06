#include <GL/glut.h>
#include <stdio.h>
#include <math.h>


GLfloat angle = 0.0f;  // rotational angle of the shapes
float dis=0;
int refreshMills = 1; // refresh interval in milliseconds
int dir=1;

void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}














void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,500,500,0);
}

void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
}
void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x,y;

  dx = x2-x1;
  dy = y2-y1;

  if (dx < 0) dx = -dx;
  if (dy < 0) dy = -dy;
  incx = 1;
  if (x2 < x1) incx = -1;
  incy = 1;
  if (y2 < y1) incy = -1;
  x = x1; y = y1;
  if (dx > dy) {
    draw_pixel(x, y);
    e = 2 * dy-dx;
    inc1 = 2*(dy-dx);
    inc2 = 2*dy;
    for (i=0; i<dx; i++) {
      if (e >= 0) {
        y += incy;
        e += inc1;
      }
      else
        e += inc2;
      x += incx;
      draw_pixel(x, y);
    }

  } else {
    draw_pixel(x, y);
    e = 2*dx-dy;
    inc1 = 2*(dx-dy);
    inc2 = 2*dx;
    for (i=0; i<dy; i++) {
      if (e >= 0) {
        x += incx;
        e += inc1;
      }
      else
        e += inc2;
      y += incy;
      draw_pixel(x, y);
    }
  }
}


void Circle(int xCenter,int yCenter,int r){
 
  int x=0,y=r;
  int d = 3 - 2*r;    // = 1 - r
  while(x<=y){
    setPixel(xCenter+x,yCenter+y);
    setPixel(xCenter+y,yCenter+x);  //find other points by symmetry
    setPixel(xCenter-x,yCenter+y);
    setPixel(xCenter+y,yCenter-x);
    setPixel(xCenter-x,yCenter-y);
    setPixel(xCenter-y,yCenter-x);
    setPixel(xCenter+x,yCenter-y);
    setPixel(xCenter-y,yCenter+x);

    if (d<0)
      d += (4*x)+6;
    else {
      d += (4*(x-y))+10;
        y -= 1;
    }
    x++;
  }

  // glFlush();
}
float root2=sqrt(2);

void wheel(int xCenter,int yCenter,int r1,int r2){
    Circle(xCenter,yCenter,r1);
    Circle(xCenter,yCenter,r2);
    glPushMatrix();
    glTranslatef(xCenter,yCenter,0);
    glRotatef(angle,0.0f,0.0f,1.0f);
    draw_line(0,0,r1,r2);
    draw_line(0,0,-r1,-r2);
    draw_line(r1,r2,0,0);
    draw_line(-r1,-r2,0,0);
        r1=r1/root2,r2=r2/root2;
       draw_line(r1,r2,r1,r2);
      draw_line(-r1,-r2,r1,r2);
      draw_line(r1,r2,-r1,-r2);
      draw_line(-r1,-r2,-r1,-r2);
    glEnd();
    glPopMatrix();

}
int r1=10,r2=50;
int inc=5;
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1 ,0, 0);
    glFlush();

}

void myclear(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1 ,0, 0);
  glFlush();
}
void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 'i':
      printf("%s","I clicked");
          r1+=inc;
          r2+=inc;
        break;
        case 'd':
          r1-=inc;
          r2-=inc;
          if(r1<0)
            r1=0;
          if(r2<0)
            r2=0;
            break;
        case 'c':
        myclear();
        break;
   }
}
void mouse(int button, int state, int x, int y) {
   printf("%d %d\n",x,y);
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Pause/resume
      wheel(x,y,r1,r2);
   }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // Pause/resume
      exit(0);
   }
   glFlush();

}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Mouse wheel");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);   // Register callback handler for special-key event
    glutMouseFunc(mouse);   // Register callback handler for mouse event
    glutMainLoop();
    return 0;
}