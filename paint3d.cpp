#include <stdio.h>
#include <iostream>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <fstream>
int m1,m2,n1,n2,option;
using namespace std;
void display();
void swap();
void basic();
float DEG2RAD = 3.14159/180.0;
ofstream fout;
ifstream fin;
GLubyte screencap[1000][1000][3];
GLubyte color[3] = {255,255,255};

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

void store_screen()
{
glReadPixels(0,0,1000,1000,GL_RGB,GL_UNSIGNED_BYTE,screencap);
}

void restore_screen()
{
glRasterPos2i(0,1000);
        glDrawPixels(1000,1000,GL_RGB,GL_UNSIGNED_BYTE,screencap);
        glFlush();
}

void open()
{
char *file1=(char*)malloc(100);
cout << "Enter the file name:" << endl;
cin >> file1;
fin.open(file1);
fin.read((char*)screencap, sizeof(screencap));
restore_screen();
fin.close();			
}


void cube()
{
glColor3ub(color[0], color[1], color[2]);
float dist;
dist=sqrt(((m1-m2)*(m1-m2))+((n1-n2)*(n1-n2)))/(float)sqrt(3);
//For Cube
if(m1 < m2 && n1 < n2)
{
glBegin(GL_LINES);
//First Square
glVertex2f(m1,n1);
glVertex2f(m1+dist,n1);
glVertex2f(m1,n1);
glVertex2f(m1,n1+dist);
glVertex2f(m1+dist,n1);
glVertex2f(m1+dist,n1+dist);
glVertex2f(m1+dist,n1+dist);
glVertex2f(m1,n1+dist);

//Second Square
glVertex2f(m2,n2);
glVertex2f(m2-dist,n2);
glVertex2f(m2,n2);
glVertex2f(m2,n2-dist);
glVertex2f(m2-dist,n2);
glVertex2f(m2-dist,n2-dist);
glVertex2f(m2-dist,n2-dist);
glVertex2f(m2,n2-dist);
glEnd();
//Dotted Lines
glBegin(GL_LINES);
glVertex2f(m1,n1);
glVertex2f(m2-dist,n2-dist);
glVertex2f(m2,n2);
glVertex2f(m1+dist,n1+dist);
glVertex2f(m1+dist,n1);
glVertex2f(m2,n2-dist);
glVertex2f(m2-dist,n2);
glVertex2f(m1,n1+dist);
glEnd();
}
	else if(m1 > m2 && n1 > n2)
	{
	glBegin(GL_LINES);
	//First Square
	glVertex2f(m2,n2);
	glVertex2f(m2+dist,n2);
	glVertex2f(m2,n2);
	glVertex2f(m2,n2+dist);
	glVertex2f(m2+dist,n2);
	glVertex2f(m2+dist,n2+dist);
	glVertex2f(m2+dist,n2+dist);
	glVertex2f(m2,n2+dist);
	
	//Second Square
	glVertex2f(m1,n1);
	glVertex2f(m1-dist,n1);
	glVertex2f(m1,n1);
	glVertex2f(m1,n1-dist);
	glVertex2f(m1-dist,n1);
	glVertex2f(m1-dist,n1-+dist);
	glVertex2f(m1-dist,n1-dist);
	glVertex2f(m1,n1-dist);
	glEnd();

	//Dotted Lines
	glBegin(GL_LINES);
	glVertex2f(m2,n2);
	glVertex2f(m1-dist,n1-dist);	
	glVertex2f(m1,n1);
	glVertex2f(m2+dist,n2+dist);
	glVertex2f(m2+dist,n2);
	glVertex2f(m1,n1-dist);
	glVertex2f(m1-dist,n1);
	glVertex2f(m2,n2+dist);
	glEnd();

	}
	else if(m2 > m1 && n2 < n1)
	{
	glBegin(GL_LINES);
	//First Square
	glVertex2f(m2,n2);
	glVertex2f(m2-dist,n2);
	glVertex2f(m2,n2);
	glVertex2f(m2,n2+dist);
	glVertex2f(m2-dist,n2);
	glVertex2f(m2-dist,n2+dist);
	glVertex2f(m2-dist,n2+dist);
	glVertex2f(m2,n2+dist);
	
	//Second Square
	glVertex2f(m1,n1);
	glVertex2f(m1+dist,n1);
	glVertex2f(m1,n1);
	glVertex2f(m1,n1-dist);
	glVertex2f(m1+dist,n1);
	glVertex2f(m1+dist,n1-dist);
	glVertex2f(m1+dist,n1-dist);
	glVertex2f(m1,n1-dist);
	glEnd();

	//Dotted Lines
	glBegin(GL_LINES);
	glVertex2f(m1,n1);
	glVertex2f(m2-dist,n2+dist);	
	glVertex2f(m2,n2);
	glVertex2f(m1+dist,n1-dist);
	glVertex2f(m1+dist,n1);
	glVertex2f(m2,n2+dist);
	glVertex2f(m1,n1-dist);
	glVertex2f(m2-dist,n2);
	glEnd();

	}
	
	else 
	{
	glBegin(GL_LINES);
	//First Square
	glVertex2f(m1,n1);
	glVertex2f(m1-dist,n1);
	glVertex2f(m1,n1);
	glVertex2f(m1,n1+dist);
	glVertex2f(m1-dist,n1);
	glVertex2f(m1-dist,n1+dist);
	glVertex2f(m1-dist,n1+dist);
	glVertex2f(m1,n1+dist);
	
	//Second Square
	glVertex2f(m2,n2);
	glVertex2f(m2+dist,n2);
	glVertex2f(m2,n2);
	glVertex2f(m2,n2-dist);
	glVertex2f(m2+dist,n2);
	glVertex2f(m2+dist,n2-dist);
	glVertex2f(m2+dist,n2-dist);
	glVertex2f(m2,n2-dist);
	glEnd();

	//Dotted Lines
	glBegin(GL_LINES);
	glVertex2f(m2,n2);
	glVertex2f(m1-dist,n1+dist);	
	glVertex2f(m1,n1);
	glVertex2f(m2+dist,n2-dist);
	glVertex2f(m2+dist,n2);
	glVertex2f(m1,n1+dist);
	glVertex2f(m2,n2-dist);
	glVertex2f(m1-dist,n1);
	glEnd();

	}


glFlush();
}


