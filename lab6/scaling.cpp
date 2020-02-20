#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500, 500, -500, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void setPixel(GLint x,GLint y)
{
  glBegin(GL_POINTS);
     glVertex2i(x,y);
  glEnd();
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

  glFlush();
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
	glFlush();
}
void drawTriangle(int x1,int x2,int x3,int y1,int y2,int y3)
{

        glBegin(GL_POLYGON);
                glVertex2f(x1, y1);
                glVertex2f(x2, y2);
                glVertex2f(x3, y3);
        glEnd();
        glFlush();
}
int f1=1,f2=1,t;

void myDisplay() {
	// glClearColor(0.0, 0.0, 0.0, 1.0);
	// glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,0, 0);
	if(t==0){
		draw_line(0*f1,100*f1,0*f2,100*f2);
		printf("Enter factor\n");
		scanf("%d%d",&f1,&f2);
		glutPostRedisplay();

	}
	else if(t==1){
		Circle(0,0,(f1+f2)*100);
			printf("Enter factor\n");
		scanf("%d%d",&f1,&f2);
		glutPostRedisplay();

	}
	else{
		drawTriangle(-100*f1,100*f1,0*f1,100*f2,100*f2,0*f2);
		printf("Enter factor\n");
		scanf("%d%d",&f1,&f2);
		glutPostRedisplay();
	}
}

int main(int argc, char **argv) {
	scanf("%d",&t);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}