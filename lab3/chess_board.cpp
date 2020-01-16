#include <GL/glut.h>

void myDisplay(void);
void myInit(void);


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("hello");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

	return 0;
}

void myInit(void)
{
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(10);
	glutInitDisplayMode(GLUT_SINGLE | GL_RGB);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 120, 0, 120);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int counter = 0;
	for (GLint x = 0; x < 120; x += 15)
	{
		for (GLint y = 0; y < 120; y += 15)
		{
			if (((x + y) / 15) & 1){
				glColor3f(.6, .6, .6);
			}
			else{
				glColor3f(.2, .2, .2);
			}
			glRecti(x, y, (x + 15), (y + 15));
		}//end of y		
	}//end of x 
	glFlush();
}