#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define  RADDEG  57.29577951f

float XUP[3] = {1,0,0}, XUN[3] = {-1, 0, 0},
      YUP[3] = {0,1,0}, YUN[3] = { 0,-1, 0},
      ZUP[3] = {0,0,1}, ZUN[3] = { 0, 0,-1},
      ORG[3] = {0,0,0};

GLfloat viewangle = 0, tippangle = 0, traj[120][3];

GLfloat d[3] = {0.1, 0.1, 0.1};

GLfloat  xAngle = 0.0, yAngle = 0.0, zAngle = 0.0;




typedef float Matrix4x4 [4][4];
Matrix4x4 theMatrix;
float ptsIni[8][3]={{180,180,-200},{280,180,-200},{280,280,-200},{180,280,-200},
                    {160,160,100},{260,160,100},{260,260,100},{160,260,100}};
float ptsFin[8][3];
float refptX,refptY,refptZ;                   
float TransDistX,TransDistY,TransDistZ;       
float ScaleX,ScaleY,ScaleZ;                   
float Alpha,Beta,Gamma,Theta;                 
float A,B,C;                                  
float aa,bb,cc;                              
float x1,y11,z1,x2,y2,z2;
int choice,choiceRot,choiceRef;
float sx=0.2,sy=0.2,sz=0.2;
void matrixSetIdentity(Matrix4x4 m)   
{
 int i, j;
 for (i=0; i<4; i++)
 for (j=0; j<4; j++)
 m[i][j] = (i == j);
}      

void matrixPreMultiply(Matrix4x4 a , Matrix4x4 b)                                                  
{
 int i,j;
 Matrix4x4 tmp;
 for (i = 0; i < 4; i++)
 for (j = 0; j < 4; j++)
 tmp[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j]+a[i][3]*b[3][j];
 for (i = 0; i < 4; i++)
 for (j = 0; j < 4; j++)
 theMatrix[i][j] = tmp[i][j];
}
void Translate(int tx, int ty, int tz)
{
 Matrix4x4 m;
 matrixSetIdentity(m);
 m[0][3] = tx;
 m[1][3] = ty;
 m[2][3] = tz;
 matrixPreMultiply(m, theMatrix);
}
void Scale(float sx , float sy ,float sz)
{
 Matrix4x4 m;
 matrixSetIdentity(m);
 m[0][0] = sx;
 m[0][3] = (1 - sx)*refptX;
 m[1][1] = sy;
 m[1][3] = (1 - sy)*refptY;
 m[2][2] = sz;
 m[2][3] = (1 - sy)*refptZ;
 matrixPreMultiply(m , theMatrix);
}
void RotateX(float angle)
{
 Matrix4x4 m;
 matrixSetIdentity(m);
 angle = angle*22/1260;
 m[1][1] = cos(angle);
 m[1][2] = -sin(angle);
 m[2][1] = sin(angle);
 m[2][2] = cos(angle);
 matrixPreMultiply(m , theMatrix);
}
void RotateY(float angle)
{
 Matrix4x4 m;
 matrixSetIdentity(m);
 angle = angle*22/1260;
 m[0][0] = cos(angle);
 m[0][2] = sin(angle);
 m[2][0] = -sin(angle);
 m[2][2] = cos(angle);
 matrixPreMultiply(m , theMatrix);
}
void RotateZ(float angle)
{
 Matrix4x4 m;
 matrixSetIdentity(m);
 angle = angle*22/1260;
 m[0][0] = cos(angle);
 m[0][1] = -sin(angle);
 m[1][0] = sin(angle);
 m[1][1] = cos(angle);
 matrixPreMultiply(m , theMatrix);
}