void cuboid()
{
float dist;
float l,b,h;
dist=sqrt(((m1-m2)*(m1-m2))+((n1-n2)*(n1-n2)))/(float)sqrt(14);
l=3*dist;
b=2*dist;
h=dist;
//For Cube
if(m1 < m2 && n1 < n2)
{
glColor3ub(color[0], color[1], color[2]);
glBegin(GL_LINES);
//First Square
glVertex2f(m1,n1);
glVertex2f(m1+l,n1);
glVertex2f(m1,n1);
glVertex2f(m1,n1+h);
glVertex2f(m1+l,n1);
glVertex2f(m1+l,n1+h);
glVertex2f(m1+l,n1+h);
glVertex2f(m1,n1+h);

//Second Square
glVertex2f(m2,n2);
glVertex2f(m2-l,n2);
glVertex2f(m2,n2);
glVertex2f(m2,n2-h);
glVertex2f(m2-l,n2);
glVertex2f(m2-l,n2-h);
glVertex2f(m2-l,n2-h);
glVertex2f(m2,n2-h);
glEnd();
//Dotted Lines
glBegin(GL_LINES);
glVertex2f(m1,n1);
glVertex2f(m2-l,n2-h);
glVertex2f(m2,n2);
glVertex2f(m1+l,n1+h);
glVertex2f(m1+l,n1);
glVertex2f(m2,n2-h);
glVertex2f(m2-l,n2);
glVertex2f(m1,n1+h);
glEnd();
}
else if(m1 > m2 && n1 > n2)
	{
	glBegin(GL_LINES);
	//First Square
	glVertex2f(m2,n2);
	glVertex2f(m2+l,n2);
	glVertex2f(m2,n2);
	glVertex2f(m2,n2+h);
	glVertex2f(m2+l,n2);
	glVertex2f(m2+l,n2+h);
	glVertex2f(m2+l,n2+h);
	glVertex2f(m2,n2+h);
	
	//Second Square
	glVertex2f(m1,n1);
	glVertex2f(m1-l,n1);
	glVertex2f(m1,n1);
	glVertex2f(m1,n1-h);
	glVertex2f(m1-l,n1);
	glVertex2f(m1-l,n1-h);
	glVertex2f(m1-l,n1-h);
	glVertex2f(m1,n1-h);
	glEnd();

	//Dotted Lines
	glBegin(GL_LINES);
	glVertex2f(m2,n2);
	glVertex2f(m1-l,n1-h);	
	glVertex2f(m1,n1);
	glVertex2f(m2+l,n2+h);
	glVertex2f(m2+l,n2);
	glVertex2f(m1,n1-h);
	glVertex2f(m1-l,n1);
	glVertex2f(m2,n2+h);
	glEnd();

	}
	else if(m2 > m1 && n2 < n1)
	{
	glBegin(GL_LINES);
	//First Square
	glVertex2f(m2,n2);
	glVertex2f(m2-l,n2);
	glVertex2f(m2,n2);
	glVertex2f(m2,n2+h);
	glVertex2f(m2-l,n2);
	glVertex2f(m2-l,n2+h);
	glVertex2f(m2-l,n2+h);
	glVertex2f(m2,n2+h);
	
	//Second Square
	glVertex2f(m1,n1);
	glVertex2f(m1+l,n1);
	glVertex2f(m1,n1);
	glVertex2f(m1,n1-h);
	glVertex2f(m1+l,n1);
	glVertex2f(m1+l,n1-h);
	glVertex2f(m1+l,n1-h);
	glVertex2f(m1,n1-h);
	glEnd();

	//Dotted Lines
	glBegin(GL_LINES);
	glVertex2f(m1,n1);
	glVertex2f(m2-l,n2+h);	
	glVertex2f(m2,n2);
	glVertex2f(m1+l,n1-h);
	glVertex2f(m1+l,n1);
	glVertex2f(m2,n2+h);
	glVertex2f(m1,n1-h);
	glVertex2f(m2-l,n2);
	glEnd();

	}
	
	else 
	{
	glBegin(GL_LINES);
	//First Square
	glVertex2f(m1,n1);
	glVertex2f(m1-l,n1);
	glVertex2f(m1,n1);
	glVertex2f(m1,n1+h);
	glVertex2f(m1-l,n1);
	glVertex2f(m1-l,n1+h);
	glVertex2f(m1-l,n1+h);
	glVertex2f(m1,n1+h);
	
	//Second Square
	glVertex2f(m2,n2);
	glVertex2f(m2+l,n2);
	glVertex2f(m2,n2);
	glVertex2f(m2,n2-h);
	glVertex2f(m2+l,n2);
	glVertex2f(m2+l,n2-h);
	glVertex2f(m2+l,n2-h);
	glVertex2f(m2,n2-h);
	glEnd();

	//Dotted Lines
	glBegin(GL_LINES);
	glVertex2f(m2,n2);
	glVertex2f(m1-l,n1+h);	
	glVertex2f(m1,n1);
	glVertex2f(m2+l,n2-h);
	glVertex2f(m2+l,n2);
	glVertex2f(m1,n1+h);
	glVertex2f(m2,n2-h);
	glVertex2f(m1-l,n1);
	glEnd();

	}

glFlush();
}

