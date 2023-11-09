
#include <Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<stdlib.h>
#include <math.h>

#include <iostream>
#include <GL/freeglut.h>


void init(void);
void display(void);


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My First OpenGL Application");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glColor3f(0.0, 0.0, 0.1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle) 
{
	double angle, angleInc;
	int k;

	if (n < 3) return;
	angle = rotAngle * 3.14159265 / 180;
	angleInc = 2 * 3.14159265 / n;
	//ini titik pertama
	glVertex2f(radius * cos(angle) + cx, radius * sin(angle)+cx);

	//ini titik berikutnya
	for (k = 0;k < n;k++) {
		angle += angleInc;
		glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cx);
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//menggambar garis strip
	/*
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP); //GL_LINE_STRIP, GL_LINE_LOOP
		glVertex2i(20, 10);
		glVertex2i(50, 10);
		glVertex2i(20, 80);
		glVertex2i(50, 10);
	glEnd();
	*/

	//menggambar gon beraturan
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	/*
	glVertex2f(40 * cos(2 * 3.14159265 * 1 / 6), 40 * sin(2 * 3.14159265 * 1 / 6));
	glVertex2f(40 * cos(2 * 3.14159265 * 2 / 6), 40 * sin(2 * 3.14159265 * 2 / 6));
	glVertex2f(40 * cos(2 * 3.14159265 * 3 / 6), 40 * sin(2 * 3.14159265 * 3 / 6));
	glVertex2f(40 * cos(2 * 3.14159265 * 4 / 6), 40 * sin(2 * 3.14159265 * 4 / 6));
	glVertex2f(40 * cos(2 * 3.14159265 * 4 / 6), 40 * sin(2 * 3.14159265 * 5 / 6));
	glVertex2f(40 * cos(2 * 3.14159265 * 6 / 6), 40 * sin(2 * 3.14159265 * 6 / 6));
	*/

	//ini pake perulangan
	ngon(6, 10, 0, 40, 180);
	glEnd();

	glutSwapBuffers();
}