void Special_Keys (int key, int x, int y)
{
       

    switch (key) {


  
       

       case GLUT_KEY_LEFT :  viewangle -= 5; RotateX(Alpha); break;
       case GLUT_KEY_RIGHT:  viewangle += 5;  RotateY(Alpha);break;
       case GLUT_KEY_UP   :  tippangle -= 5;  RotateZ(Alpha);break;
       case GLUT_KEY_DOWN :  tippangle += 5;  RotateZ(Alpha);break;

       default: printf ("   Special %c == %d", key, key);
    }

    glutPostRedisplay();
}



void Keyboard (unsigned char key, int x, int y)
{
    switch (key) {

       case 'x' : d[0] += 0.1; Translate(TransDistX , TransDistY ,TransDistZ); break;
       case 'y' : d[1] += 0.1;  Translate(TransDistX , TransDistY ,TransDistZ);break;
       case 'z' : d[2] += 0.1; Translate(TransDistX , TransDistY ,TransDistZ); break;
       case 'q' : sx+=0.1; Scale(sx ,sy ,sz);break;
       case 'w' : sy+=0.1; Scale(sx ,sy ,sz);break;
       case 'e' : sz+=0.1;Scale(sx ,sy ,sz);break;

       default: printf ("   Keyboard %c == %d", key, key);
    }

    glutPostRedisplay();
}


void CUBE(void)
{
  glColor3f  ( 1.0,  0.0, 0.0); 
    glBegin (GL_QUADS);   
      glVertex3f (-1.0,  1.0, 1.0);
      glVertex3f ( 1.0,  1.0, 1.0);
      glVertex3f ( 1.0, -1.0, 1.0);
      glVertex3f (-1.0, -1.0, 1.0);

      glVertex3f (-1.0,  1.0, -1.0);
      glVertex3f ( 1.0,  1.0, -1.0);
      glVertex3f ( 1.0, -1.0, -1.0);
      glVertex3f (-1.0, -1.0, -1.0);

    
      glVertex3f (-1.0, 1.0,  1.0);
      glVertex3f ( 1.0, 1.0,  1.0);
      glVertex3f ( 1.0, 1.0, -1.0);
      glVertex3f (-1.0, 1.0, -1.0);

      glVertex3f (-1.0, -1.0,  1.0);
      glVertex3f ( 1.0, -1.0,  1.0);
      glVertex3f ( 1.0, -1.0, -1.0);
      glVertex3f (-1.0, -1.0, -1.0);

    glEnd();
}

void pyramid(){

   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
}

void redraw (void)
{
    int v;

    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST);

    glLoadIdentity ();

    glTranslatef (0, 0, -3);
    glRotatef (tippangle, 1,0,0);  
    glRotatef (viewangle, 0,1,0); 

    glDisable (GL_LIGHTING);


    glPushMatrix ();
       glTranslatef (d[0], d[1], d[2]); 
       glScalef (sx, sy, sz);
       glRotatef (zAngle, 0,0,1);
       glRotatef (yAngle, 0,1,0);
       glRotatef (xAngle, 1,0,0);
       CUBE ();
    glPopMatrix ();

    glPushMatrix ();
       glTranslatef (d[0], d[1], d[2]); 
       glScalef (sx, sy, sz);
       glRotatef (zAngle, 0,0,1);
       glRotatef (yAngle, 0,1,0);
       glRotatef (xAngle, 1,0,0);
       pyramid();
    glPopMatrix ();



    glutSwapBuffers();
}
int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitWindowSize     (900, 600);
    glutInitWindowPosition (300, 300);
    glutInitDisplayMode    (GLUT_DEPTH | GLUT_DOUBLE);

    glutCreateWindow ("CUBE");
    glutDisplayFunc  (   redraw   );
    glutKeyboardFunc (  Keyboard  );
    glutSpecialFunc  (Special_Keys);

    glClearColor (0.1, 0.0, 0.1, 1.0);

    glMatrixMode   (GL_PROJECTION);
    gluPerspective (60, 1.5, 1, 10);
    glMatrixMode   (GL_MODELVIEW);
    glutMainLoop   ();

   
    return 1;
}