void circle(float xc,float yc,float radius,int start,int end)
{

	glBegin(GL_POINTS);
 
	for(int i=start; i < end; i++)
	{
		 float degInRad = i*DEG2RAD;
		glVertex2f(xc+cos(degInRad)*radius,yc+sin(degInRad)*radius);
	} 
	glEnd();
	glFlush();
}


void cone()
{
glColor3ub(color[0], color[1], color[2]);
float h=n2-n1;
float r=h/3.0;
float x1,y1,x2,y2,m;
m=(n2-n1)/(float)(m2-m1);
circle(m2,n2,r,0,360);
x1=m2+((r*m)/(float)(sqrt((m*m)+1)));
y1=n2-(r/(float)(sqrt((m*m)+1)));

x2=m2-((r*m)/(float)(sqrt((m*m)+1)));
y2=n2+(r/(float)(sqrt((m*m)+1)));

glBegin(GL_LINES);
glVertex2f(m1,n1);
glVertex2f(x1,y1);

glVertex2f(m1,n1);
glVertex2f(x2,y2);

glEnd();
glFlush();
}

void cylinder()
{
glColor3ub(color[0], color[1], color[2]);
float h=n2-n1;
float r=h/2.0;
float x1,y1,x2,y2,m;
float z1,t1,z2,t2;
m=(n2-n1)/(float)(m2-m1);
circle(m2,n2,r,0,360);
circle(m1,n1,r,0,360);
x1=m2+((r*m)/(float)(sqrt((m*m)+1)));
y1=n2-(r/(float)(sqrt((m*m)+1)));

x2=m2-((r*m)/(float)(sqrt((m*m)+1)));
y2=n2+(r/(float)(sqrt((m*m)+1)));

z1=m1+((r*m)/(float)(sqrt((m*m)+1)));
z2=n1-(r/(float)(sqrt((m*m)+1)));

t1=m1-((r*m)/(float)(sqrt((m*m)+1)));
t2=n1+(r/(float)(sqrt((m*m)+1)));


glBegin(GL_LINES);
glVertex2f(z1,z2);
glVertex2f(x1,y1);

glVertex2f(t1,t2);
glVertex2f(x2,y2);

glEnd();
glFlush();
}

