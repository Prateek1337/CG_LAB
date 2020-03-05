
// #include <windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

void display();
using namespace std;
float xmin=-100;
float ymin=-100;
float xmax=100;
float ymax=100;
float xa,ya,xb,yb,xc,yc;
float x[6],y[6];


void init(void)
{

    glClearColor(0.0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300,300,-300,300);

}

int code(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void cohen_Line1(float x1,float y1,float x2,float y2)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    int txa=x1,tya=y1,txb=x2,tyb=y2;
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
          xa=0,xb=0,ya=0,yb=0;
           return ;
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else{
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else{
         if((c & 2)>0)
         {
             x=xmax;
             y=yi+m*(xmax-xi);
         }
         else{
           if((c & 1)>0)
           {
               x=xmin;
               y=yi+m*(xmin-xi);
           }
         }
       }
     }

       if(c==c1)
       {
           xa=x;
           ya=y;
           c1=code(xa,ya);
       }

       if(c==c2)
       {
           xb=x;
           yb=y;
           c2=code(xb,yb);
       }
}
x[0]=xa;
x[1]=xb;
y[0]=ya;
y[1]=yb;
xa=txa;
xb=txb;
ya=tya;
yb=tyb;
}


void cohen_Line2(float x1,float y1,float x2,float y2)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    int txa=x1,tya=y1,txb=x2,tyb=y2;
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
          xa=0,xc=0,ya=0,yc=0;
           return ;
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else{
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else{
         if((c & 2)>0)
         {
             x=xmax;
             y=yi+m*(xmax-xi);
         }
         else{
           if((c & 1)>0)
           {
               x=xmin;
               y=yi+m*(xmin-xi);
           }
         }
       }
     }

       if(c==c1)
       {
           xa=x;
           ya=y;
           c1=code(xa,ya);
       }

       if(c==c2)
       {
           xc=x;
           yc=y;
           c2=code(xc,yc);
       }
}
x[2]=xa;
x[3]=xc;
y[2]=ya;
y[3]=yc;
xa=txa;
xc=txb;
ya=tya;
yc=tyb;

}

void cohen_Line3(float x1,float y1,float x2,float y2)
{
    int c1=code(x1,y1);
    int c2=code(x2,y2);
    float m=(y2-y1)/(x2-x1);
    int txa=x1,tya=y1,txb=x2,tyb=y2;
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
          xb=0,xc=0,yb=0,yc=0;
           return ;
        }

    float xi=x1;float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else{
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else{
         if((c & 2)>0)
         {
             x=xmax;
             y=yi+m*(xmax-xi);
         }
         else{
           if((c & 1)>0)
           {
               x=xmin;
               y=yi+m*(xmin-xi);
           }
         }
       }
     }

       if(c==c1)
       {
           xb=x;
           yb=y;
           c1=code(xb,yb);
       }

       if(c==c2)
       {
           xc=x;
           yc=y;
           c2=code(xc,yc);
       }
}
x[4]=xb;
x[5]=xc;
y[4]=yb;
y[5]=yc;
xb=txa;
xc=txb;
yb=tya;
yc=tyb;
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
   glColor3f(1.0,0.0,1.0);
 glBegin(GL_LINES);
   glVertex2i(x[0],y[0]);
   glVertex2i(x[1],y[1]);
   glVertex2i(x[2],y[2]);
   glVertex2i(x[3],y[3]);
   glVertex2i(x[4],y[4]);
   glVertex2i(x[5],y[5]);
   glEnd();
   glFlush();

}

void mykey(unsigned char key,int x,int y)
{
    if(key=='c')
    {  cout<<"Hello";
        cohen_Line1(xa,ya,xb,yb);
        cohen_Line2(xa,ya,xc,yc);
        cohen_Line3(xb,yb,xc,yc);
        glFlush();
    }
}
void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();
   glColor3f(1.0,0.0,1.0);
   glBegin(GL_LINES);
   glVertex2i(xa,ya);
   glVertex2i(xb,yb);
   glVertex2i(xa,ya);
   glVertex2i(xc,yc);
   glVertex2i(xb,yb);
   glVertex2i(xc,yc);
   glEnd();
   glFlush();

}


int main(int argc,char** argv)
{
    printf("Enter triangle co-ordinates1:");
    cin>>xa>>ya;
    printf("Enter triangle co-ordinates2:");
    cin>>xb>>yb;
    printf("Enter triangle co-ordinates3:");
    cin>>xc>>yc;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}