void line()
{
glColor3ub(color[0], color[1], color[2]);
glBegin(GL_LINES);
glVertex2f(m1,n1);
glVertex2f(m2,n2);
glEnd();
glFlush();
}

void save()
{
char *file=(char*)malloc(100);
cout << "Enter the file name:" << endl;
cin >> file;
fout.open(file);
store_screen();
fout.write((char*)screencap, sizeof(screencap));
fout.close();			
cout << "FIle saved Successfully!" << endl;
}

void crop()
{
if(n1 == n2 || m1 == m2)
return;
glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    for(int i=83;i<1000;i++)
    {
	for(int j=0;j<1000;j++)
	{
	if((i>=m1 && i<=m2 && j>=n1 && j<=n2))
	;
	else
	{
	if(i > 83)
        glVertex2f(i,j);
	}
	}
    }
    glEnd();
	glFlush();

}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN)
		{
		if(x>0 && x<80 && y<30 && y>0)
		option = 1;
	
	if(x>0 && x<80 && y<60 && y>30)
	option = 2;

	if(x>0 && x<80 && y<90 && y>60)
	option=3;

	if(x>0 && x<80 && y<120 && y>90)
	option =4;

	if(x>0 && x<80 && y<150 && y>120)
	option=5;

	if(x>0 && x<80 && y<180 && y>150)
	option=6;
	
	if(x>0 && x<80 && y<210 && y>180)
	option = 7;
	
	if(x>0 && x<80 && y<240 && y>210)
	option=8;

	if(x>0 && x<80 && y<270 && y>240)
	option=9;

	if(x>0 && x<80 && y<300 && y>270)
	option=10;

	if(x>0 && x<80 && y<440 && y>340 )
	{
	glReadPixels(x,1000-y,1,1,GL_RGB,GL_UNSIGNED_BYTE,color);
	}
	
		m1=x;
		n1=y;
		}
		else if(state == GLUT_UP)
		{
		m2=x;
		n2=y;
			
			if(option == 1)
			{
			cube();
			basic();
			}

			if(option == 2)
			{
			cuboid();
			basic();
			}
	
			if(option == 3)
			{
			cone();
			basic();
			}
	
			if(option == 4)
			{
			cylinder();
			basic();
			}
	
		        if(option == 5)
			{
			line();  
			basic(); 
			}

			if(option == 6)
			display();
		
			if(option == 7)
			save();
			
			if(option == 8)
			open();
			
			if(option == 10)
			crop();
		
		}
	
	break;
	default:
	break;
	}
	

}

void motion(int x,int y)
{
m2=x;
n2=y;
if(option == 1)
{
cube();
restore_screen();			
}
if(option == 2)
{
cuboid();
restore_screen();
}

if(option == 3)
{
cone();
restore_screen();
}
		
if(option == 4)
{
cylinder();
restore_screen();
}
		
if(option == 5)
{
line();
restore_screen();
}

if(option == 9)
{
glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	if(x > 83)
	glVertex2f(x,y);
	glEnd();
	glFlush();
}

}

void basic()
{

store_screen();
//End
int i,j;
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,0.0);
glVertex2f(0,0);
glVertex2f(80,0);
glVertex2f(80,1000);
glVertex2f(0,1000);
glEnd();
//TEXT
glColor3f(1.0,1.0,1.0);
glRasterPos3f(20,10,0);
char s[]="CUBE";
for(int k=0;k<4;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s[k]);

glRasterPos3f(20,40,0);
char s2[]="CUBOID";
for(int k=0;k<6;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s2[k]);

glRasterPos3f(20,70,0);
char s3[]="CONE";
for(int k=0;k<4;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s3[k]);

glRasterPos3f(20,100,0);
char s4[]="CYLINDER";
for(int k=0;k<8;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s4[k]);

glRasterPos3f(20,130,0);
char s5[]="LINE";
for(int k=0;k<4;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s5[k]);

glRasterPos3f(20,160,0);
char s6[]="NEW";
for(int k=0;k<3;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s6[k]);

glRasterPos3f(20,190,0);
char s7[]="SAVE";
for(int k=0;k<4;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s7[k]);

glRasterPos3f(20,220,0);
char s8[]="OPEN";
for(int k=0;k<4;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s8[k]);

glRasterPos3f(20,280,0);
char s9[]="CROP";
for(int k=0;k<4;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s9[k]);

glRasterPos3f(20,250,0);
char s10[]="ERASE";
for(int k=0;k<5;k++)
glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_10,s10[k]);

glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,1.0);
		glVertex2i(0,340);
		glColor3f(1.0,0.0,0.0);
		glVertex2i(0,440);
		glColor3f(0.0,1.0,0.0);
		glVertex2i(80,440);
		glColor3f(1.0,1.0,1.0);
		glVertex2i(80,340);
		glEnd();
//end

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2f(80,0);
glVertex2f(80,1000);
glVertex2f(82,1000);
glVertex2f(82,0);
glEnd();
glFlush();
//Toolbar for Dispaly
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2f(0,0);
glVertex2f(80,0);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,30);
glVertex2f(80,30);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,60);
glVertex2f(80,60);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,90);
glVertex2f(80,90);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,120);
glVertex2f(80,120);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,150);
glVertex2f(80,150);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,180);
glVertex2f(80,180);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,210);
glVertex2f(80,210);
glEnd();
glBegin(GL_LINES);
glVertex2f(0,240);
glVertex2f(80,240);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,270);
glVertex2f(80,270);
glEnd();

glBegin(GL_LINES);
glVertex2f(0,300);
glVertex2f(80,300);
glEnd();

glFlush();


}


void display()
{
glClear(GL_COLOR_BUFFER_BIT);
basic();
glFlush();
glutSwapBuffers();
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glOrtho(0.0, 1000.0,1000.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) 
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 1000);
glutInitWindowPosition (10, 10);
glutCreateWindow ("PAINT");
init ();
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutMotionFunc(motion);
glutMainLoop();
return 0;
}
